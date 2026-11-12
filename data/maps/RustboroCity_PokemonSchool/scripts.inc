RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applywaitmovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applywaitmovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Di papan hitam ada senarai perubahan\n"
	.string "status yang boleh menjejaskan POKéMON\l"
	.string "semasa bertarung.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Topik mana yang kamu nak baca?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Kalau POKéMON keracunan, HPnya akan\n"
	.string "berkurang sedikit demi sedikit.\p"
	.string "Kesan racun kekal selepas pertarungan.\p"
	.string "HP POKéMON yang keracunan akan terus\n"
	.string "susut semasa berjalan.\p"
	.string "Ubati racun dengan PENAWAR RACUN.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Kalau POKéMON lumpuh, KELAJUANNYA\n"
	.string "akan turun.\p"
	.string "Ia juga mungkin tak boleh bergerak\n"
	.string "semasa bertarung.\p"
	.string "Lumpuh kekal selepas pertarungan.\n"
	.string "Pulihkan dengan UBAT LUMPUH.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Kalau POKéMON tertidur, ia tak\n"
	.string "boleh menyerang.\p"
	.string "POKéMON mungkin terjaga sendiri, tapi\n"
	.string "kalau pertarungan tamat semasa ia\l"
	.string "tidur, ia akan terus tidur.\p"
	.string "Kejutkan ia dengan UBAT SEDAR.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Terbakar mengurangkan kuasa SERANGAN,\n"
	.string "dan HP mangsa akan berkurang sedikit\l"
	.string "demi sedikit.\p"
	.string "Terbakar kekal selepas pertarungan.\n"
	.string "Pulihkan dengan UBAT LECUR.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Kalau POKéMON membeku, ia langsung tak\n"
	.string "berdaya.\p"
	.string "Ia akan kekal beku selepas\n"
	.string "pertarungan. Cairkan dengan UBAT BEKU.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Murid yang tak belajar akan rasa sikit\n"
	.string "KUKU PANTAS saya.\p"
	.string "Murid yang baik atau tak, boleh nampak\n"
	.string "dari cara kamu guna barang ni.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "POKéMON yang memegang KUKU PANTAS\n"
	.string "kadang-kadang dapat bergerak dulu\l"
	.string "sebelum lawannya.\p"
	.string "Ada banyak lagi barang yang dibuat\n"
	.string "untuk dipegang POKéMON.\p"
	.string "Barang-barang tu saja pun dah banyak\n"
	.string "topik untuk dikaji!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Saya tengah tukar POKéMON dengan\n"
	.string "kawan saya sekarang.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Dah lama saya nak SEEDOT, dan akhirnya\n"
	.string "dapat juga!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "POKéMON boleh pegang barang, tapi\n"
	.string "mereka tak tahu guna barang buatan\l"
	.string "manusia macam POSYEN dan\l"
	.string "PENAWAR RACUN.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Kamu tahu ada move POKéMON yang boleh\n"
	.string "buat POKéMON keliru?\p"
	.string "POKéMON yang keliru kadang-kadang\n"
	.string "akan serang diri sendiri tanpa sengaja.\p"
	.string "Tapi bila keluar dari pertarungan, ia\n"
	.string "akan pulih seperti biasa.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "POKéMON yang memegang BERI akan\n"
	.string "pulihkan dirinya…\p"
	.string "Ada banyak jenis barang yang boleh\n"
	.string "dipegang POKéMON…\p"
	.string "Aduh, susahnya nak salin nota…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Ini buku nota murid ni…\p"
	.string "POKéMON ditangkap menggunakan POKé\n"
	.string "BALL.\p"
	.string "Sehingga enam POKéMON boleh menemani\n"
	.string "seorang JURULATIH.\p"
	.string "JURULATIH ialah orang yang menangkap\n"
	.string "POKéMON, membesarkannya, dan\l"
	.string "bertarung bersamanya.\p"
	.string "Misi JURULATIH ialah mengalahkan\n"
	.string "JURULATIH kuat yang menanti pencabar\l"
	.string "di GIM POKéMON.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Helo? Kita pernah jumpa, kan? Rasanya\n"
	.string "di BANDAR PETALBURG.\p"
	.string "Biar saya perkenalkan diri. Nama\n"
	.string "saya SCOTT.\p"
	.string "Saya mengembara ke merata tempat\n"
	.string "mencari JURULATIH yang hebat.\p"
	.string "Lebih tepat lagi, saya mencari pakar\n"
	.string "pertarungan POKéMON.\p"
	.string "Jadi, kamu buat apa di SEKOLAH ni? Kamu\n"
	.string "pun JURULATIH?\p"
	.string "Benda pertama yang patut kamu buat,\n"
	.string "ajar POKéMON kamu POTONG.\p"
	.string "Kalau tak silap saya, ada orang di\n"
	.string "bandar ni yang ada POTONG.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hmm…\p"
	.string "Tahap bakat murid-murid di sini belum\n"
	.string "diketahui. Tapi potensinya ada.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: Oh, apa tu?\p"
	.string "Itu LENCANA BATU, kan? Boleh tahan\n"
	.string "hebat tu.\p"
	.string "Tapi saya teringin juga nak tengok\n"
	.string "kamu bertarung.\p"
	.string "Susah nak tahu kamu JURULATIH yang\n"
	.string "macam mana hanya dari LENCANA LIGA.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Helo? Kita pernah jumpa, kan? Rasanya\n"
	.string "di BANDAR PETALBURG.\p"
	.string "Biar saya perkenalkan diri. Nama\n"
	.string "saya SCOTT.\p"
	.string "Saya mengembara ke merata tempat\n"
	.string "mencari JURULATIH yang hebat.\p"
	.string "Lebih tepat lagi, saya mencari pakar\n"
	.string "pertarungan POKéMON.\p"
	.string "Oh, apa tu? Itu LENCANA BATU, kan?\p"
	.string "Boleh tahan hebat untuk JURULATIH\n"
	.string "baru macam kamu.\p"
	.string "Tapi saya teringin juga nak tengok\n"
	.string "kamu bertarung.\p"
	.string "Susah nak tahu kamu JURULATIH yang\n"
	.string "macam mana hanya dari LENCANA LIGA.$"

