LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Ya ampun! Mengembara seorang diri?\n"
	.string "Mudanya kamu! Bagus betul!\p"
	.string "Mesti anak-anak saya boleh belajar\n"
	.string "sesuatu daripada kamu!\p"
	.string "Saya? Saya pakar {POKEBLOCK}.\p"
	.string "Kalau saya serius sikit saja, saya boleh\n"
	.string "hasilkan {POKEBLOCK} yang hebat.\p"
	.string "Kamu nak belajar daripada saya, pakar\n"
	.string "{POKEBLOCK}?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Oh? Kamu pasti?\p"
	.string "Jangan selalu cuba buat semua benda\n"
	.string "seorang diri, sayang!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Oh, bagus! Kamu memang bijak!\n"
	.string "Penerangan ni agak panjang, jadi dengar\l"
	.string "baik-baik!\p"
	.string "Dah sedia?\p"
	.string "Kalau kamu tengok {POKEBLOCK}, kamu akan\n"
	.string "nampak ia dinilai ikut RASA.\p"
	.string "Makin rendah nilai RASA, makin bagus.\n"
	.string "Jangan lupa!\p"
	.string "{POKEBLOCK} yang bagus ada nilai RASA yang\n"
	.string "rendah dan tahap yang tinggi.\p"
	.string "POKéMON juga boleh makan lebih banyak\n"
	.string "{POKEBLOCK} bagus berbanding yang biasa.\p"
	.string "Dan ini penting.\p"
	.string "Kalau nak buat {POKEBLOCK} yang licin, guna\n"
	.string "BERRY yang berlainan jenis.\p"
	.string "Jangan kedekut, jenis BERRY yang\n"
	.string "diguna mempengaruhi kelicinan {POKEBLOCK}.\p"
	.string "Satu lagi.\p"
	.string "Makin ramai orang mengisar BERRY, makin\n"
	.string "licin {POKEBLOCK} yang dihasilkan.\p"
	.string "Sebab tu kamu patut ajak orang lain dan\n"
	.string "buat {POKEBLOCK} bersama-sama.\p"
	.string "Itu saja yang kamu perlu tahu untuk\n"
	.string "buat {POKEBLOCK} yang bagus.\p"
	.string "Kalau semua orang ada POKéMON yang\n"
	.string "disayangi, {POKEBLOCK} yang licin, dan\l"
	.string "keluarga yang penyayang, dunia akan\l"
	.string "jadi lebih bahagia.\p"
	.string "Jangan putus asa, sayang!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Bila isteri saya lahirkan anak kembar\n"
	.string "empat, memang saya terkejut.\p"
	.string "Tapi sekarang, tengok mereka bermain\n"
	.string "bersama, saya rasa gembira.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Kami tengah buat TARUNG MULTI, tapi\n"
	.string "saya tahu saya akan menang.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Kami suka campur-campur benda di SUDUT\n"
	.string "REKOD.\p"
	.string "Tapi apa sebenarnya yang bercampur?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Kami nak buat {POKEBLOCK} super dengan\n"
	.string "PENGISAR BERRY!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Saya nak tunjuk betapa tegapnya\n"
	.string "POKéMON saya, jadi kami nak masuk\l"
	.string "PERTANDINGAN bersama.$"

