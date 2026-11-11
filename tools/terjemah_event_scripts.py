#!/usr/bin/env python3
"""Terjemah teks .string dalam data/event_scripts.s (bukan .inc, jadi di luar kumpulan).

Guna:  python tools/terjemah_event_scripts.py
Sentiasa mula dari teks Inggeris (tag `asal`) dan tulis semula label yang disenaraikan.
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from semak_teks import ROOT, versi_asal  # noqa: E402

FAIL = ROOT / "data/event_scripts.s"

MS = {
    "gText_PokemartSign": [
        "“Barang pilihan untuk kemudahan anda!”\\n",
        "POKé MART$",
    ],
    "gText_PokemonCenterSign": [
        "“Pulihkan rakan anda yang keletihan!”\\n",
        "PUSAT POKéMON$",
    ],
    "gText_MomOrDadMightLikeThisProgram": [
        "{STR_VAR_1} mungkin suka rancangan ni.\\n",
        "… … … … … … … … … … … … … … … …\\p",
        "Baik aku gerak sekarang!$",
    ],
    "gText_WhichFloorWouldYouLike": [
        "Selamat datang ke PASAR RAYA LILYCOVE.\\p",
        "Anda mahu ke tingkat mana?$",
    ],
    "gText_SandstormIsVicious": [
        "Ribut pasir ini sangat ganas.\\n",
        "Mustahil untuk terus mara.$",
    ],
    "gText_SelectWithoutRegisteredItem": [
        "Barang dalam BEG boleh didaftarkan\\n",
        "pada SELECT supaya mudah diguna.$",
    ],
    "gText_PokemonTrainerSchoolEmail": [
        "Ada e-mel daripada SEKOLAH\\n",
        "JURULATIH POKéMON.\\p",
        "… … … … … …\\p",
        "POKéMON boleh belajar sehingga\\n",
        "empat move.\\p",
        "Kepakaran JURULATIH diuji melalui\\n",
        "set move yang dipilih untuk POKéMON.\\p",
        "… … … … … …$",
    ],
    "gText_PlayerHouseBootPC": [
        "{PLAYER} menghidupkan PC.$",
    ],
    "gText_PokeblockLinkCanceled": [
        "Link telah dibatalkan.$",
    ],
    "gText_UnusedNicknameReceivedPokemon": [
        "Nak beri nama timangan kepada\\n",
        "{STR_VAR_2} yang kamu terima?$",
    ],
    "gText_PlayerWhitedOut": [
        "{PLAYER} dah kehabisan POKéMON\\n",
        "yang boleh bertarung!\\p",
        "{PLAYER} pitam!$",
    ],
    "gText_RegisteredTrainerinPokeNav": [
        "{STR_VAR_1} {STR_VAR_2}\\n",
        "didaftarkan dalam POKéNAV.$",
    ],
    "gText_ComeBackWithSecretPower": [
        "Kamu tahu TM KUASA RAHSIA?\\p",
        "Kumpulan kami sangat suka\\n",
        "TM KUASA RAHSIA.\\p",
        "Salah seorang ahli kami akan\\n",
        "berikannya kepada kamu.\\l",
        "Datang balik dan tunjuk kalau dapat.\\p",
        "Kami akan terima kamu sebagai ahli\\n",
        "dan jual barang bagus secara rahsia.$",
    ],
    "gText_PokerusExplanation": [
        "POKéMON kamu mungkin dijangkiti\\n",
        "POKéRUS.\\p",
        "Tak banyak yang diketahui tentang\\n",
        "POKéRUS, kecuali ia hidupan mikro\\l",
        "yang melekat pada POKéMON.\\p",
        "Semasa dijangkiti, POKéMON dikatakan\\n",
        "membesar dengan sangat baik.$",
    ],
    "gText_DoorOpenedFarAway": [
        "Kedengaran seperti ada pintu\\n",
        "terbuka di tempat yang jauh.$",
    ],
    "gText_BigHoleInTheWall": [
        "Ada lubang besar di dinding.$",
    ],
    "gText_SorryWirelessClubAdjustments": [
        "Saya mohon maaf.\\n",
        "KELAB WAYARLES POKéMON sedang\\l",
        "dalam penyelenggaraan.$",
    ],
    "gText_UndergoingAdjustments": [
        "Nampaknya ia sedang dalam\\n",
        "penyelenggaraan…$",
    ],
    "gText_SorryTradeCenterInspections": [
        "Saya mohon maaf. PUSAT TUKARAN\\n",
        "sedang diperiksa.$",
    ],
    "gText_SorryRecordCornerPreparation": [
        "Saya mohon maaf. SUDUT REKOD\\n",
        "sedang disediakan.$",
    ],
    "gText_PlayerHandedOverTheItem": [
        "{PLAYER} menyerahkan\\n",
        "{STR_VAR_1}.$",
    ],
    "gText_ThankYouForAccessingMysteryGift": [
        "Terima kasih kerana menggunakan\\n",
        "Sistem HADIAH MISTERI.$",
    ],
    "gText_PlayerFoundOneTMHM": [
        "{PLAYER} menjumpai satu {STR_VAR_1}\\n",
        "{STR_VAR_2}!$",
    ],
    "gText_Sudowoodo_Attacked": [
        "Pokok pelik ini tak suka\\n",
        "BALDI WAILMER!\\p",
        "Pokok pelik itu menyerang!$",
    ],
    "gText_LegendaryFlewAway": [
        "{STR_VAR_1} itu terbang pergi!$",
    ],
}

RE_LABEL = re.compile(r"^(\w+)::?\s*$")
RE_STRING = re.compile(r'^\s*\.string\s+"')


def main():
    baris = versi_asal(FAIL).split("\n")
    hasil, i, siap = [], 0, set()
    while i < len(baris):
        b = baris[i]
        hasil.append(b)
        i += 1
        m = RE_LABEL.match(b)
        if not m or m.group(1) not in MS:
            continue
        while i < len(baris) and RE_STRING.match(baris[i]):
            i += 1
        hasil += [f'\t.string "{s}"' for s in MS[m.group(1)]]
        siap.add(m.group(1))
    hilang = set(MS) - siap
    if hilang:
        sys.exit(f"Label tak dijumpai: {hilang}")
    FAIL.write_text("\n".join(hasil), encoding="utf-8", newline="\n")
    print(f"{len(siap)} label diterjemah dalam {FAIL.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
