LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "MAY: Eh, hai? {PLAYER}{KUN}, kau\n"
	.string "pun datang membeli-belah?\p"
	.string "Aku beli banyak PATUNG dan POSTER.\p"
	.string "Mestilah aku pun dah tangkap\n"
	.string "banyak POKéMON, dan aku\l"
	.string "latih mereka dengan betul.\p"
	.string "Yang aku risau, kau tu latih POKéMON\n"
	.string "dengan betul ke tak, {PLAYER}{KUN}.\p"
	.string "Jom bertarung. Tunjuk POKéMON\n"
	.string "kau pada aku, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "MAY: Eh, kenapa? {PLAYER}{KUN}, kau tak latih\n"
	.string "POKéMON kau ke?\p"
	.string "Tak berapa bagus untuk seorang\n"
	.string "JURULATIH…$"

LilycoveCity_Text_MayBattleMe:
	.string "MAY: Ayuh, lawan aku, aku nak tengok\n"
	.string "POKéMON kau!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "MAY: POKéMON yang aku latih takkan\n"
	.string "kalah dengan POKéMON kau, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Aku masih ingat pertarungan kita,\n"
	.string "{PLAYER}{KUN}, di LALUAN 103.\p"
	.string "Pertarungan tu yang buat kau jadi\n"
	.string "sekuat ini, {PLAYER}{KUN}, kan?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "MAY: Aku ingat nak balik ke LITTLEROOT\n"
	.string "tak lama lagi.\p"
	.string "Aku dah tangkap banyak POKéMON yang\n"
	.string "bagus, dan POKéDEX aku pun makin\l"
	.string "lengkap, jadi aku nak balik tunjuk pada\l"
	.string "ayah aku.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, kau nak buat apa lepas ni?\p"
	.string "Kumpul semua LENCANA GIM dan sahut\n"
	.string "cabaran LIGA POKéMON?\p"
	.string "Masa kau kumpul LENCANA, {PLAYER}{KUN}, aku\n"
	.string "nak lengkapkan POKéDEX aku. Aku akan\l"
	.string "siapkan sebelum kau!\p"
	.string "Jumpa lagi!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, kau nak buat apa lepas ni?\p"
	.string "Kau nak sahut cabaran LIGA POKéMON?\p"
	.string "Atau, kau nak lengkapkan POKéDEX kau?\p"
	.string "Mungkin aku kalah dengan kau dalam\n"
	.string "pertarungan, tapi aku akan siapkan\l"
	.string "POKéDEX aku dulu!\p"
	.string "Jumpa lagi!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, kau nak buat apa lepas ni?\p"
	.string "Kau nak sahut cabaran BATTLE\n"
	.string "FRONTIER?\p"
	.string "Atau, kau nak lengkapkan POKéDEX kau?\p"
	.string "Mungkin aku kalah dengan kau dalam\n"
	.string "pertarungan, tapi aku akan siapkan\l"
	.string "POKéDEX aku dulu!\p"
	.string "Jumpa lagi!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRENDAN: Eh, hai, {PLAYER} rupanya.\p"
	.string "Aku tengah buat kerja untuk ayah aku.\n"
	.string "Tak, aku bukan beli PATUNG.\p"
	.string "Apa-apa pun, lama tak jumpa.\p"
	.string "Nak bertarung? Kita tengok siapa yang\n"
	.string "latih POKéMON lebih baik.$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRENDAN: Eh, kenapa ni?\n"
	.string "Tak yakin ke?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRENDAN: Nak bertarung? Kita tengok\n"
	.string "siapa yang latih POKéMON lebih baik.$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRENDAN: Alah, kau tahu aku takkan\n"
	.string "kalah dengan {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Huh…\n"
	.string "Kau memang banyak berlatih.\p"
	.string "Pedih juga… Aku jadi JURULATIH lebih\n"
	.string "awal daripada kau…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRENDAN: Aku…\n"
	.string "Aku nak balik ke LITTLEROOT.\p"
	.string "Kau tahu kan aku tolong ayah aku\n"
	.string "siapkan POKéDEX dia. Dah agak lengkap,\l"
	.string "jadi aku patut pergi tunjuk pada dia.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, kau nak buat apa lepas ni?\p"
	.string "Kumpul semua LENCANA GIM dan sahut\n"
	.string "cabaran LIGA POKéMON?\p"
	.string "Mungkin aku pun nak buat macam tu…\p"
	.string "Apa-apa pun, teruskan usaha!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, kau nak buat apa lepas ni?\p"
	.string "Kau dah sekuat ni, kau nak sahut\n"
	.string "cabaran LIGA POKéMON ke?\p"
	.string "Heh, aku pun… kalau aku latih POKéMON\n"
	.string "aku sikit lagi, mesti aku lebih kuat\l"
	.string "daripada kau, {PLAYER}.\p"
	.string "Apa-apa pun, teruskan usaha!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, kau nak buat apa lepas ni?\p"
	.string "Kau nak sahut cabaran\n"
	.string "BATTLE FRONTIER?\p"
	.string "Atau, kau nak lengkapkan POKéDEX kau?\p"
	.string "Kau dah sekuat ni, apa kata\n"
	.string "kau cuba BATTLE FRONTIER?\p"
	.string "Heh, kalau aku latih POKéMON aku\n"
	.string "sikit lagi, aku akan jadi lebih\l"
	.string "kuat daripada kau, {PLAYER}.\p"
	.string "Mungkin aku patut pergi\n"
	.string "ke BATTLE FRONTIER.\p"
	.string "Apa-apa pun, teruskan usaha!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu…\p"
	.string "Hari ni kami pindahkan lagi banyak harta\n"
	.string "rampasan ke MARKAS rahsia kami…\p"
	.string "Si-siapa kau?!\n"
	.string "Aku cakap seorang diri je!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Aku cuma ANAK BUAH, jadi aku tak tahu\n"
	.string "apa yang BOS fikirkan…\p"
	.string "Tapi bila masuk TEAM AQUA, aku tahu aku\n"
	.string "akan dapat peluang buat benda besar!\p"
	.string "Si-siapa kau?!\n"
	.string "Aku cakap seorang diri je!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Hoi, kau!\p"
	.string "Jangan dekat dengan gua di teluk tu!\p"
	.string "Kenapa? Tak payah tanya kenapa!\n"
	.string "Aku orang dewasa, dengar je cakap aku!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Kalau seluruh dunia ni jadi milik kami,\n"
	.string "TEAM AQUA, dunia akan jadi tempat yang\l"
	.string "lebih bahagia untuk POKéMON juga.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Sekarang! WAILMER!\n"
	.string "Lompat keluar dari air!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hah? Kau nak apa?\p"
	.string "Kau kacau latihan kami, jadi boleh tak\n"
	.string "kau berambus?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Ada DEWAN PERTANDINGAN POKéMON\n"
	.string "betul-betul di bandar ni.\p"
	.string "Maknanya, POKéMON yang terlatih\n"
	.string "akan datang dari serata negara.\p"
	.string "Berdebar-debar hati saya!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Kamu dah tengok gua pelik di teluk\n"
	.string "hujung bandar tu?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Saya nak ajar POKéMON saya beberapa\n"
	.string "move baru untuk masuk PERTANDINGAN.\p"
	.string "Jadi, saya nak jumpa PEMADAM MOVE dan\n"
	.string "buat ia lupa move HM.$"

LilycoveCity_Text_ImFromKanto:
	.string "Saya datang dari KANTO.\p"
	.string "Wilayah HOENN ni cantik, banyak\n"
	.string "air dan alamnya hijau subur.\p"
	.string "Hah? Tunggu sekejap…\p"
	.string "Agaknya ada tak POKéMON nadir\n"
	.string "yang hidup di kawasan ni saja?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "TEAM AQUA asyik latih\n"
	.string "WAILMER mereka di teluk tu.\p"
	.string "Kami KELASI tak boleh bawa bot ke\n"
	.string "laut sebab mereka menghalang jalan!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ahoi, kamu tahu tak?\p"
	.string "Ada orang dah halau TEAM AQUA untuk\n"
	.string "kami!\p"
	.string "WAILMER pun dah keluar dari teluk, jadi\n"
	.string "kami boleh bawa bot keluar semula.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Saya tengah tidur lena di rumah\n"
	.string "tumpangan tepi laut, diulit bunyi\l"
	.string "ombak…\p"
	.string "Tiba-tiba ada orang curi POKéMON saya!\p"
	.string "Siapa penculiknya?\n"
	.string "TEAM AQUA? TEAM AQUA ke?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "POKéMON saya yang hilang…\n"
	.string "Ia dah balik tanpa saya sedar!$"

LilycoveCity_Text_ImArtDealer:
	.string "Saya PENIAGA SENI.\p"
	.string "Saya beli dan jual karya seni halus,\n"
	.string "terutamanya lukisan.\p"
	.string "Saya dengar MUZIUM di sini mempamerkan\n"
	.string "karya yang hebat…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Walaupun kita makin tua dan\n"
	.string "berkedut, laut tetap muda selamanya,\l"
	.string "penuh dengan sinar kehidupan…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Enam puluh tahun dulu suami saya\n"
	.string "melamar saya di sini. Laut masih cantik\l"
	.string "macam dulu.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, kamu tahu tentang\n"
	.string "gua pelik di teluk ni?\p"
	.string "Asalnya gua tu terbentuk secara\n"
	.string "semula jadi, tapi kemudian geng\l"
	.string "TEAM AQUA tu datang dan ubah suai.\p"
	.string "Mereka gelar diri mereka\n"
	.string "“TEAM AQUA pencinta alam”!\p"
	.string "Tapi cakap dengan buat\n"
	.string "langsung tak serupa!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Gua di teluk tu…\p"
	.string "Mula-mula saya tak perasan, tapi\n"
	.string "sekarang gua tu dah kosong langsung.\p"
	.string "Geng TEAM AQUA tu\n"
	.string "mesti dah pergi terus.$"

LilycoveCity_Text_CitySign:
	.string "BANDAR LILYCOVE\p"
	.string "“Tempat daratan berakhir\n"
	.string "dan lautan bermula.”$"

LilycoveCity_Text_ContestHallSign:
	.string "DEWAN PERTANDINGAN POKéMON\n"
	.string "“Tempat berkumpul para JURULATIH!”$"

LilycoveCity_Text_MotelSign:
	.string "MOTEL COVE LILY\p"
	.string "“Ingatlah kami, COVE LILY di\n"
	.string "LILYCOVE.”$"

LilycoveCity_Text_MuseumSign:
	.string "MUZIUM LILYCOVE\p"
	.string "“Koleksi Karya Agung POKéMON\n"
	.string "sedang dipamerkan!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "MUZIUM LILYCOVE\p"
	.string "“Koleksi POKéMON {PLAYER}\n"
	.string "sedang dipamerkan!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "PELABUHAN BANDAR LILYCOVE\p"
	.string "“Feri S.S. TIDAL sedang dibina di\n"
	.string "BANDAR SLATEPORT.\p"
	.string "“Perkhidmatan dijadualkan bermula\n"
	.string "tidak lama lagi.”$"

LilycoveCity_Text_HarborSign:
	.string "PELABUHAN BANDAR LILYCOVE\p"
	.string "“Nikmati pelayaran yang menyeronokkan\n"
	.string "dengan feri S.S. TIDAL.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "KELAB PEMINAT JURULATIH POKéMON\p"
	.string "Nama-nama JURULATIH diconteng di\n"
	.string "seluruh papan tanda ni…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "PASAR RAYA LILYCOVE\p"
	.string "“Penuh dengan barangan hebat dan\n"
	.string "keseronokan!\p"
	.string "“Tempat terbaik untuk cari apa yang\n"
	.string "kamu perlukan!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "RUMAH PEMADAM MOVE\p"
	.string "“Move POKéMON yang tak diingini\n"
	.string "dipadam.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Kamu tahu tentang mesin PENGISAR\n"
	.string "BERRY?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Semua orang kena bekerjasama supaya ia\n"
	.string "berpusing lebih laju.\p"
	.string "Saya dengar, makin laju ia berpusing,\n"
	.string "makin bagus {POKEBLOCK} yang kamu dapat.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Mesin tu untuk buat sejenis\n"
	.string "gula-gula yang dipanggil {POKEBLOCK}.\p"
	.string "Kalau kamu beri {POKEBLOCK} yang bagus\n"
	.string "kepada POKéMON, keadaannya\l"
	.string "akan jadi jauh lebih baik.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Saya dengar ada menara di\n"
	.string "laluan laut, entah di mana.\p"
	.string "Namanya TIANG LANGIT, katanya.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Saya nampak menara tinggi\n"
	.string "di sekitar LALUAN 131.\p"
	.string "Itu ke agaknya…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Kami baru sampai di sini untuk berbulan\n"
	.string "madu.\p"
	.string "Kebetulan kami nampak POKéMON jenis\n"
	.string "NAGA terbang tinggi di langit.\p"
	.string "POKéMON hebat macam tu memang hidup di\n"
	.string "wilayah HOENN ke?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Untuk bulan madu ni, kami berjanji nak\n"
	.string "tengok sebanyak mungkin POKéMON nadir.\p"
	.string "Jadi kami gembira sangat dapat tengok\n"
	.string "POKéMON nadir sebaik saja sampai.\p"
	.string "Pendek kata, kami bahagia sangat!$"

