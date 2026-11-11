SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Siapa kau?\n"
	.string "Kau masuk dari mana?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Kalah pula…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Aku tak jumpa jalan keluar!\p"
	.string "Aku tak takut. Jangan salah faham!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Siapa kau?\n"
	.string "Kau ingat kau nak ke mana?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Aku tak dapat menang!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Kawan aku tertinggal peta dalam kapal\n"
	.string "selam tu!\p"
	.string "Tak guna betul, kan?$"

