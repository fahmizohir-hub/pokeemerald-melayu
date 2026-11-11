EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkUp4
	delay 40
	applywaitmovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applywaitmovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applywaitmovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	delay 20
	applywaitmovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applywaitmovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "WALLACE: Selamat datang, {PLAYER}{KUN}.\p"
	.string "Kejadian di BANDAR SOOTOPOLIS itu…\n"
	.string "Kerja yang hebat, kamu tamatkan\l"
	.string "krisis itu seorang diri.\p"
	.string "Eh, silap!\p"
	.string "Tak adil kalau saya kata kamu seorang\n"
	.string "saja yang tamatkan krisis itu.\p"
	.string "Kamu atasi keadaan sukar itu dengan\n"
	.string "bersatu hati bersama POKéMON kamu.\p"
	.string "Kami JURULATIH membesarkan POKéMON\n"
	.string "dengan memberi mereka barang dan\l"
	.string "mengajar teknik pertarungan baru.\p"
	.string "Tapi kami sendiri pun belajar banyak\n"
	.string "perkara daripada POKéMON.\p"
	.string "Di sinilah pencapaian kamu diuji\n"
	.string "berbanding pencapaian orang lain\l"
	.string "yang macam kamu.\p"
	.string "Sekarang!\p"
	.string "Siapakah yang paling anggun menari\n"
	.string "bersama POKéMON di HOENN?\p"
	.string "Tunjukkan kepada saya di sini,\n"
	.string "sekarang!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Saya, sang JUARA, akhirnya tewas…\p"
	.string "Hebat sungguh.\n"
	.string "Kamu anggun, sampai saya geram.\l"
	.string "Namun ia sungguh gemilang!\p"
	.string "Syabas, {PLAYER}{KUN}!\p"
	.string "Kamu memang JURULATIH POKéMON yang\n"
	.string "mulia!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "WALLACE: POKéMON yang kamu hantar ke\n"
	.string "pertarungan…\p"
	.string "Ada kalanya mereka menari bagai\n"
	.string "bayu musim bunga, ada kalanya\l"
	.string "mereka menyambar bagai kilat.\p"
	.string "Dengan keanggunan yang ringan tapi\n"
	.string "mantap, kamu memimpin POKéMON kamu.\p"
	.string "Saya sendiri pun terpesona dengan\n"
	.string "persembahan hebat kamu!\p"
	.string "Kamu kini berdiri di puncak gemilang\n"
	.string "LIGA POKéMON.\p"
	.string "Dengan ini, wilayah HOENN\n"
	.string "mengisytiharkan kamu sebagai…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "Aku ada nasihat sebelum kau cabar\n"
	.string "JUARA…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "MAY: Eh?\n"
	.string "Apa, apa, apa?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Jangan-jangan…\l"
	.string "Dah habis ke?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRENDAN: {PLAYER}!\p"
	.string "Nak dengar nasihat aku sebelum kau\n"
	.string "cabar JUARA?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRENDAN: {PLAYER}…\p"
	.string "Kau nak cakap yang…\n"
	.string "Kau dah kalahkan JUARA?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. BIRCH: Tengok?\n"
	.string "Apa saya cakap, {RIVAL}?\p"
	.string "Kan saya dah kata tak perlu risau pasal\n"
	.string "{PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, akhirnya kamu berjaya.\p"
	.string "Bila saya dengar kamu kalahkan ayah\n"
	.string "kamu sendiri di GIM PETALBURG, saya\l"
	.string "rasa kamu mungkin ada peluang…\p"
	.string "Tapi tak sangka kamu betul-betul jadi\n"
	.string "JUARA!\p"
	.string "Ah, ya!\p"
	.string "Macam mana dengan POKéDEX kamu?\n"
	.string "Mari, saya tengok.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. BIRCH: Apa-apa pun,\n"
	.string "tahniah!\p"
	.string "Sekarang, masuklah ke bilik terakhir\n"
	.string "dengan bangga!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "WALLACE: {PLAYER}{KUN}…\p"
	.string "Tidak, biar saya sebut dengan betul.\p"
	.string "JUARA yang baru!\p"
	.string "Ikut saya.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "WALLACE: Maaf, tapi…\p"
	.string "Dari sini, hanya JURULATIH yang dah\n"
	.string "jadi JUARA boleh masuk.\p"
	.string "Kamu kena tunggu di luar bersama PROF.\n"
	.string "BIRCH.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "MAY: Huhu…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Aku bergurau saja! Tak apa!\n"
	.string "Memang itu peraturannya!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Ikhlas dari hati, tahniah!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRENDAN: Apaaa?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Nak buat macam mana, dah itu\n"
	.string "peraturannya.\p"
	.string "{PLAYER}, hebat kau!\n"
	.string "Tahniah!$"

