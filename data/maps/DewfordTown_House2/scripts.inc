DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Puaskan mata kamu dengan benda ni!\p"
	.string "Ini SKARF SUTERA. Fesyen paling terkini,\n"
	.string "yeah!\p"
	.string "Oh, saya nampak mata kamu bersinar!\n"
	.string "Kamu menghargai gaya saya yang\l"
	.string "mempesona!\p"
	.string "Oh, kamu memang menyenangkan! Nah,\n"
	.string "saya nak kamu ambil ni!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, beg kamu tak ada ruang?\p"
	.string "Dengar sini, SKARF ni wajib ada! Saya\n"
	.string "sanggup jual semua barang saya demi\l"
	.string "mendapatkannya!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "SKARF SUTERA menaikkan kuasa move\n"
	.string "jenis NORMAL.\p"
	.string "SKARF yang hebat ni sesuai dengan\n"
	.string "hampir semua POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wah, kamu sanggup seberang laut untuk\n"
	.string "datang ke DEWFORD?\p"
	.string "Kamu datang sebab dengar pasal BRAWLY,\n"
	.string "ya?\p"
	.string "Dia segak sangat… Semua orang\n"
	.string "memujanya.$"

