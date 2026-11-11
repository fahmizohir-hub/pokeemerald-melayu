AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applywaitmovement VAR_0x8008, Common_Movement_ExclamationMark
	applywaitmovement VAR_0x8008, Common_Movement_FacePlayer
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applywaitmovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	delay 20
	applywaitmovement VAR_0x8008, Common_Movement_FacePlayer
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applywaitmovement VAR_0x8008, Common_Movement_FacePlayer
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hehehe…\p"
	.string "Dah sampai sini, ya?\n"
	.string "Kami pandang rendah pada kau!\p"
	.string "Tapi setakat ini sajalah!\p"
	.string "Aku jauh lebih hebat daripada ANAK BUAH\n"
	.string "yang kau jumpa tadi.\p"
	.string "Aku bukan nak lengahkan masa.\n"
	.string "Aku nak hancurkan kau!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hehehe…\n"
	.string "Jadi, aku pun kalah juga…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hehehe!\p"
	.string "Masa aku main-main dengan kau tadi, BOS\n"
	.string "kami dah siap semua persediaan!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hehehe!\p"
	.string "BOS kami dah pun bertolak ke sebuah gua\n"
	.string "di dasar laut!\p"
	.string "Kalau kau nak kejar, baik kau cari di\n"
	.string "laut luas di seberang LILYCOVE.\p"
	.string "Tapi boleh ke kau jumpa?\n"
	.string "Hehehe!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, dah naik jemu aku menunggu!\n"
	.string "Kau kena lawan aku juga!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Penat menunggu…\n"
	.string "Kalah pula, pening…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "BOS…\n"
	.string "Cukup bagus ke ni?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Panel teleport, kebanggaan\n"
	.string "MARKAS kami!\p"
	.string "Kau langsung tak tahu kau di mana\n"
	.string "sekarang, kan?\p"
	.string "Buat musuh keliru dan penat, lepas tu\n"
	.string "baru hentam! Itu rancangan kami!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Kau ni kenapa?\n"
	.string "Kau langsung tak penat!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Baru teringat… Aku tak ingat mana aku\n"
	.string "letak MASTER BALL tu.\p"
	.string "Kalau aku gagal jaga, BOS kami mesti\n"
	.string "marah aku teruk…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Masa aku mula masuk TEAM AQUA, benda\n"
	.string "pertama aku kena belajar ialah cara\l"
	.string "panel teleport ni bersambung.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Aku asyik fikir pasal panel teleport…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Aku kena belajar cara bertarung dengan\n"
	.string "lebih berkesan…$"
