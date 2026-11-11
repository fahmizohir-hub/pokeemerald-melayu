#!/usr/bin/env python3
"""Susun semula bingkai menu move pertarungan (BG0 baris 54-59).

Asal:  kotak move lajur 0-19, kotak PP/JENIS lajur 20-29.
Baru:  kotak move lajur 0-22 (dua slot 80px), sempadan berkongsi lajur 23,
       kotak PP + ikon jenis lajur 24-29 (dalam 40px).

Jubin sempadan berkongsi dilukis ke jubin kosong 0x2B-0x2D dalam
textbox.png: separuh kanan sempadan kotak kiri + separuh kiri sempadan
kotak kanan. Semasa permainan, jubin itu dibina semula daripada bingkai
pilihan pemain (LoadMoveMenuSharedBorderTiles dalam src/battle_bg.c), sebab
0x12-0x1A dan 0x22-0x2A ditimpa oleh LoadUserWindowBorderGfx.

Jalankan dalam WSL (perlu Pillow):
    python3 tools/jana_menu_move.py
"""
import struct
import subprocess
from io import BytesIO
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
PNG = "graphics/battle_interface/textbox.png"
MAP = "graphics/battle_interface/textbox_map.bin"
BARIS = range(54, 60)
JUBIN_BARU = {"atas": 0x2B, "tengah": 0x2C, "bawah": 0x2D}


def asal(rel):
    return subprocess.run(["git", "-C", str(ROOT), "show", f"asal:{rel}"],
                          capture_output=True, check=True).stdout


def jubin(px, n):
    return [[px[(n % 16) * 8 + x, (n // 16) * 8 + y] for x in range(8)] for y in range(8)]


def tulis_jubin(px, n, data):
    for y in range(8):
        for x in range(8):
            px[(n % 16) * 8 + x, (n // 16) * 8 + y] = data[y][x]


def main():
    im = Image.open(BytesIO(asal(PNG)))
    px = im.load()
    peta = list(struct.unpack("<2048H", asal(MAP)))

    def e(row, col):
        return peta[row * 32 + col]

    # Jubin sempadan berkongsi untuk setiap jenis baris (atas/tengah/bawah).
    for jenis, row in (("atas", 54), ("tengah", 55), ("bawah", 59)):
        kanan = jubin(px, e(row, 19) & 0x3FF)   # sempadan kanan kotak move
        kiri = jubin(px, e(row, 20) & 0x3FF)    # sempadan kiri kotak PP
        baru = [kanan[y][4:8] + kiri[y][0:4] for y in range(8)]
        tulis_jubin(px, JUBIN_BARU[jenis], baru)

    for row in BARIS:
        lama = [e(row, c) for c in range(32)]
        dalam = lama[18]            # jubin dalam kotak (sama untuk semua lajur dalam)
        pal = lama[19] & 0xF000
        jenis = "atas" if row == 54 else "bawah" if row == 59 else "tengah"
        baru = lama[:]
        for c in range(1, 23):
            baru[c] = dalam
        baru[23] = JUBIN_BARU[jenis] | pal
        for c in range(24, 29):
            baru[c] = dalam
        baru[29] = lama[29]
        peta[row * 32:row * 32 + 32] = baru

    im.save(ROOT / PNG)
    (ROOT / MAP).write_bytes(struct.pack("<2048H", *peta))
    print("textbox.png dan textbox_map.bin ditulis.")


if __name__ == "__main__":
    main()
