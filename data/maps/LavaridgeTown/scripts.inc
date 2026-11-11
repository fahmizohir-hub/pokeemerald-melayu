LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	playse SE_PIN
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	closedoor 12, 15
	waitdooranim
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	playse SE_PIN
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "MAY: {PLAYER}{KUN}! Lama tak jumpa!\p"
	.string "Oh? Masa aku pergi kolam air panas,\n"
	.string "kau dah dapat LENCANA GIM LAVARIDGE.\p"
	.string "Mesti kau dah kumpul\n"
	.string "POKéMON yang bagus…\l"
	.string "Tak, aku rasa kau yang latih mereka.\p"
	.string "Rasanya tak apa kalau aku bagi\n"
	.string "kau benda ni.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "MAY: Dengan GO-GOGAL tu, kau takkan\n"
	.string "ada masalah nak lalu gurun dekat\l"
	.string "LALUAN 111.\p"
	.string "Tapi, wah, {PLAYER}{KUN}…\n"
	.string "Kau cabar GIM-GIM…\p"
	.string "Kau berusaha keras sebab tak nak\n"
	.string "kalah dengan aku, kan!\p"
	.string "{PLAYER}{KUN}, rasanya aku patut cabar\n"
	.string "ayah kau di GIM PETALBURG.\p"
	.string "Jumpa lagi!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRENDAN: {PLAYER}, hei, lama tak jumpa.\n"
	.string "Apa khabar?\p"
	.string "Hmm…\n"
	.string "Boleh tahan koleksi LENCANA kau.\p"
	.string "Baiklah.\n"
	.string "Kau ambillah benda ni.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRENDAN: Simpan benda tu kalau kau\n"
	.string "bercadang nak masuk gurun dekat\l"
	.string "LALUAN 111.\p"
	.string "Mesti ada POKéMON yang hanya hidup\n"
	.string "di gurun.\l"
	.string "Cubalah cari mereka.\p"
	.string "Aku pula…\n"
	.string "Aku tengah fikir nak cabar NORMAN,\l"
	.string "KETUA GIM PETALBURG.\p"
	.string "Tak macam kau, {PLAYER}, ayah kau\n"
	.string "nampak memang betul-betul hebat.\p"
	.string "Jumpa lagi!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Saya ada sebiji TELUR di sini.\p"
	.string "Saya harap ia menetas kalau ditutup\n"
	.string "pasir panas di tepi kolam air panas.\l"
	.string "Tapi nampaknya itu tak cukup…\p"
	.string "Saya dengar lebih baik kalau ia\n"
	.string "disimpan bersama POKéMON dan\l"
	.string "dibawa ke sana sini.\p"
	.string "Kamu seorang JURULATIH, kan?\n"
	.string "POKéMON kamu nampak sangat bertenaga.\p"
	.string "Jadi, bagaimana?\n"
	.string "Sudi kamu ambil TELUR ni untuk ditetas?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Bagus! Saya harap kamu banyak berjalan\n"
	.string "dengan TELUR ni!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} menerima TELUR itu.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh? POKéMON kamu terlalu banyak.\n"
	.string "Tak ada ruang untuk TELUR ni…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Kalau begitu, terpulanglah…\p"
	.string "Kalau kamu ubah fikiran nak tetaskan\n"
	.string "TELUR ni, saya ada di sini.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Sekali-sekala, ada TELUR dijumpai di\n"
	.string "TASKA POKéMON.\p"
	.string "Sekurang-kurangnya, itulah khabarnya.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "Kami ambil air panas sebanyak mana yang\n"
	.string "perlu, tapi kolam ni tak pernah kering.\p"
	.string "Ajaib, kan?\p"
	.string "Kolam air panas ni muncul dekat gunung\n"
	.string "berapi yang aktif. Urat air bawah tanah\l"
	.string "dipanaskan oleh magma, lalu memancut\l"
	.string "keluar jadi kolam air panas.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Ditimbus dalam pasir panas ni…\n"
	.string "Haih…\p"
	.string "Hangatnya, macam syurga…\p"
	.string "Eh? Gyaah! Aduh!\p"
	.string "Ada POKéMON gigit punggung saya!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, kamu suka kolam air panas, ya?\p"
	.string "Mengejutkan untuk orang semuda\n"
	.string "kamu.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Saya mandi di kolam air panas setiap\n"
	.string "hari.\p"
	.string "Saya nak jadi KETUA GIM yang cantik\n"
	.string "dan kuat macam FLANNERY.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Kalau orang masukkan POKéMON dalam\n"
	.string "kolam air panas, mesti jadi pelik.\p"
	.string "Mungkin jadi mandian elektrik, mandian\n"
	.string "buih, atau mandian lava pun ada…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Kata mereka, kolam air panas ni bagus\n"
	.string "untuk menenangkan saraf tegang,\l"
	.string "melegakan otot sakit, selesaikan\l"
	.string "masalah cinta, dan menarik\l"
	.string "rezeki…$"

LavaridgeTown_Text_TownSign:
	.string "PEKAN LAVARIDGE\p"
	.string "“KOLAM AIR PANAS PUSAT POKéMON\n"
	.string "Tempat terbaik untuk berehat!”$"

LavaridgeTown_Text_GymSign:
	.string "GIM POKéMON PEKAN LAVARIDGE\n"
	.string "KETUA: FLANNERY\l"
	.string "“Jiwa berapi yang membara!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "KEDAI HERBA POKéMON\n"
	.string "“Lagi pahit--lagi mujarab!”$"

