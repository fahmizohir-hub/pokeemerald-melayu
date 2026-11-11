LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hei, apa khabar, bakal JUARA\n"
	.string "{PLAYER}?\p"
	.string "KETUA GIM LAVARIDGE, FLANNERY,\n"
	.string "menggunakan POKéMON jenis API.\p"
	.string "Semangatnya untuk POKéMON membara\n"
	.string "lebih panas daripada gunung berapi.\p"
	.string "Jangan dekat sangat--nanti terbakar!\n"
	.string "Simbah dia dengan air, kemudian\l"
	.string "ayuh, buat yang terbaik!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Wah! Pertarungan tu memang panas!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Adududuh!\n"
	.string "Alamak, panasnya!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Mata saya pedih dimasuki peluh…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Ditimbus dalam pasir panas boleh\n"
	.string "melancarkan peredaran darah.\p"
	.string "Bagus untuk ubati sakit\n"
	.string "sendi.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Saya tengah cuba hilangkan tekanan.\n"
	.string "Jangan datang buat saya tertekan!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Biar FLANNERY bakar kamu cukup-cukup!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Fuh…\p"
	.string "Kalau lama sangat ditimbus dalam\n"
	.string "pasir panas, memang penat…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Mesti kamu dah penat sekarang.\n"
	.string "Kamu nak berehat dalam pasir panas,\l"
	.string "kan?\p"
	.string "Tapi ingat, semua JURULATIH mesti\n"
	.string "pandai jaga semangat supaya tak\l"
	.string "luntur.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Main api, terbakar diri…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Kemahiran kamu memang tulen…\n"
	.string "Tapi KETUA kami FLANNERY sangat kuat.\p"
	.string "Kalau tak berhati-hati, kamu akan\n"
	.string "terbakar teruk.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "POKéMON kamu boleh tahan bahang\n"
	.string "392 darjah?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Tak cukup panas rupanya…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Suhu magma ialah\n"
	.string "392 darjah.\p"
	.string "POKéMON kamu kalahkan saya, jadi\n"
	.string "mesti mereka mudah hidup dalam magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Err…\n"
	.string "Okey, saya lawan kamu.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, tapi kamu terlalu kuat.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Saya nak jadi JURULATIH yang cantik\n"
	.string "dan kuat macam FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Ayuh, cepatlah!\n"
	.string "Lawan saya sebelum semangat ni sejuk!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Panas sungguh, tapi hati saya\n"
	.string "terasa membeku…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Tengok semangat kamu yang membara tu,\n"
	.string "mungkin kamu ada peluang lawan\l"
	.string "KETUA kami.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Nampak tak api yang marak ni?\n"
	.string "Ia menyala menanti kemenangan saya!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Ada yang tak kena.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Jadi apa? Saya kata, jadi apa?\n"
	.string "Saya boleh jalan atas bara tanpa kasut!\p"
	.string "…Jangan sesekali cuba!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Saya memang suka gunung, tapi\n"
	.string "saya paling suka gunung berapi.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Nampaknya saya kalah tanpa sempat\n"
	.string "kawal keadaan langsung.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Saya di sini sebab saya jadi peminat\n"
	.string "kuasa FLANNERY.\p"
	.string "Hehehehe.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Selamat datang… Eh, tunggu.\p"
	.string "JURULATIH kerdil, baguslah kamu\n"
	.string "berjaya sampai ke sini!\p"
	.string "Saya telah diamanahkan dengan…\n"
	.string "Eh, tunggu.\p"
	.string "Saya FLANNERY, dan saya KETUA\n"
	.string "GIM di sini!\p"
	.string "Err…\n"
	.string "Jangan pandang rendah pada saya,\l"
	.string "walaupun saya baru jadi KETUA!\p"
	.string "Dengan kemahiran warisan datuk saya,\n"
	.string "saya akan, err… tunjukkan move panas\l"
	.string "yang kami asah di bumi ini!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "Rasanya saya terlalu memaksa diri…\p"
	.string "Saya… Saya baru saja jadi\n"
	.string "KETUA GIM.\p"
	.string "Saya terlalu cuba jadi orang\n"
	.string "yang bukan diri saya.\p"
	.string "Saya perlu buat cara saya sendiri.\n"
	.string "Kalau tak, POKéMON saya akan keliru.\p"
	.string "Terima kasih kerana ajar saya.\n"
	.string "Untuk itu, kamu layak dapat ini.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} menerima LENCANA HABA\n"
	.string "daripada FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Kalau kamu ada LENCANA HABA, semua\n"
	.string "POKéMON sehingga Tahap 50, termasuk\l"
	.string "yang didapati melalui tukaran, akan\l"
	.string "patuh sepenuhnya pada kamu.\p"
	.string "Dan, POKéMON boleh guna move HM\n"
	.string "KEKUATAN di luar pertarungan.\p"
	.string "Ini tanda penghargaan saya.\n"
	.string "Jangan segan, ambillah!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "TM50 tu mengandungi LAMPAU PANAS.\p"
	.string "Move tu beri kerosakan teruk kepada\n"
	.string "lawan.\p"
	.string "Tapi SERANGAN KHAS POKéMON yang guna\n"
	.string "juga turun mendadak. Mungkin tak\l"
	.string "sesuai untuk pertarungan panjang.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "KETUA GIM FLANNERY didaftarkan\n"
	.string "dalam POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Kuasa kamu mengingatkan saya pada\n"
	.string "seseorang…\p"
	.string "Oh! Saya tahu! Kamu bertarung macam\n"
	.string "NORMAN, KETUA GIM PETALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "GIM POKéMON PEKAN LAVARIDGE$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "GIM POKéMON PEKAN LAVARIDGE\p"
	.string "JURULATIH DIIKTIRAF FLANNERY:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Kalah dalam pertarungan\n"
	.string "takkan buat saya patah semangat.\p"
	.string "Saya sayang POKéMON.\n"
	.string "Saya suka bertarung.\l"
	.string "Dan… Saya sayang GIM ni!\p"
	.string "Jom kita berbalas move super panas\n"
	.string "dalam satu lagi pertarungan!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Fuh!\n"
	.string "Hampir meletus!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: Saya kalah perlawanan ni,\n"
	.string "tapi saya sangat puas hati.\p"
	.string "Jarang saya dapat nikmati pertarungan\n"
	.string "sehangat ini.\p"
	.string "Jom bertarung macam ni lagi\n"
	.string "lain kali!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: Kalah dalam pertarungan\n"
	.string "takkan buat saya patah semangat.\p"
	.string "Saya sayang POKéMON.\n"
	.string "Saya suka bertarung.\l"
	.string "Dan… Saya sayang GIM ni!\p"
	.string "Jom kita berbalas move super panas\n"
	.string "dalam satu lagi pertarungan!\p"
	.string "Oh, tunggu. Kamu cuma ada satu\n"
	.string "POKéMON yang boleh bertarung?\p"
	.string "Maaf cakap, tapi bila datang jumpa\n"
	.string "saya, bawa sekurang-kurangnya dua.$"
