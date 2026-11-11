#!/usr/bin/env python3
"""Jana semula susunan abjad Easy Chat selepas perkataan diterjemah.

Guna:
    python tools/jana_easy_chat_abjad.py            # tulis fail
    python tools/jana_easy_chat_abjad.py --semak    # lapor sahaja, jangan tulis

Apa yang dibuat:
1. src/data/easy_chat/easy_chat_words_by_letter.h
   Semua entri dalam tatasusunan _Others dan _A.._Z (EC_WORD_*, EC_MOVE(..),
   EC_MOVE2(..), EC_POKEMON(..), EC_POKEMON_NATIONAL(..), termasuk pasangan
   DOUBLE_SPECIES_NAME) dikumpul, dikira teks paparannya (perkataan dari
   easy_chat_group_*.h, nama move dari src/data/text/move_names.h, nama
   spesies dari src/data/text/species_names.h), kemudian diagih semula ikut
   huruf pertama dan disusun ikut abjad. Set entri tidak berubah. Tatasusunan
   UnusedJapanese* dan bahagian lain fail dikekalkan.
2. .alphabeticalOrder dalam easy_chat_group_*.h (mod "kumpulan" dalam skrin
   Easy Chat) disusun semula ikut abjad perkataan Melayu.
3. Senarai move dalam easy_chat_group_move_1.h / move_2.h disusun semula ikut
   nama move Melayu.
4. EC_MAX_WORDS_IN_GROUP (include/constants/easy_chat.h) dinaikkan jika ada
   huruf atau kumpulan yang melebihinya (dibundar ke atas ke gandaan 10).

Nama move/spesies sentiasa dibaca semasa skrip dijalankan, jadi jalankan
semula skrip ini setiap kali nama move, spesies atau perkataan Easy Chat
berubah.
"""
import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from semak_teks import CHARMAP  # noqa: E402

DIR_EC = ROOT / "src/data/easy_chat"
FAIL_ABJAD = DIR_EC / "easy_chat_words_by_letter.h"
FAIL_KONST = ROOT / "include/constants/easy_chat.h"
HURUF = ["Others"] + [chr(c) for c in range(ord("A"), ord("Z") + 1)]


def baca(p):
    return p.read_text(encoding="utf-8")


def tulis(p, teks):
    p.write_text(teks, encoding="utf-8", newline="\n")


# ------------------------------------------------------------ teks paparan

def teks_perkataan():
    """EC_WORD_X -> teks, dan EC_WORD_X -> (kumpulan, indeks)."""
    konst = baca(FAIL_KONST)
    indeks = {}
    for m in re.finditer(r"#define (EC_WORD_\w+)\s+\(\((EC_GROUP_\w+) << EC_MASK_BITS\) \| (\d+)\)", konst):
        indeks[m.group(1)] = (m.group(2), int(m.group(3)))
    teks = {}
    for f in sorted(DIR_EC.glob("easy_chat_group_*.h")):
        t = baca(f)
        var = dict(re.findall(r'const u8 (gEasyChatWord_\w+)\[\] = _\("(.*?)"\);', t))
        for m in re.finditer(r"\[EC_INDEX\((EC_WORD_\w+)\)\]\s*=\s*\{\s*\.text\s*=\s*(gEasyChatWord_\w+)", t):
            teks[m.group(1)] = var[m.group(2)]
    return teks, indeks


def teks_jadual(fail, awalan):
    t = baca(ROOT / fail)
    return {m.group(1): m.group(2) for m in re.finditer(r"\[" + awalan + r"(\w+)\]\s*=\s*_\(\"(.*?)\"\)", t)}


PERKATAAN, INDEKS = teks_perkataan()
MOVE = teks_jadual("src/data/text/move_names.h", "MOVE_")
SPESIES = teks_jadual("src/data/text/species_names.h", "SPECIES_")


def paparan(entri):
    m = re.fullmatch(r"EC_MOVE2?\((\w+)\)", entri)
    if m:
        return MOVE[m.group(1)]
    m = re.fullmatch(r"EC_POKEMON(?:_NATIONAL)?\((\w+)\)", entri)
    if m:
        return SPESIES[m.group(1)]
    return PERKATAAN[entri]


def normal(s):
    s = re.sub(r"\{(\w+)\}", lambda m: m.group(1), s)  # {PK}RS -> PKRS
    return s.replace("é", "E").upper()


def kunci(s):
    """Susun ikut nilai bait charmap game (ruang < tanda baca < huruf)."""
    hasil = []
    for c in normal(s):
        kod = CHARMAP.get(c)
        hasil.append(kod[0] if kod else 0x100 + ord(c))
    return tuple(hasil)


def jenis(entri):
    if entri.startswith("EC_WORD_"):
        return 0
    if entri.startswith("EC_MOVE"):
        return 1
    return 2


def baldi(s):
    c = normal(s)[:1]
    return c if "A" <= c <= "Z" else "Others"


# ------------------------------------------------------------ fail abjad

RE_TATASUSUNAN = re.compile(
    r"(const u16 gEasyChatWordsByLetter_(\w+)\[\] = \{\n)(.*?)(\n\};)", re.S)


def hurai_unit(isi):
    """Pulangkan senarai unit: setiap unit ialah senarai entri (1 atau 2)."""
    baris = [b.strip().rstrip(",") for b in isi.splitlines() if b.strip()]
    unit, i = [], 0
    while i < len(baris):
        if baris[i] == "DOUBLE_SPECIES_NAME":
            unit.append(baris[i + 1 : i + 3])
            i += 3
        else:
            unit.append([baris[i]])
            i += 1
    return unit


def tulis_unit(unit):
    keluar = []
    for u in unit:
        if len(u) == 2:
            keluar.append("    DOUBLE_SPECIES_NAME")
        keluar += [f"    {e}," for e in u]
    return "\n".join(keluar)


def jana_abjad(teks):
    lama = {}
    for m in RE_TATASUSUNAN.finditer(teks):
        if m.group(2) in HURUF:
            lama[m.group(2)] = hurai_unit(m.group(3))
    assert set(lama) == set(HURUF), "tatasusunan huruf tidak lengkap"

    semua = []  # (unit, teks, kedudukan asal, huruf asal)
    n = 0
    for h in HURUF:
        for u in lama[h]:
            nama = {paparan(e) for e in u}
            assert len(nama) == 1, f"pasangan DOUBLE_SPECIES_NAME berbeza nama: {u}"
            semua.append((u, nama.pop(), n, h))
            n += 1

    baru = {h: [] for h in HURUF}
    for item in semua:
        baru[baldi(item[1])].append(item)
    for h, senarai in baru.items():
        if h == "Others":
            # Simbol: kekalkan susunan asal; pendatang baru di belakang.
            senarai.sort(key=lambda x: (x[3] != "Others", kunci(x[1]) if x[3] != "Others" else (), x[2]))
        else:
            senarai.sort(key=lambda x: (kunci(x[1]), jenis(x[0][0]), x[2]))

    def ganti(m):
        if m.group(2) not in HURUF:
            return m.group(0)
        return m.group(1) + tulis_unit([x[0] for x in baru[m.group(2)]]) + m.group(4)

    hasil = RE_TATASUSUNAN.sub(ganti, teks)
    saiz = {h: len(v) for h, v in baru.items()}
    return hasil, saiz, semua, baru


# ------------------------------------------------------------ susunan kumpulan

def jana_kumpulan(tulis_fail):
    saiz = {}
    berubah = []
    for f in sorted(DIR_EC.glob("easy_chat_group_*.h")):
        t = baca(f)
        if "move_" in f.name:
            corak = re.compile(r"(const u16 gEasyChatGroup_\w+\[\] = \{\n)(.*?)(\n\};)", re.S)
            m = corak.search(t)
            baris = [b.strip().rstrip(",") for b in m.group(2).splitlines() if b.strip()]
            asal = list(baris)
            baris.sort(key=lambda b: (kunci(MOVE[b[len("MOVE_"):]]), asal.index(b)))
            saiz[f.stem] = len(baris)
            nt = t[: m.start(2)] + "\n".join(f"    {b}," for b in baris) + t[m.end(2):]
        elif "pokemon" in f.name:
            saiz[f.stem] = len(re.findall(r"SPECIES_\w+", t))
            continue
        else:
            entri = list(re.finditer(
                r"\[EC_INDEX\((EC_WORD_\w+)\)\]\s*=\s*\{\s*\.text\s*=\s*gEasyChatWord_\w+,\s*"
                r"\.alphabeticalOrder\s*=\s*EC_INDEX\((EC_WORD_\w+)\)", t))
            perkataan = [e.group(1) for e in entri]
            ikut_indeks = sorted(perkataan, key=lambda w: INDEKS[w][1])
            assert [INDEKS[w][1] for w in ikut_indeks] == list(range(len(entri))), f"indeks tidak berturutan: {f.name}"
            tersusun = sorted(ikut_indeks, key=lambda w: (kunci(PERKATAAN[w]), INDEKS[w][1]))
            sasaran = {w: tersusun[INDEKS[w][1]] for w in perkataan}
            saiz[f.stem] = len(entri)
            potong, akhir = [], 0
            for e in entri:
                potong.append(t[akhir : e.start(2)])
                potong.append(sasaran[e.group(1)])
                akhir = e.end(2)
            potong.append(t[akhir:])
            nt = "".join(potong)
        if nt != t:
            berubah.append(f.name)
            if tulis_fail:
                tulis(f, nt)
    return saiz, berubah


# ------------------------------------------------------------ had

def semak_had(perlu, tulis_fail):
    t = baca(FAIL_KONST)
    m = re.search(r"#define EC_MAX_WORDS_IN_GROUP (\d+)([^\n]*)", t)
    kini = int(m.group(1))
    if perlu <= kini:
        return kini, kini
    baru = -(-perlu // 10) * 10
    if tulis_fail:
        t = t[: m.start()] + f"#define EC_MAX_WORDS_IN_GROUP {baru}" + t[m.end():]
        tulis(FAIL_KONST, t)
    return kini, baru


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--semak", action="store_true", help="lapor sahaja, jangan tulis")
    a = ap.parse_args()
    tulis_fail = not a.semak

    teks = baca(FAIL_ABJAD)
    hasil, saiz, semua, baru = jana_abjad(teks)

    # Pastikan set entri sama.
    lama = sorted(tuple(x[0]) for x in semua)
    selepas = sorted(tuple(u) for h in HURUF for u in hurai_unit(
        next(m.group(3) for m in RE_TATASUSUNAN.finditer(hasil) if m.group(2) == h)))
    assert lama == selepas, "set entri berubah!"

    saiz_kump, berubah = jana_kumpulan(tulis_fail)
    if tulis_fail and hasil != teks:
        tulis(FAIL_ABJAD, hasil)
        berubah.append(FAIL_ABJAD.name)

    print("Saiz setiap huruf (unit, pasangan DOUBLE dikira 1):")
    print("  " + "  ".join(f"{h}={n}" for h, n in saiz.items()))
    besar_h = max(saiz, key=saiz.get)
    besar_k = max(saiz_kump, key=saiz_kump.get)
    print(f"Huruf terbesar: {besar_h} ({saiz[besar_h]}); kumpulan terbesar: {besar_k} ({saiz_kump[besar_k]})")
    perlu = max(saiz[besar_h], saiz_kump[besar_k])
    kini, had = semak_had(perlu, tulis_fail)
    if had != kini:
        print(f"EC_MAX_WORDS_IN_GROUP {kini} -> {had}" + ("" if tulis_fail else " (belum ditulis)"))
    else:
        print(f"EC_MAX_WORDS_IN_GROUP {kini} mencukupi.")
    print(f"{len(semua)} unit; fail {'berubah' if tulis_fail else 'akan berubah'}: {', '.join(berubah) or 'tiada'}")


if __name__ == "__main__":
    main()
