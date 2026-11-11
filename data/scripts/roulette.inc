Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	end

Roulette_Text_PlayMinimumWagerIsX::
	.string "Taruhan minimum di meja ini ialah\n"
	.string "{STR_VAR_1}. Kamu nak main?$"

Roulette_Text_NotEnoughCoins::
	.string "SYILING kamu tak cukup.$"

Roulette_Text_SpecialRateTable::
	.string "Meja kadar istimewa sekarang!$"

Roulette_Text_ControlsInstruction::
	.string "Letak taruhan dengan + Pad Kawalan,\n"
	.string "kemudian tekan Butang A.$"

Roulette_Text_ItsAHit::
	.string "Kena!$"

Roulette_Text_Jackpot::
	.string "Jackpot!$"

Roulette_Text_NothingDoing::
	.string "Tak kena!$"

Roulette_Text_YouveWonXCoins::
	.string "Kamu menang {STR_VAR_1} SYILING!$"

Roulette_Text_NoCoinsLeft::
	.string "SYILING dah habis…$"

Roulette_Text_KeepPlaying::
	.string "Nak terus main?$"

Roulette_Text_BoardWillBeCleared::
	.string "Papan RULET akan dikosongkan.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "Kamu tak ada BEKAS SYILING.$"

Roulette_Text_CoinCaseIsFull::
	.string "BEKAS SYILING kamu dah penuh!\n"
	.string "Syiling boleh ditukar dengan hadiah.$"
