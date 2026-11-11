Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Aduhai, aduhai.\n"
	.string "POKéMON kamu nampak penat sangat.\p"
	.string "Kalau kamu mahu, berehatlah di sini.\n"
	.string "Idea yang bagus tu! Buatlah begitu.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Betul tu.\n"
	.string "Ambil masa dan berehatlah!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Aduhai, aduhai.\n"
	.string "POKéMON kamu masih penat?\p"
	.string "Berehatlah lagi di sini.\n"
	.string "Idea yang bagus tu. Buatlah begitu.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Begitu ke?\n"
	.string "Tak perlu malu-malu.$"

