BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "…Kamu nak apa?\p"
	.string "Tak nampak ke kami tengah sibuk ni?\n"
	.string "Urusan kamu tak boleh tunggu nanti?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…Hah? Pada saya, kamu nampak\n"
	.string "macam JURULATIH yang handal.\p"
	.string "Hehe… Dengar sini,\n"
	.string "saya ada satu tawaran.\p"
	.string "Kami ada satu kumpulan kecil di sini, dan\n"
	.string "kami main satu permainan kecil\l"
	.string "berdasarkan apa yang berlaku di\l"
	.string "BATTLE FRONTIER.\p"
	.string "Peraturannya senang sangat.\p"
	.string "Mula-mula, kami pilih satu\n"
	.string "fasiliti di BATTLE FRONTIER.\p"
	.string "Kemudian, setiap seorang pilih\n"
	.string "JURULATIH berlainan yang sedang sahut\l"
	.string "cabaran fasiliti tu, dan bertaruh\l"
	.string "dengan Mata Tarung.\p"
	.string "Sesiapa yang bertaruh pada JURULATIH\n"
	.string "dengan rekod terbaik, dia bolot semua\l"
	.string "Mata Tarung dalam taruhan.\p"
	.string "Senang, kan? Jadi, apa-apa pun…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan mencabar BILIK TARUNG TUNGGAL di\l"
	.string "BATTLE TOWER.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan mencabar BILIK TARUNG GANDA di\l"
	.string "BATTLE TOWER.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan mencabar BILIK TARUNG MULTI di\l"
	.string "BATTLE TOWER.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan menyertai Kejohanan\l"
	.string "TARUNG TUNGGAL di BATTLE DOME.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan menyertai Kejohanan TARUNG GANDA\l"
	.string "di BATTLE DOME.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan menyertai Kejohanan Tukar Tarung\l"
	.string "Tunggal di BATTLE FACTORY.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan menyertai Kejohanan Tukar Tarung\l"
	.string "Ganda di BATTLE FACTORY.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan mencabar DEWAN TARUNG TUNGGAL di\l"
	.string "BATTLE PALACE.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan mencabar DEWAN TARUNG GANDA di\l"
	.string "BATTLE PALACE.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan menyertai Kejohanan KO Set di\l"
	.string "BATTLE ARENA.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan menyertai Pilih Tarung di\l"
	.string "BATTLE PIKE.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Yang saya cari ialah JURULATIH yang\n"
	.string "akan menyertai Misi Tarung di\l"
	.string "BATTLE PYRAMID.\p"
	.string "Tapi setakat ni, saya belum jumpa\n"
	.string "JURULATIH yang ada ciri-ciri juara.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Saya pastikan kamu pun dapat untung.\n"
	.string "Jadi, macam mana? Apa kata kamu sertai\l"
	.string "acara tu untuk saya?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Baik, elok sangat. Jadi, err… Apa\n"
	.string "kata kamu pinjamkan saya sedikit\l"
	.string "Mata Tarung kamu?\p"
	.string "Percayalah, saya akan\n"
	.string "balas budi kamu nanti.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Bagus, bagus! Jadi, berapa\n"
	.string "banyak kamu boleh beri?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Eh, tak, tak, tak!\n"
	.string "Mata Tarung kamu tak cukup!\p"
	.string "Janganlah main-main dan\n"
	.string "buang masa semua orang!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Hehe! Terima kasih\n"
	.string "banyak! Jadi, pergilah!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Cepat pergi ke BILIK TARUNG TUNGGAL\n"
	.string "di BATTLE TOWER sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Cepat pergi ke BILIK TARUNG GANDA\n"
	.string "di BATTLE TOWER sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Cepat pergi ke BILIK TARUNG MULTI\n"
	.string "di BATTLE TOWER sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Cepat pergi ke Kejohanan\n"
	.string "TARUNG TUNGGAL di BATTLE DOME\l"
	.string "sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Cepat pergi ke Kejohanan\n"
	.string "TARUNG GANDA di BATTLE DOME sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Cepat pergi ke Kejohanan Tukar Tarung\n"
	.string "Tunggal di BATTLE FACTORY sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Cepat pergi ke Kejohanan Tukar Tarung\n"
	.string "Ganda di BATTLE FACTORY sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Cepat pergi ke DEWAN TARUNG TUNGGAL\n"
	.string "di BATTLE PALACE sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Cepat pergi ke DEWAN TARUNG GANDA\n"
	.string "di BATTLE PALACE sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Cepat pergi ke Kejohanan KO\n"
	.string "Set di BATTLE ARENA sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Cepat pergi ke Pilih Tarung\n"
	.string "di BATTLE PIKE sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Cepat pergi ke Misi Tarung\n"
	.string "di BATTLE PYRAMID sekarang!\p"
	.string "Kamu wajib menang! Jangan sia-siakan\n"
	.string "peluang! Masa depan kita berdua\l"
	.string "bergantung pada kamu!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, kamu rupanya… Cubaan yang bagus…\p"
	.string "Maaf cakap, tapi saya tak boleh\n"
	.string "pulangkan Mata Tarung kamu…\p"
	.string "Anggaplah ini dorongan untuk\n"
	.string "kita cuba lebih gigih lain kali!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Oh, ya! Helo, juara!\p"
	.string "Saya tahu kamu boleh! Saya tahu kamu\n"
	.string "akan menang! Kita berdua untung besar!\p"
	.string "Saya pulangkan Mata Tarung kamu dan,\n"
	.string "sudah tentu, sedikit tambahan daripada\l"
	.string "saya!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} mendapat\n"
	.string "{STR_VAR_1} Mata Tarung.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Kalau kamu nak sahut cabaran\n"
	.string "lagi, ingatlah saya, ya!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Tak berminat?! Janganlah takut\n"
	.string "sangat nak ambil peluang!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "Saya bertaruh pada JURULATIH yang\n"
	.string "salah lagi!\p"
	.string "Mungkin saya patut bertarung\n"
	.string "biasa saja macam orang lain…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "JURULATIH tu…\p"
	.string "Dia memang bagus, tapi dia terlalu mudah\n"
	.string "gelabah untuk bertahan di BATTLE DOME…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Hihi! Sekali tengok pun saya\n"
	.string "dah tahu siapa pemenang!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "JURULATIH tu semua… Apa yang mereka\n"
	.string "buat? Patutnya mereka sahut cabaran.$"
