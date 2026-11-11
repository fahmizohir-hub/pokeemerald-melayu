#!/usr/bin/env python3
"""Tukar nama move daripada kata kerja kepada kata nama (pusingan 1).

    python tools/kata_nama_move.py --semak   # ukur lebar + cari dialog
    python tools/kata_nama_move.py           # tulis move_names.h + dialog

Had lebar (fon sempit): menu pertarungan 80px, pengajar move 72px,
contest 70px. Lihat juga tools/jana_menu_move.py.
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import semak_teks as st  # noqa: E402

# nama BM lama -> nama BM baru
# HM kekal: POTONG (CUT), LUNCUR OMBAK (SURF, memang kata nama sukan),
# TERBANG, SELAM. POTONGAN/LUNCURAN OMBAK dikembalikan dalam v0.2.1.
TUKAR = {
    # satu perkataan
    "PUKUL": "PUKULAN", "CAKAR": "CAKARAN", "IKAT": "IKATAN",
    "HEMPAS": "HEMPASAN", "PIJAK": "PIJAKAN", "TERJAH": "TERJAHAN", "BELIT": "BELITAN",
    "REMPUH": "REMPUHAN", "AMUK": "AMUKAN", "JELING": "JELINGAN", "GIGIT": "GIGITAN",
    "NYANYI": "NYANYIAN", "SEKAT": "SEKATAN", "PATUK": "PATUKAN", "SERAP": "SERAPAN",
    "TIRU": "TIRUAN", "PULIH": "PEMULIHAN", "JILAT": "JILATAN", "KEPIT": "KEPITAN",
    "JERUT": "JERUTAN", "PERCIK": "PERCIKAN", "TEBAS": "TEBASAN", "LAKAR": "LAKARAN",
    "GOLEK": "GOLEKAN", "TIMBUN": "TIMBUNAN", "LUAHKAN": "LUAHAN", "BODEK": "BODEKAN",
    "RAMPAS": "RAMPASAN", "SERGAH": "SERGAHAN", "HALANG": "HALANGAN", "LOLONG": "LOLONGAN",
    "LANTUN": "LANTUNAN", "GELETEK": "GELETEKAN", "LINDUNG": "PERLINDUNGAN",
    # dua perkataan
    "SEPAK MEGA": "SEPAKAN MEGA", "SEPAK TIGA": "SEPAKAN TIGA", "KIBAS EKOR": "KIBASAN EKOR",
    "SERAP MEGA": "SERAPAN MEGA", "BACA MINDA": "BACAAN MINDA", "PUTAR LAJU": "PUTARAN LAJU",
    "TETAK KARATE": "TETAKAN KARATE", "TETAK SILANG": "TETAKAN SILANG",
    "TAMPAR GANDA": "TAMPARAN GANDA", "SEPAK GANDA": "SEPAKAN GANDA",
    "SEPAK LOMPAT": "SEPAKAN LOMPAT", "SEPAK GULING": "SEPAKAN GULING",
    "SEPAK RENDAH": "SEPAKAN RENDAH", "SEPAK TINGGI": "SEPAKAN TINGGI",
    "SERANG SAYAP": "SERANGAN SAYAP", "SERANG PASIR": "SERANGAN PASIR",
    "SERANG UDARA": "SERANGAN UDARA", "SERANG LAJU": "SERANGAN LAJU",
    "SERANG TIGA": "SERANGAN TIGA", "TIKAM TANDUK": "TIKAMAN TANDUK",
    "TUJAH BERANG": "TUJAHAN BERANG", "SEBAT SULUR": "SEBATAN SULUR",
    "PATUK GERUDI": "PATUKAN GERUDI",
    "BALING BATU": "BALINGAN BATU", "HANTUK DAHI": "HANTUKAN DAHI",
    "CANTAS PALSU": "CANTASAN PALSU", "LONTAR JITU": "LONTARAN JITU",
    "TEPUK KEJUT": "TEPUKAN KEJUT", "KETUK JATUH": "KETUKAN JATUH",
    "TOLAK LENGAN": "TOLAKAN LENGAN", "TANGIS PALSU": "TANGISAN PALSU",
    "SIUL RUMPUT": "SIULAN RUMPUT", "SERBU TULANG": "SERBUAN TULANG",
    "HUMBAN GEMPA": "HUMBANAN GEMPA", "GIGIT REMUK": "GIGITAN REMUK",
    "LAJU EKSTREM": "KELAJUAN EKSTREM",
    # TINJU -> TUMBUKAN
    "TINJU KOMET": "TUMBUKAN KOMET", "TINJU MEGA": "TUMBUKAN MEGA",
    "TINJU API": "TUMBUKAN API", "TINJU AIS": "TUMBUKAN AIS",
    "TINJU PETIR": "TUMBUKAN PETIR", "TINJU PENING": "TUMBUKAN PENING",
    "TINJU MACH": "TUMBUKAN MACH", "TINJUDINAMIK": "TUMBUKAN DINAMIK",
    "TINJU FOKUS": "TUMBUKAN FOKUS", "TINJU METEOR": "TUMBUKAN METEOR",
    "TINJU BAYANG": "TUMBUKAN BAYANG",
    # kata kerja lain yang jelas
    "HEMPAS BADAN": "HEMPASAN BADAN", "SEMBUR API": "SEMBURAN API",
    "PUSAR API": "PUSARAN API", "KEJUT PETIR": "KEJUTAN PETIR",
    "PALIT LUMPUR": "PALITAN LUMPUR", "RENUNG JAHAT": "RENUNGAN JAHAT",
    "PANDANG JAUH": "PANDANGAN JAUH", "SAUK LANGIT": "SAUKAN LANGIT",
    "HISAP DARAH": "HISAPAN DARAH",
}

FAIL_NAMA = ROOT / "src/data/text/move_names.h"
src_font = (ROOT / "src/fonts.c").read_text(encoding="utf-8")
m = re.search(r"gFontNarrowLatinGlyphWidths\[\]\s*=\s*\{(.*?)\};", src_font, re.S)
SEMPIT = [int(x) for x in re.findall(r"\d+", m.group(1))]


def lebar_sempit(s):
    return sum(SEMPIT[st.CHARMAP[c][0]] for c in s)


def fail_dialog():
    for pola in ("data/**/*.inc", "data/*.s", "src/*.c", "src/data/**/*.h"):
        for p in ROOT.glob(pola):
            if p.name in ("move_names.h",):
                continue
            yield p


def corak(lama):
    # nama move dalam dialog ditulis huruf besar; elak padanan sebahagian perkataan
    return re.compile(r"(?<![A-Z\u00c0-\u00ff])" + re.escape(lama) + r"(?![A-Z\u00c0-\u00ff])")


def main():
    semak = "--semak" in sys.argv
    teks = FAIL_NAMA.read_text(encoding="utf-8")
    ada = set(re.findall(r'_\("([^"]*)"\)', teks))
    masalah = 0
    for lama, baru in TUKAR.items():
        if lama not in ada:
            print(f"TIADA dalam move_names.h: {lama}")
            masalah += 1
        w = lebar_sempit(baru)
        if len(baru) > 16 or w > 78:
            print(f"TERLALU PANJANG: {baru} ({len(baru)} huruf, {w}px)")
            masalah += 1
        elif w > 70:
            print(f"amaran: {baru} {w}px > 70px (contest/pengajar move guna fon sempit)")
    # dialog yang menyebut nama lama
    jumpa = {}
    for p in fail_dialog():
        t = p.read_text(encoding="utf-8", errors="ignore")
        for lama in TUKAR:
            n = len(corak(lama).findall(t))
            if n:
                jumpa.setdefault(lama, []).append((p.relative_to(ROOT).as_posix(), n))
    for lama, senarai in sorted(jumpa.items()):
        print(f"dialog {lama}: " + ", ".join(f"{f}({n})" for f, n in senarai))
    if semak:
        return
    if masalah:
        sys.exit("Betulkan masalah dulu.")
    for lama, baru in TUKAR.items():
        teks = teks.replace(f'_("{lama}")', f'_("{baru}")')
    FAIL_NAMA.write_text(teks, encoding="utf-8", newline="\n")
    print("move_names.h ditulis.")


if __name__ == "__main__":
    main()
