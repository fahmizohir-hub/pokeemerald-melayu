SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applywaitmovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	delay 10
	applywaitmovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceUp
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Sayalah GURU TENAGA! Saya akan\n"
	.string "berusaha dan jual apa yang kamu\l"
	.string "perlukan!$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh?\n"
	.string "{STR_VAR_1} kamu…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Ia dah berusaha bersungguh-sungguh!\p"
	.string "Sebagai ganjaran, berikan ia REBEN\n"
	.string "USAHA ni.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} menerima REBEN USAHA.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} memakaikan REBEN USAHA\n"
	.string "pada {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Kamu kena berusaha lebih keras sikit.\p"
	.string "Kalau kamu buat begitu, saya akan bagi\n"
	.string "POKéMON kamu sesuatu yang bagus.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! {STR_VAR_1} kamu, REBEN USAHA tu\n"
	.string "nampak sesuai padanya!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "Cahaya rumah api tu sampai\n"
	.string "berpuluh-puluh batu jauhnya.\p"
	.string "Agaknya ia tak mengejutkan POKéMON di\n"
	.string "laut ke?$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Ooh, tengok ni!\p"
	.string "Rumpai laut di kawasan ni segar dan\n"
	.string "penuh kehidupan.\p"
	.string "Wah, macam boleh bangun dan menyerang\n"
	.string "pula!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Di mana airnya bersih, di situlah hasil\n"
	.string "tuaian melimpah ruah.\p"
	.string "Dan di mana orang berkumpul, tak lama\n"
	.string "kemudian pasar pun bermula.\p"
	.string "Begitulah sebuah pekan lahir dan\n"
	.string "berkembang.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Membeli-belah sambil menghidu bau laut…\p"
	.string "SLATEPORT memang tempat yang indah!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Kalau letak PATUNG atau KUSYEN atas\n"
	.string "lantai, nanti kotor.\p"
	.string "Saya nak beli BATA supaya PATUNG dan\n"
	.string "KUSYEN saya tak kotor bila saya biarkan\l"
	.string "di luar.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Wroooar! Saya pun nak bertanding di\n"
	.string "KHEMAH BATTLE!\p"
	.string "Tapi sebelum tu, saya kena tangkap\n"
	.string "POKéMON dulu!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Fuh… Penatnya saya…\p"
	.string "Saya berjalan kaki dari\n"
	.string "BANDAR MAUVILLE. Tapi wah, besarnya\l"
	.string "bandar ni.\p"
	.string "Kalau saya tahu, baik saya naik\n"
	.string "BASIKAL ke sini.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, orang yang bina MUZIUM tu, juga\n"
	.string "ketua pasukan penjelajahan dasar laut.\p"
	.string "Jadi, semua orang panggil dia\n"
	.string "KAPT. STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Apa tu di sana?\n"
	.string "Barisan panjang tu…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Masa kecil dulu, saya selalu melawat\n"
	.string "MUZIUM.\p"
	.string "Saya selalu mengimpikan misteri lautan\n"
	.string "selepas tengok pameran di sana.$"

SlateportCity_Text_QuitPushing:
	.string "Hei, kau! Jangan tolak-tolak!\n"
	.string "Ini barisan, tak nampak ke?$"

SlateportCity_Text_AquaHasPolicy:
	.string "TEAM AQUA ada polisi berkumpul dan\n"
	.string "bersurai di tempat operasi.$"

SlateportCity_Text_BossIsBrilliant:
	.string "BOS kami memang bijak.\p"
	.string "Apa agaknya yang dia nak buat dengan\n"
	.string "MUZIUM sekarang?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Apa agaknya rancangan baru tu?\p"
	.string "BOS kami menakutkan bila marah, jadi\n"
	.string "baik aku jangan buat silap…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Kalau ada benda yang kita perlukan\n"
	.string "dalam MUZIUM, kita patut ambil\l"
	.string "semuanya!$"

SlateportCity_Text_DontButtIn:
	.string "Hei, kau!\n"
	.string "Jangan potong barisan!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Barisan panjang, ya?\p"
	.string "Teringat masa saya beratur nak beli\n"
	.string "game yang meletup…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Kenapa kita beratur dan bayar pula?\n"
	.string "Kita patut terus serbu masuk!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Apa?\n"
	.string "Kau nak apa?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Kamu nak baca papan tanda ni?\n"
	.string "Biar saya bacakan!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Hmm, kejap…\p"
	.string "Err… Rasanya tertulis lebih kurang\n"
	.string "“kehidupan di laut tiada penghujung.”\p"
	.string "Ya, saya agak pasti itulah yang\n"
	.string "tertulis.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Rungut…\p"
	.string "Patutnya saya bawa Game Boy Advance\n"
	.string "saya supaya tak bosan beratur…\p"
	.string "Rungut…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Bila operasi ni selesai, aku bawa kau\n"
	.string "pergi spa air panas!\p"
	.string "Itu yang ketua kami cakap.\n"
	.string "Tak sabarnya!$"

SlateportCity_Text_SeaIsSoWet:
	.string "Laut ni luas sangat…\p"
	.string "Mungkinkah laut terjadi daripada air\n"
	.string "mata yang dititiskan POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Kamu tahu apa mereka buat dengan kapal\n"
	.string "lama yang dah terlalu usang untuk\l"
	.string "belayar?\p"
	.string "Mereka tenggelamkan di laut supaya\n"
	.string "jadi habitat POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Setiap kali datang sini, saya terleka\n"
	.string "dan beli terlalu banyak.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Kalau kamu nak tukar nama timangan\n"
	.string "POKéMON kamu, kamu kena minta tolong\l"
	.string "PENILAI NAMA.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "POKéMON yang kamu dapat melalui\n"
	.string "tukaran, nama timangannya tak boleh\l"
	.string "ditukar.\p"
	.string "Kasih sayang JURULATIH asal pada\n"
	.string "POKéMON tu ada dalam nama timangannya.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Baru-baru ni, sebuah KHEMAH BATTLE\n"
	.string "dibina di SLATEPORT.\p"
	.string "GIM memang seronok, tapi KHEMAH BATTLE\n"
	.string "pun hebat dengan caranya sendiri.\p"
	.string "Kamu patut cari POKéMON yang kuat\n"
	.string "untuk KHEMAH BATTLE!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Saya ingatkan artis terkenal, bolehlah\n"
	.string "saya minta autograf.\p"
	.string "Tapi siapa yang sedang ditemu bual tu?\n"
	.string "Bukan ke itu KAPT. STERN?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Wanita yang menemu bual tu sangat\n"
	.string "bergaya dan cantik.\p"
	.string "Bila besar nanti, saya nak jadi wartawan\n"
	.string "antarabangsa!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "KAPT. STERN kata mereka jumpa sesuatu\n"
	.string "di dasar laut.\p"
	.string "Apa agaknya?\n"
	.string "Apa benda tu, ya?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Apa yang berlaku di sini?\p"
	.string "KAPTEN kita yang baik tu balik bawa\n"
	.string "ikan besar dari dasar laut ke?$"

SlateportCity_Text_AmIOnTV:
	.string "Hei! Kamu tengok tak?\n"
	.string "Saya masuk TV ke?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Temu bual TV! Di sini!\n"
	.string "KAPTEN tu dah jadi selebriti!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: Okey, KAPT. STERN, senyum lebar\n"
	.string "untuk kamera!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY: Begitu, begitu. Pengalaman yang\n"
	.string "sangat berharga…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "KAPT. STERN: Ya, betul. Kami bercadang\n"
	.string "untuk teruskan penjelajahan kami.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY: Hebat sekali, KAPT. STERN!\n"
	.string "Terima kasih kerana meluangkan masa\l"
	.string "daripada jadual sibuk untuk bercakap\l"
	.string "dengan kami.\p"
	.string "Kami harap dapat temu bual tuan lagi\n"
	.string "dengan berita penemuan baru!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "KAPT. STERN: Fuh…\p"
	.string "Itu kali pertama saya masuk\n"
	.string "TV. Berdebar betul.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh! {PLAYER}{KUN}!\n"
	.string "Kamu nampak sihat!\p"
	.string "Kami buat penemuan besar dalam\n"
	.string "penjelajahan dasar laut yang lepas.\p"
	.string "Kami jumpa gua bawah air di LALUAN 128.\p"
	.string "Kami rasa ia habitat POKéMON yang\n"
	.string "dikatakan dah lama pupus.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu…\n"
	.string "KAPT. STERN, kan?\p"
	.string "Kami TEAM AQUA akan ambil alih kapal\n"
	.string "selam kau!\p"
	.string "Tak guna kau membantah!\n"
	.string "Kami mahu kerjasama penuh daripada\l"
	.string "kau!\p"
	.string "Fufufu…\n"
	.string "Tengok sajalah apa yang TEAM\l"
	.string "AQUA dah rancang!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "KAPT. STERN: Apa semua tu?\p"
	.string "Bunyinya macam ada orang guna\n"
	.string "pembesar suara…\p"
	.string "Dari mana datangnya?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Dari PELABUHAN!\p"
	.string "Kapal selam tu!\n"
	.string "Mereka cuba rampas!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "Tolong, ikut saya!$"

SlateportCity_Text_BattleTentSign:
	.string "KHEMAH BATTLE SLATEPORT\n"
	.string "“Carilah! POKéMON yang terunggul!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "LIMBUNGAN STERN\p"
	.string "“Dicari: Kelasi yang mampu belayar dalam\n"
	.string "semua arus.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "LIMBUNGAN STERN\p"
	.string "“Feri S.S. TIDAL hampir siap untuk\n"
	.string "berkhidmat di pelabuhan SLATEPORT dan\l"
	.string "LILYCOVE.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "LIMBUNGAN STERN\p"
	.string "“Menaiki feri S.S. TIDAL\n"
	.string "SLATEPORT-LILYCOVE diuruskan di\l"
	.string "PELABUHAN.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "KELAB PEMINAT POKéMON\n"
	.string "“Menyeru semua peminat POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“Laut yang tiada penghujung menyokong\n"
	.string "semua kehidupan.”\p"
	.string "MUZIUM LAUTAN$"

SlateportCity_Text_CitySign:
	.string "BANDAR SLATEPORT\p"
	.string "“Pelabuhan tempat manusia dan POKéMON\n"
	.string "bertemu.”$"

SlateportCity_Text_MarketSign:
	.string "PASAR SLATEPORT\n"
	.string "“Barang unik yang tiada di tempat\l"
	.string "lain!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "PELABUHAN SLATEPORT\p"
	.string "“Feri S.S. TIDAL sedang dibina di\n"
	.string "LIMBUNGAN.\p"
	.string "“Perkhidmatan dijadualkan bermula\n"
	.string "tidak lama lagi.”$"

SlateportCity_Text_HarborSign:
	.string "PELABUHAN SLATEPORT\p"
	.string "“Nikmati pelayaran yang menyeronokkan\n"
	.string "dengan feri S.S. TIDAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "RUMAH PENILAI NAMA\n"
	.string "“Nama timangan POKéMON dinilai.”$"

SlateportCity_Text_ExplainBerries:
	.string "Kalau POKéMON liar cedera, ia sembuhkan\n"
	.string "diri dengan mengunyah BERRY.\p"
	.string "Kamu tahu tak?\p"
	.string "Ada orang nampak hal tu dan dapat idea\n"
	.string "untuk buat ubat daripada BERRY.\p"
	.string "Kamu tahu tak?\p"
	.string "Untuk jadikan BERRY sebagai ubat, ia\n"
	.string "mesti dihancurkan jadi serbuk.\p"
	.string "Kamu tahu tak?\p"
	.string "Kamu nampak berminat dengan BERRY!\p"
	.string "Saya ada sesuatu yang bagus untuk\n"
	.string "orang macam kamu.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Baru-baru ni saya pasang mesin di\n"
	.string "PUSAT POKéMON untuk menghancurkan\l"
	.string "BERRY.\p"
	.string "Mesin HANCUR BERRY ada di SUDUT TERUS\n"
	.string "di tingkat atas.\p"
	.string "Kamu tahu tak?\p"
	.string "Boleh kamu buatkan SERBUK BERRY untuk\n"
	.string "saya guna mesin tu?\p"
	.string "Saya boleh buatkan macam-macam ubat\n"
	.string "kalau kamu bawa banyak SERBUK BERRY.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Kamu ada bawa SERBUK BERRY untuk\n"
	.string "saya?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Kamu nak tukar dengan apa?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Baiklah, kamu nak tukar SERBUK BERRY\n"
	.string "kamu dengan satu {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Alamak. SERBUK BERRY kamu tak cukup.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Ini SERBUK BERRY yang bagus.\n"
	.string "Ia boleh jadi ubat yang hebat.\p"
	.string "Kamu nak tukar lagi SERBUK BERRY kamu\n"
	.string "dengan benda lain?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Baiklah! Bila kamu dapat lagi SERBUK\n"
	.string "BERRY, bawa kepada saya, ya!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Datang semula kalau nak tukar SERBUK\n"
	.string "BERRY dengan ubat.\p"
	.string "Saya sentiasa buka gerai di sini.\p"
	.string "Kamu tahu tak?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Hah?\n"
	.string "Rasanya saya pernah jumpa kamu.\p"
	.string "Saya dah kenalkan diri ke? Kalau belum,\n"
	.string "nama saya SCOTT.\p"
	.string "Saya baru nampak TEAM AQUA lari dari\n"
	.string "sini macam kena sengat.\p"
	.string "Biar saya teka, kamu yang halau mereka?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Hmm…\n"
	.string "Mungkin, cuma mungkin, JURULATIH ni…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Baiklah! Saya rasa kita akan jadi\n"
	.string "kawan baik.\p"
	.string "Jadi, jom kita daftar nama\n"
	.string "masing-masing dalam POKéNAV.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Orang bernama SCOTT ni didaftarkan\n"
	.string "dalam POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: Saya teringin nak ikut kamu, tapi\n"
	.string "saya juga nak perhatikan bakat orang\l"
	.string "lain.\p"
	.string "Jadi, saya nak merayau ke pekan lain\n"
	.string "lagi.\p"
	.string "Jumpa lagi, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: Oh, hei!\n"
	.string "Rupanya {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, biar saya teka, kamu nak sahut\n"
	.string "cabaran KHEMAH BATTLE?\p"
	.string "Ya! Idea yang bagus!\n"
	.string "Idea yang sangat bagus!\p"
	.string "Lagipun, JURULATIH yang kuat memang\n"
	.string "sesuai untuk KHEMAH BATTLE!\p"
	.string "Buat yang terbaik!$"
