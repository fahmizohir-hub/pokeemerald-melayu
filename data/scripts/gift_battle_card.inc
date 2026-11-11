MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.\p"
	.string "KAD KIRAAN TARUNG kamu merekod\n"
	.string "keputusan pertarungan kamu dengan\l"
	.string "JURULATIH yang ada KAD yang sama.\p"
	.string "Cari dan lawan JURULATIH yang ada KAD\n"
	.string "yang sama dengan kamu.\p"
	.string "Kamu boleh semak kedudukan\n"
	.string "keseluruhan dengan membaca BERITA.\p"
	.string "Cubalah!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.\p"
	.string "Tahniah!\p"
	.string "Kamu dapat hadiah sebab menang\n"
	.string "tiga pertarungan!\p"
	.string "Harap kamu makin bersemangat untuk\n"
	.string "bertarung lagi.$"
