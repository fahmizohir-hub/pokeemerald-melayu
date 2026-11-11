BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applywaitmovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applywaitmovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applywaitmovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applywaitmovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applywaitmovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
	.string "SCOTT: Helo, selamat datang! Hehe…\n"
	.string "Maaf, tempat ni sempit sikit.\p"
	.string "Apa-apa pun, {PLAYER}{KUN}, izinkan saya\n"
	.string "mengalu-alukan kamu secara rasmi ke\l"
	.string "BATTLE FRONTIER.\p"
	.string "Inilah impian saya yang jadi kenyataan.\n"
	.string "Bertahun-tahun lamanya, tapi akhirnya\l"
	.string "saya berjaya wujudkannya.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.string "Bila difikirkan semula, memang\n"
	.string "perjalanan yang sangat panjang…\p"
	.string "Saya tinggalkan rumah seorang diri\n"
	.string "untuk mencari JURULATIH yang kuat.\p"
	.string "Tiada siapa dapat bayangkan berapa\n"
	.string "banyak usaha dan masa untuk\l"
	.string "menjadikannya kenyataan.$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.string "Tapi semua tu dah berlalu.\n"
	.string "Tak guna dikenang!\p"
	.string "Saya cuma mahu kamu nikmati\n"
	.string "pertarungan sepuas hati di sini.\p"
	.string "{PLAYER}{KUN}, terimalah ini sebagai kenangan\n"
	.string "untuk setiap kali kita bertemu dalam\l"
	.string "pengembaraan kita.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{PLAYER} mendapat\n"
	.string "{STR_VAR_1} Mata Tarung.$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.string "SCOTT: Kamu boleh semak Mata Tarung\n"
	.string "kamu dalam PAS FRONTIER.\p"
	.string "Makin banyak kejayaan kamu di\n"
	.string "BATTLE FRONTIER, makin banyak\l"
	.string "Mata Tarung yang kamu kumpul.\p"
	.string "Gunakan Mata Tarung kamu ikut suka,\n"
	.string "contohnya tukar dengan barang.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.string "Saya letak harapan\n"
	.string "tinggi pada kamu!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
	.string "SCOTT: Setiap JURULATIH ada\n"
	.string "keperibadian sendiri. Masing-masing ada\l"
	.string "kehidupan sendiri.\p"
	.string "Tapi bila mereka bertarung,\n"
	.string "tak kira siapa pun mereka.\p"
	.string "Mereka semua sama!\p"
	.string "Saya suka pertarungan yang adil,\n"
	.string "bila semua orang setaraf.\p"
	.string "Sebab itulah saya pergi ke merata\n"
	.string "tempat mencari JURULATIH yang serius\l"
	.string "tentang pertarungan, dan jemput\l"
	.string "mereka ke sini.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.string "SCOTT: Kamu dah jumpa\n"
	.string "mana-mana FRONTIER BRAIN?\p"
	.string "Atau lebih hebat, kamu dah\n"
	.string "dapat simbol daripada mereka?\p"
	.string "Saya sendiri yang pilih FRONTIER BRAIN\n"
	.string "sebagai JURULATIH paling handal di\l"
	.string "mana-mana.\p"
	.string "Tapi saya pasti, kehebatan kamu\n"
	.string "akan buat mereka pun terkejut!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.string "SCOTT: Kamu bukan berlatih\n"
	.string "untuk bertarung saja, kan?\p"
	.string "Kalau tak silap saya, kamu juga\n"
	.string "sedang lengkapkan POKéDEX.\p"
	.string "Nak tahu sesuatu?\p"
	.string "Kamu mungkin terjumpa POKéMON liar di\n"
	.string "suatu tempat di BATTLE FRONTIER…\l"
	.string "Fufufu!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
	.string "SCOTT: Kamu seronok\n"
	.string "di BATTLE FRONTIER?\p"
	.string "…Sekejap… Oh!\p"
	.string "PAS FRONTIER kamu! Kamu dah\n"
	.string "kumpul set penuh simbol perak!\p"
	.string "Memang betul-betul mengagumkan! Kamu\n"
	.string "memang hebat, macam yang saya sangka!\p"
	.string "Biasanya saya tak buat begini,\n"
	.string "tapi ini saat yang istimewa!\p"
	.string "Saya mahu kamu ambil ini. Saya pasti\n"
	.string "kamu boleh gunakannya dengan baik.$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
	.string "SCOTT: Saya harap kamu seronok dengan\n"
	.string "semua yang ada di BATTLE FRONTIER.\p"
	.string "…Sekejap… Oh, tak percaya saya!\p"
	.string "PAS FRONTIER kamu! Kamu dah\n"
	.string "kumpul set penuh simbol emas!\p"
	.string "Hebat sungguh! Kamu memang\n"
	.string "luar biasa, macam yang saya\l"
	.string "sangka!\p"
	.string "… … … … … …\p"
	.string "{PLAYER}, kamu mesti terima ini!\p"
	.string "Saya rasa kamu tentu dapat\n"
	.string "menghargai nilai hadiah saya ni!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.string "Memang saya ada bakat mengenal\n"
	.string "JURULATIH yang bagus bila nampak.\p"
	.string "Saya gembira sangat saya\n"
	.string "terfikir nak bawa kamu ke sini!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.string "Nampaknya POKET BERI kamu dah penuh.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.string "SCOTT: Oh, saya dengar tentang kamu!\n"
	.string "Kamu kuasai BATTLE TOWER! Kamu\l"
	.string "kalahkan lebih 50 JURULATIH\l"
	.string "berturut-turut?\p"
	.string "Hebat sungguh! Saya\n"
	.string "mahu kamu ambil ini!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.string "SCOTT: Wah! Saya dengar tentang kamu!\n"
	.string "Kamu tundukkan BATTLE TOWER! Kamu\l"
	.string "kalahkan lebih 100 JURULATIH\l"
	.string "berturut-turut?\p"
	.string "Itu memang luar biasa\n"
	.string "hebat! Kamu mesti ambil ini!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.string "Saya akan tunggu berita yang lebih\n"
	.string "hebat tentang kamu selepas ini!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.string "Alamak, kalau barang kamu terlalu\n"
	.string "banyak, datanglah ambil ini nanti.$"

