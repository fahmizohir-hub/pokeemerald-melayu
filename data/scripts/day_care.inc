Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCostAndPrepareString
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applywaitmovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "Saya PAKCIK TASKA.\p"
	.string "Saya bantu jaga POKéMON kesayangan\n"
	.string "para JURULATIH.\p"
	.string "Kalau kamu nak saya bela POKéMON kamu,\n"
	.string "cakaplah dengan isteri saya.$"

Route117_Text_DoYouWantEgg:
	.string "Ah, kamu rupanya!\p"
	.string "Masa kami jaga POKéMON kamu,\n"
	.string "aduhai, terkejut betul kami!\p"
	.string "POKéMON kamu ada sebiji TELUR!\p"
	.string "Kami pun tak tahu dari mana datangnya,\n"
	.string "tapi memang POKéMON kamu yang ada\l"
	.string "TELUR tu.\p"
	.string "Kamu nak, kan?$"

Route117_Text_YourMonIsDoingFine:
	.string "Ah, kamu rupanya! Gembira jumpa kamu.\n"
	.string "{STR_VAR_1} kamu sihat-sihat saja.$"

Route117_Text_IllKeepIt:
	.string "Kalau begitu, saya simpan sajalah.\n"
	.string "Terima kasih!$"

Route117_Text_YouHaveNoRoomForIt:
	.string "Kamu dah tak ada ruang…\n"
	.string "Datang balik bila dah ada ruang.$"

Route117_Text_ReceivedEgg:
	.string "{PLAYER} menerima TELUR daripada\n"
	.string "PAKCIK TASKA.$"

Route117_Text_TakeGoodCareOfIt:
	.string "Jaga baik-baik, ya.$"

Route117_Text_FriendlyWithOtherTrainersMon:
	.string "Oh ya, tentang {STR_VAR_1} kamu,\n"
	.string "nampaknya dia rapat dengan\l"
	.string "{STR_VAR_3} milik {STR_VAR_2}.\p"
	.string "Rasanya saya pernah nampak dia\n"
	.string "terima sepucuk SURAT.$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.string "Kalau kamu nak ambil POKéMON kamu,\n"
	.string "cakaplah dengan isteri saya.$"

Route117_Text_YourMonsAreDoingFine:
	.string "Ah, kamu rupanya! {STR_VAR_1} dan\n"
	.string "{STR_VAR_2} kamu sihat-sihat saja.$"

Route117_Text_IWillKeepDoYouWantIt:
	.string "Betul ni, nanti saya simpan sendiri.\n"
	.string "Kamu nak, kan?$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "Saya MAKCIK TASKA.\p"
	.string "Kami boleh bela POKéMON untuk kamu.\p"
	.string "Kamu nak kami bela seekor?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "POKéMON mana yang kamu nak kami bela?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.string "Baiklah, kami jaga {STR_VAR_1}\n"
	.string "kamu untuk sementara.\p"
	.string "Nanti datang ambil, ya.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "Kami boleh bela dua POKéMON kamu.\n"
	.string "Kamu nak kami bela seekor lagi?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
	.string "Suami saya tadi cari kamu.$"

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.string "Oh, baiklah kalau begitu.\n"
	.string "Datang lagi, ya.$"

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.string "Wang kamu tak cukup…$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "Kamu nak ambil balik yang seekor lagi\n"
	.string "juga?$"

Route117_PokemonDayCare_Text_ComeAgain:
	.string "Baiklah.\n"
	.string "Datang lagi, ya.$"

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.string "Ah, kamu rupanya! Gembira jumpa kamu.\n"
	.string "POKéMON kamu memang baik-baik saja!$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "{STR_VAR_1} kamu dah naik\n"
	.string "{STR_VAR_2} tahap.$"

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.string "Pasukan POKéMON kamu dah penuh.\n"
	.string "Kosongkan ruang dulu, lepas tu\l"
	.string "jumpa saya.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
	.string "POKéMON mana yang kamu nak ambil balik?$"

Route117_PokemonDayCare_Text_ItWillCostX:
	.string "Kalau nak ambil balik {STR_VAR_1} kamu,\n"
	.string "bayarannya ¥{STR_VAR_2}.$"

Route117_PokemonDayCare_Text_HeresYourMon:
	.string "Bagus!\n"
	.string "Ini POKéMON kamu.$"

Route117_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER} mengambil balik {STR_VAR_1}\n"
	.string "daripada MAKCIK TASKA.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "Eh? Tapi kamu cuma ada seekor POKéMON.\p"
	.string "Datanglah lain kali.$"

Route117_PokemonDayCare_Text_TakeYourMonBack:
	.string "Kamu nak ambil balik POKéMON kamu?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "Kalau POKéMON itu ditinggalkan di sini,\n"
	.string "kamu nak bertarung guna apa?\p"
	.string "Datanglah lain kali.$"

Text_EggHatchHuh:
	.string "Eh?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "Eh?\n"
	.string "Sabar, sabar.\p"
	.string "Kalau POKéMON itu ditinggalkan di sini,\n"
	.string "kamu cuma ada seekor saja.\p"
	.string "Rasanya lebih baik kamu tangkap\n"
	.string "beberapa ekor lagi.$"
