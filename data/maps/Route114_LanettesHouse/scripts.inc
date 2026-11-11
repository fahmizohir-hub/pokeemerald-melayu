Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Maaf, semuanya bersepah…\n"
	.string "Bila saya asyik buat kajian,\l"
	.string "beginilah jadinya…\p"
	.string "Malunya… Tolong rahsiakan hal ni,\n"
	.string "dan sebagai balasan, ambil ni.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Boleh saya beri nasihat tentang Sistem\n"
	.string "Simpanan POKéMON saya?\p"
	.string "Susunlah KOTAK kamu supaya kamu tahu\n"
	.string "POKéMON mana yang ada di dalamnya.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Ini nota kajian LANETTE.\n"
	.string "Ada maklumat tentang KOTAK.\p"
	.string "Reka KOTAK untuk muat 30 POKéMON.\p"
	.string "Setiap JURULATIH patut boleh simpan\n"
	.string "420 POKéMON dalam sistem PC.\p"
	.string "Teruskan membaca?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Sistem tanda patut ditambah supaya\n"
	.string "POKéMON lebih mudah disusun.\p"
	.string "Nama dan reka bentuk kertas dinding\n"
	.string "setiap KOTAK boleh diubah supaya\l"
	.string "POKéMON yang disimpan gembira.\p"
	.string "Teruskan membaca?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Bila POKéMON disimpan, ia patut\n"
	.string "dihantar ke KOTAK terakhir dilihat.\p"
	.string "Kalau KOTAK itu penuh, POKéMON yang\n"
	.string "diterima disimpan di KOTAK berikutnya.\p"
	.string "Dengan kata lain, bila KOTAK diperiksa,\n"
	.string "ia dipilih secara automatik sebagai\l"
	.string "KOTAK tempat POKéMON dihantar.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} menutup buku nota.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Ada e-mel daripada seseorang dalam\n"
	.string "PC ni.\p"
	.string "“… … … … … … …\p"
	.string "“Sistem Simpanan awak lebih mudah\n"
	.string "digunakan daripada sistem saya.\p"
	.string "“Banyak ciri mesra pengguna yang\n"
	.string "buat ia seronok dan berguna.\p"
	.string "“Saya bangga kerana dapat terlibat\n"
	.string "dalam pembangunannya.\p"
	.string "“Semoga awak terus membuat kajian\n"
	.string "tentang Sistem Simpanan.\p"
	.string "“Daripada BILL\n"
	.string "… … … … … … … …”$"

