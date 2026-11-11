Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Abang saya PEMINAT FOSIL…\n"
	.string "Dia baik dan sangat suka FOSIL…\p"
	.string "Dia pun suka gali lubang…\n"
	.string "Dia gali lubang ni seorang diri…\p"
	.string "Ambillah ni, supaya kamu boleh GALI\n"
	.string "lubang macam abang saya…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Kalau POKéMON guna GALI di dalam gua,\n"
	.string "kamu akan kembali ke pintu masuk…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Batu-batu yang pelik bentuknya\n"
	.string "memenuhi almari pameran…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "KOMPOSISI LAPISAN BATUAN…\n"
	.string "BAGAIMANA HUJAN MEMBENTUK BUMI…\l"
	.string "BATU, TANAH DAN BATUAN…\p"
	.string "Penuh dengan buku.$"

