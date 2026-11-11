MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.\p"
	.string "Ada khabar angin orang ternampak\n"
	.string "POKéMON nadir.\p"
	.string "Katanya, POKéMON tu dilihat di\n"
	.string "GUA BERUBAH di LALUAN 103.\p"
	.string "Mungkin berbaloi kalau kamu pergi\n"
	.string "siasat khabar angin ni.$"
