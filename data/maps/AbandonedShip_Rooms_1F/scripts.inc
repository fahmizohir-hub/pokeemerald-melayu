AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Kapal macam ni jarang ada, jadi saya nak\n"
	.string "tengok-tengok.\p"
	.string "Hmhm…\n"
	.string "Nampaknya ada kabin lain…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Apa yang buat kamu datang ke sini?\n"
	.string "Mesti kamu ni suka ambil tahu!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Bukan setakat suka\n"
	.string "ambil tahu, kuat pula tu…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "Lelaki di bilik sebelah tu…\p"
	.string "Katanya dia cuma melancong,\n"
	.string "tapi saya tak berapa percaya.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Kamu memang JURULATIH yang hebat!\n"
	.string "Biar saya daftar kamu buat kenangan!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Apa yang buat kamu datang balik?\n"
	.string "Mesti kamu memang suka ambil tahu!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Kamu ni kuat sangat, kan?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Saya pasti lelaki tu ada apa-apa!\n"
	.string "Gerak-gerinya mencurigakan!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah!\n"
	.string "Saya dah kantoi! …Eh?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh, kamu bukan mak saya.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Mak marah saya, jadi saya lari.\n"
	.string "Jangan beritahu sesiapa saya di sini!$"

