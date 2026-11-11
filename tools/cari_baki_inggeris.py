#!/usr/bin/env python3
"""Senaraikan label .inc yang teksnya masih SAMA dengan versi Inggeris asal.

Guna:  python tools/cari_baki_inggeris.py [--semua]
Tanpa --semua, label yang jelas bukan bahasa (bunyi, nombor, placeholder)
disembunyikan.
"""
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from semak_teks import ROOT, hurai_inc  # noqa: E402


def fail_berubah_teks():
    out = subprocess.run(["git", "-C", str(ROOT), "ls-files", "data"],
                         capture_output=True, encoding="utf-8").stdout
    return [l for l in out.splitlines() if l.endswith(".inc") and "braille" not in l]


def main():
    semua = "--semua" in sys.argv
    jumlah = 0
    for rel in fail_berubah_teks():
        p = ROOT / rel
        teks = p.read_text(encoding="utf-8")
        if ".string" not in teks:
            continue
        asal = subprocess.run(["git", "-C", str(ROOT), "show", f"asal:{rel}"],
                              capture_output=True, encoding="utf-8").stdout
        b_asal, b_baru = hurai_inc(asal), hurai_inc(teks)
        for label, isi in b_baru.items():
            if b_asal.get(label) != isi:
                continue
            bersih = re.sub(r"\{[^}]*\}|\\[npl]|\$", " ", isi)
            perkataan = re.findall(r"[A-Za-z]{3,}", bersih)
            if not semua and len(perkataan) < 3:
                continue
            jumlah += 1
            print(f"{rel}: {label}: \"{isi[:70]}\"")
    print(f"\n{jumlah} label masih sama dengan Inggeris.")


if __name__ == "__main__":
    main()
