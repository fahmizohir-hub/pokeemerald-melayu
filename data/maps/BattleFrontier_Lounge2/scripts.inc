BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Helo! Kalau bab berita\n"
	.string "BATTLE FRONTIER, sayalah nombor satu.\p"
	.string "Kamu boleh panggil\n"
	.string "saya FRONTIER MANIAC.\p"
	.string "Sekadar nak pastikan, kamu\n"
	.string "ni JURULATIH, betul tak?\p"
	.string "Saya dengan senang hati akan kongsi\n"
	.string "berita paling hangat tentang\l"
	.string "BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Helo! Kamu singgah nak korek berita\n"
	.string "terbaru daripada saya? Oh, baiklah!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Macam mana? Macam mana? Macam mana?\p"
	.string "Mesti maklumat saya sangat\n"
	.string "berguna untuk kamu, kan?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Biar saya tengok…\p"
	.string "Nampaknya {STR_VAR_1} ialah\n"
	.string "tempat paling hangat sekarang.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Biar saya tengok…\p"
	.string "Nampaknya bahagian {STR_VAR_1} di\n"
	.string "BATTLE TOWER paling hangat sekarang.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Mesti kamu tak tahu ni!\p"
	.string "Salah seorang JURULATIH hebat yang\n"
	.string "SCOTT gelar FRONTIER BRAIN ada di sana.\p"
	.string "JURULATIH misteri yang digelar\n"
	.string "SALON MAIDEN yang mengendalikan\l"
	.string "tempat tu.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Kamu dah lawan SALON MAIDEN?\p"
	.string "Bila dia sedang menilai lawannya,\n"
	.string "katanya dia guna POKéMON ini:\p"
	.string "POKéMON PSI jenis PSIKIK, POKéMON\n"
	.string "GUNUNG BERAPI jenis API dan POKéMON\l"
	.string "TIDUR jenis NORMAL.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Kamu dah lawan SALON MAIDEN\n"
	.string "bila dia serius?\p"
	.string "Bila dia bertarung habis-habisan,\n"
	.string "katanya dia guna POKéMON ini:\p"
	.string "POKéMON EON jenis NAGA & PSIKIK,\n"
	.string "POKéMON GUNTUR jenis ELEKTRIK dan\l"
	.string "POKéMON TIDUR jenis NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Mesti kamu tak tahu ni!\p"
	.string "Salah seorang JURULATIH hebat yang\n"
	.string "SCOTT gelar FRONTIER BRAIN ada di sana.\p"
	.string "JURULATIH bergaya yang digelar\n"
	.string "DOME ACE yang mengendalikan tempat tu.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Kamu dah lawan DOME ACE?\p"
	.string "Bila dia pandang ringan lawannya,\n"
	.string "dia guna tiga POKéMON ini:\p"
	.string "POKéMON NAGA jenis NAGA & TERBANG,\n"
	.string "POKéMON IKAN LUMPUR jenis AIR & TANAH\l"
	.string "dan POKéMON NYALA jenis API & TERBANG.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Kamu dah lawan DOME ACE bila dia serius?\p"
	.string "Bila dia mempamerkan strateginya,\n"
	.string "dia guna tiga POKéMON ini:\p"
	.string "POKéMON EON jenis NAGA & TERBANG,\n"
	.string "POKéMON IKAN LUMPUR jenis AIR & TANAH\l"
	.string "dan POKéMON KAKI BESI jenis BESI &\l"
	.string "PSIKIK.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Mesti kamu tak tahu ni!\p"
	.string "Salah seorang JURULATIH hebat yang\n"
	.string "SCOTT gelar FRONTIER BRAIN ada di sana.\p"
	.string "JURULATIH pelik yang digelar\n"
	.string "FACTORY HEAD yang mengendalikan\l"
	.string "tempat tu.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Kamu dah lawan FACTORY HEAD?\p"
	.string "Biar saya fikir… Bila dia bertarung,\n"
	.string "dia cuma ambil tiga POKéMON sewa.\p"
	.string "Dia bertarung dalam keadaan yang\n"
	.string "lebih kurang sama dengan kamu.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Kamu dah lawan FACTORY HEAD\n"
	.string "bila dia serius?\p"
	.string "Bila dia bertarung bersungguh-sungguh\n"
	.string "pun, dia tetap ambil tiga POKéMON sewa.\p"
	.string "Dia bertarung dalam keadaan\n"
	.string "yang hampir sama dengan kamu.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Mesti kamu tak tahu ni!\p"
	.string "Salah seorang JURULATIH hebat yang\n"
	.string "SCOTT gelar FRONTIER BRAIN ada di sana.\p"
	.string "JURULATIH menakutkan yang digelar\n"
	.string "PIKE QUEEN yang mengendalikan tempat\l"
	.string "tu.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Kamu pernah lawan PIKE QUEEN?\p"
	.string "Bila angin dia baik, katanya\n"
	.string "dia guna tiga POKéMON ini:\p"
	.string "POKéMON ULAR TARING jenis RACUN,\n"
	.string "POKéMON KULAT jenis SERANGGA & BATU\l"
	.string "dan POKéMON LEMBUT jenis AIR.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Kamu dah lawan PIKE QUEEN\n"
	.string "bila dia serius?\p"
	.string "Bila dia betul-betul naik angin,\n"
	.string "katanya dia guna tiga POKéMON ini:\p"
	.string "POKéMON ULAR TARING jenis RACUN,\n"
	.string "POKéMON ULAR BESI jenis BESI & TANAH\l"
	.string "dan POKéMON GANAS jenis AIR & TERBANG.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Mesti kamu tak tahu ni!\p"
	.string "Salah seorang JURULATIH hebat yang\n"
	.string "SCOTT gelar FRONTIER BRAIN ada di sana.\p"
	.string "JURULATIH comel yang digelar\n"
	.string "ARENA TYCOON yang mengendalikan\l"
	.string "tempat tu.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Kamu pernah lawan ARENA TYCOON?\p"
	.string "Bila dia menilai kebolehan lawan,\n"
	.string "kononnya dia guna POKéMON ini:\p"
	.string "POKéMON TANDUK TUNGGAL jenis SERANGGA\n"
	.string "& LAWAN, POKéMON CAHAYA BULAN jenis\l"
	.string "GELAP dan POKéMON SALIN KULIT jenis\l"
	.string "SERANGGA & HANTU.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Kamu dah lawan ARENA TYCOON\n"
	.string "bila dia serius?\p"
	.string "Bila dia bertarung bersungguh-sungguh,\n"
	.string "kononnya dia guna POKéMON ini:\p"
	.string "POKéMON CAHAYA BULAN jenis GELAP,\n"
	.string "POKéMON BAYANG jenis HANTU & RACUN dan\l"
	.string "POKéMON CENDAWAN jenis RUMPUT & LAWAN.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Mesti kamu tak tahu ni!\p"
	.string "Salah seorang JURULATIH hebat yang\n"
	.string "SCOTT gelar FRONTIER BRAIN ada di sana.\p"
	.string "JURULATIH yang menyeramkan digelar\n"
	.string "PALACE MAVEN yang mengendalikan\l"
	.string "tempat tu.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Kamu pernah lawan PALACE MAVEN?\p"
	.string "Bila dia menguji semangat lawan,\n"
	.string "katanya dia guna POKéMON ini:\p"
	.string "POKéMON KELAWAR jenis RACUN & TERBANG,\n"
	.string "POKéMON MALAS jenis NORMAL dan\l"
	.string "POKéMON PENGANGKUT jenis AIR & AIS.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Kamu dah lawan PALACE MAVEN\n"
	.string "bila dia serius?\p"
	.string "Bila dia kerah seluruh kekuatannya,\n"
	.string "katanya dia guna POKéMON ini:\p"
	.string "POKéMON LEGENDA jenis API, POKéMON\n"
	.string "MALAS jenis NORMAL dan POKéMON AURORA\l"
	.string "jenis AIR.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Mesti kamu tak tahu ni!\p"
	.string "Salah seorang JURULATIH hebat yang\n"
	.string "SCOTT gelar FRONTIER BRAIN ada di sana.\p"
	.string "JURULATIH berapi-api yang digelar\n"
	.string "PYRAMID KING yang mengendalikan\l"
	.string "tempat tu.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Kamu pernah lawan PYRAMID KING?\p"
	.string "Bila dia menguji kekuatan lawan,\n"
	.string "nampaknya dia guna POKéMON ini:\p"
	.string "POKéMON PUNCAK BATU jenis BATU,\n"
	.string "POKéMON BONGKAH AIS jenis AIS dan\l"
	.string "POKéMON BESI jenis BESI.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Kamu dah lawan PYRAMID KING\n"
	.string "bila dia serius?\p"
	.string "Bila dia membara dengan kuasa panas,\n"
	.string "nampaknya dia guna POKéMON ini:\p"
	.string "POKéMON BEKU jenis AIS & TERBANG,\n"
	.string "POKéMON ELEKTRIK jenis ELEKTRIK &\l"
	.string "TERBANG dan POKéMON NYALA jenis API &\l"
	.string "TERBANG.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Memang ada beberapa tempat\n"
	.string "untuk masuk TARUNG GANDA.\p"
	.string "Tapi BILIK TARUNG GANDA di\n"
	.string "BATTLE TOWER tu, macam, asas!\p"
	.string "Di situlah kamu patut belajar cara\n"
	.string "TARUNG GANDA dimainkan di\l"
	.string "BATTLE FRONTIER ni.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Berhati-hati dalam pertarungan di sini.\p"
	.string "Saya dengar ada JURULATIH yang ada\n"
	.string "strategi khas untuk TARUNG GANDA.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Bila kamu dah yakin dan selesa dengan\n"
	.string "TARUNG GANDA di sini, cubalah cabar\l"
	.string "tempat lain yang menawarkan\l"
	.string "TARUNG GANDA.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Macam-macam JURULATIH\n"
	.string "berkumpul di SALUN TARUNG.\p"
	.string "Cuba bayangkan, kamu mungkin\n"
	.string "terserempak dengan kawan atau peminat\l"
	.string "kamu! Tengok betul-betul!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Kalau kamu bersama kawan, pergilah\n"
	.string "ke BILIK TARUNG MULTI LINK.\p"
	.string "Kalau kamu main dengan kawan yang\n"
	.string "kuat, bersedialah berdepan lawan yang\l"
	.string "hebat!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Hebatnya kuasa mengumpul berita!\n"
	.string "Guru saya memang tiada tandingan!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Hebatnya daya pemerhatian! Guru\n"
	.string "saya memang tiada tandingan!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Hebatnya daya pujukan! Guru\n"
	.string "saya memang tiada tandingan!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…Tempat apa ni? Saya takutlah…$"

