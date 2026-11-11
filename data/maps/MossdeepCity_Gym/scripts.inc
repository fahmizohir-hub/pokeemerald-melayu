MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Yo, apa khabar, bakal JUARA {PLAYER}?\p"
	.string "KETUA GIM di sini guna\n"
	.string "POKéMON jenis PSIKIK.\p"
	.string "Kalau kamu lawan mereka dengan\n"
	.string "POKéMON jenis LAWAN atau RACUN, mereka\l"
	.string "akan beri kerosakan yang dahsyat!\p"
	.string "Lagi satu, mereka akan serang kamu\n"
	.string "dengan serangan gabungan yang hebat.\p"
	.string "Kalau nak menang, kamu kena\n"
	.string "tunjuk betapa rapatnya kamu\l"
	.string "dengan POKéMON kamu. Teruskan!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Wah, kamu memang menakjubkan!\n"
	.string "Kamu JURULATIH yang hebat!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Pertarungan bergantung pada kekuatan\n"
	.string "semangat! Yang lemah semangat takkan\l"
	.string "menang!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "Saya kalah!\n"
	.string "Saya mesti tempa semangat saya lagi!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Orang yang teragak-agak akan\n"
	.string "kalah. Itu amaran saya kepada kamu.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Tunjukkan bakat kamu!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Kamu ada bakat yang luar biasa!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Kalau ada insan genius di dunia ni,\n"
	.string "KETUA GIM kamilah orangnya!\p"
	.string "Tapi, mungkin kamu lebih berbakat\n"
	.string "daripada mereka…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu… Tengok saya apungkan\n"
	.string "POKé BALL dengan telekinesis!\p"
	.string "Hiaaaaaaarghhh! … … … … … … …\p"
	.string "Kadang-kadang, saya hilang rentak…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Kemahiran bertarung POKéMON\n"
	.string "saya pun hilang rentak!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "POKé BALL terlalu berat nak diangkat\n"
	.string "dengan kuasa minda. Tapi gumpalan\l"
	.string "habuk ni…\p"
	.string "Fuuuuuuuuuuuuuuh!\n"
	.string "… … … … … …\p"
	.string "Tak, saya tak menipu!\n"
	.string "Saya tak tiup pun! Sumpah!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Bila kamu kalah dengan saya, jangan\n"
	.string "salahkan diri sangat.\p"
	.string "Bukan kamu yang lemah, saya yang\n"
	.string "terlalu kuat!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Kamu memang terlalu kuat!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Saya takkan bersedih sebab kalah. Saya\n"
	.string "cuma perlu berlatih lebih keras.\p"
	.string "Berfikiran positif, itulah kelebihan\n"
	.string "saya!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Saya nampak…\n"
	.string "Saya nampak masa depan kamu…\p"
	.string "Kalau kamu boleh kalahkan saya, saya\n"
	.string "akan beritahu masa depan kamu!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Saya menyerah!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Kamu akan bertarung dengan sengit\n"
	.string "sekali menentang KETUA GIM kami…\p"
	.string "Keputusannya…\n"
	.string "Kamu takkan dengar daripada saya!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Jalan yang kamu lalui…\n"
	.string "Pengalaman yang kamu tempuhi…\p"
	.string "Serang saya dengan segala yang kamu\n"
	.string "pelajari!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Kamu telah menempuh jalan kehebatan!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Masa depan cerah menanti mereka yang\n"
	.string "tekun berusaha.\p"
	.string "Bagi yang malas, hanya kecewa menanti\n"
	.string "di penghujungnya.\p"
	.string "Apa yang kita tanam, itulah yang kita\n"
	.string "tuai…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Walaupun bergadai nyawa, saya akan\n"
	.string "menang pertarungan ni!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Apa yang kamu buat…\n"
	.string "Menakutkan saya…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Berani kamu kalahkan saya…\p"
	.string "Bukan salah saya kalau ada benda\n"
	.string "dahsyat menimpa kamu…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hohoho.\p"
	.string "Biar saya tunjuk betapa gigihnya jenis\n"
	.string "PSIKIK.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Oh! Ya ampun!\n"
	.string "Gaya bertarung kamu hebat!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "S-saya tak biar kekalahan buat saya\n"
	.string "g-goyah, walau seteruk m-mana pun.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Biar saya buat kamu rasa\n"
	.string "ngeri yang amat sangat!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "T-tidaaaak!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Semangat kamu berjangkit!\n"
	.string "Cepat, jauhkan diri dari saya!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Saya mungkin dah lepas zaman\n"
	.string "kegemilangan, tapi jangan pandang\l"
	.string "rendah pada saya.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Ah, kamu melimpah dengan kuasa orang\n"
	.string "muda!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Nampaknya saya tak mampu atasi tenaga\n"
	.string "muda kamu.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Kamu takkan sampai ke hujung!\n"
	.string "Selagi saya ada di sini!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Macam mana kamu boleh kuat melampau\n"
	.string "macam ni?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Huh! Kamu mungkin kuat, tapi kamu tak\n"
	.string "sesuai dengan jenis PSIKIK!\p"
	.string "Cara kamu bertarung agak ganas!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Hiaaargh! Rasakan kuasa tarung super\n"
	.string "POKéMON saya!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Oh!\n"
	.string "Tewas!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Baiklah! Lepas ni saya nak cipta kuasa\n"
	.string "POKéMON istimewa yang tak dapat\l"
	.string "dikalahkan.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "TATE: Hehehe… Kamu terkejut?\p"
	.string "LIZA: Fufufu… Kamu terkejut?\p"
	.string "TATE: Sebab ada dua KETUA GIM?\n"
	.string "LIZA: Sebab ada dua KETUA GIM?\p"
	.string "TATE: Kami kembar!\n"
	.string "LIZA: Kami kembar!\p"
	.string "TATE: Kami tak perlu bercakap sebab…\n"
	.string "LIZA: Kami masing-masing tahu apa…\p"
	.string "TATE: Yang seorang lagi fikirkan…\n"
	.string "LIZA: Semuanya dalam minda kami!\p"
	.string "TATE: Gabungan kami ni…\n"
	.string "LIZA: Boleh kamu kalahkan?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "TATE: Apa?! Gabungan\n"
	.string "kami… LIZA: Dah hancur!\p"
	.string "TATE: Apa boleh buat. Kamu\n"
	.string "menang… LIZA: Jadi, sebagai\l"
	.string "pengiktirafan, ambil ni.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} menerima LENCANA MINDA\n"
	.string "daripada TATE dan LIZA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "TATE: LENCANA MINDA meningkatkan\n"
	.string "SERANGAN KHAS dan PERTAHANAN KHAS\l"
	.string "POKéMON.\p"
	.string "LIZA: Ia juga membolehkan kamu guna\n"
	.string "move HM SELAM di luar pertarungan.\p"
	.string "TATE: Kamu patut ambil ni juga.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "TATE: TM04 tu mengandungi…\n"
	.string "LIZA: MINDA TENANG!\p"
	.string "TATE: Ia naikkan SERANGAN KHAS dan…\n"
	.string "LIZA: Ia naikkan PERTAHANAN KHAS!\p"
	.string "TATE: Move ni memang sesuai…\n"
	.string "LIZA: Untuk POKéMON PSIKIK!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "KETUA GIM TATE & LIZA didaftarkan\n"
	.string "dalam POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "TATE: Nampaknya ikatan antara kamu dan\n"
	.string "POKéMON kamu jauh lebih kuat daripada\l"
	.string "ikatan kami sebagai kembar.\p"
	.string "LIZA: Kamu akan jadi lebih kuat lagi!\n"
	.string "Kami dah bertarung dengan kamu, jadi\l"
	.string "kami tahu.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "TATE: Hehehe… Kamu terkejut?\p"
	.string "LIZA: Sebab ada dua KETUA GIM?\p"
	.string "TATE: Alamak, kamu cuma ada satu…\n"
	.string "LIZA: POKéMON yang boleh bertarung.\p"
	.string "TATE: Kami tak boleh bertarung begitu!\p"
	.string "LIZA: Kalau nak cabar kami, bawa lebih\n"
	.string "banyak POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "GIM POKéMON BANDAR MOSSDEEP$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "GIM POKéMON BANDAR MOSSDEEP\p"
	.string "JURULATIH DIIKTIRAF LIZA DAN TATE:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "TATE: POKéMON…\n"
	.string "LIZA: POKéMON…\p"
	.string "TATE: Bila gabungan pasukan ditukar…\n"
	.string "LIZA: Gaya bertarung pun berubah.\p"
	.string "TATE: Tapi saya…\n"
	.string "LIZA: Tapi saya…\p"
	.string "TATE: Sentiasa bersama LIZA!\n"
	.string "LIZA: Sentiasa bersama TATE!\p"
	.string "TATE: Gabungan kami…\n"
	.string "LIZA: Kami akan tunjuk lagi dan lagi!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "TATE: Kamu dan POKéMON kamu…\n"
	.string "LIZA: Macam adik-beradik!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "TATE: Kamu boleh tumbangkan kami,\n"
	.string "tapi kami akan bangkit semula!\p"
	.string "LIZA: Sebab kami berdua\n"
	.string "sentiasa saling menyokong!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "TATE: Kamu datang lagi…\n"
	.string "LIZA: Kamu datang lagi…\p"
	.string "TATE: Untuk perlawanan semula.\n"
	.string "LIZA: Untuk perlawanan semula.\p"
	.string "TATE: Tapi…\n"
	.string "LIZA: Untuk perlawanan kami…\p"
	.string "TATE: Kamu bawa satu POKéMON saja!\n"
	.string "LIZA: Kamu bawa satu POKéMON saja!\p"
	.string "TATE: Lain kali, bawalah sekurangnya…\n"
	.string "LIZA: Dua POKéMON bila datang semula.$"
