BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "Di sinilah kebijaksanaan JURULATIH\n"
	.string "diuji!\p"
	.string "Selamat datang ke BATTLE FACTORY!\p"
	.string "Saya pemandu Kejohanan Tukar Tarung\n"
	.string "Tunggal.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "Kamu mahu menyahut cabaran Tukar\n"
	.string "Tarung Tunggal?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "Kejohanan Tukar Tarung Tunggal ialah\n"
	.string "pertandingan TARUNG TUNGGAL yang\l"
	.string "hanya guna POKéMON sewa.\p"
	.string "Pertama, kamu akan dipinjamkan tiga\n"
	.string "POKéMON khas untuk acara ini.\p"
	.string "Dengan POKéMON sewa yang diberi,\n"
	.string "kamu akan bertanding TARUNG TUNGGAL.\p"
	.string "Jika menang, kamu boleh menukar\n"
	.string "seekor POKéMON sewa kamu.\p"
	.string "Ulangi kitaran bertarung dan menukar\n"
	.string "ini--menang tujuh kali berturut-turut\l"
	.string "dan kamu akan dapat Mata Tarung.\p"
	.string "Jika mahu berhenti di tengah\n"
	.string "cabaran, sila simpan permainan.\p"
	.string "Jika tak simpan, penyertaan kamu\n"
	.string "dalam cabaran akan dibatalkan.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "Kami nantikan kedatangan kamu lagi.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "Tahap mana yang kamu mahu cabar?\n"
	.string "LV. 50 atau LV. TERBUKA?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "Sebelum cabaran bermula, saya perlu\n"
	.string "simpan permainan. Boleh?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "Baiklah, saya akan jaga POKéMON kamu\n"
	.string "sementara kamu bertanding.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "Sila ikut sini.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "Terima kasih kerana menyertai!\p"
	.string "Saya akan pulangkan POKéMON kamu dan\n"
	.string "ambil semula POKéMON sewa kami.\p"
	.string "Saya juga perlu simpan keputusan.\n"
	.string "Sila tunggu.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "Saya akan pulangkan POKéMON kamu dan\n"
	.string "ambil semula POKéMON sewa kami.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "Tahniah! Kamu menang tujuh perlawanan\n"
	.string "Tukar Tarung berturut-turut!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "Sempena 7 kemenangan berturut-turut,\n"
	.string "kami berikan Mata Tarung ini.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "Oh, oh, oh!\p"
	.string "Mata Tarung kamu dah maksimum.\p"
	.string "Sila datang semula selepas guna\n"
	.string "sebahagian Mata Tarung.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "Kami dah lama tunggu kamu!\p"
	.string "Sebelum kamu sambung cabaran,\n"
	.string "saya perlu simpan permainan.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "Maaf, tapi kamu tidak simpan\n"
	.string "sebelum berhenti bermain kali lepas.\p"
	.string "Sebab itu, penyertaan kamu dalam\n"
	.string "cabaran ini dibatalkan.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "Kami pulangkan POKéMON kamu sendiri.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} menerima hadiah\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "Di sinilah kebijaksanaan JURULATIH\n"
	.string "diuji!\p"
	.string "Selamat datang ke BATTLE FACTORY!\p"
	.string "Saya pemandu Kejohanan Tukar Tarung\n"
	.string "Ganda.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "Kamu mahu menyahut cabaran Tukar\n"
	.string "Tarung Ganda?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "Kejohanan Tukar Tarung Ganda ialah\n"
	.string "pertandingan TARUNG GANDA yang\l"
	.string "hanya guna POKéMON sewa.\p"
	.string "Pertama, kamu akan dipinjamkan tiga\n"
	.string "POKéMON khas untuk acara ini.\p"
	.string "Dengan POKéMON sewa yang diberi,\n"
	.string "kamu akan bertanding TARUNG GANDA.\p"
	.string "Jika menang, kamu boleh menukar\n"
	.string "seekor POKéMON sewa kamu.\p"
	.string "Ulangi kitaran bertarung dan menukar\n"
	.string "ini--menang tujuh kali berturut-turut\l"
	.string "dan kamu akan dapat Mata Tarung.\p"
	.string "Jika mahu berhenti di tengah\n"
	.string "cabaran, sila simpan permainan.\p"
	.string "Jika tak simpan sebelum berhenti,\n"
	.string "penyertaan kamu akan dibatalkan.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "Tahniah kerana menewaskan\n"
	.string "FACTORY HEAD dan memenangi\l"
	.string "tujuh perlawanan berturut-turut!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "Sebagai penghargaan atas ilmu kamu\n"
	.string "yang luas dan kepintaran yang tajam,\l"
	.string "kami berikan Mata Tarung ini.$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "Biar saya pulangkan POKéMON kamu\n"
	.string "dan ambil semula POKéMON sewa kami.\p"
	.string "Saya perlu simpan data pertarungan,\n"
	.string "jadi sila tunggu.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "Mahu rakam perlawanan terakhir\n"
	.string "BATTLE FACTORY kamu dalam\l"
	.string "PAS FRONTIER?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "Hai!\n"
	.string "Kamu yang di sana tu!\p"
	.string "Kamu ingat acara di sini senang sebab\n"
	.string "tak perlu ada pasukan POKéMON\l"
	.string "yang dibela sendiri?\p"
	.string "Jangan terlalu yakin boleh menang\n"
	.string "semudah itu.\p"
	.string "Kalau kamu tak arif tentang POKéMON\n"
	.string "dan move mereka,\l"
	.string "memang susah nak terus menang.$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "Saya tukar dengan POKéMON yang lemah…\n"
	.string "Saya ingat jenis itu bagus…\p"
	.string "Kami kena belasah teruk…$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "Asyik tak menjadi je\n"
	.string "saya ni.\p"
	.string "Kamu perlu teliti POKéMON lawan\n"
	.string "semasa bertarung untuk tahu\l"
	.string "bagus ke tidak.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "Kamu tahu kakitangan di sini ada beri\n"
	.string "sedikit petunjuk tentang lawan nanti?\p"
	.string "Saya ni dah dewasa, tapi saya masih\n"
	.string "susah nak faham petunjuk mereka.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "Saya ni memang hebat, tapi cepat bosan,\n"
	.string "jadi saya asyik bertukar dan\l"
	.string "bertarung berulang kali.\p"
	.string "Jadi, bila saya asyik masuk acara\n"
	.string "Tukar Tarung, saya perasan POKéMON\l"
	.string "sewa mereka berubah-ubah.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "Ini peraturan Tukar Tarung.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "Tajuk mana yang kamu mahu baca?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "Dalam acara Tukar Tarung, kamu hanya\n"
	.string "boleh guna tiga POKéMON.\p"
	.string "Sama ada menyewa atau menukar,\n"
	.string "pasukan kamu tak boleh ada dua atau\l"
	.string "lebih POKéMON yang sama.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "Kamu hanya boleh menukar POKéMON\n"
	.string "dengan JURULATIH yang baru tewas.\p"
	.string "Kamu hanya boleh dapat POKéMON\n"
	.string "yang digunakan oleh JURULATIH itu.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "Selepas setiap kemenangan, kamu boleh\n"
	.string "tukar dengan seekor POKéMON\l"
	.string "lawan yang kamu tewaskan.\p"
	.string "Kamu tak boleh menukar POKéMON\n"
	.string "dengan JURULATIH ketujuh dalam acara.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "Ada dua perkara penting untuk diingat\n"
	.string "semasa menukar POKéMON.\p"
	.string "Pertama, semasa menukar, kamu tak\n"
	.string "boleh semak stat POKéMON yang\l"
	.string "bakal kamu terima.\p"
	.string "Kedua, POKéMON dalam pasukan kamu\n"
	.string "disusun mengikut urutan\l"
	.string "kamu menyewa mereka.\p"
	.string "Urutan ini tidak berubah\n"
	.string "walaupun kamu menukar POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "Dalam LV. TERBUKA, POKéMON sewa\n"
	.string "dan POKéMON JURULATIH lawan\l"
	.string "semuanya pada Tahap 100.$"
