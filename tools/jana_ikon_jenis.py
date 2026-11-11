#!/usr/bin/env python3
"""Jana ikon jenis dan kategori contest dalam Bahasa Melayu.

Jalankan dalam WSL (perlu Pillow):
    python3 tools/jana_ikon_jenis.py --huruf       # tunjuk abjad yang diekstrak
    python3 tools/jana_ikon_jenis.py --pratonton F # simpan pratonton PNG 4x
    python3 tools/jana_ikon_jenis.py               # tulis graphics/types/*.png

Huruf diekstrak dari ikon Inggeris asal (tag git `asal`): putih = indeks 15,
bayang = indeks 14 (kanan, bawah, pepenjuru). Ikon 32x16, huruf baris 4-10,
bayang hingga baris 11.
"""
import subprocess
import sys
from io import BytesIO
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
DIR = "graphics/types"
PUTIH, BAYANG = 15, 14
Y0, TINGGI = 4, 7  # baris huruf

# Perkataan dalam ikon asal (untuk ekstrak huruf)
ASAL = {
    "normal": "NORMAL", "fight": "FIGHT", "flying": "FLYING", "poison": "POISON",
    "ground": "GROUND", "rock": "ROCK", "bug": "BUG", "ghost": "GHOST",
    "steel": "STEEL", "fire": "FIRE", "water": "WATER", "grass": "GRASS",
    "electric": "ELECTR", "psychic": "PSYCHC", "ice": "ICE", "dragon": "DRAGON",
    "dark": "DARK", "contest_cool": "COOL", "contest_beauty": "BEAUTY",
    "contest_cute": "CUTE", "contest_smart": "SMART", "contest_tough": "TOUGH",
}

# Perkataan Melayu (GLOSARI: nama jenis; contest: SEGAK/CANTIK/COMEL/BIJAK/TEGAP)
BARU = {
    "normal": "NORMAL", "fight": "LAWAN", "flying": "TERBANG", "poison": "RACUN",
    "ground": "TANAH", "rock": "BATU", "bug": "SERANGGA", "ghost": "HANTU",
    "steel": "BESI", "fire": "API", "water": "AIR", "grass": "RUMPUT",
    "electric": "ELEKTRIK", "psychic": "PSIKIK", "ice": "AIS", "dragon": "NAGA",
    "dark": "GELAP", "contest_cool": "SEGAK", "contest_beauty": "CANTIK",
    "contest_cute": "COMEL", "contest_smart": "BIJAK", "contest_tough": "TEGAP",
}
# Jika perkataan penuh tak muat, guna singkatan (sama seperti gTypeNames)
SINGKAT = {"TERBANG": "TERBNG", "SERANGGA": "SRNGGA", "ELEKTRIK": "ELEKTR"}

# Huruf yang tiada dalam ikon asal (7 baris, '#' = putih)
TAMBAHAN = {
    "J": ["..##", "...#", "...#", "...#", "#..#", "#..#", ".##."],
}


def asal_png(nama):
    data = subprocess.run(["git", "-C", str(ROOT), "show", f"asal:{DIR}/{nama}.png"],
                          capture_output=True, check=True).stdout
    return Image.open(BytesIO(data))


def ekstrak_huruf():
    abjad = {}
    for nama, kata in ASAL.items():
        im = asal_png(nama)
        px = im.load()
        lajur = [x for x in range(32) if any(px[x, y] == PUTIH for y in range(Y0, Y0 + TINGGI))]
        kump, cur = [], []
        for x in range(32):
            if x in lajur:
                cur.append(x)
            elif cur:
                kump.append(cur)
                cur = []
        if cur:
            kump.append(cur)
        if len(kump) != len(kata):
            continue  # huruf bercantum; guna ikon lain untuk huruf ini
        for huruf, xs in zip(kata, kump):
            topeng = ["".join("#" if px[x, y] == PUTIH else "." for x in xs) for y in range(Y0, Y0 + TINGGI)]
            abjad.setdefault(huruf, topeng)
    abjad.update({k: v for k, v in TAMBAHAN.items() if k not in abjad})
    return abjad


def lebar_kata(kata, abjad):
    return sum(len(abjad[c][0]) for c in kata) + (len(kata) - 1) + 1  # jarak 1px, +1 bayang


def lukis(nama, kata, abjad):
    im = asal_png(nama)
    px = im.load()
    latar = px[16, 3]
    for y in range(Y0, Y0 + TINGGI + 1):
        for x in range(1, 31):
            px[x, y] = latar
    w = lebar_kata(kata, abjad)
    x = (32 - w) // 2
    putih = set()
    for c in kata:
        t = abjad[c]
        for dy, baris in enumerate(t):
            for dx, ch in enumerate(baris):
                if ch == "#":
                    putih.add((x + dx, Y0 + dy))
        x += len(t[0]) + 1
    for (a, b) in putih:
        for (dx, dy) in ((1, 0), (0, 1), (1, 1)):
            p = (a + dx, b + dy)
            if p not in putih and 0 < p[0] < 31:
                px[p] = BAYANG
    for p in putih:
        px[p] = PUTIH
    return im


def kata_muat(kata, abjad):
    if lebar_kata(kata, abjad) <= 30:
        return kata
    return SINGKAT.get(kata, kata)


def main():
    abjad = ekstrak_huruf()
    if "--huruf" in sys.argv:
        for h in sorted(abjad):
            print(h, abjad[h])
        return
    hasil = {}
    for nama, kata in BARU.items():
        k = kata_muat(kata, abjad)
        if lebar_kata(k, abjad) > 30:
            print(f"TAK MUAT: {nama} {k} {lebar_kata(k, abjad)}px")
            sys.exit(1)
        hasil[nama] = (k, lukis(nama, k, abjad))
    if "--pratonton" in sys.argv:
        keluar = sys.argv[sys.argv.index("--pratonton") + 1]
        kanvas = Image.new("RGB", (32 * 4 + 12, 16 * ((len(hasil) + 3) // 4) + 3 * 6), (60, 60, 60))
        for i, (nama, (k, im)) in enumerate(hasil.items()):
            kanvas.paste(im.convert("RGB"), ((i % 4) * 35, (i // 4) * 19))
        kanvas.resize((kanvas.width * 4, kanvas.height * 4), Image.NEAREST).save(keluar)
        for nama, (k, _) in hasil.items():
            print(f"{nama:15s} {k}")
        return
    for nama, (k, im) in hasil.items():
        im.save(ROOT / DIR / f"{nama}.png")
    print(f"{len(hasil)} ikon ditulis.")


if __name__ == "__main__":
    main()
