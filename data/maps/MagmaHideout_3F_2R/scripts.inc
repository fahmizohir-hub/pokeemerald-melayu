MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Aku faham semua yang ketua kami\n"
	.string "cakap. Tapi kau tahu tak?\p"
	.string "Gali POKéMON yang super purba dan\n"
	.string "rampas METEORIT orang…\p"
	.string "Aku rasa kami dah melampau sikit.\n"
	.string "Apa pendapat kau?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Yalah, aku rasa ada yang tak kena\n"
	.string "dengan apa yang kami buat.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Kalah pada kau buat fikiran aku jelas.\p"
	.string "Lain kali aku jumpa ketua kami, aku\n"
	.string "nak tanya dia tentang kerja kami.$"

