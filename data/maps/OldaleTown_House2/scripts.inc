OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Bila POKéMON bertarung, lama-kelamaan\n"
	.string "tahapnya naik dan ia jadi lebih kuat.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Kalau POKéMON kamu jadi lebih kuat,\n"
	.string "kamu boleh pergi lebih jauh dari sini.$"

