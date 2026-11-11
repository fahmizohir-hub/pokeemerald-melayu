#!/usr/bin/env python3
"""Terjemah nama tempat dalam src/data/region_map/region_map_sections.json.

Nama ni keluar dalam pop-up nama tempat (FONT_NARROW, 80px), peta wilayah /
peta FLY (FONT_NORMAL, ~96px) dan lokasi "ditemui di" dalam ringkasan POKéMON.
Had buffer: MAP_NAME_LENGTH = 16 aksara.

Guna:  python tools/terjemah_nama_tempat.py          (semak sahaja)
       python tools/terjemah_nama_tempat.py --tulis  (tulis ke JSON)
"""
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from semak_teks import CHARMAP, ROOT, lebar_baris, versi_asal  # noqa: E402

FAIL = ROOT / "src/data/region_map/region_map_sections.json"

KHAS = {
    "ABANDONED SHIP": "KAPAL TERBIAR",
    "ALTERING CAVE": "GUA BERUBAH",
    "ANCIENT TOMB": "MAKAM PURBA",
    "AQUA HIDEOUT": "MARKAS AQUA",
    "{AQUA} HIDEOUT": "MARKAS {AQUA}",
    "MAGMA HIDEOUT": "MARKAS MAGMA",
    "ROCKET HIDEOUT": "MARKAS ROCKET",
    "ROCKET WAREHOUSE": "GUDANG ROCKET",
    "ARTISAN CAVE": "GUA TUKANG",
    "BERRY FOREST": "HUTAN BERRY",
    "BOND BRIDGE": "JAMBATAN IKATAN",
    "CANYON ENTRANCE": "PINTU NGARAI",
    "CAPE BRINK": "TANJUNG BRINK",
    "CAVE OF ORIGIN": "GUA ORIGIN",
    "DESERT RUINS": "RUNTUHAN GURUN",
    "DESERT UNDERPASS": "TEROWONG GURUN",
    "DOTTED HOLE": "LUBANG BERBINTIK",
    "EMBER SPA": "SPA EMBER",
    "EVER GRANDE CITY": "BDR EVER GRANDE",
    "SOOTOPOLIS CITY": "BDR SOOTOPOLIS",
    "FIERY PATH": "LALUAN BERAPI",
    "FIVE ISLE MEADOW": "PADANG PULAU 5",
    "GREEN PATH": "LALUAN HIJAU",
    "ICEFALL CAVE": "GUA AIS TERJUN",
    "INDIGO PLATEAU": "DATARAN INDIGO",
    "INSIDE OF TRUCK": "DALAM LORI",
    "JAGGED PASS": "DENAI BERGERIGI",
    "KINDLE ROAD": "JALAN KINDLE",
    "LOST CAVE": "GUA SESAT",
    "MARINE CAVE": "GUA MARIN",
    "MEMORIAL PILLAR": "TUGU PERINGATAN",
    "METEOR FALLS": "LATA METEOR",
    "MIRAGE ISLAND": "PULAU ILUSI",
    "MIRAGE TOWER": "MENARA ILUSI",
    "NEW MAUVILLE": "MAUVILLE BARU",
    "OUTCAST ISLAND": "PULAU TERBUANG",
    "PATTERN BUSH": "SEMAK BERCORAK",
    "PETALBURG WOODS": "HUTAN PETALBURG",
    "POKéMON LEAGUE": "LIGA POKéMON",
    "POKéMON MANSION": "RUMAH POKéMON",
    "POKéMON TOWER": "MENARA POKéMON",
    "POWER PLANT": "STESEN JANAKUASA",
    "RESORT GORGEOUS": "PERANGINAN MEWAH",
    "ROCK TUNNEL": "TEROWONG BATU",
    "RUIN VALLEY": "LEMBAH RUNTUHAN",
    "SAFARI ZONE": "ZON SAFARI",
    "SCORCHED SLAB": "BATU HANGUS",
    "SEAFLOOR CAVERN": "GUA DASAR LAUT",
    "SEAFOAM ISLANDS": "KEP. SEAFOAM",
    "SEALED CHAMBER": "BILIK TERMETERAI",
    "SECRET BASE": "PANGKALAN RAHSIA",
    "SEVAULT CANYON": "NGARAI SEVAULT",
    "SKY PILLAR": "TIANG LANGIT",
    "SPECIAL AREA": "KAWASAN KHAS",
    "TANOBY CHAMBERS": "BILIK TANOBY",
    "TANOBY KEY": "KUNCI TANOBY",
    "TANOBY RUINS": "RUNTUHAN TANOBY",
    "TERRA CAVE": "GUA TERRA",
    "THREE ISLE PATH": "LALUAN PULAU 3",
    "THREE ISLE PORT": "PELABUHAN PLU 3",
    "TRAINER HILL": "BUKIT JURULATIH",
    "TRAINER TOWER": "MENARA JURULATIH",
    "TREASURE BEACH": "PANTAI HARTA",
    "UNDERGROUND PATH": "LALUAN BAWAH",
    "UNDERWATER": "BAWAH AIR",
    "VICTORY ROAD": "JALAN KEMENANGAN",
    "VIRIDIAN FOREST": "HUTAN VIRIDIAN",
    "WATER LABYRINTH": "LABIRIN AIR",
    "WATER PATH": "LALUAN AIR",
}

# Nama khas yang kekal
KEKAL = {"BATTLE FRONTIER", "NAVEL ROCK", "S.S. ANNE", "SILPH CO.", ""}

NOMBOR = {"ONE": "1", "TWO": "2", "THREE": "3", "FOUR": "4", "FIVE": "5",
          "SIX": "6", "SEVEN": "7"}


def terjemah(n):
    if n in KEKAL:
        return n
    if n in KHAS:
        return KHAS[n]
    m = re.fullmatch(r"ROUTE (\d+)", n)
    if m:
        return f"LALUAN {m.group(1)}"
    m = re.fullmatch(r"(.+) TOWN", n)
    if m:
        return f"PEKAN {m.group(1)}"
    m = re.fullmatch(r"(.+) CITY", n)
    if m:
        return f"BANDAR {m.group(1)}"
    m = re.fullmatch(r"(ONE|TWO|THREE|FOUR|FIVE|SIX|SEVEN) ISLAND", n)
    if m:
        return f"PULAU {NOMBOR[m.group(1)]}"
    m = re.fullmatch(r"(.+) ISLAND", n)
    if m:
        return f"PULAU {m.group(1)}"
    m = re.fullmatch(r"SEVII ISLE (\d+)", n)
    if m:
        return f"PULAU SEVII {m.group(1)}"
    m = re.fullmatch(r"(.+) CAVE", n)
    if m:
        return f"GUA {m.group(1)}"
    m = re.fullmatch(r"(.+) CHAMBER", n)
    if m:
        return f"BILIK {m.group(1)}"
    m = re.fullmatch(r"MT\. (.+)", n)
    if m:
        return f"GUNUNG {m.group(1)}"
    m = re.fullmatch(r"(.+) TUNNEL", n)
    if m:
        return f"TEROWONG {m.group(1)}"
    m = re.fullmatch(r"(.+)'S CAVE", n)
    if m:
        return f"GUA {m.group(1)}"
    return None


def lebar_sempit(s):
    teks = (ROOT / "src/fonts.c").read_text(encoding="utf-8")
    m = re.search(r"gFontNarrowLatinGlyphWidths\[\]\s*=\s*\{(.*?)\};", teks, re.S)
    jadual = [int(x) for x in re.findall(r"\d+", m.group(1))]
    s = re.sub(r"\{[^}]*\}", "AQUA", s)
    return sum(jadual[b] for c in s for b in CHARMAP[c])


def main():
    tulis = "--tulis" in sys.argv
    data = json.loads(versi_asal(FAIL))  # sentiasa mula dari teks Inggeris
    salah = 0
    for sec in data["map_sections"]:
        if "name" not in sec:
            continue
        asal = sec["name"]
        baru = terjemah(asal)
        if baru is None:
            print(f"TIADA TERJEMAHAN: {asal}")
            salah += 1
            continue
        n_bait = len(re.sub(r"\{[^}]*\}", "X", baru))
        w_normal = lebar_baris(re.sub(r"\{[^}]*\}", "AQUA", baru))
        w_sempit = lebar_sempit(baru)
        if n_bait > 16 or w_normal > 96 or w_sempit > 80:
            print(f"TERLALU PANJANG: {asal} -> {baru} ({n_bait} aksara, {w_normal}px, sempit {w_sempit}px)")
            salah += 1
        sec["name"] = baru
    if salah:
        print(f"{salah} masalah")
        sys.exit(1)
    if tulis:
        FAIL.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n",
                        encoding="utf-8", newline="\n")
        print("Ditulis.")
    else:
        print("Semua OK (guna --tulis untuk simpan).")


if __name__ == "__main__":
    main()
