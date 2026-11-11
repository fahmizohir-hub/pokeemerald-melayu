#!/usr/bin/env python3
"""Lukis semula perkataan Inggeris dalam pelbagai grafik antara muka dalam BM.

Jalankan dalam WSL (perlu Pillow):
    python3 tools/jana_grafik_lain_a.py --huruf            # abjad yang diekstrak
    python3 tools/jana_grafik_lain_a.py --semak            # lukis semula EN, kira beza
    python3 tools/jana_grafik_lain_a.py --pratonton F.png  # sebelum/selepas (4x)
    python3 tools/jana_grafik_lain_a.py                    # tulis PNG

Sentiasa bermula daripada fail asal (tag git `asal`), jadi boleh diulang.
Mod P, saiz dan palet setiap PNG dikekalkan (diasert sebelum tulis).

Cara kerja: setiap label diberi `peta` (koordinat logik -> koordinat helaian),
`kotak` logik yang boleh diubah, baris huruf, warna dakwat/bayang/garis luar dan
latar. Huruf diekstrak daripada perkataan Inggeris asal; huruf yang tiada
dilukis dalam gaya yang sama (TAMBAHAN). Peta jubin (tilemap) disemak supaya
setiap jubin yang diubah hanya dipaparkan di kedudukan label itu sahaja.

Fail & kekangan (lihat juga komen setiap bahagian di bawah):
- trainer_card/tiles.png: tajuk 11 jubin (128-138/144-154; jubin 139/155 ialah
  hujung yang juga dipakai terbalik di kiri, tidak disentuh). LENCANA dalam
  jubin 6-11 (48 piksel). Huruf 7 lajur disempitkan ke 6 supaya muat 88 px.
- trainer_card/frlg/tiles.png: tajuk 12 jubin (96 piksel); huruf 7 lajur
  terlalu lebar untuk KAD JURULATIH, jadi lajur tengah huruf lebar dibuang
  (6 lajur). Kad belakang: "TRAINER:" (7 jubin) -> NAMA: (nama pemain dicetak
  selepasnya, sama seperti gText_TrainerCardName).
- frontier_pass/bg.png: tajuk, BATAL (2 keadaan), kad mini (biasa/diserlah,
  kapsul tajuk dipanjangkan, IDNo dianjak) + map_and_card.png (kad zum 8bpp).
- naming_screen/*: halaman papan kekunci, BACK -> PADAM (butang ini memadam
  aksara), [B] BUTANG. OK/START/SELECT ialah nama butang, kekal.
- pokemon_storage/menu.png: PASUKAN, BATAL, TUTUP KOTAK (2 keadaan).
- bag/check_berry.png: lima rasa BERRY (kekal di tengah slot masing-masing).
- interface/menu_info.png (ikon jenis disalin dari graphics/types + label TM),
  interface/mon_markings_menu.png (BATAL).
- shop/money.png, battle_frontier/tourney_buttons.png, easy_chat/*,
  union_room_chat/* (bar butang disusun semula), link/321start.png (MULA).
"""
import collections
import struct
import subprocess
import sys
from io import BytesIO
from pathlib import Path

from PIL import Image, ImageDraw

ROOT = Path(__file__).resolve().parent.parent
_CACHE = {}


def git_show(rel, rev="asal"):
    key = (rev, rel)
    if key not in _CACHE:
        _CACHE[key] = subprocess.run(["git", "-C", str(ROOT), "show", f"{rev}:{rel}"],
                                     capture_output=True, check=True).stdout
    return _CACHE[key]


def asal(rel):
    return Image.open(BytesIO(git_show(rel)))


# ============================================================ peta koordinat
class Peta:
    """Peta koordinat logik (x, y) -> koordinat helaian PNG."""

    def __init__(self, fn, nama=""):
        self.fn = fn
        self.nama = nama

    def __call__(self, x, y):
        return self.fn(x, y)


def terus(dx=0, dy=0):
    return Peta(lambda x, y: (x + dx, y + dy), "terus")


def baca_peta_jubin(rel_bin, bpe=2):
    data = git_show(rel_bin)
    if bpe == 1:
        return list(data)
    return list(struct.unpack(f"<{len(data) // 2}H", data))


def jubin(rel_bin, W, tx0, ty0, ntx, nty, lebar_helaian, off=0, bpe=2, kongsi=()):
    """Peta melalui tilemap: kawasan ntx x nty jubin bermula (tx0, ty0).

    `kongsi`: senarai (rel_bin, W, [(tx, ty), ...], off, bpe) tempat lain yang
    BOLEH memaparkan jubin yang sama pada kedudukan relatif yang sama (contoh:
    keadaan diserlahkan). Semua penggunaan lain dianggap ralat."""
    ent = baca_peta_jubin(rel_bin, bpe)
    tpr = lebar_helaian // 8
    jadual = {}
    for j in range(nty):
        for i in range(ntx):
            e = ent[(ty0 + j) * W + tx0 + i]
            t = (e & 0x3FF if bpe == 2 else e) - off
            assert bpe == 1 or not (e >> 10) & 3, f"{rel_bin}: jubin terbalik di {(tx0 + i, ty0 + j)}"
            jadual[(i, j)] = t
    # semak perkongsian jubin
    tempat = [(rel_bin, W, [(tx0, ty0)], off, bpe)] + list(kongsi)
    sah = collections.defaultdict(set)
    for (i, j), t in jadual.items():
        sah[t].add((i, j))
    gabung = {}
    for rb, w, asal_xy, o, b in tempat:  # gabung asal bagi bin yang sama
        gabung.setdefault((rb, w, o, b), []).extend(asal_xy)
    for (rb, w, o, b), asal_xy in gabung.items():
        en = baca_peta_jubin(rb, b)
        for n, e in enumerate(en):
            t = (e & 0x3FF if b == 2 else e) - o
            if t not in sah:
                continue
            x, y = n % w, n // w
            if not any((x - ax, y - ay) in sah[t] for ax, ay in asal_xy):
                sys.exit(f"JUBIN DIKONGSI: {rb} jubin {t} di {(x, y)} (label {rel_bin} {tx0},{ty0})")

    def peta(x, y):
        t = jadual[(x // 8, y // 8)]
        return (t % tpr) * 8 + x % 8, (t // tpr) * 8 + y % 8
    return Peta(peta, f"jubin {rel_bin}")


def sprite_1d(t0, lebar, lebar_helaian):
    """Sprite 1D (lebar piksel) bermula pada jubin t0 dalam helaian."""
    tw, tpr = lebar // 8, lebar_helaian // 8

    def peta(x, y):
        n = t0 + (y // 8) * tw + x // 8
        return (n % tpr) * 8 + x % 8, (n // tpr) * 8 + y % 8
    return Peta(peta, "sprite")


# ============================================================ label
L = []


def label(fail, peta, kotak, y, h, dakwat, fon, en, ms, **k):
    """kotak = (x0, y0, x1, y1) logik yang boleh diubah; y/h = baris huruf.

    dakwat: warna utama (atau tuple: utama, warna lain dalam huruf).
    Pilihan: bayang (warna, arah kanan/bawah/pepenjuru), garis (garis luar
    sisi), sudut (garis luar pepenjuru), latar (int / fungsi(x, y) / None =
    warna paling kerap sebaris), jajar ("tengah", "kiri", "kanan" atau x),
    jarak (antara huruf), ruang (lebar ruang), ganti (bentuk huruf khas),
    kumpul (warna untuk mengasingkan huruf; lalai semua dakwat), padam
    (warna yang dipadam), sempit (buang lajur tengah huruf >= n lajur)."""
    if isinstance(dakwat, int):
        dakwat = (dakwat,)
    d = dict(fail=fail, peta=peta, kotak=kotak, y=y, h=h, dakwat=tuple(dakwat), fon=fon,
             en=en, ms=ms, bayang=None, garis=None, sudut=None, latar=None, jajar="tengah",
             jarak=1, ruang=3, ganti={}, kumpul=None, padam=None, sempit=None,
             arah_bayang=((1, 0), (0, 1), (1, 1)), nama=None, lajur=None)
    for kk, v in k.items():
        assert kk in d, kk
        d[kk] = v
    if d["kumpul"] is None:
        d["kumpul"] = d["dakwat"]
    if d["padam"] is None:
        d["padam"] = set(d["dakwat"]) | {c for c in (d["bayang"], d["garis"], d["sudut"]) if c is not None}
    L.append(d)
    return d


def huruf_kata(kata):
    """Senarai token huruf (tanpa ruang). '{PKMN}' = satu glif."""
    hasil, i = [], 0
    while i < len(kata):
        if kata[i] == "{":
            j = kata.index("}", i)
            hasil.append(kata[i:j + 1])
            i = j + 1
        else:
            hasil.append(kata[i])
            i += 1
    return hasil


def baca(im, lb):
    px = im.load()
    p = lb["peta"]
    return lambda x, y: px[p(x, y)]


def kumpulan_lajur(get, lb):
    if lb["lajur"]:  # sempadan huruf ditetapkan tangan (huruf bersentuhan)
        return [list(range(a, b)) for a, b in lb["lajur"]]
    x0, _, x1, _ = lb["kotak"]
    lajur = [x for x in range(x0, x1)
             if any(get(x, y) in lb["kumpul"] for y in range(lb["y"], lb["y"] + lb["h"]))]
    kump, cur = [], []
    for x in lajur:
        if cur and x != cur[-1] + 1:
            kump.append(cur)
            cur = []
        cur.append(x)
    if cur:
        kump.append(cur)
    return kump


def ekstrak(imej):
    abjad = collections.defaultdict(dict)
    for lb in L:
        if lb["en"] is None:
            continue
        get = baca(imej[lb["fail"]], lb)
        kump = kumpulan_lajur(get, lb)
        huruf = [c for c in huruf_kata(lb["en"]) if c != " "]
        if len(kump) != len(huruf):
            print(f"amaran: {lb['fail']} {lb['en']}: {len(kump)} kumpulan != {len(huruf)} huruf",
                  file=sys.stderr)
            continue
        utama = lb["dakwat"][0]
        semua = set(lb["dakwat"])
        lb["tempatan"] = {}
        for n, (h, xs) in enumerate(zip(huruf, kump)):
            # lajur tambahan di kanan yang hanya ada dakwat kedua (anti-alias)
            had = kump[n + 1][0] if n + 1 < len(kump) else lb["kotak"][2]
            xe = xs[-1] + 1
            while xe < had and any(get(xe, y) in semua for y in range(lb["y"], lb["y"] + lb["h"])):
                xe += 1
            rows = []
            for y in range(lb["y"], lb["y"] + lb["h"]):
                s = ""
                for x in range(xs[0], xe):
                    c = get(x, y)
                    s += SIMBOL[lb["dakwat"].index(c)] if c in semua else "."
                rows.append(s)
            g = (tuple(rows), len(xs))
            lb["tempatan"].setdefault(h, g)
            lama = abjad[lb["fon"]].setdefault(h, g)
            if lama != g and "--huruf" in sys.argv:
                print(f"beza: {lb['fon']} {h} ({lb['en']})", file=sys.stderr)
    for f, t in TAMBAHAN.items():
        for kk, v in t.items():
            if isinstance(v, tuple):
                abjad[f].setdefault(kk, (tuple(v[0]), v[1]))
            else:
                abjad[f].setdefault(kk, (tuple(v), len(v[0])))
    return abjad


def sempitkan(g, n):
    rows, adv = g
    if adv < n:
        return g
    tengah = adv // 2
    return tuple(r[:tengah] + r[tengah + 1:] for r in rows), adv - 1


def glif(lb, c, abjad, semak):
    if not semak and c in lb["ganti"]:
        v = lb["ganti"][c]
        g = (tuple(v[0]), v[1]) if isinstance(v, tuple) else (tuple(v), len(v[0]))
    elif semak and c in lb.get("tempatan", {}):
        g = lb["tempatan"][c]
    else:
        g = abjad[lb["fon"]][c]
    if lb["sempit"] and not semak:
        g = sempitkan(g, lb["sempit"])
    return g


def lebar_teks(lb, kata, abjad, semak):
    w, x = 0, 0
    for c in huruf_kata(kata):
        if c == " ":
            x += lb["ruang"]
            continue
        rows, adv = glif(lb, c, abjad, semak)
        w = x + adv
        x += adv + lb["jarak"]
    return w


def lukis(imej, abjad, semak=False):
    for lb in L:
        kata = lb["en"] if semak else lb["ms"]
        if kata is None or (not semak and lb["ms"] == lb["en"]):
            continue
        im = imej[lb["fail"]]
        px = im.load()
        p = lb["peta"]
        x0, y0, x1, y1 = lb["kotak"]
        get = baca(im, lb)
        kump = kumpulan_lajur(get, lb) if lb["en"] else []
        if kump:
            kiri, kanan = kump[0][0], kump[-1][-1]
        else:
            kiri, kanan = x0, x1 - 1
        w = lebar_teks(lb, kata, abjad, semak)
        j = lb["jajar"]
        if isinstance(j, int):
            x = j
        elif j == "kiri":
            x = kiri
        elif j == "kanan":
            x = kanan + 1 - w
        else:
            x = (kiri + kanan + 1 - w) // 2
        # latar
        if callable(lb["latar"]):
            latar = lb["latar"]
        elif lb["latar"] is not None:
            latar = lambda xx, yy, c=lb["latar"]: c
        else:
            per_baris = {}
            semua = collections.Counter()
            for yy in range(y0, y1):
                kira = collections.Counter(get(xx, yy) for xx in range(x0, x1)
                                           if get(xx, yy) not in lb["padam"])
                semua.update(kira)
                if kira:
                    per_baris[yy] = kira.most_common(1)[0][0]
            lalai = semua.most_common(1)[0][0]
            latar = lambda xx, yy: per_baris.get(yy, lalai)
        # padam
        for yy in range(y0, y1):
            for xx in range(x0, x1):
                if get(xx, yy) in lb["padam"]:
                    px[p(xx, yy)] = latar(xx, yy)
        # bina piksel baharu
        dakwat = {}
        utama = lb["dakwat"][0]
        for c in huruf_kata(kata):
            if c == " ":
                x += lb["ruang"]
                continue
            rows, adv = glif(lb, c, abjad, semak)
            for dy, baris in enumerate(rows):
                for dx, ch in enumerate(baris):
                    if ch != ".":
                        dakwat[(x + dx, lb["y"] + dy)] = lb["dakwat"][SIMBOL.index(ch)]
            x += adv + lb["jarak"]
        titik = dict()
        if lb["sudut"] is not None:
            for (a, b) in dakwat:
                for dx, dy in ((1, 1), (1, -1), (-1, 1), (-1, -1)):
                    titik[(a + dx, b + dy)] = lb["sudut"]
        if lb["garis"] is not None:
            for (a, b) in dakwat:
                for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                    titik[(a + dx, b + dy)] = lb["garis"]
        if lb["bayang"] is not None:
            for (a, b) in dakwat:
                for dx, dy in lb["arah_bayang"]:
                    titik[(a + dx, b + dy)] = lb["bayang"]
        titik.update(dakwat)
        nama = lb["nama"] or f"{lb['fail']} {kata}"
        for (a, b), c in titik.items():
            if not (x0 <= a < x1 and y0 <= b < y1):
                if (a, b) in dakwat and not semak:
                    sys.exit(f"TAK MUAT: {nama} piksel {(a, b)} di luar kotak {lb['kotak']}")
                if lb["bayang"] is not None and c == lb["bayang"] and not semak:
                    continue  # bayang terpotong di tepi kotak dibenarkan
                continue
            px[p(a, b)] = c


# ============================================================ huruf tambahan
# '#' = warna dakwat utama label, '%' '&' '@' = dakwat ke-2/3/4; '.' = kosong.
SIMBOL = "#%&@$"
TAMBAHAN = collections.defaultdict(dict)

# ------------------------------------------------------------ KAD JURULATIH (Hoenn)
TC = "graphics/trainer_card/tiles.png"
TC_BINS = ["graphics/trainer_card/front.bin", "graphics/trainer_card/back.bin",
           "graphics/trainer_card/front_link.bin", "graphics/trainer_card/bg.bin"]


TAMBAHAN["tc_tajuk"] = {  # 6 baris, garisan 2 piksel
    "K": ["##...##", "##..##.", "####...", "##.##..", "##..##.", "##...##"],
    "J": ["....##", "....##", "....##", "....##", "##..##", ".####."],
    "U": ["##...##", "##...##", "##...##", "##...##", "##...##", ".#####."],
    "L": ["##....", "##....", "##....", "##....", "##....", "######"],
    "H": ["##...##", "##...##", "#######", "##...##", "##...##", "##...##"],
}
TAMBAHAN["tc_lencana"] = {
    "L": ["##...", "##...", "##...", "##...", "##...", "#####"],
    "N": ["##..##", "###.##", "######", "##.###", "##..##", "##..##"],
    "C": [".#####", "##....", "##....", "##....", "##....", ".#####"],
}
TAMBAHAN["tcf_tajuk"] = {  # 9 baris; % (warna 9) = jalur terang di atas palang mendatar
    "K": ["##...##", "##..##.", "##.##..", "####...", "###....", "####...", "##.##..", "##..##.", "##...##"],
    "J": [".....##", ".....##", ".....##", ".....##", ".....##", ".....##", "##...##", "##%%%##", "#######"],
    "U": ["##...##", "##...##", "##...##", "##...##", "##...##", "##...##", "##...##", "##%%%##", "#######"],
    "L": ["##.....", "##.....", "##.....", "##.....", "##.....", "##.....", "##.....", "##%%%%%", "#######"],
    "H": ["##...##", "##...##", "##...##", "##%%%##", "#######", "##...##", "##...##", "##...##", "##...##"],
}
TAMBAHAN["tcf_lencana"] = {
    "L": ["##..", "##..", "##..", "##..", "####"],
    "N": ["####", "##.#", "##.#", "##.#", "##.#"],
    "C": ["####", "##..", "##..", "##..", "####"],
}
TAMBAHAN["tcf_jurulatih"] = {
    "M": ["##...##", "###.###", "##.#.##", "##...##", "##...##", "##...##"],
}


def tc_jubin(rel_bin, W, tx0, ty0, ntx, nty, helaian, bins):
    kongsi = [(b, W, [(tx0, ty0)], 0, 2) for b in bins if b != rel_bin]
    return jubin(rel_bin, W, tx0, ty0, ntx, nty, helaian, kongsi=kongsi)


# Tajuk: putih f, anti-alias 8, latar biru d (baris 3-12 sahaja; baris 2 & 13 bingkai)
label(TC, tc_jubin(TC_BINS[0], 30, 3, 2, 11, 2, 128, TC_BINS), (0, 3, 88, 13), 5, 6, (0xF, 0x8),
      "tc_tajuk", "TRAINER CARD", "KAD JURULATIH", kumpul=(0xF,), ruang=3, sempit=7)
# LENCANA: putih 1 di atas jalur a/b, tanpa bayang
label(TC, tc_jubin(TC_BINS[0], 30, 3, 14, 6, 1, 128, TC_BINS), (0, 0, 48, 8), 1, 6, 0x1,
      "tc_lencana", "BADGES", "LENCANA", jajar="kiri")

# ------------------------------------------------------------ KAD JURULATIH (FRLG)
TCF = "graphics/trainer_card/frlg/tiles.png"
TCF_BINS = ["graphics/trainer_card/frlg/front.bin", "graphics/trainer_card/frlg/back.bin",
            "graphics/trainer_card/frlg/front_link.bin", "graphics/trainer_card/frlg/bg.bin"]
label(TCF, tc_jubin(TCF_BINS[0], 30, 2, 2, 12, 2, 128, TCF_BINS), (0, 0, 96, 16), 4, 9, (0x8, 0x9),
      "tcf_tajuk", "TRAINER CARD", "KAD JURULATIH", sempit=7, jajar="kiri", ruang=6)
label(TCF, tc_jubin(TCF_BINS[0], 30, 2, 15, 8, 1, 128, TCF_BINS), (0, 0, 64, 8), 2, 5, 0xE,
      "tcf_lencana", "BADGES", "LENCANA", jajar="kiri")
label(TCF, tc_jubin(TCF_BINS[1], 30, 10, 3, 7, 1, 128, TCF_BINS), (0, 0, 56, 7), 0, 6, 0x5,
      "tcf_jurulatih", "TRAINER:", "NAMA:", jajar="kanan")


# ------------------------------------------------------------ PAS FRONTIER
FP = "graphics/frontier_pass/bg.png"
FP_BG = "graphics/frontier_pass/bg.bin"
FP_BATAL = "graphics/frontier_pass/cancel.bin"
FP_BATAL2 = "graphics/frontier_pass/cancel_highlighted.bin"
FP_KAD = "graphics/frontier_pass/small_map_and_card.bin"
FP_SEMUA = [(FP_KAD, 12, [], 0, 2), ("graphics/frontier_pass/record_frame.bin", 12, [], 0, 2)]
# Tajuk FRONTIER PASS -> PAS FRONTIER (huruf sama, susunan BM)
label(FP, jubin(FP_BG, 32, 1, 0, 15, 2, 128, kongsi=FP_SEMUA), (0, 0, 120, 16), 2, 13, 0x1,
      "fp_tajuk", "FRONTIER PASS", "PAS FRONTIER")
# BATAL: bg.bin memaparkan jubin butang (21,0); cancel*.bin = 9x2
for _bin, _dakwat in ((FP_BATAL, (0x4, 0x3)), (FP_BATAL2, (0xD, 0xC))):
    _k = [(FP_BG, 32, [(21, 0)], 0, 2), (FP_BATAL, 9, [(0, 0)], 0, 2), (FP_BATAL2, 9, [(0, 0)], 0, 2)]
    label(FP, jubin(_bin, 9, 0, 0, 9, 2, 128, kongsi=[k for k in _k if k[0] != _bin] + FP_SEMUA),
          (16, 1, 72, 14), 3, 9, _dakwat, "fp_batal", "CANCEL", "BATAL", kumpul=_dakwat[:1], jajar="kiri")


TAMBAHAN["fp_batal"] = {
    "B": ["#####%", "######", "##..##", "##..##", "#####.", "##..##", "##..##", "######", "#####%"],
    "T": ["######", "######", "..##..", "..##..", "..##..", "..##..", "..##..", "..##..", "..##.."],
}

# ------------------------------------------------------------ PC (sistem simpanan)
# menu.png dimuat pada jubin 256 (off=256). PKMN DATA tidak diubah (DATA = BM).
# Menu pasukan memakai palet 1 (indeks PNG 0x1N).
PC = "graphics/pokemon_storage/menu.png"
PCD = "graphics/pokemon_storage/"
PC_SEMUA = [(PCD + "display_menu.bin", 32, [], 256, 2), (PCD + "pkmn_data.bin", 8, [], 256, 2),
            (PCD + "party_slot_empty.bin", 4, [], 256, 2), (PCD + "party_slot_filled.bin", 4, [], 256, 2)]


def pc_jubin(rel_bin, W, tx0, ty0, ntx, nty, kongsi=()):
    lain = [k for k in PC_SEMUA + [(PCD + "close_box_button.bin", 9, [], 256, 2),
                                   (PCD + "party_menu.bin", 12, [], 256, 2)] if k[0] != rel_bin]
    return jubin(rel_bin, W, tx0, ty0, ntx, nty, 128, off=256, kongsi=list(kongsi) + lain)


# Tab PARTY POKéMON (party_menu.bin baris 20-21; N terakhir masuk ke jubin hujung)
label(PC, pc_jubin(PCD + "party_menu.bin", 12, 0, 20, 9, 2), (5, 3, 68, 13), 4, 7, 0x18,
      "pc_besar", "PARTY POKéMON", "PASUKAN", bayang=0x17, arah_bayang=((1, 1),), jajar="kiri")
# BATAL dalam menu pasukan (baris 17-18, x 7-10)
label(PC, pc_jubin(PCD + "party_menu.bin", 12, 7, 17, 4, 2), (0, 2, 32, 14), 4, 7, 0x18,
      "pc_besar", "CANCEL", "BATAL", bayang=0x17, arah_bayang=((1, 1),))
# TUTUP KOTAK: close_box_button.bin 9x4 (baris 0-1 biasa, 2-3 pudar)
label(PC, pc_jubin(PCD + "close_box_button.bin", 9, 0, 0, 9, 2), (4, 4, 68, 14), 5, 7, 0xE,
      "pc_kotak", "CLOSE BOX", "TUTUP KOTAK", bayang=0x9, arah_bayang=((1, 1),))
label(PC, pc_jubin(PCD + "close_box_button.bin", 9, 0, 2, 9, 2), (4, 4, 68, 14), 5, 7, 0x9,
      "pc_kotak", "CLOSE BOX", "TUTUP KOTAK")


TAMBAHAN["pc_besar"] = {  # 4x7
    "S": [".##.", "#..#", "#...", ".##.", "...#", "#..#", ".##."],
    "U": ["#..#", "#..#", "#..#", "#..#", "#..#", "#..#", ".##."],
    "B": ["###.", "#..#", "#..#", "###.", "#..#", "#..#", "###."],
}
TAMBAHAN["pc_kotak"] = {  # 5x7
    "T": ["#####", "..#..", "..#..", "..#..", "..#..", "..#..", "..#.."],
    "U": ["#...#", "#...#", "#...#", "#...#", "#...#", "#...#", ".###."],
    "P": ["####.", "#...#", "#...#", "####.", "#....", "#....", "#...."],
    "K": ["#...#", "#..#.", "#.#..", "##...", "#.#..", "#..#.", "#...#"],
    "A": [".###.", "#...#", "#...#", "#####", "#...#", "#...#", "#...#"],
}

# ------------------------------------------------------------ skrin nama
NS = "graphics/naming_screen/"
# Butang tukar halaman (sprite 16x8 + 8x8 = 24 piksel pertama sahaja dipaparkan)
label(NS + "page_swap_upper.png", terus(), (0, 0, 24, 8), 0, 7, 0x1, "ns_halaman",
      "UPPER", "BESAR", bayang=0x6, latar=0x7, jajar="kiri")
label(NS + "page_swap_lower.png", terus(), (0, 0, 24, 8), 0, 7, 0x1, "ns_halaman",
      "lower", "kecil", bayang=0x8, latar=0x9, jajar="kiri",
      lajur=[(1, 2), (3, 7), (8, 13), (14, 18), (19, 22)])
label(NS + "page_swap_others.png", terus(), (0, 0, 24, 8), 0, 7, 0x1, "ns_halaman",
      "others", "lain", bayang=0xA, latar=0xB, jajar="kiri",
      lajur=[(0, 4), (4, 7), (8, 11), (12, 16), (17, 20), (20, 23)])
# BACK (padam aksara terakhir) -> PADAM; garis luar c (8 jiran), latar kuning d.
# Hanya 24 piksel untuk dakwat (bucu bingkai putih di x 5-6 dan 33-34).
label(NS + "back_button.png", terus(), (7, 4, 33, 13), 5, 7, 0x1, "ns_besar", "BACK", "PADAM",
      garis=0xC, sudut=0xC, latar=0xD, ganti={  # versi 4 lajur supaya PADAM muat
          "A": [".##.", "#..#", "#..#", "####", "#..#", "#..#", "#..#"],
          "M": ["#..#", "####", "####", "#..#", "#..#", "#..#", "#..#"]})
# [B] BUTTON -> [B] BUTANG (garis luar gelap f, latar 4)
label(NS + "back_button.png", terus(), (9, 16, 38, 23), 17, 5, 0x1, "ns_kecil", "BUTTON", "BUTANG",
      garis=0xF, sudut=0xF, latar=0x4, jajar="kiri")

# ------------------------------------------------------------ BEG: tag BERRY
# berry_tag.bin baris 12, x 4-28 (25 jubin unik); setiap rasa kekal di tengah
# slotnya (bulatan kekuatan rasa dilukis di bawah setiap label).
BT = "graphics/bag/check_berry.png"
_bt = jubin("graphics/bag/berry_tag.bin", 32, 4, 12, 25, 1, 80,
            kongsi=[("graphics/bag/berry_tag_title.bin", 32, [], 0, 2)])
for (_x0, _x1), _en, _ms in zip(((0, 39), (39, 79), (79, 119), (119, 159), (159, 200)),
                               ("SPICY", "DRY", "SWEET", "BITTER", "SOUR"),
                               ("PEDAS", "KERING", "MANIS", "PAHIT", "MASAM")):
    label(BT, _bt, (_x0, 0, _x1, 8), 0, 7, 0xB, "berry", _en, _ms, bayang=0x8, latar=0x3)

# ------------------------------------------------------------ penanda POKéMON (OK/BATAL)
# Sprite teks 32x32 bermula pada jubin 9 (helaian 200x8, 1D). CANCEL di baris 19-27.
label("graphics/interface/mon_markings_menu.png", sprite_1d(9, 32, 200), (0, 18, 32, 30), 19, 9, 0x2,
      "penanda", "CANCEL", "BATAL", bayang=0x5, latar=0x1)

# ------------------------------------------------------------ Battle Dome: butang carta
TB = "graphics/battle_frontier/tourney_buttons.png"
for _y, _en, _ms, _bay, _lat in ((5, "CANCEL", "BATAL", 0x9, 0x6), (21, "CANCEL", "BATAL", 0x8, 0x2),
                                  (69, "EXIT", "KELUAR", 0x9, 0x6), (85, "EXIT", "KELUAR", 0x8, 0x2)):
    label(TB, terus(), (4, _y, 28, _y + 7), _y, 7, 0x4, "dome", _en, _ms, bayang=_bay, latar=_lat)

# ------------------------------------------------------------ Easy Chat
EC = "graphics/easy_chat/"
# Tetingkap butang: MODE / DELETE / [B] BUTTON / CANCEL (garis luar c, latar 5)
label(EC + "button_window.png", terus(), (34, 16, 56, 22), 16, 5, 0xF, "ec_kecil", "MODE", "MOD",
      garis=0xC, sudut=0xC, latar=0x5, jajar="kanan")
label(EC + "button_window.png", terus(), (24, 29, 57, 36), 30, 5, 0xF, "ec_kecil", "DELETE", "PADAM",
      garis=0xC, sudut=0xC, latar=0x5)
label(EC + "button_window.png", terus(), (32, 40, 57, 47), 41, 5, 0xC, "ec_butang", "BUTTON", "BUTANG",
      latar=0x5, jajar="kiri")
label(EC + "button_window.png", terus(), (24, 47, 57, 54), 48, 5, 0xF, "ec_kecil", "CANCEL", "BATAL",
      garis=0xC, sudut=0xC, latar=0x5)
# Tetingkap mod (sprite 64x32 bertindan): A-Z / GROUP (besar) + MODE (kotak kecil)
label(EC + "mode.png", terus(), (36, 23, 56, 28), 23, 5, (0xC, 0xD), "ec_kotak", "MODE", "MOD", latar=0xF)
label(EC + "mode.png", terus(), (36, 55, 56, 60), 55, 5, (0xC, 0xD), "ec_kotak", "MODE", "MOD", latar=0xF)
label(EC + "mode.png", terus(), (28, 46, 56, 54), 47, 6, 0xF, "ec_besar", "GROUP", "TOPIK",
      garis=0xC, sudut=0xC, latar=0xE)

# ------------------------------------------------------------ Bilik Kesatuan: label butang R
label("graphics/union_room_chat/r_button_labels.png", terus(), (1, 52, 31, 59), 52, 7, 0xE, "urc_r",
      "REGISTER", "DAFTAR", latar=0xF,
      lajur=[(1, 4), (5, 8), (9, 13), (14, 15), (16, 20), (20, 23), (24, 27), (28, 31)])

# ------------------------------------------------------------ menu_info.png (TM dalam BEG)
# BlitMenuInfoIcon membaca helaian sebagai peta bit 128x128 (src/menu.c
# sMenuInfoIcons): ikon jenis 32x12, label 42x12. Label: huruf putih f dengan
# garis luar e di atas palang e (5 baris tengah); palang dibina semula daripada
# baris asal.
MI = "graphics/interface/menu_info.png"
TAMBAHAN["mi"] = {
    "J": ["...#", "...#", "...#", "...#", "#..#", "#..#", ".##."],
    "N": ["#..#", "##.#", "##.#", "#.##", "#.##", "#..#", "#..#"],
    "I": ["###", ".#.", ".#.", ".#.", ".#.", ".#.", "###"],
    "S": [".##.", "#..#", "#...", ".##.", "...#", "#..#", ".##."],
    "K": ["#..#", "#.#.", "##..", "##..", "#.#.", "#..#", "#..#"],
}
# KETEPATAN: huruf 3 lajur (seperti ACCURACY asal) supaya muat dalam palang 40 piksel
MI_SEMPIT = {
    "K": ["#.#", "#.#", "##.", "#..", "##.", "#.#", "#.#"],
    "E": ["###", "#..", "#..", "##.", "#..", "#..", "###"],
    "T": ["###", ".#.", ".#.", ".#.", ".#.", ".#.", ".#."],
    "P": ["##.", "#.#", "#.#", "##.", "#..", "#..", "#.."],
}


def latar_palang(rel, x0, x1, y0, y1, warna):
    """Latar: `warna` di dalam julat mendatar palang asal setiap baris, 0 di luar."""
    px = asal(rel).load()
    julat = {}
    for y in range(y0, y1):
        xs = [x for x in range(x0, x1) if px[x, y] in (warna, 0xF)]
        if xs:
            julat[y] = (min(xs), max(xs))

    def latar(x, y):
        a, b = julat.get(y, (1, 0))
        return warna if a <= x <= b else 0
    return latar


for (_x, _y), _en, _ms in (((64, 80), "TYPE", "JENIS"), ((0, 96), "POWER", "KUASA"),
                            ((64, 96), "ACCURACY", "KETEPATAN"), ((64, 112), "EFFECT", "KESAN")):
    label(MI, terus(), (_x, _y, _x + 42, _y + 12), _y + 3, 7, 0xF, "mi", _en, _ms, garis=0xE, sudut=0xE,
          latar=latar_palang(MI, _x, _x + 42, _y + 4, _y + 9, 0xE), padam={0xE, 0xF},
          ganti=MI_SEMPIT if _ms == "KETEPATAN" else {})

# Ikon jenis 32x12: salin teks BM daripada graphics/types/*.png (HEAD, sudah
# dilukis oleh tools/jana_ikon_jenis.py), baris 4-11 -> baris 2-9 ikon, dengan
# pemetaan warna (undian majoriti) daripada pasangan asal.
IKON_MI = [("normal", 0x20), ("fight", 0x64), ("flying", 0x60), ("poison", 0x80), ("ground", 0x48),
           ("rock", 0x44), ("bug", 0x6C), ("ghost", 0x68), ("steel", 0x88), ("fire", 0x24),
           ("water", 0x28), ("grass", 0x2C), ("electric", 0x40), ("psychic", 0x84), ("ice", 0x4C),
           ("dragon", 0xA0), ("dark", 0x8C)]
PANEL = []  # (fail, x0, y0, x1, y1) pratonton tambahan


def jana_ikon_jenis_menu(imej, abjad):
    im = imej[MI]
    px = im.load()
    asl = asal(MI).load()
    for nama, off in IKON_MI:
        x0, y0 = (off % 16) * 8, (off // 16) * 8
        rel = f"graphics/types/{nama}.png"
        a = Image.open(BytesIO(git_show(rel))).load()
        b = Image.open(BytesIO(git_show(rel, "HEAD"))).load()
        undi = collections.defaultdict(collections.Counter)
        for y in range(4, 12):
            for x in range(32):
                undi[a[x, y]][asl[x0 + x, y0 + y - 2]] += 1
        # warna majoriti (ikon menu_info berbeza sepiksel dua daripada ikon asal)
        peta = {k: v.most_common(1)[0][0] for k, v in undi.items()}
        for y in range(4, 12):
            for x in range(32):
                px[x0 + x, y0 + y - 2] = peta[b[x, y]]
    PANEL.append((MI, 0, 16, 128, 92))


# ------------------------------------------------------------ WANG (kedai / jual dalam BEG)
# Sprite 32x16. Huruf 5 baris berwarna kecerunan (e atas, d, c bawah) dengan garis
# luar 6 (8 jiran); piksel kelabu 2 (bayang luar) dipadam.
label("graphics/shop/money.png", terus(), (3, 3, 31, 10), 4, 5, (0xE, 0xD, 0xC), "wang", "MONEY", "WANG",
      garis=0x6, sudut=0x6, latar=0x0, padam={0xE, 0xD, 0xC, 0x6, 0x2})
TAMBAHAN["wang"] = {  # '#' = e, '%' = d, '&' = c
    "W": ["#...#", "#...#", "&.&.&", "&&.&&", "%...%"],
    "A": [".##.", "#..%", "&&&&", "&..&", "%..%"],
    "G": [".##%", "#...", "&.&&", "&..&", ".%%."],
}

# ------------------------------------------------------------ Bilik Kesatuan: bar butang sembang
# background.bin baris 0, x 7-29 (23 jubin unik) = jalur 184x8:
#   [A]OK  [B]BACK  [SELECT]SWITCH  [START]SEND
# Perkataan BM lebih panjang, jadi seluruh jalur disusun semula: ikon disalin,
# perkataan dilukis (dakwat e, garis luar f 8 jiran, termasuk baris 7) dan
# jurang dibahagi sama rata.
URC = "graphics/union_room_chat/background.png"
URC_PETA = jubin("graphics/union_room_chat/background.bin", 32, 7, 0, 23, 1, 104,
                 kongsi=[("graphics/union_room_chat/keyboard.bin", 32, [], 0, 2)])
URC_IKON = {"A": (0, 8), "B": (30, 38), "SELECT": (70, 92), "START": (136, 158)}
URC_KATA = {"OK": (8, 19), "BACK": (38, 59), "SWITCH": (93, 125), "SEND": (159, 180)}
for _en, (_a, _b) in URC_KATA.items():  # untuk ekstrak huruf sahaja
    label(URC, URC_PETA, (_a, 0, _b, 8), 0, 7, 0xE, "urc", _en, None, garis=0xF, sudut=0xF)
TAMBAHAN["urc"] = {  # baris 0 kosong, huruf baris 1-6
    "M": [".....", "#...#", "##.##", "#.#.#", "#...#", "#...#", "#...#"],
    "L": ["....", "#...", "#...", "#...", "#...", "#...", "####"],
    "U": ["....", "#..#", "#..#", "#..#", "#..#", "#..#", ".##."],
    "R": ["....", "###.", "#..#", "###.", "#.#.", "#..#", "#..#"],
}
# (ikon, perkataan BM, jurang ikon->perkataan)
URC_SUSUN = [("A", "OK", 0), ("B", "KEMBALI", 0), ("SELECT", "TUKAR", 1), ("START", "HANTAR", 1)]


def jana_bar_urc(imej, abjad):
    lb = next(l for l in L if l["fon"] == "urc")
    im = imej[URC]
    px = im.load()
    asl = asal(URC).load()
    p = URC_PETA
    W = 184
    ikon = {k: [[asl[p(x, y)] for y in range(8)] for x in range(a, b)] for k, (a, b) in URC_IKON.items()}

    def kata_px(kata):
        x, d = 1, {}
        for c in kata:
            rows, adv = glif(lb, c, abjad, False)
            for dy, r in enumerate(rows):
                for dx, ch in enumerate(r):
                    if ch == "#":
                        d[(x + dx, dy)] = 0xE
            x += adv + 1
        lebar = x  # termasuk 1 lajur garis luar di kanan
        t = {}
        for (a, b) in d:
            for dx in (-1, 0, 1):
                for dy in (-1, 0, 1):
                    t[(a + dx, b + dy)] = 0xF
        t.update(d)
        return t, lebar + 1
    blok = []
    for k, kata, jurang in URC_SUSUN:
        t, w = kata_px(kata)
        blok.append((k, t, w, jurang))
    isi = sum(len(ikon[k]) + jurang + w for k, _, w, jurang in blok)
    baki = W - isi
    if baki < 3:
        sys.exit(f"TAK MUAT: bar sembang {isi} > {W}")
    sela = (baki - 2) // 3  # jurang antara kumpulan; baki (>= 2) di hujung kanan
    # latar
    for x in range(W):
        for y in range(8):
            px[p(x, y)] = 0xD if y == 7 else 0x1
    x = 0
    for k, t, w, jurang in blok:
        for i, kol in enumerate(ikon[k]):
            for y in range(8):
                px[p(x + i, y)] = kol[y]
        x += len(ikon[k]) + jurang
        for (a, b), c in t.items():
            if 0 <= b < 8:
                px[p(x + a, b)] = c
        x += w + sela
    PANEL.append(("urc", URC_PETA, 184, 8))


# ------------------------------------------------------------ PAS FRONTIER: kad kecil
# Kad jurulatih mini (small_map_and_card.bin baris 14-20 biasa, 21-27 diserlah;
# bg.bin (16,10) memakai jubin yang sama). Jubin dalaman dikongsi antara keadaan
# biasa & diserlah pada kedudukan relatif yang sama. Kad zum (map_and_card.png,
# 8bpp afin) disalin daripada kad biasa dengan pemetaan warna.
FP_K = [(FP_BG, 32, [(17, 11)], 0, 2), (FP_KAD, 12, [(1, 22)], 0, 2),
        ("graphics/frontier_pass/record_frame.bin", 12, [], 0, 2)]
FP_KAD_PETA = jubin(FP_KAD, 12, 1, 15, 10, 5, 128, kongsi=FP_K)  # dalaman x 8-87, y 8-47
# Label (koordinat dalaman: x + 8, y + 8 = koordinat kad). Palet 1: dakwat 0x1F,
# bayang 0x1E di kanan.
# (NAME: kotak berhenti sebelum medan bertitik 0x1E di kanannya)
for (_y, _x1), _en, _ms in (((8, 18), "NAME", "NAMA"), ((18, 32), "MONEY", "WANG"), ((28, 32), "TIME", "MASA")):
    label(FP, FP_KAD_PETA, (1, _y, _x1, _y + 4), _y, 4, 0x1F, "fp_kad", _en, _ms,
          bayang=0x1E, arah_bayang=((1, 0),), jajar="kiri")
label(FP, FP_KAD_PETA, (1, 23, 40, 27), 23, 4, 0x1F, "fp_kad", "POKéDEX", None,
      bayang=0x1E, arah_bayang=((1, 0),))
TAMBAHAN["fp_kad"] = {  # 3x4
    "W": ["#.#", "#.#", "###", "#.#"],
    "G": [".##", "#..", "#.#", ".##"],
    "S": [".##", "#..", "..#", "##."],
}
# Tajuk kapsul "TRAINER CARD" (fon 3 baris, putih 0x1F atas biru 0x1D) -> KAD JURULATIH.
# Kapsul dipanjangkan ke kanan dan "IDNo" dianjak; baris 7 (garis atas kapsul)
# terletak dalam jubin berbeza bagi kad biasa & diserlah, jadi dilukis pada kedua-duanya.
FP_TAJUK_KAD = {
    "K": ["#.#", "##.", "#.#"], "A": [".#.", "###", "#.#"], "D": ["##.", "#.#", "##."],
    "J": ["..#", "..#", "##."], "U": ["#.#", "#.#", "###"], "R": ["##.", "##.", "#.#"],
    "L": ["#.", "#.", "##"], "T": ["###", ".#.", ".#."], "I": ["#", "#", "#"], "H": ["#.#", "###", "#.#"],
}
FP_KAD_AFIN = "graphics/frontier_pass/map_and_card.png"


def jana_kad_fp(imej, abjad):
    im = imej[FP]
    px = im.load()
    kong = [(FP_BG, 32, [(16, 10)], 0, 2)]
    pn = jubin(FP_KAD, 12, 0, 14, 12, 7, 128, kongsi=kong + [(FP_KAD, 12, [(0, 21)], 0, 2)])
    ph = jubin(FP_KAD, 12, 0, 21, 12, 7, 128, kongsi=kong + [(FP_KAD, 12, [(0, 14)], 0, 2)])
    BIRU, PUTIH, BINGKAI, BAYANG = 0x1D, 0x1F, 0x18, 0x1E
    get = lambda x, y: px[pn(x, y)]
    jalur = {y: collections.Counter(get(x, y) for x in range(50, 90)).most_common(1)[0][0] for y in range(7, 12)}
    # angkat IDNo (x 50-75, baris 8-11)
    idno = {(x, y): get(x, y) for x in range(50, 76) for y in range(8, 12) if get(x, y) in (PUTIH, BAYANG)}
    for (x, y) in idno:
        px[pn(x, y)] = jalur[y]
    # teks baharu
    teks, x = {}, 9
    for c in "KAD JURULATIH":
        if c == " ":
            x += 2
            continue
        g = FP_TAJUK_KAD[c]
        for dy, r in enumerate(g):
            for dx, ch in enumerate(r):
                if ch == "#":
                    teks[(x + dx, 8 + dy)] = PUTIH
        x += len(g[0]) + 1
    xr = x  # bingkai kanan (1 piksel jidar selepas huruf akhir)
    for y in range(8, 11):
        for xx in range(8, 49):
            px[pn(xx, y)] = jalur[y]  # padam kapsul lama (termasuk bingkai kanan x 48)
        for xx in range(8, xr):
            px[pn(xx, y)] = BIRU
        px[pn(xr, y)] = BINGKAI
    for peta in (pn, ph):
        for xx in range(8, 49):
            if px[peta(xx, 7)] == BINGKAI:
                px[peta(xx, 7)] = jalur[7]
        for xx in range(8, xr):
            px[peta(xx, 7)] = BINGKAI
    for xx in range(8, 49):
        if get(xx, 11) == BINGKAI:
            px[pn(xx, 11)] = jalur[11]
    for xx in range(8, xr):
        px[pn(xx, 11)] = BINGKAI
    for (a, b), c in teks.items():
        px[pn(a, b)] = c
    dx = xr + 6 - min(x for x, _ in idno)
    for (x, y), c in idno.items():
        assert x + dx < 92, "IDNo melepasi kad"
        px[pn(x + dx, y)] = c
    # kad zum 8bpp (small_map_and_card_affine.bin, segmen kedua = kad)
    _af = "graphics/frontier_pass/small_map_and_card_affine.bin"  # segmen ke-3 = salinan kad
    afin = jubin(_af, 12, 0, 7, 12, 7, 128, bpe=1, kongsi=[(_af, 12, [(0, 14)], 0, 1)])
    asl = asal(FP).load()
    a8 = asal(FP_KAD_AFIN).load()
    undi = collections.defaultdict(collections.Counter)
    for y in range(56):
        for x in range(96):
            undi[asl[pn(x, y)]][a8[afin(x, y)]] += 1
    cmap = {k: v.most_common(1)[0][0] for k, v in undi.items()}
    p8 = imej[FP_KAD_AFIN].load()
    for y in range(56):
        for x in range(96):
            if px[pn(x, y)] != asl[pn(x, y)]:
                p8[afin(x, y)] = cmap[px[pn(x, y)]]
    PANEL.append(("peta", FP, pn, 96, 56, "frontier_pass/bg.png (kad biasa)"))
    PANEL.append(("peta", FP, ph, 96, 56, "frontier_pass/bg.png (kad diserlah)"))
    PANEL.append(("peta", FP_KAD_AFIN, afin, 96, 56, "frontier_pass/map_and_card.png (kad zum 8bpp)"))


# ------------------------------------------------------------ kiraan detik minigame: START -> MULA
# link/321start.png (Berry Crush, Dodrio Berry Picking, POKéMON Jump): dua sprite
# 64x32 bersebelahan (bingkai jubin 48 = kiri, 80 = kanan) = jalur 128x32.
# Huruf besar: isian berwarna ikut baris (e kuning baris 6-8, c baris 9-15,
# a baris 16-25), garis luar 8 (8 jiran) dan garis luar putih f di luarnya.
# Huruf dilukis daripada topeng isian; A diambil daripada START asal.
# (321start_static.png tidak dipakai: tiada pemanggil tugas kiraan statik.)
MULA = "graphics/link/321start.png"
MULA_TOPENG = {
    "M": ["####..........####", "#####........#####", "######......######", "#######....#######",
          "####.###..###.####", "####..######..####", "####...####...####", "####....##....####"]
         + ["####..........####"] * 12,
    "U": ["####......####"] * 17 + ["#####....#####", ".############.", "..##########.."],
    "L": ["####........"] * 17 + ["############"] * 3,
}


def jana_mula(imej, abjad):
    im = imej[MULA]
    px = im.load()
    peta = lambda x, y: (x % 64, (48 if x < 64 else 80) + y)
    asl = asal(MULA).load()
    ISI = {0xE, 0xC, 0xA, 0xB, 0xD, 0x9}
    # topeng A asal (lajur 56-71)
    xs = [x for x in range(56, 72) if any(asl[peta(x, y)] in ISI for y in range(6, 26))]
    topeng_a = ["".join("#" if asl[peta(x, y)] in ISI else "." for x in range(min(xs), max(xs) + 1))
                for y in range(6, 26)]
    topeng = dict(MULA_TOPENG, A=topeng_a)
    warna = lambda y: 0xE if y <= 8 else (0xC if y <= 15 else 0xA)
    lebar = sum(len(topeng[c][0]) for c in "MULA") + 3 * 3
    x0 = 64 - lebar // 2
    isi = set()
    x = x0
    for c in "MULA":
        for dy, r in enumerate(topeng[c]):
            for dx, ch in enumerate(r):
                if ch == "#":
                    isi.add((x + dx, 6 + dy))
        x += len(topeng[c][0]) + 3
    jiran = [(dx, dy) for dx in (-1, 0, 1) for dy in (-1, 0, 1) if dx or dy]
    garis = {(a + dx, b + dy) for (a, b) in isi for dx, dy in jiran} - isi
    putih = {(a + dx, b + dy) for (a, b) in isi | garis for dx, dy in jiran} - isi - garis
    for y in range(32):
        for xx in range(128):
            c = 0
            if (xx, y) in isi:
                c = warna(y)
            elif (xx, y) in garis:
                c = 0x8
            elif (xx, y) in putih:
                c = 0xF
            px[peta(xx, y)] = c
    PANEL.append(("peta", MULA, Peta(peta), 128, 32, "link/321start.png (bingkai 48 + 80)"))


TAMBAHAN["ns_halaman"] = {  # 4x7 (huruf kecil: x-tinggi baris 2-6)
    "B": ["###.", "#..#", "#..#", "###.", "#..#", "#..#", "###."],
    "S": [".##.", "#..#", "#...", ".##.", "...#", "#..#", ".##."],
    "A": [".##.", "#..#", "#..#", "####", "#..#", "#..#", "#..#"],
    "k": ["#..", "#..", "#.#", "##.", "##.", "#.#", "#.#"],
    "c": ["...", "...", ".##", "#..", "#..", "#..", ".##"],
    "i": ["#", ".", "#", "#", "#", "#", "#"],
    "a": ["....", "....", ".##.", "...#", ".###", "#..#", ".###"],
    "n": ["...", "...", "##.", "#.#", "#.#", "#.#", "#.#"],
}
TAMBAHAN["ns_besar"] = {
    "P": ["###.", "#..#", "#..#", "###.", "#...", "#...", "#..."],
    "D": ["###.", "#..#", "#..#", "#..#", "#..#", "#..#", "###."],
}
TAMBAHAN["ns_kecil"] = {  # 3x5 bersegi
    "A": ["###", "#.#", "###", "#.#", "#.#"],
    "G": ["###", "#..", "#.#", "#.#", "###"],
}
TAMBAHAN["berry"] = {  # 5x7
    "A": [".###.", "#...#", "#...#", "#####", "#...#", "#...#", "#...#"],
    "K": ["#...#", "#..#.", "#.#..", "##...", "#.#..", "#..#.", "#...#"],
    "N": ["#...#", "##..#", "#.#.#", "#..##", "#...#", "#...#", "#...#"],
    "G": [".###.", "#...#", "#....", "#.###", "#...#", "#...#", ".###."],
    "M": ["#...#", "##.##", "#.#.#", "#.#.#", "#...#", "#...#", "#...#"],
    "H": ["#...#", "#...#", "#...#", "#####", "#...#", "#...#", "#...#"],
}
TAMBAHAN["penanda"] = {  # 4x9
    "B": ["###.", "#..#", "#..#", "#..#", "###.", "#..#", "#..#", "#..#", "###."],
    "T": ["###", ".#.", ".#.", ".#.", ".#.", ".#.", ".#.", ".#.", ".#."],
}
TAMBAHAN["dome"] = {  # 3x7
    "B": ["##.", "#.#", "#.#", "##.", "#.#", "#.#", "##."],
    "K": ["#.#", "#.#", "##.", "#..", "##.", "#.#", "#.#"],
    "U": ["#.#", "#.#", "#.#", "#.#", "#.#", "#.#", "###"],
    "R": ["##.", "#.#", "#.#", "##.", "#.#", "#.#", "#.#"],
}
TAMBAHAN["ec_besar"] = {  # 4x6
    "T": ["###", ".#.", ".#.", ".#.", ".#.", ".#."],
    "I": ["###", ".#.", ".#.", ".#.", ".#.", "###"],
    "K": ["#..#", "#.#.", "##..", "#.#.", "#..#", "#..#"],
}
TAMBAHAN["ec_butang"] = {  # 3x5
    "A": ["###", "#.#", "###", "#.#", "#.#"],
    "G": ["###", "#..", "#.#", "#.#", "###"],
}
TAMBAHAN["ec_kecil"] = {  # 4x5
    "P": ["###.", "#..#", "###.", "#...", "#..."],
    "B": ["###.", "#..#", "###.", "#..#", "###."],
}
TAMBAHAN["urc_r"] = {  # 3x7
    "D": ["##.", "#.#", "#.#", "#.#", "#.#", "#.#", "##."],
    "A": [".#.", "#.#", "#.#", "###", "#.#", "#.#", "#.#"],
    "F": ["###", "#..", "#..", "###", "#..", "#..", "#.."],
}

KHAS = [jana_ikon_jenis_menu, jana_bar_urc, jana_kad_fp, jana_mula]  # fungsi tambahan (selepas label)
FAIL_KHAS = [MI, URC, FP_KAD_AFIN, MULA]



def lukis_skrin(im, bins, W, off=0):
    """Render tilemap (beberapa lapisan, flip disokong) kepada RGB."""
    rgb = im.convert("RGB")
    tpr = im.width // 8
    lapisan = []
    for rel_bin in bins:
        en = baca_peta_jubin(rel_bin)
        H = len(en) // W
        k = Image.new("RGB", (W * 8, H * 8), (255, 0, 255))
        for n, e in enumerate(en):
            t = (e & 0x3FF) - off
            if not 0 <= t < tpr * (im.height // 8):
                continue
            g = rgb.crop(((t % tpr) * 8, (t // tpr) * 8, (t % tpr) * 8 + 8, (t // tpr) * 8 + 8))
            if e >> 10 & 1:
                g = g.transpose(Image.FLIP_LEFT_RIGHT)
            if e >> 11 & 1:
                g = g.transpose(Image.FLIP_TOP_BOTTOM)
            k.paste(g, ((n % W) * 8, (n // W) * 8))
        lapisan.append(k)
    lebar = sum(k.width + 4 for k in lapisan)
    hasil = Image.new("RGB", (lebar, max(k.height for k in lapisan)), (40, 40, 40))
    x = 0
    for k in lapisan:
        hasil.paste(k, (x, 0))
        x += k.width + 4
    return hasil


# sprite kecil penuh untuk konteks pratonton
PANEL += [(NS + "back_button.png", 0, 0, 40, 24), ("graphics/shop/money.png", 0, 0, 32, 16),
          (EC + "button_window.png", 16, 0, 64, 60), (EC + "mode.png", 24, 0, 64, 64),
          (TB, 0, 0, 32, 96), ("graphics/union_room_chat/r_button_labels.png", 0, 0, 32, 64)]

# (fail, [bin...], lebar peta, offset jubin) skrin penuh untuk konteks pratonton
SKRIN = [
    (TC, TC_BINS[:3], 30, 0),
    (TCF, TCF_BINS[:3], 30, 0),
    (FP, [FP_BG], 32, 0),
    (FP, [FP_BATAL, FP_BATAL2], 9, 0),
    (PC, [PCD + "party_menu.bin"], 12, 256),
    (PC, [PCD + "close_box_button.bin"], 9, 256),
    (BT, ["graphics/bag/berry_tag.bin"], 32, 0),
]


# ============================================================ pratonton
def pratonton(asli, baru, keluar, skala=4, semak=False):
    keping = []
    for lb in L:
        if lb["ms"] is None or (lb["ms"] == lb["en"] and not semak):
            continue
        x0, y0, x1, y1 = lb["kotak"]
        a, b = (Image.new("RGB", (x1 - x0, y1 - y0)) for _ in range(2))
        for src, dst in ((asli, a), (baru, b)):
            im = src[lb["fail"]]
            px = im.load()
            pal = im.getpalette()
            for yy in range(y0, y1):
                for xx in range(x0, x1):
                    i = px[lb["peta"](xx, yy)]
                    dst.putpixel((xx - x0, yy - y0), tuple(pal[i * 3:i * 3 + 3]))
        keping.append((f"{lb['fail'].replace('graphics/', '')}: {lb['en']} -> {lb['ms']}", a, b))
    for pn in ([] if semak else PANEL):
        if pn[0] in ("urc", "peta"):
            if pn[0] == "urc":
                _, peta, w, h = pn
                rel, tajuk = URC, "union_room_chat/background.png (bar)"
            else:
                _, rel, peta, w, h, tajuk = pn
            a, b = (Image.new("RGB", (w, h)) for _ in range(2))
            for src, dst in ((asli, a), (baru, b)):
                im = src[rel].convert("RGB")
                for yy in range(h):
                    for xx in range(w):
                        dst.putpixel((xx, yy), im.getpixel(peta(xx, yy)))
            keping.append((tajuk, a, b))
            continue
        rel, x0, y0, x1, y1 = pn
        a = asli[rel].convert("RGB").crop((x0, y0, x1, y1))
        b = baru[rel].convert("RGB").crop((x0, y0, x1, y1))
        keping.append((rel.replace("graphics/", ""), a, b))
    for rel, bins, W, off in ([] if semak else SKRIN):
        a = lukis_skrin(asli[rel], bins, W, off)
        b = lukis_skrin(baru[rel], bins, W, off)
        keping.append((f"{rel.replace('graphics/', '')} ({', '.join(x.split('/')[-1] for x in bins)})",
                       a, b, 2, True))
    # bahagi kepada beberapa fail (tinggi maksimum ~1800 piksel)
    halaman, cur, tinggi = [], [], 0
    for kp in keping:
        teks, a, b = kp[:3]
        sk, tegak = (kp[3], kp[4]) if len(kp) > 3 else (skala, False)
        h = (a.height * sk * (2 if tegak else 1) + 4 * tegak) + 16
        if cur and tinggi + h > 1800:
            halaman.append(cur)
            cur, tinggi = [], 0
        cur.append((teks, a, b, sk, tegak, h))
        tinggi += h
    if cur:
        halaman.append(cur)
    keluar_semua = []
    for n, hal in enumerate(halaman):
        lebar = max(max(a.width * sk * (1 if tg else 2) + 12, 420) for _, a, _, sk, tg, _ in hal)
        k = Image.new("RGB", (lebar, sum(h for *_, h in hal)), (40, 40, 40))
        dr = ImageDraw.Draw(k)
        y = 0
        for teks, a, b, sk, tegak, h in hal:
            dr.text((2, y), teks, fill=(255, 255, 0))
            y += 12
            ra = a.resize((a.width * sk, a.height * sk), Image.NEAREST)
            rb = b.resize((b.width * sk, b.height * sk), Image.NEAREST)
            k.paste(ra, (0, y))
            if tegak:  # sebelum di atas, selepas di bawah
                k.paste(rb, (0, y + ra.height + 4))
            else:
                k.paste(rb, (ra.width + 12, y))
            y += h - 12
        nama = keluar if n == 0 else keluar.replace(".png", f"_{n + 1}.png")
        k.save(nama)
        keluar_semua.append(nama)
    print("pratonton:", " ".join(keluar_semua))


# ============================================================ main
def main():
    fail = sorted({lb["fail"] for lb in L} | set(FAIL_KHAS))
    asli = {rel: asal(rel) for rel in fail}
    imej = {rel: im.copy() for rel, im in asli.items()}
    abjad = ekstrak(asli)
    if "--huruf" in sys.argv:
        for f in sorted(abjad):
            print("==", f)
            for h in sorted(abjad[f]):
                rows, adv = abjad[f][h]
                print(f"  {h} (lebar {adv})")
                for r in rows:
                    print("     ", r)
        return
    if "--semak" in sys.argv:
        lukis(imej, abjad, semak=True)
        if "--pratonton" in sys.argv:
            pratonton(asli, imej, sys.argv[sys.argv.index("--pratonton") + 1], semak=True)
        for rel in fail:
            beza = sum(1 for p, q in zip(asli[rel].tobytes(), imej[rel].tobytes()) if p != q)
            print(f"{rel}: {beza} piksel berbeza")
        return
    lukis(imej, abjad)
    for fn in KHAS:
        fn(imej, abjad)
    if "--pratonton" in sys.argv:
        pratonton(asli, imej, sys.argv[sys.argv.index("--pratonton") + 1])
        return
    for rel, im in imej.items():
        a = asli[rel]
        assert im.mode == "P" and im.size == a.size and im.getpalette() == a.getpalette(), rel
        im.save(ROOT / rel)
    print(f"{len(imej)} fail ditulis.")


if __name__ == "__main__":
    main()
