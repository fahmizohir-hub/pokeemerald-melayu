MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.\p"
	.string "Kamu mesti {PLAYER}.\n"
	.string "Ada tiket di sini untuk kamu.$"

sText_AuroraTicketUseAtPort:
	.string "Nampaknya tiket ini untuk digunakan di\n"
	.string "pelabuhan BANDAR LILYCOVE.\p"
	.string "Apa kata kamu pergi ke sana dan\n"
	.string "tengok sendiri?$"

sText_AuroraTicketThankYou:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.$"

sText_AuroraTicketBagFull:
	.string "Oh, maaf, {PLAYER}.\n"
	.string "POKET BRG PENTING dalam BEG penuh.\p"
	.string "Tolong simpan sesuatu dalam PC,\n"
	.string "lepas tu datang balik ambil tiket ni.$"
