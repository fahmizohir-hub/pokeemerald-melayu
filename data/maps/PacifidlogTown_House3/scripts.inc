PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Tengok {STR_VAR_2} ni!\p"
	.string "Ini {STR_VAR_2} yang saya tangkap\n"
	.string "semalam sempena hari jadi saya!\p"
	.string "Oh, saya tahu kamu nak!\n"
	.string "Mestilah, ia tak ternilai!\p"
	.string "Begini. Saya mungkin sanggup\n"
	.string "tukar dengan {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, jadi inilah {STR_VAR_1}?\p"
	.string "Ia agak macam {STR_VAR_2},\n"
	.string "tapi ada sedikit bezanya.\p"
	.string "Terima kasih!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Tak, tak, tak! Saya cuma terima\n"
	.string "{STR_VAR_1} yang sebenar!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, jadi kamu tak nak teruskan?\p"
	.string "Tak apa. Saya bukannya terdesak\n"
	.string "sangat nak bertukar.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Saya tahu saya boleh cari sendiri, tapi…\p"
	.string "Saya betul-betul nak BAGON yang\n"
	.string "ditangkap oleh JURULATIH lain…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Itu POKéDEX ke?\p"
	.string "Kamu dah jumpa banyak\n"
	.string "jenis POKéMON ke?\p"
	.string "Seronoknya jadi macam kamu.$"

