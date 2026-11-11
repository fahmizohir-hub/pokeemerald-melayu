FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applywaitmovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_WingullExit
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "Bila bersama POKéMON, manusia\n"
	.string "dapat lebih ramai kawan.\p"
	.string "Dan itu buat dunia jadi lebih rapat.\n"
	.string "Saya rasa itu sangat indah!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "Nah!\n"
	.string "Pergi, POKéMON BURUNG!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Hehe, saya suruh WINGULL saya\n"
	.string "buat satu kerja untuk saya.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "Bagus!\n"
	.string "Selamat kembali, WINGULL!\p"
	.string "Eh? Apa ni?\n"
	.string "Apa yang ia pegang?\p"
	.string "HERBA MENTAL?\n"
	.string "Mesti ia kutip di mana-mana.\p"
	.string "Tapi saya bukan JURULATIH, jadi\n"
	.string "kamu ambillah.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Berkat WINGULL saya, saya ada\n"
	.string "kawan-kawan yang tinggal jauh.$"

FortreeCity_House4_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

