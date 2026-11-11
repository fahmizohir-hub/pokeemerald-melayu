MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Woohoo!\p"
	.string "Orang panggil saya MAMAT HANCUR BATU,\n"
	.string "tapi saya rasa macam diperkecilkan.\p"
	.string "Saya rasa saya patut dihormati sikit,\n"
	.string "macam ABANG HANCUR BATU ke.\p"
	.string "Woohoo!\p"
	.string "Apa-apa pun, POKéMON kamu nampak kuat.\p"
	.string "Saya suka!\n"
	.string "Nah, ambil MESIN TERSEMBUNYI ni!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "HM tu mengandungi HANCUR BATU.\p"
	.string "Kalau kamu jumpa batu besar yang\n"
	.string "menghalang jalan kamu…\p"
	.string "Guna saja move HM tu dan hancurkan\n"
	.string "batu tu dari laluan kamu!\p"
	.string "Betul tu! Hancurkan batu, kata saya!\n"
	.string "Woohoo!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Oh, ya, kalau kamu hancurkan batu,\n"
	.string "mungkin ada POKéMON yang melompat\l"
	.string "keluar dari persembunyian.\p"
	.string "Woohoo!$"

