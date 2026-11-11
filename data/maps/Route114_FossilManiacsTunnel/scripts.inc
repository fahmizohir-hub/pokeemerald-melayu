Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Saya PEMINAT FOSIL…\n"
	.string "Saya orang baik yang suka FOSIL…\p"
	.string "Kamu nak FOSIL?\p"
	.string "Tapi semua FOSIL di kawasan ni\n"
	.string "saya punya… Tak ada untuk kamu…\p"
	.string "Kalau kamu tak tahan tanpa FOSIL,\n"
	.string "carilah di gurun yang ada batu\l"
	.string "besar dan pasir yang mungkin\l"
	.string "menyembunyikan FOSIL…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Kamu jumpa FOSIL, kan?\n"
	.string "Bestnya… Macam dalam mimpi…\p"
	.string "Apa kamu nak buat dengan FOSIL\n"
	.string "tu?\p"
	.string "Saya dengar DEVON sedang buat\n"
	.string "kajian untuk menghidupkan POKéMON\l"
	.string "daripada FOSIL…\p"
	.string "Saya sayang FOSIL saya, jadi saya\n"
	.string "takkan buat benda macam tu…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "FOSIL memang… Menakjubkan…\n"
	.string "Macam dalam mimpi…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh…\n"
	.string "Sana tak selamat…\p"
	.string "Saya tengah gali, masa tu…\n"
	.string "Tiba-tiba seluruh dinding runtuh…\p"
	.string "Rasanya ada gua besar di bawah\n"
	.string "sekarang…\p"
	.string "Tapi saya biarkan saja sebab saya\n"
	.string "rasa tak ada FOSIL di situ…$"

