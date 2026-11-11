GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hei, kamu. Depan sana gelap gelita.\n"
	.string "Susah nak menjelajah.\p"
	.string "Lelaki yang lalu tadi… STEVEN, rasanya\n"
	.string "namanya.\p"
	.string "Dia tahu guna KILAT, jadi dia patutnya\n"
	.string "tak apa-apa, tapi…\p"
	.string "Bagi kami PENDAKI, menolong orang yang\n"
	.string "kami jumpa ialah moto kami.\p"
	.string "Nah, saya berikan ini kepada kamu.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Ajar move tersembunyi KILAT kepada\n"
	.string "POKéMON dan gunakannya.\p"
	.string "Ia boleh menerangi kegelapan gua yang\n"
	.string "paling pekat.\p"
	.string "Tapi untuk menggunakannya, kamu perlu\n"
	.string "LENCANA GIM dari GIM POKéMON DEWFORD.$"

