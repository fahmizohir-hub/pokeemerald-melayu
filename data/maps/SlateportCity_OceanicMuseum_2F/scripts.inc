SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applywaitmovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applywaitmovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Ya? Kalau kamu cari STERN, sayalah\n"
	.string "orangnya.\p"
	.string "Ah! Itu mesti alat ganti yang saya\n"
	.string "pesan daripada ENCIK STONE di DEVON.\p"
	.string "Terima kasih! Bagus sekali!\n"
	.string "Sekarang kami boleh bersedia untuk\l"
	.string "ekspedisi.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Hehehe, nanti dulu!\n"
	.string "Kami akan ambil alat ganti tu!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "KAPT. STERN: A-apa?\n"
	.string "Siapa kamu semua ni?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Kami TEAM AQUA!\p"
	.string "BOS kami nak alat ganti tu!\n"
	.string "Tutup mulut dan serahkan!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Awaaaah!\n"
	.string "Budak kecil kalahkan aku!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Alamak, teruknya…\n"
	.string "BOS mesti mengamuk nanti…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Hmph, pengecut cengeng!\n"
	.string "Biar aku uruskan!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Apa?!\n"
	.string "Aku pun kalah!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Sekarang macam mana? Kalau tak dapat\n"
	.string "alat ganti tu, habislah kita!\p"
	.string "Arrgh, aku tak sangka ada budak\n"
	.string "penyibuk yang masuk campur!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Aku datang nak tengok kenapa lama\n"
	.string "sangat nak rampas alat ganti, rupanya\l"
	.string "kau orang lembik ni tersangkut dengan\l"
	.string "budak kecil?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Kami TEAM AQUA,\n"
	.string "dan kami cintakan laut!\p"
	.string "Dan akulah ketua TEAM AQUA, ARCHIE!\p"
	.string "Apa yang buat kau masuk campur urusan\n"
	.string "kami?\p"
	.string "…Tidak! Takkanlah!\n"
	.string "Kau bukan ahli TEAM MAGMA, kan?\p"
	.string "Tunggu, tak mungkin.\n"
	.string "Pakaian kau tak sesuai.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, manusia… Semua kehidupan\n"
	.string "bergantung pada laut.\p"
	.string "Jadi, TEAM AQUA berjuang untuk\n"
	.string "meluaskan lautan.\p"
	.string "Kau setuju, kan? Apa yang kami buat\n"
	.string "ialah usaha yang agung.\p"
	.string "Ah, sudahlah…\n"
	.string "Kau masih terlalu muda untuk faham\l"
	.string "matlamat murni kami.\p"
	.string "Tapi aku beri amaran, jangan sesekali\n"
	.string "fikir nak ganggu rancangan kami lagi.\p"
	.string "Akibatnya akan sangat mahal buat kau!\p"
	.string "Dan jangan kau lupa!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "KAPT. STERN: Kamu…\n"
	.string "Ah, ya, kamu {PLAYER}{KUN}…\p"
	.string "Apa-apa pun, tadi tu memang tegang!\n"
	.string "Terima kasih kerana selamatkan kami!\p"
	.string "Oh, ya, hampir saya terlupa yang kamu\n"
	.string "bawa alat ganti dari DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "KAPT. STERN: Alamak!\n"
	.string "Tak boleh buang masa!\p"
	.string "Kami perlu mulakan ekspedisi dasar laut\n"
	.string "tak lama lagi.\p"
	.string "Terima kasih sekali lagi, tapi saya kena\n"
	.string "pergi sekarang!\p"
	.string "Tapi silalah jalan-jalan dan tengok\n"
	.string "kemudahan kami.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "Saya nampak model kapal di sini.\p"
	.string "Ia buat saya teringat KAPAL TERBIAR\n"
	.string "dekat PEKAN DEWFORD…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Jangan berani berlari-lari dalam\n"
	.string "MUZIUM!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Wah, kapal selam tu hebat!\n"
	.string "Saya nak naik!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“SAMPEL KUALITI AIR 1,” tertulis pada\n"
	.string "label.\p"
	.string "Laut semuanya bersambung, tapi airnya\n"
	.string "nampak berbeza ikut kawasan.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“SAMPEL KUALITI AIR 2,” tertulis pada\n"
	.string "label.\p"
	.string "Adakah kemasinan air laut juga berbeza\n"
	.string "ikut kawasan?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Sebiji bola getah mengembang dan\n"
	.string "mengecut.\p"
	.string "“Di laut, berat air itu sendiri\n"
	.string "menghasilkan tekanan.\p"
	.string "“Di air cetek, tekanannya tidak begitu\n"
	.string "berat.\p"
	.string "“Namun, di air yang sangat dalam,\n"
	.string "tekanan boleh mencecah puluhan ribu\l"
	.string "tan pada kawasan yang kecil.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MODEL WILAYAH HOENN”\p"
	.string "Ini diorama kecil wilayah HOENN.\p"
	.string "Di mana PEKAN LITTLEROOT dalam model\n"
	.string "ni?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "Ini pameran tentang aliran air laut.\p"
	.string "“Berhampiran dasar laut, air mengalir\n"
	.string "disebabkan perbezaan faktor seperti\l"
	.string "suhu dan kemasinan.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "Ini pameran tentang aliran air laut.\p"
	.string "“Berhampiran permukaan, air laut\n"
	.string "mengalir sebagai arus yang ditolak oleh\l"
	.string "angin.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“FERI S.S. TIDAL\p"
	.string "“Replika berskala kapal yang sedang\n"
	.string "dibina di LIMBUNGAN STERN.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“KAPAL SELAM PENEROKA 1\p"
	.string "“Replika kapal selam berprestasi tinggi\n"
	.string "untuk penjelajahan dasar laut.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“KAPSUL SELAM\p"
	.string "“Replika kapsul kecil tanpa pemandu\n"
	.string "untuk penjelajahan dasar laut.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“S.S. ANNE\p"
	.string "“Replika kapal persiaran mewah yang\n"
	.string "mengelilingi dunia.”$"

