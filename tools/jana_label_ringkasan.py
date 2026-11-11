#!/usr/bin/env python3
"""Lukis semula label dalam graphics/summary_screen/tiles.png (skrin ringkasan).

Jalankan dalam WSL (perlu Pillow):
    python3 tools/jana_label_ringkasan.py --huruf
    python3 tools/jana_label_ringkasan.py --pratonton FAIL.png
    python3 tools/jana_label_ringkasan.py

Kawasan label diambil dari tilemap graphics/summary_screen/*.bin. Tile 136 dan
200 dikongsi sebagai tile kosong, jadi tak boleh disentuh.
Warna: putih = 2, bayang = 6 (kanan, bawah, pepenjuru), latar = piksel (0,0) tile.
"""
import subprocess
import sys
from io import BytesIO
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
FAIL = "graphics/summary_screen/tiles.png"
PUTIH, BAYANG = 2, 6
LEBAR_SHEET = 16  # tile sesaris

# (kod, perkataan Inggeris asal, tile pertama, bilangan tile, perkataan Melayu)
LABEL = [
    ("profil", "PROFILE", 128, 8, "PROFIL"),
    ("item", "ITEM", 137, 7, "BARANG"),
    ("ability", "ABILITY", 144, 9, "KEBOLEHAN"),
    ("ribbon", "RIBBON", 153, 7, "REBEN"),
    ("stats", "STATS", 169, 7, "STAT"),
    ("state", "STATE", 176, 9, "KEADAAN"),
    ("exp", "EXP.", 185, 7, "EXP."),
    ("moves", "MOVES", 192, 8, "MOVE"),
    ("effect", "EFFECT", 202, 6, "KESAN"),
    ("desc", "DESCRIPTION", 208, 10, "HURAIAN"),
    ("memo", "TRAINER MEMO", 224, 9, "CATATAN"),
]

# Huruf yang tiada dalam label asal (7 baris, '#' = putih), 5 lajur seperti asal
TAMBAHAN = {
    "G": [".###.", "#...#", "#....", "#.###", "#...#", "#...#", ".###."],
    "H": ["#...#", "#...#", "#...#", "#####", "#...#", "#...#", "#...#"],
    "K": ["#...#", "#..#.", "#.#..", "##...", "#.#..", "#..#.", "#...#"],
    "U": ["#...#", "#...#", "#...#", "#...#", "#...#", "#...#", ".###."],
}


def asal():
    data = subprocess.run(["git", "-C", str(ROOT), "show", f"asal:{FAIL}"],
                          capture_output=True, check=True).stdout
    return Image.open(BytesIO(data))


def kotak(tile, n):
    """(x0, y0, lebar) kawasan label dalam piksel."""
    return (tile % LEBAR_SHEET) * 8, (tile // LEBAR_SHEET) * 8, n * 8


def ekstrak_huruf(im):
    px = im.load()
    abjad = {}
    for _, kata, tile, n, _ in LABEL:
        x0, y0, w = kotak(tile, n)
        lajur = [x for x in range(x0, x0 + w) if any(px[x, y] == PUTIH for y in range(y0, y0 + 7))]
        kump, cur = [], []
        for x in range(x0, x0 + w + 1):
            if x in lajur:
                cur.append(x)
            elif cur:
                kump.append(cur)
                cur = []
        huruf = [c for c in kata if c != " "]
        if len(kump) != len(huruf):
            continue
        for h, xs in zip(huruf, kump):
            abjad.setdefault(h, ["".join("#" if px[x, y] == PUTIH else "." for x in xs)
                                 for y in range(y0, y0 + 7)])
    for k, v in TAMBAHAN.items():
        abjad.setdefault(k, v)
    return abjad


def lebar(kata, abjad):
    return sum(len(abjad[c][0]) for c in kata) + (len(kata) - 1) + 1


def lukis(im, abjad):
    px = im.load()
    for kod, _, tile, n, kata in LABEL:
        x0, y0, w = kotak(tile, n)
        latar = px[x0, y0]
        if 2 + lebar(kata, abjad) > w:
            sys.exit(f"TAK MUAT: {kod} {kata} {2 + lebar(kata, abjad)} > {w}px")
        for y in range(y0, y0 + 8):
            for x in range(x0, x0 + w):
                px[x, y] = latar
        putih = set()
        x = x0 + 2
        for c in kata:
            for dy, baris in enumerate(abjad[c]):
                for dx, ch in enumerate(baris):
                    if ch == "#":
                        putih.add((x + dx, y0 + dy))
            x += len(abjad[c][0]) + 1
        for (a, b) in putih:
            for dx, dy in ((1, 0), (0, 1), (1, 1)):
                p = (a + dx, b + dy)
                if p not in putih and p[0] < x0 + w and p[1] < y0 + 8:
                    px[p] = BAYANG
        for p in putih:
            px[p] = PUTIH
    return im


def main():
    im = asal()
    abjad = ekstrak_huruf(im)
    if "--huruf" in sys.argv:
        for h in sorted(abjad):
            print(h, abjad[h])
        return
    im = lukis(im, abjad)
    if "--pratonton" in sys.argv:
        keluar = sys.argv[sys.argv.index("--pratonton") + 1]
        k = im.convert("RGB").crop((0, 64, 128, 120))
        k.resize((k.width * 5, k.height * 5), Image.NEAREST).save(keluar)
        return
    im.save(ROOT / FAIL)
    print("tiles.png ditulis.")


if __name__ == "__main__":
    main()
