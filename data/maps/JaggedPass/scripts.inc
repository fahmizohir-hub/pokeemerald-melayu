JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "DENAI BERGERIGI GUNUNG CHIMNEY…\p"
	.string "Inilah yang saya selalu idamkan\n"
	.string "pada sebuah gunung.\p"
	.string "Permukaan yang bergerigi ni…\n"
	.string "Menggegarkan jiwa saya!$"

JaggedPass_Text_EricDefeat:
	.string "Kalah buat saya rasa pahit!$"

JaggedPass_Text_EricPostBattle:
	.string "Ya, saya kalah dalam POKéMON…\p"
	.string "Tapi kalau bab cintakan gunung,\n"
	.string "saya menang!$"

JaggedPass_Text_DianaIntro:
	.string "Tempat ni bukan untuk jalan santai.\n"
	.string "Tak sesuai untuk berkelah.$"

JaggedPass_Text_DianaDefeat:
	.string "Ohhh, tidak!\n"
	.string "Tanah ni terlalu berbonggol…$"

JaggedPass_Text_DianaPostBattle:
	.string "Kamu tahu tak?\p"
	.string "Ada orang yang pandai naik basikal\n"
	.string "mendaki denai yang teruk ni.$"

JaggedPass_Text_DianaRegister:
	.string "Kamu akan datang ke sini lagi?\n"
	.string "Kalau datang, saya nak lawan lagi.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Berkelah memang seronok di mana saja.\n"
	.string "Macam POKéMON juga!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Saya kalah pun sebab tanah ni\n"
	.string "terlalu berbonggol!$"

JaggedPass_Text_DianaPostRematch:
	.string "Saya nak lupakan kekalahan ni dan\n"
	.string "nikmati pendakian berbonggol ni.$"

JaggedPass_Text_EthanIntro:
	.string "DENAI BERGERIGI susah nak dilalui.\n"
	.string "Tempat yang bagus untuk berlatih.$"

JaggedPass_Text_EthanDefeat:
	.string "Semuanya dah tamat masa kami masih\n"
	.string "cuba cari tempat berpijak…$"

JaggedPass_Text_EthanPostBattle:
	.string "Kalau saya ada BASIKAL ACRO, saya\n"
	.string "boleh lompat tebing.$"

JaggedPass_Text_EthanRegister:
	.string "Bila dah biasa dengan bonggol ni,\n"
	.string "saya pasti menang!\p"
	.string "Boleh daftar saya dalam POKéNAV kamu?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Saya dah biasa dengan bonggol ni.\n"
	.string "Sekarang saya menyanyi sambil daki.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Masih tak mudah bertarung di atas\n"
	.string "tanah berbonggol ni…$"

JaggedPass_Text_EthanPostRematch:
	.string "Saya patut dapatkan BASIKAL ACRO\n"
	.string "daripada RYDEL di BANDAR MAUVILLE…$"

JaggedPass_Text_GruntIntro:
	.string "Wah!\n"
	.string "Apa kau buat di sini?\p"
	.string "Apa aku buat di tempat macam ni?\p"
	.string "Apa kena-mengena dengan kau?$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh…\p"
	.string "Patutnya aku terus menyorok dalam\n"
	.string "MARKAS kami tadi…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Okey, o-key!\n"
	.string "Aku mengaku--kau memang kuat!\p"
	.string "Jangan risau pasal aku.\n"
	.string "Pergilah ke mana kau suka!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! Batu besar ni bergegar, macam\n"
	.string "bertindak balas pada LAMBANG MAGMA!$"

JaggedPass_Text_JulioIntro:
	.string "Aiyeeh! Seram betul meluncur turun\n"
	.string "gunung sekali harung!$"

JaggedPass_Text_JulioDefeat:
	.string "Rasa macam badan saya nak bercerai…$"

JaggedPass_Text_JulioPostBattle:
	.string "Basikal saya terlantun-lantun teruk,\n"
	.string "sakit punggung saya…$"

JaggedPass_Text_AutumnIntro:
	.string "Saya daki bukit ni setiap hari.\n"
	.string "Saya yakin dengan kekuatan saya!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm…\n"
	.string "Apa yang tak kena?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Apa agaknya batu pelik yang tersembul\n"
	.string "di atas bukit sikit dari sini?$"

