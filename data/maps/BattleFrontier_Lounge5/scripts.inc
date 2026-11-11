BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Hehe! Saya boleh tahu\n"
	.string "apa yang POKéMON fikir!\p"
	.string "Tolonglah! Boleh saya\n"
	.string "tengok POKéMON kamu?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Huh! Kedekut!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka bertarung! Ia\n"
	.string "tetap bertarung walaupun dah banyak\l"
	.string "sakit!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka main licik! Tapi\n"
	.string "kalau dah cukup sakit, ia akan balas\l"
	.string "balik!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka bertarung! Tapi\n"
	.string "kalau dah cukup sakit, ia akan risaukan\l"
	.string "diri sendiri!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka bertarung! Ia\n"
	.string "tetap bertarung walaupun dah banyak\l"
	.string "sakit!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka jaga diri! Tapi\n"
	.string "kalau dah cukup sakit, ia akan balas\l"
	.string "balik!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka main licik! Tapi\n"
	.string "kalau dah cukup sakit, ia akan risaukan\l"
	.string "diri sendiri!$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka bertarung! Ia\n"
	.string "tetap bertarung walaupun dah banyak\l"
	.string "sakit!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka main licik! Tapi\n"
	.string "kalau dah cukup sakit, ia akan balas\l"
	.string "balik!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka bertarung! Tapi\n"
	.string "kalau dah cukup sakit, ia akan risaukan\l"
	.string "diri sendiri!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka main licik! Ia kata\n"
	.string "ia tetap main licik walaupun dah banyak\l"
	.string "sakit!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka bertarung! Tapi\n"
	.string "kalau dah cukup sakit, ia akan jadi\l"
	.string "licik!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka bertarung! Ia\n"
	.string "tetap bertarung walaupun dah banyak\l"
	.string "sakit!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka main licik! Ia kata\n"
	.string "ia tetap main licik walaupun dah banyak\l"
	.string "sakit!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka main licik! Tapi\n"
	.string "kalau dah cukup sakit, ia akan risaukan\l"
	.string "diri sendiri!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka jaga diri! Ia kata\n"
	.string "ia risaukan diri sendiri, sakit atau\l"
	.string "tidak!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka jaga diri! Tapi\n"
	.string "kalau dah cukup sakit, ia akan jadi\l"
	.string "licik!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka jaga diri! Ia kata\n"
	.string "ia tetap risaukan diri walaupun dah\l"
	.string "banyak sakit!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka main licik! Ia kata\n"
	.string "ia tetap main licik walaupun dah banyak\l"
	.string "sakit!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka jaga diri! Ia kata\n"
	.string "ia tetap risaukan diri walaupun dah\l"
	.string "banyak sakit!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka jaga diri! Tapi\n"
	.string "kalau dah cukup sakit, ia akan balas\l"
	.string "balik!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka bertarung! Tapi\n"
	.string "kalau dah cukup sakit, ia akan jadi\l"
	.string "licik!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Hmhm…\p"
	.string "Yang ni kata ia suka jaga diri! Tapi\n"
	.string "kalau dah cukup sakit, ia akan jadi\l"
	.string "licik!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Mengarutlah! TELUR tu tengah tidur!\n"
	.string "Saya tak boleh bercakap dengannya!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Comelnya! Budak perempuan tu\n"
	.string "kata dia faham cakap POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Saya rasa budak perempuan tu sedang\n"
	.string "cakap sesuatu yang sangat mendalam.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Saya tahu sesuatu!\p"
	.string "Budak perempuan tu selalu\n"
	.string "main di rumah merah!$"

