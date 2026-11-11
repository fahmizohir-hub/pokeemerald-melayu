SeafloorCavern_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_OnResume
	.byte 0

SeafloorCavern_Entrance_OnResume:
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	end

SeafloorCavern_Entrance_EventScript_Grunt::
	lockall
	goto_if_eq VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1, SeafloorCavern_Entrance_EventScript_GruntSpeechShort
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_Delay48
	delay 20
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	copyobjectxytoperm LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterUp
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntSpeechShort::
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterUp
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast::
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest::
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterRight
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth::
	applywaitmovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterDown
	return

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep:
	.string "Hoi! Aku ingat muka kau!\p"
	.string "Kalau kau ada di sini, maknanya\n"
	.string "kau nak kacau kami lagi!\p"
	.string "Budak hingusan macam kau,\n"
	.string "ingat boleh lawan TEAM AQUA?\p"
	.string "Kau tu baru setahun jagung!\p"
	.string "Kau lebih sesuai dengan\n"
	.string "geng TEAM MAGMA!\p"
	.string "Cakap pasal TEAM MAGMA, aku dengar ada\n"
	.string "orang nampak mereka dekat MOSSDEEP.\p"
	.string "Gerombolan samseng tu memang\n"
	.string "tak sesuai langsung dekat laut!$"

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort:
	.string "Budak hingusan macam kau,\n"
	.string "ingat boleh lawan TEAM AQUA?\p"
	.string "Kau tu baru setahun jagung!\p"
	.string "Kau lebih sesuai dengan\n"
	.string "geng TEAM MAGMA!\p"
	.string "Cakap pasal TEAM MAGMA, aku dengar ada\n"
	.string "orang nampak mereka dekat MOSSDEEP.\p"
	.string "Gerombolan samseng tu memang\n"
	.string "tak sesuai langsung dekat laut!$"

