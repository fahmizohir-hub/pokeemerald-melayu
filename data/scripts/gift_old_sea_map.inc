MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.\p"
	.string "Biar saya pastikan--kamu {PLAYER}?\p"
	.string "Kami ada terima PETA LAUT TUA ini\n"
	.string "yang dialamatkan kepada kamu.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Nampaknya peta ini untuk digunakan di\n"
	.string "pelabuhan BANDAR LILYCOVE.\p"
	.string "Apa kata kamu pergi ke sana dan\n"
	.string "tengok sendiri?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, maaf, {PLAYER}.\n"
	.string "POKET BRG PENTING dalam BEG penuh.\p"
	.string "Tolong simpan sesuatu dalam PC,\n"
	.string "lepas tu datang balik ambil peta ni.$"
