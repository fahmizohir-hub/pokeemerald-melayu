#!/usr/bin/env python3
"""Lukis semula teks Inggeris dalam grafik minigame/contest/pokeblock dalam BM.

Jalankan dalam WSL (perlu Pillow):
    python3 tools/jana_grafik_lain_b.py --huruf
    python3 tools/jana_grafik_lain_b.py --semak
    python3 tools/jana_grafik_lain_b.py --pratonton FAIL.png
    python3 tools/jana_grafik_lain_b.py

Sentiasa bermula daripada fail asal (tag git `asal`), jadi boleh diulang.

Cara kerja: setiap imej dibuka sebagai "kanvas logik" = susunan tile 8x8
seperti yang dipaparkan dalam game (helaian terus, sprite 1D, atau tilemap BG
.bin). Teks dipadam dan dilukis semula pada kanvas, kemudian setiap tile
ditulis balik ke helaian. Tile yang dipakai di lebih daripada satu tempat
(termasuk dengan flip) mesti berakhir dengan kandungan yang sama di semua
tempat, jika tidak skrip berhenti (lihat Kanvas.simpan).

Fon diambil daripada perkataan Inggeris asal (komponen piksel warna isi);
huruf yang tiada dilukis dalam gaya sama (TAMBAHAN setiap fon). Garis luar /
bayang dijana semula ikut lapisan gaya (Gaya.lapisan) supaya huruf lama dan
baharu sepadan. --semak melukis semula perkataan Inggeris dan melaporkan
bilangan piksel yang berbeza daripada asal (ukuran ketepatan model gaya).
"""
import collections
import struct
import subprocess
import sys
from io import BytesIO
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
G = "graphics/"


def baca_git(rel):
    return subprocess.run(["git", "-C", str(ROOT), "show", f"asal:{rel}"],
                          capture_output=True, check=True).stdout


def asal(rel):
    return Image.open(BytesIO(baca_git(rel)))


# ============================================================== kanvas
class Kanvas:
    """Imej logik (palet indeks) yang dibina daripada tile helaian.

    sel: {(cx, cy): (tile, hflip, vflip)} — sel tanpa tile tidak boleh ditulis.
    """

    def __init__(self, im, lebar_sel, tinggi_sel, sel):
        self.im = im
        self.tw = im.width // 8
        self.sel = sel
        self.w, self.h = lebar_sel * 8, tinggi_sel * 8
        sp = im.load()
        self.buf = [[0] * self.w for _ in range(self.h)]
        for (cx, cy), (t, hf, vf) in sel.items():
            for y in range(8):
                for x in range(8):
                    sx, sy = self._sumber(t, x, y, hf, vf)
                    self.buf[cy * 8 + y][cx * 8 + x] = sp[sx, sy]
        # PNG 4bpp dengan palet >16 warna: gbagfx hanya guna 4 bit rendah
        # (indeks % 16). Kanvas bekerja dengan 4 bit rendah; 4 bit tinggi
        # (baris palet) dikekalkan ikut tile supaya PNG kekal kemas.
        self.multi = len(im.getpalette()) > 48
        self.nib = {}
        if self.multi:
            for (cx, cy) in sel:
                c = collections.Counter(self.buf[cy * 8 + y][cx * 8 + x] >> 4 for y in range(8)
                                        for x in range(8) if self.buf[cy * 8 + y][cx * 8 + x] & 15)
                self.nib[(cx, cy)] = c.most_common(1)[0][0] if c else 0

    def _sumber(self, t, x, y, hf, vf):
        if hf:
            x = 7 - x
        if vf:
            y = 7 - y
        return (t % self.tw) * 8 + x, (t // self.tw) * 8 + y

    def __getitem__(self, p):
        v = self.buf[p[1]][p[0]]
        return v & 15 if self.multi else v

    def __setitem__(self, p, v):
        x, y = p
        if (x // 8, y // 8) not in self.sel:
            raise ValueError(f"piksel {p} di luar tile yang dipaparkan")
        if self.multi:
            v = (self.nib[(x // 8, y // 8)] << 4) | (v & 15) if v & 15 else self.buf[y][x] & 0xF0
        self.buf[y][x] = v

    def boleh(self, x, y):
        return 0 <= x < self.w and 0 <= y < self.h and (x // 8, y // 8) in self.sel

    def simpan(self):
        """Tulis balik ke salinan helaian. Semak tile kongsi konsisten."""
        mahu, konflik = {}, set()
        for (cx, cy), (t, hf, vf) in self.sel.items():
            for y in range(8):
                for x in range(8):
                    sp = self._sumber(t, x, y, hf, vf)
                    v = self.buf[cy * 8 + y][cx * 8 + x]
                    if mahu.setdefault(sp, v) != v:
                        konflik.add(t)
        for t in sorted(konflik):
            sel = [c for c, (tt, _, _) in self.sel.items() if tt == t]
            msg = f"KONFLIK tile {t}: dikongsi oleh sel {sel} tetapi kandungan baharu berbeza"
            if not LONGGAR:
                raise SystemExit(msg)
            print("  (semak)", msg)
        im = self.im.copy()
        px = im.load()
        for sp, v in mahu.items():
            px[sp] = v
        return im


def kanvas_terus(im):
    tw, th = im.width // 8, im.height // 8
    return Kanvas(im, tw, th, {(cx, cy): (cy * tw + cx, 0, 0) for cy in range(th) for cx in range(tw)})


def kanvas_sprite(im, bingkai):
    """bingkai: senarai (tile pertama, lebar tile, tinggi tile, cx, cy) — sprite 1D."""
    sel = {}
    lw = lh = 0
    for t0, w, h, cx, cy in bingkai:
        for r in range(h):
            for c in range(w):
                sel[(cx + c, cy + r)] = (t0 + r * w + c, 0, 0)
        lw, lh = max(lw, cx + w), max(lh, cy + h)
    return Kanvas(im, lw, lh, sel)


def kanvas_peta(im, rel_bin, lebar, offset=0, data=None):
    data = data if data is not None else baca_git(rel_bin)
    e = struct.unpack(f"<{len(data) // 2}H", data)
    n = (im.width // 8) * (im.height // 8)
    sel = {}
    for i, v in enumerate(e):
        t = (v & 0x3FF) - offset
        if 0 <= t < n:
            sel[(i % lebar, i // lebar)] = (t, (v >> 10) & 1, (v >> 11) & 1)
    kv = Kanvas(im, lebar, len(e) // lebar, sel)
    kv.entri, kv.lebar_peta, kv.offset = list(e), lebar, offset
    return kv


def ke_bin(kv):
    """Tilemap baharu daripada kv.sel (bit palet entri asal dikekalkan)."""
    e = list(kv.entri)
    for (cx, cy), (t, hf, vf) in kv.sel.items():
        i = cy * kv.lebar_peta + cx
        e[i] = (e[i] & 0xF000) | (t + kv.offset) | (hf << 10) | (vf << 11)
    return struct.pack(f"<{len(e)}H", *e)


def bebaskan_tile(kv, bebas, ganti, sel_baru):
    """Tile `bebas` ialah salinan hflip tile `ganti`: alihkan semua sel yang
    memakai `bebas` ke `ganti` (hflip ditukar), kemudian beri tile `bebas`
    kepada sel `sel_baru` (tanpa flip) supaya sel itu tidak lagi berkongsi.
    Kandungan logik kanvas tidak berubah."""
    for c, (t, hf, vf) in list(kv.sel.items()):
        if t == bebas:
            kv.sel[c] = (ganti, hf ^ 1, vf)
    kv.sel[sel_baru] = (bebas, 0, 0)


# ============================================================== gaya & fon
SISI = ((1, 0), (-1, 0), (0, 1), (0, -1))
SUDUT = ((1, 1), (1, -1), (-1, 1), (-1, -1))
LAPAN = SISI + SUDUT
BAYANG = ((1, 0), (0, 1), (1, 1))  # kanan, bawah, pepenjuru


class Gaya:
    """isi: set warna isi huruf. lapisan: [(offset, warna)] dari dalam ke luar;
    setiap lapisan = jiran (ikut offset) kepada semua piksel sebelumnya.
    warna_baris: warna isi bagi huruf baharu ikut baris (relatif atas teks)."""

    def __init__(self, isi, lapisan, tinggi, warna_baris=None):
        self.isi = set(isi)
        self.lapisan = lapisan
        self.tinggi = tinggi
        self.warna_baris = warna_baris

    @property
    def semua(self):
        return self.isi | {lp[1] for lp in self.lapisan}


def komponen(titik):
    """Komponen 8-sambung; pulangkan senarai set, disusun ikut x minimum."""
    baki = set(titik)
    hasil = []
    while baki:
        p = baki.pop()
        k, tindan = {p}, [p]
        while tindan:
            x, y = tindan.pop()
            for dx, dy in LAPAN:
                q = (x + dx, y + dy)
                if q in baki:
                    baki.remove(q)
                    k.add(q)
                    tindan.append(q)
        hasil.append(k)
    return sorted(hasil, key=lambda k: min(x for x, _ in k))


def ekstrak(kv, kotak, y_atas, gaya, kata, fon):
    """Ambil glyph `kata` daripada kanvas. kotak = (x0, y0, x1, y1) carian.
    Glyph = {(dx, dy): warna} dengan dy relatif `y_atas`."""
    x0, y0, x1, y1 = kotak
    titik = {(x, y) for x in range(x0, x1) for y in range(y0, y1)
             if kv.boleh(x, y) and kv[x, y] in gaya.isi}
    huruf = [c for c in kata if c != " "]
    # cuba kumpulan lajur dahulu, kemudian komponen
    xs = sorted({x for x, _ in titik})
    kump, cur = [], []
    for x in xs:
        if cur and x != cur[-1] + 1:
            kump.append(cur)
            cur = []
        cur.append(x)
    if cur:
        kump.append(cur)
    if len(kump) == len(huruf):
        bahagian = [{p for p in titik if kump[i][0] <= p[0] <= kump[i][-1]} for i in range(len(kump))]
    else:
        bahagian = komponen(titik)
        if len(bahagian) != len(huruf):
            raise SystemExit(f"EKSTRAK GAGAL {kata}: {len(kump)} lajur / {len(bahagian)} komponen")
    for h, b in zip(huruf, bahagian):
        if h == "?":  # komponen bercantum / tidak diperlukan
            continue
        bx = min(x for x, _ in b)
        g = {(x - bx, y - y_atas): kv[x, y] for x, y in b}
        fon.setdefault(h, []).append(g)
    return min(xs), max(xs)


def glyph_dari_teks(baris, gaya):
    g = {}
    for dy, s in enumerate(baris):
        for dx, ch in enumerate(s):
            if ch == "#":
                g[(dx, dy)] = gaya.warna_baris[dy] if gaya.warna_baris else min(gaya.isi)
            elif ch != ".":
                g[(dx, dy)] = int(ch, 16)
    return g


def satukan(fon, tambahan, gaya, ganti=None):
    hasil = {}
    for h, senarai in fon.items():
        kira = collections.Counter(tuple(sorted(g.items())) for g in senarai)
        hasil[h] = dict(max(kira, key=lambda k: kira[k]))
    for h, b in tambahan.items():
        hasil.setdefault(h, glyph_dari_teks(b, gaya))
    for h, b in (ganti or {}).items():
        hasil[h] = glyph_dari_teks(b, gaya)
    return hasil


def lebar_glyph(g):
    return max(x for x, _ in g) + 1


def susun(kata, fon, jarak, ruang):
    """Pulangkan ({(x, y): warna}, lebar)."""
    titik, x, w = {}, 0, 0
    for c in kata:
        if c == " ":
            x += ruang
            continue
        g = fon[c]
        for (dx, dy), v in g.items():
            titik[(x + dx, dy)] = v
        w = x + lebar_glyph(g)
        x = w + jarak
    return titik, w


def padam(kv, kotak, warna, latar=None, zon=None):
    """Ganti piksel berwarna `warna` dalam kotak dengan latar:
    None = warna bukan-teks paling kerap dalam baris kotak;
    "jiran" = piksel bukan-teks terdekat dalam baris yang sama (untuk latar
    berbentuk, cth. bulatan berwarna di belakang label graf);
    nombor = warna tetap."""
    x0, y0, x1, y1 = kotak
    for y in range(y0, y1):
        asal_baris = {x: kv[x, y] for x in range(x0 - 8, x1 + 8) if kv.boleh(x, y)}
        lt = latar
        if latar is None:
            c = collections.Counter(v for x, v in asal_baris.items()
                                    if x0 <= x < x1 and v not in warna)
            lt = c.most_common(1)[0][0] if c else 0
        for x in range(x0, x1):
            if not (kv.boleh(x, y) and kv[x, y] in warna):
                continue
            if zon is not None and (x, y) not in zon:
                continue  # warna sama tetapi bukan sebahagian teks (cth. garis pentagon)
            if latar == "jiran":
                v = 0
                for d in range(1, 16):
                    kiri, kanan = asal_baris.get(x - d), asal_baris.get(x + d)
                    if kiri is not None and kiri not in warna:
                        v = kiri
                        break
                    if kanan is not None and kanan not in warna:
                        v = kanan
                        break
                kv[x, y] = v
            else:
                kv[x, y] = lt


LONGGAR = False  # --semak: lukisan Inggeris yang terkeluar had hanya diberi amaran


def lukis(kv, titik_teks, x, y, gaya, had, bingkai, nama=""):
    """Lukis teks (dari susun) pada (x, y) dengan lapisan gaya.
    had = kotak yang mesti memuatkan piksel isi; bingkai = kotak yang boleh
    disentuh oleh lapisan (garis luar/bayang)."""
    hx0, hy0, hx1, hy1 = had
    bx0, by0, bx1, by1 = bingkai
    isi = {(x + dx, y + dy): v for (dx, dy), v in titik_teks.items()}
    luar = [p for p in isi if not (hx0 <= p[0] < hx1 and hy0 <= p[1] < hy1)]
    if luar:
        if not LONGGAR:
            raise SystemExit(f"TAK MUAT: {nama} piksel {luar[0]} di luar had {had}")
        print(f"  (semak) {nama}: {len(luar)} piksel di luar had")
        isi = {p: v for p, v in isi.items() if kv.boleh(*p)}
    sudah = set(isi)
    lapis = []
    for lp in gaya.lapisan:
        offset, warna = lp[0], lp[1]
        asas = set(isi) if len(lp) > 2 and lp[2] == "isi" else sudah
        baru = {(a + dx, b + dy) for (a, b) in asas for dx, dy in offset} - sudah
        lapis.append((baru, warna))
        sudah |= baru
    for baru, warna in reversed(lapis):
        for p in baru:
            if bx0 <= p[0] < bx1 and by0 <= p[1] < by1 and kv.boleh(*p):
                kv[p] = warna
    for p, v in isi.items():
        kv[p] = v


# ============================================================== label
class Label:
    """Satu perkataan pada satu kanvas.

    kotak: kawasan teks asal untuk dipadam (x0, y0, x1, y1).
    had: kawasan yang dibenarkan untuk teks baharu (lalai = kotak).
    jajar: 'tengah' (pusat kotak teks asal), 'kiri' (x kiri teks asal),
           atau nombor x tetap.
    """

    def __init__(self, en, ms, kotak, y_atas, fon, had=None, jajar="tengah", latar=None,
                 jarak=1, ruang=4, ekstrak=True, gaya=None, bingkai=None, en_ekstrak=None):
        self.en, self.ms, self.kotak, self.y = en, ms, kotak, y_atas
        self.fon, self.had, self.jajar, self.latar = fon, had or kotak, jajar, latar
        self.jarak, self.ruang, self.ekstrak = jarak, ruang, ekstrak
        self.gaya = gaya or fon.gaya  # gaya lain (cth. warna bayang) dengan bentuk huruf sama
        self.bingkai = bingkai or kotak
        self.en_ekstrak = en_ekstrak or en  # '?' = komponen yang diabaikan


class Fon:
    def __init__(self, nama, gaya, tambahan=None, ganti=None):
        self.nama, self.gaya = nama, gaya
        self.tambahan, self.ganti = tambahan or {}, ganti or {}
        self.mentah = {}
        self.huruf = None


class Kerja:
    """Satu fail PNG: cara bina kanvas + senarai label."""

    def __init__(self, rel, bina, label, pasca=None, pratonton=None, bin_keluar=None):
        self.rel, self.bina, self.label = rel, bina, label
        self.bin_keluar = bin_keluar  # tilemap .bin yang turut ditulis (jika susunan tile diubah)
        self.pasca = pasca
        self.pratonton = pratonton  # kotak kanvas untuk pratonton (lalai: penuh)

    def kanvas(self):
        return self.bina(asal(G + self.rel))


def proses(kerja, semak=False):
    kv = kerja.kanvas()
    asal_teks = {}
    for lb in kerja.label:
        g = lb.gaya
        # kedudukan teks asal (isi sahaja)
        x0, y0, x1, y1 = lb.kotak
        xs = [x for x in range(x0, x1) for y in range(lb.y, lb.y + g.tinggi)
              if kv.boleh(x, y) and kv[x, y] in g.isi]
        asal_teks[id(lb)] = (min(xs), max(xs))
    for lb in kerja.label:
        g = lb.gaya
        kata = lb.en if semak else lb.ms
        if kata is None:
            continue
        if semak and any(c != " " and c not in lb.fon.huruf for c in kata):
            continue  # huruf asal tidak diekstrak (komponen bercantum)
        kiri, kanan = asal_teks[id(lb)]
        # zon padam = piksel isi asal + jiran sejauh bilangan lapisan
        x0, y0, x1, y1 = lb.kotak
        zon = {(x, y) for x in range(x0, x1) for y in range(y0, y1) if kv.boleh(x, y) and kv[x, y] in g.isi}
        for _ in g.lapisan:
            zon |= {(a + dx, b + dy) for (a, b) in zon for dx, dy in LAPAN}
        padam(kv, lb.kotak, g.semua, lb.latar, zon)
        titik, w = susun(kata, lb.fon.huruf, lb.jarak, lb.ruang)
        if lb.jajar == "tengah":
            x = (kiri + kanan + 1 - w) // 2
        elif lb.jajar == "kiri":
            x = kiri
        elif lb.jajar == "kanan":
            x = kanan + 1 - w
        elif lb.jajar == "pusat":  # tengah kawasan had
            x = (lb.had[0] + lb.had[2] - w) // 2
        elif isinstance(lb.jajar, tuple):  # ("kanan", x hujung) / ("kiri", x mula)
            x = lb.jajar[1] + 1 - w if lb.jajar[0] == "kanan" else lb.jajar[1]
        else:
            x = lb.jajar
        lukis(kv, titik, x, lb.y, g, lb.had, lb.bingkai, f"{kerja.rel} {kata}")
    if kerja.pasca and not semak:
        kerja.pasca(kv)
    return kv


def sedia_fon(senarai_kerja):
    for k in senarai_kerja:
        kv = None
        for lb in k.label:
            if not lb.ekstrak:
                continue
            kv = kv or k.kanvas()
            ekstrak(kv, lb.kotak, lb.y, lb.gaya, lb.en_ekstrak, lb.fon.mentah)
    for k in senarai_kerja:
        for lb in k.label:
            f = lb.fon
            if f.huruf is None:
                f.huruf = satukan(f.mentah, f.tambahan, f.gaya, f.ganti)


# ============================================================== DATA
def terus(rel):
    return lambda im: kanvas_terus(im)


def peta(rel_bin, lebar, offset=0):
    return lambda im: kanvas_peta(im, G + rel_bin, lebar, offset)


def peta_gabung(senarai_bin, lebar):
    """Beberapa tilemap yang berkongsi satu helaian, disusun menegak."""
    return lambda im: kanvas_peta(im, None, lebar, 0, b"".join(baca_git(G + b) for b in senarai_bin))


KERJA = []

# ---------------------------------------------------------------- Berry Blender
# start.png: sprite 64x32 "START" (isyarat mula mengisar). Isi c, garis luar
# 8-jiran 1 lalu f (dua lapis), latar 0.
F_MULA = Fon("mula", Gaya({12}, [(LAPAN, 1), (LAPAN, 15)], 21), tambahan={
    # 21 baris, strok 3 lajur seperti T/R asal
    "M": ["####......####", "#####....#####", "######..######", "###.######.###",
          "###..####..###", "###...##...###"] + ["###........###"] * 15,
    "U": ["###......###"] * 17 + ["####....####", ".##########.", "..########..", "...######..."],
    "L": ["###"] * 18 + ["###########"] * 3,
})
KERJA.append(Kerja("berry_blender/start.png", terus(0), [
    # S dan T bersentuh (satu komponen) -> diabaikan; huruf A diambil
    Label("START", "MULA", (0, 3, 64, 28), 5, F_MULA, had=(2, 5, 62, 26), latar=0, en_ekstrak="?ART"),
]))

# ---------------------------------------------------------------- POKéMON Jump
# bonuses.png + bonuses.bin: empat sepanduk bonus (BG). Isi a (sudut 9),
# garis luar 7 (4-jiran), latar berjalur ikut baris. Seluruh "KATA+NNN"
# dilukis semula dan dipusatkan dalam sepanduk; digit dan '+' diambil dari asal.
F_LOMPAT = Fon("lompat", Gaya({9, 10}, [(SISI, 7)], 14, warna_baris=[10] * 14), tambahan={
    # 14 baris, strok 4 lajur, sudut dibulatkan dengan 9 (seperti huruf asal)
    "B": ["9aaaaaaaa9.", "aaaaaaaaaa9", "aaaaaaaaaaa", "aaaa..9aaaa", "aaaa...aaaa", "aaaa..9aaa9", "aaaaaaaaaa.",
          "aaaaaaaaaa.", "aaaa..9aaa9", "aaaa...aaaa", "aaaa..9aaaa", "aaaaaaaaaaa", "aaaaaaaaaa9", "9aaaaaaaa9."],
    "K": ["9aa9....9aa9", "aaaa...9aaaa", "aaaa..9aaaa9", "aaaa.9aaaa9.", "aaaa9aaaa9..", "aaaaaaaa9...",
          "aaaaaaa9....", "aaaaaaa9....", "aaaaaaaa9...", "aaaa9aaaa9..", "aaaa.9aaaa9.", "aaaa..9aaaa9",
          "aaaa...9aaaa", "9aa9....9aa9"],
    "H": ["9aa9....9aa9"] + ["aaaa....aaaa"] * 5 + ["aaaaaaaaaaaa"] * 2 + ["aaaa....aaaa"] * 5 + ["9aa9....9aa9"],
    "U": ["9aa9....9aa9"] + ["aaaa....aaaa"] * 9 + ["9aaa9..9aaa9", ".aaaaaaaaaa.", ".9aaaaaaaa9.", "...9aaaa9..."],
    "S": [".9aaaaaaa9.", "9aaaaaaaaa9", "aaaaaaaaaaa", "aaaa9..9aaa", "aaaa9......", "aaaaaaaa9..", "9aaaaaaaaa.",
          ".9aaaaaaaa9", "..9aaaaaaaa", "......9aaaa", "aaa9..9aaaa", "aaaaaaaaaaa", "9aaaaaaaaa9", ".9aaaaaaa9."],
    "M": ["9aa9......9aa9", "aaaa9....9aaaa", "aaaaa9..9aaaaa", "aaaaaa99aaaaaa", "aaaa9aaaa9aaaa",
          "aaaa.9aa9.aaaa", "aaaa..aa..aaaa"] + ["aaaa......aaaa"] * 6 + ["9aa9......9aa9"],
})
_SEP = [  # (en, ms, y atas isi, x dalam kiri, x dalam kanan, jarak huruf)
    ("NICE + 50", "BAIK + 50", 9, 69, 171, 3),
    ("GREAT + 200", "HEBAT + 200", 265, 53, 187, 3),
    ("GOOD + 100", "BAGUS + 100", 521, 61, 179, 2),  # jarak 3 terlebih 1 piksel
    ("EXCELLENT + 500", "CEMERLANG + 500", 777, 29, 211, 3),
]
def _peta_lompat(im):
    # Tile 99 dipakai dua kali dalam sepanduk EXCELLENT: (14,97) dan (14,98)
    # dengan vflip (separuh huruf E yang simetri). CEMERLANG tidak simetri di
    # situ, jadi sel (14,98) diberi tile sendiri: tile 121 (= hflip tile 2,
    # bucu atas sepanduk NICE) dibebaskan dengan memakai tile 2 + hflip.
    kv = kanvas_peta(im, G + "pokemon_jump/bonuses.bin", 32)
    bebaskan_tile(kv, 121, 2, (14, 98))
    return kv


KERJA.append(Kerja("pokemon_jump/bonuses.png", _peta_lompat, bin_keluar="pokemon_jump/bonuses.bin",
                   pratonton=[(24, y - 9, 216, y + 23) for _, _, y, _, _, _ in _SEP], label=[
    Label(en, ms, (x0, y - 1, x1, y + 15), y, F_LOMPAT, had=(x0 + 1, y, x1 - 1, y + 14),
          jarak=j, ruang=4 - j)
    for en, ms, y, x0, x1, j in _SEP
]))

# ---------------------------------------------------------------- Roulette
# credit.png: sprite 64x32. Isi d/f/e ikut baris, bayang 1 (kanan/bawah).
F_KREDIT_R = Fon("kredit_roulette", Gaya({13, 14, 15}, [(BAYANG, 1)], 7,
                                         warna_baris=[13, 13, 15, 15, 15, 15, 14]), tambahan={
    "K": ["##..##", "##.##.", "####..", "###...", "####..", "##.##.", "##..##"],
})
KERJA.append(Kerja("roulette/credit.png", terus(0), [
    Label("CREDIT", "KREDIT", (8, 8, 57, 16), 8, F_KREDIT_R, had=(8, 8, 56, 15)),
]))

# ---------------------------------------------------------------- Contest
# applause.png: sprite 64x32, isi 5 atas latar 4, tiada bayang.
F_TEPUK = Fon("tepukan", Gaya({5}, [], 7), tambahan={
    "T": ["###", ".#.", ".#.", ".#.", ".#.", ".#.", ".#."],
    "K": ["#..#", "#..#", "#.#.", "##..", "#.#.", "#..#", "#..#"],
    "N": ["#..#", "##.#", "##.#", "#.##", "#.##", "#..#", "#..#"],
})
KERJA.append(Kerja("contest/applause.png", terus(0), [
    Label("APPLAUSE", "TEPUKAN", (5, 7, 54, 14), 7, F_TEPUK, had=(5, 7, 54, 14)),
]))

# nextturn.png: sprite 64x8; tile 6 (x48-55) ditimpa nombor giliran oleh kod,
# jadi teks mesti kekal dalam x 0-47.
F_GILIR = Fon("giliran", Gaya({15}, [], 5), tambahan={
    "G": [".###", "#...", "#.##", "#..#", ".###"],
    "I": ["###", ".#.", ".#.", ".#.", "###"],
    "L": ["#..", "#..", "#..", "#..", "###"],
    "A": [".##.", "#..#", "####", "#..#", "#..#"],
    "K": ["#..#", "#.#.", "##..", "#.#.", "#..#"],
})
KERJA.append(Kerja("contest/nextturn.png", terus(0), [
    Label("NEXT TURN", "GILIRAN KE", (1, 2, 48, 7), 2, F_GILIR, had=(1, 2, 47, 7),
          jajar="kiri", ruang=3),
]))

# interface.png: APPEAL/JAM (tile 25-28, 41-44, sekali dalam interface.bin)
# dan label kategori 5x2 tile yang disalin oleh kod (contest.c, categoryTile
# 0x40/0x45/0x4A/0x6A/0x8A). Label kategori: isi d, bayang ikut kategori.
F_PIKAT = Fon("pikat", Gaya({10}, [], 5), tambahan={
    "I": ["###", ".#.", ".#.", ".#.", "###"],
    "K": ["#..#", "#.#.", "##..", "#.#.", "#..#"],
    "T": ["###", ".#.", ".#.", ".#.", ".#."],
    "G": [".###", "#...", "#.##", "#..#", ".###"],
    "N": ["#..#", "##.#", "#.##", "#..#", "#..#"],
    "U": ["#..#", "#..#", "#..#", "#..#", ".##."],
})
F_KATEGORI = Fon("kategori", Gaya({13}, [(BAYANG, 2)], 9), tambahan={
    "K": ["##.##", "##.##", "####.", "###..", "###..", "####.", "##.##", "##.##", "##.##"],
    "N": ["##..##", "###.##", "######", "##.###", "##..##", "##..##", "##..##", "##..##", "##..##"],
    "I": ["##"] * 9,
    "J": ["...##"] * 6 + ["##.##", "##.##", ".###."],
    "P": ["####.", "##.##", "##.##", "##.##", "####.", "##...", "##...", "##...", "##..."],
})


def _kat(en, ms, x0, y0, bayang):
    return Label(en, ms, (x0 + 1, y0 + 1, x0 + 39, y0 + 15), y0 + 3, F_KATEGORI,
                 had=(x0 + 1, y0 + 1, x0 + 39, y0 + 14), gaya=Gaya({13}, [(BAYANG, bayang)], 9))


KERJA.append(Kerja("contest/interface.png", terus(0), [
    Label("APPEAL", "PIKAT", (72, 10, 104, 15), 10, F_PIKAT, jajar="kiri"),
    Label("JAM", "GANGGU", (72, 18, 104, 23), 18, F_PIKAT, jajar="kiri"),
    _kat("COOL", "SEGAK", 0, 32, 2),
    _kat("BEAUTY", "CANTIK", 40, 32, 5),
    _kat("CUTE", "COMEL", 80, 32, 8),
    _kat("SMART", "BIJAK", 80, 48, 10),
    _kat("TOUGH", "TEGAP", 80, 64, 12),
], pratonton=(0, 0, 128, 80)))

# results_screen/tiles.png: bar tajuk keputusan. Isi 1, bayang 9.
# Susunan kod: [tahap 10 tile][kategori 5][title.bin 6]. Untuk "TAHAP NORMAL"
# tilemap title_<tahap>.bin disusun semula supaya tile kongsi RANK (0x6B-0x6F,
# 0x7B-0x7F) datang dahulu (lihat TAJUK_BIN). CONTEST (title.bin) dikosongkan:
# "PERTANDINGAN" tak muat dan susunan Melayu memerlukannya di depan.
F_HASIL = Fon("keputusan", Gaya({1}, [(BAYANG, 9)], 11), tambahan={
    "I": ["##"] * 11,
    "J": ["...##"] * 8 + ["##.##", "##.##", ".###."],
})


def _hasil(en, ms, x0, y0, jajar="kiri", w=40):
    return Label(en, ms, (x0, y0, x0 + w, y0 + 16), y0 + 2, F_HASIL, had=(x0 + 1, y0 + 1, x0 + w - 1, y0 + 15),
                 jajar=jajar)


# Nama tahap (NORMAL dll.) bermula ~3 piksel dari kiri bloknya, jadi TAHAP
# dirapatkan ke kanan bloknya; nama kategori pula dirapatkan ke kiri (selepas
# nama tahap yang hampir penuh bloknya).
KERJA.append(Kerja("contest/results_screen/tiles.png", terus(0), [
    # nama tahap kini selepas TAHAP: rapatkan ke kiri blok (seperti NORMAL/MASTER)
    _hasil("SUPER", "SUPER", 40, 16, ("kiri", 40 + 3)),
    _hasil("HYPER", "HIPER", 80, 16, ("kiri", 80 + 3)),
    _hasil("RANK", "TAHAP", 88, 48, ("kanan", 88 + 36)),
    _hasil("COOL", "SEGAK", 0, 96, ("kiri", 0 + 4)),
    _hasil("BEAUTY", "CANTIK", 40, 96, ("kiri", 40 + 4)),
    _hasil("CUTE", "COMEL", 80, 96, ("kiri", 80 + 4)),
    _hasil("SMART", "BIJAK", 0, 112, ("kiri", 0 + 4)),
    _hasil("TOUGH", "TEGAP", 40, 112, ("kiri", 40 + 4)),
    _hasil("CONTEST", "", 80, 112, w=48),
]))

TAJUK_BIN = ["contest/results_screen/title_" + t + ".bin" for t in ("normal", "super", "hyper", "master")]


def FAIL_LAIN():
    """Fail bukan-PNG: title_<tahap>.bin (10x2) disusun semula daripada
    [NAMA TAHAP][RANK] kepada [TAHAP][NAMA TAHAP] supaya terbaca "TAHAP NORMAL"."""
    hasil = []
    for rel in TAJUK_BIN:
        e = struct.unpack("<20H", baca_git(G + rel))
        assert all(0x6B <= (v & 0x3FF) <= 0x6F for v in e[5:10]), rel
        baru = e[5:10] + e[0:5] + e[15:20] + e[10:15]
        hasil.append((rel, struct.pack("<20H", *baru)))
    return hasil

# ---------------------------------------------------------------- Pokéblock
# menu.png (menu.bin): tajuk lajur "FEEL" dalam BEKAS POKéBLOCK.
F_RASA = Fon("rasa", Gaya({9}, [(BAYANG, 11)], 9), tambahan={
    "R": ["####.", "#...#", "#...#", "#...#", "####.", "#.#..", "#..#.", "#...#", "#...#"],
    "A": [".###.", "#...#", "#...#", "#...#", "#####", "#...#", "#...#", "#...#", "#...#"],
    "S": [".####", "#....", "#....", "#....", ".###.", "....#", "....#", "....#", "####."],
})
KERJA.append(Kerja("pokeblock/menu.png", peta("pokeblock/menu.bin", 32), [
    Label("FEEL", "RASA", (55, 139, 84, 151), 140, F_RASA, had=(55, 139, 105, 150), jajar="kiri"),
], pratonton=(40, 128, 112, 160)))

# use_screen/condition.png: dua sprite 64x32 sebelah-menyebelah (kepala KEADAAN).
F_KEADAAN = Fon("keadaan", Gaya({1}, [(BAYANG, 2)], 9), tambahan={
    "K": ["#...#", "#...#", "#..#.", "#.#..", "##...", "#.#..", "#..#.", "#...#", "#...#"],
    "E": ["#####", "#....", "#....", "#....", "####.", "#....", "#....", "#....", "#####"],
    "A": [".###.", "#...#", "#...#", "#...#", "#####", "#...#", "#...#", "#...#", "#...#"],
})
KERJA.append(Kerja("pokeblock/use_screen/condition.png",
                   lambda im: kanvas_sprite(im, [(0, 8, 4, 0, 0), (32, 8, 4, 8, 0)]), [
    Label("CONDITION", "KEADAAN", (16, 7, 72, 17), 7, F_KEADAAN, had=(2, 7, 87, 17), jajar="kiri"),
], pratonton=(0, 0, 96, 24)))

# use_screen/updown.png: sprite 32x16 x2 (NAIK / TURUN).
F_NAIK = Fon("naik", Gaya({1}, [(LAPAN, 2)], 9), tambahan={
    "N": ["##...##", "###..##", "####.##", "##.####", "##..###", "##...##", "##...##", "##...##", "##...##"],
    "A": [".####.", "######", "##..##", "##..##", "######", "######", "##..##", "##..##", "##..##"],
    "I": ["##"] * 9,
    "K": ["##..##", "##.##.", "####..", "###...", "###...", "####..", "##.##.", "##..##", "##..##"],
})
F_TURUN = Fon("turun", Gaya({1}, [(LAPAN, 3)], 8), tambahan={
    "T": ["#####", "#####", ".###.", ".###.", ".###.", ".###.", ".###.", ".###."],
    "U": ["##.##"] * 6 + ["#####", ".###."],
    "R": ["####.", "#####", "##.##", "##.##", "####.", "#####", "##.##", "##.##"],
})
KERJA.append(Kerja("pokeblock/use_screen/updown.png", terus(0), [
    Label("UP", "NAIK", (0, 2, 32, 13), 3, F_NAIK, had=(1, 3, 31, 12), jarak=2),
    Label("DOWN", "TURUN", (0, 19, 32, 29), 20, F_TURUN, had=(1, 20, 31, 28)),
]))

# use_screen/graph.png (graph.bin, tile bermula 640): label pentagon.
# Isi 1, sisi 4, sudut f (seperti graf PokéNav). Latar bulatan berwarna -> "jiran".
F_GRAF = Fon("graf", Gaya({1}, [(SISI, 4, "isi"), (SUDUT, 15, "isi")], 7), tambahan={
    "K": ["#...#", "#..#.", "#.#..", "##...", "#.#..", "#..#.", "#...#"],
    "P": ["####.", "#...#", "#...#", "####.", "#....", "#....", "#...."],
    "N": ["#...#", "##..#", "#.#.#", "#.#.#", "#.#.#", "#..##", "#...#"],
    "I": ["###", ".#.", ".#.", ".#.", ".#.", ".#.", "###"],
    "J": ["....#", "....#", "....#", "....#", "#...#", "#...#", ".###."],
})


def _graf(en, ms, x0, y, x1):
    return Label(en, ms, (x0, y - 1, x1, y + 8), y, F_GRAF, had=(x0 + 1, y, x1 - 1, y + 7), latar="jiran")


KERJA.append(Kerja("pokeblock/use_screen/graph.png", peta("pokeblock/use_screen/graph.bin", 32, 640), [
    _graf("COOL", "SEGAK", 136, 42, 180),
    _graf("TOUGH", "TEGAP", 99, 65, 140),
    _graf("BEAUTY", "CANTIK", 172, 65, 212),
    _graf("SMART", "BIJAK", 105, 125, 145),
    _graf("CUTE", "COMEL", 164, 125, 205),
], pratonton=(96, 32, 216, 136)))

# ---------------------------------------------------------------- Slot machine
# menu.png dipapar melalui menu.bin DAN info_box.bin (helaian sama); kedua-dua
# tilemap disusun menegak (info_box bermula y=160) supaya tile kongsi disemak.
F_KREDIT_S = Fon("kredit_slot", Gaya({3}, [], 5), tambahan={
    "K": ["#.#", "#.#", "##.", "#.#", "#.#"],
    "B": ["##.", "#.#", "##.", "#.#", "##."],
    "N": ["#..#", "##.#", "#.##", "#..#", "#..#"],
})
F_BUTANG_S = Fon("butang_slot", Gaya({3}, [(BAYANG, 12)], 7), tambahan={
    "H": ["#...#"] * 3 + ["#####"] + ["#...#"] * 3,
    "T": ["#####"] + ["..#.."] * 6,
    "B": ["####.", "#...#", "#...#", "####.", "#...#", "#...#", "####."],
})
F_INFO_S = Fon("info_slot", Gaya({1}, [(BAYANG, 15)], 5))
# POWER hanya 19 piksel sebelum ",3": KUASA dengan huruf 3 lajur (seperti P/O/U asal)
F_INFO_S3 = Fon("info_slot_sempit", F_INFO_S.gaya, tambahan={
    "K": ["#.#", "#.#", "##.", "#.#", "#.#"],
    "U": ["#.#", "#.#", "#.#", "#.#", "###"],
    "A": ["###", "#.#", "###", "#.#", "#.#"],
    "S": ["###", "#..", "###", "..#", "###"],
})
_kredit = []
for _dy in (0, 160):
    _kredit += [
        Label("CREDIT", "KREDIT", (177, 9 + _dy, 206, 14 + _dy), 9 + _dy, F_KREDIT_S,
              had=(178, 9 + _dy, 206, 14 + _dy), ekstrak=_dy == 0),
        Label("PAYOUT", "BAYARAN", (209, 9 + _dy, 239, 14 + _dy), 9 + _dy, F_KREDIT_S,
              had=(209, 9 + _dy, 239, 14 + _dy), ekstrak=_dy == 0),
    ]
KERJA.append(Kerja("slot_machine/menu.png", peta_gabung(["slot_machine/menu.bin", "slot_machine/info_box.bin"], 32),
                   _kredit + [
    Label("INFO.", None, (128, 148, 162, 157), 149, F_BUTANG_S),  # hanya untuk huruf I, N, O
    # tile hujung butang (x224+) dikongsi dengan butang INFO./CANCEL, jadi
    # HENTI dianjak ke kiri supaya kekal sebelum x223
    Label("QUIT", "HENTI", (186, 148, 223, 157), 149, F_BUTANG_S, had=(186, 148, 223, 157), ekstrak=False,
          jajar=("kanan", 221)),
    Label("CANCEL", "BATAL", (128, 308, 166, 317), 309, F_BUTANG_S, had=(128, 308, 166, 317), jajar="kiri"),
    Label("BIG", None, (184, 192, 200, 199), 193, F_INFO_S),  # sumber huruf sahaja
    Label("BONUS", None, (200, 192, 224, 199), 193, F_INFO_S),
    Label("REPLAY", "ULANG", (208, 272, 239, 279), 273, F_INFO_S, jajar="kiri"),
    Label("POWER", "KUASA", (208, 280, 230, 287), 281, F_INFO_S3, jajar="kiri", ekstrak=False),
], pratonton=(80, 0, 240, 320)))

# reel_symbols/7.png: simbol gulungan REPLAY (32x32). Isi 3, bayang f, latar putih 1.
F_REEL = Fon("simbol_replay", Gaya({3}, [(BAYANG, 15)], 5), tambahan={
    "U": ["#.#", "#.#", "#.#", "#.#", "###"],
    "N": ["#..#", "##.#", "#.##", "#..#", "#..#"],
    "G": ["###", "#..", "#.#", "#.#", "###"],
})
KERJA.append(Kerja("slot_machine/reel_symbols/7.png", terus(0), [
    Label("REPLAY", "ULANG", (4, 13, 29, 19), 13, F_REEL, had=(4, 13, 28, 18), latar=1),
]))

# digital_display.png: paparan titik (dot-matrix) 19 lajur x pic 3 piksel
# (titik 2x2, x = 4 + 3c). INSERT (baris 64-79, 5 baris titik y = 65 + 3r)
# -> TARUH (bertaruh). Perkataan lain (REEL TIME, STOP, WIN, LOSE, BONUS, BIG,
# REG) tidak muat dalam 19 lajur dalam BM atau disusun huruf demi huruf oleh
# kod sprite, jadi dikekalkan.
TITIK_TARUH = {
    "T": ["###", ".#.", ".#.", ".#.", ".#."],
    "A": [".#.", "#.#", "###", "#.#", "#.#"],
    "R": ["##.", "#.#", "##.", "#.#", "#.#"],
    "U": ["#.#", "#.#", "#.#", "#.#", "###"],
    "H": ["#.#", "#.#", "###", "#.#", "#.#"],
}


def _taruh(kv):
    for y in range(64, 80):
        for x in range(64):
            if kv[x, y] == 1:
                kv[x, y] = 0
    c0 = 0
    for h in "TARUH":
        for r, baris in enumerate(TITIK_TARUH[h]):
            for c, ch in enumerate(baris):
                if ch == "#":
                    x, y = 4 + 3 * (c0 + c), 65 + 3 * r
                    for dx in (0, 1):
                        for dy in (0, 1):
                            kv[x + dx, y + dy] = 1
        c0 += len(TITIK_TARUH[h][0]) + 1
    assert c0 - 1 <= 19


KERJA.append(Kerja("slot_machine/digital_display.png", terus(0), [], pasca=_taruh, pratonton=(0, 64, 64, 80)))


class _PratontonTajuk:
    """Bar tajuk keputusan contest (title_<tahap>.bin + title_<kategori>.bin +
    title.bin) untuk pratonton sahaja: sebelum (asal) dan selepas."""
    rel = "contest/results_screen/tiles.png"
    pratonton = None

    def __init__(self, baru=None, bins=None):
        self.baru, self.bins = baru, bins

    def _bina(self, im, data):
        # tiga baris: NORMAL+COOL, HYPER+BEAUTY, LINK+TOUGH (21 sel lebar)
        susunan = [("normal", "cool"), ("hyper", "beauty"), ("link", "tough")]
        e = []
        for tahap, kat in susunan:
            t = struct.unpack("<%dH" % (len(data[tahap]) // 2), data[tahap])
            k = struct.unpack("<10H", baca_git(G + f"contest/results_screen/title_{kat}.bin"))
            c = struct.unpack("<12H", data["title"])
            w = len(t) // 2
            for r in range(2):
                baris = list(t[r * w:(r + 1) * w]) + list(k[r * 5:(r + 1) * 5]) + list(c[r * 6:(r + 1) * 6])
                e += baris + [0] * (21 - len(baris))
        return kanvas_peta(im, None, 21, 0, struct.pack("<%dH" % len(e), *e))

    def data(self, baru):
        d = {t: baca_git(G + f"contest/results_screen/title_{t}.bin") for t in ("normal", "hyper", "link")}
        d["title"] = baca_git(G + "contest/results_screen/title.bin")
        if baru:
            d.update({rel.split("title_")[1][:-4]: b for rel, b in FAIL_LAIN()})
        return d

    def kanvas(self):
        return self._bina(asal(G + self.rel), self.data(False))


def main():
    global LONGGAR
    LONGGAR = "--semak" in sys.argv
    sedia_fon(KERJA)
    if "--huruf" in sys.argv:
        dicetak = set()
        for k in KERJA:
            for lb in k.label:
                f = lb.fon
                if f.nama in dicetak:
                    continue
                dicetak.add(f.nama)
                print("==", f.nama)
                for h in sorted(f.huruf):
                    g = f.huruf[h]
                    w, t = lebar_glyph(g), max(y for _, y in g) + 1
                    print(" ", h, " ".join("".join("%x" % g[(x, y)] if (x, y) in g else "."
                                                   for x in range(w)) for y in range(t)))
        return
    if "--semak" in sys.argv and "--pratonton" not in sys.argv:
        for k in KERJA:
            kv = proses(k, semak=True)
            a = k.kanvas()
            beza = [(x, y) for y in range(kv.h) for x in range(kv.w) if kv.buf[y][x] != a.buf[y][x]]
            print(f"{k.rel}: {len(beza)} piksel berbeza")
            if "-v" in sys.argv:
                baris = collections.Counter(y for _, y in beza)
                print("   baris:", sorted(baris.items())[:40])
        return
    hasil = []
    semak = "--semak" in sys.argv  # dengan --pratonton: lukis semula perkataan Inggeris
    for k in KERJA:
        kv = proses(k, semak)
        im = kv.simpan()
        a = asal(G + k.rel)
        assert im.mode == "P" and im.size == a.size and im.getpalette() == a.getpalette(), k.rel
        hasil.append((k, a, im, kv))
    if "--pratonton" in sys.argv:
        pt = _PratontonTajuk()
        im_hasil = next(im for k, _, im, _ in hasil if k.rel == pt.rel)
        hasil.append((pt, asal(G + pt.rel), im_hasil, pt._bina(im_hasil, pt.data(not semak))))
        pratonton(hasil, sys.argv[sys.argv.index("--pratonton") + 1])
        return
    for k, _, im, kv in hasil:
        im.save(ROOT / G / k.rel)
        if k.bin_keluar:
            (ROOT / G / k.bin_keluar).write_bytes(ke_bin(kv))
            print("ditulis:", k.bin_keluar)
    for rel, data in FAIL_LAIN():
        (ROOT / G / rel).write_bytes(data)
        print("ditulis:", rel)
    print(f"{len(hasil)} fail PNG ditulis.")


def pratonton(hasil, keluar, skala=3, maks_tinggi=900):
    """Sebelum (kiri) / selepas (kanan) kanvas logik setiap fail; dipecah ke
    beberapa fail jika terlalu tinggi (FAIL.png, FAIL_2.png, ...)."""
    baris = []
    for k, a, im, kv in hasil:
        ka = k.kanvas()
        senarai = k.pratonton or (0, 0, kv.w, kv.h)
        if isinstance(senarai[0], int):
            senarai = [senarai]
        for kotak in senarai:
            baris.append((ke_rgb(ka, a, kotak), ke_rgb(kv, a, kotak)))
    halaman, cur, h = [], [], 0
    for a, b in baris:
        if cur and h + a.height > maks_tinggi // skala:
            halaman.append(cur)
            cur, h = [], 0
        cur.append((a, b))
        h += a.height + 4
    if cur:
        halaman.append(cur)
    for i, hal in enumerate(halaman):
        W = max(a.width * 2 + 6 for a, _ in hal)
        H = sum(a.height + 4 for a, _ in hal)
        k = Image.new("RGB", (W, H), (255, 0, 255))
        y = 0
        for a, b in hal:
            k.paste(a, (0, y))
            k.paste(b, (a.width + 6, y))
            y += a.height + 4
        nama = keluar if i == 0 else keluar.replace(".png", f"_{i + 1}.png")
        k.resize((W * skala, H * skala), Image.NEAREST).save(nama)
        print("pratonton:", nama)


def ke_rgb(kv, im, kotak):
    pal = im.getpalette()
    x0, y0, x1, y1 = kotak
    o = Image.new("RGB", (x1 - x0, y1 - y0), (40, 40, 40))
    px = o.load()
    for y in range(y0, y1):
        for x in range(x0, x1):
            if kv.boleh(x, y):
                v = kv.buf[y][x]
                px[x - x0, y - y0] = tuple(pal[v * 3:v * 3 + 3])
    return o


if __name__ == "__main__":
    main()
