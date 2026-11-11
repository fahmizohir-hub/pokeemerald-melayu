MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Oh, wah, {PLAYER}{KUN}.\n"
	.string "Saya kagum kamu tahu saya di sini.\p"
	.string "Kamu, err… mungkin anggap saya\n"
	.string "cuma seorang peminat batu?\p"
	.string "Tidak, itu tak mungkin.\p"
	.string "Kita pernah bertarung bersama di\n"
	.string "PUSAT ANGKASA SOOTOPOLIS.\p"
	.string "Kamu sepatutnya dah tahu betapa\n"
	.string "hebatnya saya.\p"
	.string "Okey, {PLAYER}{KUN}, kalau kamu nak cabar\n"
	.string "saya dengan serius, bersedialah!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Kamu…\n"
	.string "Tak sangka kamu dah jadi sekuat ini…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Bila difikirkan, sejak kita\n"
	.string "mula-mula bertemu di GUA GRANITE\l"
	.string "di DEWFORD, saya dah rasa sesuatu.\p"
	.string "Saya rasa kamu akhirnya akan\n"
	.string "menjadi JUARA.\p"
	.string "Ramalan saya selalunya tepat.\p"
	.string "Jadi, ke mana kamu selepas ni?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, saya sendiri pun tak tahu.$"

