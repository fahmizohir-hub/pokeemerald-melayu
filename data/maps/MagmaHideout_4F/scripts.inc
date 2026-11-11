MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Aku pun nak tengok GROUDON, tapi\n"
	.string "ekornya pun mereka tak bagi tengok…\p"
	.string "Geram betul aku rasa.\p"
	.string "Alamak!\n"
	.string "Aku terlepas cakap pasal GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Rasanya memang mustahil menang kalau\n"
	.string "fikiran tak tenang…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "GROUDON tu ada ekor ke, agaknya?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Tak lama lagi! Tak lama lagi!\l"
	.string "Matlamat besar kami akan tercapai!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "Dah sampai sejauh ni, jadi begini?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "Tuan MAXIE!\n"
	.string "Ada penceroboh menuju ke arah tuan!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Kau belum selesai lagi!\n"
	.string "Kau takkan lepasi aku dengan mudah!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Senang sangat ke aku ditumpaskan?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "J-jomlah, satu pusingan lagi…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe!\n"
	.string "Kau dah sampai sejauh ni, aku beritahu!\p"
	.string "Betul!\n"
	.string "Di hadapan sana, GROUDON sedang tidur!\p"
	.string "MAXIE baru saja pergi ke arah GROUDON\n"
	.string "beberapa saat tadi!\p"
	.string "Ia akan bangun tak lama lagi!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Tumpas lagi…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…Dan masa kau buang masa dengan aku,\n"
	.string "MAXIE patut dah bangunkan GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: GROUDON…\p"
	.string "Tiada apa yang dapat membangunkan\n"
	.string "kau dari tidur bermandikan magma…\p"
	.string "MESTIKA BIRU inilah yang kau cari.\n"
	.string "Bukankah begitu?\p"
	.string "Aku dah bawakan MESTIKA BIRU.\n"
	.string "Biar sinarnya membangunkan kau!\p"
	.string "Dan tunjukkan kepadaku…\n"
	.string "Tunjukkan sepenuh kuasamu!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: GROUDON!\n"
	.string "Kenapa?\p"
	.string "Bukankah MESTIKA BIRU kuncinya?\p"
	.string "GROUDON!\n"
	.string "Ke mana kau pergi…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAXIE: Oh, jadi kau rupanya?\p"
	.string "Aku nampak kau menyibuk di sana sini\n"
	.string "tanpa diundang…\p"
	.string "Sekarang aku faham!\n"
	.string "Kau mesti dah buat helah murahan!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Apa yang buat kau begitu mahir\n"
	.string "mengendalikan POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAXIE: Mesti ada sebab kenapa\n"
	.string "GROUDON melarikan diri…\p"
	.string "Itu yang kau cuba katakan,\n"
	.string "bukan?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hmph…\n"
	.string "Kau ingat aku tak tahu?\p"
	.string "Bila GROUDON dah tiada, gunung\n"
	.string "berapi celaka ni tak diperlukan lagi.\p"
	.string "Aku akan kejar GROUDON, jadi di\n"
	.string "sinilah kita berpisah!$"
