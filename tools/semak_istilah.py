#!/usr/bin/env python3
"""Semak keselarasan istilah dan sisa Bahasa Inggeris dalam teks terjemahan.

Guna:
    python tools/semak_istilah.py FAIL...            # lapor
    python tools/semak_istilah.py --betul FAIL...    # betulkan varian salah
    python tools/semak_istilah.py --kumpulan 01 02   # fail dari tools/kumpulan/NN-*.txt
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# Varian salah -> bentuk betul (ikut GLOSARI.md). Diganti automatik dengan --betul.
VARIAN = {
    "KAPTEN STERN": "KAPT. STERN",
    "AIR TERJUN METEOR": "LATA METEOR",
    "LENCANA DYNAMO": "LENCANA DINAMO",
    "LENCANA STONE": "LENCANA BATU",
    "LENCANA KNUCKLE": "LENCANA BUKU JARI",
    "LENCANA HEAT": "LENCANA HABA",
    "LENCANA BALANCE": "LENCANA IMBANGAN",
    "LENCANA FEATHER": "LENCANA BULU",
    "LENCANA MIND": "LENCANA MINDA",
    "LENCANA RAIN": "LENCANA HUJAN",
    "BARUA": "ANAK BUAH",
    "PUSAT POKEMON": "PUSAT POKéMON",
    "MR. BRINEY": "ENCIK BRINEY",
    "MR. STONE": "ENCIK STONE",
    "GUNUNG MT.": "GUNUNG",
    "POSTER CIUM": "POSTER KISS",  # ikut nama hiasan dalam strings.c
    "KUSYEN CIUM": "KUSYEN KISS",
    "Mata Pertarungan": "Mata Tarung",
    "MC:": "PENGACARA:",
    "SUDUT LOTERI POKéMON": "SUDUT CABUTAN BERTUAH POKéMON",
    "LOTERI POKéMON": "CABUTAN BERTUAH",
    "ROLET": "RULET",
    "Penyesuai Tanpa Wayar": "Penyesuai Wayarles",
}

# Perkataan Inggeris yang tak patut tinggal dalam dialog (sempadan perkataan).
INGGERIS = re.compile(
    r"\b(the|you|your|and|with|this|that|what|have|don't|can't|I'm|it's|"
    r"will|would|there|here|please|thank|POKéMON CENTER|TRAINER|"
    r"GYM LEADER|ROUTE \d|TOWN|CITY|BADGE)\b"
)
# Bunyi/nama yang dibenarkan walaupun nampak Inggeris
ABAIKAN = re.compile(r"TEAM AQUA|TEAM MAGMA|BATTLE (TOWER|DOME|PALACE|ARENA|FACTORY|PIKE|PYRAMID|FRONTIER|TENT)|"
                     r"TRAINER HILL|DEVON|SILPH|MATCH CALL|GAME FREAK|REEL TIME")

RE_STRING = re.compile(r'^(\s*\.string\s+")(.*)("\s*)$')


def fail_kumpulan(kod):
    hasil = []
    for k in kod:
        for f in (ROOT / "tools/kumpulan").glob(f"{k}-*.txt"):
            hasil += [l.strip() for l in f.read_text().splitlines() if l.strip()]
    return hasil


def main():
    args = sys.argv[1:]
    betul = "--betul" in args
    args = [a for a in args if a != "--betul"]
    if args and args[0] == "--kumpulan":
        fail = fail_kumpulan(args[1:])
    else:
        fail = args
    n_varian = n_ing = 0
    for rel in fail:
        p = ROOT / rel
        baris = p.read_text(encoding="utf-8").split("\n")
        ubah = False
        for i, b in enumerate(baris):
            m = RE_STRING.match(b)
            if not m:
                continue
            isi = m.group(2)
            for salah, betul_ in VARIAN.items():
                corak = re.compile(r"(?<![A-Za-z])" + re.escape(salah) + r"(?![A-Za-z])")
                if corak.search(isi):
                    n_varian += 1
                    print(f"{rel}:{i+1}: varian '{salah}' -> '{betul_}'")
                    if betul:
                        isi = corak.sub(betul_, isi)
                        ubah = True
            bersih = ABAIKAN.sub("", re.sub(r"\{[^}]*\}", "", isi))
            if INGGERIS.search(bersih):
                n_ing += 1
                print(f"{rel}:{i+1}: mungkin Inggeris: \"{isi}\"")
            baris[i] = m.group(1) + isi + m.group(3)
        if ubah:
            p.write_text("\n".join(baris), encoding="utf-8", newline="\n")
    print(f"\n{len(fail)} fail, {n_varian} varian, {n_ing} baris mungkin Inggeris.")


if __name__ == "__main__":
    main()
