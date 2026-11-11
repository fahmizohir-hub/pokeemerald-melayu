Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume:
	special UpdateCyclingRoadState
	end

Route110_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Route110_OnFrame:
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route110_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route110_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route110_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

Route110_EventScript_Boy1::
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1::
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1::
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan::
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman::
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2::
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2::
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign::
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign::
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign::
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign::
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign::
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign::
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep::
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems::
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign::
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign::
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet::
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy::
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike::
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike::
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused::
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd::
	lockall
	applywaitmovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_ChallengeReactionBest
	case 9, Route110_EventScript_ChallengeReactionGood
	case 8, Route110_EventScript_ChallengeReactionGood
	case 7, Route110_EventScript_ChallengeReactionGood
	case 6, Route110_EventScript_ChallengeReactionOk
	case 5, Route110_EventScript_ChallengeReactionOk
	case 4, Route110_EventScript_ChallengeReactionOk
	case 3, Route110_EventScript_ChallengeReactionBad
	case 2, Route110_EventScript_ChallengeReactionBad
	case 1, Route110_EventScript_ChallengeReactionBad
	case 0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest::
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood::
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk::
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad::
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst::
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 1
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 2
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 3
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
	applywaitmovement LOCALID_ROUTE110_RIVAL, Common_Movement_WalkInPlaceFasterDown
	applywaitmovement LOCALID_ROUTE110_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_ROUTE110_RIVAL, Common_Movement_Delay48
	delay 30
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
	releaseall
	end

Route110_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route110_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route110_EventScript_MayBattle::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_MayBattleTreecko
	case 1, Route110_EventScript_MayBattleTorchic
	case 2, Route110_EventScript_MayBattleMudkip
	end

Route110_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanBattle::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_BrendanBattleTreecko
	case 1, Route110_EventScript_BrendanBattleTorchic
	case 2, Route110_EventScript_BrendanBattleMudkip
	end

Route110_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_GiveItemfinder::
	giveitem ITEM_ITEMFINDER
	return

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_ROUTE110_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_ROUTE110_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_ROUTE110_RIVAL
	addobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
	removeobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applywaitmovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer1
	return

Route110_EventScript_RivalApproachPlayer2::
	applywaitmovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer2
	return

Route110_EventScript_RivalApproachPlayer3::
	applywaitmovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer3
	return

Route110_EventScript_RivalExit1::
	applywaitmovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	return

Route110_EventScript_RivalExit2::
	applywaitmovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	return

Route110_EventScript_RivalExit3::
	applywaitmovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 35, 55
	return

Route110_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalExit1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_BirchScene1::
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene2::
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene3::
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene4::
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene::
	addobject LOCALID_ROUTE110_BIRCH
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchEntrance
	playse SE_PIN
	applywaitmovement LOCALID_ROUTE110_BIRCH, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_ROUTE110_BIRCH, Common_Movement_Delay48
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applywaitmovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterLeft
	delay 10
	applywaitmovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterRight
	delay 20
	applywaitmovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterDown
	delay 30
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
	removeobject LOCALID_ROUTE110_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer1
	return

Route110_EventScript_BirchApproachPlayer2::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer2
	return

Route110_EventScript_BirchApproachPlayer3::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer3
	return

Route110_EventScript_BirchApproachPlayer4::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer4
	return

Route110_EventScript_BirchExit1::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit1
	return

Route110_EventScript_BirchExit2::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit2
	return

Route110_EventScript_BirchExit3::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit3
	return

Route110_EventScript_BirchExit4::
	applywaitmovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit4
	return

Route110_Movement_BirchEntrance:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer2:
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer3:
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer4:
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_BirchExit1:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities:
	.string "Aktiviti TEAM AQUA…\n"
	.string "Kami tak boleh cerita lagi.$"

Route110_Text_KickUpARuckus:
	.string "Aku nak cepat ke SLATEPORT dan buat\n"
	.string "kecoh!$"

Route110_Text_MyFirstJobInAqua:
	.string "Ini kerja pertama aku lepas sertai\n"
	.string "TEAM AQUA. Seram sikit.$"

Route110_Text_AquaActionsBringSmiles:
	.string "Tindakan TEAM AQUA patut buat orang\n"
	.string "tersenyum!$"

Route110_Text_MayLetsBattle:
	.string "MAY: Hai, {PLAYER}{KUN}, lama tak jumpa!\p"
	.string "Masa aku cari POKéMON lain, POKéMON aku\n"
	.string "jadi makin kuat.\p"
	.string "Jadi…\n"
	.string "Apa kata kita bertarung sikit?$"

Route110_Text_MayDefeated:
	.string "Alamak!\n"
	.string "Kau lagi hebat dari jangkaan aku!$"

Route110_Text_MayTakeThis:
	.string "MAY: {PLAYER}{KUN}, kau pun sibuk berlatih,\n"
	.string "kan?\p"
	.string "Aku rasa kau layak dapat hadiah!\n"
	.string "Ini daripada aku!$"

Route110_Text_MayExplainItemfinder:
	.string "MAY: Itu PENGESAN.\p"
	.string "Cubalah. Kalau ada barang yang tak\n"
	.string "kelihatan, ia akan berbunyi.\p"
	.string "Okey, {PLAYER}{KUN}, jumpa lagi!\p"
	.string "Pelik sikit aku cakap macam ni, tapi aku\n"
	.string "rasa kau patut berlatih lebih keras\l"
	.string "untuk lain kali.$"

Route110_Text_BrendanLetsBattle:
	.string "BRENDAN: Hei, {PLAYER}.\n"
	.string "Rupanya kau di sini.\l"
	.string "Macam mana sekarang?\p"
	.string "Kau ada latih POKéMON kau?\n"
	.string "Biar aku tengokkan.$"

Route110_Text_BrendanDefeated:
	.string "Hmm…\n"
	.string "Boleh tahan juga kau.$"

Route110_Text_BrendanTakeThis:
	.string "BRENDAN: {PLAYER}, kau berlatih tanpa\n"
	.string "aku sedar…\p"
	.string "Bagus juga!\n"
	.string "Nah, ambil ni.$"

Route110_Text_BrendanExplainItemfinder:
	.string "BRENDAN: Itu PENGESAN.\p"
	.string "Guna untuk cari barang yang tak\n"
	.string "kelihatan.\p"
	.string "Kalau ia kesan sesuatu, ia akan\n"
	.string "berbunyi.\p"
	.string "Apa-apa pun, aku nak pergi cari POKéMON\n"
	.string "baru.$"

Route110_Text_RideBikeAtFullSpeed:
	.string "Bukan ke seronok kalau dapat tunggang\n"
	.string "BASIKAL selaju-lajunya di\l"
	.string "JALAN BASIKAL?$"

Route110_Text_HairStreamsBehindMe:
	.string "Macam mana, cantik tak rambut hitam\n"
	.string "legam saya beralun di belakang?\p"
	.string "Saya simpan rambut panjang\n"
	.string "semata-mata untuk itu.$"

Route110_Text_YouGotBikeFromRydel:
	.string "Oh, hei, kamu dapat BASIKAL tu daripada\n"
	.string "RYDEL!\p"
	.string "Oh, jelas sangat.\n"
	.string "Ada tertulis pada basikal kamu…\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
	.string "Nama tu ada di mana-mana.\p"
	.string "Kamu patut tunggang ke merata tempat,\n"
	.string "iklan yang bagus tu!$"

Route110_Text_TwoRoads:
	.string "Dua jalan, satu di atas, satu di bawah…\p"
	.string "Satu jalan untuk manusia dan satu\n"
	.string "untuk POKéMON. Mungkin itu adil.$"

Route110_Text_WalkOnTheLowRoad:
	.string "Saya tiada BASIKAL, jadi saya jalan\n"
	.string "santai saja di jalan bawah.$"

Route110_Text_BikeTechniques:
	.string "Belajar teknik akan buat tunggang\n"
	.string "BASIKAL lebih seronok.\p"
	.string "Ada tempat yang cuma boleh dicapai\n"
	.string "dengan teknik BASIKAL.$"

Route110_Text_WhichShouldIChoose:
	.string "Yang mana patut saya pilih?\p"
	.string "Terus pecut ke MAUVILLE di\n"
	.string "JALAN BASIKAL, atau ikut jalan bawah\l"
	.string "dan cari POKéMON?$"

Route110_Text_CyclingChallengeResultSummary:
	.string "Bilangan perlanggaran:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "Jumlah masa:\n"
	.string "… … {STR_VAR_2}!$"

Route110_Text_ChallengeReactionBest:
	.string "Bravo! Persembahan yang hebat!\p"
	.string "Cinta kamu pada berbasikal datang dari\n"
	.string "lubuk hati.\l"
	.string "Saya tersentuh hingga ke jiwa!$"

Route110_Text_ChallengeReactionGood:
	.string "Teknik kamu sangat mengagumkan.\p"
	.string "Saya cadangkan kamu laju sedikit sambil\n"
	.string "masih mengelak perlanggaran.$"

Route110_Text_ChallengeReactionOk:
	.string "Kamu masih belajar lagi, agaknya.\p"
	.string "Tapi jangan lupa betapa seronoknya\n"
	.string "berbasikal.$"

Route110_Text_ChallengeReactionBad:
	.string "Ya ampun… Kemahiran berbasikal kamu\n"
	.string "hampir menakutkan.\p"
	.string "Kamu memang perlukan lebih banyak\n"
	.string "latihan menunggang.$"

Route110_Text_ChallengeReactionWorst:
	.string "…Saya terkejut…\p"
	.string "Mungkin kamu tak sesuai untuk urusan\n"
	.string "berbasikal ni.\p"
	.string "Baik kamu fikir masak-masak, patut\n"
	.string "tak pulangkan BASIKAL tu kepada RYDEL.$"

Route110_Text_RatedForNumberOfCollisions:
	.string "Ini JALAN BASIKAL.\p"
	.string "Kalau kamu tunggang BASIKAL MACH dari\n"
	.string "MAUVILLE ke SLATEPORT, kamu akan\l"
	.string "dinilai ikut bilangan perlanggaran dan\l"
	.string "jumlah masa.$"

Route110_Text_AlwaysAimHigher:
	.string "Walau apa pun keputusannya, saya nak\n"
	.string "tengok lebih banyak cabaran daripada\l"
	.string "kamu. Sentiasa sasar lebih tinggi!$"

Route110_Text_AcroBikesDoNotQualify:
	.string "Di JALAN BASIKAL ni, penunggang\n"
	.string "BASIKAL MACH dinilai ikut bilangan\l"
	.string "perlanggaran dan jumlah masa.\p"
	.string "BASIKAL ACRO tak layak dinilai. Ia\n"
	.string "senang dibelok, jadi tak adil.$"

Route110_Text_SlateportCitySign:
	.string "LALUAN 110\n"
	.string "{DOWN_ARROW} BANDAR SLATEPORT$"

Route110_Text_CyclingRoadSign:
	.string "JALAN BASIKAL TEPI LAUT$"

Route110_Text_AquaWasHere:
	.string "“TEAM AQUA pernah di sini!”\p"
	.string "Ada orang cat ayat tu pada papan tanda\n"
	.string "ni, tapi orang lain cat atasnya pula.\p"
	.string "“TEAM MAGMA terbaik!” itulah yang\n"
	.string "tertulis sekarang.$"

Route110_Text_Route103Sign:
	.string "LALUAN 110\n"
	.string "{LEFT_ARROW} LALUAN 103$"

Route110_Text_SeasideParkingSign:
	.string "PARKIR TEPI LAUT$"

Route110_Text_MauvilleCitySign:
	.string "LALUAN 110\n"
	.string "{UP_ARROW} BANDAR MAUVILLE$"

Route110_Text_TrainerTipsPrlzSleep:
	.string "PETUA JURULATIH\p"
	.string "Musuh boleh jadi tak berdaya kalau\n"
	.string "dilumpuhkan atau ditidurkan.\p"
	.string "Ini teknik penting dalam pertarungan\n"
	.string "POKéMON.$"

Route110_Text_TrainerTipsRegisterItems:
	.string "PETUA JURULATIH\p"
	.string "Barang dalam BEG boleh disusun semula\n"
	.string "dengan menekan SELECT.$"

Route110_Text_TrickHouseSign:
	.string "“Tiga langkah {RIGHT_ARROW} dan dua langkah {UP_ARROW}\n"
	.string "ke RUMAH HELAH yang menakjubkan.”$"

Route110_Text_BestRecord:
	.string "REKOD TERBAIK SETAKAT INI…\p"
	.string "Bil. perlanggaran: {STR_VAR_1}\p"
	.string "Masa diambil: {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord:
	.string "REKOD TERBAIK SETAKAT INI…\p"
	.string "Nampaknya belum ada yang sahut\n"
	.string "cabaran. Tiada rekod…$"

Route110_Text_ImagineSeeingYouHere:
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "Tak sangka jumpa kamu di sini!\p"
	.string "Mana pula {RIVAL} saya?$"

Route110_Text_HeardYouInstallMatchCall:
	.string "Oh, begitu!\n"
	.string "Kamu berdua bergerak berasingan.\l"
	.string "Tak apalah.\p"
	.string "Oh, ya, saya dengar POKéNAV kamu dah\n"
	.string "dipasang sistem MATCH CALL.\p"
	.string "Kalau begitu, saya patut daftarkan\n"
	.string "kamu dalam POKéNAV saya juga.\p"
	.string "Dengan cara tu, walaupun berjauhan,\n"
	.string "saya boleh nilai POKéDEX kamu bila-bila\l"
	.string "masa.\p"
	.string "… … … … … …$"

Route110_Text_RegisteredBirchInPokenav:
	.string "PROF. BIRCH didaftarkan\n"
	.string "dalam POKéNAV.$"

Route110_Text_KeepAnEyeOutForRival:
	.string "PROF. BIRCH: {PLAYER}{KUN}…\p"
	.string "Tolong tengok-tengokkan {RIVAL} saya.\n"
	.string "… … … … … …\p"
	.string "Baiklah, saya patut pergi sekarang.\n"
	.string "Jumpa lagi, {PLAYER}{KUN}!$"

