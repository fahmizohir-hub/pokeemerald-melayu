RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Riak wajah yang penuh tekad…\n"
	.string "Gerak-geri yang tangkas… Dan POKéMON\l"
	.string "yang terlatih…\p"
	.string "Jelas sekali kamu JURULATIH yang mahir!\p"
	.string "Eh, nanti, jangan cakap apa-apa. Tengok\n"
	.string "muka pun saya dah tahu.\p"
	.string "Saya yakin kamu boleh guna MESIN\n"
	.string "TERSEMBUNYI ni dengan baik.\p"
	.string "Tak payah malu-malu. Ambillah!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "MESIN TERSEMBUNYI tu, atau ringkasnya\n"
	.string "HM, berisi POTONGAN.\p"
	.string "Move HM boleh diguna POKéMON di\n"
	.string "luar pertarungan.\p"
	.string "POKéMON yang belajar POTONGAN boleh\n"
	.string "tebang pokok kecil kalau JURULATIHNYA\l"
	.string "ada LENCANA BATU.\p"
	.string "Lagi satu, tak macam TM, HM boleh\n"
	.string "diguna berkali-kali.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Masa BANDAR RUSTBORO diperbesar dulu,\n"
	.string "ayah saya pun tolong.\p"
	.string "Dia suruh POKéMON dia guna POTONGAN\n"
	.string "untuk tebang pokok dan\l"
	.string "bersihkan tanah.$"

