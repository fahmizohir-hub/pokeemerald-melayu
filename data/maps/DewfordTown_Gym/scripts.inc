DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Hei, apa khabar, bakal JUARA {PLAYER}?\p"
	.string "KETUA GIM DEWFORD, BRAWLY, guna\n"
	.string "POKéMON jenis LAWAN.\p"
	.string "Melawan dia dengan POKéMON jenis\n"
	.string "NORMAL memang cari nahas.\p"
	.string "POKéMON LAWAN akan belasah teruk\n"
	.string "POKéMON NORMAL, jadi berhati-hati!\p"
	.string "Satu lagi masalah, GIM ni gelap macam\n"
	.string "dasar laut.\p"
	.string "Tapi makin terang bila kamu kalahkan\n"
	.string "JURULATIH yang menghalang.\p"
	.string "Okey, ayuh, buat yang terbaik!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Wah! Terang sangat dah di sini!\p"
	.string "Masa depan kamu pun cerah!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "Yang kuat yang menang! Mari!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Tak cukup kuat…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Kemahiran kamu atasi kekuatan saya!\n"
	.string "Teknik kamu patut dipuji!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "BRAWLY tak perlu masuk campur!\p"
	.string "Biar saya yang tumpaskan kamu!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Tapi… Macam mana? Macam mana saya\n"
	.string "boleh kalah semudah itu?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Saya takkan sia-siakan kekalahan ni.\n"
	.string "Saya akan jadikan ia semangat\l"
	.string "untuk berlatih!\p"
	.string "Satu hari nanti saya akan jadi\n"
	.string "KETUA GIM…\p"
	.string "Tak, saya akan jadi JUARA LIGA POKéMON!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Jangan berani pandang rendah pada\n"
	.string "saya! Bukan salah saya kalau kamu\l"
	.string "menangis!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Waaaaaaah! Saya kalah!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Saya bertarung dalam gelap untuk\n"
	.string "kuatkan hati saya.\p"
	.string "Tapi sebab gelap sangat, saya tak\n"
	.string "pernah nampak muka BRAWLY…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu… Kamu teraba-raba dalam\n"
	.string "gelap ke?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, kamu ni… Saya tak nak kenal kamu!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Padan muka kalau kamu sesat dan balik\n"
	.string "ke pintu masuk lagi!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Biar saya tunjuk semangat anak kapal!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Macam mana boleh jadi begini? Bukan\n"
	.string "selalu saya kalah macam ni!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Ya, betul! Kamu layak jumpa KETUA\n"
	.string "GIM kami.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Kalau kamu nak lalu, kamu kena\n"
	.string "tumpaskan saya dulu!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr! Kamu jauh lebih kuat!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Kamu menang! Pergilah dapatkan\n"
	.string "LENCANA tu!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Saya BRAWLY! KETUA GIM DEWFORD!\p"
	.string "Saya dibesarkan dek ombak ganas di\n"
	.string "sini, dan jadi tegap dalam gua yang\l"
	.string "gelap gelita!\p"
	.string "Jadi kamu nak cabar saya? Tunjukkan\n"
	.string "apa yang kamu ada!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Wah, wah! Percikan kamu jauh lebih besar\n"
	.string "dari jangkaan saya!\p"
	.string "Saya pula yang tenggelam!\p"
	.string "Okey, kamu menang. Ambil LENCANA GIM ni!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} menerima LENCANA BUKU JARI\n"
	.string "daripada BRAWLY.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "Dengan LENCANA BUKU JARI, semua\n"
	.string "POKéMON sehingga Tahap 30, termasuk\l"
	.string "yang kamu dapat melalui tukaran, akan\l"
	.string "patuh tanpa soal.\p"
	.string "Kamu juga boleh guna HM KILAT di\n"
	.string "luar pertarungan.\p"
	.string "Kalau nak, ambil MESIN TEKNIKAL ni juga.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "TM08 tu mengandungi BINA OTOT.\p"
	.string "Move ni naikkan stat SERANGAN dan\n"
	.string "PERTAHANAN sekali gus.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "KETUA GIM BRAWLY didaftarkan\n"
	.string "dalam POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Saya nampak bakat kamu akan jadi ombak\n"
	.string "gergasi yang menggemparkan para\l"
	.string "JURULATIH satu hari nanti!$"

DewfordTown_Gym_Text_GymStatue:
	.string "GIM POKéMON PEKAN DEWFORD$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "GIM POKéMON PEKAN DEWFORD\p"
	.string "JURULATIH DIIKTIRAF BRAWLY:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BRAWLY: Ombak mungkin surut, tapi ia\n"
	.string "sentiasa kembali ke pantai.\p"
	.string "Ombak gergasi berbakat macam kamu…\n"
	.string "Saya tahu kamu akan kembali!\p"
	.string "Tunjukkan setinggi mana kamu dah naik!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Wah! Tenggelam lagi!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY: Pertarungan ni luas dan dalam.\n"
	.string "Dasarnya tak nampak. Sama macam lautan\l"
	.string "HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY: Ombak mungkin surut, tapi ia\n"
	.string "sentiasa kembali ke pantai.\p"
	.string "Ombak gergasi berbakat macam kamu…\n"
	.string "Saya tahu kamu akan kembali!\p"
	.string "Oh? Kamu cuma ada satu POKéMON yang\n"
	.string "boleh bertarung.\p"
	.string "Maaf, tapi saya nak kamu datang balik\n"
	.string "dengan sekurang-kurangnya dua\l"
	.string "POKéMON.$"
