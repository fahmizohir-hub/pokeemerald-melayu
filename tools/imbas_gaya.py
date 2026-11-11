#!/usr/bin/env python3
"""Imbas teks terjemahan untuk corak "AI slop" dan bahasa terjemahan (Detect).

Berdasarkan skill no-ai-slop (bahagian Bahasa Melayu) + tanda terjemahan
literal dari Bahasa Inggeris.

Guna:  python tools/imbas_gaya.py [--contoh N] [--csv FAIL]
"""
import argparse
import collections
import csv
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from semak_teks import ROOT, hurai_inc, string_c  # noqa: E402

CORAK = [
    # (kod, keterangan, regex, abaikan-huruf-besar?)
    ("formal", "kata formal dalam ayat santai",
     r"\b(sesungguhnya|justeru|oleh yang demikian|di samping itu|walau bagaimanapun|namun demikian|tambahan pula|seterusnya,)\b"),
    ("puffery", "frasa megah kosong",
     r"\b(memainkan peranan|amat penting|satu langkah besar|mencipta sejarah|merevolusikan|landskap|lembaran baru|tidak dapat dinafikan)\b"),
    ("pembuka", "pembuka kosong",
     r"\b(dalam era|dalam dunia yang|tahukah anda|jom kita selami|mari kita lihat)\b"),
    ("rumusan", "penutup rumusan",
     r"\b(kesimpulannya|secara keseluruhannya|akhir kata)\b"),
    ("bukan-sekadar", "kontras binari",
     r"\bbukan (sahaja|sekadar)\b.*\b(tetapi|malah)\b"),
    ("ianya", "'ianya' (tak baku)", r"\bianya\b"),
    ("adalah+sifat", "'adalah' sebelum kata sifat/keterangan",
     r"\badalah (sangat|amat|terlalu|begitu|agak|lebih|paling|sungguh|tidak|tak|di|dalam|untuk)\b"),
    ("di-mana", "'di mana' sebagai 'where/which' (bukan soalan)",
     r"[a-z,] di mana (?!-)(?=[a-z])"),
    ("yang-mana", "'yang mana' sebagai penghubung", r"[a-z,] yang mana [a-z]"),
    ("ia-adalah", "'Ia adalah' terjemahan literal 'It is'", r"\b[Ii]a adalah\b"),
    ("telah-oleh", "pasif berat 'telah ... oleh'", r"\btelah di\w+ oleh\b"),
    ("sebuah", "penjodoh 'sebuah' untuk benda abstrak",
     r"\bsebuah (idea|masalah|keputusan|perasaan|rahsia|impian|cabaran|peluang)\b"),
    # Dari panduan DBP (keemanxp/dbp-translator-claude, MIT): bentuk Indonesia
    ("indonesia", "perkataan/ejaan Indonesia (guna bentuk Malaysia)",
     r"\b(karena|bagian|informasi|karyawan|merekomendasikan|rumah sakit|pemerintah|bisa|kalian|gimana|banget|nggak|enggak|aja|dong|sih|kok|cuman|udah|sudah dong|sabuk|mengapa sih|kamar|tolol|cewek|cowok|bapak-bapak|ngomong|nanti dulu sih|lagi pula|silakan saja|mau(?= (ke|pergi|apa|beli)))\b"),
    ("anglisisme", "pinjaman Inggeris yang ada padanan Melayu",
     r"\b(download|upload|password|window|file|email|online|offline|level up|update|save|loading|delete|cancel)\b"),
]


def semua_teks():
    """(fail, label/baris, teks) untuk semua teks yang berubah dari asal."""
    out = subprocess.run(["git", "-C", str(ROOT), "diff", "asal", "--name-only", "--", "data", "src"],
                         capture_output=True, encoding="utf-8").stdout.split()
    for rel in out:
        p = ROOT / rel
        if not p.exists():
            continue
        teks = p.read_text(encoding="utf-8")
        if rel.endswith((".inc", ".s")):
            for label, isi in hurai_inc(teks).items():
                yield rel, label, isi
        elif rel.endswith((".c", ".h")):
            for off, isi in string_c(teks):
                yield rel, f"baris {teks.count(chr(10), 0, off) + 1}", isi


def bersih(isi):
    isi = re.sub(r"\{[^}]*\}", " ", isi)
    isi = re.sub(r"\\[npl]", " ", isi)
    return isi.replace("$", "")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--contoh", type=int, default=3)
    ap.add_argument("--csv")
    a = ap.parse_args()
    kira = collections.Counter()
    contoh = collections.defaultdict(list)
    baris_csv = []
    for rel, label, isi in semua_teks():
        t = bersih(isi)
        for kod, ket, rx in CORAK:
            for m in re.finditer(rx, t, re.I if kod not in ("ia-adalah",) else 0):
                kira[kod] += 1
                if len(contoh[kod]) < a.contoh:
                    contoh[kod].append(f"{rel}: {label}: …{t[max(0, m.start()-35):m.end()+35]}…")
                baris_csv.append([kod, rel, label, isi])
                break
    for kod, ket, _ in CORAK:
        print(f"{kira[kod]:5d}  {kod:14s} {ket}")
        for c in contoh[kod]:
            print(f"         {c}")
    print(f"\nJumlah: {sum(kira.values())} kemunculan")
    if a.csv:
        with open(a.csv, "w", encoding="utf-8", newline="") as f:
            csv.writer(f).writerows([["kod", "fail", "label", "teks"]] + baris_csv)
        print(f"Senarai penuh: {a.csv}")


if __name__ == "__main__":
    main()
