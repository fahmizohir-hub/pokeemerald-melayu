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
	.string "Tak, tunggu, jangan cakap apa-apa.\n"
	.string "Saya boleh tahu dengan tengok kamu\l"
	.string "saja.\p"
	.string "Saya yakin kamu boleh guna MESIN\n"
	.string "TERSEMBUNYI ni dengan baik.\p"
	.string "Tak payah malu-malu. Ambillah!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "MESIN TERSEMBUNYI tu, atau ringkasnya\n"
	.string "HM, ialah POTONG.\p"
	.string "Move HM ialah move yang boleh diguna\n"
	.string "POKéMON di luar pertarungan.\p"
	.string "POKéMON yang belajar POTONG boleh\n"
	.string "tebang pokok kecil kalau JURULATIHNYA\l"
	.string "ada LENCANA BATU.\p"
	.string "Dan tak macam TM, HM boleh diguna lebih\n"
	.string "dari sekali.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Masa BANDAR RUSTBORO sedang\n"
	.string "diluaskan, ayah saya tolong sekali.\p"
	.string "Dia suruh POKéMON dia guna POTONG\n"
	.string "untuk tebang pokok dan bersihkan\l"
	.string "tanah.$"

