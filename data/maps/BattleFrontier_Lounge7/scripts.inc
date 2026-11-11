BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "Kamu takkan percaya kalau tengok\n"
	.string "sekarang, tapi dulu saya JURULATIH\l"
	.string "yang sangat handal.\p"
	.string "Saya terkenal sebagai JELITA paling\n"
	.string "hebat di sekitar sini, tahu tak!\p"
	.string "… … … … … …\p"
	.string "Apa lagi? Kamu tak percaya cakap saya.\p"
	.string "Saya tak sama macam perempuan cakap\n"
	.string "besar di sana tu. Saya memang berbakat!\p"
	.string "Biar saya buktikan. Saya boleh ajar\n"
	.string "POKéMON kamu move yang istimewa tapi\l"
	.string "comel.\p"
	.string "Tapi pelajaran saya tak percuma. Apa\n"
	.string "kata kamu bayar move yang saya ajar\l"
	.string "dengan sedikit Mata Tarung?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Kamu datang lagi nak belajar move\n"
	.string "POKéMON yang istimewa tapi comel?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Baiklah, baiklah, tengok sini!\n"
	.string "Move mana yang patut saya ajar?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "Move {STR_VAR_1}, ya? Harganya\n"
	.string "{STR_VAR_2} Mata Tarung, boleh?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Baiklah, baiklah, sekarang pilih\n"
	.string "POKéMON yang patut saya ajar move tu.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Apa ni… Mata Tarung kamu tak cukup!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Sekarang kamu nampak betapa mahirnya\n"
	.string "saya? Saya ambil Mata Tarung kamu,\l"
	.string "terima kasih!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Apa? Kamu tak mahu…\p"
	.string "Kalau nak tengok kemahiran saya,\n"
	.string "datanglah jumpa saya bila-bila masa!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "Memang susah nak percaya sekarang,\n"
	.string "tapi dulu saya JURULATIH yang sangat\l"
	.string "hebat.\p"
	.string "Saya terkenal sebagai PERENANG yang\n"
	.string "paling tak terkalahkan di sekitar sini,\l"
	.string "tahu tak!\p"
	.string "… … … … … …\p"
	.string "Kenapa? Kamu tak percaya cakap saya.\p"
	.string "Saya tak sama macam perempuan badut\n"
	.string "di sana tu. Saya memang berpengalaman!\p"
	.string "Saya boleh buktikan. Saya boleh ajar\n"
	.string "POKéMON kamu move yang keras tapi\l"
	.string "cantik.\p"
	.string "Tapi pelajaran saya tak percuma. Apa\n"
	.string "kata kamu bayar move yang saya ajar\l"
	.string "dengan sedikit Mata Tarung?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Kamu datang nak belajar move\n"
	.string "POKéMON yang keras tapi cantik?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Tengok cara mak cik berdua tu kutuk\n"
	.string "satu sama lain, mesti kamu ingat mereka\l"
	.string "tak sebulu.\p"
	.string "Tapi kalau betul begitu, takkanlah\n"
	.string "mereka duduk sama-sama di sini, kan?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Masa saya masih ANAK MUDA kecil,\n"
	.string "mak cik berdua tu kuat dan cantik.\p"
	.string "Mereka jadi idola kami semua JURULATIH.\p"
	.string "Sampai sekarang pun, usia tak\n"
	.string "melemahkan kebolehan mereka.\p"
	.string "Malah, move POKéMON\n"
	.string "mereka jadi lebih mantap.\p"
	.string "Tapi… Entah kenapa, saya\n"
	.string "tak dapat elak rasa begini…\p"
	.string "Masa memang kejam…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Pulihkan sehingga\n"
	.string "separuh HP maks\n"
	.string "pengguna.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Beri kerosakan\n"
	.string "sama dengan tahap\n"
	.string "pengguna.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Serap separuh\n"
	.string "kerosakan ke atas\n"
	.string "musuh yang tidur.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Tumbukan kuat\n"
	.string "dengan kuasa yang\n"
	.string "luar biasa.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Sepakan yang\n"
	.string "amat kuat dengan\n"
	.string "daya dahsyat.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Hempasan seluruh\n"
	.string "badan, mungkin\n"
	.string "melumpuhkan.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Batu besar\n"
	.string "dihumban. Mungkin\n"
	.string "musuh gentar.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Balas serangan\n"
	.string "fizikal dengan\n"
	.string "kuasa berganda.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Kejutan elektrik\n"
	.string "lemah yang\n"
	.string "lumpuhkan musuh.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Tarian tempur,\n"
	.string "SERANGAN naik\n"
	.string "mendadak.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Bergulung tutup\n"
	.string "titik lemah, dan\n"
	.string "PERTAHANAN naik.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Serangan bising\n"
	.string "yang hanya boleh\n"
	.string "diguna masa tidur.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Baling lumpur ke\n"
	.string "muka musuh supaya\n"
	.string "tepatnya turun.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Sinar berbentuk\n"
	.string "bintang yang tak\n"
	.string "pernah tersasar.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Serangan dingin\n"
	.string "yang turunkan\n"
	.string "KELAJUAN musuh.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Bertahan apa jua\n"
	.string "serangan 1 giliran\n"
	.string "dengan baki 1HP.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Salin kesan stat\n"
	.string "musuh kepada\n"
	.string "pengguna.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Tumbukan berais\n"
	.string "yang mungkin\n"
	.string "membekukan musuh.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Tumbukan elektrik\n"
	.string "yang mungkin\n"
	.string "lumpuhkan musuh.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Tumbukan berapi\n"
	.string "yang mungkin\n"
	.string "membakar musuh.$"
