MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Wah, wah, siapa pula ni?\n"
	.string "Pelanggan yang sangat bertenaga!\p"
	.string "Saya? Panggil saja saya RYDEL.\n"
	.string "Saya pemilik kedai basikal ni.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: KASUT LARI kamu…\n"
	.string "Kotor sungguh.\p"
	.string "Kamu datang dari jauh ke?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Oh, begitu?\p"
	.string "Kalau macam tu, kamu tak perlukan\n"
	.string "BASIKAL saya, agaknya.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "Kamu kata kamu datang jauh-jauh dari\n"
	.string "LITTLEROOT?\p"
	.string "Ya ampun!\n"
	.string "Jauh betul tu!\p"
	.string "Kalau kamu ada BASIKAL saya, kamu\n"
	.string "boleh pergi ke mana saja dengan mudah\l"
	.string "sambil dibelai angin lembut!\p"
	.string "Macam nilah!\n"
	.string "Saya bagi kamu sebuah BASIKAL!\p"
	.string "Oh, tunggu sekejap!\p"
	.string "Saya terlupa nak beritahu, ada dua\n"
	.string "jenis BASIKAL!\p"
	.string "BASIKAL MACH dan\n"
	.string "BASIKAL ACRO!\p"
	.string "BASIKAL MACH untuk penunggang yang\n"
	.string "nak rasa angin menerpa badan!\p"
	.string "BASIKAL ACRO pula untuk mereka yang\n"
	.string "suka tunggangan teknikal!\p"
	.string "Saya ni baik hati, jadi kamu boleh pilih\n"
	.string "yang mana kamu suka!\p"
	.string "Kamu nak pilih yang mana?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} memilih BASIKAL MACH.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} memilih BASIKAL ACRO.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: Kalau kamu teringin nak tukar\n"
	.string "BASIKAL, datang saja jumpa saya!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: Oh? Kamu terfikir nak tukar\n"
	.string "BASIKAL ke?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Baiklah, tiada masalah!\n"
	.string "Saya tukarkan BASIKAL untuk kamu!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} menukar BASIKAL MACH\n"
	.string "dengan BASIKAL ACRO.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} menukar BASIKAL ACRO\n"
	.string "dengan BASIKAL MACH.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Bagus, bagus!\n"
	.string "Saya gembira kamu suka!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? Mana BASIKAL yang saya bagi tu?\p"
	.string "Oh, saya faham, kamu simpan dalam PC.\p"
	.string "Keluarkan dari simpanan PC, nanti saya\n"
	.string "tukarkan dengan senang hati!\p"
	.string "Semoga angin sentiasa meniup dari\n"
	.string "belakang dalam pengembaraan kamu!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Saya belajar tentang BASIKAL sambil\n"
	.string "bekerja di sini.\p"
	.string "Kalau kamu perlukan nasihat cara\n"
	.string "menunggang BASIKAL, ada beberapa buku\l"
	.string "panduan di belakang.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "Ini buku panduan BASIKAL MACH.\p"
	.string "Kamu nak baca muka surat mana?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "BASIKAL bergerak ke arah + Pad Kawalan\n"
	.string "yang ditekan.\p"
	.string "Bila dah bergerak, ia makin laju.\p"
	.string "Untuk berhenti, lepaskan + Pad Kawalan.\n"
	.string "BASIKAL akan perlahan dan berhenti.\p"
	.string "Nak baca muka surat lain?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "BASIKAL MACH memang laju, tapi ia tak\n"
	.string "boleh berhenti dengan cepat.\p"
	.string "Agak susah sikit nak membelok di\n"
	.string "selekoh.\p"
	.string "Lepaskan + Pad Kawalan sedikit sebelum\n"
	.string "selekoh dan perlahankan.\p"
	.string "Nak baca muka surat lain?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Ada cerun berpasir kecil di seluruh\n"
	.string "wilayah HOENN.\p"
	.string "Pasirnya gembur dan mudah runtuh, jadi\n"
	.string "mustahil nak didaki dengan cara biasa.\p"
	.string "Tapi kalau kamu ada BASIKAL MACH, kamu\n"
	.string "boleh memecut naik cerun berpasir.\p"
	.string "Nak baca muka surat lain?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "Ini buku panduan BASIKAL ACRO.\p"
	.string "Kamu nak baca muka surat mana?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Tekan Butang B semasa menunggang, dan\n"
	.string "roda depan akan terangkat.\p"
	.string "Kamu boleh bergerak dengan roda depan\n"
	.string "terangkat guna + Pad Kawalan.\p"
	.string "Teknik ni dipanggil wheelie.\p"
	.string "Nak baca muka surat lain?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Kalau Butang B terus ditekan,\n"
	.string "BASIKAL kamu boleh melompat di tempat.\p"
	.string "Teknik ni dipanggil lompat arnab.\p"
	.string "Kamu juga boleh bergerak sambil\n"
	.string "melompat.\p"
	.string "Nak baca muka surat lain?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Tekan Butang B dan + Pad Kawalan\n"
	.string "serentak untuk melompat.\p"
	.string "Tekan + Pad Kawalan ke tepi untuk\n"
	.string "melompat ke sisi.\p"
	.string "Tekan ke belakang untuk buat\n"
	.string "BASIKAL tukar arah semasa melompat.\p"
	.string "Nak baca muka surat lain?$"

