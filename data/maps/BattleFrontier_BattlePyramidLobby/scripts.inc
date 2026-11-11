BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applywaitmovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	applywaitmovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "Di sinilah keberanian para JURULATIH\n"
	.string "diuji!\p"
	.string "Selamat datang ke BATTLE PYRAMID!\p"
	.string "Saya pemandu\n"
	.string "Misi Tarung.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "Kamu berani menyahut cabaran\n"
	.string "Misi Tarung?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Kami menanti cabaran kamu lain kali!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "Dalam Misi Tarung, kamu mesti\n"
	.string "meneroka PYRAMID dan cuba\l"
	.string "sampai ke puncak.\p"
	.string "Dalam PYRAMID ada tujuh tingkat\n"
	.string "labirin, yang penuh dengan JURULATIH\l"
	.string "mahir dan juga POKéMON liar.\p"
	.string "Kamu mesti masuk dengan tiga POKéMON,\n"
	.string "tanpa sebarang barang dipegang.\p"
	.string "Semasa mendaki, kamu akan diberi\n"
	.string "BEG TARUNG untuk barang.\p"
	.string "Jika kamu gagal, semua barang dalam\n"
	.string "BEG TARUNG akan hilang.\p"
	.string "Jika mahu berhenti di tengah\n"
	.string "cabaran, kamu mesti pilih “REHAT”\l"
	.string "dan simpan permainan.\p"
	.string "Jika tak simpan sebelum berhenti,\n"
	.string "penyertaan kamu akan dibatalkan.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "PYRAMID ada dua laluan,\n"
	.string "LV. 50 dan LV. TERBUKA.\l"
	.string "Yang mana kamu mahu masuk?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Bagus. Sekarang, sila pilih tiga\n"
	.string "POKéMON yang akan menemani kamu.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Ada sedikit masalah, pengembara!\p"
	.string "Nampaknya kamu tiada tiga POKéMON\n"
	.string "yang layak untuk cabaran ini.\p"
	.string "Ingat juga untuk ambil semua\n"
	.string "barang daripada POKéMON kamu.\p"
	.string "TELUR{STR_VAR_1}tidak layak.\p"
	.string "Bila kamu dah sedia, datang\n"
	.string "jumpa saya.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "Ada sedikit masalah, pengembara!\p"
	.string "Nampaknya kamu tiada tiga POKéMON\n"
	.string "yang layak untuk cabaran ini.\p"
	.string "Tiga POKéMON itu mesti berlainan\n"
	.string "dan tidak melebihi Tahap 50.\p"
	.string "Ingat juga untuk ambil semua\n"
	.string "barang daripada POKéMON kamu.\p"
	.string "TELUR{STR_VAR_1}tidak layak.\p"
	.string "Bila kamu dah sedia, datang\n"
	.string "jumpa saya.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Sebelum masuk BATTLE PYRAMID,\n"
	.string "permainan mesti disimpan. Boleh?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Bagus. Saya akan bawa kamu masuk\n"
	.string "ke BATTLE PYRAMID sekarang.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Kami akan jaga BEG kamu, {PLAYER},\n"
	.string "sementara kamu meneroka.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "Sebagai ganti, ambil BEG TARUNG ini,\n"
	.string "iaitu yang kamu guna sebelum ini.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "Sebagai ganti, sila ambil\n"
	.string "BEG TARUNG ini.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} menukar BEG dengan\n"
	.string "BEG TARUNG.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Bila kamu pijak panel lantai ini,\n"
	.string "kamu akan dibawa ke tingkat yang\l"
	.string "lebih tinggi dalam PYRAMID.\p"
	.string "Saya harap pengembaraan kamu\n"
	.string "selamat!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Masalah besar, penjelajah!\p"
	.string "Kamu tidak simpan sebelum menamatkan\n"
	.string "cabaran kamu pada kali lepas.\p"
	.string "Dengan kesalnya, penyertaan kamu\n"
	.string "dalam cabaran itu dibatalkan.\p"
	.string "Ini BEG yang kami jaga\n"
	.string "untuk kamu.\p"
	.string "{PLAYER} mendapat semula BEG.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Gembira tengok kamu kembali!\p"
	.string "Kamu berjaya menakluk PYRAMID!\n"
	.string "Hebat sungguh!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Ah, ada sedikit masalah.\p"
	.string "Sekurang-kurangnya seekor POKéMON\n"
	.string "sedang memegang barang.\p"
	.string "Maaf, barang yang diperoleh dalam\n"
	.string "PYRAMID tidak boleh dibawa keluar.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Semua barang pegangan POKéMON kamu\n"
	.string "akan dipindah ke BEG TARUNG, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "Maaf, BEG TARUNG tidak dapat muat\n"
	.string "semua barang kamu.\p"
	.string "Sila pilih barang yang mahu disimpan\n"
	.string "dalam BEG TARUNG dan pada POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Sekurang-kurangnya seekor POKéMON\n"
	.string "masih memegang barang.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Sila pilih barang yang mahu disimpan\n"
	.string "dalam BEG TARUNG dan pada POKéMON.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} memulangkan semua barang\n"
	.string "yang dipegang POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "BEG TARUNG yang kamu guna disimpan\n"
	.string "untuk cabaran kamu yang seterusnya.\p"
	.string "{PLAYER} menyerahkan BEG TARUNG\n"
	.string "dan menerima semula BEG.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "Saya perlu rekodkan keputusan kamu.\n"
	.string "Sila tunggu.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "Sebagai kenangan menakluk\n"
	.string "BATTLE PYRAMID, sila ambil ini.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} menerima hadiah\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…Ah…\n"
	.string "Nampaknya BEG kamu dah penuh.\p"
	.string "Sila datang semula selepas kamu\n"
	.string "kemaskan isi BEG kamu.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Sayang sekali…\p"
	.string "Ini BEG yang kami jaga\n"
	.string "untuk kamu.\p"
	.string "{PLAYER} mendapat semula BEG.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Kami nantikan cabaran kamu\n"
	.string "yang seterusnya!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "Kami memang nantikan\n"
	.string "kedatangan kamu!\p"
	.string "Ini hadiah kamu kerana menakluk\n"
	.string "PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Selamat datang…\p"
	.string "Biar saya ramalkan nasib malang\n"
	.string "yang menanti kamu di PYRAMID…$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "Aah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Saya nampak percikan api elektrik…\p"
	.string "…Dan di dalamnya, POKéMON kamu\n"
	.string "bergelut kerana lumpuh…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Saya nampak racun…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita kesan racun…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Saya nampak api merah menyala…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita kerana terbakar…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Saya rasa tekanan dahsyat daripada\n"
	.string "kemarahan yang terpendam…\p"
	.string "Ia satu sumpahan…\p"
	.string "…Dan, saya nampak PP POKéMON kamu\n"
	.string "habis dikuras hingga tiada pilihan\l"
	.string "selain guna MERONTA…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Saya nampak POKéMON melayang tinggi…\p"
	.string "…Dan, saya nampak POKéMON kamu kecewa\n"
	.string "kerana move jenis TANAH tak berkesan…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Saya rasa tenaga dahsyat naik dari\n"
	.string "tanah di bawah…\p"
	.string "…Dan, saya nampak POKéMON kamu tak\n"
	.string "dapat lepas dari cengkaman kuasa itu…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Saya nampak POKéMON jenis AIS…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "melawan kesan beku ais…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Saya nampak rentetan move yang\n"
	.string "membahayakan penggunanya…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "tumbang kerananya…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Saya nampak POKéMON jenis PSIKIK…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "terseksa oleh move PSIKIK…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Saya nampak POKéMON jenis BATU…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita akibat move BATU…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Saya nampak POKéMON jenis LAWAN…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "dibelasah oleh move LAWAN…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "TARIAN HUJAN… HARI CERAH…\n"
	.string "RIBUT PASIR… HUJAN BATU…\p"
	.string "Saya nampak POKéMON yang jadi lebih\n"
	.string "kuat mengikut cuaca…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "keliru dengan pelbagai jenis move…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Saya nampak POKéMON jenis SERANGGA…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita pelbagai jenis serangan…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Saya nampak POKéMON jenis GELAP…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita akibat move jenis GELAP…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Saya nampak POKéMON jenis AIR…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita akibat move jenis AIR…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Saya nampak POKéMON jenis HANTU…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita akibat move jenis HANTU…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Saya nampak POKéMON jenis BESI…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita akibat move yang amat kuat…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Saya nampak POKéMON yang terbang…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita akibat move yang amat kuat…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Saya nampak mereka yang berevolusi\n"
	.string "dengan kuasa batu…\p"
	.string "Saya juga rasa api, air,\n"
	.string "dan elektrik…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita akibat tiga kuasa itu…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Saya nampak POKéMON jenis NORMAL…\p"
	.string "…Dan, saya nampak POKéMON kamu\n"
	.string "menderita akibat move yang amat kuat…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Sama ada kamu percaya ramalan saya\n"
	.string "atau tidak, terpulang kepada kamu…\p"
	.string "Masa depan boleh berubah bila-bila…\n"
	.string "Semoga perjalanan kamu selamat…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "Kamu tahu tak?\p"
	.string "Kalau kamu berlari laju, JURULATIH\n"
	.string "mungkin perasan dan kejar kamu.\p"
	.string "Jadi, kalau mahu elak JURULATIH,\n"
	.string "jangan sampai mereka nampak kamu.\l"
	.string "Lalu perlahan-lahan, senyap-senyap.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Awaaaaaaarrrrgh!\p"
	.string "Saya ada banyak barang, tapi semuanya\n"
	.string "hilang bila saya kalah!\p"
	.string "Awaaaaaaarrrrgh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Selamat kembali!\n"
	.string "Kamu buat sesuatu yang luar biasa!\p"
	.string "Kamu menewaskan PYRAMID KING\n"
	.string "dan menakluk BATTLE PYRAMID!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Wahai penjelajah muda!\n"
	.string "Sebagai pujian atas keberanian kamu,\l"
	.string "kami berikan Mata Tarung ini!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Ini peraturan Misi Tarung.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Tajuk mana yang kamu mahu baca?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Bila PYRAMID ditakluk, POKéMON\n"
	.string "liar yang muncul di dalamnya\l"
	.string "akan diganti dengan jenis lain.\p"
	.string "Teroka, perhati dan kenal pasti\n"
	.string "POKéMON liar yang mungkin kamu temui.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "JURULATIH sedang menunggu kamu\n"
	.string "di dalam PYRAMID.\p"
	.string "Di setiap tingkat, ada sehingga\n"
	.string "lapan JURULATIH.\p"
	.string "Bila kamu tewaskan JURULATIH, kamu\n"
	.string "akan dapat petunjuk yang berguna.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Labirin dalam PYRAMID akan berubah\n"
	.string "setiap kali kamu masuk.\p"
	.string "Labirin itu malap.\n"
	.string "Kamu mesti mara dengan berhati-hati.\p"
	.string "Cahaya makin terang setiap kali kamu\n"
	.string "tewaskan POKéMON liar atau JURULATIH.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "BEG TARUNG berfungsi sebagai BEG\n"
	.string "kamu semasa dalam PYRAMID.\p"
	.string "Ada dua BEG TARUNG berasingan--\n"
	.string "satu untuk pengembaraan LV. 50 dan\l"
	.string "satu untuk LV. TERBUKA.\p"
	.string "Setiap satu boleh muat sehingga 99\n"
	.string "unit bagi sepuluh jenis barang.\p"
	.string "Isi BEG TARUNG akan hilang jika\n"
	.string "kamu gagal dalam misi kamu.$"

