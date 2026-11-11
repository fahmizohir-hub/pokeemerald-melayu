PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Saya tak nampak PULAU ILUSI hari ni…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Oh! Wah!\n"
	.string "Saya nampak PULAU ILUSI hari ni!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "PULAU ILUSI…\p"
	.string "Mesti ia kelihatan dan hilang\n"
	.string "ikut keadaan cuaca yang\l"
	.string "menghasilkan fatamorgana.\p"
	.string "Atau memang betul-betul\n"
	.string "muncul dan hilang?$"

