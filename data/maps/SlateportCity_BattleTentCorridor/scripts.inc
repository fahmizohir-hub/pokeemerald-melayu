SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Nak sedikit nasihat berguna tentang\n"
	.string "PERTANDINGAN?\p"
	.string "Guna move tertentu selepas jenis move\n"
	.string "tertentu yang lain kadang-kadang\l"
	.string "dapat perhatian lebih.\p"
	.string "Kalau kamu tahu apa yang kamu buat,\n"
	.string "kamu boleh dapat markah PIKAT yang\l"
	.string "tinggi.\p"
	.string "Tentu saja, lawan kamu mungkin cuba\n"
	.string "ganggu persembahan POKéMON kamu.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Papa saya, dia HAKIM PERTANDINGAN.\p"
	.string "Bila besar nanti, saya nak jadi apa, ya?\n"
	.string "HAKIM atau KETUA GIM?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Hei, bro, aku tengah geram gila, tau.\n"
	.string "Macam, tau tak, aku cuma nak tahu\l"
	.string "kenapa POKéMON aku tak pernah menang,\l"
	.string "macam, hei?\p"
	.string "Jadi, macam, aku bagi HAKIM tu pendapat\n"
	.string "aku, tau, percuma je.\p"
	.string "Tapi dia tak nak dengar, macam, hei!\n"
	.string "Jadi, macam, frust gila, bro!\p"
	.string "Hei, macam, kau! Diam, tau?\n"
	.string "Ambil je, tau, benda ni!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "Tu, macam, TM41, tau?\n"
	.string "Hei, tu SEKSA, kau dengar tak?\p"
	.string "Macam, ia tak bagi lawan guna move yang\n"
	.string "sama dua kali berturut-turut, faham?\p"
	.string "Hei, sekarang kau dengar sini, macam,\n"
	.string "aku bukan nak seksa kau pun!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "PENGACARA: Oh, wah, wah!\n"
	.string "Hebat sungguh POKéMON tu!\p"
	.string "Silakan! Datanglah sertai PERTANDINGAN\n"
	.string "kami yang gemilang!\p"
	.string "Kamu pasti berjaya! Saya yakin!\n"
	.string "Mata saya tak pernah silap!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "HAKIM: Wah, helo!\n"
	.string "Saya nampak kamu seorang JURULATIH!\p"
	.string "Kalau begitu, rugilah kalau kamu\n"
	.string "terlepas PERTANDINGAN POKéMON!\p"
	.string "Dapatkan PAS CONTEST di\n"
	.string "PEKAN VERDANTURF dan masuk bila-bila\l"
	.string "masa!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "Masa untuk PIKAT!\n"
	.string "Apa yang patut saya mulakan dulu?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "Mereka tak ambil kisah sangat dengan\n"
	.string "PIKAT POKéMON saya…\p"
	.string "Hmph, HAKIM tu, dia tak kenal benda\n"
	.string "bagus walaupun depan mata.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Oh, hai! Kamu mesti peminat setia sampai\n"
	.string "datang sedekat ni.\p"
	.string "Saya akan balas semangat kamu dengan\n"
	.string "nasihat bijak ni.\p"
	.string "Kalau satu move betul-betul berjaya,\n"
	.string "penonton akan jadi teruja.\p"
	.string "POKéMON yang buat PIKAT tepat ketika\n"
	.string "semua orang teruja…\p"
	.string "Hmm, tentu ada sesuatu yang bagus akan\n"
	.string "berlaku!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Saya tak boleh! Saya lebih gementar\n"
	.string "daripada POKéMON saya.\p"
	.string "Saya menggigil dan jantung saya\n"
	.string "berdebar-debar!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Pertarungan dan PERTANDINGAN tak\n"
	.string "sama, tapi ada persamaan juga.\p"
	.string "Kamu perlu berusaha keras dan percaya\n"
	.string "pada POKéMON yang kamu latih.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "POKéMON tu nampak dalam prestasi\n"
	.string "terbaik, kan?\p"
	.string "POKéMON yang berjaya dalam penilaian\n"
	.string "kedua nampaknya lebih tenang semasa\l"
	.string "buat PIKAT.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Tengoklah pemandangan menyedihkan tu.\p"
	.string "Heh, POKéMON saya memang jauh lebih\n"
	.string "bagus daripada mereka semua!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "Tak rasa ke nak bergerak sama dengan\n"
	.string "POKéMON bila mereka buat PIKAT yang\l"
	.string "bertenaga?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "PERTANDINGAN POKéMON\n"
	.string "PENTAS TAHAP HIPER!$"

