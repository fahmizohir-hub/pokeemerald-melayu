MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.\p"
	.string "Kamu mesti {PLAYER}.\n"
	.string "Ada tiket di sini untuk kamu.$"

sText_MysticTicketUseAtPort:
	.string "Nampaknya tiket ini untuk digunakan di\n"
	.string "pelabuhan BANDAR LILYCOVE.\p"
	.string "Apa kata kamu cuba dan tengok apa\n"
	.string "sebenarnya?$"

sText_MysticTicketThankYou:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.$"

sText_MysticTicketBagFull:
	.string "Oh, maaf, {PLAYER}.\n"
	.string "POKET BRG PENTING dalam BEG penuh.\p"
	.string "Tolong simpan sesuatu dalam PC,\n"
	.string "kemudian datang balik untuk ambil ini.$"
