#!/usr/bin/env python3
"""Kemas kini dialog yang menyebut nama move selepas tools/kata_nama_move.py.

Penggantian ditulis satu-satu (bukan cari-ganti buta) sebab ada perkataan
yang sama tapi bukan nama move (IKAT FOKUS, KELAB TIRU, PULIH ALAMI...).
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import semak_teks as st  # noqa: E402

# (fail, lama, baru, bilangan dijangka atau None = semua)
GANTI = [
    # PROTECT
    ("data/maps/BattleFrontier_BattleArenaLobby/scripts.inc",
     '\t.string "Mata Teknik tidak naik untuk\\n"\n\t.string "move seperti LINDUNG dan WASPADA.\\p"',
     '\t.string "Mata Teknik tidak naik untuk move\\n"\n\t.string "seperti PERLINDUNGAN dan WASPADA.\\p"', 1),
    ("data/maps/BattleFrontier_BattleArenaLobby/scripts.inc",
     '\t.string "Jika lawan guna LINDUNG atau\\n"',
     '\t.string "Jika lawan guna PERLINDUNGAN atau\\n"', 1),
    # SURF (guna kata nama; tambah "guna" bila asalnya kata kerja)
    ("data/text/trainers.inc", "yang tengah LUNCUR OMBAK?", "yang tengah guna LUNCUR OMBAK?", 1),
    ("data/text/trainers.inc", "pengsan pun masih boleh LUNCUR OMBAK,", "pengsan pun boleh guna LUNCUR OMBAK,", 1),
    ("src/strings.c", '_("Tak boleh LUNCUR OMBAK di sini.")', '_("Tak boleh guna LUNCUR OMBAK di sini.")', 1),
    ("src/strings.c", '_("Kamu sedang LUNCUR OMBAK.")', '_("Kamu sedang guna LUNCUR OMBAK.")', 1),
    # CUT
    ("src/strings.c", '_("Tiada apa untuk POTONG.")', '_("Tiada apa untuk dipotong.")', 1),
    ("data/maps/RustboroCity_PokemonCenter_1F/scripts.inc",
     '\t.string "Saya guna untuk ajar POKéMON saya\\n"\n\t.string "POTONG pokok-pokok kecil.$"',
     '\t.string "Saya guna untuk ajar POKéMON saya\\n"\n\t.string "POTONG. Boleh tebang pokok kecil!$"', 1),
    # SNATCH (baris 168 ialah gurauan kata kerja, kekal)
    ("data/maps/SSTidalRooms/scripts.inc", '"RAMPAS mencuri kesan baik move', '"RAMPASAN mencuri kesan baik move', 1),
    # BIND, SPIT UP
    ("src/battle_message.c", "dihimpit oleh\\nIKAT {B_ATK_NAME_WITH_PREFIX}!", "dihimpit oleh\\nIKATAN {B_ATK_NAME_WITH_PREFIX}!", 1),
    ("src/battle_message.c", "tidak dapat\\nLUAHKAN apa-apa!", "tidak dapat\\nmeluahkan apa-apa!", 1),
    # MIMIC, ROLLOUT, DYNAMICPUNCH (pengajar move)
    ("data/text/move_tutors.inc", "Saya boleh ajar move GOLEK\\n", "Saya boleh ajar move GOLEKAN\\n", 1),
    ("data/text/move_tutors.inc", "untuk ajar move TIRU?", "untuk ajar move TIRUAN?", 1),
    ("data/text/move_tutors.inc", "Saya nak ajar TIRU\\n", "Saya nak ajar TIRUAN\\n", 1),
    ("data/text/move_tutors.inc", '"TIRU ialah move', '"TIRUAN ialah move', 1),
    ("data/text/move_tutors.inc", "TINJUDINAMIK", "TUMBUKAN DINAMIK", 2),
    # lain-lain
    ("data/text/apprentice.inc", "TANGIS PALSU saya!", "TANGISAN PALSU saya!", 1),
    ("data/text/contest_strings.inc", '"TIKAM TANDUK$"', '"TIKAMAN TANDUK$"', 1),
    ("data/maps/LilycoveCity_ContestHall/scripts.inc", '"HISAP DARAH ZUBAT', '"HISAPAN DARAH ZUBAT', 1),
    ("data/scripts/mauville_man.inc", "PERCIK", "PERCIKAN", 3),
]

# Ganti terus semua kejadian (nama move sahaja dalam fail ini).
# v0.2.1: POTONG dan LUNCUR OMBAK dikekalkan (lihat GLOSARI), jadi kosong.
SEMUA = {}
FAIL_SEMUA = [
    "data/text/surf.inc", "data/text/trainers.inc",
    "data/maps/LilycoveCity_MoveDeletersHouse/scripts.inc", "data/maps/MauvilleCity/scripts.inc",
    "data/maps/MossdeepCity/scripts.inc", "data/maps/MossdeepCity_StevensHouse/scripts.inc",
    "data/maps/PacifidlogTown/scripts.inc", "data/maps/PetalburgCity_Gym/scripts.inc",
    "data/maps/Route118/scripts.inc", "src/data/decoration/description.h",
    "data/scripts/field_move_scripts.inc", "data/scripts/mauville_man.inc",
    "data/maps/Route110_TrickHousePuzzle1/scripts.inc", "data/maps/RustboroCity_CuttersHouse/scripts.inc",
    "data/maps/RustboroCity_Gym/scripts.inc", "data/maps/RustboroCity_PokemonSchool/scripts.inc",
]

# Senarai tukar BP (Battle Frontier): lajur nama 78px, fon biasa.
BP = {
    "HUMBAN GEMPA": "HUMBANAN GEMPA", "TINJU MEGA": "TUMBUKAN MEGA",
    "SEPAK MEGA": "SEPAKAN MEGA", "HEMPAS BADAN": "HEMPASAN BADAN",
    "PALIT LUMPUR": "PALITAN LUMPUR", "TINJU AIS": "TUMBUKAN AIS",
    "TINJU PETIR": "TUMBUKAN PETIR", "TINJU API": "TUMBUKAN API",
}


def main():
    fail = {}

    def baca(rel):
        if rel not in fail:
            fail[rel] = (ROOT / rel).read_text(encoding="utf-8")
        return fail[rel]

    ok = True
    for rel, lama, baru, n in GANTI:
        t = baca(rel)
        c = t.count(lama)
        if c == 0 or (n is not None and c != n):
            print(f"LANGKAU {rel}: '{lama[:40]}' jumpa {c}")
            ok = False
            continue
        fail[rel] = t.replace(lama, baru)

    for rel in FAIL_SEMUA:
        t = baca(rel)
        for lama, baru in SEMUA.items():
            t = re.sub(r"(?<![A-Z])" + re.escape(lama) + r"(?![A-Z])", baru, t)
        fail[rel] = t

    t = baca("src/strings.c")
    for lama, baru in BP.items():
        pola = f'_("{lama}{{CLEAR_TO 78}}'
        if pola not in t:
            print(f"LANGKAU BP {lama}")
            ok = False
            continue
        nama = baru
        if st.lebar_baris(baru) > 76:
            nama = "{FONT_NARROW}" + baru + "{FONT_NORMAL}"
        t = t.replace(pola, f'_("{nama}{{CLEAR_TO 78}}')
    fail["src/strings.c"] = t

    for rel, t in fail.items():
        (ROOT / rel).write_text(t, encoding="utf-8", newline="\n")
    print(f"{len(fail)} fail ditulis." + ("" if ok else " (ada LANGKAU)"))


if __name__ == "__main__":
    main()
