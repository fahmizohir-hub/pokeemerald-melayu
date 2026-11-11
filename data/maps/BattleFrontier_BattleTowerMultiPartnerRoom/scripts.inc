BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applywaitmovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	applywaitmovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applywaitmovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applywaitmovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Sila cari rakan daripada\n"
	.string "JURULATIH yang berkumpul di sini.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, kamu belum jumpa rakan\n"
	.string "untuk pasukan berpasangan kamu.\p"
	.string "Kamu mahu berhenti mencari dan\n"
	.string "kembali ke kaunter penyambut tetamu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Kalau begitu, sila cari rakan daripada\n"
	.string "JURULATIH yang berkumpul di sini.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Terima kasih kerana memilih rakan.\p"
	.string "Sekarang saya akan bawa kamu\n"
	.string "ke BILIK TARUNG MULTI kamu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Saya anak murid no. {STR_VAR_2}\n"
	.string "{STR_VAR_1}. Panggil saya {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Atas nasihat {STR_VAR_1}, saya bawa\n"
	.string "satu {STR_VAR_3} dengan {STR_VAR_2}\l"
	.string "dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Tolonglah, benarkan saya\n"
	.string "sertai kamu sebagai pasangan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Terima kasih! Saya pergi\n"
	.string "daftar sekarang juga.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Saya betul-betul nak berpasangan\n"
	.string "dengan kamu, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Saya anak murid no. {STR_VAR_2}\n"
	.string "{STR_VAR_1}. Nama saya {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Saya dapat nasihat daripada\n"
	.string "{STR_VAR_1} dan pilih satu {STR_VAR_3}\l"
	.string "dengan {STR_VAR_2} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Jom kita jadi pasangan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Terima kasih banyak! Saya akan\n"
	.string "siapkan pendaftaran dengan cepat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, saya harap sangat\n"
	.string "dapat berpasangan dengan kamu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Err, nama saya {STR_VAR_3}, saya anak\n"
	.string "murid no. {STR_VAR_2} {STR_VAR_1}.\p"
	.string "Teresak…\p"
	.string "Maaf! Saya gementar\n"
	.string "sangat sampai menangis…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} nasihatkan saya, jadi saya\n"
	.string "ada satu {STR_VAR_2} dengan\l"
	.string "{STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Teresak… Tolonglah, tolonglah\n"
	.string "jadi pasangan saya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Oh, betul ke? Kamu sudi?\n"
	.string "Hebat! Mantap! Awoooh!\p"
	.string "Oh… Maaf… Saya gembira\n"
	.string "sangat sampai menangis…\p"
	.string "Saya pergi daftar sekarang.\n"
	.string "Jangan pergi mana-mana, ya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, t-tapi… Teresak… Waaaaah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Hai! Saya {STR_VAR_3}! Saya anak\n"
	.string "murid no. {STR_VAR_2} {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} yang cadangkan pasukan\n"
	.string "saya. Satu {STR_VAR_2} dengan\l"
	.string "{STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1},\n"
	.string "itulah yang saya ada! Hebat, kan?\p"
	.string "Jadi, ayuh! Jom jadi pasangan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Yeay! Bagus! Okey,\n"
	.string "saya pergi daftar, ya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Alah, kenapa? Saya nak\n"
	.string "berpasangan dengan kamu, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Saya {STR_VAR_3}, anak murid no.\n"
	.string "{STR_VAR_2} kepada {STR_VAR_1} yang\l"
	.string "terkenal!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Saya minta nasihat {STR_VAR_3}. Satu\n"
	.string "{STR_VAR_2} yang guna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "dan satu {STR_VAR_2} dengan\n"
	.string "{STR_VAR_1}, itulah pasangan saya.\p"
	.string "Sudikah kamu berpasangan dengan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Terima kasih! Saya\n"
	.string "pergi daftar sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, saya memang berharap\n"
	.string "dapat berpasangan dengan kamu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Err… Saya betul-betul gembira kamu sudi\n"
	.string "luangkan masa bercakap dengan saya.\p"
	.string "Saya {STR_VAR_3}. Saya anak murid\n"
	.string "no. {STR_VAR_2} {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} beri saya nasihat.\n"
	.string "Saya sangat berterima kasih.\p"
	.string "Pasukan saya ada satu {STR_VAR_2}\n"
	.string "dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\n"
	.string "Saya tahu saya minta banyak…\p"
	.string "Saya rasa kamu tak sudi, tapi\n"
	.string "boleh saya jadi pasangan kamu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Betul ke? Saya tak percaya! Saya tak\n"
	.string "percaya kamu benarkan saya sertai\l"
	.string "kamu! Sa… Saya takkan kecewakan kamu!\p"
	.string "Err… Kalau betul-betul boleh,\n"
	.string "saya pergi daftar sekarang juga!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh… Saya memang rasa\n"
	.string "saya tak cukup bagus…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Hai, saya {STR_VAR_3}. Saya anak\n"
	.string "murid no. {STR_VAR_2} {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} kata pasukan ni bagus:\n"
	.string "satu {STR_VAR_2} yang guna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "dan satu {STR_VAR_2} yang\n"
	.string "tahu guna {STR_VAR_1}.\p"
	.string "Boleh tahan, kan? Nak\n"
	.string "saya jadi pasangan kamu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Okey, seronok dapat sertai kamu! Harap\n"
	.string "kamu tak rosakkan apa-apa untuk saya!\l"
	.string "Saya pergi daftar sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Hah? Kenapa kamu tolak saya? Kamu\n"
	.string "memang tak pandai menilai orang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Saya {STR_VAR_3}, seorang TRIATLET.\n"
	.string "Saya sibuk setiap hari dengan\l"
	.string "berjoging, berlatih dan menyanyi rap.\p"
	.string "Saya juga kebetulan anak murid\n"
	.string "no. {STR_VAR_2} {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Inilah yang {STR_VAR_3} cadangkan.\n"
	.string "Satu {STR_VAR_2} yang guna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "dan satu {STR_VAR_2}\n"
	.string "yang guna {STR_VAR_1}.\p"
	.string "Saya bersusah payah membela\n"
	.string "mereka, walaupun saya sibuk.\p"
	.string "Jom jadi pasangan dan cuba!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Terima kasih, itulah semangatnya!\n"
	.string "Tunggu sekejap, saya pergi daftar,\l"
	.string "okey?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "Saya curi masa dari jadual sibuk saya\n"
	.string "untuk datang ke sini! Kesianlah sikit!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Hai! Apa khabar?\p"
	.string "Saya {STR_VAR_3}, anak murid no.\n"
	.string "{STR_VAR_2} {STR_VAR_1}. Gembira jumpa\l"
	.string "kamu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Dengar, dengar! Kamu mesti dengar\n"
	.string "tentang POKéMON yang {STR_VAR_3}\l"
	.string "cadangkan. Satu {STR_VAR_2} dengan\l"
	.string "{STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\n"
	.string "Tentulah saya bela mereka dengan\l"
	.string "cemerlang!\p"
	.string "Jadi, nak berpasangan? Saya\n"
	.string "pasti kita kombo yang hebat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Yeay, mesti seronok\n"
	.string "ni! Saya pergi daftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Ish, kamu ni jahat! Saya ni datang\n"
	.string "dengan cadangan, tahu tak.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Izinkan saya memperkenalkan\n"
	.string "diri. Saya {STR_VAR_3}.\p"
	.string "Saya berkhidmat sebagai anak\n"
	.string "murid no. {STR_VAR_2} {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "Saya dapatkan nasihat bijak\n"
	.string "{STR_VAR_3} dan bela pasukan saya, satu\l"
	.string "{STR_VAR_2} dengan {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "dan satu {STR_VAR_2}\n"
	.string "dengan {STR_VAR_1}.\p"
	.string "Sudilah berpasangan dengan saya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… Saya gembira sekali! Saya\n"
	.string "janji akan berikan yang terbaik!\p"
	.string "Tentu saya akan daftarkan\n"
	.string "kita! Tunggu sebentar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Saya memang berharap dapat\n"
	.string "sertai kamu, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Eeek! Kamu tegur saya!\n"
	.string "Sa… Saya gembira sangat!\p"
	.string "Saya {STR_VAR_3}! Saya anak murid\n"
	.string "no. {STR_VAR_2} {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Atas nasihat {STR_VAR_3}, saya latih\n"
	.string "satu {STR_VAR_2} yang guna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "dan satu {STR_VAR_2}\n"
	.string "yang guna {STR_VAR_1}.\p"
	.string "Tolonglah, tunaikan hajat saya?\n"
	.string "Saya nak jadi pasangan kamu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Eeek! Sa… Saya rasa pening! Terima\n"
	.string "kasih banyak! Saya pergi daftarkan\l"
	.string "kita sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah! Kamu tak kesian ke?\n"
	.string "Tapi itu buat kamu lagi hebat…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Yihaa! Saya anak murid no.\n"
	.string "{STR_VAR_2} {STR_VAR_1}!\p"
	.string "Nama saya {STR_VAR_3}, helo, helo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Guru saya {STR_VAR_3} cadangkan\n"
	.string "satu {STR_VAR_2} pakar {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "dan satu {STR_VAR_2} pakar {STR_VAR_1}.\p"
	.string "Mantap, kan? Kamu nak\n"
	.string "jadi pasangan saya, kan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Okey, bagus! Saya siapkan\n"
	.string "pendaftaran cepat-cepat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah! Kamu ni berkira betul, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Hei! Ada masalah besar! Hari ni\n"
	.string "hari terakhir BATTLE TOWER!\p"
	.string "… … … … … … Saya bergurau saja!\p"
	.string "Orang panggil saya {STR_VAR_3}, saya\n"
	.string "pun sama! Saya anak murid ke-1,000\l"
	.string "{STR_VAR_1}! Sebenarnya, saya no.\l"
	.string "{STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} beri saya nasihat.\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} dengan {STR_VAR_1}. Saya\n"
	.string "ada sepuluh ekor setiap satu!\l"
	.string "Sebenarnya, seekor saja setiap satu!\p"
	.string "Macam mana? Nak cuba tarung\n"
	.string "berpasangan dengan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Yeay! Saya beri kamu\n"
	.string "POKéMON tanda terima kasih!\p"
	.string "Gurau saja! Tapi saya\n"
	.string "betul-betul pergi daftar, okey?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Ish, dinginnya! Saya kena\n"
	.string "musnahkan BATTLE TOWER sebab tu!\p"
	.string "Tentulah tidak!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Hei, saya bergoyang dan berguling!\n"
	.string "POKéMON saya kawal, tak terpusing!\p"
	.string "Sayalah {STR_VAR_3}, KELASI yang\n"
	.string "pandai rap. Jangan silap, saya bukan\l"
	.string "pengecut yang meratap!\p"
	.string "Saya anak murid no. {STR_VAR_2}\n"
	.string "{STR_VAR_1}. Jangan cepat pandang\l"
	.string "rendah, nanti kamu menyesal!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Nasihat {STR_VAR_3} saya ikut, pasukan\n"
	.string "bangga saya pun terbentuk! Satu\l"
	.string "{STR_VAR_2} yang guna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "dan satu {STR_VAR_2}\n"
	.string "yang guna {STR_VAR_1}!\p"
	.string "Pertemuan kita patut diraikan,\n"
	.string "dengan kemenangan berpasangan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hei, hei, gaya kamu saya suka!\n"
	.string "Pendaftaran kita, saya uruskan segera!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, hei, {PLAYER}, dinginnya kamu! Maaf\n"
	.string "kalau saya terlalu terus terang dengan\l"
	.string "kamu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Yipi-yahu! Eh, jangan lari!\n"
	.string "Saya bergurau saja tadi!\p"
	.string "Helo! Saya {STR_VAR_3}! Saya anak\n"
	.string "murid no. {STR_VAR_2} {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} ajar saya apa nak buat.\n"
	.string "Jadi satu {STR_VAR_2} yang guna\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "dan satu {STR_VAR_2} yang guna\n"
	.string "{STR_VAR_1}, itulah pilihan saya.\p"
	.string "Jadi, apa kata kamu?\n"
	.string "Ayuh, ceriakan hari saya!\p"
	.string "Tolonglah, saya merayu! Biar saya\n"
	.string "sertai kamu, jangan biar saya pilu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Yeahah! Tuah menyebelahi saya!\n"
	.string "Hati saya gembira tak terkata!\p"
	.string "Sebelum kita turun bertarung, saya\n"
	.string "pergi daftar dulu, tak tertangguh!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Kamu tolak saya? {PLAYER},\n"
	.string "kamu buat saya kecewa!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Uhuk!\p"
	.string "Oh, maaf, saya selesema.\n"
	.string "Tapi POKéMON saya sihat.\p"
	.string "Nama saya {STR_VAR_3}, anak murid\n"
	.string "no. {STR_VAR_2} {STR_VAR_1}. Uhuk!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Saya ambil nasihat {STR_VAR_3} dengan\n"
	.string "serius dan bentuk pasukan saya, satu\l"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Saya latih mereka setiap hari,\n"
	.string "walaupun ribut dan hujan.\p"
	.string "Sebab itulah saya selesema, rasanya.\p"
	.string "Begitulah saya. Nak\n"
	.string "jadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Terima kasih, saya hargai! Uhuk, uhuk!\n"
	.string "Tunggu sekejap, saya pergi daftar.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, tak mahu? {PLAYER}, saya\n"
	.string "rasa kita pasangan yang serasi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, helo! Saya gementar betul.\p"
	.string "Saya {STR_VAR_3}. Saya anak murid\n"
	.string "no. {STR_VAR_2} kepada {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} kata pasukan ni bagus: satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Saya rasa segan, tapi sudikah\n"
	.string "kamu benarkan saya sertai kamu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, wah, terima kasih! Saya malu,\n"
	.string "tapi saya akan buat yang terbaik!\p"
	.string "Saya pergi siapkan pendaftaran.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, tolonglah jangan tolak!\n"
	.string "Saya dah cukup segan…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Saya {STR_VAR_3}, dan itu bukan tipu.\n"
	.string "Saya anak murid no. {STR_VAR_2}\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} cadangkan pasukan saya.\p"
	.string "Memandangkan nasihatnya ikhlas, saya\n"
	.string "putuskan untuk bawa {STR_VAR_2} saya\l"
	.string "yang guna {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "{STR_VAR_2} saya yang guna {STR_VAR_1}.\p"
	.string "Kalau boleh, saya ingin kamu terima\n"
	.string "saya sebagai pasangan kamu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Kamu betul-betul terima saya?\n"
	.string "Kalau tidak, teruk jadinya.\p"
	.string "Tapi memandangkan kamu setuju,\n"
	.string "baguslah. Saya akan daftarkan kita\l"
	.string "berdua.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Kenapa pula kamu\n"
	.string "menolak? Kamu bergurau ke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Saya {STR_VAR_1}, seorang ANAK DARA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Yang saya ada ialah satu {STR_VAR_2}\n"
	.string "yang guna {STR_VAR_1} dan satu$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} yang guna {STR_VAR_1}.\n"
	.string "Itulah yang saya bawa.\p"
	.string "Sudi jadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Terima kasih! Saya pergi daftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Kamu tak mahu jadi pasangan\n"
	.string "saya? Nanti kamu menyesal!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Helo!\p"
	.string "Saya ANAK MUDA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Nak tahu apa yang saya ada? Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Kamu sudi jadi pasangan saya, kan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Yeay! Saya pergi daftar, okey?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Alah! Kalau kamu berpasangan dengan\n"
	.string "POKéMON saya, kita takkan dapat\l"
	.string "dihalang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Yahuu! Saya PENDAKI {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Tahu apa yang saya bawa? {STR_VAR_2}\n"
	.string "saya yang guna {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "{STR_VAR_2} saya yang guna {STR_VAR_1}!\p"
	.string "Bagus, kan? Nak jadi pasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Yahuu! Kalau begitu, saya pergi daftar.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Saya nak sangat bertarung\n"
	.string "dengan kamu di sisi saya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Helo! Saya {STR_VAR_1}, seorang JELITA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Kamu tahu apa yang saya bela? Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Apa pendapat kamu? Nak\n"
	.string "jadi pasangan bersama?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Bagusnya! Saya siapkan\n"
	.string "pendaftaran sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Hampanya!\p"
	.string "Kita berdua bersama,\n"
	.string "mesti kita yang terbaik!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Yo!\p"
	.string "Kamu tahu siapa saya? Saya\n"
	.string "{STR_VAR_1} si NELAYAN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Saya bawa pasukan, satu {STR_VAR_2}\n"
	.string "yang guna {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "satu {STR_VAR_2} yang guna {STR_VAR_1}.\p"
	.string "Jadi, macam mana? Sudi\n"
	.string "bertarung di sisi saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Bagus, bagus! Serahkan pada saya!\p"
	.string "Saya pergi daftarkan kita sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Padahal kita memang sepadan…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Gembira berkenalan dengan kamu.\n"
	.string "Saya {STR_VAR_1}, seorang CIK PUAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Saya ditemani pasukan, satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Saya harap kamu berkenan. Kerana\n"
	.string "saya ingin kamu jadi pasangan saya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Saya ucapkan terima kasih yang ikhlas.\n"
	.string "Biar saya uruskan pendaftaran.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Saya pasti kamu akan menyesal tidak\n"
	.string "memilih saya sebagai pasangan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Saya TRIATLET {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Yang saya ada… Satu {STR_VAR_2}\n"
	.string "dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "satu {STR_VAR_2} dengan\n"
	.string "{STR_VAR_1}! Itulah pasangan saya!\p"
	.string "Boleh? Sudi jadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Wah, terima kasih! Saya\n"
	.string "pergi daftar di kaunter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Kita berdua bersama, pasti kita kuat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Hai! Saya PENANGKAP {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Tengok apa saya ada! Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Jadi, dengar sini! Kamu\n"
	.string "nak jadi pasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Beres!\p"
	.string "Saya pergi uruskan\n"
	.string "pendaftaran di kaunter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Alah, POKéMON saya hebat-hebat.\n"
	.string "Harap kamu tak menyesal!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Selamat sejahtera! Saya\n"
	.string "MURID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Yang saya bela ialah satu\n"
	.string "{STR_VAR_2} yang guna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "dan satu {STR_VAR_2}\n"
	.string "yang guna {STR_VAR_1}.\p"
	.string "Boleh tahan, kan? Sudi jadi pasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Terima kasih banyak! Saya\n"
	.string "siapkan pendaftaran.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Sayangnya…\p"
	.string "Saya harap dapat belajar\n"
	.string "daripada kamu sebagai pasangan…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Yo! Biar saya beritahu siapa\n"
	.string "saya! Saya BUDAK KAYA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Cuba teka apa saya ada! Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Saya sudi beri kamu peluang\n"
	.string "jadi pasangan saya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Langkah bijak!\p"
	.string "Saya siapkan proses\n"
	.string "pendaftaran cepat-cepat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Kamu sanggup tolak orang macam saya?\n"
	.string "Kamu pasti menyesal dengan keputusan\l"
	.string "tu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiyah! Saya PENDEKAR {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Sebagai teman, saya ada satu\n"
	.string "{STR_VAR_2} yang guna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "dan satu {STR_VAR_2}\n"
	.string "yang guna {STR_VAR_1}.\p"
	.string "Tolonglah, tunaikan hajat saya!\n"
	.string "Izinkan saya jadi pasangan kamu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiyah! Saya pergi daftar dengan segera!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Begitu… Saya harap dapat\n"
	.string "peluang bila kita jumpa lagi…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Hai! Saya {STR_VAR_1},\n"
	.string "seorang BUDAK TIUB!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Saya beritahu apa saya ada. Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\n"
	.string "Boleh saya jadi pasangan kamu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Terima kasih! Saya pergi\n"
	.string "daftarkan kita sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Kalau kita jadi pasangan,\n"
	.string "mesti kita kuat sangat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Salam… Aku MANIAK SIHIR {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Aku bawa satu {STR_VAR_2} yang\n"
	.string "guna {STR_VAR_1} bersama satu$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} yang guna {STR_VAR_1}…\p"
	.string "Aku merayu… Jadilah pasanganku…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Terima kasih… Aku akan daftarkan kita…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Aku begitu rindu untuk menyertaimu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Apa khabar? Saya {STR_VAR_1},\n"
	.string "seorang PENTERNAK POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "Saya bela dua ekor yang bagus! Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Macam mana? Rasa nak\n"
	.string "jadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Terima kasih banyak!\p"
	.string "Saya pergi uruskan pendaftaran,\n"
	.string "jadi kamu tunggu di sini!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Saya dah tak sabar nak\n"
	.string "jadi pasangan kamu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Helo! Saya TRIATLET {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Nak tahu saya berlari dengan siapa?\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1}\l"
	.string "dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Jadi? Nak jadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Bagus!\p"
	.string "Saya akan cepat-cepat\n"
	.string "siapkan pendaftaran!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Kamu dan saya, mesti kita\n"
	.string "yang terhebat. Sayangnya…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Hei! Nama saya {STR_VAR_1}!\n"
	.string "Saya seorang TRIATLET!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Saya berlari dengan pasukan saya yang\n"
	.string "tahan lasak: satu {STR_VAR_2} dengan\l"
	.string "{STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Boleh tahan, kan? Kita\n"
	.string "patut jadi pasangan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Baiklah! Saya pergi\n"
	.string "daftar sekelip mata!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Saya betul-betul nak bertarung\n"
	.string "sebagai pasangan kamu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Saya SRIKANDI {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "Saya dah latih satu {STR_VAR_2}\n"
	.string "yang guna {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "satu {STR_VAR_2} yang guna {STR_VAR_1}!\p"
	.string "Kamu suka kombo tu? Apa\n"
	.string "kata kita bergabung?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Wah, terima kasih!\p"
	.string "Saya siapkan pendaftaran\n"
	.string "sekarang juga!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Dengan kamu, saya ingat kita\n"
	.string "boleh jadi pasangan paling hebat…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Saya TRIATLET {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "Saya berlari dengan satu {STR_VAR_2}\n"
	.string "yang tahu guna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "dan satu {STR_VAR_2}\n"
	.string "dengan {STR_VAR_1}!\p"
	.string "Kita boleh jadi pasangan.\n"
	.string "Bukankah itu hebat?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Terima kasih!\p"
	.string "Saya pergi daftarkan\n"
	.string "kita, sekarang juga!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Alah, sayangnya. Mesti kita jadi\n"
	.string "pasangan paling kuat di sini!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Saya? Saya BUDAK TIUB {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Apa yang saya bawa? Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Hei? Kamu nak jadi pasangan saya, kan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Okey!\p"
	.string "Saya pergi daftar! Jom\n"
	.string "jadi hebat bersama!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "POKéMON saya memang kuat… Sayang\n"
	.string "kamu tak mahu berpasangan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Yay-hei! Panggil saya\n"
	.string "GITARIS {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Tengok rombongan saya! Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Yay-hei! Liar, kan? Kita mesti\n"
	.string "berduet sebagai pasangan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Yay-hei! Mantap! Saya uruskan\n"
	.string "pendaftaran sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "POKéMON saya rock habis! Kamu\n"
	.string "akan menyesal, percayalah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Gembira bertemu kamu. Saya\n"
	.string "{STR_VAR_1}, seorang BUDIMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Saya ditemani {STR_VAR_2} kepercayaan\n"
	.string "saya yang guna {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "satu {STR_VAR_2} yang guna {STR_VAR_1}.\p"
	.string "Bolehkah saya mempelawa kamu\n"
	.string "untuk menjadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, terima kasih atas kepercayaan kamu.\n"
	.string "Saya akan selesaikan pendaftaran.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Sungguh malang…\p"
	.string "Saya akan menanti peluang\n"
	.string "yang akan datang…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Helo, saya {STR_VAR_1},\n"
	.string "seorang PEMINAT POKé.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Sekarang saya bawa satu {STR_VAR_2}\n"
	.string "yang tahu move {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Berkenan? Apa kata kamu\n"
	.string "jadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Terima kasih! Biar saya\n"
	.string "uruskan pendaftaran!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "POKéMON saya kelas atasan… Sayang\n"
	.string "kamu tak dapat menghargainya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm! Saya {STR_VAR_1},\n"
	.string "dan sayalah MAHAGURU!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "POKéMON yang saya latih ialah satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Apa kata kamu\n"
	.string "berpasangan dengan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm! Saya daftarkan kita segera! Mari\n"
	.string "kita sama-sama buat yang terbaik!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Saya harap pilihan kamu memang betul…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Helo, helo. Saya {STR_VAR_1},\n"
	.string "seorang MAHAGURU.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "Saya bela POKéMON saya dengan teliti.\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1}\l"
	.string "dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "satu {STR_VAR_2} dengan\n"
	.string "{STR_VAR_1}, itulah yang saya ada.\p"
	.string "Kamu tak mahu\n"
	.string "berpasangan dengan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bagus, bagus. Saya uruskan\n"
	.string "pendaftaran segera.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Mungkin kita boleh berpasangan\n"
	.string "bila kita jumpa lagi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Saya PAWANG NAGA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "Pasukan yang saya latih ialah satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Macam mana? Nak jadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Okey, saya akan buat yang terbaik!\n"
	.string "Saya pergi daftar sekarang, boleh?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Susah kamu nak cari pasangan\n"
	.string "yang lebih kuat daripada saya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Saya PAKAR BURUNG {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "POKéMON apa yang saya ada? Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Tak rasa ke kita boleh\n"
	.string "jadi pasangan yang hebat?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Bagus, terima kasih! Biar\n"
	.string "saya uruskan pendaftaran!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Saya dan POKéMON saya kuat. Hampanya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Saya BUDAK NINJA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Pasukan POKéMON saya terdiri daripada\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}\l"
	.string "dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Jom jadi pasangan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Yeay! Biar saya pergi daftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Kamu akan menyesal tak ambil POKéMON\n"
	.string "saya yang kuat di pihak kamu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Helo! Saya GADIS PAYUNG {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Yang mengiringi saya ialah {STR_VAR_2}\n"
	.string "saya yang guna {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "satu {STR_VAR_2} yang guna {STR_VAR_1}.\p"
	.string "Comel, kan? Sudi sertai\n"
	.string "kami sebagai pasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Terima kasih banyak!\p"
	.string "Saya pergi daftar di kaunter. Jangan\n"
	.string "kita kecewakan satu sama lain!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "POKéMON saya sangat kuat. Hampanya…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Helo. Saya {STR_VAR_1},\n"
	.string "seorang MANIAK SRNGA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "Saya dah jumpa POKéMON saya, ya. Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "satu {STR_VAR_2} dengan\n"
	.string "{STR_VAR_1}, itulah yang saya jumpa.\p"
	.string "Kamu berminat jadi pasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Okey! Faham!\p"
	.string "Saya takkan lama untuk pendaftaran!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Dengan POKéMON yang saya\n"
	.string "jumpa, kita takkan kalah…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ahoi! Saya KELASI {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Biar saya tunjuk kebanggaan saya! Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Tentu kamu takkan tolak saya.\n"
	.string "Kita jadi pasangan, kan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "Memang saya dah agak! Saya\n"
	.string "pergi daftar sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Kita mesti dah rempuh\n"
	.string "semua lawan! Sayangnya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hai, saya {STR_VAR_1}.\n"
	.string "Saya seorang PENGUMPUL.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "Permata dalam koleksi saya ialah\n"
	.string "{STR_VAR_2} saya dengan {STR_VAR_1}\l"
	.string "dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Hebat, kan? Kita patut\n"
	.string "jadi satu pasukan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, ya!\p"
	.string "Jangan buang masa. Saya\n"
	.string "pergi daftarkan kita berdua.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Hmm, kecewanya. Kamu tak\n"
	.string "hargai POKéMON saya.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Helo, saya {STR_VAR_1}. Saya\n"
	.string "seorang RENJER POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Yang menemani saya ialah satu\n"
	.string "{STR_VAR_2} yang guna {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Tak rasa ke kita boleh jadi\n"
	.string "pasangan yang mengagumkan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "Hebat! Saya uruskan\n"
	.string "pendaftaran sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "Lain kali, pilih POKéMON saya, ya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Nama saya {STR_VAR_1}. Saya\n"
	.string "seorang RENJER POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Biar saya ceritakan pasukan saya. Saya\n"
	.string "ada satu {STR_VAR_2} dengan\l"
	.string "{STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Sudi jadi pasangan dengan\n"
	.string "geng kecil saya ni?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Kita akan jadi yang terbaik! Saya\n"
	.string "siapkan pendaftaran cepat-cepat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "Saya harap kamu pilih\n"
	.string "POKéMON saya lain kali.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Gembira bertemu kamu. Saya {STR_VAR_1}.\n"
	.string "Saya anggap diri saya seorang AROMA\l"
	.string "CIK PUAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Saya mengembara dengan satu\n"
	.string "{STR_VAR_2} yang guna {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "satu {STR_VAR_2} yang guna {STR_VAR_1}.\p"
	.string "Harap kamu berkenan.\n"
	.string "Sudi jadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Saya berbesar hati kamu terima.\n"
	.string "Saya pergi daftar sekarang juga.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Alangkah baiknya kalau kita dapat\n"
	.string "berpasangan bila kita jumpa lagi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Nak tahu siapa saya? Saya\n"
	.string "{STR_VAR_1}, si MANIAK PURBA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "POKéMON yang saya bawa ialah satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Menarik, kan? Apa kata\n"
	.string "kita berpasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "Keputusan yang bijak! Saya pergi\n"
	.string "uruskan kertas pendaftaran.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm… Saya rasa POKéMON saya kuat…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Saya JAGUH {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "POKéMON yang saya ada sekarang ialah\n"
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}\l"
	.string "dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "satu {STR_VAR_2} dengan\n"
	.string "{STR_VAR_1}. Hebat, kan?\p"
	.string "Tak rasa ke hebat kalau\n"
	.string "kita jadi pasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Hebat! Saya pergi daftar sekelip mata!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Saya ingat kita boleh jadi\n"
	.string "pasukan yang paling hebat.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Saya JAGUH {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "Pasukan yang saya bela ada satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Okey tak? Apa kata kita jadi pasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Beres! Baik saya pergi daftar.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Saya terfikir betapa\n"
	.string "kuatnya pasukan kita nanti…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Heyo! Saya {STR_VAR_1}, si POKéMANIAK!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Apa yang orang macam saya ada? Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "satu {STR_VAR_2} dengan\n"
	.string "{STR_VAR_1}, itulah dia!\p"
	.string "Jom! Kita pijak semua\n"
	.string "lawan sebagai pasangan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Pilihan tepat! Saya\n"
	.string "daftarkan kita berdua!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "POKéMON saya ganas! Bukan\n"
	.string "salah saya kalau kamu menyesal!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Yo! Saya PEMAIN API {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Kamu tahu apa hasil latihan saya? Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Jadi, apa kata kamu? Nak jadi pasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "Baiklah! Saya teruskan\n"
	.string "dengan pendaftaran.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Janji kamu akan berpasangan dengan\n"
	.string "saya bila kita terserempak lagi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Saya {STR_VAR_1}, seorang PEKHEMAH!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "Saya bela satu {STR_VAR_2}\n"
	.string "yang guna {STR_VAR_1} dan satu$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_2} yang guna {STR_VAR_1}.\p"
	.string "Seronok tak kalau kita\n"
	.string "berpasangan? Mesti seronok!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Yeah! Saya pergi daftar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "Lain kali, okey? Saya\n"
	.string "nak jadi pasangan kamu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Helo! Saya {STR_VAR_1},\n"
	.string "seorang GADIS PIKNIK!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "POKéMON yang saya bawa ialah satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Kamu berminat jadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Wah, terima kasih! Saya\n"
	.string "uruskan pendaftaran sekarang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Seronok kalau saya dapat\n"
	.string "sertai kamu lain kali.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Saya PSIKIK {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "Pasangan yang saya bela ialah satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Sudi jadi pasangan saya?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Tentu! Saya uruskan pendaftaran!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Kalau kita jumpa lagi, masa itulah\n"
	.string "saya nak berpasangan dengan kamu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Saya {STR_VAR_1}.\n"
	.string "Saya seorang PSIKIK.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Satu {STR_VAR_2}\n"
	.string "dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1},\n"
	.string "merekalah pengikut saya.\p"
	.string "Tak tertarik ke kamu dengan\n"
	.string "idea menjadi pasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Terima kasih. Saya pergi\n"
	.string "uruskan pendaftaran.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "Saya harap ada peluang lain\n"
	.string "untuk menjalin pakatan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Saya MURID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Satu {STR_VAR_2} yang guna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "dan satu {STR_VAR_2} yang guna\n"
	.string "{STR_VAR_1}, itulah pasangan POKéMON\l"
	.string "saya.\p"
	.string "Boleh saya jadi pasangan kamu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, terima kasih! Saya pergi\n"
	.string "daftar di kaunter sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Tolonglah? Boleh saya\n"
	.string "sertai kamu lain kali?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Hai! Nama saya {STR_VAR_1}!\n"
	.string "Saya seorang PENTERNAK POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "POKéMON yang saya bela ialah satu\n"
	.string "{STR_VAR_2} yang guna {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "satu {STR_VAR_2} yang guna {STR_VAR_1}.\p"
	.string "Menarik? Apa kata kita jadi pasangan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Baiklah! Serahkan\n"
	.string "pendaftaran pada saya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Lain kali kamu mesti\n"
	.string "berpasangan dengan saya, okey?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Saya {STR_VAR_1}, dan saya bangga\n"
	.string "mengaku saya seorang PEMINAT POKé.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "POKéMON kesayangan yang saya bela\n"
	.string "ialah satu {STR_VAR_2} dengan\l"
	.string "{STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}.\p"
	.string "Comel sangat, kan? Kita\n"
	.string "patut jadi satu pasukan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Terima kasih, sayang! Saya\n"
	.string "pergi daftar sekarang!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "POKéMON kesayangan saya yang terbaik,\n"
	.string "tahu tak. Menjengkelkan betul!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hai, saya PERENANG {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Satu {STR_VAR_2} yang guna {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "dan satu {STR_VAR_2} yang guna\n"
	.string "{STR_VAR_1}, itulah yang saya latih.\p"
	.string "Kamu dan saya, jom jadi pasangan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Bagus! Saya daftarkan kita berdua.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Kalau kita jumpa lagi, kamu berhutang\n"
	.string "satu pasangan dengan saya!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Apa cerita? Saya {STR_VAR_1},\n"
	.string "seorang TRIATLET.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Saya ada dua POKéMON yang boleh tahan.\n"
	.string "Satu {STR_VAR_2} dengan {STR_VAR_1}\l"
	.string "dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Best kalau kita jadi\n"
	.string "pasangan, jadi macam mana?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Mantap! Kamu tunggu\n"
	.string "sementara saya daftar, okey?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Saya harap kamu benarkan saya\n"
	.string "sertai kamu lain kali, boleh?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Saya TRIATLET {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Satu {STR_VAR_2}\n"
	.string "dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "satu lagi {STR_VAR_2} yang tahu guna\n"
	.string "{STR_VAR_1}. Itulah pasangan saya.\p"
	.string "Apa pendapat kamu? Pada saya,\n"
	.string "kita pasukan yang bagus.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "Saya suka jawapan tu! Saya\n"
	.string "siapkan pendaftaran cepat-cepat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Kamu akan beri saya peluang\n"
	.string "lagi untuk berpasangan, kan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Hai! Helo! Saya {STR_VAR_1},\n"
	.string "seorang PERENANG!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Tengok apa yang saya bela! Satu\n"
	.string "{STR_VAR_2} dengan {STR_VAR_1} dan$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "satu {STR_VAR_2} dengan {STR_VAR_1}!\p"
	.string "Best, kan? Lagi best\n"
	.string "kalau kita jadi pasangan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Terima kasih banyak! Saya\n"
	.string "siapkan pendaftaran ni!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Kalau kita jumpa lagi, kamu mesti\n"
	.string "berpasangan dengan saya. Kamu akan\l"
	.string "buat, kan?$"

