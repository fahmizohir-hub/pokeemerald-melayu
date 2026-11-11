LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applywaitmovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "IBU: Tengok, {PLAYER}? Dalam\n"
	.string "rumah pun cantik, kan?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "POKéMON syarikat pindah yang buat\n"
	.string "semua kerja angkat barang dan kemas\l"
	.string "rumah. Senang betul!\p"
	.string "{PLAYER}, bilik kamu di tingkat\n"
	.string "atas. Pergilah tengok, sayang!\p"
	.string "AYAH belikan kamu jam baru sempena kita\n"
	.string "pindah ke sini. Jangan lupa setkan!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "IBU: Hmm, {PLAYER}?\p"
	.string "Kamu tak nak tengok\n"
	.string "bilik kamu sendiri ke?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "IBU: {PLAYER}.\p"
	.string "Pergi setkan jam dalam\n"
	.string "bilik kamu, sayang.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "IBU: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Cepat! Mari sini cepat!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "IBU: Tengok! GIM PETALBURG!\n"
	.string "Mungkin AYAH masuk TV!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "IBU: Oh… Dah habis.\p"
	.string "Rasanya AYAH ada tadi, tapi\n"
	.string "kita terlepas. Sayangnya.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Oh, ya. Salah seorang kawan\n"
	.string "AYAH tinggal di pekan ni.\p"
	.string "Namanya PROF. BIRCH.\p"
	.string "Dia tinggal di sebelah rumah kita,\n"
	.string "jadi pergilah kenalkan diri kamu.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "IBU: Jumpa lagi, sayang!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "IBU: Kamu dah kenalkan\n"
	.string "diri pada PROF. BIRCH?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "IBU: Kamu apa khabar,\n"
	.string "{PLAYER}? Nampak penat sikit.\p"
	.string "Ibu rasa kamu patut berehat sekejap.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "IBU: Jaga diri, sayang!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "IBU: Oh? AYAH bagi LENCANA tu?\p"
	.string "Kalau macam tu, ini pula\n"
	.string "hadiah daripada IBU!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Jangan paksa diri sangat, sayang.\n"
	.string "Kamu boleh balik rumah bila-bila.\p"
	.string "Teruskan usaha, sayang!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "IBU: Apa tu, sayang? POKéNAV?\n"
	.string "Orang DEVON yang bagi?\p"
	.string "Hmm, sayang, apa kata\n"
	.string "daftarkan Ibu sekali?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "IBU didaftarkan\n"
	.string "dalam POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "PEMBERITA: …Itulah laporan kami\n"
	.string "dari hadapan GIM PETALBURG.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Ada filem di TV.\p"
	.string "Dua lelaki sedang menari di atas\n"
	.string "papan kekunci piano yang besar.\p"
	.string "Baik cepat pergi!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "Ini buku arahan untuk KASUT LARI.\p"
	.string "“Tekan Butang B semasa memakai\n"
	.string "KASUT LARI untuk berlari pantas!\p"
	.string "“Sarung KASUT LARI ini dan\n"
	.string "berlumba di alam terbuka!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "AYAH: Hm?\p"
	.string "Eh, {PLAYER} rupanya!\p"
	.string "Lama Ayah tak jumpa kamu, tapi\n"
	.string "kamu nampak… lebih kuat sekarang.\p"
	.string "Itu yang Ayah rasa. Tapi ayah\n"
	.string "kamu ni belum mengalah lagi!\p"
	.string "Oh, ya, Ayah ada sesuatu untuk kamu. Ini\n"
	.string "dihantar oleh seseorang bernama ENCIK\l"
	.string "BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "AYAH: Hm, TIKET feri?\p"
	.string "Kalau tak silap, ada pelabuhan\n"
	.string "feri di SLATEPORT dan LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Ayah kena balik ke GIM PETALBURG.\p"
	.string "IBU, terima kasih jaga\n"
	.string "rumah masa Ayah tiada.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "IBU: AYAH kamu tu…\p"
	.string "Lama baru balik rumah, tapi\n"
	.string "asyik cakap pasal POKéMON saja.\p"
	.string "Patutnya dia berehat\n"
	.string "dan tinggal lama sikit.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "IBU: Itu berita tergempar ke?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Kami bawakan berita kecemasan ini!\p"
	.string "Di beberapa tempat di HOENN, ada\n"
	.string "laporan tentang POKéMON berwarna\l"
	.string "BZZT… yang sedang terbang.\p"
	.string "Identiti POKéMON ini\n"
	.string "masih belum diketahui.\p"
	.string "Kami kembali ke rancangan\n"
	.string "filem seperti biasa.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "IBU: {PLAYER}, kamu dengar tak tadi?\p"
	.string "Apa warna POKéMON yang\n"
	.string "pemberita tu sebut?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "IBU: Hebat, kan! Masih ada\n"
	.string "POKéMON yang belum diketahui.$"
