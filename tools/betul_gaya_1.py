#!/usr/bin/env python3
"""Pembetulan gaya pusingan 1 (skill no-ai-slop): buang 'di mana' literal,
kata formal dalam dialog santai, dan pasif berat. Perubahan minimum."""
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

GANTI = [
    ("data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc",
     '\t.string "Misi Tarung ialah acara pertarungan\\n"\n'
     '\t.string "di mana kamu mesti meneroka\\l"\n'
     '\t.string "PYRAMID dan cuba sampai ke puncak.\\p"',
     '\t.string "Dalam Misi Tarung, kamu mesti\\n"\n'
     '\t.string "meneroka PYRAMID dan cuba\\l"\n'
     '\t.string "sampai ke puncak.\\p"'),
    ("data/maps/BattleFrontier_BattleTowerLobby/scripts.inc",
     '\t.string "SALUN TARUNG di mana kamu boleh\\l"',
     '\t.string "SALUN TARUNG, tempat kamu boleh\\l"'),
    ("data/maps/BattleFrontier_ScottsHouse/scripts.inc",
     '\t.string "Saya suka kemurnian pertarungan,\\n"\n'
     '\t.string "di mana semua orang setaraf.\\p"',
     '\t.string "Saya suka pertarungan yang adil,\\n"\n'
     '\t.string "bila semua orang setaraf.\\p"'),
    ("data/maps/MtPyre_Summit/scripts.inc",
     '\t.string "Ini tempat tinggi di mana seseorang\\n"\n'
     '\t.string "boleh melihat seluruh HOENN…\\p"',
     '\t.string "Dari tempat tinggi ini, kita boleh\\n"\n'
     '\t.string "melihat seluruh HOENN…\\p"'),
    ("data/maps/SlateportCity_OceanicMuseum_1F/scripts.inc",
     '\t.string "“Batu dari gunung dihanyutkan oleh\\n"\n'
     '\t.string "sungai, di mana ia terhakis dan terkikis.\\p"',
     '\t.string "“Batu dari gunung dihanyutkan sungai\\n"\n'
     '\t.string "lalu terhakis dan terkikis.\\p"'),
    ("data/maps/SlateportCity_PokemonFanClub/scripts.inc",
     '\t.string "Ia acara di mana POKéMON boleh\\n"',
     '\t.string "Dalam acara ni, POKéMON boleh\\n"'),
    ("data/maps/SootopolisCity/scripts.inc",
     '\t.string "Pertembungan dua POKéMON yang\\n"\n'
     '\t.string "terjaga telah ditenangkan oleh\\l"\n'
     '\t.string "kebangkitan POKéMON ketiga…$"',
     '\t.string "Kebangkitan POKéMON ketiga telah\\n"\n'
     '\t.string "menenangkan pertembungan dua\\l"\n'
     '\t.string "POKéMON yang terjaga itu…$"'),
    ("data/text/match_call.inc",
     '\t.string "Walau bagaimanapun, saya gesa kamu\\n"',
     '\t.string "Apa pun, saya gesa kamu\\n"'),
]

for rel, lama, baru in GANTI:
    p = ROOT / rel
    t = p.read_text(encoding="utf-8")
    n = t.count(lama)
    if n != 1:
        print(f"LANGKAU {rel}: jumpa {n} kali")
        continue
    p.write_text(t.replace(lama, baru), encoding="utf-8", newline="\n")
    print(f"OK {rel}")
