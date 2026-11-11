Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} menulis kod rahsia pada pintu.\p"
	.string "“PAKAR HELAH memang hebat.”\n"
	.string "… … … … … … … …\p"
	.string "Kunci terbuka dengan bunyi klik!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Saya akan tetak dan tebas sampai\n"
	.string "menang dengan POTONG yang baru kami\l"
	.string "belajar!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Kenapa kamu serius sangat?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Saya tak pernah jemu menetak dan\n"
	.string "menebas!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Saya tersesat masuk rumah pelik ni\n"
	.string "secara tak sengaja…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Dan sekarang saya kalah pula…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Saya sesat jalan, kalah bertarung, dan\n"
	.string "sekarang lagi sesat… Saya tak boleh\l"
	.string "keluar…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Siapa sebenarnya PAKAR HELAH tu?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Saya kalah sebab leka berfikir!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Kamu kuat!\n"
	.string "Siapa sebenarnya kamu ni?$"

