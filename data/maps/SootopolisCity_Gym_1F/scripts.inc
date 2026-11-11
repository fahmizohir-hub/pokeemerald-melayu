SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applywaitmovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo! Apa khabar, bakal JUARA\n"
	.string "{PLAYER}?\p"
	.string "KETUA GIM SOOTOPOLIS, JUAN, ialah pakar\n"
	.string "POKéMON jenis AIR.\p"
	.string "Dan, untuk sampai kepada JUAN, lantai\n"
	.string "ais akan menyukarkan perjalanan kamu…\p"
	.string "Maaf, tapi itu saja nasihat yang saya\n"
	.string "ada untuk kamu.\p"
	.string "Selebihnya, kamu kena usaha sendiri!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Wah! Kamu kalahkan JUAN, yang\n"
	.string "katanya paling hebat di HOENN!\p"
	.string "Okey! Periksa KAD JURULATIH kamu.\p"
	.string "Kalau kamu dah dapat semua LENCANA,\n"
	.string "kamu sedia untuk cabaran LIGA POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Izinkan saya bertanya.\n"
	.string "Kamu tahu tak?\l"
	.string "Ah, tak perlulah saya berselindung.\p"
	.string "Sayalah yang ajar WALLACE\n"
	.string "segala-galanya tentang POKéMON.\p"
	.string "Dulu, saya pernah lepaskan jawatan\n"
	.string "sebagai KETUA GIM.\p"
	.string "Sebagai ganti, saya amanahkan GIM ini\n"
	.string "kepada WALLACE.\p"
	.string "Namun, ada sebab kukuh yang buat saya\n"
	.string "kembali semula.\p"
	.string "Ah, cukuplah berbual.\n"
	.string "Mari kita mulakan pertarungan, ya?\p"
	.string "Silakan saksikan seni kami.\p"
	.string "Ilusi air yang megah, diukir oleh\n"
	.string "POKéMON dan saya sendiri!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, hebat!\n"
	.string "Baiklah, kamulah pemenangnya.\p"
	.string "Dalam diri kamu, saya rasa sinar\n"
	.string "kemahiran yang mampu atasi segalanya.\p"
	.string "Namun, berbanding saya atau WALLACE,\n"
	.string "kamu kurang keanggunan.\p"
	.string "Mungkin saya patut pinjamkan pakaian\n"
	.string "saya kepada kamu?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hahaha, saya bergurau saja!\p"
	.string "Bukan pakaian saya, tapi saya\n"
	.string "hadiahkan kamu ini, LENCANA HUJAN!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} menerima LENCANA HUJAN\n"
	.string "daripada JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Dengan LENCANA HUJAN, semua POKéMON\n"
	.string "kamu akan patuh sepenuhnya pada\l"
	.string "setiap arahan kamu.\p"
	.string "LENCANA HUJAN juga membolehkan move\n"
	.string "HM AIR TERJUN diguna untuk mendaki\l"
	.string "dinding air terjun.\p"
	.string "Dan supaya kamu tak lupa pertarungan\n"
	.string "kita, ambillah ini…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "TM yang saya beri itu mengandungi\n"
	.string "DENYUT AIR.\p"
	.string "Bila diguna, kadangkala ia mengelirukan\n"
	.string "sasaran dengan gelombang ultrasonik.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "KETUA GIM JUAN didaftarkan\n"
	.string "dalam POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "JURULATIH yang dah kumpul semua\n"
	.string "LENCANA GIM di HOENN patut menuju\l"
	.string "ke destinasi terakhir.\p"
	.string "LIGA POKéMON.\p"
	.string "Pergilah ke hujung timur HOENN, ke pulau\n"
	.string "EVER GRANDE.\p"
	.string "Di sana, kamu akan jumpa LIGA POKéMON.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Tinggal satu saja LENCANA lagi untuk\n"
	.string "didapatkan di HOENN.\p"
	.string "Kalau kamu nak cabar LIGA POKéMON,\n"
	.string "kamu mesti dapatkan LENCANA terakhir\l"
	.string "dari GIM di FORTREE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "GIM POKéMON BANDAR SOOTOPOLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "GIM POKéMON BANDAR SOOTOPOLIS\p"
	.string "JURULATIH DIIKTIRAF JUAN:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Ah, GIM ini baru saja kembali\n"
	.string "tenang seperti biasa…\p"
	.string "Tapi taufan muda kita dah kembali untuk\n"
	.string "menguji kami lagi!\p"
	.string "Baiklah, kawan, sudah tentu!\p"
	.string "Saya gembira menari dengan kamu\n"
	.string "sekerap mana yang kamu mahu!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, kamulah pemenangnya!\n"
	.string "Kamu kalahkan saya sekali lagi!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Kalau saya ajak kamu jadi anak\n"
	.string "murid saya, pasti kamu menolak.\p"
	.string "Saya ingin hadiahkan kot saya kepada\n"
	.string "kamu.\p"
	.string "Tapi sekali lagi, kamu akan menolak.\n"
	.string "Saya bayangkan begitulah.\p"
	.string "Dan itu, kawan, tanda pasti seorang\n"
	.string "yang mulia!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Ah, GIM ini baru saja kembali\n"
	.string "tenang seperti biasa…\p"
	.string "Tapi taufan muda kita dah kembali untuk\n"
	.string "menguji kami lagi!\p"
	.string "Baiklah, kawan, sudah tentu!\n"
	.string "Saya gembira menari dengan kamu…\p"
	.string "Ah, tidak, tidak, tidak.\n"
	.string "Kamu cuma bawa satu POKéMON.\p"
	.string "Saya harap kamu kembali dengan dua,\n"
	.string "mungkin lebih, POKéMON.$"

