PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Sistem Simpanan POKéMON berasaskan\n"
	.string "PC tu…\p"
	.string "Siapa pun yang cipta, mesti\n"
	.string "genius sains!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Bila POKéMON saya makan\n"
	.string "BERI ORAN, HPnya pulih!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Ada banyak jenis POKéMON.\p"
	.string "Setiap jenis ada kekuatan dan\n"
	.string "kelemahan terhadap jenis lain.\p"
	.string "Bergantung pada jenis POKéMON,\n"
	.string "pertarungan boleh jadi mudah atau\l"
	.string "susah.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Contohnya, TREECKO kamu jenis RUMPUT.\p"
	.string "Ia kuat terhadap jenis AIR dan TANAH.\p"
	.string "Tapi, ia lemah terhadap\n"
	.string "POKéMON jenis API.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Contohnya, TORCHIC kamu jenis API.\p"
	.string "Ia kuat terhadap jenis\n"
	.string "RUMPUT dan SERANGGA.\p"
	.string "Tapi, ia lemah terhadap\n"
	.string "POKéMON jenis AIR.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Contohnya, MUDKIP kamu jenis AIR.\p"
	.string "Ia kuat terhadap jenis API.\p"
	.string "Tapi, ia lemah terhadap POKéMON\n"
	.string "jenis RUMPUT dan ELEKTRIK.$"

