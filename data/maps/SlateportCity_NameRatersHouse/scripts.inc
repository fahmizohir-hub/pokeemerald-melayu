SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Hai, hai! Sayalah PENILAI NAMA!\n"
	.string "Saya tukang tilik nama!\p"
	.string "Dengan senang hati saya akan nilai nama\n"
	.string "timangan POKéMON kamu.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Nama timangan POKéMON mana yang patut\n"
	.string "saya kritik?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, ya? Nama yang kamu\n"
	.string "beri tu agak bagus.\p"
	.string "Tapi! Apa kata kalau saya cadangkan\n"
	.string "nama yang lebih baik sedikit?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, bagus. Jadi, apa nama timangan\n"
	.string "barunya?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Siap! Mulai sekarang, POKéMON ni akan\n"
	.string "dikenali sebagai {STR_VAR_1}!\p"
	.string "Nama ni lebih baik daripada sebelumnya!\n"
	.string "Bertuahnya kamu!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Begitu.\n"
	.string "Datanglah melawat lagi.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Siap! Mulai sekarang, POKéMON ni akan\n"
	.string "dikenali sebagai {STR_VAR_1}!\p"
	.string "Nampak sama saja macam sebelumnya,\n"
	.string "tapi sebenarnya jauh lebih hebat!\p"
	.string "Bertuahnya kamu!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1} rupanya!\p"
	.string "Ini nama timangan yang hebat!\n"
	.string "Langsung tiada cacat celanya!\p"
	.string "Hargailah {STR_VAR_1} kamu sekarang\n"
	.string "dan selamanya.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Eh, eh.\n"
	.string "Itu cuma TELUR!$"

