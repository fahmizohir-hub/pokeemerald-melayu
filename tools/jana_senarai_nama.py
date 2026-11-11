#!/usr/bin/env python3
"""Jana SENARAI-NAMA.md: padanan nama Inggeris (git HEAD) -> Melayu (fail semasa).

Guna:  python tools/jana_senarai_nama.py
Hasil dipakai sebagai rujukan semasa menterjemah huraian, menu dan dialog.
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from semak_teks import ROOT, string_c, versi_asal  # noqa: E402

BAHAGIAN = [
    ("Move", "src/data/text/move_names.h", None),
    ("Barang", "src/data/items.h", r"\.name\s*=\s*$"),
    ("Kebolehan", "src/data/text/abilities.h", "gAbilityNames"),
    ("Sifat", "src/data/text/nature_names.h", None),
    ("Jenis", "src/battle_main.c", "gTypeNames"),
]


def pilih(teks, corak):
    hasil = []
    for off, isi in string_c(teks):
        sebelum = teks[:off]
        if corak is None:
            hasil.append(isi)
        elif corak.startswith("\\."):
            if re.search(corak, sebelum):
                hasil.append(isi)
        else:
            mula = sebelum.rfind(corak)
            if mula != -1 and "};" not in sebelum[mula:]:
                hasil.append(isi)
    return hasil


def main():
    keluar = ["# Senarai Nama (dijana automatik)", "",
              "Jangan edit fail ni. Jalankan `python tools/jana_senarai_nama.py`.", ""]
    for tajuk, rel, corak in BAHAGIAN:
        baru = pilih((ROOT / rel).read_text(encoding="utf-8"), corak)
        asal = pilih(versi_asal(ROOT / rel), corak)
        keluar += [f"## {tajuk}", "", "| Inggeris | Melayu |", "|---|---|"]
        for a, b in zip(asal, baru):
            if a and a not in ("-", "-------", "????????", "???"):
                keluar.append(f"| {a} | {b} |")
        keluar.append("")
    (ROOT / "SENARAI-NAMA.md").write_text("\n".join(keluar), encoding="utf-8", newline="\n")
    print("SENARAI-NAMA.md dijana.")


if __name__ == "__main__":
    main()
