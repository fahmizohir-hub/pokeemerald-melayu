RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "POKéMON saya bersifat NAIF, dan\n"
	.string "POKéMON kawan saya bersifat CERIA.\p"
	.string "Menarik betul, POKéMON pun ada perangai\n"
	.string "masing-masing!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Macam manusia juga, ada POKéMON jantan\n"
	.string "dan betina.\p"
	.string "Tapi tak ada siapa yang tahu apa\n"
	.string "bezanya.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "Pak cik sebelah rumah bagi saya HM!\p"
	.string "Saya guna untuk ajar POKéMON saya\n"
	.string "POTONG. Boleh tebang pokok kecil!$"

