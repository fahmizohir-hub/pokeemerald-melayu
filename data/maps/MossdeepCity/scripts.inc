MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applywaitmovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Saya dapat ni daripada STEVEN, tapi\n"
	.string "saya tak tahu apa gunanya.\p"
	.string "Rasanya namanya BATU RAJA.\n"
	.string "Kamu nak?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Kenapa kamu nak benda ni?\n"
	.string "Peliklah kamu.\p"
	.string "Kamu boleh simpan, tapi rahsiakan\n"
	.string "daripada STEVEN.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "Rumah STEVEN di sebelah sana tu!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Ha, kamu pun fikir macam tu! Nak buat\n"
	.string "apa dengan batu pelik macam tu?$"

MossdeepCity_Text_WailmerWatching:
	.string "Di sekitar MOSSDEEP, kamu boleh nampak\n"
	.string "WAILMER liar.\p"
	.string "Namanya, err…\n"
	.string "Apa ya…\p"
	.string "WAI, WAI, WAI…\p"
	.string "Meninjau WAILMER!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "PUSAT ANGKASA di pulau ni asyik\n"
	.string "melancarkan roket besar.\p"
	.string "Baru-baru ni kecoh sikit pasal sepucuk\n"
	.string "surat yang mereka terima.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "PUSAT ANGKASA di pulau ni asyik\n"
	.string "melancarkan roket besar.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Kawan saya, seorang KELASI, cakap\n"
	.string "TEAM AQUA buka markas di LILYCOVE.\p"
	.string "Saya dengar juga ada orang datang\n"
	.string "dan belasah mereka cukup-cukup!\p"
	.string "Tapi MOSSDEEP ni pula\n"
	.string "jadi sasaran TEAM MAGMA.\p"
	.string "Kalau kamu nak tahu apa rancangan\n"
	.string "mereka, pergilah ke PUSAT ANGKASA.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Saya KELASI, jadi tentulah laut lebih\n"
	.string "penting bagi saya.\p"
	.string "Tapi kamu tahu? Bila saya jejak darat\n"
	.string "selepas pelayaran panjang, memang rasa\l"
	.string "lega!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Mesti indah, kan?\p"
	.string "Kalau seluruh dunia dilitupi\n"
	.string "tumbuhan dan bunga macam pulau ni?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Semua makhluk perlukan laut untuk\n"
	.string "hidup, walaupun mereka tinggal di darat.\p"
	.string "Bila sampai ajal, makhluk hidup\n"
	.string "jadi tanah dan kembali ke bumi.\p"
	.string "Dan laut sentiasa\n"
	.string "bersambung dengan daratan.\p"
	.string "Ya, macam pantai di sini.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Belayar naik kapal pun bagus juga.\p"
	.string "Tapi menyeberang laut bersama POKéMON\n"
	.string "guna LUNCUR OMBAK…\p"
	.string "Itu baru perjalanan yang mengujakan!\n"
	.string "Betul tak, anak muda?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Batu ni ada makna istimewa bagi\n"
	.string "orang-orang di PUSAT ANGKASA.\p"
	.string "Mereka letak di sini sebagai hajat\n"
	.string "supaya roket mereka terbang dengan\l"
	.string "selamat.\p"
	.string "Bila kamu berhajat, kamu guna apa? Kamu\n"
	.string "berhajat pada bintang?\p"
	.string "Saya guna tag hajat supaya ia jadi\n"
	.string "kenyataan. Itulah cara saya.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "Ini batu putih.$"

MossdeepCity_Text_GymSign:
	.string "GIM POKéMON BANDAR MOSSDEEP\n"
	.string "KETUA: LIZA & TATE\p"
	.string "“Gabungan mistik!”$"

MossdeepCity_Text_CitySign:
	.string "BANDAR MOSSDEEP\n"
	.string "“Slogan kami: Sayangi POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "PUSAT ANGKASA MOSSDEEP\n"
	.string "“Tempat paling dekat dengan angkasa.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, sihat?\n"
	.string "Saya sihat walafiat!\p"
	.string "Saya dengar KETUA GIM MOSSDEEP\n"
	.string "agak kuat, jadi saya\l"
	.string "datang nak tengok sendiri.\p"
	.string "Tapi ada sesuatu yang tak\n"
	.string "kena dengan bandar ni.\p"
	.string "Orang ramai asyik bercakap pasal\n"
	.string "surat amaran dan PUSAT ANGKASA…\p"
	.string "Tapi rasanya tak ada\n"
	.string "kena-mengena dengan saya pun.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… Seronoknya biar\n"
	.string "ombak membasahi kaki…\p"
	.string "Cakap pasal ombak, kamu tahu\n"
	.string "bandar pulau SOOTOPOLIS?\p"
	.string "Rasanya GIM di sana ada KETUA baru.\p"
	.string "Orang kata KETUA baru tu\n"
	.string "pernah jadi guru WALLACE.$"

