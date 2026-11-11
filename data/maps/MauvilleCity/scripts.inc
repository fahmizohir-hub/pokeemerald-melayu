MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	playse SE_PIN
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applywaitmovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applywaitmovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
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

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "PAKCIK: Budak ni jadi lebih bersemangat\n"
	.string "sebab POKéMON, agaknya…\l"
	.string "Tapi sekarang terlebih semangat pula…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "WALLY: Alaa, PAKCIK, bolehlah?\p"
	.string "Saya nak cabar GIM ni dan tengok\n"
	.string "sejauh mana saya dah berkembang.\p"
	.string "Bolehlah? Boleh, kan?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "PAKCIK: Sabar dulu, WALLY.\p"
	.string "Sejak kamu mula hidup dengan POKéMON,\n"
	.string "kamu memang dah jadi jauh lebih kuat.\p"
	.string "Tapi tak rasa ke kamu terlalu memaksa\n"
	.string "diri kalau tiba-tiba nak cabar GIM?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "WALLY: Saya tak memaksa diri.\p"
	.string "Kalau saya bergabung tenaga dengan\n"
	.string "RALTS, kami boleh kalahkan sesiapa\l"
	.string "saja!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "WALLY: Oh! Hai, {PLAYER}!\p"
	.string "Saya dah jadi jauh lebih kuat sejak kita\n"
	.string "berjumpa.\p"
	.string "{PLAYER}, saya nak kamu dan PAKCIK saya\n"
	.string "nampak sendiri.\p"
	.string "{PLAYER}, tolonglah, boleh kamu\n"
	.string "bertarung dengan saya?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "WALLY: Oh… Kalau kamu tak bertarung,\n"
	.string "{PLAYER}, PAKCIK saya takkan tahu\l"
	.string "yang saya dah betul-betul kuat.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "PAKCIK: {PLAYER}{KUN}, kan?\n"
	.string "Boleh saya minta kamu bertarung\l"
	.string "dengan WALLY sekali ni saja?\p"
	.string "Saya rasa dia takkan dengar apa-apa\n"
	.string "nasihat dalam keadaan begini.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "WALLY: {PLAYER}, tolonglah!\n"
	.string "Bertarunglah dengan saya.$"

MauvilleCity_Text_WallyHereICome:
	.string "WALLY: {PLAYER}, terima kasih.\p"
	.string "Baiklah… Saya datang!$"

MauvilleCity_Text_WallyDefeat:
	.string "WALLY: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "Saya kalah…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "WALLY: PAKCIK…\n"
	.string "Saya balik ke VERDANTURF…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, terima kasih.\n"
	.string "Jadi JURULATIH ni susah, kan?\p"
	.string "Tak cukup sekadar ada POKéMON dan\n"
	.string "suruh mereka bertarung. Bukan itu\l"
	.string "maknanya jadi JURULATIH sebenar.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "PAKCIK: WALLY, tak perlu kecewa dengan\n"
	.string "diri sendiri.\p"
	.string "Lagipun, apa yang boleh halang kamu\n"
	.string "jadi makin kuat?\p"
	.string "Jom, kita balik.\n"
	.string "Semua orang tengah tunggu kamu.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "PAKCIK: {PLAYER}{KUN}, baru saya teringat,\n"
	.string "kamu mesti JURULATIH yang tolong\l"
	.string "tengokkan WALLY masa dia tangkap\l"
	.string "POKéMON dia.\p"
	.string "Datanglah melawat kami di VERDANTURF\n"
	.string "nanti. Saya pasti WALLY suka.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Bip!\p"
	.string "WALLY: Oh, helo, {PLAYER}!\p"
	.string "Saya cuma nak beritahu yang pakcik\n"
	.string "saya belikan saya POKéNAV!\p"
	.string "Sekarang saya boleh hubungi kamu\n"
	.string "bila-bila masa, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Klik!$"

MauvilleCity_Text_RegisteredWally:
	.string "WALLY didaftarkan\n"
	.string "dalam POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT: Hehe…\n"
	.string "Saya tengok pertarungan tadi!\p"
	.string "Kamu kawan budak WALLY tu, kan?\p"
	.string "Tapi kamu tak berlembut langsung dan\n"
	.string "kalahkan dia dengan hebat.\p"
	.string "Ya! Itulah maksud sebenar pertarungan\n"
	.string "POKéMON!\p"
	.string "Saya kagum dengan JURULATIH macam tu!\p"
	.string "… … … … … …\n"
	.string "Saya akan sokong kamu!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WATTSON: Oh, {PLAYER}{KUN}!\n"
	.string "Kamu nampak penuh tenaga!\l"
	.string "Bagus tu, wahahahaha!\p"
	.string "Baiklah! Saya dah buat keputusan!\n"
	.string "Saya perlukan bantuan, {PLAYER}{KUN}!\p"
	.string "BANDAR MAUVILLE ada kawasan bawah\n"
	.string "tanah bernama MAUVILLE BARU.\p"
	.string "{PLAYER}{KUN}, saya nak kamu pergi ke sana\n"
	.string "dan matikan PENJANA.\p"
	.string "PENJANA tu dah buat hal sikit.\n"
	.string "Makin lama makin bahaya.\p"
	.string "Nah, ini KUNCI untuk masuk ke MAUVILLE\n"
	.string "BARU.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WATTSON: Jangan risau.\n"
	.string "Takkan susah punya bagi kamu.\p"
	.string "Pintu masuk MAUVILLE BARU tak jauh,\n"
	.string "guna LUNCURAN OMBAK sikit saja dari\l"
	.string "LALUAN 110.\p"
	.string "Itu saja, saya percayakan kamu!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WATTSON: Wahahahaha!\p"
	.string "Saya dah agak, {PLAYER}{KUN}! Memang\n"
	.string "tak salah saya minta tolong kamu!\p"
	.string "Ini tanda terima kasih saya, TM yang\n"
	.string "mengandungi PANAH PETIR!\p"
	.string "Ambillah, kamu layak!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WATTSON: Wahahahaha!\p"
	.string "Saya gembira sungguh tengok orang\n"
	.string "muda tampil dan ambil tanggungjawab!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Seronok juga bertarung POKéMON dan\n"
	.string "sebagainya…\p"
	.string "Tapi kalau POKéMON kamu cedera, kamu\n"
	.string "kena rawat sampai sihat semula.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Jalan di bandar ni menghala ke utara\n"
	.string "dan selatan, timur dan barat.\p"
	.string "Sebab tu, macam-macam orang lalu di\n"
	.string "sini.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Kamu dah pergi KEDAI BASIKAL RYDEL?\p"
	.string "RYDEL, tuan kedai tu, memang sangat\n"
	.string "pemurah.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Walaupun kamu naik BASIKAL, POKéMON\n"
	.string "liar masih boleh serang kamu.$"

MauvilleCity_Text_CitySign:
	.string "BANDAR MAUVILLE\n"
	.string "“Bandar ceria yang bersinar terang!”$"

MauvilleCity_Text_GymSign:
	.string "GIM POKéMON BANDAR MAUVILLE\n"
	.string "KETUA: WATTSON\l"
	.string "“Lelaki ceria yang menyetrum!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Redah batu kerikil dan gegarkan jiwa!”\n"
	.string "KEDAI BASIKAL RYDEL$"

MauvilleCity_Text_GameCornerSign:
	.string "“Tempat main untuk semua!”\n"
	.string "SUDUT PERMAINAN MAUVILLE$"

MauvilleCity_Text_ExplainTV:
	.string "Hai, kamu selalu tengok TV tak?\p"
	.string "Ada banyak rancangan baru yang menarik\n"
	.string "sekarang.\p"
	.string "TV memang best. Tiba-tiba saja saya\n"
	.string "nampak kawan-kawan saya masuk TV.\p"
	.string "Kadang-kadang, mereka masukkan kamu\n"
	.string "dalam TV tanpa beritahu pun.\p"
	.string "Saya harap satu hari nanti saya masuk\n"
	.string "TV.\p"
	.string "Sebab tu saya rasa kamu patut tengok\n"
	.string "TV bila-bila ada peluang.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Hai, kamu ada tengok TV?$"
