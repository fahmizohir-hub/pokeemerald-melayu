SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Kamu kenal POKéMON SEEDOT?\n"
	.string "Jarang sekali nampak di SOOTOPOLIS.\p"
	.string "Apa-apa pun, saya suka SEEDOT besar.\n"
	.string "Lagi besar lagi bagus.\p"
	.string "Tapi adik saya kata LOTAD lebih besar.\p"
	.string "Mengarut.\n"
	.string "SEEDOT mesti lebih besar!\p"
	.string "Eh? Kamu ada bawa SEEDOT?\n"
	.string "To-to-tolong, tunjukkan saya!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} inci!\n"
	.string "Ya ampun, besarnya!\p"
	.string "Mungkin lebih besar daripada LOTAD\n"
	.string "besar yang adik saya nampak!\p"
	.string "Terima kasih tunjukkan saya.\n"
	.string "Ini tanda terima kasih saya!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} menerima UBAT.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Eh?\n"
	.string "BEG kamu dah penuh sesak.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} inci, ya?\p"
	.string "Hmm… Saya pernah nampak SEEDOT yang\n"
	.string "lebih besar daripada ini.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Oh, yang ni memang menarik…\n"
	.string "Tapi ini bukan SEEDOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Kamu tak ada SEEDOT besar?\n"
	.string "Sayangnya…\p"
	.string "Kalau kamu dapat SEEDOT besar,\n"
	.string "datanglah tunjukkan saya.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "SEEDOT terbesar dalam sejarah!\n"
	.string "{STR_VAR_2}: gergasi {STR_VAR_3} inci!\p"
	.string "SEEDOT lebih besar daripada LOTAD\n"
	.string "yang selama ini diidamkan!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Kamu kenal POKéMON LOTAD?\n"
	.string "Jarang sekali nampak di SOOTOPOLIS.\p"
	.string "Saya suka, betul-betul suka, LOTAD\n"
	.string "besar!\p"
	.string "Abang saya kata SEEDOT lebih besar.\p"
	.string "Tapi salah! Semua orang tahu LOTAD jauh\n"
	.string "lebih besar.\p"
	.string "Eh? Kamu ada LOTAD?\n"
	.string "To-to-tolong tunjukkan saya!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} inci!\n"
	.string "Wah, besarnya!\p"
	.string "Mungkin lebih besar daripada SEEDOT\n"
	.string "gergasi yang abang saya nampak.\p"
	.string "Terima kasih tunjukkan saya!\n"
	.string "Ini tanda terima kasih saya!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} menerima UBAT.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Eh?\n"
	.string "BEG kamu dah penuh sesak.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} inci?\p"
	.string "Hmm… Saya pernah nampak LOTAD yang\n"
	.string "lebih besar daripada yang ini.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Wah, menarik juga ni!\n"
	.string "Tapi ini bukan LOTAD!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Kamu tak ada LOTAD besar?\n"
	.string "Hampanya…\p"
	.string "Kalau kamu dapat LOTAD besar,\n"
	.string "datanglah tunjukkan saya!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "LOTAD terbesar dalam sejarah!\n"
	.string "{STR_VAR_2}: raksasa {STR_VAR_3} inci!\p"
	.string "LOTAD lebih besar daripada SEEDOT\n"
	.string "yang selama ini diidamkan!$"

