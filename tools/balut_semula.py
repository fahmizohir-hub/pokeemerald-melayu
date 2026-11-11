#!/usr/bin/env python3
"""Balut semula label .inc yang ada baris melebihi had lebar kotak dialog.

Guna:  python tools/balut_semula.py FAIL.inc [--had 208]

Untuk setiap label yang ada baris terlalu lebar, setiap perenggan (\\p)
dicantum semula dan dibalut tamak: baris ke-2 guna \\n, baris seterusnya \\l.
Label lain tidak disentuh.
"""
import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from semak_teks import HAD_LALAI, lebar_baris, pecah_baris  # noqa: E402

RE_LABEL = re.compile(r"^(\w+)::?\s*$")
RE_STRING = re.compile(r'^\s*\.string\s+"(.*)"\s*$')


def balut_perenggan(teks, had):
    perkataan = teks.split(" ")
    baris, semasa = [], ""
    for p in perkataan:
        cuba = p if not semasa else semasa + " " + p
        if semasa and lebar_baris(cuba) > had:
            baris.append(semasa)
            semasa = p
        else:
            semasa = cuba
    if semasa:
        baris.append(semasa)
    return baris


def balut_label(isi, had):
    tamat = isi.endswith("$")
    badan = isi[:-1] if tamat else isi
    perenggan = badan.split("\\p")
    keluar = []
    for pi, per in enumerate(perenggan):
        rata = re.sub(r"\\[nl]", " ", per)
        rata = re.sub(r" {2,}", " ", rata).strip()
        baris = balut_perenggan(rata, had) if rata else [""]
        for bi, b in enumerate(baris):
            if bi < len(baris) - 1:
                b += "\\n" if bi == 0 else "\\l"
            elif pi < len(perenggan) - 1:
                b += "\\p"
            keluar.append(b)
    if tamat:
        keluar[-1] += "$"
    return keluar


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("fail")
    ap.add_argument("--had", type=int, default=HAD_LALAI)
    a = ap.parse_args()
    p = Path(a.fail)
    baris = p.read_text(encoding="utf-8").split("\n")
    hasil, i, dibalut = [], 0, []
    while i < len(baris):
        b = baris[i]
        hasil.append(b)
        m = RE_LABEL.match(b)
        i += 1
        if not m:
            continue
        j = i
        isi = ""
        while j < len(baris) and RE_STRING.match(baris[j]):
            isi += RE_STRING.match(baris[j]).group(1)
            j += 1
        if j == i:
            continue
        terlebar = any(lebar_baris(x) > a.had for x in pecah_baris(isi))
        if not terlebar:
            continue
        lekuk = re.match(r"^(\s*)", baris[i]).group(1)
        for x in balut_label(isi, a.had):
            hasil.append(f'{lekuk}.string "{x}"')
        dibalut.append(m.group(1))
        i = j
    p.write_text("\n".join(hasil), encoding="utf-8", newline="\n")
    print(f"{len(dibalut)} label dibalut semula: {', '.join(dibalut)}")


if __name__ == "__main__":
    main()
