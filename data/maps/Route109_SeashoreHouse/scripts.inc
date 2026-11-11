Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Saya pemilik RUMAH TEPI PANTAI ni. Tapi\n"
	.string "panggil saja saya ENCIK LAUT!\p"
	.string "Yang paling saya suka ialah tengok\n"
	.string "pertarungan POKéMON yang panas!\p"
	.string "Tunjukkan semangat kamu yang membara!\p"
	.string "Kalau kamu boleh kalahkan semua\n"
	.string "JURULATIH di sini, saya akan beri\l"
	.string "ganjaran.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Tunjukkan saya perlawanan yang panas!\p"
	.string "Saya buka RUMAH TEPI PANTAI ni\n"
	.string "semata-mata sebab tu!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Kamu memang panas membara!\n"
	.string "Pertarungan tadi menyala-nyala! Saya\l"
	.string "puas hati sangat!\p"
	.string "Sebagai tanda terima kasih sebab\n"
	.string "tunjuk semangat panas kamu, ambillah\l"
	.string "ni.\p"
	.string "Setengah dozen botol AIR SODA!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, tapi BEG kamu dah sendat. Biar saya\n"
	.string "simpankan dulu untuk kamu.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Nak beli AIR SODA? POKéMON suka\n"
	.string "sangat!\p"
	.string "¥300 sebotol saja! Belilah!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Nah, ambil ni!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Duit kamu tak cukup.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Tak nak? Sayangnya.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Kalau cari lawan di RUMAH TEPI PANTAI,\n"
	.string "tak ada JURULATIH lebih panas daripada\l"
	.string "saya, kawan!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Pertarungan yang panas! Saya terima\n"
	.string "kekalahan ni, kawan!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Setiap kali ke SLATEPORT, saya mesti\n"
	.string "layan pertarungan panas dan AIR\l"
	.string "SODA sejuk!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Tak berbaloi bertarung\n"
	.string "kalau membosankan.\p"
	.string "Pertarungan yang panas membara yang\n"
	.string "buat JURULATIH dan POKéMON jadi tegap!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Panasnya!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Fuh, hausnya. Nak minum AIR SODA lah.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Saya nak tunjuk betapa hebatnya\n"
	.string "POKéMON saya, tapi jangan menangis!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…Saya kalah, tapi saya takkan\n"
	.string "menangis…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Kalau POKéMON saya tahu move untuk\n"
	.string "bawa saya merentas air atas\l"
	.string "belakangnya, saya boleh buang\l"
	.string "pelampung ni.$"

