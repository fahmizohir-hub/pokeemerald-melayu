Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "ENCIK BRINEY: Nanti dulu,\n"
	.string "cik adik! Tunggu, PEEKO!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Hm? Kamu {PLAYER}{KUN}! Kamu yang\n"
	.string "selamatkan PEEKO kesayangan saya!\l"
	.string "Besar jasa kamu!\p"
	.string "Apa dia? Kamu nak belayar dengan saya?\p"
	.string "Hmhm…\p"
	.string "Kamu ada SURAT untuk DEWFORD dan\n"
	.string "bungkusan untuk SLATEPORT, ya?\p"
	.string "Sibuk betul hidup kamu!\p"
	.string "Tapi, permintaan kamu tu\n"
	.string "langsung tak jadi masalah.\p"
	.string "Kamu dah jumpa orang yang\n"
	.string "tepat! Kita belayar ke DEWFORD.$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "ENCIK BRINEY: DEWFORD, kalau begitu!\p"
	.string "Angkat sauh! PEEKO, kita\n"
	.string "nak belayar, sayang!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "ENCIK BRINEY: Begitu?\n"
	.string "Penghantaran kamu boleh tunggu?\p"
	.string "Beritahu saja saya\n"
	.string "bila kamu nak belayar!$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "ENCIK BRINEY: Ahoi! Saya tahu\n"
	.string "apa yang kamu nak cakap!\p"
	.string "Kamu nak hantar SURAT ke DEWFORD\n"
	.string "dan bungkusan ke SLATEPORT.\p"
	.string "Apa yang kamu perlukan langsung\n"
	.string "tak jadi masalah. Sayalah orangnya!\p"
	.string "Mula-mula, kita belayar ke DEWFORD.$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "ENCIK BRINEY: Ahoi! Saya tahu\n"
	.string "apa yang kamu nak cakap!\p"
	.string "Kamu nak hantar bungkusan\n"
	.string "kepada KAPT. STERN di SLATEPORT.\p"
	.string "Apa yang kamu perlukan langsung\n"
	.string "tak jadi masalah. Sayalah orangnya!\p"
	.string "Mula-mula, kita belayar ke DEWFORD.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "ENCIK BRINEY: Ahoi! Untuk kamu,\n"
	.string "saya sanggup ke laut bila-bila masa!\p"
	.string "Jadi, kawan, kita nak ke mana?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "ENCIK BRINEY: Begitu? Yalah,\n"
	.string "PEEKO terhutang nyawa pada kamu.\p"
	.string "Beritahu saja saya\n"
	.string "bila kamu nak belayar!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO: Pii piihyoro!$"

