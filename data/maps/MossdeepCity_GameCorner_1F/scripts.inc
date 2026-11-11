MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Masa muda dulu, saya mengembara ke\n"
	.string "seluruh dunia sebagai JURULATIH\l"
	.string "POKéMON.\p"
	.string "Sekarang saya dah tua, satu-satunya\n"
	.string "hiburan saya ialah tengok JURULATIH\l"
	.string "muda bertarung.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "Pintu ni nampaknya berkunci.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Seorang JURULATIH bernama {STR_VAR_1}\n"
	.string "sedang melawat rumah saya.\p"
	.string "Kamu nak cabar {STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Kamu tak nak bertarung? Kecewa saya\n"
	.string "tak dapat tengok kamu bertarung…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, bagus, bagus!\p"
	.string "Tapi rumah saya ni tak berapa kukuh.\p"
	.string "Boleh tak kamu bertarung\n"
	.string "3 lawan 3 saja?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Sebelum kamu berdua bertarung, kamu\n"
	.string "patut simpan permainan dulu.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "Saya harap dapat tengok perlawanan\n"
	.string "yang bagus!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Jadi, keputusannya seri.\p"
	.string "Perlawanan yang hebat, kedua-dua pihak\n"
	.string "tak berganjak walau selangkah!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "Hebat sungguh!\p"
	.string "Macam tengok diri saya masa muda dulu!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, sayang sekali!\p"
	.string "Tapi perlawanan tadi bagus.\n"
	.string "Saya harap kamu menang lain kali.$"
