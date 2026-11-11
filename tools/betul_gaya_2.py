#!/usr/bin/env python3
"""Pembetulan gaya pusingan 2: 'simpan kemajuan' (terjemahan terus 'save
progress') -> 'simpan permainan', ikut maklum balas uji main."""
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

GANTI = [
    ("data/maps/OldaleTown/scripts.inc",
     '\t.string "Saya nak berehat, jadi saya\\n"\n'
     '\t.string "simpan kemajuan saya dulu.$"',
     '\t.string "Saya nak rehat sekejap,\\n"\n'
     '\t.string "jadi saya simpan permainan dulu.$"', 1),
    ("data/maps/MossdeepCity_GameCorner_1F/scripts.inc",
     '\t.string "patut simpan kemajuan kamu.$"',
     '\t.string "patut simpan permainan dulu.$"', 1),
    ("data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.inc",
     '\t.string "Sebelum kamu berdua bertarung, simpan\\n"\n'
     '\t.string "dulu kemajuan kamu.$"',
     '\t.string "Sebelum kamu berdua bertarung,\\n"\n'
     '\t.string "simpan permainan dulu.$"', 1),
    ("data/maps/BattleFrontier_BattleTowerLobby/scripts.inc",
     '\t.string "Sebelum masuk BILIK TARUNG, kemajuan\\n"\n'
     '\t.string "kamu akan disimpan. Sila tunggu.$"',
     '\t.string "Sebelum masuk BILIK TARUNG,\\n"\n'
     '\t.string "permainan kamu akan disimpan.\\l"\n'
     '\t.string "Sila tunggu.$"', 1),
    ("data/maps/BattleFrontier_BattleTowerLobby/scripts.inc",
     '\t.string "Sebelum masuk BILIK TARUNG, kemajuan\\n"\n'
     '\t.string "kamu mesti disimpan. Boleh?$"',
     '\t.string "Sebelum masuk BILIK TARUNG,\\n"\n'
     '\t.string "permainan kamu mesti disimpan.\\l"\n'
     '\t.string "Boleh?$"', 1),
    ("data/scripts/contest_hall.inc",
     '\t.string "Sebelum masuk PERTANDINGAN, kemajuan\\n"\n'
     '\t.string "kamu akan disimpan.$"',
     '\t.string "Sebelum masuk PERTANDINGAN,\\n"\n'
     '\t.string "permainan kamu akan disimpan.$"', 1),
    ("data/maps/LittlerootTown_BrendansHouse_2F/scripts.inc",
     '\t.string "Rekod kemajuan dengan SIMPAN.\\p"',
     '\t.string "Simpan permainan guna SIMPAN.\\p"', None),
]

for rel, lama, baru, jangka in GANTI:
    p = ROOT / rel
    t = p.read_text(encoding="utf-8")
    n = t.count(lama)
    if n == 0 or (jangka is not None and n != jangka):
        print(f"LANGKAU {rel}: jumpa {n} kali")
        continue
    p.write_text(t.replace(lama, baru), encoding="utf-8", newline="\n")
    print(f"OK {rel} ({n}x)")
