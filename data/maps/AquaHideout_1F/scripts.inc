AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Apa? Apa? Kau nak apa dengan\n"
	.string "TEAM AQUA?\p"
	.string "BOS kami tak ada di sini! Dia dah pergi\n"
	.string "rampas sesuatu yang penting!\p"
	.string "… …\n"
	.string "Dia pergi mana?\p"
	.string "Wahaha! Kau ingat aku nak beritahu\n"
	.string "benda sepenting tu?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Apa? Apa?\n"
	.string "Kau ni anak buah TEAM MAGMA ke?\p"
	.string "Aku dengar TEAM MAGMA nak bangkitkan\n"
	.string "POKéMON yang dahsyat di MARKAS mereka.\p"
	.string "Tapi di mana agaknya MARKAS mereka?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Apa? Apa? Kau nak apa dengan\n"
	.string "TEAM AQUA?\p"
	.string "BOS kami tak ada di sini!\n"
	.string "Dia dah pergi curi kapal selam!\p"
	.string "… …\n"
	.string "Dia pergi mana?\p"
	.string "Wahaha! Kau ingat aku nak beritahu\n"
	.string "benda sepenting tu?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Apa? Apa? Kau nak apa dengan\n"
	.string "TEAM AQUA?\p"
	.string "BOS kami tak ada di sini! Dia dalam\n"
	.string "perjalanan ke GUNUNG PYRE di\l"
	.string "LALUAN 122!\p"
	.string "… …\n"
	.string "Kenapa dia pergi?\p"
	.string "Wahaha! Kau ingat aku nak beritahu\n"
	.string "benda sepenting tu?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Apa? Apa?\n"
	.string "Kau ni anak buah TEAM MAGMA ke?\p"
	.string "Aku dengar TEAM MAGMA sedang memburu\n"
	.string "POKéMON yang dahsyat di\l"
	.string "GUNUNG CHIMNEY.\p"
	.string "Tapi POKéMON tu macam mana rupanya?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Apa? Apa? Kau nak apa dengan\n"
	.string "TEAM AQUA?\p"
	.string "BOS kami tak ada di sini! Dia dalam\n"
	.string "perjalanan ke BANDAR SLATEPORT!\p"
	.string "… …\n"
	.string "Kenapa dia pergi?\p"
	.string "Wahaha! Kau ingat aku nak beritahu\n"
	.string "benda sepenting tu?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Aiyoyoi!\n"
	.string "Ada orang mencurigakan!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr…\n"
	.string "Aku kalah!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "Aku kalah demi PASUKAN, tapi tugas aku\n"
	.string "dah selesai…$"

