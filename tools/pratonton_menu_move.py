#!/usr/bin/env python3
"""Lukis pratonton menu move pertarungan (susun atur 80px + ikon jenis).

Guna jubin/peta bingkai, fon sempit dan ikon jenis sebenar dari repo.
Jalankan dalam WSL (perlu Pillow):
    python3 tools/pratonton_menu_move.py KELUAR.png
"""
import re
import struct
import sys
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import semak_teks as st  # noqa: E402

R0, R1 = 54, 60
src = (ROOT / "src/fonts.c").read_text(encoding="utf-8")


def jadual(n):
    m = re.search(n + r"\[\]\s*=\s*\{(.*?)\};", src, re.S)
    return [int(x) for x in re.findall(r"\d+", m.group(1))]


FON = (Image.open(ROOT / "graphics/fonts/latin_narrow.png"), jadual("gFontNarrowLatinGlyphWidths"))
tiles = Image.open(ROOT / "graphics/battle_interface/textbox.png")
tw = tiles.width // 8
tp = tiles.load()
raw = (ROOT / "graphics/battle_interface/textbox.gbapal").read_bytes()
pal = [((v & 31) * 8, ((v >> 5) & 31) * 8, ((v >> 10) & 31) * 8)
       for v in struct.unpack("<%dH" % (len(raw) // 2), raw)]
peta = struct.unpack("<2048H", (ROOT / "graphics/battle_interface/textbox_map.bin").read_bytes())


def bingkai(img):
    px = img.load()
    for row in range(R0, R1):
        for col in range(30):
            e = peta[row * 32 + col]
            t, hf, vf, p = e & 0x3FF, (e >> 10) & 1, (e >> 11) & 1, e >> 12
            tx, ty = (t % tw) * 8, (t // tw) * 8
            for y in range(8):
                for x in range(8):
                    sx = 7 - x if hf else x
                    sy = 7 - y if vf else y
                    c = tp[tx + sx, ty + sy]
                    px[col * 8 + x, (row - R0) * 8 + y] = pal[(p * 16 + c) % len(pal)]


def teks(img, s, X, Y, warna=(72, 72, 72), bayang=(208, 208, 200)):
    gim, wtab = FON
    g = gim.load()
    px = img.load()
    for ch in s:
        code = st.CHARMAP[ch][0]
        cx, cy = (code % 16) * 16, (code // 16) * 16
        for yy in range(16):
            for xx in range(16):
                v = g[cx + xx, cy + yy]
                if v == 1:
                    px[X + xx, Y + yy] = warna
                elif v == 2:
                    px[X + xx, Y + yy] = bayang
        X += wtab[code]


def panel(nama, jenis, pp="PP 35/35"):
    img = Image.new("RGB", (240, (R1 - R0) * 8))
    bingkai(img)
    pos = [(2, 55), (13, 55), (2, 57), (13, 57)]
    for n, (c, r) in zip(nama, pos):
        teks(img, n, c * 8, (r - R0) * 8 + 1)
    teks(img, "▶", 1 * 8 + 1, (55 - R0) * 8 + 1)
    teks(img, pp, 24 * 8 + 1, (55 - R0) * 8 + 1)
    ikon = Image.open(ROOT / f"graphics/types/{jenis}.png").convert("RGBA")
    # indeks 0 lutsinar
    ip = Image.open(ROOT / f"graphics/types/{jenis}.png")
    mask = Image.eval(ip.convert("L"), lambda v: 0)
    mpx, ipx = mask.load(), ip.load()
    for y in range(ip.height):
        for x in range(ip.width):
            mpx[x, y] = 0 if ipx[x, y] == 0 else 255
    img.paste(ikon.convert("RGB"), (24 * 8 + 5, (57 - R0) * 8), mask)
    return img


def main():
    keluar = sys.argv[1]
    a = panel(["TETAKAN KARATE", "KELAJUAN EKSTREM", "TUMBUKAN DINAMIK", "SERANGAN SAYAP"], "fight")
    b = panel(["PERLINDUNGAN", "SEMBURAN API", "GIGITAN REMUK", "LUNCURAN OMBAK"], "fire", "PP 15/15")
    c = panel(["TUMBUKAN METEOR", "SEPAKAN LOMPAT", "PANDANGAN JAUH", "PUKULAN"], "steel", "PP 10/10")
    h = a.height
    out = Image.new("RGB", (240, h * 3 + 8), (30, 30, 30))
    for i, im in enumerate((a, b, c)):
        out.paste(im, (0, i * (h + 4)))
    out.resize((240 * 4, out.height * 4), Image.NEAREST).save(keluar)


if __name__ == "__main__":
    main()
