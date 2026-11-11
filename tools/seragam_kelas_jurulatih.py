#!/usr/bin/env python3
"""Ganti nama kelas jurulatih Inggeris dalam dialog .inc dengan nama Melayu
dari src/data/text/trainer_class_names.h (padanan ikut tag `asal`).

Guna:  python tools/seragam_kelas_jurulatih.py [--tulis] FAIL.inc ...
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from semak_teks import ROOT, string_c, versi_asal  # noqa: E402

REL = "src/data/text/trainer_class_names.h"


def peta_kelas():
    asal = [s for _, s in string_c(versi_asal(ROOT / REL))]
    baru = [s for _, s in string_c((ROOT / REL).read_text(encoding="utf-8"))]
    peta = {}
    for a, b in zip(asal, baru):
        a = a.replace("{PKMN}", "POKéMON")
        b = b.replace("{PKMN}", "POKéMON")
        if a != b and a not in peta:
            peta[a] = b
    # Bentuk tanpa simbol jantina, dan bentuk tanpa "POKéMON"
    for a, b in list(peta.items()):
        if a.endswith(("♂", "♀")):
            peta.setdefault(a[:-1], b[:-1])
    peta.setdefault("BREEDER", "PENTERNAK")
    peta.setdefault("RANGER", "RENJER")
    return dict(sorted(peta.items(), key=lambda kv: -len(kv[0])))


RE_STRING = re.compile(r'^(\s*\.string\s+")(.*)("\s*)$')


def main():
    tulis = "--tulis" in sys.argv
    fail = [a for a in sys.argv[1:] if a != "--tulis"]
    peta = peta_kelas()
    n = 0
    for rel in fail:
        p = ROOT / rel
        baris = p.read_text(encoding="utf-8").split("\n")
        for i, b in enumerate(baris):
            m = RE_STRING.match(b)
            if not m:
                continue
            isi = m.group(2)
            for en, ms in peta.items():
                corak = re.compile(r"(?<![A-Za-z])" + re.escape(en) + r"(?![A-Za-z])")
                if corak.search(isi):
                    n += 1
                    print(f"{rel}:{i+1}: {en} -> {ms}")
                    isi = corak.sub(ms, isi)
            baris[i] = m.group(1) + isi + m.group(3)
        if tulis:
            p.write_text("\n".join(baris), encoding="utf-8", newline="\n")
    print(f"{n} penggantian{' ditulis' if tulis else ' (cuba sahaja)'}")


if __name__ == "__main__":
    main()
