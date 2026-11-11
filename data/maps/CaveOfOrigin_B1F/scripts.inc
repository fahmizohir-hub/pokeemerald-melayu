CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	delay 60
	playse SE_PIN
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	delay 30
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, jadi kamulah {PLAYER}{KUN}?\n"
	.string "Saya dah dengar kisah kehebatan kamu.\p"
	.string "Nama saya WALLACE.\p"
	.string "Saya pernah jadi KETUA GIM SOOTOPOLIS,\n"
	.string "tapi ada hal yang berlaku.\p"
	.string "Jadi sekarang, saya serahkan urusan\n"
	.string "GIM kepada guru saya, JUAN.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON dan KYOGRE, dua POKéMON yang\n"
	.string "mengamuk di sini, dianggap sebagai\l"
	.string "POKéMON yang teramat purba.\p"
	.string "Tapi bukan dua itu saja POKéMON yang\n"
	.string "teramat purba.\p"
	.string "Ada satu lagi di suatu tempat.\p"
	.string "Di suatu tempat, ada POKéMON teramat\n"
	.string "purba bernama RAYQUAZA.\p"
	.string "Kononnya RAYQUAZA yang menenangkan\n"
	.string "kedua-dua seteru itu pada zaman\l"
	.string "silam dahulu.\p"
	.string "Tapi saya sendiri pun tak tahu di mana\n"
	.string "RAYQUAZA berada…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}{KUN}, kamu tahu tak\n"
	.string "di mana RAYQUAZA sekarang?\p"
	.string "Kalau tahu, tolong beritahu saya.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: GUA ORIGIN?\p"
	.string "Tapi kita memang di sini!\n"
	.string "Cubalah fikir lagi.\p"
	.string "Tolong fikir di mana RAYQUAZA mungkin\n"
	.string "berada sekarang.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: GUNUNG PYRE?\p"
	.string "Tapi bila saya jumpa nenek di sana tadi,\n"
	.string "dia tak sebut apa-apa pun.\p"
	.string "Saya rasa nenek itu takkan sembunyikan\n"
	.string "apa-apa daripada saya…\p"
	.string "{PLAYER}{KUN}, boleh kamu fikir\n"
	.string "betul-betul sekali lagi?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: Eh? Kamu tak ingat?\n"
	.string "Hmm… Susah juga ni…\p"
	.string "Cubalah ingat balik, boleh?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: TIANG LANGIT?\p"
	.string "Betul!\n"
	.string "Mesti di TIANG LANGIT!\p"
	.string "{PLAYER}{KUN}, tiada masa lagi!\n"
	.string "Mari kita terus ke TIANG LANGIT!$"

