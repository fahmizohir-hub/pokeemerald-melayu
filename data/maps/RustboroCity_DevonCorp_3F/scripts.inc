RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	delay 80
	applywaitmovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Saya ENCIK STONE, PRESIDEN\n"
	.string "DEVON CORPORATION.\p"
	.string "Saya baru dengar cerita pasal kamu!\p"
	.string "Kamu selamatkan staf kami bukan sekali,\n"
	.string "tapi dua kali!\p"
	.string "Saya ada satu permintaan untuk orang\n"
	.string "hebat macam kamu.\p"
	.string "Saya dengar kamu nak hantar bungkusan\n"
	.string "ke LIMBUNGAN SLATEPORT.\p"
	.string "Dalam perjalanan, boleh kamu singgah di\n"
	.string "PEKAN DEWFORD?\p"
	.string "Boleh tolong hantarkan SURAT kepada\n"
	.string "STEVEN di DEWFORD?$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "ENCIK STONE: Kamu patut tahu, saya ni\n"
	.string "PRESIDEN yang hebat.\p"
	.string "Jadi, saya takkan kedekut minta tolong\n"
	.string "tanpa balas apa-apa.\p"
	.string "Sebab tu saya nak kamu ambil ini!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} menerima POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "ENCIK STONE: Alat itu…\p"
	.string "Namanya NAVIGATOR POKéMON, atau\n"
	.string "ringkasnya POKéNAV.\p"
	.string "Alat ni wajib ada bagi setiap JURULATIH\n"
	.string "yang mengembara.\p"
	.string "Ada peta rantau HOENN di dalamnya.\p"
	.string "Kamu boleh semak lokasi DEWFORD dan\n"
	.string "SLATEPORT dengan mudah!\p"
	.string "Oh ya, saya dengar penjenayah durjana…\n"
	.string "MAGMA dan AQUA, rasanya… sedang buat\l"
	.string "kacau di merata tempat.\p"
	.string "Saya rasa lebih baik kamu berehat dulu\n"
	.string "sebelum teruskan perjalanan.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "ENCIK STONE: Baiklah, {PLAYER}{KUN},\n"
	.string "pergilah dengan berhati-hati!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "ENCIK STONE: Saya harapkan kamu!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "ENCIK STONE: Kamu dah hantar SURAT\n"
	.string "saya? Terima kasih banyak!\p"
	.string "Ini tanda terima kasih saya. Barang ni\n"
	.string "pasti berguna untuk JURULATIH\l"
	.string "macam kamu.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "ENCIK STONE: POKéMON yang memegang\n"
	.string "KONGSI EXP. akan dapat sebahagian Mata\l"
	.string "EXP dari pertarungan.\p"
	.string "Ia tetap dapat Mata EXP walaupun\n"
	.string "tak bertarung.\p"
	.string "Pada saya, KONGSI EXP. memang berguna\n"
	.string "untuk membesarkan POKéMON yang lemah.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "ENCIK STONE: Sejak muda, saya\n"
	.string "tenggelam dalam kerja.\p"
	.string "Sebab tu saya tak tahu sangat pasal\n"
	.string "trend dan benda-benda macam tu.\p"
	.string "Tapi betul ke semua orang muda\n"
	.string "sekarang nak jadi JURULATIH dalam\l"
	.string "LIGA POKéMON?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Ini tingkat tiga DEVON CORPORATION.\p"
	.string "PEJABAT PRESIDEN kami ada di\n"
	.string "tingkat ini.\p"
	.string "Apa-apa pun, saya betul-betul\n"
	.string "berterima kasih atas jasa kamu.\p"
	.string "Err… Oh ya, bungkusan yang kamu\n"
	.string "dapatkan balik tu…\p"
	.string "Boleh saya minta kamu hantar ke\n"
	.string "LIMBUNGAN di SLATEPORT?\p"
	.string "Teruk jadinya kalau perompak tu cuba\n"
	.string "curi lagi.\p"
	.string "Err… Hehehe, jadi, err, boleh saya\n"
	.string "harapkan kamu?\p"
	.string "Oh, ya. Boleh kamu tunggu sekejap\n"
	.string "di sini?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "PRESIDEN kami nak bercakap dengan\n"
	.string "kamu.\p"
	.string "Sila ikut saya.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Silakan masuk.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Kalau kamu ke LIMBUNGAN di SLATEPORT,\n"
	.string "pergilah jumpa KAPT. STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Produk baru DEVON, REPEAT BALL dan\n"
	.string "TIMER BALL, dah jadi sangat popular\l"
	.string "dalam kalangan JURULATIH.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Ini koleksi batu-batu nadir yang\n"
	.string "dikumpul oleh PRESIDEN.$"

