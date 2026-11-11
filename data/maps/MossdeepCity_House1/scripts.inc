MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Hmm!\n"
	.string "{STR_VAR_1} kamu…$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "Ia suka {STR_VAR_1},\n"
	.string "kan?\p"
	.string "Tak, saya pasti! Memang ia suka\n"
	.string "{STR_VAR_1}!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Ia nampaknya tak suka dan tak benci\n"
	.string "mana-mana {POKEBLOCK}.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Suami saya boleh tahu jenis {POKEBLOCK} yang\n"
	.string "POKéMON suka sekali pandang saja.$"

