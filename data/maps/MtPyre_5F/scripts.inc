MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "Saya suka semua benda yang\n"
	.string "menyeramkan… Macam satu penyakit…\p"
	.string "Bila saya di sini…\n"
	.string "Saya menggigil ketakutan…$"

MtPyre_4F_Text_TashaDefeat:
	.string "Kalah… saya tak suka…$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Saya nak tengok benda yang ngeri… Saya\n"
	.string "tak boleh pergi…\p"
	.string "Tinggallah…\n"
	.string "Sudikah kamu tinggal bersama saya?$"

