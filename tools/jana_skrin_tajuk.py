#!/usr/bin/env python3
"""Jana graphics/title_screen/press_start.png versi Melayu.

Jalankan dalam WSL (perlu Pillow):  python3 tools/jana_skrin_tajuk.py [--pratonton]

Susun atur gambar (dibaca sebagai metatile 32x8, 5 setiap baris, 4 tile setiap
metatile). Setiap "banner" ialah 20 tile = 160px:
  tile  1-20 : "TEKAN START"  (baris 0 x8-159 + baris 1 x0-7)
  tile 21-40 : hak cipta asal (baris 1 x8-159 + baris 2 x0-7)
  tile 41-60 : kredit         (baris 2 x8-159 + baris 3 x0-7)
"""
import re
import subprocess
import sys
from io import BytesIO
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
FAIL = ROOT / "graphics/title_screen/press_start.png"
FON_KECIL = ROOT / "graphics/fonts/latin_small.png"

TEKS_BESAR = "TEKAN START"
TEKS_KREDIT = "Terjemahan BM oleh me2suzuran"

# Topeng huruf besar (5 baris isi), diambil dari gambar asal; K dan N dilukis baru.
HURUF = {
    "T": ["########", "...##...", "...##...", "...##...", "...##..."],
    "E": ["#######", "##.....", "#####..", "##.....", "#######"],
    "K": ["##...##", "##..##.", "####...", "##.##..", "##..###"],
    "A": ["...##...", "..####..", ".##..##.", "##....##", "#####..#"],
    "N": ["##...##", "###..##", "####.##", "##.####", "##..###"],
    "S": ["#######", "##.....", "#######", ".....##", "#######"],
    "R": ["######.", "##...##", "##...##", "##.###.", "##..###"],
    " ": ["....", "....", "....", "....", "...."],
}
WARNA_BARIS = [5, 5, 4, 3, 3]  # warna isi ikut baris, seperti asal
HITAM, PUTIH = 1, 5


def gambar_asal():
    data = subprocess.run(["git", "-C", str(ROOT), "show", "asal:graphics/title_screen/press_start.png"],
                          capture_output=True, check=True).stdout
    return Image.open(BytesIO(data))


def tulis_banner(kanvas, banner, nombor):
    """Salin banner 160x8 ke kedudukan tile nombor*20+1 .. nombor*20+20."""
    for t in range(20):
        tile = nombor * 20 + 1 + t
        m = tile // 4
        x = (m % 5) * 32 + (tile % 4) * 8
        y = (m // 5) * 8
        kanvas.paste(banner.crop((t * 8, 0, t * 8 + 8, 8)), (x, y))


def banner_dari_asal(asal, nombor):
    b = Image.new("P", (160, 8), 0)
    for t in range(20):
        tile = nombor * 20 + 1 + t
        m = tile // 4
        x = (m % 5) * 32 + (tile % 4) * 8
        y = (m // 5) * 8
        b.paste(asal.crop((x, y, x + 8, y + 8)), (t * 8, 0))
    return b


def garis_luar(isi, lebar, tinggi):
    luar = set()
    for (x, y) in isi:
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                p = (x + dx, y + dy)
                if p not in isi and 0 <= p[0] < lebar and 0 <= p[1] < tinggi:
                    luar.add(p)
    return luar


def banner_besar(pusat_x):
    lajur = []
    for i, c in enumerate(TEKS_BESAR):
        if i:
            lajur.append(None)  # lajur pemisah
        h = HURUF[c]
        for x in range(len(h[0])):
            lajur.append([h[y][x] == "#" for y in range(5)])
    lebar = len(lajur)
    mula = pusat_x - lebar // 2
    b = Image.new("P", (160, 8), 0)
    px = b.load()
    isi = {}
    for i, kol in enumerate(lajur):
        if kol is None:
            continue
        for y in range(5):
            if kol[y]:
                isi[(mula + i, 1 + y)] = WARNA_BARIS[y]
    for p in garis_luar(isi, 160, 8):
        px[p] = HITAM
    for p, w in isi.items():
        px[p] = w
    return b


def glif_kecil():
    fon = Image.open(FON_KECIL).load()
    teks = (ROOT / "src/fonts.c").read_text(encoding="utf-8")
    m = re.search(r"gFontSmallLatinGlyphWidths\[\]\s*=\s*\{(.*?)\};", teks, re.S)
    lebar = [int(v) for v in re.findall(r"\d+", m.group(1))]
    peta = {}
    for b in (ROOT / "charmap.txt").read_text(encoding="utf-8").splitlines():
        mm = re.match(r"^'(.)'\s*=\s*([0-9A-F]{2})\s*$", b.split("@")[0].strip())
        if mm:
            peta[mm.group(1)] = int(mm.group(2), 16)
    return fon, lebar, peta


def banner_kredit():
    fon, lebar, peta = glif_kecil()
    # Glif kecil: dakwat = 1, bayang = 2, latar = 3, baris 4..11 dalam sel 16x16.
    isi = {}
    x = 0
    for c in TEKS_KREDIT:
        kod = peta[c]
        cx, cy = (kod % 16) * 16, (kod // 16) * 16
        for gy in range(4, 12):
            for gx in range(lebar[kod]):
                if fon[cx + gx, cy + gy] == 1:
                    isi[(x + gx, gy - 4)] = PUTIH
        x += lebar[kod]
    jumlah = x
    mula = (160 - jumlah) // 2
    isi = {(px_ + mula, py): w for (px_, py), w in isi.items()}
    b = Image.new("P", (160, 8), 0)
    px = b.load()
    for p in garis_luar(isi, 160, 8):
        px[p] = HITAM
    for p, w in isi.items():
        px[p] = w
    return b, jumlah


def main():
    asal = gambar_asal()
    kanvas = Image.new("P", (160, 32), 0)
    kanvas.putpalette(asal.getpalette())
    # pusat teks asal "PRESS START" dalam ruang banner
    lama = banner_dari_asal(asal, 0).load()
    xs = [x for x in range(160) for y in range(8) if lama[x, y]]
    pusat = (min(xs) + max(xs)) // 2
    tulis_banner(kanvas, banner_besar(pusat), 0)
    tulis_banner(kanvas, banner_dari_asal(asal, 1), 1)
    kredit, w = banner_kredit()
    tulis_banner(kanvas, kredit, 2)
    if "--pratonton" in sys.argv:
        for n, b in enumerate([banner_besar(pusat), banner_dari_asal(asal, 1), kredit]):
            p = b.load()
            print(f"banner {n}:")
            for y in range(8):
                print("  " + "".join(" 12345"[p[x, y]] if p[x, y] < 6 else "?" for x in range(160)).rstrip())
        print(f"lebar kredit {w}px")
        return
    kanvas.save(FAIL)
    print(f"Ditulis {FAIL.relative_to(ROOT)} (kredit {w}px)")


if __name__ == "__main__":
    main()


def pratonton_png(keluar):
    """Gambar pratonton 4x atas latar gelap (untuk semakan mata)."""
    asal = gambar_asal()
    lama = banner_dari_asal(asal, 0).load()
    xs = [x for x in range(160) for y in range(8) if lama[x, y]]
    pusat = (min(xs) + max(xs)) // 2
    banners = [banner_dari_asal(asal, 0), banner_besar(pusat), banner_dari_asal(asal, 1), banner_kredit()[0]]
    pal = asal.getpalette()
    im = Image.new("RGB", (160, 8 * len(banners) + 3 * len(banners)), (40, 90, 60))
    for i, b in enumerate(banners):
        p = b.load()
        for y in range(8):
            for x in range(160):
                v = p[x, y]
                if v:
                    im.putpixel((x, i * 11 + y), tuple(pal[v * 3:v * 3 + 3]))
    im.resize((im.width * 4, im.height * 4), Image.NEAREST).save(keluar)
