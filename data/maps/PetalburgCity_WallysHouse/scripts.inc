PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Kamu ni… Ah, mesti kamu {PLAYER}{KUN}, kan?\p"
	.string "Terima kasih sebab bermain\n"
	.string "dengan WALLY tadi.\p"
	.string "Dia memang lemah dan selalu\n"
	.string "sakit sejak kecil lagi.\p"
	.string "Kami hantar dia tinggal dengan saudara\n"
	.string "saya di PEKAN VERDANTURF buat\l"
	.string "sementara.\p"
	.string "Udara di sana jauh lebih\n"
	.string "bersih daripada di sini.\p"
	.string "Apa? Mana WALLY? Dia dah\n"
	.string "pun bertolak, WALLY kami tu.\p"
	.string "Agaknya dah sampai mana dia sekarang?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Apa khabar agaknya WALLY kami?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Maafkan kami sebab\n"
	.string "bawa kamu ke sini begini.\p"
	.string "Tapi WALLY kami dah jadi sangat sihat\n"
	.string "sejak dia pergi ke PEKAN VERDANTURF.\p"
	.string "Semua ini berkat kamu!\p"
	.string "Masa WALLY tinggalkan pekan, kamu\n"
	.string "tolong dia tangkap POKéMON, kan?\p"
	.string "Saya rasa itu buat WALLY\n"
	.string "betul-betul gembira.\p"
	.string "Sebenarnya, bukan WALLY saja.\n"
	.string "Saya, ayahnya, pun gembira.\p"
	.string "Gembira sebab dia dapat\n"
	.string "kawan sebaik kamu.\p"
	.string "Ini bukan rasuah atau apa, tapi\n"
	.string "saya betul-betul nak kamu ambil ini.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Kalau POKéMON kamu boleh guna LUNCUR\n"
	.string "OMBAK, kamu boleh pergi ke macam-macam\l"
	.string "tempat.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "WALLY akan balik tak lama lagi.\n"
	.string "Saya tak sabar menunggunya.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Eh? Kamu jumpa WALLY\n"
	.string "di BANDAR EVER GRANDE?\p"
	.string "Alah, {PLAYER}{KUN}, jangan bergurau.\p"
	.string "Mungkin dia dah sihat, tapi dia tak\n"
	.string "boleh pergi sejauh itu seorang diri.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "WALLY betul-betul gembira masa dia\n"
	.string "beritahu kami dia dapat tangkap\l"
	.string "POKéMON.\p"
	.string "Dah lama saya tak tengok\n"
	.string "dia senyum macam tu.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Tolong rahsiakan ini\n"
	.string "daripada suami saya…\p"
	.string "Tapi WALLY kami tinggalkan PEKAN\n"
	.string "VERDANTURF tanpa beritahu sesiapa.\p"
	.string "Walaupun WALLY tu lemah,\n"
	.string "semangatnya kuat, tau.\p"
	.string "Saya pasti dia akan pulang\n"
	.string "dengan selamat satu hari nanti!$"

