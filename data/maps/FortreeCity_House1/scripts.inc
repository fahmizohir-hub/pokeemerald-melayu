FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Wargghhh! Saya nak sangat!\n"
	.string "Saya mesti dapatkan {STR_VAR_1}!\l"
	.string "Saya sanggup buat apa saja!\p"
	.string "…Err… Kamu dengar tak tadi?\n"
	.string "Jeritan dari lubuk hati saya?\p"
	.string "Bila dah dengar tu, kamu mesti nak\n"
	.string "tukar {STR_VAR_1} kamu dengan\l"
	.string "{STR_VAR_2} saya, kan?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Oh, yeah, mantap!\p"
	.string "{STR_VAR_1}, selamat datang!\n"
	.string "{STR_VAR_2}, jaga diri baik-baik!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Err, tak, rasanya bukan.\n"
	.string "Itu bukan {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Tak nak? Kamu tak nak tukar?\n"
	.string "Walaupun saya dah luah isi hati?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Mulai saat ini, saya akan buat\n"
	.string "VOLBEAT jadi super kuat!\p"
	.string "Harap kamu pun buat begitu dengan\n"
	.string "PLUSLE!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Bertukar POKéMON dengan orang lain…\p"
	.string "Macam bertukar kenangan sendiri\n"
	.string "dengan orang lain.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gumomoh?$"

