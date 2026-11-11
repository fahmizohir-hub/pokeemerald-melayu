#!/usr/bin/env python3
"""Sahkan teks wujud dalam ROM yang dibina (encode guna charmap.txt).

Guna:  python tools/cari_dalam_rom.py "TEKS 1" "TEKS 2" ...
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from semak_teks import CHARMAP, ROOT  # noqa: E402

rom = (ROOT / "pokeemerald.gba").read_bytes()
tiada = 0
for s in sys.argv[1:]:
    b = b"".join(bytes(CHARMAP[c]) for c in s)
    ada = b in rom
    tiada += not ada
    print(f"{'ADA  ' if ada else 'TIADA'}  {s}")
sys.exit(1 if tiada else 0)
