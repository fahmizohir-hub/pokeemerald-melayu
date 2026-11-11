VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applywaitmovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applywaitmovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "WALLY: Hai! {PLAYER}!\p"
	.string "Mesti kamu terkejut jumpa saya di sini!\p"
	.string "Saya berjaya sampai ke sini,\n"
	.string "dan semuanya berkat kamu!\p"
	.string "{PLAYER}, kalah dengan kamu\n"
	.string "dulu buat saya jadi lebih kuat!\p"
	.string "Tapi saya takkan kalah lagi!\p"
	.string "Saya akan menang! Demi POKéMON yang\n"
	.string "beri saya keberanian dan kekuatan!\p"
	.string "Okey… Saya datang ni!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Wah!\n"
	.string "{PLAYER}, kamu memang kuat!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "WALLY: Saya tak dapat kalahkan kamu\n"
	.string "hari ni, {PLAYER}, tapi satu hari\l"
	.string "nanti, saya akan kejar kamu!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "WALLY: Hai! {PLAYER}!\p"
	.string "Saya dah makin kuat sejak kali\n"
	.string "terakhir kita jumpa! Saya nak\l"
	.string "tunjuk pada kamu, {PLAYER}!\p"
	.string "Okey… Saya datang ni!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Wah!\n"
	.string "{PLAYER}, kamu memang kuat!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "WALLY: Kali ini pun saya tak dapat\n"
	.string "kalahkan kamu… Tapi satu hari nanti,\l"
	.string "{PLAYER}, saya akan kejar kamu…\p"
	.string "Dan cabar LIGA POKéMON!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "Dah beberapa kali saya sampai sini, tapi\n"
	.string "laluan terakhir ni panjang sangat…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Impian saya berakhir di sini lagi…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Kamu dah sampai sejauh ini. Teruskan\n"
	.string "semangat dan jadilah JUARA! Kalau\l"
	.string "ada yang mampu, kamulah orangnya!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Saya tak datang sejauh ini untuk\n"
	.string "kalah. Kalah tak ada dalam kamus saya!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Mustahil…\n"
	.string "Saya kalah?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "Saya kalah di sini…\p"
	.string "Maknanya saya tak layak untuk jadi\n"
	.string "JUARA…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Jalan keras yang seakan tiada hujung\n"
	.string "ini memang layak digelar KEMENANGAN.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Gaya bertarung kamu memang hebat…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Nampaknya kamu berpotensi untuk jadi\n"
	.string "JUARA.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Apa itu JALAN KEMENANGAN?\n"
	.string "Saya beritahu kalau kamu menang!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Okey!\n"
	.string "Syabas!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Melepasi tempat ini dengan selamat,\n"
	.string "itulah ujian terakhir bagi JURULATIH\l"
	.string "yang mahu jadi JUARA POKéMON.\p"
	.string "Sebab itulah ia dipanggil JALAN\n"
	.string "KEMENANGAN.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Saya tak ada apa nak cakap dengan\n"
	.string "orang yang dah sampai sejauh ni. Ayuh!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "Memalukan…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Hmph, teruskanlah.\n"
	.string "Saya tak kisah.$"
