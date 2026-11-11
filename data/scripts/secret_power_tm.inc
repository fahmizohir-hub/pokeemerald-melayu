Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Apa tu?\n"
	.string "Saya tengah buat apa?\p"
	.string "Saya terfikir nak buat bilik sendiri di\n"
	.string "sini guna move POKéMON.\p"
	.string "Ha, saya tahu! Saya bagi kamu TM ini.\n"
	.string "Kamu nak guna untuk buat bilik sendiri?$"

Route111_Text_ExplainSecretPower:
	.string "Cari pokok besar yang nampak macam\n"
	.string "ada akar gantung nak terjatuh.\p"
	.string "Guna KUASA RAHSIA di depan pokok itu.\n"
	.string "Akar gantung tu akan terlerai dan\l"
	.string "jatuh, lepas tu kamu boleh panjat.\p"
	.string "Di situ ada banyak ruang untuk letak\n"
	.string "barang kegemaran kamu.\p"
	.string "Itulah bilik rahsia kamu sendiri…\n"
	.string "PANGKALAN RAHSIA!\p"
	.string "Kamu patut buat satu juga.\p"
	.string "Satu lagi, PANGKALAN RAHSIA tak\n"
	.string "semestinya dibuat dalam pokok.\p"
	.string "Cuba guna KUASA RAHSIA pada dinding\n"
	.string "batu yang ada lekuk kecil.\p"
	.string "Saya pun nak pergi cari tempat lain.\n"
	.string "Okey, jumpa lagi!$"

Route111_Text_DontWantThis:
	.string "Oh, kamu tak nak?\n"
	.string "Kalau ubah fikiran, beritahu saya, ya?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, kamu dah tak ada ruang nak\n"
	.string "simpan benda ni.\p"
	.string "Saya simpan dulu, jadi datanglah ambil\n"
	.string "lain kali, okey?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applywaitmovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	return

Route111_EventScript_SecretPowerManExitNorth::
	applywaitmovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
