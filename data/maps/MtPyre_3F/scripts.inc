MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "Suasana gunung yang kuat ni dah\n"
	.string "tingkatkan kuasa psikik saya!\p"
	.string "Budak kecil macam kamu…\n"
	.string "Kamu mimpi nak menang?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Saya tenggelam dalam rasa kasihan pada\n"
	.string "diri…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Kuasa psikik saya pasti dah bertambah\n"
	.string "berlipat kali ganda, tapi…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Ini bukan tempat untuk budak-budak,\n"
	.string "apatah lagi kamu!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Saya kalah dengan begitu mudah…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Maknanya latihan saya masih belum\n"
	.string "cukup…\p"
	.string "Saya kena terus berusaha ke puncak…\p"
	.string "Ayuh, saya!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Kenapa kamu datang ke sini?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Hebat sungguh!\n"
	.string "Kamu JURULATIH yang sangat istimewa.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "POKéMON yang dah tiada di dunia ini.\n"
	.string "POKéMON yang bersama kamu sekarang.\p"
	.string "Dan POKéMON yang akan kamu temui pada\n"
	.string "masa depan…\p"
	.string "Semuanya patut disayangi sama rata.\n"
	.string "Tolong ingat itu.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Saya nak tengok POKéMON kamu bila\n"
	.string "mereka dah lebih membesar…\p"
	.string "Tolong, saya perlu tengok POKéNAV kamu.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, kamu rupanya…\p"
	.string "Kamu datang nak tunjuk POKéMON kamu\n"
	.string "yang dah membesar?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Hebatnya!\n"
	.string "Kamu memang orang yang istimewa.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON yang dah tiada di dunia ini.\n"
	.string "POKéMON yang bersama kamu sekarang.\p"
	.string "Dan POKéMON yang akan kamu temui pada\n"
	.string "masa depan…\p"
	.string "Semuanya patut disayangi sama rata.\n"
	.string "Nampaknya kamu masih ingat.$"

