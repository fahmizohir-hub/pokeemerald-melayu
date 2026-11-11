SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Nak petua bertarung?\p"
	.string "Bagi saya, latih pelbagai jenis POKéMON\n"
	.string "secara seimbang.\p"
	.string "Tak bagus kalau kuatkan satu POKéMON\n"
	.string "saja.\p"
	.string "Kalau jenisnya tak menguntungkan,\n"
	.string "mungkin ia langsung tiada peluang.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Saya tukar POKéMON dengan\n"
	.string "kawan-kawan.\p"
	.string "Kalau POKéMON yang ditukar pegang\n"
	.string "barang, saya jadi dua kali ganda\l"
	.string "gembira!$"

