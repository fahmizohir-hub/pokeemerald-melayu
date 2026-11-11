#!/usr/bin/env python3
"""Semak lebar piksel baris dialog dalam fail .inc.

Guna:
    python tools/semak_teks.py data/maps/LittlerootTown/scripts.inc
    python tools/semak_teks.py --semua            # semua fail .inc dalam data/
    python tools/semak_teks.py --had 208 FAIL...  # tukar had lebar

Kira lebar setiap baris (dipisah oleh \\n, \\l, \\p) guna jadual lebar font
FONT_NORMAL dari src/fonts.c dan charmap.txt, kemudian lapor baris yang
melebihi had kotak dialog. Juga semak kod kawalan yang hilang berbanding
versi asal dalam git (tag `asal`, teks Inggeris).
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
HAD_LALAI = 208  # kotak dialog 27 tile = 216 px, tolak margin

# Anggaran lebar untuk placeholder yang nilainya berubah semasa game.
LEBAR_PLACEHOLDER = {
    "PLAYER": 7 * 6,
    "RIVAL": 7 * 6,
    "STR_VAR_1": 10 * 6,
    "STR_VAR_2": 10 * 6,
    "STR_VAR_3": 10 * 6,
    "KUN": 0,
}


def baca_jadual_lebar(nama="gFontNormalLatinGlyphWidths"):
    teks = (ROOT / "src/fonts.c").read_text(encoding="utf-8")
    m = re.search(nama + r"\[\]\s*=\s*\{(.*?)\};", teks, re.S)
    return [int(x) for x in re.findall(r"\d+", m.group(1))]


def baca_charmap():
    peta = {}
    for baris in (ROOT / "charmap.txt").read_text(encoding="utf-8").splitlines():
        baris = baris.split("@")[0].strip()
        m = re.match(r"^'(.+)'\s*=\s*([0-9A-Fa-f ]+)$", baris)
        if m:
            kunci, kod = m.group(1), [int(b, 16) for b in m.group(2).split()]
            peta[kunci] = kod
            # '\'' dalam charmap = apostrof biasa dalam teks
            if len(kunci) == 2 and kunci[0] == "\\" and kunci[1] in "'\"":
                peta.setdefault(kunci[1], kod)
            continue
        m = re.match(r"^([A-Z0-9_]+)\s*=\s*([0-9A-Fa-f ]+)$", baris)
        if m:
            peta["{" + m.group(1) + "}"] = [int(b, 16) for b in m.group(2).split()]
    return peta


LEBAR = baca_jadual_lebar()
LEBAR_SEMPIT = baca_jadual_lebar("gFontNarrowLatinGlyphWidths")
# {FONT_NARROW} ... {FONT_NORMAL} dalam teks menukar jadual lebar.
FON = {"FONT_NORMAL": LEBAR, "FONT_NARROW": LEBAR_SEMPIT}
CHARMAP = baca_charmap()


def lebar_baris(s):
    """Lebar piksel satu baris teks (tanpa \\n, \\p, \\l)."""
    jumlah = 0
    jadual = LEBAR
    i = 0
    while i < len(s):
        if s[i] == "{":
            j = s.index("}", i)
            nama = s[i + 1 : j]
            if nama in FON:
                jadual = FON[nama]
            elif nama in LEBAR_PLACEHOLDER:
                jumlah += LEBAR_PLACEHOLDER[nama]
            elif "{" + nama + "}" in CHARMAP:
                kod = CHARMAP["{" + nama + "}"]
                if kod[0] < 0xF7:  # aksara boleh cetak (contoh {PKMN})
                    jumlah += sum(jadual[b] for b in kod)
            i = j + 1
            continue
        c = s[i]
        if c == "\\" and i + 1 < len(s):
            c = s[i : i + 2]
            i += 1
        kod = CHARMAP.get(c)
        if kod is None:
            raise ValueError(f"aksara tiada dalam charmap: {c!r}")
        jumlah += sum(jadual[b] for b in kod if b < len(jadual))
        i += 1
    return jumlah


RE_LABEL = re.compile(r"^(\w+)::?\s*$")
RE_STRING = re.compile(r'^\s*\.string\s+"(.*)"\s*$')


def hurai_inc(teks):
    """Pulangkan {label: teks_penuh} untuk setiap blok .string."""
    blok, label = {}, None
    for baris in teks.splitlines():
        m = RE_LABEL.match(baris)
        if m:
            label = m.group(1)
            continue
        m = RE_STRING.match(baris)
        if m and label:
            blok[label] = blok.get(label, "") + m.group(1)
    return blok


def pecah_baris(teks):
    teks = teks.rstrip("$")
    return [b for b in re.split(r"\\[npl]", teks)]


def susunan_baris_ok(teks):
    for perenggan in teks.split("\\p"):
        pemisah = re.findall(r"\\[nl]", perenggan)
        if pemisah.count("\\n") > 1:
            return False
        if "\\n" in pemisah and "\\l" in pemisah[: pemisah.index("\\n")]:
            return False
    return True


def kod_kawalan(teks):
    # Kod tukar fon boleh ditambah untuk muatkan teks; tidak dikira.
    return sorted(k for k in re.findall(r"\{[A-Z_0-9]+(?: [^}]*)?\}|\$", teks)
                  if k not in ("{FONT_NARROW}", "{FONT_NORMAL}"))


def versi_asal(fail):
    rel = Path(fail).resolve().relative_to(ROOT).as_posix()
    try:
        return subprocess.run(
            ["git", "-C", str(ROOT), "show", f"asal:{rel}"],
            capture_output=True, check=True, encoding="utf-8",
        ).stdout
    except subprocess.CalledProcessError:
        return None


def semak_fail(fail, had):
    teks = Path(fail).read_text(encoding="utf-8")
    blok = hurai_inc(teks)
    asal = versi_asal(fail)
    blok_asal = hurai_inc(asal) if asal else {}
    masalah = 0
    for label, isi in blok.items():
        isi_asal = blok_asal.get(label)
        # Placeholder dianggar besar; jangan salahkan baris yang tak lebih
        # lebar daripada baris terlebar teks asal label yang sama.
        had_label = max(had, lebar_maks(isi_asal)) if isi_asal else had
        for baris in pecah_baris(isi):
            try:
                w = lebar_baris(baris)
            except ValueError as e:
                print(f"{fail}: {label}: {e}")
                masalah += 1
                continue
            if w > had_label:
                print(f"{fail}: {label}: {w}px > {had_label}px: \"{baris}\"")
                masalah += 1
        # Kotak dialog 2 baris: dalam satu perenggan (\p) hanya satu \n,
        # dan \n tak boleh datang selepas \l.
        if isi_asal is not None and susunan_baris_ok(isi_asal) and not susunan_baris_ok(isi):
            print(f"{fail}: {label}: lebih dari 2 baris dalam satu kotak "
                  f"(guna \\n sekali, kemudian \\l atau \\p): \"{isi}\"")
            masalah += 1
        if label in blok_asal and kod_kawalan(isi) != kod_kawalan(blok_asal[label]):
            print(f"{fail}: {label}: kod kawalan berbeza dari asal "
                  f"{kod_kawalan(blok_asal[label])} -> {kod_kawalan(isi)}")
            masalah += 1
    for label in blok_asal.keys() - blok.keys():
        print(f"{fail}: label hilang: {label}")
        masalah += 1
    return masalah


# ---------------------------------------------------------------- fail C

RE_C_STRING = re.compile(r'_\(\s*((?:"(?:[^"\\]|\\.)*"\s*)+)\)')
RE_C_KEPING = re.compile(r'"((?:[^"\\]|\\.)*)"')

# Had panjang nama (dalam bait) untuk array bersaiz tetap.
# (fail, corak baris sebelum string atau nama array, had)
HAD_NAMA = [
    ("src/data/text/move_names.h", None, 16),  # BM: dinaikkan (slot pertarungan 80px)
    ("src/data/items.h", r"\.name\s*=\s*$", 13),  # name[14] termasuk penamat
    ("src/data/text/abilities.h", "gAbilityNames", 12),
    ("src/battle_main.c", "gTypeNames", 6),
    ("src/data/text/nature_names.h", None, 7),
    ("src/data/text/trainer_class_names.h", None, 12),  # [13]
    ("src/data/decoration/header.h", None, 15),  # name[16]
    ("src/data/pokemon/pokedex_entries.h", r"\.categoryName\s*=\s*$", 11),  # [12]
]

# Fail huraian yang tingkapnya tetap: had = baris terpanjang asal dalam fail.
FAIL_HURAIAN = {
    "src/data/text/item_descriptions.h",
    "src/data/text/move_descriptions.h",
    "src/data/text/abilities.h",
    "src/data/pokemon/pokedex_text.h",
    "src/berry.c",
    "src/data/text/ribbon_descriptions.h",
    "src/data/text/gift_ribbon_descriptions.h",
    "src/data/decoration/description.h",
}

# Perkataan Easy Chat: had = perkataan terlebar asal merentas SEMUA kumpulan.
FOLDER_EASY_CHAT = "src/data/easy_chat/"
_had_easy_chat = None


def had_easy_chat():
    global _had_easy_chat
    if _had_easy_chat is None:
        w = 0
        for f in sorted((ROOT / FOLDER_EASY_CHAT).glob("easy_chat_group_*.h")):
            asal = versi_asal(f) or ""
            for _, s in string_c(asal):
                w = max(w, lebar_maks(s))
        _had_easy_chat = w
    return _had_easy_chat


def string_c(teks):
    """Senarai (offset, isi) bagi setiap _("...") dalam fail C."""
    hasil = []
    for m in RE_C_STRING.finditer(teks):
        isi = "".join(RE_C_KEPING.findall(m.group(1)))
        isi = isi.replace('\\"', '"')
        hasil.append((m.start(), isi))
    return hasil


def panjang_bait(s):
    n, i = 0, 0
    while i < len(s):
        if s[i] == "{":
            j = s.index("}", i)
            kod = CHARMAP.get(s[i : j + 1])
            n += len(kod) if kod else 2
            i = j + 1
            continue
        if s[i] == "\\" and i + 1 < len(s):
            i += 1
        n += 1
        i += 1
    return n


def had_nama_untuk(rel, teks, offset):
    for fail, corak, had in HAD_NAMA:
        if rel != fail:
            continue
        if corak is None:
            return had
        sebelum = teks[:offset]
        if corak.startswith("\\."):
            if re.search(corak, sebelum):
                return had
        else:
            mula = sebelum.rfind(corak)
            if mula != -1 and "};" not in sebelum[mula:]:
                return had
    return None


def lebar_maks(isi):
    try:
        return max(lebar_baris(b) for b in pecah_baris(isi))
    except ValueError:
        return 0


def semak_clear_to(isi):
    """Teks sebelum {CLEAR_TO n} mesti muat dalam n piksel."""
    salah = []
    for baris in re.split(r"\\[npl]", isi):
        for m in re.finditer(r"\{CLEAR_TO (\d+)\}", baris):
            sebelum = re.sub(r"\{CLEAR_TO \d+\}", "", baris[: m.start()])
            sebelum = re.sub(r"{FONT_(?!NARROW}|NORMAL})[A-Z_]+}", "", sebelum)
            try:
                w = lebar_baris(sebelum)
            except ValueError:
                continue
            if w > int(m.group(1)):
                salah.append((w, int(m.group(1)), sebelum))
    return salah


def semak_fail_c(fail, had_dialog):
    rel = Path(fail).resolve().relative_to(ROOT).as_posix()
    teks = Path(fail).read_text(encoding="utf-8")
    baru = string_c(teks)
    asal_teks = versi_asal(fail)
    asal = string_c(asal_teks) if asal_teks else []
    masalah = amaran = 0
    if asal and len(asal) != len(baru):
        print(f"{rel}: bilangan string berubah {len(asal)} -> {len(baru)}")
        return 1, 0
    had_fail = None
    if rel in FAIL_HURAIAN and asal:
        had_fail = max(lebar_maks(s) for _, s in asal)
    elif rel.startswith(FOLDER_EASY_CHAT) and asal:
        had_fail = had_easy_chat()
    for idx, (off, isi) in enumerate(baru):
        no = teks.count("\n", 0, off) + 1
        isi_asal = asal[idx][1] if asal else isi
        tempat = f"{rel}:{no}"
        # aksara tak dikenali
        for b in pecah_baris(isi):
            try:
                lebar_baris(re.sub(r"\{[^}]*\}", "", b))
            except ValueError as e:
                print(f"{tempat}: {e}")
                masalah += 1
        # kod kawalan
        if kod_kawalan(isi) != kod_kawalan(isi_asal):
            print(f"{tempat}: kod kawalan berbeza {kod_kawalan(isi_asal)} -> {kod_kawalan(isi)}")
            masalah += 1
        if re.findall(r"\\[npl]", isi_asal).count("\\p") != re.findall(r"\\[npl]", isi).count("\\p") and "\\p" in isi_asal:
            print(f"{tempat}: bilangan \\p berubah: \"{isi}\"")
            amaran += 1
        # had nama
        had = had_nama_untuk(rel, teks, off)
        if had is not None and panjang_bait(isi) > had:
            print(f"{tempat}: nama {panjang_bait(isi)} > {had} aksara: \"{isi}\"")
            masalah += 1
        # CLEAR_TO
        for w, n, s in semak_clear_to(isi):
            print(f"{tempat}: {w}px > CLEAR_TO {n}: \"{s}\"")
            masalah += 1
        # lebar baris
        if had is None:
            w_baru, w_asal = lebar_maks(isi), lebar_maks(isi_asal)
            if had_fail is not None:
                if w_baru > had_fail:
                    print(f"{tempat}: {w_baru}px > {had_fail}px (tingkap huraian): \"{isi}\"")
                    masalah += 1
            elif rel == "src/battle_message.c" and w_baru > had_dialog and w_baru > w_asal:
                print(f"{tempat}: {w_baru}px > {had_dialog}px: \"{isi}\"")
                masalah += 1
            elif w_baru > max(w_asal, 1) * 1.15 and w_baru - w_asal > 8:
                print(f"{tempat}: AMARAN lebih lebar dari asal {w_asal}px -> {w_baru}px: \"{isi}\"")
                amaran += 1
    return masalah, amaran


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("fail", nargs="*")
    ap.add_argument("--semua", action="store_true")
    ap.add_argument("--had", type=int, default=HAD_LALAI)
    a = ap.parse_args()
    fail = a.fail or []
    if a.semua:
        fail = sorted(str(p) for p in (ROOT / "data").rglob("*.inc"))
    jumlah = amaran = 0
    for f in fail:
        if f.endswith((".c", ".h")):
            m, w = semak_fail_c(f, a.had)
            jumlah += m
            amaran += w
        else:
            jumlah += semak_fail(f, a.had)
    if amaran:
        print(f"{amaran} amaran (semak sendiri, mungkin okey).")
    print(f"\n{len(fail)} fail disemak, {jumlah} masalah.")
    sys.exit(1 if jumlah else 0)


if __name__ == "__main__":
    main()
