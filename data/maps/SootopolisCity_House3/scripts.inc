SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Kamu JURULATIH POKéMON, kan?\p"
	.string "JUAN dari SOOTOPOLIS ada ramai peminat.\n"
	.string "Lebih ramai daripada muridnya WALLACE!\p"
	.string "Kamu ada peminat?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, kalau begitu mesti kamu agak kuat.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Alahai…\n"
	.string "Sunyi sikit, ya.\p"
	.string "Cubalah berusaha lebih sikit untuk\n"
	.string "dapat peminat.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Peminat setia datang dari luar HOENN\n"
	.string "pun.\p"
	.string "Meriah betul masa saya pergi ke KELAB\n"
	.string "PEMINAT JURULATIH di LILYCOVE.$"

