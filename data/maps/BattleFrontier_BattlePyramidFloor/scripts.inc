BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, LOCALID_NONE, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Ini mesej contoh.$"

gText_BattlePyramidConfirmRest::
	.string "Pengembaraan BATTLE PYRAMID kamu\n"
	.string "akan disimpan supaya boleh berhenti.\l"
	.string "Boleh?$"

gText_BattlePyramidConfirmRetire::
	.string "Kamu pasti mahu hentikan\n"
	.string "pengembaraan PYRAMID kamu?$"

BattlePyramid_Text_ExitHintUp1::
	.string "Pintu keluar tingkat ini ada di\n"
	.string "arah sana: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "Pintu keluar tingkat ini ada di\n"
	.string "arah sana: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "Pintu keluar tingkat ini ada di\n"
	.string "arah sana: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "Pintu keluar tingkat ini ada di\n"
	.string "arah sana: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "Pintu keluar di tingkat ini\n"
	.string "menghala ke {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "Pintu keluar di tingkat ini\n"
	.string "menghala ke {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "Pintu keluar di tingkat ini\n"
	.string "menghala ke {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "Pintu keluar di tingkat ini\n"
	.string "menghala ke {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "Pintu keluar ada\n"
	.string "di sebelah {UP_ARROW} sana.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "Pintu keluar ada\n"
	.string "di sebelah {LEFT_ARROW} sana.$"

BattlePyramid_Text_ExitHintRight3::
	.string "Pintu keluar ada\n"
	.string "di sebelah {RIGHT_ARROW} sana.$"

BattlePyramid_Text_ExitHintDown3::
	.string "Pintu keluar ada\n"
	.string "di sebelah {DOWN_ARROW} sana.$"

BattlePyramid_Text_ExitHintUp4::
	.string "Di tingkat ini, pintu keluar ada di\n"
	.string "suatu tempat ke arah {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "Di tingkat ini, pintu keluar ada di\n"
	.string "suatu tempat ke arah {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "Di tingkat ini, pintu keluar ada di\n"
	.string "suatu tempat ke arah {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "Di tingkat ini, pintu keluar ada di\n"
	.string "suatu tempat ke arah {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "Pintu keluar?\n"
	.string "Ikut arah {UP_ARROW} tu.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "Pintu keluar?\n"
	.string "Ikut arah {LEFT_ARROW} tu.$"

BattlePyramid_Text_ExitHintRight5::
	.string "Pintu keluar?\n"
	.string "Ikut arah {RIGHT_ARROW} tu.$"

BattlePyramid_Text_ExitHintDown5::
	.string "Pintu keluar?\n"
	.string "Ikut arah {DOWN_ARROW} tu.$"

BattlePyramid_Text_ExitHintUp6::
	.string "Kebetulan, pintu keluar ada\n"
	.string "ke arah {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "Kebetulan, pintu keluar ada\n"
	.string "ke arah {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "Kebetulan, pintu keluar ada\n"
	.string "ke arah {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "Kebetulan, pintu keluar ada\n"
	.string "ke arah {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Kamu sedang cari barang?\p"
	.string "Ada lapan barang lagi yang\n"
	.string "belum dijumpai.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Kamu sedang cari barang?\p"
	.string "Ada tujuh barang lagi yang\n"
	.string "belum dijumpai.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Kamu sedang cari barang?\p"
	.string "Ada enam barang lagi yang\n"
	.string "belum dijumpai.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Kamu sedang cari barang?\p"
	.string "Ada lima barang lagi yang\n"
	.string "belum dijumpai.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Kamu sedang cari barang?\p"
	.string "Ada empat barang lagi yang\n"
	.string "belum dijumpai.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Kamu sedang cari barang?\p"
	.string "Ada tiga barang lagi yang\n"
	.string "belum dijumpai.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Kamu sedang cari barang?\p"
	.string "Ada dua barang lagi yang\n"
	.string "belum dijumpai.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Kamu sedang cari barang?\p"
	.string "Ada satu barang lagi yang\n"
	.string "belum dijumpai.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Kamu sedang cari barang?\p"
	.string "Dah tiada apa-apa lagi yang\n"
	.string "boleh dijumpai!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Sebab kamu menang, saya beritahu\n"
	.string "satu rahsia kecil!\p"
	.string "Ada lapan barang\n"
	.string "bertaburan di sini.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Sebab kamu menang, saya beritahu\n"
	.string "satu rahsia kecil!\p"
	.string "Ada tujuh barang lagi\n"
	.string "bertaburan di sini.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Sebab kamu menang, saya beritahu\n"
	.string "satu rahsia kecil!\p"
	.string "Ada enam barang lagi\n"
	.string "bertaburan di sini.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Sebab kamu menang, saya beritahu\n"
	.string "satu rahsia kecil!\p"
	.string "Ada lima barang lagi\n"
	.string "bertaburan di sini.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Sebab kamu menang, saya beritahu\n"
	.string "satu rahsia kecil!\p"
	.string "Ada empat barang lagi\n"
	.string "bertaburan di sini.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Sebab kamu menang, saya beritahu\n"
	.string "satu rahsia kecil!\p"
	.string "Ada tiga barang lagi\n"
	.string "bertaburan di sini.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Sebab kamu menang, saya beritahu\n"
	.string "satu rahsia kecil!\p"
	.string "Ada dua barang lagi\n"
	.string "bertaburan di sini.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Sebab kamu menang, saya beritahu\n"
	.string "satu rahsia kecil!\p"
	.string "Cuma ada satu barang\n"
	.string "bertaburan di sini.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Sebab kamu menang, saya beritahu\n"
	.string "satu rahsia kecil!\p"
	.string "Dah tiada apa-apa lagi\n"
	.string "bertaburan di sini.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Macam mana stok barang kamu?\p"
	.string "Rasanya ada lapan barang lagi\n"
	.string "menunggu dijumpai di tingkat ini.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Macam mana stok barang kamu?\p"
	.string "Rasanya ada tujuh barang lagi\n"
	.string "menunggu dijumpai di tingkat ini.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Macam mana stok barang kamu?\p"
	.string "Rasanya ada enam barang lagi\n"
	.string "menunggu dijumpai di tingkat ini.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Macam mana stok barang kamu?\p"
	.string "Rasanya ada lima barang lagi\n"
	.string "menunggu dijumpai di tingkat ini.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Macam mana stok barang kamu?\p"
	.string "Rasanya ada empat barang lagi\n"
	.string "menunggu dijumpai di tingkat ini.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Macam mana stok barang kamu?\p"
	.string "Rasanya ada tiga barang lagi\n"
	.string "menunggu dijumpai di tingkat ini.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Macam mana stok barang kamu?\p"
	.string "Rasanya ada dua barang lagi\n"
	.string "menunggu dijumpai di tingkat ini.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Macam mana stok barang kamu?\p"
	.string "Rasanya cuma ada satu barang lagi\n"
	.string "menunggu dijumpai di tingkat ini.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Macam mana stok barang kamu?\p"
	.string "Rasanya dah tiada barang lagi\n"
	.string "menunggu dijumpai di tingkat ini.\l"
	.string "Jaga diri, ya!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Kamu kuat, jadi kamu layak dapat\n"
	.string "satu petunjuk!\p"
	.string "Nampaknya ada lapan lagi\n"
	.string "barang di atas lantai.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Kamu kuat, jadi kamu layak dapat\n"
	.string "satu petunjuk!\p"
	.string "Nampaknya ada tujuh lagi\n"
	.string "barang di atas lantai.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Kamu kuat, jadi kamu layak dapat\n"
	.string "satu petunjuk!\p"
	.string "Nampaknya ada enam lagi\n"
	.string "barang di atas lantai.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Kamu kuat, jadi kamu layak dapat\n"
	.string "satu petunjuk!\p"
	.string "Nampaknya ada lima lagi\n"
	.string "barang di atas lantai.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Kamu kuat, jadi kamu layak dapat\n"
	.string "satu petunjuk!\p"
	.string "Nampaknya ada empat lagi\n"
	.string "barang di atas lantai.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Kamu kuat, jadi kamu layak dapat\n"
	.string "satu petunjuk!\p"
	.string "Nampaknya ada tiga lagi\n"
	.string "barang di atas lantai.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Kamu kuat, jadi kamu layak dapat\n"
	.string "satu petunjuk!\p"
	.string "Nampaknya ada dua lagi\n"
	.string "barang di atas lantai.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Kamu kuat, jadi kamu layak dapat\n"
	.string "satu petunjuk!\p"
	.string "Nampaknya cuma ada satu lagi\n"
	.string "barang di atas lantai.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Kamu kuat, jadi kamu layak dapat\n"
	.string "satu petunjuk!\p"
	.string "Nampaknya dah tiada lagi\n"
	.string "barang di atas lantai.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "Di tingkat PYRAMID ini,\n"
	.string "katanya ada lapan barang…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "Di tingkat PYRAMID ini,\n"
	.string "katanya ada tujuh barang…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "Di tingkat PYRAMID ini,\n"
	.string "katanya ada enam barang…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "Di tingkat PYRAMID ini,\n"
	.string "katanya ada lima barang…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "Di tingkat PYRAMID ini,\n"
	.string "katanya ada empat barang…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "Di tingkat PYRAMID ini,\n"
	.string "katanya ada tiga barang…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "Di tingkat PYRAMID ini,\n"
	.string "katanya ada dua barang…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "Di tingkat PYRAMID ini,\n"
	.string "katanya ada satu barang…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "Di tingkat PYRAMID ini,\n"
	.string "katanya tiada barang…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Kamu ada kumpul barang?\p"
	.string "Saya rasa ada lapan lagi\n"
	.string "barang di tingkat ini.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Kamu ada kumpul barang?\p"
	.string "Saya rasa ada tujuh lagi\n"
	.string "barang di tingkat ini.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Kamu ada kumpul barang?\p"
	.string "Saya rasa ada enam lagi\n"
	.string "barang di tingkat ini.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Kamu ada kumpul barang?\p"
	.string "Saya rasa ada lima lagi\n"
	.string "barang di tingkat ini.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Kamu ada kumpul barang?\p"
	.string "Saya rasa ada empat lagi\n"
	.string "barang di tingkat ini.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Kamu ada kumpul barang?\p"
	.string "Saya rasa ada tiga lagi\n"
	.string "barang di tingkat ini.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Kamu ada kumpul barang?\p"
	.string "Saya rasa ada dua lagi\n"
	.string "barang di tingkat ini.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Kamu ada kumpul barang?\p"
	.string "Saya rasa ada satu lagi\n"
	.string "barang di tingkat ini.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Kamu ada kumpul barang?\p"
	.string "Saya rasa dah tiada lagi\n"
	.string "barang di tingkat ini.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Kamu memang hebat!\p"
	.string "Tapi masih ada tujuh JURULATIH\n"
	.string "hebat selain saya!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Kamu memang hebat!\p"
	.string "Tapi masih ada enam JURULATIH\n"
	.string "hebat selain saya!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Kamu memang hebat!\p"
	.string "Tapi masih ada lima JURULATIH\n"
	.string "hebat selain saya!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Kamu memang hebat!\p"
	.string "Tapi masih ada empat JURULATIH\n"
	.string "hebat selain saya!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Kamu memang hebat!\p"
	.string "Tapi masih ada tiga JURULATIH\n"
	.string "hebat selain saya!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Kamu memang hebat!\p"
	.string "Tapi masih ada dua JURULATIH\n"
	.string "hebat selain saya!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Kamu memang hebat!\p"
	.string "Tapi masih ada seorang JURULATIH\n"
	.string "hebat selain saya!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Kamu memang hebat!\p"
	.string "Dah tiada sesiapa lagi yang\n"
	.string "boleh kalahkan kamu!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "Geramnya saya!\p"
	.string "Tapi ada tujuh JURULATIH lagi!\n"
	.string "Akan ada yang tundukkan kamu!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "Geramnya saya!\p"
	.string "Tapi ada enam JURULATIH lagi!\n"
	.string "Akan ada yang tundukkan kamu!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "Geramnya saya!\p"
	.string "Tapi ada lima JURULATIH lagi!\n"
	.string "Akan ada yang tundukkan kamu!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "Geramnya saya!\p"
	.string "Tapi ada empat JURULATIH lagi!\n"
	.string "Akan ada yang tundukkan kamu!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "Geramnya saya!\p"
	.string "Tapi ada tiga JURULATIH lagi!\n"
	.string "Akan ada yang tundukkan kamu!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "Geramnya saya!\p"
	.string "Tapi ada dua JURULATIH lagi!\n"
	.string "Akan ada yang tundukkan kamu!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "Geramnya saya!\p"
	.string "Tapi masih ada seorang JURULATIH!\n"
	.string "Pasti kamu akan ditundukkan!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "Geramnya saya!\p"
	.string "Tapi dah tiada JURULATIH lagi\n"
	.string "yang boleh lawan kamu!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Boleh tahan hebat kamu!\p"
	.string "Tapi ada tujuh lagi JURULATIH di\n"
	.string "tingkat ini. Boleh kalahkan semua?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Boleh tahan hebat kamu!\p"
	.string "Tapi ada enam lagi JURULATIH di\n"
	.string "tingkat ini. Boleh kalahkan semua?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "Boleh tahan hebat kamu!\p"
	.string "Tapi ada lima lagi JURULATIH di\n"
	.string "tingkat ini. Boleh kalahkan semua?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "Boleh tahan hebat kamu!\p"
	.string "Tapi ada empat lagi JURULATIH di\n"
	.string "tingkat ini. Boleh kalahkan semua?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "Boleh tahan hebat kamu!\p"
	.string "Tapi ada tiga lagi JURULATIH di\n"
	.string "tingkat ini. Boleh kalahkan semua?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Boleh tahan hebat kamu!\p"
	.string "Tapi ada dua lagi JURULATIH di\n"
	.string "tingkat ini. Boleh kalahkan kedua-dua?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Boleh tahan hebat kamu!\p"
	.string "Tapi masih ada seorang lagi JURULATIH\n"
	.string "di tingkat ini. Boleh kamu menang?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "Boleh tahan hebat kamu!\p"
	.string "Kamu dah tewaskan semua JURULATIH\n"
	.string "di tingkat ini.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Mungkin kamu boleh sapu bersih\n"
	.string "tujuh JURULATIH yang tinggal di sini.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Mungkin kamu boleh sapu bersih\n"
	.string "enam JURULATIH yang tinggal di sini.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Mungkin kamu boleh sapu bersih\n"
	.string "lima JURULATIH yang tinggal di sini.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Mungkin kamu boleh sapu bersih\n"
	.string "empat JURULATIH yang tinggal di sini.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Mungkin kamu boleh sapu bersih\n"
	.string "tiga JURULATIH yang tinggal di sini.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Mungkin kamu boleh sapu bersih\n"
	.string "dua JURULATIH yang tinggal di sini.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Mungkin kamu boleh sapu bersih\n"
	.string "dengan JURULATIH terakhir di sini.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Dah tiada sesiapa lagi yang boleh\n"
	.string "kalahkan kamu sekarang…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Mungkin kamu mampu tewaskan\n"
	.string "tujuh JURULATIH pakar yang tinggal.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Mungkin kamu mampu tewaskan\n"
	.string "enam JURULATIH pakar yang tinggal.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Mungkin kamu mampu tewaskan\n"
	.string "lima JURULATIH pakar yang tinggal.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Mungkin kamu mampu tewaskan\n"
	.string "empat JURULATIH pakar yang tinggal.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Mungkin kamu mampu tewaskan\n"
	.string "tiga JURULATIH pakar yang tinggal.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Mungkin kamu mampu tewaskan\n"
	.string "dua JURULATIH pakar yang tinggal.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Mungkin kamu mampu tewaskan\n"
	.string "seorang JURULATIH pakar yang tinggal.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Kemahiran kamu tiada tolok bandingnya.\p"
	.string "Tiada lagi JURULATIH di sini\n"
	.string "yang mampu kalahkan kamu.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Boleh kamu terus menang menentang\n"
	.string "tujuh JURULATIH yang tinggal?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Boleh kamu terus menang menentang\n"
	.string "enam JURULATIH yang tinggal?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Boleh kamu terus menang menentang\n"
	.string "lima JURULATIH yang tinggal?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Boleh kamu terus menang menentang\n"
	.string "empat JURULATIH yang tinggal?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Boleh kamu terus menang menentang\n"
	.string "tiga JURULATIH yang tinggal?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Boleh kamu terus menang menentang\n"
	.string "dua JURULATIH yang tinggal?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Boleh kamu terus menang menentang\n"
	.string "JURULATIH terakhir yang tinggal?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Dah tiada JURULATIH yang boleh\n"
	.string "lawan kamu sekarang…$"
