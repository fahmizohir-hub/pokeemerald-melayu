MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Kenangan bersama SKITTY kesayangan\n"
	.string "saya… Berlinang air mata bila teringat.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Aduh, sakitnya… Ada lubang di lantai\n"
	.string "sana sini.\p"
	.string "Saya tak perasan, terus jatuh dari\n"
	.string "tingkat atas.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hoi! Kamu cari POKéMON ke?\n"
	.string "Kamu ikut saya! Biadabnya!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Aiyaaaaa!\n"
	.string "Maaf, ampunkan saya!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Orang jarang datang ke sini, jadi saya\n"
	.string "ingat ada POKéMON nadir.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE: Kami datang sini sebab disahut\n"
	.string "cabaran.\p"
	.string "Hehe, kalau saya tunjuk betapa\n"
	.string "hebatnya saya, mesti dia jatuh cinta.\l"
	.string "Saya tahu!\p"
	.string "Saya tahu! Saya belasah kamu dan\n"
	.string "tunjuk pada dia betapa hebatnya saya!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE: Alamak!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE: Kita kalah, tapi tak apa! Saya ada\n"
	.string "di sisi kamu. Kita akan lepasi cabaran\l"
	.string "ni!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE: Kalau nak lawan saya, bawa lebih\n"
	.string "banyak POKéMON.\p"
	.string "Kalau tidak, saya tak dapat tunjuk pada\n"
	.string "teman wanita saya betapa hebatnya\l"
	.string "saya!$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ: Saya datang sini sebab disahut\n"
	.string "cabaran dengan teman lelaki saya.\p"
	.string "Memang seram sangat, tapi saya bersama\n"
	.string "teman lelaki saya. Tak apa.\p"
	.string "Saya tahu! Saya akan buat teman lelaki\n"
	.string "saya nampak hebat dengan kalahkan\l"
	.string "kamu!$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ: Waaaa! Saya takut!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ: Kami sedang hangat bercinta, jadi\n"
	.string "kalah pun tak kisah!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ: Kalau nak cabar kami, kamu patut\n"
	.string "bawa sekurang-kurangnya dua POKéMON.\p"
	.string "Teman lelaki saya kuat.\n"
	.string "Satu POKéMON langsung tak cukup.$"

MtPyre_2F_Text_LeahIntro:
	.string "Wajah kamu asing di sini…\n"
	.string "Pergilah sebelum sesuatu menimpa kamu!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm…\n"
	.string "Kamu memang tahan lasak.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Keluarga kami dah jadi JURULATIH di sini\n"
	.string "sejak zaman moyang saya…\p"
	.string "Menjadi tugas saya untuk melindungi\n"
	.string "gunung ini…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kyaaaaaa!\n"
	.string "Saya takut!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Tidaaaaak!\n"
	.string "Saya hilang akal!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Saya terkejut setiap kali nampak\n"
	.string "apa-apa yang bergerak…\p"
	.string "Patutnya saya tak datang berlatih di\n"
	.string "sini…$"

