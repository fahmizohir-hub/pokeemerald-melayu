BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applywaitmovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applywaitmovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applywaitmovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applywaitmovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Inilah BATTLE DOME!\n"
	.string "Jalan kamu menjadi bintang yang tak\l"
	.string "terkalahkan!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Inilah BATTLE FACTORY!\n"
	.string "Carilah POKéMON yang paling kuat!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Inilah BATTLE PIKE!\n"
	.string "Pilih satu daripada tiga laluan!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Inilah BATTLE TOWER.\p"
	.string "JURULATIH membawa POKéMON terbaik\n"
	.string "mereka untuk perlawanan kalah mati.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Helo, anda mahu naik feri?\n"
	.string "Boleh saya lihat TIKET anda?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} tiada TIKET…\p"
	.string "Saya mohon maaf.\p"
	.string "Anda mesti ada TIKET\n"
	.string "untuk menaiki feri.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} menunjukkan TIKET.\p"
	.string "Bagus! Itu saja yang diperlukan!\p"
	.string "Jadi, anda mahu ke mana?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "BANDAR SLATEPORT, baiklah!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "BANDAR LILYCOVE, baiklah!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Belayarlah bersama kami lain kali!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Sila naik feri dan\n"
	.string "tunggu waktu berlepas.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Kalau begitu, anda mahu ke mana?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Saya yang terbaik antara kawan-kawan\n"
	.string "saya. Tapi di sini… saya tak berguna\l"
	.string "langsung!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Saya nak pergi ke BATTLE TOWER, tapi\n"
	.string "tak jumpa-jumpa walaupun saya ada\l"
	.string "peta BATTLE FRONTIER.\p"
	.string "Tempat ni besar sangat!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Saya nak terus sahut cabaran\n"
	.string "sebaik sampai di sini.\p"
	.string "Tapi dalam perjalanan,\n"
	.string "saya mabuk laut… Uwekkk…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Bukan sebarang orang boleh\n"
	.string "datang ke sini, tahu tak?\p"
	.string "Hanya JURULATIH yang diiktiraf\n"
	.string "handal saja yang dibawa ke sini.\p"
	.string "Sebab itulah ramai JURULATIH langsung\n"
	.string "tak tahu tentang BATTLE FRONTIER.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Abang…\p"
	.string "Betul ke kita boleh sahut cabaran\n"
	.string "walaupun kita tak ada POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Err… Abang rasa tak apa.\p"
	.string "Rasanya…\p"
	.string "Tapi ingat lelaki besar yang menakutkan\n"
	.string "tu? Dia kata, “Saya pinjamkan\l"
	.string "POKéMON!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Itulah BATTLE FACTORY. Kamu boleh\n"
	.string "sewa POKéMON yang kuat di sana.\p"
	.string "Tapi saya tertanya-tanya. Siapa\n"
	.string "yang bela POKéMON sewa tu semua?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Saya takut nak masuk\n"
	.string "BATTLE PIKE sebab SEVIPER…\p"
	.string "T-tapi saya dah datang jauh-jauh, jadi\n"
	.string "saya akan cuba takluk semuanya!\l"
	.string "…Gigil…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Jom main batu, kertas,\n"
	.string "gunting! Satu, dua, tiga!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Yeay! Saya menang! Saya akan\n"
	.string "sahut cabaran BATTLE PIKE!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Alamak… Saya kalah.\p"
	.string "Nampaknya nasib saya tak baik hari ni.\n"
	.string "Saya tangguhkan cabaran BATTLE PIKE\l"
	.string "sampai esok.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Rasanya sayalah satu-satunya orang di\n"
	.string "sini yang, entah kenapa, lebih suka\l"
	.string "memancing daripada bertarung.\p"
	.string "Hah? Tak ada apa boleh\n"
	.string "ditangkap di sini? Hampanya…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Hari ni, saya akan terus bertarung,\n"
	.string "walau apa pun, sampai saya dapat Simbol.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh? Kamu nak pergi cabar BATTLE DOME?\p"
	.string "Saya doakan kamu berjaya. Mari kita\n"
	.string "sama-sama menang dan bertemu dalam\l"
	.string "cabaran nanti.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Atuk, sini! BATTLE DOME ada di\n"
	.string "sini! Kalahkan mereka, Atuk!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, jadi inilah BATTLE DOME? Saya\n"
	.string "takkan biar BUDIMAN kalahkan saya!\p"
	.string "Tapi di mana pintu masuknya?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Tak lama dulu, tempat ni kosong saja.\p"
	.string "Tapi sekarang, tengoklah tempat ni!\n"
	.string "Menakjubkan! Saya nak bawa ibu saya\l"
	.string "datang tengok.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Akhirnya saya sampai\n"
	.string "di BATTLE FRONTIER!\p"
	.string "Mesti saya menarik perhatian\n"
	.string "dengan rupa dan kebolehan saya!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Kunyah, kunyah…\p"
	.string "Nampaknya dataran ni penuh\n"
	.string "dengan orang yang handal.\p"
	.string "Kunyah, kunyah…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Kunyah, kunyah…\p"
	.string "Tak lama dulu, saya jumpa\n"
	.string "seorang kakak di BATTLE PIKE.\p"
	.string "Matanya menakutkan, garang betul.\p"
	.string "Kunyah, kunyah…\p"
	.string "Dia naik angin: “Boleh tak kamu berhenti\n"
	.string "makan!” Lepas tu dia belasah saya.\p"
	.string "Memang pengalaman yang menyeramkan,\n"
	.string "sampai meremang bulu roma.\p"
	.string "Kunyah, kunyah…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Hah? Cuba dengar apa kamu\n"
	.string "cakap tu? Itu tak ada apa-apa!\p"
	.string "Masa terakhir saya bersorak untuk dia,\n"
	.string "mata kami bertentang dan terus\l"
	.string "berpercikan api!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Apaaaaa?! Huh!\p"
	.string "Itu cuma berlaku sebab saya\n"
	.string "kebetulan duduk sebelah kamu!\p"
	.string "DOME ACE pandang ke arah kita pun\n"
	.string "sebab sorakan saya kuat sangat!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Ish, diamlah! Jangan bising sangat!\p"
	.string "Peminat musiman macam kamu patut\n"
	.string "bersorak untuk mana-mana KETUA GIM\l"
	.string "saja!\p"
	.string "DOME ACE tu saya punya!\n"
	.string "Satu-satunya idola saya!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Orang-orang yang bertekak di sana tu…\p"
	.string "Susah nak percaya, tapi dulu mereka\n"
	.string "JURULATIH, dan yang hebat pula.\p"
	.string "Dulu mereka sangat\n"
	.string "kuat, dan terkenal juga.\p"
	.string "Tapi mereka dihancurkan oleh seorang\n"
	.string "JURULATIH dalam satu kejohanan.\p"
	.string "Mereka kalah teruk sangat sampai\n"
	.string "jatuh hati pada JURULATIH tu.\p"
	.string "Sekarang mereka cuma peminat\n"
	.string "JURULATIH tu. Setiap hari mereka pergi\l"
	.string "bersorak untuk idola mereka di\l"
	.string "BATTLE DOME.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Saya dengar khabar angin ada orang\n"
	.string "nampak POKéMON dengan ekor yang luar\l"
	.string "biasa panjang di suatu tempat di\l"
	.string "BATTLE FRONTIER.\p"
	.string "Mesti comel. Saya pasti…\p"
	.string "Oh, cabaran boleh tunggu. Saya rasa\n"
	.string "terdorong nak cari makhluk comel tu!$"

