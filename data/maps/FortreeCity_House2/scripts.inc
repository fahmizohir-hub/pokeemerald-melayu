FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Manusia… POKéMON…\p"
	.string "Kuasa terpendam mereka terbangkit\n"
	.string "bila hidup di persekitaran alam…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Biar nenek tua ni tengok sama ada\n"
	.string "kuasa terpendam kamu dah bangkit…\p"
	.string "Nenek pegang sekeping syiling.\p"
	.string "Sekarang, beritahu nenek, syiling ni\n"
	.string "di tangan kanan? Atau tangan kiri?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Ya, betul!\p"
	.string "Kita cuba lagi.\p"
	.string "Di tangan mana nenek sorok syiling?\n"
	.string "Kanan atau kiri?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Ya, betul!\p"
	.string "Kita cuba lagi.\p"
	.string "Di tangan mana nenek sorok syiling?\n"
	.string "Kanan atau kiri?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Oh! Hebat!\n"
	.string "Kuasa terpendam kamu dah bangkit!\p"
	.string "Nah, ambil ni dan bangkitkan kuasa\n"
	.string "terpendam POKéMON kamu.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "KUASA PENDAM ialah move yang berubah\n"
	.string "mengikut POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Tidak, sayang sekali.\n"
	.string "Tekaan kamu salah.$"

