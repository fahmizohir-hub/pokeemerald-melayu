# Semakan gaya dialog (pusingan 2): buang bahasa "terjemahan mesin"

Projek: `D:\work folder\translate game gba\pokeemerald-melayu` (pokeemerald decomp,
terjemahan Bahasa Melayu). Semua dialog SUDAH diterjemah. Kerja kamu ialah
**membaca semula** dan membetulkan ayat yang bunyinya kaku, terlalu formal,
terjemahan kata demi kata, atau bunyi seperti ditulis AI. Matlamat: pemain
Malaysia baca dan rasa NPC bercakap macam orang biasa.

Edit fail dalam kumpulan kamu SAHAJA (`tools/kumpulan/NN-*.txt`). Agen lain
sedang edit fail lain serentak. Jangan build, jangan commit, jangan sentuh
fail lain (termasuk GLOSARI.md).

## Baca dulu
1. `GLOSARI.md` (terutama **Suara watak**, **Nama move (bentuk kata nama)**).
2. `SENARAI-NAMA.md` untuk nama item/move/ability yang tepat (HURUF BESAR).
3. `tools/kumpulan/ARAHAN.md` bahagian **Format kotak dialog** (peraturan
   `\n` `\l` `\p` `$`, 208px, kod `{...}` kekal).
4. Teks Inggeris asal untuk banding makna: `git show asal:<fail>`.

## Apa yang dibetulkan (contoh)
- Terlalu formal untuk cakap santai: "adalah", "merupakan", "telah" berulang,
  "untuk" yang tak perlu, "sedang" berlebihan, "ianya", "oleh itu", "walau
  bagaimanapun", "sebenarnya" sebagai pengisi.
  - "Ini adalah POKéMON yang sangat kuat." → "POKéMON ni kuat betul."
  - "Saya telah menunggu kamu." → "Saya dah tunggu kamu."
- Struktur Inggeris: "di mana" sebagai kata hubung relatif, "yang mana",
  pasif berat "telah ... oleh", "Ia adalah...", "Adakah kamu...?" berulang
  (cakap biasa: "Kamu ... ke?" / "Nak ...?"), "Dia" untuk benda.
- Gaya AI: frasa megah kosong ("pengalaman yang tidak dapat dilupakan"),
  binaan "Bukan sekadar X, malah Y", "Mari kita ...!" berulang, pembuka kosong
  ("Sudah tentu!", "Baiklah, jadi..."), tanda seru bertubi-tubi, sinonim yang
  ditukar-tukar tanpa sebab.
- Bentuk Indonesia (bisa, kalian, banget, nggak, sih, mengapa → kenapa jika
  santai, sabuk, dll.).
- Simpulan bahasa Inggeris yang diterjemah terus. Guna padanan Melayu yang
  biasa, atau ayat biasa.

## Apa yang JANGAN diubah
- Makna, maklumat permainan dan fakta mesti sama dengan Inggeris asal.
- Jangan ubah baris yang sudah sedap dibaca. Pembetulan kecil lebih baik dari
  tulis semula. Bukan semua "adalah"/"telah" salah; tukar hanya bila janggal.
- Suara watak kekal (kata ganti ikut glosari: contoh ibu "Ibu/sayang", Team
  Aqua/Magma "kami/kau" ikut yang sedia ada dalam fail).
- Nama khas, nama POKéMON, nama tempat, nama item/move/ability (ikut
  SENARAI-NAMA), huruf besar seperti asal.
- Label, arahan skrip, `.byte`, `.braille`, komen; hanya isi `.string "..."`.
- Kod `{...}` dan `$` mesti kekal (set sama dalam setiap label).
- Kata ganti "kamu" untuk pemain (bukan "anda"), kecuali watak yang memang
  guna "kau" atau "anda" dalam fail sedia ada (pekerja kaunter rasmi boleh kekal).

## Format
- Kotak 2 baris; setiap baris maksimum 208px. Bila ayat jadi lebih panjang,
  balut semula baris (`\n` sekali dalam satu perenggan, kemudian `\l`, atau `\p`).
- UTF-8, hujung baris LF. Simpan skrip kerja dalam scratchpad kamu sendiri
  (subfolder ikut kumpulan, contoh `scratchpad/g03/`).

## Semak (wajib sebelum lapor)
    python tools/semak_teks.py $(cat tools/kumpulan/NN-*.txt)
Mesti tamat dengan `0 masalah` (amaran boleh diabaikan). Juga jalankan
    python tools/imbas_gaya.py
dan pastikan tiada kemunculan baru dalam fail kamu.

## Laporan (ringkas)
Baris akhir pemeriksa, bilangan label diubah setiap fail (anggaran), corak
utama yang dibetulkan, dan 8 contoh "sebelum → selepas". Sebut juga baris yang
kamu ragu dan tidak ubah.
