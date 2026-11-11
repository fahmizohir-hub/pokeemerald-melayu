PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "Laut antara PACIFIDLOG dan SLATEPORT\n"
	.string "ada arus yang sangat deras.\p"
	.string "Kalau kamu guna LUNCUR OMBAK, kamu\n"
	.string "mungkin dihanyutkan ke tempat lain.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Tengok, menarik, kan?\n"
	.string "Rumah-rumah ni atas air!\p"
	.string "Saya lahir di sini!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "TIANG LANGIT?\p"
	.string "…Oh, maksud kamu menara tinggi\n"
	.string "menjulang di sebelah sana tu.\p"
	.string "Kalau saya, saya tak nak panjat.\n"
	.string "Seram sangat naik tinggi macam tu.\p"
	.string "Hidup di paras laut di PACIFIDLOG ni dah\n"
	.string "cukup bagi saya.$"

PacifidlogTown_Text_TownSign:
	.string "PEKAN PACIFIDLOG\p"
	.string "“Tempat mentari pagi tersenyum\n"
	.string "ke atas air.”$"

