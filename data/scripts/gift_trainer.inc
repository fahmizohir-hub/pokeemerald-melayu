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
	.string "Dengan memegang KAD AJAIB ini, kamu\n"
	.string "boleh menyertai tinjauan di POKé MART.\p"
	.string "Gunakan tinjauan itu untuk menjemput\n"
	.string "JURULATIH ke BANDAR SOOTOPOLIS.\p"
	.string "…Biar saya beri kamu kata laluan rahsia\n"
	.string "untuk tinjauan:\p"
	.string "“BERI SAYA\n"
	.string "GEMPAK JURULATIH”\p"
	.string "Tulis itu dalam tinjauan dan hantar\n"
	.string "kepada SISTEM KOMUNIKASI WAYARLES.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Terima kasih kerana menggunakan Sistem\n"
	.string "HADIAH MISTERI.\p"
	.string "Seorang JURULATIH telah tiba di\n"
	.string "BANDAR SOOTOPOLIS untuk mencari kamu.\p"
	.string "Kami harap kamu seronok bertarung\n"
	.string "dengan JURULATIH pelawat itu.\p"
	.string "Kamu boleh jemput JURULATIH lain\n"
	.string "dengan memasukkan kata laluan lain.\p"
	.string "Cuba cari kata laluan lain yang mungkin\n"
	.string "berkesan.$"
