# Arahan menterjemah dialog (.inc) — Pokémon Emerald → Bahasa Melayu

Projek: `D:\work folder\translate game gba\pokeemerald-melayu` (pokeemerald decomp).
Kerja kamu: terjemah SEMUA teks `.string "..."` dalam fail yang disenaraikan
dalam fail kumpulan kamu (`tools/kumpulan/NN-*.txt`). Edit fail itu SAHAJA.
Jangan build, jangan commit, jangan sentuh fail lain (orang lain sedang edit fail
lain secara serentak).

## Baca dulu
1. `GLOSARI.md` — istilah tetap, frasa, dan **Suara watak** (kata ganti ikut watak).
2. `SENARAI-NAMA.md` — nama Melayu setiap item, move, ability, sifat, jenis.
   Bila dialog sebut item/move/dsb, guna nama TEPAT dari senarai (HURUF BESAR
   seperti asal). Nama BALL, BERRY, TM/HM, nama Pokémon, watak dan tempat kekal.
3. Contoh siap: `data/maps/LittlerootTown/scripts.inc` (bahagian `_Text_`).

## Apa yang boleh diubah
- HANYA isi di dalam `.string "..."`. Label, arahan skrip, komen, `.braille`,
  `.byte`, dll. TIDAK diubah.
- Kamu boleh tambah/kurang bilangan baris `.string` dalam satu label untuk
  susun semula baris (contoh fail Littleroot).
- Rentetan yang bukan bahasa (kosong, `{...}` sahaja, nombor) dibiarkan.
- Sesetengah fail (contoh Littleroot) mungkin dah separa diterjemah — kekalkan
  yang dah Melayu, terjemah yang masih Inggeris.

## Format kotak dialog (WAJIB)
- Kod: `\n` = baris ke-2, `\l` = skrol satu baris, `\p` = kotak baru,
  `$` = tamat. Kotak hanya 2 baris: dalam satu perenggan (antara `\p`) guna `\n`
  SEKALI sahaja, kemudian `\l` untuk baris seterusnya, atau `\p` untuk kotak baru.
- Setiap baris maksimum 208 piksel (lebih kurang 34–38 aksara; huruf besar lebih
  lebar). Placeholder dianggarkan: `{PLAYER}`/`{RIVAL}` 42px, `{STR_VAR_n}` 60px.
- Semua kod `{...}` dan `$` mesti kekal sama (set yang sama setiap label).
  Kod seperti `{PAUSE 15}`, `{PLAY_SE ...}`, `{COLOR ...}` dikekalkan di tempat
  yang setara dalam ayat.
- Hanya aksara dalam `charmap.txt`: A–Z a–z 0–9, ruang, `. , ! ? - ' : / ( ) &`,
  `é`, `…`, `“ ”`, `‘ ’`. Tiada huruf beraksen lain.

## Gaya
- Bahasa Melayu Malaysia, santai tapi sopan, ikut **Suara watak** dalam glosari.
- Terjemah makna, bukan perkataan demi perkataan. Lawak dan pun boleh diadaptasi.
- Konsisten: watak yang sama mesti guna kata ganti yang sama dalam semua fail.

## Semak
Dari folder projek:
`python tools/semak_teks.py $(cat tools/kumpulan/NN-*.txt)`
Mesti tamat dengan `0 masalah`. Ia bandingkan dengan teks Inggeris (tag git
`asal`): lebar piksel, kod kawalan, label hilang, susunan baris kotak.

## Cara kerja yang disyorkan
Fail banyak. Guna skrip Python: untuk setiap fail, terjemah label demi label,
tulis semula `.string` (UTF-8, hujung baris LF), dan semak selepas setiap
beberapa fail. Simpan skrip kerja dalam folder scratchpad sendiri bernama ikut
kumpulan (contoh `scratchpad/k03/`) — scratchpad dikongsi dengan agen lain.

## Laporan
Akhiri dengan: baris akhir pemeriksa, bilangan fail/label diterjemah, istilah
baru yang kamu cipta (yang patut masuk GLOSARI.md), dan 10 contoh terjemahan.
