Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER_END
	showobjectat LOCALID_TRICK_MASTER_END, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_FacePlayer
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applywaitmovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterSpin
	playse SE_M_EXPLOSION
	applywaitmovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterJumpAway
	removeobject LOCALID_TRICK_MASTER_END
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterDown
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterUp
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterLeft
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterRight
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER_END, DIR_WEST
	playse SE_PIN
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_ExclamationMark
	delay 20
	applywaitmovement LOCALID_TRICK_MASTER_END, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	playse SE_M_EXPLOSION
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	delay 4
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.string "Aak!\n"
	.string "Kamu dah sampai kepada saya?\l"
	.string "Hmmm… Kamu memang bijak!$"

Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "Semalaman saya tanam semua pokok tu…\p"
	.string "Kehebatan kamu hampir setanding saya,\n"
	.string "kurang satu, dua, tiga, empat, lima, enam\l"
	.string "tangga saja!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "Semalaman saya bina labirin tu…\p"
	.string "Kehebatan kamu hampir setanding saya,\n"
	.string "kurang satu, dua, tiga, empat, lima\l"
	.string "tangga saja!$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "Semalaman saya sediakan panel dinding\n"
	.string "tu…\p"
	.string "Kehebatan kamu hampir setanding saya,\n"
	.string "kurang satu, dua, tiga, empat tangga\l"
	.string "saja!$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "Semalaman saya tolak masuk batu-batu\n"
	.string "besar tu…\p"
	.string "Kehebatan kamu hampir setanding saya,\n"
	.string "kurang satu, dua, tiga tangga saja!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "Semalaman saya buat MECHADOLL dan\n"
	.string "semalam lagi untuk fikirkan kuiz…\p"
	.string "Kehebatan kamu hampir setanding saya,\n"
	.string "kurang satu, dua tangga saja!$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "Semalaman saya pasang pintu-pintu tu…\p"
	.string "Kehebatan kamu hampir setanding saya!$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "Semalaman saya pasang anak panah…\p"
	.string "Kehebatan kamu setanding saya!$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "Semalaman saya gilap lantai…\p"
	.string "Kehebatan kamu mengatasi saya!\n"
	.string "Mungkin…$"

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "A-apa saya nak buat?\n"
	.string "Idea helah saya dah kering…\p"
	.string "Mungkin dah tiba masanya saya\n"
	.string "mengembara ke seluruh negara untuk\l"
	.string "cipta helah baru…$"

Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.string "Berat hati saya nak mengaku kalah, tapi\n"
	.string "kamu dah tewaskan saya!\p"
	.string "Namun, kamu mesti terpikat dengan\n"
	.string "karisma saya sampai datang melawat\l"
	.string "berulang kali. Ya, mesti begitu!\p"
	.string "Tapi itu tak ada kena-mengena dengan\n"
	.string "kekalahan saya!\p"
	.string "Sebagai tanda persahabatan antara\n"
	.string "kamu yang gigih dan saya yang genius ni,\l"
	.string "saya mahu kamu ambil kenang-kenangan\l"
	.string "ni!\p"
	.string "Sebenarnya ada dua, KHEMAH MERAH dan\n"
	.string "KHEMAH BIRU.\l"
	.string "Kamu suka yang mana?$"

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.string "Apa? PC kamu dah tiada ruang?\n"
	.string "Apa saya nak buat dengan itu?\p"
	.string "Nak saja saya cakap begitu, tapi saya\n"
	.string "terlalu baik hati, jadi datanglah semula\l"
	.string "nanti!$"

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.string "… … … … … …\p"
	.string "Saya akan pergi mengembara untuk\n"
	.string "meneroka. Satu misi mencari helah baru.\p"
	.string "Saya harap satu hari nanti kamu datang\n"
	.string "melawat dan hiburkan saya lagi.\p"
	.string "Dan sekarang, selamat tinggal!$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "Baiklah!\n"
	.string "Kamu layak dapat ganjaran ni!$"

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.string "Apa? Kamu tiada ruang untuk ni?\n"
	.string "Barang apa yang kamu bawa sebenarnya?\p"
	.string "Tak apa, sebab kamu dah sampai kepada\n"
	.string "saya, ganjaran kamu saya simpan dulu.$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "Hapuskan senyum sinis tu dari muka\n"
	.string "kamu! Terlalu awal nak rasa kamu dah\l"
	.string "menang!\p"
	.string "Saya akan cipta helah baru untuk buat\n"
	.string "kamu buntu. Kamu boleh ejek saya bila\l"
	.string "kamu dah selesai.\p"
	.string "Datang semula untuk episod seterusnya\n"
	.string "yang mendebarkan!$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.string "Eh, eh! Kamu buat tak tahu pada saya?\n"
	.string "Itu sungguh menghancurkan hati saya!$"

