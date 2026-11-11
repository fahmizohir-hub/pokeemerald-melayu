Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "Saya ada dengar tentang sebuah gua\n"
	.string "bernama GUA ORIGIN.\p"
	.string "Orang kata roh POKéMON dihidupkan\n"
	.string "semula di sana. Betul ke benda\l"
	.string "macam tu boleh jadi?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

