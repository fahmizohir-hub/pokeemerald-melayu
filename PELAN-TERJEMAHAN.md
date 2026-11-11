# Pokémon Emerald: Terjemahan Bahasa Melayu

Projek ni guna kod sumber `pret/pokeemerald`. Semua teks diedit terus dalam
fail sumber, kemudian ROM dibina semula.

## Saiz kerja

| Bahagian | Lokasi | Anggaran |
|---|---|---|
| Dialog peta (519 kawasan) | `data/maps/*/scripts.inc` | 15,800 baris |
| Teks umum (Pusat POKéMON, Mart, cerita) | `data/text/*.inc` | 11,300 baris |
| Skrip umum | `data/scripts/*.inc` | 1,500 baris |
| Menu dan sistem | `src/strings.c` | 1,760 string |
| Mesej pertarungan | `src/battle_message.c` | 540 string |
| Item (nama dan huraian) | `src/data/items.h`, `src/data/text/item_descriptions.h` | 377 item |
| Move (nama dan huraian) | `src/data/text/move_names.h`, `move_descriptions.h` | 355 move |
| Ability | `src/data/text/abilities.h` | 78 ability |
| Entri Pokédex | `src/data/pokemon/pokedex_entries.h` | 386 entri |
| Lain-lain (trainer, Match Call, Battle Frontier, kredit) | `src/data/...` | ~2,500 string |

Jumlah dialog: lebih kurang 843,000 aksara.

## Fasa

1. **Setup.** Pasang WSL dan toolchain, kemudian build ROM asal dan sahkan
   SHA1 `f3ae088181bf583e55daf962a92bb46f4f1d07b7`.
2. **Alat semakan.** Skrip Python untuk kira lebar piksel setiap baris
   (guna jadual lebar font game), semak had nama, dan pastikan kod kawalan
   (`{PLAYER}`, `\n`, `\p`, `\l`, `$`) tidak hilang.
3. **Menu dan sistem.** `strings.c`, mesej pertarungan, nama item, move dan
   ability. Fasa ni didahulukan supaya istilah terkunci sebelum dialog.
4. **Dialog cerita utama.** Ikut turutan permainan: Littleroot → Oldale →
   Petalburg → … → Ever Grande.
5. **Kandungan sampingan.** Pokédex, Battle Frontier, Contest, Match Call,
   Trainer Hill, kredit.
6. **Uji main.** Main dalam mGBA dan laporkan baris yang terpotong atau pelik.

## Had panjang (dalam aksara)

| Jenis | Had |
|---|---|
| Nama item | 13 |
| Nama move | 16 (78px fon sempit) |
| Nama ability | 12 |
| Nama Pokémon (tidak ditukar) | 10 |
| Baris dialog | lebih kurang 36–38 (ikut lebar piksel, bukan bilangan huruf) |

## Gaya bahasa

- NPC bercakap santai, guna "kamu" untuk pemain dan "saya" untuk diri sendiri.
- Ibu panggil pemain "sayang".
- Huruf besar dikekalkan untuk nama khas, ikut gaya asal game
  (contoh: `KASUT LARI`, `MAKMAL`).
- Nama Pokémon, nama watak dan nama tempat dikekalkan. Hanya jenis tempat
  diterjemah (`LITTLEROOT TOWN` → `PEKAN LITTLEROOT`).

## Glosari

Lihat [GLOSARI.md](GLOSARI.md). Itu satu-satunya sumber istilah.

## Status

- [x] Fasa 1: setup, ROM asal disahkan (SHA1 sepadan)
- [x] Fasa 2: alat semakan dalam `tools/`
- [x] Fasa 3: nama dan huraian move/item/ability/sifat/jenis, menu, mesej pertarungan
- [x] Fasa 4: semua dialog (.inc + data/event_scripts.s), nama tempat
- [x] Skrin tajuk: TEKAN START + kredit me2suzuran
- [x] Fasa 5: kelas jurulatih, hiasan (nama + huraian), berry, Pokedex (kategori +
      penerangan), Match Call, Union Room, tajuk kredit, Easy Chat (+ senarai abjad
      `tools/jana_easy_chat_abjad.py`), reben, landmark PokeNav, PKLN. (secret_base.c)
- [ ] Semakan gaya (skill no-ai-slop)
- [x] Grafik: ikon jenis + kategori contest (`tools/jana_ikon_jenis.py`)
- [x] Grafik: label skrin ringkasan (`tools/jana_label_ringkasan.py`)
- [x] Grafik: ikon status menu + pertarungan (`tools/jana_ikon_status.py`)
- [x] Grafik: Pokedex (`tools/jana_grafik_pokedex.py`) dan PokeNav
      (`tools/jana_grafik_pokenav.py`)
- [x] Grafik kecil lain: kad jurulatih, Frontier Pass, papan kekunci nama, PC,
      beg, Easy Chat, Union Room, contest, mesin slot, rolet, Pokeblock, Pokemon
      Jump (`tools/jana_grafik_lain_a.py`, `tools/jana_grafik_lain_b.py`)
- [x] Nama move dalam bentuk kata nama (`tools/kata_nama_move.py`); had nama move
      16 aksara, menu move pertarungan 80px + ikon jenis (`tools/jana_menu_move.py`)
- [ ] Kekal Inggeris (had ruang): paparan titik mesin slot (REEL TIME, WIN, LOSE,
      BIG/REG BONUS), notis hak cipta penamat
- [ ] Fasa 6: uji main
