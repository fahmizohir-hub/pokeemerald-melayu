PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Orang kata mereka nampak POKéMON\n"
	.string "terbang tinggi di atas HOENN.\p"
	.string "Ia terbang sepanjang masa ke?\n"
	.string "Tak perlu rehat di mana-mana ke?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "POKéMON langit!\n"
	.string "POKéMON langit!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Kamu datang dari mana?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Ya?\n"
	.string "PEKAN YA?\p"
	.string "Tak pernah saya dengar tempat macam\n"
	.string "tu.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Tidak? Tak masuk akal.\n"
	.string "Kamu mesti datang dari suatu tempat.\p"
	.string "Oh! Nanti! Jangan cakap kamu lahir di\n"
	.string "dasar laut?$"

