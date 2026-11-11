VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Bila fikir saya makin hampir dengan LIGA\n"
	.string "POKéMON…\p"
	.string "Saya jadi gemuruh…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Saya tak dapat buat apa-apa…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "LIGA POKéMON jadi jauh semula…\n"
	.string "Hampanya…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Untuk menang di LIGA POKéMON, kamu\n"
	.string "perlukan kepercayaan POKéMON kamu.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Hubungan kamu dibina atas kepercayaan\n"
	.string "yang kukuh.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Bila sentiasa bersama,\n"
	.string "kepercayaan akan tumbuh\l"
	.string "antara POKéMON dan JURULATIH.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Ini bukan garisan penamat.\n"
	.string "Ini cuma persinggahan dalam\l"
	.string "perjalanan ke LIGA POKéMON.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "Macam tulah!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Kamu pasti boleh!\n"
	.string "POKéMON kamu semua tak sabar nak maju!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "POKéMON saya sungguh mengagumkan\n"
	.string "sampai ke angkasa!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Tak pernah saya jumpa orang macam\n"
	.string "kamu.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Walaupun di luar pertarungan, saya\n"
	.string "rasa kuasa luar biasa terpancar dari\l"
	.string "kamu dan POKéMON kamu.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Okey, tak perlu tegang!\n"
	.string "Relaks, kita santai saja!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Wah!\n"
	.string "Hebat!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Memang, ini JALAN KEMENANGAN.\p"
	.string "Tapi tak banyak beza dengan\n"
	.string "jalan yang kamu lalui selama ini.\p"
	.string "Cubalah berseronok sepanjang\n"
	.string "perjalanan yang tinggal!$"

