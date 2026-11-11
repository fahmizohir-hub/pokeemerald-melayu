TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applywaitmovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Inilah BUKIT JURULATIH, tempat kamu\n"
	.string "boleh nikmati pertarungan berpasangan\l"
	.string "dengan ramai JURULATIH.\p"
	.string "Malangnya, kami masih membuat\n"
	.string "persiapan. Sila datang lagi nanti!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Selamat datang!\p"
	.string "Inilah BUKIT JURULATIH, tempat kamu\n"
	.string "boleh nikmati pertarungan berpasangan\l"
	.string "dengan ramai JURULATIH!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "Ini kali pertama kamu datang ke sini?\p"
	.string "Sebelum masuk, sila\n"
	.string "simpan permainan kamu.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Biar saya lihat… JURULATIH\n"
	.string "yang ada sekarang…\p"
	.string "Sehingga tingkat {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Biar saya lihat… JURULATIH\n"
	.string "yang ada sekarang…\p"
	.string "Nampaknya ada JURULATIH\n"
	.string "berkumpul di setiap bilik.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Kamu mahu mencabar JURULATIH\n"
	.string "yang sedang menunggu?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Saya akan kira masa perjalanan\n"
	.string "kamu. Semoga berjaya!\p"
	.string "Di garisan…\p"
	.string "Sedia…\p"
	.string "Mula!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Datanglah melawat kami lagi!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Sayang sekali.\p"
	.string "Saya rasa kamu dah berusaha\n"
	.string "bersungguh-sungguh dalam pertarungan.\p"
	.string "Datanglah lagi dan cuba sekali lagi!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Berusahalah sehabis baik, ya.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Bila JURULATIH bertukar tempat,\n"
	.string "keadaan boleh jadi kelam-kabut.\p"
	.string "Untuk elak rempuhan, kami pindahkan\n"
	.string "kaunter penyambut tetamu ke sini.\p"
	.string "Maaf atas kesulitan.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Terima kasih kerana bermain!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Di BUKIT JURULATIH, kami adakan acara\n"
	.string "bernama Lumba Masa.\p"
	.string "Perlumbaan ini mengukur berapa lama\n"
	.string "kamu ambil untuk sampai kepada pemilik\l"
	.string "kami di bumbung dari kaunter ini.\p"
	.string "Masa terpantas dipaparkan di PAPAN\n"
	.string "MASA. Cubalah bersaing dengan\l"
	.string "kawan-kawan kamu.\p"
	.string "Dalam pertarungan JURULATIH di\n"
	.string "sepanjang jalan, Mata EXP. dan wang\l"
	.string "tidak akan diberi.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Oh, maaf, nampaknya kamu\n"
	.string "cuma bawa satu POKéMON.\p"
	.string "Kamu perlukan sekurang-kurangnya dua\n"
	.string "POKéMON untuk menyertai acara ini.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hm! Hm!\p"
	.string "Akhirnya kamu datang!\n"
	.string "Ya, kamu dah tiba!\p"
	.string "Tunggu! Jangan cakap! Saya tahu\n"
	.string "kenapa kamu datang jauh-jauh ke sini\l"
	.string "seorang diri!\p"
	.string "Kamu nak jumpa saya, pemilik\n"
	.string "BUKIT JURULATIH, sebab…\p"
	.string "Kamu nak berganding bahu dengan\n"
	.string "saya sebagai pasangan! Wa-hoo!\p"
	.string "…Eh? Bukan begitu?\p"
	.string "Apa-apa pun, saya perhatikan kamu\n"
	.string "sepanjang jalan ke atas. Pertarungan\l"
	.string "yang mengagumkan! Bravo, memang bravo!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Untuk insan hebat macam kamu,\n"
	.string "saya ada hadiah yang paling hebat!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Alamak, barang kamu dah penuh!\n"
	.string "Kamu datang ambil ini nanti!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh, nanti dulu! Kamu sampai ke sini\n"
	.string "dengan sangat pantas, ya?\p"
	.string "Hebatnya! Tak perlulah tergesa-gesa\n"
	.string "sangat nak jumpa saya!\p"
	.string "Seronok sungguh. Saya akan suruh\n"
	.string "PAPAN MASA di kaunter dikemas kini!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Tapi, oh… Kamu tak begitu\n"
	.string "pantas sampai ke sini.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Mungkin saya lebih gembira kalau\n"
	.string "kamu sampai lebih laju lain kali.\p"
	.string "Barulah saya sudi berganding\n"
	.string "dengan kamu sebagai pasangan!\p"
	.string "Sampai jumpa lagi, amigo!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "Saya bina BUKIT JURULATIH atas\n"
	.string "satu sebab, dan satu sebab sahaja!\p"
	.string "Untuk mencari rakan paling sesuai yang\n"
	.string "boleh berganding dengan saya sebagai\l"
	.string "pasangan!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min.\n"
	.string "{STR_VAR_2}.{STR_VAR_3} saat.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Siapa tahu JURULATIH dan kombo\n"
	.string "POKéMON macam mana yang menanti di\l"
	.string "depan?\p"
	.string "Yang saya tahu, saya akan tolak\n"
	.string "tepi sesiapa yang menghalang saya!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "Saya dengar JURULATIH handal dari\n"
	.string "merata tempat datang ke\l"
	.string "BUKIT JURULATIH ni.\p"
	.string "Saya tak sabar nak cuba!\p"
	.string "Saya akan tolak tepi sesiapa\n"
	.string "yang menghalang saya!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Kamu nampak PAPAN MASA di sana tu?\p"
	.string "Saya dan kawan-kawan sedang bersaing\n"
	.string "siapa boleh sampai ke atas paling\l"
	.string "cepat.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Kamu tahu bila tempat ni nak dibuka?\p"
	.string "Saya tunggu di sini nak jadi\n"
	.string "pencabar yang paling pertama!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Kamu mahu kembali ke\n"
	.string "kaunter penyambut tetamu?$"
