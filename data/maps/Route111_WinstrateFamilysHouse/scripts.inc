Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applywaitmovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Kamu JURULATIH pertama yang saya\n"
	.string "tengok guna POKéMON dengan begitu\l"
	.string "mahir.\p"
	.string "Tapi saya patut beritahu, anak lelaki\n"
	.string "saya lebih kuat daripada kamu.\p"
	.string "Untuk pengetahuan kamu, dia pun dah\n"
	.string "sahut cabaran LIGA POKéMON.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Kami guna GELANG MACHO ni untuk\n"
	.string "kuatkan POKéMON kami dengan lebih\l"
	.string "berkesan semasa berlatih.\p"
	.string "Kamu dah kalahkan kami semua, jadi\n"
	.string "entah kamu perlukannya atau tidak,\l"
	.string "tapi kami nak bagi GELANG MACHO kami.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Kalau bab pertarungan POKéMON,\n"
	.string "kami memang agak bersemangat.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mak lebih kuat daripada Ayah.\p"
	.string "Saya lebih kuat daripada Mak.\p"
	.string "Dan Nenek lebih kuat daripada saya!\p"
	.string "Tapi abang saya lebih kuat lagi\n"
	.string "daripada Nenek.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Tak dinafikan kamu memang kuat.\p"
	.string "Tapi kalau kamu lawan cucu saya, kamu\n"
	.string "pasti menangis kegeraman.\p"
	.string "Dia jauh lebih kuat daripada mana-mana\n"
	.string "JURULATIH yang keluarga kami kenal.\p"
	.string "Mesti dia sedang cabar JUARA LIGA\n"
	.string "POKéMON sekarang.\p"
	.string "Kalau ikut perangai cucu saya, mungkin\n"
	.string "dia dah jadi JUARA pun!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Mesti cucu saya sedang cabar JUARA\n"
	.string "LIGA POKéMON sekarang.\p"
	.string "Kalau ikut perangai cucu saya, mungkin\n"
	.string "dia dah jadi JUARA pun!$"

