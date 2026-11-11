SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applywaitmovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applywaitmovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applywaitmovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applywaitmovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Selamat datang ke MUZIUM LAUTAN.\p"
	.string "Bayaran masuk ialah ¥50.\n"
	.string "Anda mahu masuk?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Selamat menikmati lawatan anda.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh? Maaf, nampaknya wang anda tak\n"
	.string "mencukupi.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh? Anda dari kumpulan yang masuk\n"
	.string "tadi?\p"
	.string "Anda seorang saja yang lewat.\n"
	.string "Baik anda cepat kejar mereka!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Kami, TEAM AQUA, wujud demi kebaikan\n"
	.string "semua!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Kami disuruh berkumpul di sini, jadi kami\n"
	.string "datanglah, tapi…\p"
	.string "BOS kami, tulang belakang kami, tak ada\n"
	.string "pula.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Kalau aku curi barang-barang di sini,\n"
	.string "aku boleh jadi kaya ke?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Apa yang aku belajar di sini, boleh aku\n"
	.string "guna untuk kerja-kerja jahat…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Kalau budak-budak kita tak buat\n"
	.string "kucar-kacir di RUSTBORO, kita takkan\l"
	.string "ada di sini!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Aku tak ada ¥50, jadi lama juga baru\n"
	.string "dapat lepas penyambut tetamu tu.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Saya nak belajar tentang laut dan guna\n"
	.string "ilmu tu untuk bertarung.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Saya jadi teruja dan seronok sangat\n"
	.string "bila nampak laut!\p"
	.string "Bagi saya, KAPT. STERN ialah idola\n"
	.string "nombor satu!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "Laut ni luas tanpa penghujung, dan\n"
	.string "dalam tak terhingga…\p"
	.string "Mesti ada banyak POKéMON yang kita tak\n"
	.string "tahu.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Saya nak POKéMON laut.\p"
	.string "Mesti sejuk dan selesa bila dipeluk.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aiyeeeh!\n"
	.string "Apa kau buat di sini?\p"
	.string "Aku? Aku ahli TEAM AQUA yang kau\n"
	.string "belasah dulu, ingat tak?\l"
	.string "Di TEROWONG RUSTURF?\p"
	.string "Nah, ambil ni!\n"
	.string "Kau kena maafkan aku!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "TM tu lebih sesuai dengan kau daripada\n"
	.string "aku.\p"
	.string "Harap aku takkan jumpa kau lagi!\n"
	.string "Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Alaaa, tolonglah!\n"
	.string "Kau kena ambil ni dan lepaskan aku!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Cecair biru berpusar di dalam bekas\n"
	.string "kaca.\p"
	.string "“Ini eksperimen untuk mencipta\n"
	.string "PUSARAN AIR secara buatan\l"
	.string "menggunakan angin.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Sebiji bola merah terapung naik turun di\n"
	.string "dalam bekas kaca.\p"
	.string "“Ini eksperimen menyerupai AIR TERJUN\n"
	.string "menggunakan daya apungan bola.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "Ini sampel tanah dari dasar laut.\p"
	.string "“Selama bertahun-tahun, sisa hidupan\n"
	.string "mendap di dasar laut dan membentuk\l"
	.string "lapisan sedimen.\p"
	.string "“Dengan menganalisis lapisan ini, masa\n"
	.string "lampau purba dapat didedahkan.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "Ini sampel pasir pantai.\p"
	.string "“Batu dari gunung dihanyutkan sungai\n"
	.string "lalu terhakis dan terkikis.\p"
	.string "“Ia menjadi butiran halus dan akhirnya\n"
	.string "menjadi pasir di pantai.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“FAKTA MINI LAUTAN 1\n"
	.string "Kenapa air laut berwarna biru?\p"
	.string "“Cahaya terdiri daripada banyak warna.\p"
	.string "“Bila cahaya melalui air, kebanyakan\n"
	.string "jenis cahaya hilang warnanya.\p"
	.string "“Namun, cahaya biru kekal warnanya,\n"
	.string "menjadikan laut kelihatan biru.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“FAKTA MINI LAUTAN 2\n"
	.string "Kenapa laut masin?\p"
	.string "“Air laut mengandungi garam terlarut\n"
	.string "dalam bentuk ion natrium dan klorin.\p"
	.string "“Ion ini larut keluar dari batu dan\n"
	.string "dibawa ke laut oleh hujan.\p"
	.string "“Kepekatan garam terlarut menjadikan\n"
	.string "laut masin.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“FAKTA MINI LAUTAN 3\n"
	.string "Mana lebih besar? Laut atau darat?\p"
	.string "“Laut meliputi kira-kira 70% planet ini,\n"
	.string "dan selebihnya daratan.\p"
	.string "“Oleh itu, laut lebih dua kali ganda saiz\n"
	.string "daratan.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "Ini fosil dengan rabung beralun\n"
	.string "padanya.\p"
	.string "“Tanah di dasar laut dihakis oleh air\n"
	.string "pasang surut.\p"
	.string "“Air laut yang mengalir menandakan\n"
	.string "tanah dengan rabung dan lurah kecil.\p"
	.string "“Jika tanah ini menjadi fosil, ia\n"
	.string "dipanggil tanda riak.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Sebuah mesin pelik berputar di bawah\n"
	.string "kubah kaca.\p"
	.string "Mungkin untuk mengukur kedalaman\n"
	.string "sesuatu…$"

