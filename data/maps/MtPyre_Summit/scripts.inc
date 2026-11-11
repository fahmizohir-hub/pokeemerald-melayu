MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceUp
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Tidak! Samseng TEAM MAGMA tu sampai\n"
	.string "sini dulu!\p"
	.string "Kita tak boleh ketinggalan!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Aku ingat kau ni ahli MAGMA yang patah\n"
	.string "balik…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ya, kau memang kuat…\n"
	.string "Tapi kami ramai!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah!\n"
	.string "Malang nasib kau!\p"
	.string "Kalau kau datang awal, kau cuma perlu\n"
	.string "lawan TEAM MAGMA yang lembik tu.\p"
	.string "Tapi sebab kau sampai sekarang, kau\n"
	.string "kena lawan kami yang gagah ni!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh… Patutnya aku biar kau lawan\n"
	.string "TEAM MAGMA dulu…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Kau tak tahu apa-apa!\n"
	.string "Jadi kenapa kau kacau kami?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Kau…\n"
	.string "Kami nampak kau di GUNUNG CHIMNEY.\p"
	.string "Kau bukan ahli mana-mana PASUKAN, jadi\n"
	.string "kenapa kau ada di sini?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Kalau nak kacau orang, kacaulah\n"
	.string "TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, tak kisahlah!\n"
	.string "Kami dah berjaya lengahkan masa!\p"
	.string "BOS mesti dah rampas apa yang dia mahu!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, aku tahu! Kau cuba masuk\n"
	.string "TEAM MAGMA, tapi mereka tak terima kau!\p"
	.string "Jangan ingat kami akan terima kau\n"
	.string "masuk TEAM AQUA!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Kalau kau teringin sangat nak masuk\n"
	.string "TEAM AQUA, kami boleh fikirkan…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Kami ahli-ahli dan ketua kami memang\n"
	.string "gabungan yang hebat.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIE: MAXIE TEAM MAGMA dah dahului\n"
	.string "kami, tapi kami pun dapat apa yang kami\l"
	.string "mahu.\p"
	.string "MESTIKA MERAH yang disimpan di\n"
	.string "GUNUNG PYRE… Kini milik aku, ARCHIE!\p"
	.string "Fufufu… Sekarang kami boleh capai\n"
	.string "matlamat muktamad kami!\p"
	.string "Okey, PASUKAN!\n"
	.string "Kita berundur!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, tidak…\n"
	.string "Ini tak boleh berlaku…\p"
	.string "Bukan saja MESTIKA BIRU, malah MESTIKA\n"
	.string "MERAH pun dah diambil…\p"
	.string "MESTIKA BIRU dan MESTIKA MERAH tak\n"
	.string "boleh dipisahkan. Ia mesti bersama.\p"
	.string "Apa yang orang-orang itu cuba lakukan\n"
	.string "dengan dua MESTIKA itu?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, ya. TEAM MAGMA ke yang datang dan\n"
	.string "ambil MESTIKA BIRU dulu?\p"
	.string "Dalam tergesa-gesa, mereka tertinggal\n"
	.string "benda ini.\p"
	.string "Saya tak dapat bayangkan apa\n"
	.string "sebenarnya benda ini.\p"
	.string "Saya mahu kamu menyimpannya. Mungkin\n"
	.string "ia berguna nanti.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "MESTIKA BIRU dan MESTIKA MERAH diambil\n"
	.string "oleh orang-orang jahat itu…\p"
	.string "Ia tak boleh berpisah… Saya takut\n"
	.string "sesuatu yang dahsyat akan berlaku…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Ya Tuhan…\p"
	.string "Kamu kata GROUDON dan KYOGRE\n"
	.string "kedua-duanya dah bangkit?\p"
	.string "Kata orang, MESTIKA BIRU dan MESTIKA\n"
	.string "MERAH yang meredakan amarah dua\l"
	.string "POKéMON itu…\p"
	.string "Kata orang juga, pemilik sebenar\n"
	.string "MESTIKA itu masih wujud.\p"
	.string "Tapi, tiada siapa tahu siapa, atau apa\n"
	.string "sebenarnya, pemilik MESTIKA itu.\p"
	.string "Mungkin manusia, mungkin juga POKéMON,\n"
	.string "tapi tiada siapa yang tahu.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Dua lelaki yang ambil MESTIKA itu\n"
	.string "datang semula memulangkannya sendiri.\p"
	.string "Mereka itu… Mungkin mereka tak sejahat\n"
	.string "yang disangka…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Penjelmaan daratan, lautan dan langit…\p"
	.string "Itulah dikatakan identiti POKéMON\n"
	.string "purba agung…\p"
	.string "Sama seperti kita manusia dan POKéMON\n"
	.string "yang bernyawa, dunia kita juga hidup…\p"
	.string "POKéMON purba agung yang mengajar kita\n"
	.string "perkara itu…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "GUNUNG PYRE ialah tempat kami\n"
	.string "menenangkan roh POKéMON yang telah\l"
	.string "pergi…\p"
	.string "Dari tempat tinggi ini, kita boleh\n"
	.string "melihat seluruh HOENN…\p"
	.string "Roh POKéMON yang telah pergi pasti\n"
	.string "mendapat ketenangan di sini…\p"
	.string "Kebetulankah kamu berada di sini…\p"
	.string "Sudikah kamu dengar kisah saya? Kisah\n"
	.string "yang lama diceritakan di wilayah HOENN?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Ia berlaku lama, lama dahulu…\p"
	.string "Dunia digoncang oleh pertembungan\n"
	.string "dahsyat antara POKéMON daratan dan\l"
	.string "POKéMON lautan…\p"
	.string "POKéMON daratan menaikkan\n"
	.string "gunung-ganang dan mencipta benua…\p"
	.string "POKéMON lautan menaikkan ombak besar\n"
	.string "dan mengukir samudera…\p"
	.string "Pertarungan sengit mereka berterusan\n"
	.string "tanpa henti.\p"
	.string "Dunia ditelan api yang marak dan ribut\n"
	.string "yang ganas.\p"
	.string "MESTIKA BIRU dan MESTIKA MERAH\n"
	.string "menamatkan malapetaka itu.\p"
	.string "Cahaya memancar dari dua MESTIKA itu\n"
	.string "dan menenangkan dua seteru yang murka.\p"
	.string "Kedua-duanya, yang kini jinak, menyelam\n"
	.string "jauh ke dasar laut dan akhirnya lenyap…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Begitu…\n"
	.string "Ya, itu pun tak apa…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Tugas saya ialah menyampaikan legenda\n"
	.string "HOENN kepada generasi akan datang.\p"
	.string "Dan krisis yang baru berakhir di\n"
	.string "SOOTOPOLIS telah mengubah sebuah\l"
	.string "legenda…\p"
	.string "Kamu ada masa untuk mendengar legenda\n"
	.string "baru HOENN?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Ia berlaku lama, lama dahulu…\p"
	.string "Dunia digoncang oleh pertembungan\n"
	.string "dahsyat antara POKéMON daratan dan\l"
	.string "POKéMON lautan…\p"
	.string "POKéMON daratan menaikkan\n"
	.string "gunung-ganang dan mencipta benua…\p"
	.string "POKéMON lautan menaikkan ombak besar\n"
	.string "dan mengukir samudera…\p"
	.string "Pertarungan sengit mereka berterusan\n"
	.string "tanpa henti.\p"
	.string "Dunia ditelan api yang marak dan ribut\n"
	.string "yang ganas.\p"
	.string "Ketika itulah POKéMON langit turun dari\n"
	.string "ribut.\p"
	.string "POKéMON itu, bersinar hijau terang,\n"
	.string "menenangkan dua POKéMON yang murka.\p"
	.string "Kemudian, setelah tugasnya selesai,\n"
	.string "POKéMON hijau itu terbang jauh ke\l"
	.string "langit biru…$"

