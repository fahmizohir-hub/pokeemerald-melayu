MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "Adik lelaki saya kata dia suka pergi\n"
	.string "cari PANGKALAN RAHSIA orang.$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "Adik lelaki saya kata dia suka melawat\n"
	.string "PANGKALAN RAHSIA orang dan bertarung\l"
	.string "POKéMON.$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "Kamu ke yang buat PANGKALAN RAHSIA\n"
	.string "dekat {STR_VAR_1}?$"

MossdeepCity_House4_Text_MakeSecretBase:
	.string "Kamu patut buat PANGKALAN RAHSIA di\n"
	.string "mana-mana. Saya akan pergi cari!$"

MossdeepCity_House4_Text_Skitty:
	.string "SKITTY: Miyaan?$"

