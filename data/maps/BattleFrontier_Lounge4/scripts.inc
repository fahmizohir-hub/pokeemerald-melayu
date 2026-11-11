BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Agaknya hari ni ada tak siaran temu\n"
	.string "bual dengan JURULATIH yang hebat?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Kalau saya buka restoran\n"
	.string "di sini, mesti untung punya.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Fuh…\p"
	.string "Saya perlu tarik nafas dulu selepas\n"
	.string "beberapa pertarungan sengit…\p"
	.string "Tapi masa rehat pun, otak saya tak\n"
	.string "berhenti fikir strategi dan kombo.$"

