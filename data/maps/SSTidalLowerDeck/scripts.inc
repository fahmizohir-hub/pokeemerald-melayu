SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrgh! Saya dah muak dan penat\n"
	.string "bersihkan tempat sebesar ni!\p"
	.string "Jom bertarung sekejap!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Adik, abang kalah!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Kamilah ADIK-BERADIK PEMBERSIH!\p"
	.string "Yang tua tuang sabun, yang muda pula\n"
	.string "gosok!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Ini bahagian paling bawah badan kapal.\n"
	.string "Ruangnya luas.\l"
	.string "Sesuai untuk bertarung POKéMON.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Abang, adik kalah!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Kamilah ADIK-BERADIK PEMBERSIH!\p"
	.string "Yang tua tuang sabun, yang muda pula\n"
	.string "gosok!$"

