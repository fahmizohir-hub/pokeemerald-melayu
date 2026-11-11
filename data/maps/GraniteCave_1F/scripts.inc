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
	.string "Lelaki yang lalu tadi… STEVEN,\n"
	.string "rasanya namanya.\p"
	.string "Dia tahu guna KILAT, jadi mesti dia tak\n"
	.string "apa-apa, tapi…\p"
	.string "Kami PENDAKI ni, moto kami tolong\n"
	.string "sesiapa yang kami jumpa.\p"
	.string "Nah, ambil ni.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Ajar HM KILAT pada POKéMON,\n"
	.string "kemudian gunakan.\p"
	.string "Ia boleh menerangi kegelapan gua yang\n"
	.string "paling pekat.\p"
	.string "Tapi untuk guna, kamu perlu LENCANA GIM\n"
	.string "dari GIM POKéMON DEWFORD.$"

