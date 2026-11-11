Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "BOS berminat dengan kajian yang\n"
	.string "dibuat di sini, jadi dia hantar\l"
	.string "kami ke sini.\p"
	.string "Jangan masuk campur!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Celaka…\n"
	.string "Dikalahkan oleh budak…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "BOS kami tahu segala-galanya.\p"
	.string "Tapi aku cuma ANAK BUAH. Mana aku tahu\n"
	.string "apa yang dia fikirkan?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Hah?\n"
	.string "Apa budak buat di sini?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Hah?\n"
	.string "Aku kalah?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, tidak…\n"
	.string "Teruk aku kena marah sebab kalah…\p"
	.string "Baik aku tidur saja atas katil tu…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Masa saya tidur, semua orang naik\n"
	.string "ke tingkat atas!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Wah, kamu memang kuat!\p"
	.string "Saya pun nak jadi JURULATIH POKéMON\n"
	.string "macam kamu!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "PROFESOR suka hujan.\n"
	.string "Itu fakta.\p"
	.string "Tapi kalau hujan tak henti, orang\n"
	.string "akan susah. Itu pun fakta.\p"
	.string "Jadi, PROFESOR sedang mengkaji cara\n"
	.string "hujan boleh dimanfaatkan.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Di tingkat 2 INSTITUT ni, kami kaji\n"
	.string "corak cuaca di seluruh rantau\l"
	.string "HOENN.\p"
	.string "Baru-baru ni kami perasan ada kes\n"
	.string "kemarau dan hujan lebat yang\l"
	.string "sementara dan terpencil…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Helo!\n"
	.string "Kami terselamat berkat tindakan kamu!\p"
	.string "Yang saya tak faham, apa sebenarnya\n"
	.string "yang orang AQUA tu nak buat.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Ada katil…\n"
	.string "Jom berehat.$"

