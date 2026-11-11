LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applywaitmovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hm, jadi tetamu mereka berganda sebab\n"
	.string "guna POKéMON sebagai tarikan?\p"
	.string "Hm, mungkin saya patut jadikan POKéMON\n"
	.string "comel sebagai maskot rumah tumpangan\l"
	.string "kami.\p"
	.string "Agaknya lebih ramai tetamu akan datang\n"
	.string "menginap tak?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, maaf, maaf!\n"
	.string "Saya leka sangat tengok TV!\p"
	.string "Sejak TEAM AQUA tu datang ke bandar,\n"
	.string "pelancong dah tak mahu datang.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hoi, tunduk sikit!\n"
	.string "Saya tak nampak TV!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Hebatnya! POKéMON jumpa barang orang\n"
	.string "yang hilang?\p"
	.string "Bagus tu. Kalau kami ada POKéMON yang\n"
	.string "bijak macam tu…\p"
	.string "Kami boleh cari apa saja barang yang\n"
	.string "tetamu kami tercicir…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, maaf, maaf!\n"
	.string "Saya leka sangat tengok TV!\p"
	.string "Saya dengar ada orang dah serbu\n"
	.string "MARKAS TEAM AQUA.\p"
	.string "Berkat itu, kami baru terima tempahan\n"
	.string "daripada satu kumpulan besar.\p"
	.string "Nama syarikatnya… Err…\n"
	.string "GAME sesuatu…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Hebatnya! POKéMON penjaga\n"
	.string "rumah tangkap pencuri?\p"
	.string "Bagus tu. Kalau kami ada POKéMON yang\n"
	.string "tegap sebagai pengawal keselamatan…\p"
	.string "Tetamu kami tentu lebih selamat.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, maaf, maaf!\n"
	.string "Saya leka sangat tengok TV.\p"
	.string "Oh, ya. Satu kumpulan tetamu yang besar\n"
	.string "baru sampai tadi.\p"
	.string "Mereka mendaftar atas nama GAME FREAK,\n"
	.string "jadi mesti mereka pembuat game.\p"
	.string "Alamak, baik saya mula masak makan\n"
	.string "malam mereka!$"

