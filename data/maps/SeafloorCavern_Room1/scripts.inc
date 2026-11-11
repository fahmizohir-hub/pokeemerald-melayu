SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Kami tak perlukan budak di sini!\n"
	.string "Baliklah cepat!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Aku nak balik…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Aku nak naik pangkat supaya boleh\n"
	.string "arah-arahkan ANAK BUAH lain…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Kapal selam tu… Sempit gila dalamnya.\n"
	.string "Sakit satu badan aku!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Kalah ni lagi buat aku sakit hati!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Kapal selam yang kami rampas tu,\n"
	.string "memang seksa nak naik.\l"
	.string "Sempit sangat dalam tu!$"

