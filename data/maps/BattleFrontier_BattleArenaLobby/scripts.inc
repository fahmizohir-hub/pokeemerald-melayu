BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "Di sinilah semangat bertarung para\n"
	.string "JURULATIH diuji!\p"
	.string "Selamat datang ke BATTLE ARENA!\p"
	.string "Saya pemandu Kejohanan KO Set!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "Jadi, kamu mahu menyahut\n"
	.string "cabaran BATTLE ARENA?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Kami menanti cabaran kamu\n"
	.string "pada lain kali!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "Di BATTLE ARENA, kami mengadakan\n"
	.string "Kejohanan KO Set.\p"
	.string "Setiap peserta masuk dengan pasukan\n"
	.string "tiga POKéMON.\p"
	.string "Tiga POKéMON itu mesti disusun ikut\n"
	.string "urutan mereka akan keluar.\p"
	.string "Semasa bertarung, POKéMON keluar\n"
	.string "seekor demi seekor ikut urutan itu.\p"
	.string "Sebaik POKéMON masuk bertarung, ia\n"
	.string "mesti kekal sehingga ada keputusan.\p"
	.string "Jika tiada keputusan dalam tiga\n"
	.string "giliran, ia akan ke penilaian.\p"
	.string "Jika mahu berhenti seketika,\n"
	.string "sila simpan permainan.\p"
	.string "Jika tak simpan, kamu tidak boleh\n"
	.string "meneruskan cabaran kamu.\p"
	.string "Jika kamu berjaya menewaskan tujuh\n"
	.string "JURULATIH berturut-turut,\l"
	.string "kami akan berikan Mata Tarung.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Sebelum ke BATTLE ARENA, kamu mesti\n"
	.string "simpan permainan. Boleh?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "BATTLE ARENA ada dua tahap cabaran,\n"
	.string "LV. 50 dan LV. TERBUKA.\l"
	.string "Yang mana pilihan kamu?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Baiklah, sila pilih\n"
	.string "tiga POKéMON kamu.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Wahai pencabar!\p"
	.string "Kamu tiada tiga POKéMON yang\n"
	.string "diperlukan untuk menyertai.\p"
	.string "Untuk layak, kamu mesti bawa tiga\n"
	.string "POKéMON yang berlainan jenis.\p"
	.string "Mereka juga tidak boleh memegang\n"
	.string "barang yang sama.\p"
	.string "TELUR{STR_VAR_1}tidak layak.\p"
	.string "Bila kamu sudah bersedia,\n"
	.string "sila datang semula.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "Wahai pencabar!\p"
	.string "Kamu tiada tiga POKéMON yang\n"
	.string "diperlukan untuk menyertai.\p"
	.string "Untuk layak, kamu mesti bawa tiga\n"
	.string "POKéMON yang berlainan jenis.\p"
	.string "Ketiga-tiga POKéMON itu mesti\n"
	.string "pada Tahap 50 atau lebih rendah.\p"
	.string "Mereka juga tidak boleh memegang\n"
	.string "barang yang sama.\p"
	.string "TELUR{STR_VAR_1}tidak layak.\p"
	.string "Bila kamu sudah bersedia,\n"
	.string "sila datang semula.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Saya akan bawa kamu ke\n"
	.string "BATTLE ARENA sekarang.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Wahai pencabar!\p"
	.string "Kamu tidak simpan permainan sebelum\n"
	.string "menutupnya, bukan?\p"
	.string "Sayang sekali, kerana itu kamu\n"
	.string "telah dibatalkan penyertaan\l"
	.string "daripada cabaran kamu.\p"
	.string "Sudah tentu, kamu boleh mulakan\n"
	.string "cabaran baru.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Tahniah atas kemenangan hebat kamu\n"
	.string "ke atas tujuh JURULATIH!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "Pencapaian kamu akan direkodkan.\n"
	.string "Sila tunggu, saya simpan permainan.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "Sempena 7 kemenangan berturut-turut,\n"
	.string "kami hadiahkan kamu hadiah ini.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} menerima hadiah\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Oh?\n"
	.string "BEG kamu nampaknya penuh.\p"
	.string "Sila kosongkan ruang dan\n"
	.string "datang semula untuk hadiah kamu.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Terima kasih banyak kerana menyertai!\p"
	.string "Sila tunggu, saya simpan permainan.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Kami menanti cabaran kamu\n"
	.string "pada lain kali!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Kami memang menanti\n"
	.string "ketibaan kamu.\p"
	.string "Sebelum ke BATTLE ARENA, saya\n"
	.string "perlu simpan permainan.\l"
	.string "Sila tunggu.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Mahu saya rakam perlawanan terakhir\n"
	.string "BATTLE ARENA dalam PAS FRONTIER?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "Saya kalah ikut keputusan PENGADIL…\p"
	.string "Rasanya bukan idea baik guna move\n"
	.string "bertahan sahaja tanpa menyerang…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "Saya menang dalam penilaian!\p"
	.string "Asyik menyerang POKéMON lawan\n"
	.string "memang berkesan!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "Perlawanan kami diisytiharkan seri.\p"
	.string "Bila masa tamat, HP POKéMON saya\n"
	.string "dan POKéMON lawan lebih kurang\l"
	.string "sama banyak.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "Di BATTLE ARENA, urutan POKéMON\n"
	.string "memang sangat penting.\p"
	.string "Contohnya, jika POKéMON pertama\n"
	.string "kamu lemah terhadap jenis tertentu,\l"
	.string "jadikan POKéMON kedua kamu yang\l"
	.string "ada move sangat berkesan terhadap\l"
	.string "lawan yang mengalahkan yang pertama.\p"
	.string "Saya rasa itu cara bagus untuk\n"
	.string "bina pasukan yang berkesan.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "Peraturan Kejohanan KO Set tertera.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Tajuk mana yang kamu mahu baca?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "Kejohanan KO Set ada peraturan khas,\n"
	.string "tidak seperti pertarungan biasa.\p"
	.string "Pertama, satu pertarungan hanya\n"
	.string "berlangsung tiga giliran.\p"
	.string "Jika tiada keputusan selepas\n"
	.string "tiga giliran, ia akan ke penilaian.\p"
	.string "PENGADIL akan pilih pemenang\n"
	.string "ikut cara POKéMON bertarung.\p"
	.string "Selain itu, POKéMON tidak boleh ditukar\n"
	.string "sehingga pertarungannya selesai.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "Faktor penilaian pertama ialah “Minda.”\n"
	.string "Faktor ini menilai betapa agresif\l"
	.string "POKéMON yang bertarung.\p"
	.string "Penilaian berdasarkan kekerapan\n"
	.string "JURULATIH mengarahkan penggunaan\l"
	.string "move menyerang.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "Faktor penilaian kedua ialah “Teknik.”\n"
	.string "Faktor ini menilai betapa berkesan\l"
	.string "move POKéMON digunakan.\p"
	.string "Jika sesuatu move berjaya,\n"
	.string "mata Teknik akan naik.\p"
	.string "Jika sesuatu move gagal, mata Teknik\n"
	.string "akan turun.\p"
	.string "Bagi move menyerang, mata Teknik\n"
	.string "naik jika move itu “sangat berkesan”\l"
	.string "dan turun jika ia\l"
	.string "“kurang berkesan.”\p"
	.string "Mata Teknik tidak naik untuk\n"
	.string "move seperti LINDUNG dan WASPADA.\p"
	.string "Jika lawan guna LINDUNG atau\n"
	.string "WASPADA dan move POKéMON kamu\l"
	.string "tidak kena, mata Teknik tidak\l"
	.string "akan turun.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "Faktor penilaian ketiga ialah “Tubuh.”\n"
	.string "Faktor ini berdasarkan baki HP\l"
	.string "di akhir pertarungan.\p"
	.string "Penilaian mengambil kira HP POKéMON\n"
	.string "pada awal pertarungan dan\l"
	.string "baki HP pada akhirnya.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "Kemenangan ke atas ARENA TYCOON,\n"
	.string "dan menyapu bersih tujuh JURULATIH!\p"
	.string "Tahniah atas cabaran kamu yang\n"
	.string "sungguh hebat!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Wahai pencabar, sebagai penghargaan\n"
	.string "atas semangat kamu yang tak kenal\l"
	.string "penat, terimalah Mata Tarung ini.$"
