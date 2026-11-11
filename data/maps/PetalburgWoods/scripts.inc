PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm… Seekor pun tak jumpa…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Helo, kamu ada nampak POKéMON nama\n"
	.string "SHROOMISH dekat-dekat sini?\p"
	.string "Saya suka sangat POKéMON tu.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Aku nak serang hendap kau, tapi kau\n"
	.string "terhegeh-hegeh dalam HUTAN PETALBURG\l"
	.string "ni lama sangat, kan?\p"
	.string "Aku dah muak menunggu,\n"
	.string "jadi aku datanglah!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Kau! PENYELIDIK DEVON!\p"
	.string "Serahkan dokumen tu!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aiyaaa!\p"
	.string "Kamu JURULATIH POKéMON,\n"
	.string "kan? Tolonglah saya!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hah? Kau ingat kau buat apa ni? Nak\n"
	.string "lindungi dia pula?\p"
	.string "Sesiapa yang cari pasal dengan TEAM\n"
	.string "AQUA takkan dikasihani, budak pun sama!\p"
	.string "Mari lawan aku!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Biar betul! Kuat juga kau!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Berani kau masuk campur urusan\n"
	.string "TEAM AQUA! Mari lawan aku lagi!\p"
	.string "Itulah yang aku nak cakap,\n"
	.string "tapi POKéMON aku dah habis…\p"
	.string "Lagipun, kami TEAM AQUA pun\n"
	.string "sedang buru sesuatu di RUSTBORO.\p"
	.string "Hari ni aku lepaskan kau!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Fuh… Nyaris betul tadi!\p"
	.string "Berkat kamu, dia tak dapat rampas\n"
	.string "dokumen penting ni daripada saya.\p"
	.string "Ha, saya bagi kamu GREAT BALL\n"
	.string "sebagai tanda terima kasih!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Samseng TEAM AQUA tu kata mereka pun\n"
	.string "sedang buru sesuatu di RUSTBORO, kan?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Alamak! Gawat ni! Saya tak boleh\n"
	.string "buang masa!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Barang kamu dah penuh. Saya\n"
	.string "tak dapat bagi GREAT BALL ni.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Saya dah tangkap banyak POKéMON!\p"
	.string "Ayuh, ayuh, ayuh! Pasukan\n"
	.string "POKéMON SERANGGA saya!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Saya ada banyak POKéMON,\n"
	.string "tapi saya tetap tak menang…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Saya dah tangkap banyak POKéMON.\n"
	.string "Sekarang POKé BALL saya dah habis.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Kalau bawa POKéMON SERANGGA\n"
	.string "ke sekolah, terus jadi popular!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Mana boleh popular kalau kalah.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Kalau ada POKéMON SERANGGA yang\n"
	.string "besar, orang akan hormat kamu.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Saya nak lawan semula bila\n"
	.string "POKéMON SERANGGA saya dah besar!\p"
	.string "Saya daftarkan kamu\n"
	.string "dalam POKéNAV saya!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Saya nak lawan semula bila\n"
	.string "POKéMON SERANGGA saya dah besar!\p"
	.string "Saya daftarkan kamu\n"
	.string "dalam POKéNAV saya!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "POKéMON SERANGGA saya dah\n"
	.string "besar. Saya akan popular lagi.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Mana boleh popular kalau kalah.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Kalau ada POKéMON yang kuat, kita jadi\n"
	.string "popular, kan? Jadi, saya berlatih\l"
	.string "bersungguh-sungguh.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Hai, kamu! POKéMON kamu okey?\p"
	.string "Kalau POKéMON kamu lemah dan kamu nak\n"
	.string "elak pertarungan, jauhkan diri dari\l"
	.string "rumput tinggi.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Kadang-kadang, ada barang di atas\n"
	.string "tanah walaupun kamu tak nampak.\p"
	.string "Sebab tu saya selalu perhati tempat\n"
	.string "saya jalan.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Wah, hebat! Itu LENCANA GIM RUSTBORO!\p"
	.string "Mesti kamu JURULATIH.\n"
	.string "Cubalah guna barang ni.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "Itu BENIH AJAIB. Kalau POKéMON\n"
	.string "memegangnya, move jenis RUMPUTnya jadi\l"
	.string "lebih kuat.\p"
	.string "Selain BENIH AJAIB, saya rasa ada\n"
	.string "banyak lagi barang berguna untuk\l"
	.string "dipegang POKéMON.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "PETUA JURULATIH\p"
	.string "Mana-mana POKéMON yang muncul walau\n"
	.string "sekali dalam pertarungan akan diberi\l"
	.string "Mata EXP.\p"
	.string "Untuk melatih POKéMON yang lemah,\n"
	.string "letakkan ia di kiri senarai pasukan.\p"
	.string "Sebaik saja pertarungan bermula, tukar\n"
	.string "keluar. POKéMON tu tetap dapat Mata\l"
	.string "EXP tanpa terdedah kepada bahaya.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "PETUA JURULATIH\p"
	.string "Selain Mata Hayat (HP), POKéMON ada\n"
	.string "Mata Kuasa (PP) untuk guna move\l"
	.string "dalam pertarungan.\p"
	.string "Kalau PP POKéMON habis, bawa ia ke\n"
	.string "PUSAT POKéMON.$"

