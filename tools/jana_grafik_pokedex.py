#!/usr/bin/env python3
"""Lukis semula perkataan Inggeris dalam grafik POKéDEX (graphics/pokedex/*.png) dalam BM.

Jalankan dalam WSL (perlu Pillow):
    python3 tools/jana_grafik_pokedex.py --huruf
    python3 tools/jana_grafik_pokedex.py --pratonton FAIL.png
    python3 tools/jana_grafik_pokedex.py

Sentiasa bermula daripada fail asal (tag git `asal`), jadi boleh diulang.

Fail & kekangan:
- menu.png (helaian tile 16x16, palet BG): tab bar pilihan skrin
  (screen_select_bar_*.bin) dan menu START senarai (start_menu_*.bin).
  Tab KAWASAN hanya ada 3 tile unik (34-36, 24px) kerana tile 33 dikongsi
  di kiri dan kanan tab -> tak muat KAWASAN, guna PETA.
  Item menu START: 9 tile (72px) untuk 3 item pertama, 11 tile (88px) untuk
  2 item terakhir; tile di kanannya ialah grafik lain.
- search_menu.png (search_menu_*.bin): setiap butang 5 tile (40px). Tile 111
  dikongsi sebagai hujung kosong butang SHIFT/SEARCH, jadi tak disentuh.
- interface.png (sprite 1D, 4 tile sebaris): SEARCH/MENU/HOENN/NATIONAL ialah
  sprite 32x16, SEEN/OWN sprite 64x32 (frame 64 dan 96) yang tilenya
  terpecah dua baris helaian.
- area_unknown.png: 3 sprite 32x32 bersebelahan (x 160/192/224) = satu
  sepanduk 96x32.
Huruf diambil daripada perkataan asal; huruf yang tiada dilukis dalam
gaya yang sama (TAMBAHAN). Bayang: kanan, bawah, pepenjuru (seperti asal).
"""
import subprocess
import sys
from io import BytesIO
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
MENU = "graphics/pokedex/menu.png"
CARIAN = "graphics/pokedex/search_menu.png"
ANTARA = "graphics/pokedex/interface.png"
KAWASAN = "graphics/pokedex/area_unknown.png"
FAIL = [MENU, CARIAN, ANTARA, KAWASAN]


# --- pemetaan koordinat logik -> koordinat helaian -------------------------
def terus(x, y):
    return x, y


def sprite(frame, lebar):
    """Sprite 1D dalam helaian 32px lebar (4 tile sebaris)."""
    tw = lebar // 8

    def peta(x, y):
        n = frame + (y // 8) * tw + x // 8
        return (n % 4) * 8 + x % 8, (n // 4) * 8 + y % 8
    return peta


def sepanduk(x, y):
    """area_unknown.png: 3 sprite 32x32 disusun menegak, dipapar mendatar."""
    return x % 32, y + 32 * (x // 32)


# --- label ------------------------------------------------------------------
# fail, peta, x0, x1 (kawasan boleh diubah), y teks, tinggi glyph, warna teks,
# bayang, latar, fon, Inggeris, BM, jajaran ("tengah" = pusat teks asal,
# "kiri" = mula di x teks asal)
L = []


def label(fail, peta, x0, x1, y, tinggi, teks, bayang, latar, fon, en, ms, jajar="tengah", ganti=None):
    L.append(dict(fail=fail, peta=peta, x0=x0, x1=x1, y=y, h=tinggi, teks=teks, bayang=bayang,
                  latar=latar, fon=fon, en=en, ms=ms, jajar=jajar, ganti=ganti or {}))


# menu.png: tab (hitam f, bayang hijau tua d, latar hijau c); tile 34-36 / 38-42 / 43-47
label(MENU, terus, 16, 40, 20, 9, 15, 13, 12, "besar", "AREA", "PETA")
label(MENU, terus, 48, 88, 20, 9, 15, 13, 12, "besar", "CRY", "BUNYI")
label(MENU, terus, 88, 128, 20, 9, 15, 13, 12, "besar", "SIZE", "SAIZ")
# CANCEL putih bersama butang B (tile 64-70), CANCEL merah jambu (tile 72-76)
label(MENU, terus, 16, 56, 36, 9, 9, 5, 7, "besar", "CANCEL", "BATAL", "kiri")
label(MENU, terus, 64, 104, 36, 9, 15, 2, 11, "besar", "CANCEL", "BATAL")
# menu START (putih 9, bayang 5, latar d)
label(MENU, terus, 0, 72, 51, 9, 9, 5, 13, "besar", "BACK TO LIST", "KE SENARAI", "kiri")
label(MENU, terus, 0, 72, 67, 9, 9, 5, 13, "besar", "LIST TOP", "PALING ATAS", "kiri")
label(MENU, terus, 0, 72, 83, 9, 9, 5, 13, "besar", "LIST BOTTOM", "PALING BAWAH", "kiri")
label(MENU, terus, 0, 88, 99, 9, 9, 5, 13, "besar", "BACK TO POKéDEX", "KE POKéDEX", "kiri")
label(MENU, terus, 0, 88, 115, 9, 9, 5, 13, "besar", "CLOSE POKéDEX", "TUTUP POKéDEX", "kiri")
# area_unknown.png (hitam 1, bayang kelabu 2, latar putih a). Ruang putih 76px;
# TAK DIKETAHUI (= gText_Unknown) 75px dengan I biasa, jadi I dikecilkan ke 3 lajur
# supaya ada jidar di kiri/kanan.
I_SEMPIT = ["###"] + [".#."] * 7 + ["###"]
label(KAWASAN, sepanduk, 6, 82, 11, 9, 1, 2, 10, "besar", "AREA UNKNOWN", "TAK DIKETAHUI",
      ganti={"I": I_SEMPIT})

# search_menu.png: butang oren (putih 4, bayang b, latar a), hijau (4, 9, 8)
label(CARIAN, terus, 0, 40, 20, 7, 4, 11, 10, "kecil", "MODE", "MOD")
label(CARIAN, terus, 40, 80, 20, 7, 4, 11, 10, "kecil", "ORDER", "SUSUN")
label(CARIAN, terus, 80, 120, 20, 7, 4, 11, 10, "kecil", "NAME", "NAMA")
label(CARIAN, terus, 0, 40, 36, 7, 4, 11, 10, "kecil", "COLOR", "WARNA")
label(CARIAN, terus, 40, 80, 36, 7, 4, 11, 10, "kecil", "TYPE", "JENIS")
label(CARIAN, terus, 80, 120, 36, 7, 4, 9, 8, "kecil", "CANCEL", "BATAL")
label(CARIAN, terus, 0, 40, 52, 7, 4, 9, 8, "kecil", "OK", "OK")
label(CARIAN, terus, 40, 80, 52, 7, 4, 9, 8, "kecil", "SHIFT", "TUKAR")
label(CARIAN, terus, 80, 120, 52, 7, 4, 9, 8, "kecil", "SEARCH", "CARI")

# interface.png (putih 1, bayang hitam f, lutsinar 0)
label(ANTARA, sprite(64, 64), 0, 64, 6, 7, 1, 15, 0, "kecil", "SEEN", "DILIHAT")
label(ANTARA, sprite(96, 64), 0, 64, 6, 7, 1, 15, 0, "kecil", "OWN", "DIMILIKI")
label(ANTARA, terus, 0, 32, 83, 9, 1, 15, 0, "sprite", "SEARCH", "CARI", "kiri")
label(ANTARA, terus, 0, 32, 115, 9, 1, 15, 0, "sprite", "MENU", "MENU", "kiri")
label(ANTARA, terus, 0, 32, 324, 7, 1, 15, 0, "nipis", "HOENN", "HOENN", "kiri")
label(ANTARA, terus, 0, 32, 340, 7, 1, 15, 0, "nipis", "NATIONAL", "NASIONAL", "kiri")

# Huruf yang tiada dalam perkataan asal ('#' = warna teks), gaya & saiz sama
TAMBAHAN = {
    "besar": {  # 5x9
        "G": [".###.", "#...#", "#....", "#....", "#.###", "#...#", "#...#", "#...#", ".###."],
        "H": ["#...#", "#...#", "#...#", "#...#", "#####", "#...#", "#...#", "#...#", "#...#"],
    },
    "kecil": {  # 5x7
        "B": ["####.", "#...#", "#...#", "####.", "#...#", "#...#", "####."],
        "J": ["....#", "....#", "....#", "....#", "....#", "#...#", ".###."],
        "U": ["#...#", "#...#", "#...#", "#...#", "#...#", "#...#", ".###."],
    },
    "sprite": {  # 4x9 (I 3 lajur)
        "I": ["###", ".#.", ".#.", ".#.", ".#.", ".#.", ".#.", ".#.", "###"],
    },
    "nipis": {  # 3x7
        "S": [".##", "#..", "#..", ".#.", "..#", "..#", "##."],
    },
}
RUANG = {"besar": 3, "kecil": 3, "sprite": 2, "nipis": 2}  # lebar tambahan untuk jarak
# Fon yang hurufnya diambil dahulu daripada perkataan asal label itu sendiri
# (huruf O dalam HOENN dan NATIONAL berbeza lebar).
TEMPATAN = {"nipis"}


def asal(rel):
    data = subprocess.run(["git", "-C", str(ROOT), "show", f"asal:{rel}"],
                          capture_output=True, check=True).stdout
    return Image.open(BytesIO(data))


def lajur_teks(px, lb):
    p = lb["peta"]
    return [x for x in range(lb["x0"], lb["x1"])
            if any(px[p(x, y)] == lb["teks"] for y in range(lb["y"], lb["y"] + lb["h"]))]


def kumpulan(lajur):
    kump, cur = [], []
    for x in lajur:
        if cur and x != cur[-1] + 1:
            kump.append(cur)
            cur = []
        cur.append(x)
    if cur:
        kump.append(cur)
    return kump


def ekstrak(imej):
    abjad = {f: {} for f in TAMBAHAN}
    for lb in L:
        px = imej[lb["fail"]].load()
        p = lb["peta"]
        kump = kumpulan(lajur_teks(px, lb))
        huruf = [c for c in lb["en"] if c != " "]
        if len(kump) != len(huruf):
            print(f"amaran: {lb['en']}: {len(kump)} kumpulan != {len(huruf)} huruf", file=sys.stderr)
            continue
        lb["tempatan"] = {}
        for h, xs in zip(huruf, kump):
            g = ["".join("#" if px[p(x, y)] == lb["teks"] else "." for x in xs)
                 for y in range(lb["y"], lb["y"] + lb["h"])]
            lb["tempatan"].setdefault(h, g)
            lama = abjad[lb["fon"]].setdefault(h, g)
            if lama != g and "--huruf" in sys.argv:  # huruf sama tetapi bentuk lain
                print(f"beza: {lb['fon']} {h} ({lb['en']})", file=sys.stderr)
    for f, t in TAMBAHAN.items():
        for k, v in t.items():
            abjad[f].setdefault(k, v)
    return abjad


def glyph(lb, c, abjad):
    if c in lb["ganti"]:
        return lb["ganti"][c]
    if lb["fon"] in TEMPATAN and c in lb.get("tempatan", {}):
        return lb["tempatan"][c]
    return abjad[lb["fon"]][c]


def lebar(lb, abjad):
    kata, w = lb["ms"], 0
    for i, c in enumerate(kata):
        if c == " ":
            w += RUANG[lb["fon"]]
            continue
        w += len(glyph(lb, c, abjad)[0]) + (1 if i < len(kata) - 1 else 0)
    return w + 1  # bayang lajur akhir


def lukis(imej, abjad):
    for lb in L:
        if lb["ms"] == lb["en"]:
            continue
        px = imej[lb["fail"]].load()
        p = lb["peta"]
        kump = kumpulan(lajur_teks(px, lb))
        kiri, kanan = kump[0][0], kump[-1][-1] + 1  # +1 = lajur bayang
        fon = lb["fon"]
        w = lebar(lb, abjad)
        if lb["jajar"] == "kiri":
            x = kiri
        else:
            x = (kiri + kanan + 1 - w) // 2
        x = max(lb["x0"], min(x, lb["x1"] - w))
        if w > lb["x1"] - lb["x0"]:
            sys.exit(f"TAK MUAT: {lb['ms']} {w} > {lb['x1'] - lb['x0']}px")
        y0, y1 = lb["y"], lb["y"] + lb["h"] + 1
        for y in range(y0, y1):
            for xx in range(lb["x0"], lb["x1"]):
                if px[p(xx, y)] in (lb["teks"], lb["bayang"]):
                    px[p(xx, y)] = lb["latar"]
        putih = set()
        for i, c in enumerate(lb["ms"]):
            if c == " ":
                x += RUANG[fon]
                continue
            g = glyph(lb, c, abjad)
            for dy, baris in enumerate(g):
                for dx, ch in enumerate(baris):
                    if ch == "#":
                        putih.add((x + dx, y0 + dy))
            x += len(g[0]) + 1
        for (a, b) in putih:
            for dx, dy in ((1, 0), (0, 1), (1, 1)):
                q = (a + dx, b + dy)
                if q not in putih and lb["x0"] <= q[0] < lb["x1"] and q[1] < y1:
                    px[p(*q)] = lb["bayang"]
        for q in putih:
            px[p(*q)] = lb["teks"]


def susun(im, peta, w, h):
    """Bina imej w x h (koordinat logik) daripada helaian melalui peta."""
    px = im.load()
    k = Image.new("RGB", (w, h))
    pal = im.getpalette()
    for y in range(h):
        for x in range(w):
            i = px[peta(x, y)]
            k.putpixel((x, y), tuple(pal[i * 3:i * 3 + 3]))
    return k


# (fail, peta, kotak potongan logik x0, y0, x1, y1)
PANEL = [
    (MENU, terus, (0, 0, 128, 128)),
    (CARIAN, terus, (0, 0, 128, 64)),
    (KAWASAN, sepanduk, (0, 0, 96, 32)),
    (ANTARA, sprite(64, 64), (0, 0, 64, 16)),
    (ANTARA, sprite(96, 64), (0, 0, 64, 16)),
    (ANTARA, terus, (0, 80, 32, 128)),
    (ANTARA, terus, (0, 320, 32, 352)),
]


def pratonton(asli, baru, keluar):
    """Asal (kiri) dan baharu (kanan) bagi setiap panel, dibesarkan 4x."""
    s, jarak = 4, 4
    baris = []
    for rel, peta, (x0, y0, x1, y1) in PANEL:
        a = susun(asli[rel], peta, x1, y1).crop((x0, y0, x1, y1))
        b = susun(baru[rel], peta, x1, y1).crop((x0, y0, x1, y1))
        baris.append((a, b))
    lebar_k = max(a.width * 2 + jarak for a, _ in baris) * s
    tinggi_k = sum(a.height + jarak for a, _ in baris) * s
    k = Image.new("RGB", (lebar_k, tinggi_k), (255, 0, 255))
    y = 0
    for a, b in baris:
        k.paste(a.resize((a.width * s, a.height * s), Image.NEAREST), (0, y))
        k.paste(b.resize((b.width * s, b.height * s), Image.NEAREST), ((a.width + jarak) * s, y))
        y += (a.height + jarak) * s
    k.save(keluar)


def main():
    asli = {rel: asal(rel) for rel in FAIL}
    imej = {rel: im.copy() for rel, im in asli.items()}
    abjad = ekstrak(asli)
    if "--huruf" in sys.argv:
        for f in abjad:
            print("==", f)
            for h in sorted(abjad[f]):
                print(h)
                for baris in abjad[f][h]:
                    print("   ", baris)
        return
    lukis(imej, abjad)
    if "--pratonton" in sys.argv:
        pratonton(asli, imej, sys.argv[sys.argv.index("--pratonton") + 1])
        return
    for rel, im in imej.items():
        im.save(ROOT / rel)
    print(f"{len(imej)} fail ditulis.")


if __name__ == "__main__":
    main()
