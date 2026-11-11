#!/usr/bin/env python3
"""BERRY -> BERI (v0.2.1).

- "ORAN BERRY" -> "BERI ORAN" (susunan Melayu) untuk nama buah dalam
  src/berry.c; "JUS BERRY" -> "JUS BERI".
- Teks yang nama buahnya datang dari {STR_VAR_n}: susunan diterbalikkan dalam
  fail yang disenaraikan dalam TERBALIK.
- BERRY / BERRIES lain -> BERI.

Hanya isi rentetan diubah: `.string "..."` dalam .inc/.s, dan "..." dalam
fail .c/.h. Nama dalam kod (ITEM_ORAN_BERRY, BERRY_NAME_LENGTH) tak disentuh
kerana ia di luar tanda petik.

    python tools/tukar_beri.py --semak   # tunjuk bilangan sahaja
    python tools/tukar_beri.py
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

NAMA_BUAH = re.findall(r'\.name\s*=\s*_\("([A-Z]+)"\)',
                       (ROOT / "src/berry.c").read_text(encoding="utf-8"))

# {STR_VAR_n} BERRY di mana STR_VAR_n ialah nama buah (bukan bilangan)
TERBALIK = {
    "src/mystery_event_msg.c": ["STR_VAR_1", "STR_VAR_2"],
    "src/strings.c": ["STR_VAR_1"],  # gText_Var1Berry (HANCUR BERRY)
}

RE_STRING_INC = re.compile(r'(\.string\s+")((?:[^"\\]|\\.)*)(")')
RE_STRING_C = re.compile(r'(")((?:[^"\\]|\\.)*)(")')
RE_BUAH = re.compile(r"\b(" + "|".join(NAMA_BUAH) + r") BERR(?:Y|IES)\b")


def tukar(teks, var_buah=()):
    teks = RE_BUAH.sub(r"BERI \1", teks)
    for v in var_buah:
        teks = re.sub(r"\{" + v + r"\} BERRY\b", "BERI {" + v + "}", teks)
    teks = re.sub(r"\bBERRIES\b", "BERI", teks)
    teks = re.sub(r"\bBERRY\b", "BERI", teks)
    return teks


def proses(p, semak):
    rel = p.relative_to(ROOT).as_posix()
    t = p.read_text(encoding="utf-8")
    if "BERR" not in t:
        return 0
    var_buah = TERBALIK.get(rel, [])
    if p.suffix in (".inc", ".s"):
        baru = RE_STRING_INC.sub(lambda m: m.group(1) + tukar(m.group(2), var_buah) + m.group(3), t)
    else:
        out = []
        for baris in t.split("\n"):
            s = baris.lstrip()
            if s.startswith("#include") or s.startswith("//"):
                out.append(baris)
                continue
            out.append(RE_STRING_C.sub(lambda m: m.group(1) + tukar(m.group(2), var_buah) + m.group(3), baris))
        baru = "\n".join(out)
    n = sum(1 for a, b in zip(t.split("\n"), baru.split("\n")) if a != b)
    if n and not semak:
        p.write_text(baru, encoding="utf-8", newline="\n")
    return n


def main():
    semak = "--semak" in sys.argv
    jumlah = 0
    fail = list(ROOT.glob("data/**/*.inc")) + list(ROOT.glob("data/*.s")) + \
        list(ROOT.glob("src/**/*.c")) + list(ROOT.glob("src/**/*.h"))
    for p in sorted(fail):
        n = proses(p, semak)
        if n:
            print(f"{n:4d}  {p.relative_to(ROOT).as_posix()}")
            jumlah += n
    print(f"Jumlah baris: {jumlah}" + (" (semak sahaja)" if semak else ""))


if __name__ == "__main__":
    main()
