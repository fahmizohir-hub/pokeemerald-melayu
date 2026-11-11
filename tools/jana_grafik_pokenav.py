#!/usr/bin/env python3
"""Lukis semula teks dalam grafik POKéNAV (graphics/pokenav/**) dalam BM.

Jalankan dalam WSL (perlu Pillow):
    python3 tools/jana_grafik_pokenav.py --huruf
    python3 tools/jana_grafik_pokenav.py --semak
    python3 tools/jana_grafik_pokenav.py --pratonton FAIL.png
    python3 tools/jana_grafik_pokenav.py

Sentiasa bermula daripada fail asal (tag git `asal`), jadi boleh diulang.

Fail dan cara ia dipaparkan:
- left_headers/*.png: sprite. Kepala utama = dua sprite 64x32 (baris 0-31 di
  kiri, baris 32-63 di kanan, x2=64); HOENN MAP = 64x96, sprite kedua (x2=56)
  memakai baris 32-63 (FULL VIEW) atau 64-95 (ZOOM VIEW). Sub-kepala = dua
  sprite 32x16 (baris 0-15 dan 16-31 sebelah-menyebelah); baris 32-63 tidak
  dipaparkan dan dibiarkan.
- options/*.png: sprite, empat 32x16 sebelah-menyebelah (jalur 128x16).
  options.4bpp dicantum oleh Makefile daripada fail .4bpp setiap pilihan.
- Fon besar (kepala & pilihan): 5x9, putih = 1, bayang = 2 (kanan, bawah,
  pepenjuru), jarak huruf 1, jarak perkataan 4.
- condition/cancel.png: sprite 32x16, fon 3x5 warna 15 di atas latar 2.
- condition/graph.png: helaian tile BG (graph.bin). Tile label COOL, TOUGH,
  BEAUTY, SMART, CUTE masing-masing dipakai sekali sahaja dalam tilemap
  (tile kongsi 0x0/0x10/.../0x90/0xF tidak disentuh). Fon 5x7 warna 1 dengan
  garis luar 4 (sisi) dan 15 (pepenjuru).
- region_map/city_zoom_text.png: sprite 32x8 x3 yang menatal satu tile
  sebingkai melalui 64 tile (jalur 512x8). Setiap entri berhenti pada
  halaman 96 piksel (12 tile), jadi setiap entri mesti kekal dalam halamannya.
  Fon kecil 6 baris tanpa bayang, warna ikut entri.
- header.png TIDAK diubah: header.bin hanya memaparkan logo POKéNAV (tile
  0x01-0x1B); tile "POKéMON NAVIGATOR" dalam helaian tidak dipaparkan.
"""
import collections
import subprocess
import sys
from io import BytesIO
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
D = "graphics/pokenav/"


def asal(rel):
    data = subprocess.run(["git", "-C", str(ROOT), "show", f"asal:{rel}"],
                          capture_output=True, check=True).stdout
    return Image.open(BytesIO(data))


# ---------------------------------------------------------------- jalur
def ke_jalur(im, tinggi):
    """Susun blok setinggi `tinggi` sebelah-menyebelah (susunan sprite)."""
    n = im.height // tinggi
    j = Image.new("P", (im.width * n, tinggi))
    j.putpalette(im.getpalette())
    for i in range(n):
        j.paste(im.crop((0, i * tinggi, im.width, (i + 1) * tinggi)), (i * im.width, 0))
    return j


def dari_jalur(im, j, tinggi):
    n = j.width // im.width
    for i in range(n):
        im.paste(j.crop((i * im.width, 0, (i + 1) * im.width, tinggi)), (0, i * tinggi))
    return im


# ---------------------------------------------------------------- huruf
def ekstrak(px, x0, x1, y0, tinggi, kata, dakwat, abjad):
    """Ambil bentuk huruf `kata` (tanpa ruang) dari kawasan [x0,x1) x [y0,y0+tinggi)."""
    lajur = [x for x in range(x0, x1) if any(dakwat(px[x, y]) for y in range(y0, y0 + tinggi))]
    kump, cur = [], []
    for x in range(x0, x1 + 1):
        if x in lajur:
            cur.append(x)
        elif cur:
            kump.append(cur)
            cur = []
    huruf = [c for c in kata if c != " "]
    if len(kump) != len(huruf):
        return False
    for h, xs in zip(huruf, kump):
        bentuk = ["".join("#" if dakwat(px[x, y]) else "." for x in xs) for y in range(y0, y0 + tinggi)]
        abjad.setdefault(h, []).append(bentuk)
    return True


def satukan(abjad, tambahan):
    """Pilih bentuk paling kerap bagi setiap huruf; tambah huruf baharu."""
    hasil = {}
    for h, senarai in abjad.items():
        kira = collections.Counter(tuple(b) for b in senarai)
        hasil[h] = list(max(kira, key=lambda b: (kira[b], len(b[0]))))
    for h, b in tambahan.items():
        hasil.setdefault(h, b)
    return hasil


def lebar_teks(kata, abjad, jarak, ruang):
    w, x = 0, 0
    for i, c in enumerate(kata):
        if c == " ":
            x += ruang - jarak
            continue
        x += len(abjad[c][0])
        w = x
        x += jarak
    return w


def piksel_teks(kata, abjad, x, y, jarak, ruang):
    titik = set()
    for c in kata:
        if c == " ":
            x += ruang - jarak
            continue
        for dy, baris in enumerate(abjad[c]):
            for dx, ch in enumerate(baris):
                if ch == "#":
                    titik.add((x + dx, y + dy))
        x += len(abjad[c][0]) + jarak
    return titik


# ================================================================ fon besar
PUTIH, BAYANG = 1, 2
TINGGI_BESAR = 9
JARAK, RUANG = 1, 4  # ruang = lebar jurang antara perkataan

# Huruf yang tiada dalam grafik asal (5x9, gaya sama: sudut bulat seperti C/G/S)
TAMBAHAN_BESAR = {
    "K": ["#...#", "#...#", "#..#.", "#.#..", "##...", "#.#..", "#..#.", "#...#", "#...#"],
    "J": ["....#", "....#", "....#", "....#", "....#", "....#", "#...#", "#...#", ".###."],
}

# (fail, tinggi blok, baris atas huruf, x0, x1, perkataan asal, perkataan BM, jajaran, had x)
#  x0..x1 = kawasan teks asal dalam jalur; jajaran "tengah" ikut pusat teks asal,
#  "kiri" ikut x kiri teks asal; had x = julat yang dibenarkan untuk teks baharu.
BESAR = [
    ("left_headers/main_menu.png", 32, 7, 2, 84, "MAIN MENU", "MENU UTAMA", "tengah", (4, 82)),
    ("left_headers/condition.png", 32, 7, 2, 84, "CONDITION", "KEADAAN", "tengah", (4, 82)),
    ("left_headers/ribbons.png", 32, 7, 2, 84, "RIBBONS", "REBEN", "tengah", (4, 82)),
    ("left_headers/match_call.png", 32, 7, 2, 84, "MATCH CALL", None, "tengah", (4, 82)),
    ("left_headers/hoenn_map.png", 32, 7, 2, 56, "HOENN MAP", "PETA", "tengah", (4, 53)),
    ("left_headers/hoenn_map.png", 32, 7, 64, 120, "FULL VIEW", "PENUH", "tengah", (66, 117)),
    ("left_headers/hoenn_map.png", 32, 7, 128, 184, "ZOOM VIEW", "ZUM", "tengah", (130, 181)),
    ("left_headers/party.png", 16, 4, 2, 60, "PARTY", "PASUKAN", "tengah", (3, 58)),
    ("left_headers/search.png", 16, 4, 2, 60, "SEARCH", "CARI", "tengah", (3, 58)),
    ("left_headers/cool.png", 16, 4, 2, 60, "COOL", "SEGAK", "tengah", (3, 58)),
    ("left_headers/beauty.png", 16, 4, 2, 60, "BEAUTY", "CANTIK", "tengah", (3, 58)),
    ("left_headers/cute.png", 16, 4, 2, 60, "CUTE", "COMEL", "tengah", (3, 58)),
    ("left_headers/smart.png", 16, 4, 2, 60, "SMART", "BIJAK", "tengah", (3, 58)),
    ("left_headers/tough.png", 16, 4, 2, 60, "TOUGH", "TEGAP", "tengah", (3, 58)),
    ("options/hoenn_map.png", 16, 4, 15, 128, "HOENN MAP", "PETA HOENN", "kiri", (15, 108)),
    ("options/condition.png", 16, 4, 15, 128, "CONDITION", "KEADAAN", "kiri", (15, 108)),
    ("options/match_call.png", 16, 4, 15, 128, "MATCH CALL", None, "kiri", (15, 108)),
    ("options/ribbons.png", 16, 4, 15, 128, "RIBBONS", "REBEN", "kiri", (15, 108)),
    ("options/switch_off.png", 16, 4, 15, 128, "SWITCH OFF", "TUTUP", "kiri", (15, 108)),
    ("options/party.png", 16, 4, 15, 128, "PARTY", "PASUKAN", "kiri", (15, 108)),
    ("options/search.png", 16, 4, 15, 128, "SEARCH", "CARI", "kiri", (15, 108)),
    ("options/cool.png", 16, 4, 7, 128, "COOL", "SEGAK", "kiri", (7, 108)),
    ("options/beauty.png", 16, 4, 7, 128, "BEAUTY", "CANTIK", "kiri", (7, 108)),
    ("options/cute.png", 16, 4, 7, 128, "CUTE", "COMEL", "kiri", (7, 108)),
    ("options/smart.png", 16, 4, 7, 128, "SMART", "BIJAK", "kiri", (7, 108)),
    ("options/tough.png", 16, 4, 7, 128, "TOUGH", "TEGAP", "kiri", (7, 108)),
    ("options/cancel.png", 16, 4, 15, 128, "CANCEL", "BATAL", "kiri", (15, 108)),
]


def kotak_teks(px, x0, x1, y0, y1):
    xs = [x for x in range(x0, x1) for y in range(y0, y1) if px[x, y] == PUTIH]
    return min(xs), max(xs)


def huruf_besar():
    abjad = {}
    for rel, tinggi, y0, x0, x1, kata, _, _, _ in BESAR:
        j = ke_jalur(asal(D + rel), tinggi)
        px = j.load()
        kiri, kanan = kotak_teks(px, x0, x1, y0, y0 + TINGGI_BESAR)
        # PARTY diikuti glif kecil PKMN; ambil kawasan PARTY sahaja
        if kata == "PARTY":
            kanan = kiri + 5 * 6 - 2
        ekstrak(px, kiri, kanan + 1, y0, TINGGI_BESAR, kata, lambda v: v == PUTIH, abjad)
    return abjad


def lukis_besar(j, entri, abjad):
    _, tinggi, y0, x0, x1, kata_asal, kata, jajar, (had0, had1) = entri
    px = j.load()
    kiri, kanan = kotak_teks(px, x0, x1, y0, y0 + TINGGI_BESAR)
    w = lebar_teks(kata, abjad, JARAK, RUANG)
    if jajar == "tengah":
        x = (kiri + kanan + 1 - w) // 2
    else:
        x = kiri
    if x < had0 or x + w - 1 > had1:
        sys.exit(f"TAK MUAT: {entri[0]} {kata} x={x} w={w} had={had0}..{had1}")
    # padam: semua piksel putih/bayang dalam kawasan teks (termasuk glif PKMN)
    for y in range(j.height):
        latar = collections.Counter(px[xx, y] for xx in range(x0, x1)
                                    if px[xx, y] not in (PUTIH, BAYANG)).most_common(1)[0][0]
        for xx in range(x0, x1):
            if px[xx, y] in (PUTIH, BAYANG):
                px[xx, y] = latar
    putih = piksel_teks(kata, abjad, x, y0, JARAK, RUANG)
    for (a, b) in putih:
        for dx, dy in ((1, 0), (0, 1), (1, 1)):
            p = (a + dx, b + dy)
            if p not in putih and p[0] < x1 and p[1] <= y0 + TINGGI_BESAR:
                px[p] = BAYANG
    for p in putih:
        px[p] = PUTIH


def jana_besar(abjad, semak=False):
    """Pulangkan {rel: imej baharu}. Jika semak, lukis semula perkataan Inggeris."""
    hasil = {}
    for e in BESAR:
        rel, tinggi = e[0], e[1]
        kata = e[5] if semak else e[6]
        if kata is None:
            continue
        im = hasil.get(rel) or asal(D + rel)
        j = ke_jalur(im, tinggi)
        lukis_besar(j, e[:6] + (kata,) + e[7:], abjad)
        hasil[rel] = dari_jalur(im, j, tinggi)
    return hasil


# ================================================================ graf keadaan
GRAF = "condition/graph.png"
TINGGI_GRAF = 7
G_TEKS, G_SISI, G_SUDUT, G_LATAR = 1, 4, 15, 3

TAMBAHAN_GRAF = {
    "K": ["#...#", "#..#.", "#.#..", "##...", "#.#..", "#..#.", "#...#"],
    "P": ["####.", "#...#", "#...#", "####.", "#....", "#....", "#...."],
    "N": ["#...#", "##..#", "#.#.#", "#.#.#", "#.#.#", "#..##", "#...#"],
    "I": ["###", ".#.", ".#.", ".#.", ".#.", ".#.", "###"],
    "J": ["....#", "....#", "....#", "....#", "#...#", "#...#", ".###."],
}
# A 4 lajur (seperti SMART asal) supaya CANTIK tidak menyentuh bingkai kanan
GANTI_GRAF = {"A": [".##.", "#..#", "#..#", "#..#", "####", "#..#", "#..#"]}

# (x0, x1 kawasan carian, baris atas huruf, asal, BM, {baris: (kiri, kanan, warna)} latar bulatan)
LABEL_GRAF = [
    (50, 90, 2, "COOL", "SEGAK", {6: (62, 73, 6), 7: (61, 74, 6), 8: (60, 75, 6), 9: (59, 76, 6)}),
    (12, 50, 25, "TOUGH", "TEGAP", {32: (30, 40, 8)}),
    (85, 123, 25, "BEAUTY", "CANTIK", {}),
    (14, 60, 85, "SMART", "BIJAK", {84: (36, 57, 10), 85: (36, 57, 10), 86: (37, 56, 10), 87: (37, 56, 10),
                                     88: (38, 55, 10), 89: (39, 54, 10), 90: (40, 53, 10), 91: (42, 51, 10)}),
    (75, 115, 85, "CUTE", "COMEL", {84: (77, 98, 12), 85: (77, 98, 12), 86: (78, 97, 12), 87: (78, 97, 12),
                                    88: (79, 97, 12), 89: (80, 97, 12), 90: (81, 96, 12), 91: (83, 95, 12)}),
]


def huruf_graf():
    abjad = {}
    px = asal(D + GRAF).load()
    for x0, x1, y0, kata, _, _ in LABEL_GRAF:
        kiri, kanan = kotak_warna(px, x0, x1, y0, y0 + TINGGI_GRAF, G_TEKS)
        ekstrak(px, kiri, kanan + 1, y0, TINGGI_GRAF, kata, lambda v: v == G_TEKS, abjad)
    return abjad


def kotak_warna(px, x0, x1, y0, y1, warna):
    xs = [x for x in range(x0, x1) for y in range(y0, y1) if px[x, y] == warna]
    return min(xs), max(xs)


def jiran(titik, arah):
    return {(a + dx, b + dy) for (a, b) in titik for dx, dy in arah} - titik


SISI = ((1, 0), (-1, 0), (0, 1), (0, -1))
SUDUT = ((1, 1), (1, -1), (-1, 1), (-1, -1))


def jana_graf(abjad, semak=False):
    im = asal(D + GRAF)
    px = im.load()
    for x0, x1, y0, kata_asal, kata_bm, bulatan in LABEL_GRAF:
        kata = kata_asal if semak else kata_bm
        kiri, kanan = kotak_warna(px, x0, x1, y0, y0 + TINGGI_GRAF, G_TEKS)
        lama = {(x, y) for x in range(kiri, kanan + 1) for y in range(y0, y0 + TINGGI_GRAF)
                if px[x, y] == G_TEKS}
        for p in lama | jiran(lama, SISI + SUDUT):
            if px[p] in (G_TEKS, G_SISI, G_SUDUT):
                ki, ka, w = bulatan.get(p[1], (0, -1, 0))
                px[p] = w if ki <= p[0] <= ka else G_LATAR
        w = lebar_teks(kata, abjad, 1, 4)
        x = (kiri + kanan + 1 - w) // 2
        if x - 1 < x0 or x + w >= x1:
            sys.exit(f"TAK MUAT: {GRAF} {kata} x={x} w={w} had={x0}..{x1}")
        teks = piksel_teks(kata, abjad, x, y0, 1, 4)
        sisi = jiran(teks, SISI)
        for p in jiran(teks, SUDUT) - sisi:
            px[p] = G_SUDUT
        for p in sisi:
            px[p] = G_SISI
        for p in teks:
            px[p] = G_TEKS
    return {GRAF: im}


# ================================================================ BATAL kecil
BATAL = "condition/cancel.png"
B_TEKS = 15
TAMBAHAN_BATAL = {
    "B": ["##.", "#.#", "##.", "#.#", "##."],
    "T": ["###", ".#.", ".#.", ".#.", ".#."],
}


def huruf_batal():
    abjad = {}
    px = asal(D + BATAL).load()
    ekstrak(px, 4, 23, 5, 5, "CANCEL", lambda v: v == B_TEKS, abjad)
    return abjad


def jana_batal(abjad, semak=False):
    im = asal(D + BATAL)
    px = im.load()
    kata = "CANCEL" if semak else "BATAL"
    kiri, kanan = kotak_warna(px, 4, 23, 5, 10, B_TEKS)
    latar = px[3, 7]
    for x in range(kiri, kanan + 1):
        for y in range(5, 10):
            px[x, y] = latar
    w = lebar_teks(kata, abjad, 1, 3)
    for p in piksel_teks(kata, abjad, (kiri + kanan + 1 - w) // 2, 5, 1, 3):
        px[p] = B_TEKS
    return {BATAL: im}


# ================================================================ petunjuk peta bandar
ZUM = "region_map/city_zoom_text.png"
HALAMAN = 96  # 12 tile; sprite berhenti pada setiap 12 tile
Z_Y0, Z_TINGGI = 1, 6
Z_RUANG = 4

TAMBAHAN_ZUM = {
    "U": ["#..#", "#..#", "#..#", "#..#", "#..#", ".##."],
    "I": ["###", ".#.", ".#.", ".#.", ".#.", "###"],
    "H": ["#..#", "#..#", "####", "#..#", "#..#", "#..#"],
    "D": ["###.", "#..#", "#..#", "#..#", "#..#", "###."],
}

# (halaman, teks asal tanpa kotak, teks BM)
ENTRI_ZUM = [
    (0, "POKéMON CENTER", "PUSAT POKéMON"),
    (1, "POKé MART", None),
    (2, "POKéMON GYM", "GIM POKéMON"),
    (3, "BATTLE TENT", "KHEMAH BATTLE"),
    (4, "POKéMON CONTEST", "PERTANDINGAN"),
]


def warna_halaman(px, h):
    return collections.Counter(px[x, y] for x in range(h * HALAMAN, (h + 1) * HALAMAN)
                               for y in range(8) if px[x, y]).most_common(1)[0][0]


def mula_teks_zum(px, h, warna):
    """x huruf pertama (selepas kotak warna 6 piksel)."""
    xs = sorted({x for x in range(h * HALAMAN, (h + 1) * HALAMAN) for y in range(8) if px[x, y] == warna})
    kotak_akhir = xs[0] + 5
    return min(x for x in xs if x > kotak_akhir), max(xs)


def huruf_zum():
    abjad = {}
    j = ke_jalur(asal(D + ZUM), 8)
    px = j.load()
    for h, kata, _ in ENTRI_ZUM:
        warna = warna_halaman(px, h)
        x0, x1 = mula_teks_zum(px, h, warna)
        ekstrak(px, x0, x1 + 1, Z_Y0, Z_TINGGI, kata, lambda v, w=warna: v == w, abjad)
    return abjad


def jana_zum(abjad, semak=False):
    im = asal(D + ZUM)
    j = ke_jalur(im, 8)
    px = j.load()
    for h, kata_asal, kata_bm in ENTRI_ZUM:
        kata = kata_asal if semak else kata_bm
        if kata is None:
            continue
        warna = warna_halaman(px, h)
        x0, x1 = mula_teks_zum(px, h, warna)
        for x in range(x0, x1 + 1):
            for y in range(8):
                if px[x, y] == warna:
                    px[x, y] = 0
        w = lebar_teks(kata, abjad, 1, Z_RUANG)
        if x0 + w > (h + 1) * HALAMAN:
            sys.exit(f"TAK MUAT: {ZUM} {kata} melepasi halaman {h}")
        for p in piksel_teks(kata, abjad, x0, Z_Y0, 1, Z_RUANG):
            px[p] = warna
    return {ZUM: dari_jalur(im, j, 8)}


# ================================================================ main
def semua_huruf():
    return {"besar": (huruf_besar(), TAMBAHAN_BESAR), "graf": (huruf_graf(), TAMBAHAN_GRAF),
            "batal": (huruf_batal(), TAMBAHAN_BATAL), "zum": (huruf_zum(), TAMBAHAN_ZUM)}


def jana(semak=False):
    f = {k: satukan(ab, tb) for k, (ab, tb) in semua_huruf().items()}
    if not semak:
        f["graf"].update(GANTI_GRAF)
    hasil = jana_besar(f["besar"], semak)
    hasil.update(jana_graf(f["graf"], semak))
    hasil.update(jana_batal(f["batal"], semak))
    hasil.update(jana_zum(f["zum"], semak))
    return hasil


def pratonton(hasil, keluar, skala=4):
    """Sebelum (kiri) / selepas (kanan) bagi setiap imej, disusun menegak."""
    pasangan = []
    for rel, im in hasil.items():
        a = asal(D + rel)
        if rel.startswith("left_headers/") or rel.startswith("options/"):
            sub = a.width == 32 and rel.startswith("left_headers/")
            tinggi = 32 if a.width == 64 else 16
            a, b = ke_jalur(a, tinggi), ke_jalur(im, tinggi)
            if sub:  # sub-kepala: hanya 2 blok pertama dipaparkan
                a, b = a.crop((0, 0, 64, 16)), b.crop((0, 0, 64, 16))
        elif rel == ZUM:
            a, b = ke_jalur(a, 8), ke_jalur(im, 8)
        else:
            b = im
        pasangan.append((a.convert("RGB"), b.convert("RGB")))
    W = max(a.width + b.width + 6 for a, b in pasangan if a.width <= 200)
    baris = []
    for a, b in pasangan:
        if a.width > 200:
            baris.append((a, None))
            baris.append((b, None))
        else:
            baris.append((a, b))
    W = max(W, max(a.width for a, b in baris))
    H = sum(a.height + 3 for a, _ in baris)
    k = Image.new("RGB", (W, H), (255, 0, 255))
    y = 0
    for a, b in baris:
        k.paste(a, (0, y))
        if b is not None:
            k.paste(b, (a.width + 6, y))
        y += a.height + 3
    k.resize((W * skala, H * skala), Image.NEAREST).save(keluar)


def main():
    if "--huruf" in sys.argv:
        for nama, (ab, _) in semua_huruf().items():
            print("==", nama)
            for h in sorted(ab):
                variasi = collections.Counter(tuple(b) for b in ab[h])
                for b, n in variasi.most_common():
                    print(f"  {h} x{n}", " ".join(b))
        return
    if "--semak" in sys.argv:
        for rel, im in jana(semak=True).items():
            beza = sum(1 for p, q in zip(asal(D + rel).tobytes(), im.tobytes()) if p != q)
            print(f"{rel}: {beza} piksel berbeza")
        return
    hasil = jana()
    if "--pratonton" in sys.argv:
        pratonton(hasil, sys.argv[sys.argv.index("--pratonton") + 1])
        return
    for rel, im in hasil.items():
        a = asal(D + rel)
        assert im.mode == "P" and im.size == a.size and im.getpalette() == a.getpalette(), rel
        im.save(ROOT / D / rel)
    print(f"{len(hasil)} fail grafik POKéNAV ditulis.")


if __name__ == "__main__":
    main()
