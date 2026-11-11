FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applywaitmovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Tak ada siapa percaya, tapi saya\n"
	.string "nampak POKéMON gergasi di langit.\p"
	.string "Ia macam menggeliat sambil terbang\n"
	.string "ke arah LALUAN 131.\p"
	.string "Oh ya… Sniff…\n"
	.string "Err… Kamu, err… bau macam hangus.\p"
	.string "Kamu baru balik dari gunung berapi ke?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Saya nak pergi ke GIM POKéMON,\n"
	.string "tapi ada sesuatu yang menghalang.\p"
	.string "Penat-penat saya berlatih di\n"
	.string "LALUAN 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Saya bawa POKéMON kebanggaan saya.\n"
	.string "Kali ni, saya akan kalahkan WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Tanah menyerap air hujan, dan pokok\n"
	.string "membesar dengan meminum air itu…\p"
	.string "BANDAR FORTREE wujud kerana ada\n"
	.string "air dan tanah.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "BANDAR ni terdiri daripada rumah yang\n"
	.string "dibina di atas pokok.\p"
	.string "Mungkin sebab cara hidup begitu,\n"
	.string "semua orang sihat dan cergas.\p"
	.string "Saya sendiri pun--rasa macam dah\n"
	.string "muda tiga puluh tahun.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Tinggal di atas pokok memang okey.\p"
	.string "Tapi kadang-kadang POKéMON SERANGGA\n"
	.string "masuk ikut tingkap.\l"
	.string "Memang mengejutkan.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Ada POKéMON yang berevolusi bila\n"
	.string "ditukar! Itu yang saya dengar.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Ada sesuatu yang halimunan menghalang.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Ada sesuatu yang halimunan menghalang.\p"
	.string "Nak guna SKOP DEVON?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} menggunakan SKOP DEVON.\p"
	.string "POKéMON yang halimunan kini kelihatan\n"
	.string "sepenuhnya!\p"
	.string "POKéMON yang terkejut itu lari!$"

FortreeCity_Text_CitySign:
	.string "BANDAR FORTREE\n"
	.string "“Bandar puncak pokok yang bermain\l"
	.string "riang bersama alam.”$"

FortreeCity_Text_GymSign:
	.string "GIM POKéMON BANDAR FORTREE\n"
	.string "KETUA: WINONA\p"
	.string "“Pengguna burung yang terbang\n"
	.string "menjelajah dunia.”$"

