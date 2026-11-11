Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} menulis kod rahsia pada pintu.\p"
	.string "“PAKAR HELAH ialah nyawa saya.”\n"
	.string "… … … … … … … …\p"
	.string "Kunci terbuka dengan bunyi klik!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Bila saya dengar ada rumah pelik, saya\n"
	.string "kena datang tengok.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "Saya dah jumpa JURULATIH yang hebat!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Memang seronok saya meneroka tempat\n"
	.string "ni.\p"
	.string "Ini cabaran yang berbaloi untuk\n"
	.string "diulang!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Mungkin saya boleh suruh POKéMON\n"
	.string "BURUNG saya terbang atas dinding…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gwaaah! Saya rosakkan semuanya!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe… Agaknya saya kalah sebab\n"
	.string "cuba main tipu.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Saya pening dengan pintu berputar ni…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Semuanya berpusing-pusing. Saya dah\n"
	.string "tak tahan…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Kamu nampak langsung tak terkesan.\n"
	.string "Atau kamu sedang buat muka selamba?$"

