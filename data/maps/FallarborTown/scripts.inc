FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Ada sesuatu yang tak kena,\n"
	.string "dan saya tak suka!\p"
	.string "Saya nampak orang mencurigakan keluar\n"
	.string "masuk rumah PROF. COZMO…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Kawasan ni terkenal dengan meteor\n"
	.string "sejak zaman dahulu lagi.\p"
	.string "Kata orang, LATA METEOR terbentuk\n"
	.string "akibat meteorit jatuh dulu-dulu.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Tengok! Tengok ni!\n"
	.string "Inilah AZURILL kesayangan saya!\p"
	.string "Licin, halus dan gebu pula tu!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Kamu dah cabar FLANNERY, KETUA\n"
	.string "GIM LAVARIDGE?\p"
	.string "Datuk budak tu memang terkenal.\n"
	.string "Dia pernah jadi salah seorang ELIT\l"
	.string "EMPAT dalam LIGA POKéMON dulu.\p"
	.string "Saya tak terkejut kalau FLANNERY\n"
	.string "jadi JURULATIH yang hebat dengan\l"
	.string "usahanya sendiri.$"

FallarborTown_Text_BattleTentSign:
	.string "KHEMAH BATTLE FALLARBOR\n"
	.string "“Tempat Pasukan Terhebat Berhimpun!”$"

FallarborTown_Text_TownSign:
	.string "PEKAN FALLARBOR\n"
	.string "“Komuniti tani dengan taman kecil.”$"

FallarborTown_Text_MoveTutorSign:
	.string "RUMAH GURU MOVE\n"
	.string "“Move baru diajar kepada POKéMON.”$"

