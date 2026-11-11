BattleFrontier_BattlePikeRoomNormal_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomNormal_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp
	.byte 0

BattleFrontier_BattlePikeRoomNormal_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom::
	setvar VAR_TEMP_0, 1
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom::
	lockall
	delay 16
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle
BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle::
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom::
	lockall
	delay 16
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle::
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	applywaitmovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2, MSGBOX_DEFAULT
	closemessage
	release
	applywaitmovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom::
	delay 22
	lockall
	applywaitmovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer
	pike_prequeenheal
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon
	case 2, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons

BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy
	waitmovement 0
	playse SE_PIKE_CURTAIN_CLOSE
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed
	delay 4
	waitse
	delay 60
	playse SE_PIKE_CURTAIN_OPEN
	delay 65
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
	showobjectat LOCALID_PIKE_ROOM_NPC_1, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen
	waitse
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter
	pike_getbrainstatus
	switch VAR_RESULT
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy

BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_IWontForget, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy::
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside
	applywaitmovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
	pike_get PIKE_DATA_WIN_STREAK
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_WIN_STREAK, VAR_RESULT
	call BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom::
	lockall
	delay 16
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	message BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom::
	lockall
	delay 16
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer
	waitmovement 0
	applywaitmovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	delay 16
	applywaitmovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
	pike_gettrainerintro 1
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_DOUBLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle::
	applywaitmovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit
	applywaitmovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit
	applywaitmovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom::
	lockall
	message BattleFrontier_BattlePikeRoomNormal_Text_WatchOut
	applywaitmovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer
	pike_getstatusmon
	copyvar VAR_0x8004, VAR_RESULT
	call_if_eq VAR_0x8004, PIKE_STATUSMON_KIRLIA, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack
	call_if_eq VAR_0x8004, PIKE_STATUSMON_DUSCLOPS, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	pike_getstatus
	call_if_eq VAR_RESULT, PIKE_STATUS_TOXIC, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp
	call_if_eq VAR_RESULT, PIKE_STATUS_PARALYSIS, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave
	call_if_eq VAR_RESULT, PIKE_STATUS_SLEEP, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis
	pike_flashscreen
	waitstate
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
	applywaitmovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	pike_getstatus
	call_if_eq VAR_RESULT, PIKE_STATUS_FREEZE, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp
	pike_flashscreen
	waitstate
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
	applywaitmovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam::
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp::
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle::
	closemessage
	applywaitmovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	return

BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit:
	walk_up
	walk_up
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit:
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon:
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer:
	walk_down
	face_left
	delay_16
	delay_16
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_left
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC:
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside:
	walk_left
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer:
	walk_down
	walk_down
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1:
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp:
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight:
	walk_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft:
	walk_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer:
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	set_invisible
	walk_up
	step_end

@ For approaching Lucy and exiting room after defeating Lucy
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter:
	set_visible
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside:
	walk_left
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_EventScript_NPC::
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC
BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC::
	lock
	faceplayer
	pike_getnpcmsg
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC::
	pike_healonetwomons
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon
	playfanfare MUS_HEAL
	waitfanfare
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell, MSGBOX_DEFAULT
	closemessage
	release
	applywaitmovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon, MSGBOX_DEFAULT
	closemessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons, MSGBOX_DEFAULT
	closemessage
	return

@ Dusclops or Kirlia
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusMon::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_Silence, MSGBOX_DEFAULT
	closemessage
	release
	applywaitmovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage1_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage1_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage1_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage1_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage1_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage1_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage1_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage2_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage2_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage2_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage2_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage2_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage2_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage2_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage3_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage3_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage3_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage3_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage3_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage3_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage3_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage0_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage0_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage0_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage0_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage0_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage0_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage0_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp:
	walk_up
	walk_up
	step_end

@ Unused
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanDown:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth:
	.string "Selamat datang…\n"
	.string "Tuah kamu memang patut dipuji…\p"
	.string "POKéMON kamu akan dipulihkan\n"
	.string "sepenuhnya…$"

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge:
	.string "Nikmatilah baki cabaran\n"
	.string "Pilih Tarung kamu…$"

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon:
	.string "Ah, kamu memang bertuah.\n"
	.string "Saya agak gembira sekarang.\p"
	.string "Saya akan pulihkan seekor POKéMON\n"
	.string "kamu sepenuhnya.$"

BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell:
	.string "Semoga berjaya.\n"
	.string "Selamat tinggal.$"

@ Seems there was a planned room type where the player could choose to battle and would be healed if they won
@ Possibly replaced/superseded by the hard battle room, which is the same but the battle isnt optional
@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_CareForBattleWillRestoreMons:
	.string "Maafkan saya…\p"
	.string "Sudi bertarung dengan saya?\n"
	.string "POKéMON kamu dipulihkan jika menang.$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_NowShallWe:
	.string "Baiklah…\n"
	.string "Kita mulakan?$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_HowUnsportingOfYou:
	.string "Begitu…\n"
	.string "Tak sporting langsung kamu ni…$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreMonsAsPromised:
	.string "Hebat sekali…\p"
	.string "Seperti dijanjikan, saya akan pulihkan\n"
	.string "POKéMON kamu sepenuhnya.$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell2:
	.string "Semoga berjaya.\n"
	.string "Selamat tinggal.$"

BattleFrontier_BattlePikeRoomNormal_Text_WatchOut:
	.string "Alamak!\p"
	.string "Hati-hati!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop:
	.string "Sudah, sudah!\n"
	.string "KIRLIA, berhenti!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop:
	.string "Sudah, sudah!\n"
	.string "DUSCLOPS, berhenti!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic:
	.string "KIRLIA menggunakan TOKSIK!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis:
	.string "KIRLIA menggunakan HIPNOSIS!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave:
	.string "KIRLIA menggunakan GELOMBANG PETIR!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp:
	.string "KIRLIA menggunakan PELITA HANTU!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp:
	.string "DUSCLOPS menggunakan\n"
	.string "PELITA HANTU!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam:
	.string "DUSCLOPS menggunakan SINAR AIS!$"

BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough:
	.string "Hei!\n"
	.string "Cukuplah tu!$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia:
	.string "Saya minta maaf…\p"
	.string "KIRLIA saya bersifat PENAKUT…$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops:
	.string "Saya minta maaf…\p"
	.string "DUSCLOPS saya bersifat PENAKUT…$"

BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled:
	.string "Ia menyerang tanpa amaran jika\n"
	.string "dikejutkan oleh orang lain…\p"
	.string "Kamu dan POKéMON kamu tak apa-apa?$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine:
	.string "Saya betul-betul minta maaf…\n"
	.string "Saya harap POKéMON kamu tak apa-apa.$"

BattleFrontier_BattlePikeRoomNormal_Text_Silence:
	.string "… … … … … …\n"
	.string "… … … … … …$"

BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer:
	.string "Selamat datang…\p"
	.string "Di sini, kamu akan bertarung dengan\n"
	.string "JURULATIH yang agak hebat…$"

BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth:
	.string "Hebat sungguh…\p"
	.string "Sempena kemenangan kamu, POKéMON\n"
	.string "kamu akan dipulihkan sepenuhnya…$"

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2:
	.string "Nikmatilah baki cabaran\n"
	.string "Pilih Tarung kamu…$"

BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen:
	.string "Saya LUCY…\n"
	.string "Sayalah undang-undang di sini…\l"
	.string "Kerana sayalah PIKE QUEEN…\p"
	.string "Kamu sudah tahu, tapi untuk mara,\n"
	.string "kamu mesti kalahkan saya…\p"
	.string "…Saya tak suka berbual kosong.\n"
	.string "Cepat. Ayuh…$"

BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck:
	.string "Tuah kamu…\n"
	.string "Harap kamu tak habiskannya di sini…$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass:
	.string "LUCY: … … … … … …\n"
	.string "Tunjukkan PAS FRONTIER kamu…$"

BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol:
	.string "Simbol Tuah telah dicap pada\n"
	.string "PAS FRONTIER!$"

BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear:
	.string "…Itu saja…\n"
	.string "Pergilah…$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain:
	.string "LUCY: …Kamu lagi…\p"
	.string "… … … … … …\p"
	.string "…Saya pijak bunga dan redah ribut\n"
	.string "untuk sampai ke tahap ini…\p"
	.string "Saya tak rela terus kalah kepada\n"
	.string "lawan yang sama…\p"
	.string "… … … … … …\n"
	.string "Baiklah… Saya lawan…$"

BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn:
	.string "Sekarang!\n"
	.string "Ayuh!$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass:
	.string "LUCY: … … … … … …\p"
	.string "…PAS FRONTIER…$"

BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine:
	.string "Simbol Tuah kini bersinar\n"
	.string "keemasan!$"

BattleFrontier_BattlePikeRoomNormal_Text_IWontForget:
	.string "…Kamu, saya takkan lupa…\n"
	.string "…Selamanya…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal:
	.string "Selamat datang…\p"
	.string "Hihi…\n"
	.string "Nampaknya kamu tak bertuah…\p"
	.string "Kalaulah kamu tak pilih bilik ini,\n"
	.string "POKéMON kamu boleh dipulihkan…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne:
	.string "Selamat datang…\p"
	.string "Sebab kamu pilih bilik ini, saya\n"
	.string "akan pulihkan seekor POKéMON kamu…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo:
	.string "Selamat datang…\p"
	.string "Sebab kamu pilih bilik ini, saya\n"
	.string "akan pulihkan dua POKéMON kamu…$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreAllMons:
	.string "Selamat datang…\p"
	.string "Hihi…\n"
	.string "Bersyukurlah dengan tuah kamu…\p"
	.string "Sebab kamu pilih bilik ini,\n"
	.string "semua POKéMON kamu akan dipulihkan…$"

BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster:
	.string "Saya akan panggil tuan kami…$"

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons:
	.string "Ah, kamu memang bertuah!\n"
	.string "Saya gembira sekarang.\p"
	.string "Saya akan pulihkan dua POKéMON\n"
	.string "kamu sepenuhnya!$"

