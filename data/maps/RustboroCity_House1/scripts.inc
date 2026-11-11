RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Hah? POKéMON saya comel? Mestilah,\n"
	.string "saya tahu.\p"
	.string "Tapi kalau kamu betul-betul nak, saya\n"
	.string "sanggup tukar dengan kamu.\p"
	.string "Saya tukar {STR_VAR_2} saya dengan\n"
	.string "{STR_VAR_1} kalau kamu nak.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Ehehe… Tolong jaga POKéMON saya\n"
	.string "baik-baik.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hah? Itu langsung tak nampak macam\n"
	.string "{STR_VAR_1} pada saya.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Oh, kalau kamu tak nak, tak apa. Tapi\n"
	.string "POKéMON saya comel, tau…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Semua POKéMON boleh jadi comel kalau\n"
	.string "dibela dengan penuh kasih sayang.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Di serata tempat, ada macam-macam\n"
	.string "POKéMON dan manusia.\p"
	.string "Saya rasa itu menarik, jadi saya pergi\n"
	.string "ke serata tempat.$"

