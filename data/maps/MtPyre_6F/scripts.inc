MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Bila saya di sini…\n"
	.string "Satu kuasa aneh mengalir ke dalam diri…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "Kuasa itu semakin surut…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Mungkin kuasa itu datang daripada roh\n"
	.string "POKéMON yang tidur gelisah di sini…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… Saya kalah, tapi… Saya ada\n"
	.string "kebolehan kecil ni…\p"
	.string "Tanpa sentuh POKéNAV kamu pun… Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Di belakang kamu…\n"
	.string "Apa itu…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Sesuatu dah lenyap…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "POKéMON yang bersemadi di sini…\n"
	.string "Kadang-kadang, mereka bermain…$"

MtPyre_6F_Text_CedricIntro:
	.string "Kamu sesat ke?\n"
	.string "Jangan takut, saya ada di sini!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Kamu tak sesat ke?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Saya ingat JURULATIH yang sesat mesti\n"
	.string "panik dan senang dikalahkan.\p"
	.string "Itu taktik kotor, saya takkan cuba\n"
	.string "lagi…$"

