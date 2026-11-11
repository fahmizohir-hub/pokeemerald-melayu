Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition:
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

Route112_EventScript_MagmaGrunts::
	lockall
	delay 40
	applywaitmovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	delay 20
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_FaceOriginalDirection
	delay 40
	applywaitmovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	delay 20
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_FaceOriginalDirection
	delay 40
	applywaitmovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	delay 20
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_FaceOriginalDirection
	delay 40
	applywaitmovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	delay 20
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_FaceOriginalDirection
	releaseall
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker::
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route112_EventScript_RematchTrent
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RegisterTrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRENT_1
	release
	end

Route112_EventScript_RematchTrent::
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry::
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_LeaderGoingToAwakenThing:
	.string "Hei, bro, betul ke ketua kita nak\n"
	.string "bangkitkan benda tu?$"

Route112_Text_YeahWeNeedMeteorite:
	.string "Macam tu lah bunyinya. Tapi aku dengar\n"
	.string "kita perlukan METEORIT untuk buat\l"
	.string "begitu.$"

Route112_Text_OhThatsWhyCrewWentToFallarbor:
	.string "Oh, baru aku faham. Sebab tu yang lain\n"
	.string "pergi ke FALLARBOR.$"

Route112_Text_CantLetAnyonePassUntilTheyreBack:
	.string "Betul tu. Dan selagi mereka belum balik,\n"
	.string "kita tak boleh biar sesiapa lalu, faham.$"

Route112_Text_NotEasyToGetBackToLavaridge:
	.string "Eh, saya nak ke MAUVILLE, tapi kalau\n"
	.string "saya turun tebing ni, susah nak balik\l"
	.string "semula ke LAVARIDGE.$"

Route112_Text_MtChimneyCableCarSign:
	.string "KERETA KABEL GUNUNG CHIMNEY\n"
	.string "“Jalan sikit saja ke {UP_ARROW}!”$"

Route112_Text_MtChimneySign:
	.string "GUNUNG CHIMNEY\p"
	.string "“Ke PEKAN LAVARIDGE atau puncak, sila\n"
	.string "naik KERETA KABEL.”$"

Route112_Text_RouteSignLavaridge:
	.string "LALUAN 112\n"
	.string "{LEFT_ARROW} PEKAN LAVARIDGE$"

