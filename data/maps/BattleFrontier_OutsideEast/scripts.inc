BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applywaitmovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitse
	playse SE_SUDOWOODO_SHAKE
	applywaitmovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Inilah BATTLE TOWER!\n"
	.string "Kekalkan rentetan kemenangan sebagai\l"
	.string "JURULATIH terhandal!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Inilah BATTLE PALACE!\n"
	.string "Perhatikan pertarungan POKéMON!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Inilah BATTLE ARENA!\n"
	.string "Biar pasukan terkuat berkumpul!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Inilah BATTLE PYRAMID!\n"
	.string "Maralah dalam Misi Tarung!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "DEWAN KEDUDUKAN BATTLE FRONTIER\n"
	.string "Sasarkan rekod baru!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "KAUNTER PENUKARAN MATA TARUNG\n"
	.string "Tukarkan Mata Tarung kamu!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Wah! Besarnya!\p"
	.string "BATTLE TOWER ni terasa istimewa.\n"
	.string "Lain daripada yang lain.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Cita-cita besar saya ialah menakluk\n"
	.string "BATTLE FRONTIER dan juga\l"
	.string "LIGA POKéMON.\p"
	.string "Dan kalau impian saya jadi kenyataan…\p"
	.string "Saya… Saya nak tanya MIMI jiran\n"
	.string "sebelah, sudi tak dia berkawan dengan\l"
	.string "saya!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "BATTLE PYRAMID tu terlalu kejam!\n"
	.string "Saya tak dapat sampai ke puncak!\p"
	.string "Dah tak ada pilihan lain, mungkin\n"
	.string "saya boleh panjat dari luar…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Aku subur dalam kegelapan… Ya… Apa\n"
	.string "yang layak untukku? Tiada lain selain\l"
	.string "BATTLE PYRAMID…\p"
	.string "Apa kata kau mengembara dalam\n"
	.string "kegelapan, dalam keputusasaan yang\l"
	.string "mutlak?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Seminggu saya tak tidur, tapi akhirnya\n"
	.string "saya berjaya bentuk pasukan yang\l"
	.string "paling hebat!\p"
	.string "Saya tak nampak macam mana saya boleh\n"
	.string "kalah, betul ni. Kami akan serbu\l"
	.string "BATTLE ARENA!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "SCOTT bawa kamu ke sini juga?\n"
	.string "Apa kena dengan lelaki tu?\p"
	.string "Nampaknya dia memang pandai\n"
	.string "cari JURULATIH berbakat, tapi…\p"
	.string "Saya tak pernah sekali pun\n"
	.string "nampak dia bertarung sendiri.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG! Saya percaya pada\n"
	.string "kamu, kawan kecilku!\p"
	.string "Kalau kamu menang, saya buatkan apa\n"
	.string "saja makanan sedap kegemaran ZIGG\l"
	.string "kecil saya!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON nampak termenung kosong…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Orang kata saya ni suka jaga tepi\n"
	.string "kain orang, tapi saya tak boleh tahan.\p"
	.string "Topi kamu senget! Alamak, ada sampah\n"
	.string "atas tanah! Eh, dah nak waktu makan\l"
	.string "malam!\p"
	.string "Entahlah saya tahan ke tidak\n"
	.string "tengok saja di BATTLE PALACE…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Saya mungkin tak nampak hebat\n"
	.string "sekarang, tapi saya pernah kalahkan\l"
	.string "KETUA GIM.\p"
	.string "Siapa tahu, mungkin saya patut cuba\n"
	.string "sekali lagi untuk kegemilangan.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Saya laju atas BASIKAL, dan\n"
	.string "begitu juga cara saya bertarung.\p"
	.string "Saya menang perlawanan\n"
	.string "dalam sekelip mata!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Saya lebih hebat main\n"
	.string "POKéMON daripada ayah saya.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Pergilah, sayang ayah! Kumpul\n"
	.string "kemenangan banyak-banyak untuk Ayah!\p"
	.string "Kamu sebiji macam ibu kamu, jadi\n"
	.string "mesti kamu menguasai semuanya!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Bukan senang nak sampai ke sini, tapi\n"
	.string "saya dengar ada seorang gadis cantik\l"
	.string "menawan di BATTLE ARENA.\p"
	.string "Tapi kamu tahu apa yang saya jumpa?\p"
	.string "Sekumpulan ahli seni mempertahankan\n"
	.string "diri yang berpeluh, busuk dan kasar!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Kadang-kadang saya nampak seorang\n"
	.string "pakcik yang nampak penting masuk ke\l"
	.string "situ.\p"
	.string "POKéMON dia memang hebat-hebat.\n"
	.string "Tapi dia nampak baik orangnya.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Kamu tahu tak? Legenda\n"
	.string "BATTLE PYRAMID?\p"
	.string "Bila tiba seorang JURULATIH yakin yang\n"
	.string "menggapai puncak keemasan, maka akan\l"
	.string "muncul seorang wira antara wira.\p"
	.string "Tak tahu legenda tu? Mestilah\n"
	.string "tak tahu! Saya baru reka tadi!\p"
	.string "Apa maksudnya? Itu, kawan,\n"
	.string "saya tak boleh beritahu!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Aduhai! Aduh! Saya tak pernah\n"
	.string "kalah sekali pun sebelum ni!\p"
	.string "Tapi saya kena belasah teruk\n"
	.string "tanpa sebarang harapan!\p"
	.string "Lepas tu orang kata saya\n"
	.string "tak ada bakat?! Aduhai!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Lelaki ni terserempak dengan JURULATIH\n"
	.string "yang teramat kuat semasa cabaran\l"
	.string "BATTLE TOWER.\p"
	.string "Sekarang tengoklah dia…\p"
	.string "Kamu kena berhati-hati kalau\n"
	.string "nak pergi ke BATTLE TOWER.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Yes! Akhirnya Mata Tarung\n"
	.string "saya dah cukup!\p"
	.string "Saya rasa saya nak tukar dengan\n"
	.string "satu lagi PATUNG gebu gergasi!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Oh, ya, okey! Jadi inilah\n"
	.string "DEWAN KEDUDUKAN!\p"
	.string "Saya nak tercatat dalam sejarah\n"
	.string "sebagai juara hebat dan nama saya\l"
	.string "direkodkan di sini untuk generasi akan\l"
	.string "datang.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Dengan awak di sisi, saya\n"
	.string "boleh buat apa saja.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ooh, sayang, awak memang hebat!\p"
	.string "Ooh, saya dah tak sabar lagi!\p"
	.string "Jom pergi ke BILIK TARUNG MULTI\n"
	.string "sekarang juga!\p"
	.string "Kalau kita bergabung di SALUN TARUNG,\n"
	.string "kuasa cinta kita akan menewaskan\l"
	.string "semua yang kita jumpa.\p"
	.string "Wah, di depan kita, sayang, semuanya\n"
	.string "akan tumbang macam domino!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "BATTLE FRONTIER ni bukan khas\n"
	.string "untuk JURULATIH handal sahaja.\p"
	.string "Nampaknya ramai orang yang ada\n"
	.string "kebolehan istimewa turut dijemput.\p"
	.string "Lelaki bernama SCOTT tu…\p"
	.string "Mungkin dia bina tempat ni\n"
	.string "untuk tujuan yang lebih besar…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Maafkan saya, orang muda.\n"
	.string "Penglihatan kamu baik?\p"
	.string "Ada pokok pelik di hujung sana, dan\n"
	.string "pada mata tua saya ni, ia nampak macam\l"
	.string "bergoyang.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Maafkan saya, orang\n"
	.string "muda. Ingatan kamu baik?\p"
	.string "Saya rasa dulu pernah ada\n"
	.string "pokok pelik di hujung sana.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Sa… Saya nampak!\p"
	.string "Ada POKéMON yang macam melekit\n"
	.string "dengan ekor panjang di depan sana!\p"
	.string "Ia bersembunyi bawah batu\n"
	.string "besar, dan asyik merenung saya!$"
