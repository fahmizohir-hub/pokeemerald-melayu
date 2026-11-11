#!/usr/bin/env python3
"""Lukis semula ikon status (graphics/interface/status_icons.png) dalam BM.

Jalankan dalam WSL (perlu Pillow):
    python3 tools/jana_ikon_status.py --huruf
    python3 tools/jana_ikon_status.py --pratonton FAIL.png
    python3 tools/jana_ikon_status.py

Setiap ikon 32x8 (7 ikon disusun menegak). Huruf putih (indeks 2) baris 1-6,
tanpa bayang. Singkatan ikut src/strings.c (gText_Psn dll.).
"""
import collections
import subprocess
import sys
from io import BytesIO
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
FAIL = "graphics/interface/status_icons.png"
PUTIH = 2

# (y atas, perkataan asal, perkataan BM)
IKON = [
    (0, "PSN", "RCN"),
    (8, "PAR", "LMP"),
    (16, "SLP", "TDR"),
    (24, "FRZ", "BKU"),
    (32, "BRN", "BKR"),
    (40, "PKRS", "PKRS"),
    (48, "FNT", "PGS"),
]

TAMBAHAN = {
    "C": [".##.", "#..#", "#...", "#...", "#..#", ".##."],
    "D": ["###.", "#..#", "#..#", "#..#", "#..#", "###."],
    "G": [".##.", "#...", "#...", "#.##", "#..#", ".##."],
    "K": ["#..#", "#.#.", "##..", "##..", "#.#.", "#..#"],
    "M": ["#...#", "##.##", "#.#.#", "#...#", "#...#", "#...#"],
    "U": ["#..#", "#..#", "#..#", "#..#", "#..#", ".##."],
}


def asal():
    data = subprocess.run(["git", "-C", str(ROOT), "show", f"asal:{FAIL}"],
                          capture_output=True, check=True).stdout
    return Image.open(BytesIO(data))


def ekstrak(im):
    px = im.load()
    abjad = {}
    for y0, kata, _ in IKON:
        lajur = [x for x in range(32) if any(px[x, y] == PUTIH for y in range(y0 + 1, y0 + 7))]
        kump, cur = [], []
        for x in range(33):
            if x in lajur:
                cur.append(x)
            elif cur:
                kump.append(cur)
                cur = []
        if len(kump) != len(kata):
            continue
        for h, xs in zip(kata, kump):
            abjad.setdefault(h, ["".join("#" if px[x, y] == PUTIH else "." for x in xs)
                                 for y in range(y0 + 1, y0 + 7)])
    for k, v in TAMBAHAN.items():
        abjad.setdefault(k, v)
    return abjad


def lukis(im, abjad):
    px = im.load()
    for y0, kata_asal, kata in IKON:
        if kata == kata_asal:
            continue  # contoh PKRS: kekal asal
        # latar = warna paling kerap dalam baris tengah ikon (bukan putih/lutsinar)
        warna = collections.Counter(px[x, y0 + 3] for x in range(32) if px[x, y0 + 3] not in (0, PUTIH))
        latar = warna.most_common(1)[0][0]
        lajur_teks = [x for x in range(32) for y in range(y0 + 1, y0 + 7) if px[x, y] == PUTIH]
        kiri, kanan = min(lajur_teks), max(lajur_teks)
        pusat2 = kiri + kanan  # dua kali titik tengah teks asal
        for y in range(y0 + 1, y0 + 7):
            for x in range(kiri - 1, kanan + 2):
                if px[x, y] == PUTIH:
                    px[x, y] = latar
        lebar = sum(len(abjad[c][0]) for c in kata) + len(kata) - 1
        x = (pusat2 - lebar + 1) // 2 + 1
        if kata == kata_asal:
            x = kiri
        for c in kata:
            for dy, baris in enumerate(abjad[c]):
                for dx, ch in enumerate(baris):
                    if ch == "#":
                        px[x + dx, y0 + 1 + dy] = PUTIH
            x += len(abjad[c][0]) + 1
    return im


PERTARUNGAN = [f"graphics/battle_interface/status{n}.png" for n in ("", "2", "3", "4")]
IKON_PERTARUNGAN = [(0, "RCN"), (8, "LMP"), (16, "TDR"), (24, "BKU"), (32, "BKR")]  # PSN PAR SLP FRZ BRN
X_KIRI, X_KANAN = 3, 17  # ruang teks dalam kotak 24x8


def lukis_pertarungan(rel, abjad):
    data = subprocess.run(["git", "-C", str(ROOT), "show", f"asal:{rel}"],
                          capture_output=True, check=True).stdout
    im = Image.open(BytesIO(data))
    px = im.load()
    for y0, kata in IKON_PERTARUNGAN:
        latar = px[2, y0 + 3]
        teks = collections.Counter(px[x, y] for x in range(X_KIRI, X_KANAN + 1)
                                   for y in range(y0 + 1, y0 + 7) if px[x, y] != latar)
        warna = teks.most_common(1)[0][0]
        for y in range(y0 + 1, y0 + 7):
            for x in range(X_KIRI, X_KANAN + 1):
                px[x, y] = latar
        lebar = sum(len(abjad[c][0]) for c in kata) + len(kata) - 1
        x = X_KIRI + (X_KANAN - X_KIRI + 1 - lebar) // 2
        for c in kata:
            for dy, baris in enumerate(abjad[c]):
                for dx, ch in enumerate(baris):
                    if ch == "#":
                        px[x + dx, y0 + 1 + dy] = warna
            x += len(abjad[c][0]) + 1
    return im


def main():
    im = asal()
    abjad = ekstrak(im)
    if "--pertarungan" in sys.argv:
        for rel in PERTARUNGAN:
            hasil = lukis_pertarungan(rel, abjad)
            if "--pratonton" in sys.argv:
                keluar = sys.argv[sys.argv.index("--pratonton") + 1]
                hasil.convert("RGB").resize((24 * 6, 40 * 6), Image.NEAREST).save(keluar)
                return
            hasil.save(ROOT / rel)
        print(f"{len(PERTARUNGAN)} fail ikon pertarungan ditulis.")
        return
    if "--huruf" in sys.argv:
        for h in sorted(abjad):
            print(h, abjad[h])
        return
    im = lukis(im, abjad)
    if "--pratonton" in sys.argv:
        keluar = sys.argv[sys.argv.index("--pratonton") + 1]
        a = asal().convert("RGB")
        b = im.convert("RGB")
        k = Image.new("RGB", (70, 56), (40, 40, 40))
        k.paste(a, (0, 0))
        k.paste(b, (36, 0))
        k.resize((k.width * 6, k.height * 6), Image.NEAREST).save(keluar)
        return
    im.save(ROOT / FAIL)
    print("status_icons.png ditulis.")


if __name__ == "__main__":
    main()
