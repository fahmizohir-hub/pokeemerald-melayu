BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applywaitmovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "Pertama kali kamu ke sini?\n"
	.string "Silakan ke sebelah sini!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "Barisan hadapan pertarungan POKéMON!\n"
	.string "Selamat datang ke BATTLE FRONTIER!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Untuk pelawat kali pertama,\n"
	.string "kami keluarkan PAS FRONTIER.\p"
	.string "Pas ini boleh digunakan di semua\n"
	.string "fasiliti di BATTLE FRONTIER.\p"
	.string "Nah, ambillah!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} mendapat PAS FRONTIER.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} memasukkan KAD JURULATIH\n"
	.string "ke dalam PAS FRONTIER.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Semoga kamu menikmati semua yang\n"
	.string "ditawarkan oleh BATTLE FRONTIER!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Wah, {PLAYER}{KUN} rupanya!\n"
	.string "Kamu datang juga ke sini!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "PEMANDU: Oh! ENCIK SCOTT!\n"
	.string "Selamat sejahtera, encik!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SCOTT: Seronok sungguh\n"
	.string "jumpa kamu di sini, betul!\p"
	.string "Saya harap kamu luangkan masa\n"
	.string "dan jelajah setiap pelosok.\p"
	.string "Tentu sekali, saya juga harap kamu\n"
	.string "dapat rasai intipati sebenar\l"
	.string "pertarungan.\p"
	.string "Saya pun ada tempat tinggal di sini,\n"
	.string "jadi singgahlah kalau ada masa.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Saya pemandu untuk pelbagai\n"
	.string "fasiliti di BATTLE FRONTIER ini.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Yang mana kamu mahu tahu?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "Menara gergasi ini dianggap sebagai\n"
	.string "lambang BATTLE FRONTIER.\p"
	.string "Ada empat jenis BILIK TARUNG dalam\n"
	.string "menara itu, untuk TARUNG TUNGGAL,\l"
	.string "GANDA, MULTI dan MULTI LINK.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "BATTLE DOME ialah bangunan besar\n"
	.string "berbentuk seperti telur gergasi.\p"
	.string "Acara bernama Kejohanan\n"
	.string "Pertarungan diadakan di fasiliti ini.\p"
	.string "Kejohanan Pertarungan ditawarkan\n"
	.string "dalam dua kategori, iaitu\l"
	.string "TARUNG TUNGGAL dan GANDA.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "BATTLE PALACE ialah bangunan merah\n"
	.string "di sebelah kanan BATTLE FRONTIER.\p"
	.string "Ada dua jenis DEWAN TARUNG,\n"
	.string "untuk TARUNG TUNGGAL dan GANDA.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "BATTLE ARENA ialah bangunan seperti\n"
	.string "dojo di tengah-kanan BATTLE FRONTIER.\p"
	.string "Acara bernama Kejohanan KO\n"
	.string "Set diadakan di BATTLE ARENA.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "BATTLE FACTORY ialah bangunan\n"
	.string "besar yang paling dekat dengan kita.\p"
	.string "Acara bernama Tukar Tarung\n"
	.string "dijalankan di sana.\p"
	.string "Acara Tukar Tarung ditawarkan dalam\n"
	.string "dua kategori, untuk TARUNG TUNGGAL dan\l"
	.string "GANDA.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "BATTLE PIKE ialah bangunan berbentuk\n"
	.string "POKéMON di tengah-kiri\l"
	.string "BATTLE FRONTIER.\p"
	.string "Acara bernama Pilih Tarung\n"
	.string "dijalankan di sana.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "BATTLE PYRAMID ialah\n"
	.string "piramid yang sangat besar.\p"
	.string "Acara bernama Misi Tarung\n"
	.string "dijalankan di sana.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "DEWAN KEDUDUKAN terletak\n"
	.string "berhampiran BATTLE TOWER.\p"
	.string "Di sana, kamu boleh lihat rekod paling\n"
	.string "hebat yang ditinggalkan oleh JURULATIH\l"
	.string "yang menyahut pelbagai cabaran\l"
	.string "BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "KAUNTER PENUKARAN terletak\n"
	.string "berhampiran BATTLE TOWER.\p"
	.string "Mata Tarung yang kamu peroleh di\n"
	.string "BATTLE FRONTIER boleh ditukar dengan\l"
	.string "hadiah hebat di sana.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Saya pemandu untuk peraturan asas\n"
	.string "yang sama bagi semua cabaran yang\l"
	.string "ditawarkan oleh fasiliti di\l"
	.string "BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Apa yang kamu mahu tahu?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Semua cabaran di fasiliti\n"
	.string "BATTLE FRONTIER ada dua kategori,\l"
	.string "iaitu LV. 50 dan LV. TERBUKA.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "Kategori LV. 50 terbuka kepada\n"
	.string "POKéMON Lv. 50 ke bawah.\p"
	.string "Tapi ingat, tiada JURULATIH yang\n"
	.string "kamu lawan akan guna POKéMON di\l"
	.string "bawah Lv. 50.\p"
	.string "Kategori ini ialah tahap permulaan\n"
	.string "untuk pertarungan di BATTLE FRONTIER.\p"
	.string "Sebagai permulaan, kami harap\n"
	.string "kamu cabar kategori ini dulu.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "Kategori LV. TERBUKA tidak menghadkan\n"
	.string "tahap POKéMON yang menyertai cabaran.\p"
	.string "Tahap lawan kamu akan diselaraskan\n"
	.string "mengikut tahap POKéMON kamu.\p"
	.string "Tapi, tiada JURULATIH yang kamu lawan\n"
	.string "akan guna POKéMON di bawah Lv. 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Hampir semua jenis POKéMON boleh\n"
	.string "menyahut cabaran di semua fasiliti.\p"
	.string "Tetapi, TELUR dan sesetengah\n"
	.string "jenis POKéMON tidak dibenarkan.\p"
	.string "Bilangan POKéMON yang diperlukan untuk\n"
	.string "cabaran bergantung pada fasiliti.\p"
	.string "Tetapi di semua fasiliti, POKéMON\n"
	.string "yang sama tidak boleh dimasukkan\l"
	.string "lebih daripada seekor.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "Bila menyertai cabaran di fasiliti\n"
	.string "BATTLE FRONTIER, POKéMON tidak boleh\l"
	.string "memegang barang yang sama jenis.\p"
	.string "Pastikan semua POKéMON yang menyertai\n"
	.string "cabaran memegang barang yang\l"
	.string "berlainan.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Saya pemandu untuk PAS FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Yang mana kamu mahu tahu?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Ada tujuh fasiliti di BATTLE FRONTIER.\p"
	.string "JURULATIH yang diiktiraf kebolehannya\n"
	.string "mungkin diberi simbol daripada setiap\l"
	.string "fasiliti.\p"
	.string "Untuk dapat simbol, JURULATIH mungkin\n"
	.string "perlu tewaskan JURULATIH lain\l"
	.string "berturut-turut, dan mungkin perlu\l"
	.string "menang acara berulang kali.\p"
	.string "Memang tidak mudah untuk dapat\n"
	.string "simbol. Semoga kamu berjaya!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Kamu boleh rakam satu pertarungan\n"
	.string "dalam PAS FRONTIER kamu.\p"
	.string "Kamu boleh rakam pertarungan dengan\n"
	.string "seorang atau beberapa orang kawan.\p"
	.string "Atau kamu boleh rakam pertarungan di\n"
	.string "BATTLE FRONTIER, kecuali perlawanan di\l"
	.string "BATTLE PIKE atau BATTLE PYRAMID.\p"
	.string "Kamu boleh pilih untuk rakam\n"
	.string "perlawanan di penghujung pertarungan.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Mata Tarung ialah ganjaran untuk\n"
	.string "JURULATIH yang bertarung dengan\l"
	.string "cemerlang di BATTLE FRONTIER.\p"
	.string "Kamu boleh tukar Mata Tarung dengan\n"
	.string "hadiah di KAUNTER PENUKARAN.$"

