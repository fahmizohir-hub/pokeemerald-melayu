SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Ada katil…\n"
	.string "Jom berehat.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Saya selalu belayar ke BANDAR\n"
	.string "LILYCOVE.\p"
	.string "Saya suka menyertai PERTANDINGAN,\n"
	.string "tahu tak.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Seronok betul pertarungan tadi!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Saya teruja sangat bayangkan POKéMON\n"
	.string "apa yang akan saya tengok dalam\l"
	.string "PERTANDINGAN akan datang. Tak sabar!$"

SSTidalRooms_Text_MicahIntro:
	.string "Kawan-kawan kamu kuat tak?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Kawan-kawan kamu memang kuat.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Kawan tak semestinya manusia.\n"
	.string "Bagi saya, POKéMON sahabat berharga!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Nak…\n"
	.string "Kamu ada ketuk pintu tadi?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Kekalahan harus diterima tanpa gopoh\n"
	.string "atau panik.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Tak pernah gelabah dalam apa jua\n"
	.string "keadaan, itulah adab lelaki budiman.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Malu juga saya, tapi…\n"
	.string "Kami tunjukkan kuasa cinta kami!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Haih…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: Pertama kali kuasa cinta kami\n"
	.string "tak berjaya!\l"
	.string "Mesti kamu JURULATIH yang hebat!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Kamu cuma ada satu POKéMON?\n"
	.string "Tak sunyi ke?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Rasa macam mengada pula, tapi…\n"
	.string "Kami tunjukkan kuasa cinta kami!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Alaa!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Tak sangka!\n"
	.string "Kuasa cinta kami gagal…\l"
	.string "Mesti kamu JURULATIH yang hebat!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Saya nak bertarung…\n"
	.string "Tapi kamu tak ada dua POKéMON pun…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, kamu datang tepat pada masanya.\p"
	.string "Saya bosan, tahu tak.\n"
	.string "Kamu boleh hiburkan saya.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Cukuplah tu.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Mungkin saya patut minta Ayahanda\n"
	.string "belikan kapal layar mewah untuk saya.\l"
	.string "Untuk saya dan POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, comelnya JURULATIH ni.\n"
	.string "Nak minum teh?\l"
	.string "Atau kamu lebih suka bertarung?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Begitu.\n"
	.string "Kamu jenis yang aktif.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Pelayaran dunia dengan kapal mewah\n"
	.string "memang ada daya tarikannya…\p"
	.string "Tapi saya akui, melancong di HOENN\n"
	.string "dengan feri pun ada keseronokannya.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Err… Hai! Sa… Saya tak buat benda pelik!\n"
	.string "Err… Ambillah ni! Percuma!\p"
	.string "Ini… Sumpah, saya tak RAMPAS benda\n"
	.string "ni dari orang! Saya takkan buat\l"
	.string "begitu! Ia bersih! Gunalah!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "RAMPAS mencuri kesan baik move\n"
	.string "tertentu sebelum ia dapat diguna\l"
	.string "oleh musuh atau rakan.$"

