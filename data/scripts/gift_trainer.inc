MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.\p"
	.string "Dengan KAD AJAIB ini, kamu boleh\n"
	.string "sertai tinjauan di POKé MART.\p"
	.string "Guna tinjauan tu untuk jemput\n"
	.string "JURULATIH ke BANDAR SOOTOPOLIS.\p"
	.string "…Biar saya beri kamu kata laluan rahsia\n"
	.string "untuk tinjauan:\p"
	.string "“BERI SAYA\n"
	.string "GEMPAK JURULATIH”\p"
	.string "Tulis kata laluan tu dalam tinjauan\n"
	.string "dan hantar kepada SISTEM\l"
	.string "KOMUNIKASI WAYARLES.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.\p"
	.string "Seorang JURULATIH dah sampai di\n"
	.string "BANDAR SOOTOPOLIS untuk cari kamu.\p"
	.string "Kami harap kamu seronok bertarung\n"
	.string "dengan JURULATIH pelawat itu.\p"
	.string "Kamu boleh jemput JURULATIH lain\n"
	.string "dengan masukkan kata laluan lain.\p"
	.string "Cubalah cari kata laluan lain yang\n"
	.string "mungkin menjadi.$"
