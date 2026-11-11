SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Dengar sini, saya nak beritahu sesuatu\n"
	.string "yang menarik.\p"
	.string "Katanya ada runtuhan purba di dalam\n"
	.string "laut sekitar sini.\p"
	.string "Mungkin ada harta karun di bawah sana\n"
	.string "yang menunggu untuk ditemui.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Harta karun purba…\p"
	.string "Seronok kalau betul-betul wujud, tapi\n"
	.string "kalau tak pun, mesti indah dapat\l"
	.string "bersiar-siar di bawah air bersama\l"
	.string "POKéMON saya.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Marurii.$"

