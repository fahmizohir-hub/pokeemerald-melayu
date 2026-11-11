MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Di sinilah kami pengguna NAGA\n"
	.string "berlatih.\p"
	.string "JUARA pun datang ke sini.\n"
	.string "Sekarang kamu nampak istimewanya?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Urgh!\n"
	.string "Tak sangka kamu sekuat ini!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "Jalan di hadapan masih jauh dan sukar.\p"
	.string "Bilakah saya dan POKéMON saya akan\n"
	.string "jadi yang terbaik?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Saya nak tahu lebih lanjut kuasa kamu.\n"
	.string "Biar saya daftar kamu dalam POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Sejak kita berjumpa, kami berlatih\n"
	.string "keras dengan sasaran nombor satu.\p"
	.string "Tolong tunjukkan betapa kuatnya kami\n"
	.string "sekarang!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Urgh!\n"
	.string "Tak sangka kamu sekuat ini!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Jelas kamu terus melatih POKéMON\n"
	.string "kamu.\p"
	.string "Selagi kamu kekal kuat, saya pun\n"
	.string "boleh jadi lebih kuat!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN: Kami sentiasa bertarung POKéMON\n"
	.string "bersama-sama berdua.\l"
	.string "Kami yakin dengan diri kami.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN: Aduhai.\n"
	.string "Kita kalah, isteriku sayang.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN: Kami dah berkahwin selama\n"
	.string "lima puluh tahun.\p"
	.string "Bila difikirkan, saya belum pernah\n"
	.string "menang bertarung dengan isteri saya.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN: Wah, wah, mudanya JURULATIH ni!\p"
	.string "Nak lawan kami? Kalau ya, kamu kena\n"
	.string "datang semula dengan lebih POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN: JURULATIH muda, kalau ada\n"
	.string "peluang, sudi lawan kami lagi?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: Kami dah berkahwin selama\n"
	.string "lima puluh tahun.\p"
	.string "Ikatan kami sebagai suami isteri\n"
	.string "takkan dapat diputuskan.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: Aduhai.\n"
	.string "Kita kalah, suamiku sayang.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Lima puluh tahun berkahwin…\p"
	.string "Kalau bergaduh, kami selalu selesaikan\n"
	.string "dengan pertarungan POKéMON…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Wah, wah, kamu JURULATIH muda,\n"
	.string "ya?\p"
	.string "Kalau nak lawan kami, kamu kena\n"
	.string "datang semula dengan lebih POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN: Kami sentiasa bertarung POKéMON\n"
	.string "bersama-sama berdua.\l"
	.string "Kami yakin dengan diri kami.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN: Aduhai.\n"
	.string "Kita kalah, isteriku sayang.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN: Lima puluh tahun berkahwin…\p"
	.string "Bila dikenang, saya dan isteri saya\n"
	.string "bertarung siang dan malam…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN: Wah, wah, mudanya JURULATIH ni!\p"
	.string "Nak lawan kami? Kalau ya, kamu kena\n"
	.string "datang semula dengan lebih POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: Kami dah berkahwin selama\n"
	.string "lima puluh tahun.\p"
	.string "Kami saling menyokong sepanjang masa\n"
	.string "itu. Kami jadi kuat bersama.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: Aduhai.\n"
	.string "Kita kalah, suamiku sayang.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Lima puluh tahun berkahwin…\n"
	.string "Macam-macam yang dah berlaku.\p"
	.string "Saya harap kami terus cipta kenangan\n"
	.string "gembira bersama.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Wah, wah, kamu JURULATIH muda,\n"
	.string "ya?\p"
	.string "Kalau nak lawan kami, kamu kena\n"
	.string "datang semula dengan lebih POKéMON.$"

