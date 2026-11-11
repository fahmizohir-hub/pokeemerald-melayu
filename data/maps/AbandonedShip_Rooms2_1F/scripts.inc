AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Masa mencari harta karun, kami\n"
	.string "terjumpa seorang JURULATIH!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: Kami tak boleh menang walaupun dah\n"
	.string "bekerjasama…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: Kami tak jumpa apa-apa harta… Ada\n"
	.string "orang dah ambil ke?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Kamu tak ada dua POKéMON pun.\n"
	.string "Macam mana nak kalahkan kami?$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: Oh?\n"
	.string "Kami tengah cari harta karun.\l"
	.string "Tapi terjumpa JURULATIH pula!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: Ooh, kuatnya!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: Di mana agaknya harta tu?\p"
	.string "Saya dah tahu nak beli apa bila kami\n"
	.string "jumpa harta tu nanti!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Oh, kamu tak ada dua POKéMON?\n"
	.string "Kita lawan lain kali sajalah!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: Oh, geramnya saya!\n"
	.string "Saya nak daftarkan kamu sebab tu!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: Kami dah lama cari harta karun.\p"
	.string "POKéMON kami pun dah makin kuat.\n"
	.string "Biar kami tunjukkan, okey?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Kamu memang kuat macam biasa!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: Harta tak jumpa, lawan POKéMON pun\n"
	.string "kalah…\p"
	.string "Saya nak balik… Tapi kalau saya cakap\n"
	.string "macam tu, dia mesti marah…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Kamu tak ada dua POKéMON pun.\n"
	.string "Macam mana nak kalahkan kami?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: Oh? Kita jumpa lagi!\p"
	.string "Macam kami, kamu pun belum berputus asa\n"
	.string "cari harta, kan?\p"
	.string "Apa kata yang kalah kena berhenti\n"
	.string "mencari?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: Alamak, kami kalah lagi…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: Kami takkan pergi selagi tak latih\n"
	.string "POKéMON kami lagi dan jumpa harta\l"
	.string "karun di sini!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Oh, kamu tak ada dua POKéMON?\n"
	.string "Kita lawan lain kali sajalah!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Saya tak pandai berenang,\n"
	.string "tapi saya pandai bertarung!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Alamak.\n"
	.string "Tak menjadi pula.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Berjalan kaki ayam dalam kapal ni rasa\n"
	.string "geli sikit.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Kekuatan dan belas kasihan…\n"
	.string "Itulah harta seorang JURULATIH!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, ada sesuatu tentang kamu yang\n"
	.string "berkilauan.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "Dalam salah satu kabin di kapal ini, saya\n"
	.string "nampak sesuatu berkilau.$"
