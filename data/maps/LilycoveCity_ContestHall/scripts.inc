@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applywaitmovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "POKéMON ni pernah menang\n"
	.string "PERTANDINGAN KECANTIKAN di sini dulu.\p"
	.string "Dan tahu tak? Hari ni,\n"
	.string "saya bawa ia menang\l"
	.string "PERTANDINGAN KEBIJAKSANAAN pula!\p"
	.string "Saya sendiri pun takut\n"
	.string "dengan kehebatan saya…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Saya dah masuk banyak PERTANDINGAN,\n"
	.string "jadi saya mula faham cara ia berjalan.\p"
	.string "Kalau kamu masuk\n"
	.string "PERTANDINGAN KESEGAKAN, move\l"
	.string "segak memang mudah memikat.\p"
	.string "Tapi move bijak dan move comel\n"
	.string "pula, contohnya, kurang menjadi.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Pemuda yang menang tadi ada banyak\n"
	.string "jenis {POKEBLOCK} yang berlainan.\p"
	.string "Boleh menang ke kalau ada sebanyak tu?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Wah, besarnya tempat ni!\p"
	.string "Suasana tegang ni… Tak sama macam\n"
	.string "dewan PERTANDINGAN di kampung.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "PENGACARA: Baiklah, POKéMON BIJAK\n"
	.string "dan JURULATIH mereka, dah sedia?!\p"
	.string "Tunjukkan persembahan\n"
	.string "terbaik! Ayuh, pikat mereka!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "HAKIM: Kamu seronok dengan\n"
	.string "PERTANDINGAN ni?\p"
	.string "Datanglah lagi dengan tiga orang kawan,\n"
	.string "dan kamu semua boleh masuk\l"
	.string "PERTANDINGAN!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Alamak…\n"
	.string "Saya masuk PERTANDINGAN yang salah.\p"
	.string "Saya masukkan POKéMON tegap ni dalam\n"
	.string "PERTANDINGAN KEBIJAKSANAAN…\p"
	.string "Ayuh, kagumkan mereka dengan HANCUR\n"
	.string "BATU yang nampak bijak.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Bertahun-tahun saya habiskan,\n"
	.string "dengan segala ilmu saya, untuk\l"
	.string "latih POKéMON ni jadi bijak.\p"
	.string "Ia takkan mudah dikalahkan\n"
	.string "oleh POKéMON budak mentah.\p"
	.string "Isteriku sayang, awak nampak tak ni?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Itu dia!\p"
	.string "Kalau POKéMON saya buat move bijak\n"
	.string "lepas ni, penonton pasti bersorak\l"
	.string "habis!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Alamak, tidak!\p"
	.string "HISAPAN DARAH ZUBAT kesayangan saya\n"
	.string "comel sangat, jadi saya guna\l"
	.string "berkali-kali!\p"
	.string "Tapi orang-orang jahat ni langsung tak\n"
	.string "menghargainya!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kyaaa! Atuk nampak cantik!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Walaupun JURULATIH masukkan POKéMON\n"
	.string "yang sama, mereka semua guna move yang\l"
	.string "berbeza untuk memikat.\p"
	.string "Sama macam setiap orang ada gaya\n"
	.string "bertarung masing-masing.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Saya rasa POKéMON nampak lebih bijak\n"
	.string "daripada JURULATIH mereka. Jauh lebih\l"
	.string "bijak.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Apa pun, saya tetap suka PERTANDINGAN\n"
	.string "KEBIJAKSANAAN.\p"
	.string "Warna hijau yang intelek tu…\n"
	.string "Sungguh… Sungguh… Segak.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "PENGACARA: Kamu pun masuk\n"
	.string "PERTANDINGAN KECANTIKAN? Semoga\l"
	.string "berjaya!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "HAKIM: Ah, setiap POKéMON di sini\n"
	.string "lambang kecantikan yang murni!\p"
	.string "Hampir saya terlupa nak beri markah!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "POKéMON secantik ni…\n"
	.string "Tiada yang lain macam dia.\p"
	.string "Mata semua orang pasti terpaku pada\n"
	.string "kecantikan saya.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaa!\p"
	.string "Saya sikat dan rapikan POKéMON saya\n"
	.string "dengan teliti untuk PERTANDINGAN ni…\p"
	.string "Tapi saya terlebih buat…\n"
	.string "Bulu POKéMON saya jadi kusut-masai…\p"
	.string "Apa saya nak buat ni?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "SINAR AURORA ni terlalu menyilaukan,\n"
	.string "sampai HAKIM pun tak boleh nampak.\p"
	.string "Eh, tunggu sekejap…\n"
	.string "Kalau macam tu, tak ada gunanya!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "POKéMON cantik ni sebiji macam saya\n"
	.string "masa muda dulu.\p"
	.string "Sebaik saja saya cakap macam tu, suami\n"
	.string "saya tersembur kopi yang dia minum.\p"
	.string "Saya ada cakap benda kelakar ke?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Kamu tahu, kalau saya menang\n"
	.string "PERTANDINGAN KECANTIKAN, memang saya\l"
	.string "gembira. Lebih daripada biasa.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah!\p"
	.string "Tengoklah semua POKéMON cantik tu!\n"
	.string "Saya memang suka kemeriahan macam ni!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Kamu tak boleh selalu menang dengan\n"
	.string "kecantikan saja.\p"
	.string "Kamu kena rapikan POKéMON kamu supaya\n"
	.string "ia cantik berkilat macam POKéMON saya.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "PENGACARA: Alamak! Helo!\n"
	.string "Kami tengah adakan PERTANDINGAN!\p"
	.string "Sila daftar di kaunter pendaftaran kami\n"
	.string "dulu, ya?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "HAKIM: Oh, pikatan yang\n"
	.string "menawan dan comel sekali!\p"
	.string "Ya ampun! Pikatan MAIN AIR\n"
	.string "yang sungguh comel!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Alamak… AZURILL kesayangan saya\n"
	.string "terganggu dengan POKéMON lain.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "POKéMON saya tak pernah menang\n"
	.string "pertarungan, tapi dalam PERTANDINGAN,\l"
	.string "jaga-jaga!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "TARIAN KELOPAK POKéMON saya sungguh\n"
	.string "anggun dan menakjubkan.\p"
	.string "Saya takkan biar sesiapa ganggu\n"
	.string "persembahannya.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "POKéMON semua orang\n"
	.string "comel-comel belaka.\p"
	.string "Tapi, kalau POKéMON saya\n"
	.string "buat pikatan comel…\p"
	.string "Saya pasti ia jauh lebih\n"
	.string "comel daripada yang lain.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Anak saya masuk PERTANDINGAN ni.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Ayuh, sayang. Teruskan!\n"
	.string "POKéMON kamu yang terbaik!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Saya rasa budak perempuan di sana tu\n"
	.string "yang paling comel.\p"
	.string "Apa? Mereka menilai rupa POKéMON?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ohh, tengok semua POKéMON comel ni\n"
	.string "buat saya nak ada sendiri!\p"
	.string "Saya nak pergi tangkap!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "PENTAS PERTANDINGAN KECANTIKAN\n"
	.string "TERPESONA DENGAN POKéMON CANTIK!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "PENTAS PERTANDINGAN KECOMELAN\n"
	.string "TERPIKAT DENGAN POKéMON COMEL!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "PENTAS PERTANDINGAN KEBIJAKSANAAN\n"
	.string "KAGUM DENGAN POKéMON BIJAK!$"

