Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} menulis kod rahsia pada pintu.\p"
	.string "“PAKAR HELAH memang segak.”\n"
	.string "… … … … … … … …\p"
	.string "Kunci terbuka dengan bunyi klik!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Leceh betul nak fikir semua ni. Saya\n"
	.string "cuma nak bertarung!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Walaupun kalah, saya tetap paling suka\n"
	.string "bertarung!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Kamu setuju, kan? Kamu sanggup pergi\n"
	.string "ke mana saja kalau ada JURULATIH di\l"
	.string "sana.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Heh! Batu macam ni, saya boleh tolak\n"
	.string "dengan sebatang jari!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Saya boleh tolak batu, tapi tak boleh\n"
	.string "selesaikan teka-teki…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Kuat saja tak cukup…\n"
	.string "Kena guna kepala. Jadi bijak!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "RUMAH HELAH ni makin rumit, kan?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaak!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Ada sesiapa yang dah sampai ke hujung?$"

