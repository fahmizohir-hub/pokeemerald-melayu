MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Macam-macam makhluk berkeliaran di\n"
	.string "lereng GUNUNG PYRE…\p"
	.string "Tiada siapa tahu apa yang mungkin\n"
	.string "berlaku. Ambil ini. Untuk kebaikan kamu\l"
	.string "sendiri.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Biar POKéMON kamu pegang TANGKAL SUCI\n"
	.string "itu.\p"
	.string "Ia akan bantu menghalau POKéMON liar.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Kamu datang untuk memberi\n"
	.string "penghormatan kepada roh POKéMON yang\l"
	.string "telah pergi?\p"
	.string "Mesti kamu sangat sayangkan POKéMON\n"
	.string "kamu.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Inilah tempat persemadian\n"
	.string "terakhir ZIGZAGOON saya.\l"
	.string "Saya sayang sangat padanya…$"

