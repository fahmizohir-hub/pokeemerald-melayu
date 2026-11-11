SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "POKéMON saya bersifat GOPOH.\p"
	.string "KELAJUANNYA lebih tinggi berbanding\n"
	.string "POKéMON saya yang lain.\p"
	.string "Mungkin sifat ada kaitan dengan\n"
	.string "kenaikan stat POKéMON.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Kamu JURULATIH, kan?\p"
	.string "Dah sampai BANDAR SLATEPORT, mesti\n"
	.string "kamu nak pergi ke KHEMAH BATTLE.$"

