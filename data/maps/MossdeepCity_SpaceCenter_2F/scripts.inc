MossdeepCity_SpaceCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_OnFrame
	.byte 0

MossdeepCity_SpaceCenter_2F_OnTransition:
	call_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians
	call_if_eq VAR_MOSSDEEP_SPACE_CENTER_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts
	end

MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians::
	clearflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	setobjectxyperm LOCALID_SPACE_CENTER_2F_SCIENTIST, 5, 3
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_2F_RICH_BOY, 3, 2
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_RICH_BOY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_2F_GENTLEMAN, 1, 3
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_GENTLEMAN, MOVEMENT_TYPE_FACE_RIGHT
	return

MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts::
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_6, 11, 2
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_7, 15, 2
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_5, 13, 4
	return

MossdeepCity_SpaceCenter_2F_OnFrame:
	map_script_2 VAR_MOSSDEEP_SPACE_CENTER_STATE, 1, MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts
	.2byte 0

MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts::
	playse SE_PIN
	applywaitmovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_PLAYER, Common_Movement_Delay48
	msgbox MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
	msgbox MossdeepCity_SpaceCenter_2F_Text_GoodAnswer, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerExit
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 13, 1
	waitstate
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_PlayerExit:
	walk_up
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_5, MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat
	applywaitmovement LOCALID_SPACE_CENTER_GRUNT_5, MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_6, MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat
	applywaitmovement LOCALID_SPACE_CENTER_GRUNT_6, MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_7, MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat
	applywaitmovement LOCALID_SPACE_CENTER_GRUNT_7, MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 2
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_6
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_7
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_5
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoy::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace, MSGBOX_DEFAULT
	release
	end

@ Battle for the below 3 grunts is handled in MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
MossdeepCity_SpaceCenter_2F_EventScript_Grunt6::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt7::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt5::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Tabitha::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Maxie::
	lockall
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_Steven::
	lockall
	goto_if_set FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER, MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel, MSGBOX_DEFAULT
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_NOT_EFFECTIVE
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth
	applywaitmovement LOCALID_SPACE_CENTER_2F_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFight
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth::
	applywaitmovement LOCALID_SPACE_CENTER_2F_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_StevenFight:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	step_end

MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth:
	face_left
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_left
	walk_slow_left
	face_down
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt::
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle::
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle
	special LoadPlayerParty
	goto MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt

MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle::
	special ReducePlayerPartyToSelectedMons
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, SPECIAL_BATTLE_STEVEN
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	frontier_saveparty
	special LoadPlayerParty
	switch VAR_RESULT
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_SPACE_CENTER_MAXIE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SPACE_CENTER_TABITHA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 60
	applymovement LOCALID_SPACE_CENTER_MAXIE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_SPACE_CENTER_TABITHA, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MOSSDEEP_CITY_STATE, 3
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 3
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	removeobject LOCALID_SPACE_CENTER_GRUNT_6
	removeobject LOCALID_SPACE_CENTER_GRUNT_7
	removeobject LOCALID_SPACE_CENTER_GRUNT_5
	removeobject LOCALID_SPACE_CENTER_TABITHA
	removeobject LOCALID_SPACE_CENTER_MAXIE
	setobjectxy LOCALID_SPACE_CENTER_2F_SCIENTIST, 5, 6
	turnobject LOCALID_SPACE_CENTER_2F_SCIENTIST, DIR_SOUTH
	setobjectxy LOCALID_SPACE_CENTER_2F_GENTLEMAN, 11, 8
	turnobject LOCALID_SPACE_CENTER_2F_GENTLEMAN, DIR_NORTH
	setobjectxy LOCALID_SPACE_CENTER_2F_RICH_BOY, 6, 2
	turnobject LOCALID_SPACE_CENTER_2F_RICH_BOY, DIR_NORTH
	call MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer
	fadescreen FADE_FROM_BLACK
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	removeobject LOCALID_SPACE_CENTER_2F_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	removeobject LOCALID_SPACE_CENTER_2F_SCIENTIST
	setobjectxyperm LOCALID_SPACE_CENTER_2F_SCIENTIST, 5, 6
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_SCIENTIST, MOVEMENT_TYPE_WANDER_AROUND
	addobject LOCALID_SPACE_CENTER_2F_SCIENTIST
	fadescreen FADE_FROM_BLACK
#ifdef BUGFIX
	releaseall
#endif
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer::
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth
	case DIR_WEST, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth::
	turnobject LOCALID_SPACE_CENTER_2F_STEVEN, DIR_NORTH
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest::
	turnobject LOCALID_SPACE_CENTER_2F_STEVEN, DIR_EAST
	return

MossdeepCity_SpaceCenter_2F_EventScript_MaxieTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_MAXIE_MOSSDEEP, LOCALID_NONE, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand
	end

MossdeepCity_SpaceCenter_2F_EventScript_TabithaTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_TABITHA_MOSSDEEP, LOCALID_NONE, MossdeepCity_SpaceCenter_Text_TabithaDefeat, MossdeepCity_SpaceCenter_Text_TabithaDefeat
	end

MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall
	call_if_eq VAR_RESULT, FEMALE, MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall
	closemessage
	clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall::
	pokenavcall MatchCall_Text_MayRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall::
	pokenavcall MatchCall_Text_BrendanRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets:
	.string "Cuaca di MOSSDEEP kebanyakannya\n"
	.string "cerah, dan anginnya stabil.\p"
	.string "Memang tempat yang\n"
	.string "sesuai untuk lancar roket.$"

MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel:
	.string "Kenapalah TEAM MAGMA nak\n"
	.string "curi bahan api roket kami?$"

MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut:
	.string "Kalaulah saya muda sikit, saya nak jadi\n"
	.string "angkasawan…\p"
	.string "Tidak… Belum terlambat!\n"
	.string "Saya boleh dan saya akan cuba!$"

MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis:
	.string "Kalau TEAM MAGMA ambil bahan api roket,\n"
	.string "saya tak boleh pergi ke angkasa!\p"
	.string "Kita tak boleh biar mereka\n"
	.string "terlepas begitu saja!$"

MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace:
	.string "Saya harap orang biasa boleh pergi ke\n"
	.string "angkasa satu hari nanti…$"

MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace:
	.string "TEAM MAGMA…\n"
	.string "Mereka pun nak pergi ke angkasa ke?$"

MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn:
	.string "Kau ni kenapa?\p"
	.string "Kau seorang lawan tiga, tapi masih nak\n"
	.string "lawan kami?$"

MossdeepCity_SpaceCenter_2F_Text_GoodAnswer:
	.string "Jawapan yang bagus!\n"
	.string "Itulah yang orang bijak akan buat!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro:
	.string "Kau ni jenis redah saja, ya?\n"
	.string "Okey, aku mula dulu!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat:
	.string "Aku kalah!\n"
	.string "Tapi!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro:
	.string "Awal lagi nak lega!\n"
	.string "Giliran aku pula!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat:
	.string "Aku pun kalah!\n"
	.string "Tapi!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro:
	.string "Mesti kau nak berehat, kan.\n"
	.string "Tapi aku takkan bagi kau rehat!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat:
	.string "Patutnya kami yang berehat…\n"
	.string "Itulah yang patut kami buat…$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle:
	.string "Bertiga pun, tengoklah\n"
	.string "teruknya kami kena.$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle:
	.string "Kami bertiga kalah macam ni…\n"
	.string "Tiga kali lebih memalukan!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle:
	.string "Kami ni berguna ke langsung kepada\n"
	.string "ketua kami?$"

MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou:
	.string "Hehehe!\p"
	.string "Jauh-jauh kami datang nak ambil bahan\n"
	.string "api, kena kacau lagi!\p"
	.string "Kalau kau pun nak masuk campur, kami\n"
	.string "ajar kau sekali!$"

MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere:
	.string "MAXIE: Ke tepi!\n"
	.string "Jangan berani masuk campur!$"

MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel:
	.string "STEVEN: TEAM MAGMA…\p"
	.string "Apa gunanya mencuri bahan api roket?$"

MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano:
	.string "MAXIE: Fufufu… Memandangkan kau ingin\n"
	.string "tahu sangat, biar aku terangkan.\p"
	.string "Kami akan humban semua muatan ini ke\n"
	.string "dalam GUNUNG CHIMNEY!\p"
	.string "Bila GROUDON dah tiada, kami tak\n"
	.string "perlukan gunung timbunan sanga tu lagi!\p"
	.string "Jadi kami akan guna kuasa bahan api ni\n"
	.string "untuk buat gunung berapi itu meletus!\p"
	.string "Pasti dahsyat!$"

MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle:
	.string "STEVEN: {PLAYER}{KUN}!\n"
	.string "Kamu nak tolong saya?\p"
	.string "Mari kita bertarung bersama!\n"
	.string "Kamu dah sedia?$"

MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly:
	.string "STEVEN: Kalau begitu,\n"
	.string "cepat! Bersiap sekarang!$"

MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand:
	.string "Aku cuma mahu…\n"
	.string "Aku cuma mahu meluaskan daratan…$"

MossdeepCity_SpaceCenter_Text_TabithaDefeat:
	.string "Aku tetap bersama ketua kami…$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided:
	.string "MAXIE: Kami gagal buat\n"
	.string "gunung berapi itu meletus…\p"
	.string "Kami gagal kawal GROUDON\n"
	.string "selepas membangkitkannya…\p"
	.string "Salahkah matlamat kami\n"
	.string "untuk meluaskan daratan?\p"
	.string "… … … … … … … … … … … …\p"
	.string "Kalau… Kalau kami,\n"
	.string "TEAM MAGMA, salah… … … … … … …\p"
	.string "Mungkinkah matlamat TEAM AQUA\n"
	.string "meluaskan lautan juga sama silapnya?$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp:
	.string "MAXIE: Baiklah…\n"
	.string "Kami lepaskan bahan api ini…\p"
	.string "Nampaknya ada perkara lebih penting\n"
	.string "yang perlu aku selidik…$"

MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome:
	.string "STEVEN: Fuh, tegang sungguh\n"
	.string "tadi. {PLAYER}{KUN}, terima kasih.\p"
	.string "Saya ada sesuatu nak beri pada\n"
	.string "kamu sebagai tanda terima kasih.\p"
	.string "Datanglah jumpa saya di rumah lepas ni.\p"
	.string "Oh, ya, saya tak tinggal di BANDAR\n"
	.string "RUSTBORO. Saya tinggal di pulau ni.$"
