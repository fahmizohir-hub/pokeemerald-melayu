AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Apa yang kelakar sangat kalau saya\n"
	.string "bawa tiub renang naik kapal ni?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Wah, saya tewas teruk!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Bukan senang nak baling POKé BALL\n"
	.string "sambil berpaut pada tiub renang!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Seronok, kan tempat ni? Duduk\n"
	.string "sini pun saya dah teruja!$"
