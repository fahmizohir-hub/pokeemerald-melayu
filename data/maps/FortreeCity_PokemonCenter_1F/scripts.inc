FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Dengar sini, nak, kamu sedang isi\n"
	.string "POKéDEX?\p"
	.string "Hmm… Pergilah ke ZON SAFARI.\n"
	.string "Itu cadangan saya.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Kamu pernah cuba apa-apa di\n"
	.string "SUDUT REKOD?\p"
	.string "Memang menarik. Ia campur dan padankan\n"
	.string "rekod para JURULATIH.\p"
	.string "Saya tak tahu sangat cara ia berfungsi,\n"
	.string "tapi memang hebat. Mengujakan, pula!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, wah, kamu ada POKéNAV!\n"
	.string "Sama macam saya punya!\p"
	.string "Kamu tahu tentang sistem MATCH CALL\n"
	.string "dalam POKéNAV?\p"
	.string "Buka sistem tu, dan kamu boleh bual\n"
	.string "dengan JURULATIH berdaftar bila-bila.\p"
	.string "Ia juga tunjuk JURULATIH mana yang\n"
	.string "nak bertarung semula dengan kamu.\p"
	.string "Memang canggih! Orang DEVON tu\n"
	.string "memang pakar!$"

