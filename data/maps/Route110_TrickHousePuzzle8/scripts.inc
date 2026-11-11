Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} menulis kod rahsia pada pintu.\p"
	.string "“PAKAR HELAH saya cintai.”\n"
	.string "… … … … … … … …\p"
	.string "Kunci terbuka dengan bunyi klik!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Tak ramai JURULATIH yang sampai sejauh\n"
	.string "ni.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Maknanya kamu pun hebat…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Kamu dah kalahkan JUARA LIGA POKéMON?\n"
	.string "Biar betul!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Kamu patut rasa bertuah dapat lawan\n"
	.string "saya!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Ini tak betul!\n"
	.string "Saya tak boleh kalah!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Satu keajaiban kamu kalahkan saya.\n"
	.string "Kamu boleh berbangga.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Kamu pun bertungkus-lumus melalui\n"
	.string "cabaran RUMAH HELAH.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Begitu…\n"
	.string "Kamu ada gaya yang luar biasa.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Tengok orang macam kamu mesti buat\n"
	.string "PAKAR HELAH gembira.$"

