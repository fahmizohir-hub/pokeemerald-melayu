RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
	.byte 0

RustboroCity_OnTransition:
	setflag FLAG_VISITED_RUSTBORO_CITY
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	end

RustboroCity_EventScript_PositionScientistForExit::
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 12, 15
	end

RustboroCity_EventScript_PositionScientistLeftExit::
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 11, 15
	end

RustboroCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

RustboroCity_OnFrame:
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
	.2byte 0

RustboroCity_EventScript_ScientistAddMatchCall::
	lockall
	setvar VAR_ROUTE104_STATE, 1
	applywaitmovement LOCALID_PLAYER, RustboroCity_Movement_PlayerWalkDown
	playse SE_EXIT
	delay 10
	addobject LOCALID_RUSTBORO_SCIENTIST
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_PleaseSelectPokenav::
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
	closemessage
	delay 10
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_MatchCallTutorial::
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	special ScriptMenu_CreateStartMenuForPokenavTutorial
	switch VAR_RESULT
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
	special OpenPokenavForTutorial
	delay 20
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistLeave
	playse SE_EXIT
	removeobject LOCALID_RUSTBORO_SCIENTIST
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	setvar VAR_RUSTBORO_CITY_STATE, 7
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

RustboroCity_Movement_ScientistWalkInPlaceDown:
	walk_in_place_down
	step_end

RustboroCity_Movement_PlayerWalkDown:
	walk_down
	step_end

RustboroCity_Movement_ScientistApproachPlayer:
	walk_down
	delay_16
	step_end

@ Unused
RustboroCity_Movement_ScientistWalkAroundPlayer:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_up
	delay_16
	step_end

RustboroCity_Movement_ScientistLeave:
	walk_up
	step_end

RustboroCity_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_FatManSawGrunt::
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_DevonEmployee2::
	lock
	faceplayer
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Woman::
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
	end

RustboroCity_EventScript_Man1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Man1HaveBadge::
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2BrineyLeftTunnel::
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Twin::
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
	end

RustboroCity_EventScript_NinjaBoy::
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
	end

RustboroCity_EventScript_TunnelSign::
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
	end

RustboroCity_EventScript_DevonCorpSign::
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_GymSign::
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

@ Unused
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign::
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TrainersSchoolSign::
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CuttersHouseSign::
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
	end

RustboroCity_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
	applywaitmovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
	applywaitmovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_EventScript_Man2::
	lock
	faceplayer
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_StolenGoodsTrigger0::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 0
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger1::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 1
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger2::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 2
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger3::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 3
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger4::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 4
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsScene::
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	addobject LOCALID_RUSTBORO_GRUNT
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
	applywaitmovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
	removeobject LOCALID_RUSTBORO_GRUNT
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
	fadedefaultbgm
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_DEVON_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 2
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
	setvar VAR_ROUTE116_STATE, 1
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	releaseall
	end

@ Unused
RustboroCity_EventScript_ShadyCharacterTookOff::
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	return

@ Unused
RustboroCity_EventScript_YouGotItThankYou::
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	return

@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
RustboroCity_EventScript_EmployeeApproachUp::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachLeft::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachRight::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachDown::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
	return

@ Unused, similar movement to the above scripts
RustboroCity_EventScript_EmployeeApproachPlayerFar::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

@ Unused
RustboroCity_Movement_GruntEscapeExtended:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_GruntEscape:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachUp:
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachLeft:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachRight:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachDown:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachPlayerFar:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

RustboroCity_EventScript_DevonEmployee1::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
	waitse
	setvar VAR_TEMP_1, 4
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_EmployeeAskToGetGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 3
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
	releaseall
	end

@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
RustboroCity_EventScript_EmployeeFacePlayerUp1::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft1::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceRight
	return

RustboroCity_EventScript_EmployeeFacePlayerDown1::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown1::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

RustboroCity_Movement_EmployeeApproachPlayerDown:
	walk_down
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setvar VAR_RUSTBORO_CITY_STATE, 5
	delay 30
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
	waitstate
	releaseall
	end

RustboroCity_EventScript_BagFull::
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_EmployeeFacePlayerUp2::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft2::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceLeft
	return

RustboroCity_EventScript_EmployeeFacePlayerDown2::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown2::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

RustboroCity_EventScript_EmployeeFacePlayerRight::
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	return

RustboroCity_EventScript_Rival::
	lockall
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_PlayRivalMusic::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
	return

RustboroCity_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

RustboroCity_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

RustboroCity_EventScript_RivalTrigger0::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger1::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger2::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger3::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger4::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger5::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger6::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger7::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	playse SE_PIN
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalEncounter::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
	end

RustboroCity_EventScript_MayEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_MayAskToBattle::
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleMay::
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMayTreecko
	case 1, RustboroCity_EventScript_BattleMayTorchic
	case 2, RustboroCity_EventScript_BattleMayMudkip
	end

RustboroCity_EventScript_MayBrineyHint::
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_RestoreBgm::
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

RustboroCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BrendanEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BrendanAskToBattle::
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleBrendan::
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
	end

RustboroCity_EventScript_BrendanBrineyHint::
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_Movement_RivalApproachPlayer0:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer2:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer3:
	walk_down
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer4:
	walk_down
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer5:
	walk_down
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer6:
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer7:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_EventScript_Boy1::
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
	end

RustboroCity_Text_WeShortenItToDevon:
	.string "DEVON CORPORATION… Kami semua panggil\n"
	.string "DEVON saja.\p"
	.string "Syarikat tu buat macam-macam produk\n"
	.string "yang memudahkan hidup.$"

RustboroCity_Text_SneakyLookingManWentAroundCorner:
	.string "Hm? Lelaki yang mencurigakan?\p"
	.string "Baru saya teringat, memang ada lelaki\n"
	.string "yang nampak macam orang jahat belok ke\l"
	.string "selekoh tu.$"

RustboroCity_Text_HaveYouChallengedGym:
	.string "Kamu dah sahut cabaran GIM POKéMON?\p"
	.string "Bila dah pegang LENCANA GIM yang\n"
	.string "berkilat tu, rasanya JURULATIH mula\l"
	.string "sedar apa yang diharapkan daripada\l"
	.string "mereka.$"

RustboroCity_Text_HeyThatsRustborosGymBadge:
	.string "Eh, itu LENCANA GIM RUSTBORO!\p"
	.string "Antara semua LENCANA GIM POKéMON,\n"
	.string "yang RUSTBORO paling segak, pada saya.$"

RustboroCity_Text_YoureNewAroundHere:
	.string "Oh? Kamu siapa? Muka baru di kawasan\n"
	.string "ni.\p"
	.string "Kamu baru masuk SEKOLAH JURULATIH\n"
	.string "POKéMON ke?$"

RustboroCity_Text_GymLeaderIsntEasyWithFire:
	.string "Saya dah cabar KETUA GIM, tapi…\p"
	.string "Bukan senang nak menang dengan\n"
	.string "POKéMON jenis API saya…\p"
	.string "POKéMON jenis API tak berapa sesuai\n"
	.string "lawan POKéMON jenis BATU…$"

RustboroCity_Text_MrBrineyWalksInTheTunnel:
	.string "Pelaut tua ENCIK BRINEY tinggal di\n"
	.string "pondok tepi laut.\p"
	.string "Sekali-sekala dia pergi berjalan-jalan\n"
	.string "dalam terowong tu.$"

RustboroCity_Text_MrBrineyLovesPeeko:
	.string "Pelaut tua ENCIK BRINEY tinggal di\n"
	.string "pondok tepi laut.\p"
	.string "Katanya dia nak ke SLATEPORT beli\n"
	.string "barang untuk PEEKO,\l"
	.string "haiwan peliharaannya.\p"
	.string "Pelaut tua tu mesti sayang betul\n"
	.string "pada PEEKO.$"

RustboroCity_Text_WowYouHavePokemon:
	.string "Wah, kamu pun ada POKéMON.\p"
	.string "Bila dah besar nanti, saya pun nak\n"
	.string "mengembara dengan POKéMON.$"

RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
	.string "SEKOLAH JURULATIH POKéMON!\p"
	.string "Kalau saya masuk sekolah ni, senang ke\n"
	.string "saya nak tangkap POKéMON nadir nanti?$"

RustboroCity_Text_PokemonCanChangeLookFromExp:
	.string "Kalau POKéMON dapat pengalaman dalam\n"
	.string "pertarungan, kadang-kadang rupanya\l"
	.string "boleh berubah.$"

RustboroCity_Text_PokemonChangeShape:
	.string "POKéMON berubah bentuk? Kalau betul,\n"
	.string "mesti saya terkejut!$"

RustboroCity_Text_TradePokemonGrowFast:
	.string "POKéMON yang kamu dapat hasil tukaran\n"
	.string "dengan orang lain cepat membesar.\p"
	.string "Tapi kalau kamu tak ada LENCANA GIM\n"
	.string "tertentu, ia mungkin tak patuh\l"
	.string "pada kamu…$"

RustboroCity_Text_OutOfTheWay:
	.string "Ke tepi! Jangan halang jalan!$"

RustboroCity_Text_WaitDontTakeMyGoods:
	.string "Tunggu! Tolonglaaah!\p"
	.string "Jangan ambil BARANG saya!$"

RustboroCity_Text_HelpMeIWasRobbed:
	.string "Oh, kamu rupanya!\p"
	.string "Kamulah JURULATIH hebat yang tolong\n"
	.string "saya di HUTAN PETALBURG!\p"
	.string "Tolong saya! Saya dirompak TEAM AQUA!\n"
	.string "Saya mesti dapatkan balik\l"
	.string "BARANG DEVON!\p"
	.string "Kalau tak… Habislah saya.$"

RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
	.string "Orang yang mencurigakan tu, rasanya\n"
	.string "dia lari ke arah terowong di sana.$"

RustboroCity_Text_YouGotItThankYou:
	.string "Oh! Macam mana? BARANG DEVON tu?\p"
	.string "Kamu berjaya! Kamu dapat balik!\p"
	.string "Kamu memang JURULATIH yang hebat!\p"
	.string "Haa! Sebagai tanda terima kasih, saya\n"
	.string "beri kamu satu lagi GREAT BALL!$"

RustboroCity_Text_YoureLoadedWithItems:
	.string "Barang kamu dah penuh. Saya tak dapat\n"
	.string "bagi GREAT BALL ni.$"

RustboroCity_Text_PleaseComeWithMe:
	.string "Maaf ganggu! Tolong ikut saya!$"

RustboroCity_Text_MayHiLetsRegister:
	.string "MAY: Oh, hai, {PLAYER}{KUN}!\p"
	.string "POKéNAV kau dah dipasang ciri\n"
	.string "MATCH CALL!\p"
	.string "Jom daftar nama masing-masing supaya\n"
	.string "boleh berhubung bila-bila masa!\p"
	.string "… … … … … …$"

RustboroCity_Text_RegisteredMay:
	.string "MAY didaftarkan\n"
	.string "dalam POKéNAV.$"

RustboroCity_Text_MayPassedBrineyWantToBattle:
	.string "MAY: Oh ya, aku terserempak ENCIK\n"
	.string "BRINEY di HUTAN PETALBURG.\p"
	.string "Rasanya dia dalam perjalanan balik ke\n"
	.string "pondoknya di tepi laut.\p"
	.string "Macam mana POKéDEX kau,\n"
	.string "{PLAYER}{KUN}? Aku punya dah boleh tahan!\p"
	.string "Jadi… Apa kata kita bertarung sikit?$"

RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
	.string "MAY: Eh, kenapa ni?\p"
	.string "Kau tak banyak tangkap atau latih\n"
	.string "POKéMON kau ke?\p"
	.string "Tak elok macam tu, kau kan JURULATIH!$"

RustboroCity_Text_MayWantToBattle:
	.string "MAY: Jadi, macam mana? Nak bertarung\n"
	.string "sikit di sini?$"

RustboroCity_Text_MayImNotGoingToLose:
	.string "MAY: Kau baru jadi JURULATIH,\n"
	.string "{PLAYER}{KUN}. Aku takkan kalah!$"

RustboroCity_Text_MayDefeat:
	.string "Alamak! Kau lebih hebat dari jangkaan\n"
	.string "aku!$"

RustboroCity_Text_MayMrBrineyHint:
	.string "MAY: Oh ya, ENCIK BRINEY yang aku jumpa\n"
	.string "tadi…\p"
	.string "{PLAYER}{KUN}, kau baru pindah ke\n"
	.string "sini jadi mungkin tak tahu, tapi\l"
	.string "ENCIK BRINEY dulu pelaut yang\l"
	.string "sangat dihormati.$"

RustboroCity_Text_BrendanHiLetsRegister:
	.string "BRENDAN: Oh, hei, {PLAYER}!\p"
	.string "POKéNAV kau dah dipasang ciri MATCH\n"
	.string "CALL! Hebat!\p"
	.string "Jom daftar nama masing-masing supaya\n"
	.string "boleh berhubung bila-bila masa!\p"
	.string "… … … … … …$"

RustboroCity_Text_RegisteredBrendan:
	.string "BRENDAN didaftarkan\n"
	.string "dalam POKéNAV.$"

RustboroCity_Text_BrendanPassedBrineyWantToBattle:
	.string "BRENDAN: Oh ya, {PLAYER}, aku\n"
	.string "terserempak ENCIK BRINEY di\l"
	.string "HUTAN PETALBURG.\p"
	.string "Mesti dia dalam perjalanan balik ke\n"
	.string "pondoknya di tepi laut.\p"
	.string "{PLAYER}, macam mana POKéDEX kau? Dah\n"
	.string "ada isi ke belum?\p"
	.string "Aku punya memang power.\p"
	.string "Nak bertarung untuk uji sejauh mana\n"
	.string "kau dah maju?$"

RustboroCity_Text_BrendanNoConfidenceInPokemon:
	.string "BRENDAN: Kenapa? Tak yakin dengan\n"
	.string "POKéMON kau?$"

RustboroCity_Text_BrendanWantToBattle:
	.string "BRENDAN: Apa cerita? Nak bertarung\n"
	.string "dengan aku?$"

RustboroCity_Text_BrendanIWontGoEasy:
	.string "BRENDAN: Aku tahu kau baru jadi\n"
	.string "JURULATIH, tapi aku takkan berlembut!$"

RustboroCity_Text_BrendanDefeat:
	.string "Hmm… Kau boleh tahan juga.$"

RustboroCity_Text_BrendanMrBrineyHint:
	.string "BRENDAN: Oh ya, kau kenal ENCIK BRINEY?\n"
	.string "Orang yang aku jumpa tadi?\p"
	.string "Mesti kau tak tahu, sebab kau baru\n"
	.string "pindah ke sini, {PLAYER}, tapi\l"
	.string "ENCIK BRINEY dulu pelaut yang hebat.$"

RustboroCity_Text_TunnelNearingCompletion:
	.string "“Terowong jalan pintas hampir siap!”\p"
	.string "…Begitulah tulisan pada papan tanda,\n"
	.string "tapi ada pangkah “X” besar dicat merah\l"
	.string "di atasnya…$"

RustboroCity_Text_DevonCorpSign:
	.string "DEVON CORPORATION\p"
	.string "“Untuk semua keperluan hidup anda,\n"
	.string "kami buat semuanya.”$"

RustboroCity_Text_GymSign:
	.string "GIM POKéMON BANDAR RUSTBORO\n"
	.string "KETUA: ROXANNE\p"
	.string "“Pelajar cemerlang yang cintakan\n"
	.string "BATU!”$"

RustboroCity_Text_DevonCorpBranchOfficeSign:
	.string "PEJABAT CAWANGAN DEVON CORP.\p"
	.string "“Akses terhad kepada pekerja DEVON\n"
	.string "dan kakitangan yang dibenarkan.”$"

RustboroCity_Text_CitySign:
	.string "BANDAR RUSTBORO\p"
	.string "“Bandar yang meneroka penyatuan alam\n"
	.string "dan sains.”$"

RustboroCity_Text_TrainersSchoolSign:
	.string "SEKOLAH JURULATIH POKéMON\p"
	.string "“Kami ajar apa saja tentang POKéMON!”$"

RustboroCity_Text_CuttersHouse:
	.string "RUMAH PENEBANG$"

RustboroCity_Text_DevelopedNewPokenavFeature:
	.string "Saya tengah bangunkan ciri tambahan\n"
	.string "untuk POKéNAV…\p"
	.string "Dan hasilnya memang menjadi!\p"
	.string "{PLAYER}, boleh saya tengok POKéNAV tu?\n"
	.string "Yang PRESIDEN kami bagi tu?$"

RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
	.string "Siap, {PLAYER}!\p"
	.string "Saya dah tambah ciri baru bernama\n"
	.string "MATCH CALL pada POKéNAV kamu.\p"
	.string "Dengan ciri MATCH CALL, kamu boleh\n"
	.string "berbual dengan orang yang didaftarkan\l"
	.string "dalam POKéNAV kamu.\p"
	.string "{PLAYER}, PRESIDEN STONE kami mesti dah\n"
	.string "ada dalam POKéNAV kamu.\p"
	.string "Cubalah. Telefon PRESIDEN kami.$"

RustboroCity_Text_PleaseSelectPokenav:
	.string "Sila pilih POKéNAV.$"

RustboroCity_Text_IdBetterGetBackToWork:
	.string "Okey, baik saya sambung kerja. Jaga\n"
	.string "diri, {PLAYER}!$"

RustboroCity_Text_YouCanHave2On2Battle:
	.string "Kamu tahu tak?\p"
	.string "Kamu boleh bertarung 2 lawan 2 walaupun\n"
	.string "kamu tak berteman.\p"
	.string "Kalau dua JURULATIH nampak kamu bila\n"
	.string "kamu ada dua atau lebih POKéMON,\l"
	.string "kedua-duanya akan mencabar kamu.\p"
	.string "Hebat, kan, kalau kamu boleh kalahkan\n"
	.string "dua JURULATIH seorang diri?$"
