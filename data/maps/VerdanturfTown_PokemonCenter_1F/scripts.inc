VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Kamu bukan JURULATIH sebenar kalau\n"
	.string "tak percaya pada POKéMON kamu.\p"
	.string "Hanya orang yang percaya pada POKéMON\n"
	.string "yang bertarung untuknya boleh menang\l"
	.string "sampai ke penghujung.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "Sebab orang datang ke VERDANTURF…\p"
	.string "Sudah tentu KHEMAH BATTLE.\p"
	.string "Atau ada seseorang di sini yang kamu\n"
	.string "datang nak jumpa?$"

