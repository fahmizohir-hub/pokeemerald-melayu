VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "PERTANDINGAN mana yang kamu nak\n"
	.string "masuk? Nak sedikit nasihat?\p"
	.string "Dalam mana-mana PERTANDINGAN,\n"
	.string "contohnya PERTANDINGAN COMEL, saya\l"
	.string "rasa pusingan pertama bukan menilai\l"
	.string "kecomelan saja.\p"
	.string "Kamu perlu cari cara untuk melatih\n"
	.string "POKéMON dengan lebih baik.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "Saya latih POKéMON saya supaya comel.\p"
	.string "Rupanya POKéMON boleh dimasukkan ke\n"
	.string "PERTANDINGAN kecomelan!\p"
	.string "Gembiranya saya sebab latih POKéMON\n"
	.string "saya dengan penuh kasih sayang…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "POKéMON saya memang terbaik!\p"
	.string "Ia segak, tegap tapi cantik, comel, dan\n"
	.string "bijak. Lengkap!\p"
	.string "Baik saya cuba menang setiap\n"
	.string "PERTANDINGAN.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "PERTANDINGAN POKéMON\n"
	.string "PENTAS TAHAP NORMAL!$"

