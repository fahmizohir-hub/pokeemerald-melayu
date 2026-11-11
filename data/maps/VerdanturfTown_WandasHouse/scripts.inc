VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "WALLY: Saya kalah dengan kamu, {PLAYER},\n"
	.string "tapi saya dah tak sedih lagi.\p"
	.string "Sebab saya ada tujuan hidup yang baru.\n"
	.string "Bersama RALTS saya, saya akan cabar\l"
	.string "GIM POKéMON dan jadi JURULATIH yang\l"
	.string "hebat.\p"
	.string "Tengoklah saya, {PLAYER}.\n"
	.string "Saya akan jadi lebih kuat daripada\l"
	.string "kamu.\p"
	.string "Bila tiba masanya, saya akan cabar kamu\n"
	.string "bertarung lagi.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "WALLY: Tengoklah saya, {PLAYER}.\n"
	.string "Saya akan jadi lebih kuat daripada\l"
	.string "kamu.\p"
	.string "Bila tiba masanya, saya akan cabar kamu\n"
	.string "bertarung lagi.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "PAKCIK: Oh! {PLAYER}{KUN}!\n"
	.string "WALLY ada di sebelah.\p"
	.string "Tapi, nak, ada sesuatu saya nak\n"
	.string "beritahu kamu.\p"
	.string "Alam semula jadi di sini sangat bagus\n"
	.string "untuk kesihatan WALLY.\p"
	.string "Mungkin bukan alam sekitar saja.\n"
	.string "Mungkin POKéMON yang beri budak tu\l"
	.string "harapan.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "WALLY dah pergi…\n"
	.string "Dia keluar senyap-senyap seorang diri…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "PAKCIK: Betul ke?\n"
	.string "WALLY dah pergi sejauh tu seorang diri…\p"
	.string "Hmm, saya kena puji dia, dia memang anak\n"
	.string "adik saya.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "WANDA: Kamu siapa?\n"
	.string "Oh, ya, saya faham!\p"
	.string "Kamu {PLAYER} yang WALLY selalu cerita\n"
	.string "tu.\p"
	.string "Saya sepupu WALLY.\n"
	.string "Selamat berkenalan!\p"
	.string "Saya rasa WALLY jadi jauh lebih ceria\n"
	.string "dan sihat sejak datang ke sini.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "WANDA: Jangan risau tentang WALLY.\n"
	.string "Dia akan baik-baik saja.\p"
	.string "Saya kenal sepupu kecil saya tu,\n"
	.string "lagipun dia ada POKéMON bersamanya.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Terima kasih kepada kamu, saya boleh\n"
	.string "jumpa kekasih saya setiap hari.\l"
	.string "Gembira? Mestilah!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Teman lelaki anak saya memang seorang\n"
	.string "yang gigih dan bersemangat.\p"
	.string "Dia gali terowong tanpa henti\n"
	.string "semata-mata nak jumpa anak saya.\p"
	.string "Anak saya agak risau, jadi dia selalu\n"
	.string "pergi ke terowong tu.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Menakjubkan. Teman lelaki anak saya\n"
	.string "gali terowong tu dengan tangan!\p"
	.string "Sungguh luar biasa!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Kalau apa-apa berlaku pada WALLY, saya\n"
	.string "takkan sanggup bertentang mata\l"
	.string "dengan ibu bapanya di PETALBURG…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "WALLY ada di EVER GRANDE?\p"
	.string "Ibu bapanya di PETALBURG mesti\n"
	.string "terkejut kalau dengar!$"

