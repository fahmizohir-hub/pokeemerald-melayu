FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Hei, apa khabar, bakal JUARA\n"
	.string "{PLAYER}?\p"
	.string "KETUA GIM FORTREE, WINONA, ialah\n"
	.string "pakar POKéMON jenis TERBANG.\p"
	.string "Dia menunggu di belakang GIM ni,\n"
	.string "di sebalik pintu berputar.\p"
	.string "Dia menanti pencabar baru yang\n"
	.string "cuba mengembangkan sayap!\p"
	.string "Okey, ayuh, buat yang terbaik!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Kamu berjaya!\n"
	.string "Kamu dah berlepas ke udara!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Saksikan gaya bertarung anggun\n"
	.string "POKéMON BURUNG!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Kamu…\n"
	.string "Kamu memang kuat…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "JURULATIH mesti bijak untuk hadapi\n"
	.string "perubahan yang tak dijangka.\p"
	.string "Kamu cukup bijak ke untuk sampai\n"
	.string "kepada KETUA kami?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Peminat POKéMON BURUNG bercita-cita\n"
	.string "nak sertai GIM ni.\p"
	.string "Sebagai ahli GIM FORTREE,\n"
	.string "saya tak dibenarkan kalah!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Beban tu terlalu berat untuk\n"
	.string "saya pikul…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Dunia ni luas, dan ada ramai\n"
	.string "JURULATIH yang hebat.\p"
	.string "Saya akan terus berlatih dan jadi\n"
	.string "lebih kuat lagi.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "WINONA, KETUA GIM kami, tak perlu\n"
	.string "pun nak layan kamu!\p"
	.string "Saya seorang pun dah cukup!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "WINONA, saya…\n"
	.string "Saya kalah!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "WINONA comel dan kuat.\n"
	.string "Dialah KETUA yang terhebat!\p"
	.string "Malunya…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "WINONA sendiri yang ajar saya!\n"
	.string "Saya takkan tewas dengan mudah!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Saya kalah…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Berkat WINONA, penduduk FORTREE\n"
	.string "boleh hidup tanpa rasa takut.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Bila WINONA bertarung, wajahnya\n"
	.string "bersinar dengan tekad yang indah…\p"
	.string "Saya takkan biar kamu saksikan\n"
	.string "pemandangan indah tu!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Urk!\n"
	.string "Saya tak dapat halang kamu.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Hati-hati!\n"
	.string "Jangan leka merenung WINONA, nanti\l"
	.string "kamu jatuh terhempas!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Kamu patut tahu ada pelbagai jenis\n"
	.string "POKéMON jenis TERBANG.\p"
	.string "Kamu tahu, kan?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Nampaknya kamu memang arif!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Ya, kamu memang kalahkan saya.\n"
	.string "Tapi hati-hati! POKéMON KETUA kami,\l"
	.string "WINONA, semuanya tak main-main.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Saya WINONA. Saya KETUA\n"
	.string "GIM POKéMON FORTREE.\p"
	.string "Saya dah bersatu dengan POKéMON\n"
	.string "BURUNG dan terbang di angkasa…\p"
	.string "Walau sesukar mana pertarungan, kami\n"
	.string "tetap menang dengan penuh anggun…\p"
	.string "Saksikan tarian anggun saya\n"
	.string "bersama POKéMON BURUNG!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Tak pernah saya lihat JURULATIH yang\n"
	.string "mengendalikan POKéMON dengan lebih\l"
	.string "anggun daripada saya…\p"
	.string "Sebagai pengiktirafan kehebatan kamu,\n"
	.string "saya serahkan LENCANA GIM ini.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} menerima LENCANA BULU\n"
	.string "daripada WINONA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Dengan LENCANA BULU, semua POKéMON\n"
	.string "sehingga Tahap 70, termasuk yang\l"
	.string "didapati melalui tukaran, akan patuh\l"
	.string "pada setiap arahan kamu.\p"
	.string "Kamu juga boleh guna move HM\n"
	.string "TERBANG di luar pertarungan.\p"
	.string "Dan ini…\n"
	.string "Ini hadiah daripada saya.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 mengandungi JAGUH UDARA.\p"
	.string "Kelajuannya…\n"
	.string "Tiada POKéMON yang dapat mengelaknya.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "KETUA GIM WINONA didaftarkan\n"
	.string "dalam POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Walaupun saya tewas kepada kamu, saya\n"
	.string "tetap setia pada POKéMON BURUNG.$"

FortreeCity_Gym_Text_GymStatue:
	.string "GIM POKéMON BANDAR FORTREE$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "GIM POKéMON BANDAR FORTREE\p"
	.string "JURULATIH DIIKTIRAF WINONA:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA: Kita manusia tak dapat lari\n"
	.string "daripada tarikan graviti bumi.\p"
	.string "Tapi dengan mengejar kecemerlangan,\n"
	.string "kita ada kuasa untuk terbang tinggi!\p"
	.string "Kamu dah sampai ke puncak sebagai\n"
	.string "JUARA yang bertakhta.\p"
	.string "Izinkan saya lihat kuasa kamu\n"
	.string "terbang sepenuhnya!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Saya gagal capai ketinggian kamu lagi…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA: Walaupun saya kalah, sayap\n"
	.string "hati saya tetap tidak patah.\p"
	.string "Saya boleh bangkit dan terbang lagi\n"
	.string "dan lagi.\p"
	.string "Saya yakin!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA: Kita manusia tak dapat lari\n"
	.string "daripada tarikan graviti bumi.\p"
	.string "Tapi dengan mengejar kecemerlangan,\n"
	.string "kita ada kuasa untuk terbang tinggi!\p"
	.string "Kamu dah sampai ke puncak sebagai\n"
	.string "JUARA yang bertakhta.\p"
	.string "Izinkan saya lihat kuasa kamu\n"
	.string "terbang sepenuhnya!\p"
	.string "Oh, tidak… Kamu cuma bawa satu\n"
	.string "POKéMON?\p"
	.string "Sila kembali dengan sekurang-\n"
	.string "kurangnya dua POKéMON.$"
