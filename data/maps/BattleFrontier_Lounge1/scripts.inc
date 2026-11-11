BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "Sudah 70 tahun saya membela POKéMON!\n"
	.string "Sayalah lelaki yang digelar PENTERNAK\l"
	.string "POKéMON agung yang legenda!\p"
	.string "Kalau kamu sudah semahir saya, kamu\n"
	.string "boleh nampak kebolehan POKéMON sekali\l"
	.string "pandang.\p"
	.string "Kamu seorang JURULATIH. Tak teringin\n"
	.string "ke kamu tahu kebolehan POKéMON kamu\l"
	.string "sendiri?\p"
	.string "Mari! Biar saya tengok POKéMON kamu!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "…Hmm…\p"
	.string "Yang ini, secara keseluruhan, saya\n"
	.string "katakan kebolehannya sederhana.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "…Hmm…\p"
	.string "Yang ini, secara keseluruhan, saya\n"
	.string "katakan kebolehannya melebihi purata.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "…Hmm…\p"
	.string "Yang ini, secara keseluruhan, saya\n"
	.string "katakan kebolehannya agak\l"
	.string "mengagumkan!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "…Hmm…\p"
	.string "Yang ini, secara keseluruhan, saya\n"
	.string "katakan kebolehannya sungguh\l"
	.string "cemerlang!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "Oh ya, aspek terbaiknya, pada\n"
	.string "pendapat saya, ialah HP…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "Oh ya, aspek terbaiknya, pada\n"
	.string "pendapat saya, ialah SERANGAN…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "Oh ya, aspek terbaiknya, pada\n"
	.string "pendapat saya, ialah PERTAHANAN…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "Oh ya, aspek terbaiknya, pada\n"
	.string "pendapat saya, ialah SERANGAN KHAS…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Oh ya, aspek terbaiknya, pada pendapat\n"
	.string "saya, ialah PERTAHANAN KHAS…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Oh ya, aspek terbaiknya, pada\n"
	.string "pendapat saya, ialah KELAJUAN…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Stat itu agak baik. …Hm…\n"
	.string "Begitulah penilaian saya.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Stat itu agak mengagumkan.\n"
	.string "…Hm… Begitulah penilaian saya.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "Stat itu cemerlang! …Hm…\n"
	.string "Begitulah penilaian saya.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "Sempurna! Tiada cacat celanya!\n"
	.string "…Hm… Begitulah penilaian saya.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "Apa? Kamu tak ada masa\n"
	.string "untuk nasihat saya?\p"
	.string "Kamu patut sentiasa rajin belajar\n"
	.string "daripada pengalaman orang tua!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Ya, apa lagi?\p"
	.string "Saya ada urusan yang perlu\n"
	.string "diselesaikan! Simpan untuk lain kali!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Ah, orang muda! Kamu ingin\n"
	.string "tahu kebolehan POKéMON kamu?\p"
	.string "Mari, mari! Biar saya\n"
	.string "tengok POKéMON kamu!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Saya memang pakar, tapi saya pun tak\n"
	.string "dapat menilai POKéMON yang belum\l"
	.string "menetas!\p"
	.string "Tunjukkan saya POKéMON!\n"
	.string "POKéMON yang saya mahu tengok!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "Dia kata POKéMON saya cemerlang!\n"
	.string "Berbaloi saya jaga ia baik-baik!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "Dia kata POKéMON saya cemerlang! Tapi\n"
	.string "saya tak buat apa-apa yang istimewa\l"
	.string "pun masa bela ia…$"

