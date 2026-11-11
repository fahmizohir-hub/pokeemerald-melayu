MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Apa salah aku sampai kena jaga\n"
	.string "tempat ni?\p"
	.string "Telinga kiri aku rasa nak terbakar!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Aku dah lemah kena bahang ni…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Pelik tak kami pakai hud dalam gunung\n"
	.string "berapi yang penuh magma ni?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Kami sertai pasukan ni untuk bantu\n"
	.string "ketua capai impiannya yang hebat.\p"
	.string "Aku tak kisah kau orang TEAM AQUA\n"
	.string "atau budak yang kebetulan lalu.\p"
	.string "Sesiapa yang ganggu kami takkan\n"
	.string "terlepas begitu saja!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh, tidak!\n"
	.string "Kau memang tak boleh dipercayai!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Dengar sini.\n"
	.string "TEAM MAGMA yang betul!\p"
	.string "Jangan dengar cakap TEAM AQUA.\n"
	.string "Jangan percaya pembohongan mereka!$"

