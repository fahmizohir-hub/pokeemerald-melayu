MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	playse SE_PIN
	applywaitmovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	return

MtChimney_EventScript_ArchieExitEast::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	return

MtChimney_EventScript_ArchieExitNorth::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "Kuasa yang terkandung dalam METEORIT…\p"
	.string "Dengan menguatkan kuasanya guna mesin\n"
	.string "ni, aktiviti gunung berapi GUNUNG\l"
	.string "CHIMNEY akan terus memuncak…\p"
	.string "Tenaganya akan bertambah jauh di\n"
	.string "dalam kawah dan…\l"
	.string "Fufufu…$"

MtChimney_Text_MaxieIntro:
	.string "MAXIE: Hm?\n"
	.string "Siapa kau?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Aku dengar ARCHIE merungut tentang\n"
	.string "budak yang suka masuk campur urusan\l"
	.string "TEAM AQUA.\p"
	.string "Mesti kaulah yang dia maksudkan.\p"
	.string "Hmph! Jadi kau nak masuk campur\n"
	.string "urusan kami, TEAM MAGMA?\p"
	.string "Dengar sini.\n"
	.string "Dahulu kala, makhluk hidup guna\l"
	.string "daratan untuk hidup dan membesar.\p"
	.string "Sebab itulah daratan sangat penting!\n"
	.string "Ia buaian segala kehidupan!\p"
	.string "Sebab itulah TEAM MAGMA berjuang\n"
	.string "untuk meluaskan daratan.\p"
	.string "Semuanya demi kemajuan manusia dan\n"
	.string "POKéMON!\p"
	.string "Dan untuk itu, kami perlukan kuasa\n"
	.string "yang tidur dalam gunung ni…\p"
	.string "Oh! Kau tak perlu tahu sebanyak\n"
	.string "tu pun.\p"
	.string "Tapi, tak apa!\n"
	.string "Aku akan ajar kau akibatnya masuk\l"
	.string "campur dalam rancangan besar kami!$"

MtChimney_Text_MaxieDefeat:
	.string "Apa?!\p"
	.string "Aku, MAXIE, terleka?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAXIE: Tapi, cukuplah.\n"
	.string "Aku berundur kali ni.\p"
	.string "Tapi jangan ingat ini kali terakhir\n"
	.string "kau jumpa TEAM MAGMA.\p"
	.string "Fufufu…\p"
	.string "Walaupun tanpa METEORIT, kalau kami\n"
	.string "dapat MESTIKA tu… Fufufu…$"

MtChimney_Text_TabithaIntro:
	.string "Hehehe!\p"
	.string "Jadi kau datang jauh-jauh ke sini!\p"
	.string "Tapi kau dah terlambat!\n"
	.string "Aku dah serahkan METEORIT dari\l"
	.string "LATA METEOR kepada BOS!$"

MtChimney_Text_TabithaDefeat:
	.string "Hehehe…\p"
	.string "Walaupun aku kalah, kalau ketua\n"
	.string "kami bangunkan benda tu…$"

MtChimney_Text_TabithaPostBattle:
	.string "BOS, cepat!\n"
	.string "Beri ia tenaga METEORIT!\p"
	.string "Hehehe…$"

MtChimney_Text_Grunt2Intro:
	.string "Kami TEAM MAGMA bekerja keras demi\n"
	.string "semua orang.\p"
	.string "Macam ni, kalau kuasa benda tu buat\n"
	.string "lebih banyak daratan, lebih banyaklah\l"
	.string "tempat untuk tinggal.\p"
	.string "Semua orang akan gembira!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hah?\n"
	.string "Apa maksud kau aku kalah?$"

MtChimney_Text_Grunt2PostBattle:
	.string "BOS kami kata, “Ia akan buat semua\n"
	.string "orang gembira.”\p"
	.string "Tapi kenapa semua orang asyik\n"
	.string "halang kami?$"

MtChimney_Text_Grunt1Intro:
	.string "Kalau ada lebih banyak daratan, aku\n"
	.string "boleh ada rumah besar sendiri!\p"
	.string "Aku nak bina atas lava yang dah keras!$"

MtChimney_Text_Grunt1Defeat:
	.string "Impian rumah besar aku…$"

MtChimney_Text_Grunt1PostBattle:
	.string "Budak macam kau ni, patutnya main\n"
	.string "air di tepi pantai saja!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "TEAM AQUA yang menjengkelkan tu…\n"
	.string "Asyik kacau rancangan kami!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "METEORIT ada kuasa yang hebat!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Jangan cuba main-main dengan kami!\p"
	.string "Kami nak bangunkan benda tu demi\n"
	.string "kebaikan semua orang!$"

MtChimney_Text_AquasNameSimilar:
	.string "Kami TEAM MAGMA!\p"
	.string "Mereka TEAM AQUA!\p"
	.string "Geram betul aku mereka guna nama\n"
	.string "yang macam nama kami!$"

MtChimney_Text_DouseThemInFire:
	.string "Yeah!\n"
	.string "Bakar mereka dengan api!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Kami akan terus cipta lebih daratan!$"

MtChimney_Text_Bufoh:
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARCHIE: Grr, {PLAYER}!\n"
	.string "Patut aku dah agak kau akan muncul!\p"
	.string "Tengok sendiri apa yang si fanatik\n"
	.string "TEAM MAGMA sedang buat!\p"
	.string "Mereka cuba suntik kuasa METEORIT\n"
	.string "yang dicuri ke dalam gunung berapi!\p"
	.string "Kalau buat begitu, gunung berapi\n"
	.string "ni akan meletus!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIE: Grrr…\p"
	.string "Aku nak halang MAXIE tu,\n"
	.string "tapi aku tak boleh!\p"
	.string "Aku tengah sibuk bertarung dengan\n"
	.string "tiga lawan serentak!$"

MtChimney_Text_ArchieThankYou:
	.string "ARCHIE: {PLAYER}!\n"
	.string "Terima kasih!\p"
	.string "Dengan bantuan kau, kita gagalkan\n"
	.string "rancangan jahat TEAM MAGMA!\p"
	.string "Tapi… Kau…\n"
	.string "Kau sebenarnya di pihak siapa?\p"
	.string "Ah, tak penting.\p"
	.string "Kami akan terus berwaspada dan\n"
	.string "terus memburu TEAM MAGMA.\p"
	.string "{PLAYER}, kita akan berjumpa lagi!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Cis… TEAM MAGMA lebih ramai!\n"
	.string "Kami tak dapat tandingi mereka!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Kalau mereka luaskan daratan, habitat\n"
	.string "POKéMON AIR akan berkurangan!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Kami TEAM AQUA!\p"
	.string "Mereka TEAM MAGMA!\p"
	.string "Panas hati aku mereka guna nama\n"
	.string "yang mengelirukan macam tu!$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "BISKUT LAVA ialah makanan istimewa\n"
	.string "GUNUNG CHIMNEY.\p"
	.string "Cubalah satu. Cuma ¥200.$"

MtChimney_Text_ThankYouDear:
	.string "Terima kasih, sayang!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Alahai. Tak boleh beli apa-apa kalau\n"
	.string "tak ada duit.$"

MtChimney_Text_OhFineThen:
	.string "Oh, tak apalah.$"

MtChimney_Text_MeteoriteFittedOnMachine:
	.string "Sebiji METEORIT dipasang pada mesin\n"
	.string "yang misteri…\p"
	.string "Mesin ni seolah-olah sedang menyimpan\n"
	.string "tenaga dalam METEORIT itu.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Sebiji METEORIT dipasang pada mesin\n"
	.string "yang misteri…\p"
	.string "Mahu tanggalkan METEORIT itu?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} menanggalkan METEORIT dari\n"
	.string "mesin misteri itu.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} membiarkan METEORIT itu\n"
	.string "di tempatnya.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Mesin misteri ni…\n"
	.string "Langsung tak memberi tindak balas.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} DENAI BERGERIGI\n"
	.string "PEKAN LAVARIDGE DI HADAPAN$"

MtChimney_Text_ShelbyIntro:
	.string "Saya baru dari kolam air panas dan\n"
	.string "tulang saya yang penat dah segar.\l"
	.string "Sekarang saya rasa kuat!$"

MtChimney_Text_ShelbyDefeat:
	.string "Ya ampun.\n"
	.string "Hebat betul kamu ni!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Wah, wah, saya kalah. Tak bolehlah\n"
	.string "saya gelar diri PAKAR lagi, kan?$"

MtChimney_Text_ShelbyRegister:
	.string "Terima kasih, nak. Seronok, macam\n"
	.string "bertarung dengan cucu sendiri.\p"
	.string "Datanglah jumpa nenek lagi untuk\n"
	.string "perlawanan semula.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Kalau kamu dapat satukan hati kamu\n"
	.string "dengan hati POKéMON kamu, kamu pasti\l"
	.string "boleh capai perkara yang hebat.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Ya ampun.\n"
	.string "Hebat betul kamu ni!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Mungkin hati kamu dah bersatu\n"
	.string "dengan hati POKéMON kamu.$"

MtChimney_Text_MelissaIntro:
	.string "Ada api dalam diri saya, sayang.\n"
	.string "Tak tahan dah! Saya mesti bertarung!$"

MtChimney_Text_MelissaDefeat:
	.string "Ooh, perlawanan tu memang panas!$"

MtChimney_Text_MelissaPostBattle:
	.string "Bahang GUNUNG CHIMNEY buat saya\n"
	.string "rasa hangat, sayang!$"

MtChimney_Text_SheilaIntro:
	.string "Akhirnya saya tiba di GUNUNG CHIMNEY.\n"
	.string "Saya nak suruh POKéMON saya bertarung!$"

MtChimney_Text_SheilaDefeat:
	.string "Cara kamu bertarung…\n"
	.string "Macam GUNUNG CHIMNEY meletus!$"

MtChimney_Text_SheilaPostBattle:
	.string "Macam saya cakap, akhirnya saya sampai\n"
	.string "ke GUNUNG CHIMNEY. Rugilah kalau\l"
	.string "saya cuma bersiar-siar sikit…\p"
	.string "Saya nak bertarung dan beli BISKUT\n"
	.string "sebagai cenderamata.$"

MtChimney_Text_ShirleyIntro:
	.string "Sejak mandi di kolam air panas,\n"
	.string "saya rasa sangat segar!\l"
	.string "Saya pasti akan menang!$"

MtChimney_Text_ShirleyDefeat:
	.string "Aduh!\n"
	.string "Saya kesejukan lepas keluar dari air.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Saya kena berendam lagi dalam kolam\n"
	.string "air panas. Nak ikut sekali?\p"
	.string "Gurau saja!$"

MtChimney_Text_SawyerIntro:
	.string "Gunung ni memang hebat! Ramai orang\n"
	.string "yang bersemangat panas jadi teman!$"

MtChimney_Text_SawyerDefeat:
	.string "Oh, kamu pun memang berapi-api!$"

MtChimney_Text_SawyerPostBattle:
	.string "Rasanya saya perlu berendam di KOLAM\n"
	.string "AIR PANAS LAVARIDGE dengan orang sini!$"

MtChimney_Text_SawyerRegister:
	.string "Saya suka bola api kecil macam kamu.\n"
	.string "Biar saya daftar kamu dalam POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Saya gembira dikelilingi orang yang\n"
	.string "bersemangat di sini. Saya takkan kalah!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Aduhai, kamu masih berapi-api\n"
	.string "macam dulu!$"

MtChimney_Text_SawyerPostRematch:
	.string "Sebenarnya, memang panas di sini.\n"
	.string "Saya pakai baju terlalu tebal.$"

