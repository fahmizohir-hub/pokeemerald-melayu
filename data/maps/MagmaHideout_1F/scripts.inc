MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Masa TEAM MAGMA ambil kehadiran, tugas\n"
	.string "kawalan penting dibahagi ikut siapa\l"
	.string "beratur dulu.\p"
	.string "Sebab tu aku tersadai di sudut ni.\n"
	.string "Aku selalu lambat masa kehadiran!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Aku pun selalu lambat masa sesi\n"
	.string "latihan!\p"
	.string "Malu nak cakap, tapi aku memang lemah…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Okeylah, lepas ni aku cuba lebih\n"
	.string "berusaha sikit…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Ketua suruh kami gali GUNUNG\n"
	.string "CHIMNEY, jadi kami gali dan gali.\p"
	.string "Masa menggali, kami terjumpa sesuatu\n"
	.string "yang buat kami tercengang!\p"
	.string "Apa yang kami jumpa?\p"
	.string "Fuhahaha!\n"
	.string "Aku beritahu kalau kau kalahkan aku!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Arrgh!\n"
	.string "Aku tumbang!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Tak jadilah aku beritahu.\n"
	.string "Kau akan tahu bila sampai nanti!\p"
	.string "Lebih baik simpan kejutan sampai\n"
	.string "ke akhir, betul tak?$"

