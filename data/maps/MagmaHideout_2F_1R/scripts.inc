MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Apa, apa, apa?\p"
	.string "Hanya ahli TEAM MAGMA dibenarkan\n"
	.string "berada di sini!\p"
	.string "Tapi kau tak pakai pakaian seragam\n"
	.string "TEAM MAGMA…\p"
	.string "Kau memang mencurigakan!\n"
	.string "Lawan aku!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiyiyi…\n"
	.string "Maruah aku sebagai ahli TEAM MAGMA…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Kalau kau selalu rasa sejuk, baik kau\n"
	.string "sertai TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Berhenti di situ!\p"
	.string "Kau ingat aku nak diam saja dan\n"
	.string "biar kau lalu dengan senang?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Ooh wah!\n"
	.string "Aku mengaku kalah!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Mungkin lebih baik kalau aku biar\n"
	.string "saja kau lalu tanpa dicabar…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ahah!\n"
	.string "Penceroboh!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Aku dah kalah.\p"
	.string "Perlu ke aku terus berlari\n"
	.string "berpusing-pusing?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh, oh!\n"
	.string "Penceroboh!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Rungut…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "Sebenarnya aku bukan pakar bertarung…$"

