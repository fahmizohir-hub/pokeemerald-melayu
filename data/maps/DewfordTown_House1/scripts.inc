DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Banyak kebaikannya tinggal di pulau\n"
	.string "kecil macam ni, aman bersama POKéMON\l"
	.string "dan keluarga.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Saya tinggalkan pelabuhan besar\n"
	.string "BANDAR SLATEPORT bila berkahwin\l"
	.string "dengan suami saya di sini.\p"
	.string "Hidup di pulau kecil ni tenang dan\n"
	.string "perlahan. Tapi dikelilingi laut yang\l"
	.string "cantik… itu pun bahagia juga.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"

