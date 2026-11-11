DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applywaitmovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applywaitmovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Apa yang tengah popular? Mestilah\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Tak dapat saya bayangkan hidup tanpa\n"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Apa yang tengah popular? Mestilah\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Tapi saya dah mula bosan dengannya.\p"
	.string "Saya patut cari benda hangat yang\n"
	.string "seterusnya.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Saya sedang ajar POKéMON saya tentang\n"
	.string "“{STR_VAR_1},”\l"
	.string "tapi tak berapa menjadi.\p"
	.string "Rasanya macam berat sangat untuk dia.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Saya sedang mendalami trend terkini,\n"
	.string "“{STR_VAR_1}”.\p"
	.string "Betul ke ada kaitan yang mendalam\n"
	.string "antara “{STR_VAR_1}”\l"
	.string "dan “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Oh! Jadi, firasat saya betul!\p"
	.string "Saya selangkah lagi untuk jadi orang\n"
	.string "yang hip dan hangat, yahoo!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Apa?! Betul ke?!\p"
	.string "Bukan senang orang tua macam saya nak\n"
	.string "ikut trend!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Segala hal tentang\n"
	.string "“{STR_VAR_1}” ni…\l"
	.string "Ada rancangan TV tentangnya, kan?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Di seberang laut…\p"
	.string "Adakah “{STR_VAR_1}”\n"
	.string "lebih popular lagi?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Saya kumpul barangan rasmi berlesen\n"
	.string "“{STR_VAR_1}”.\p"
	.string "Saya ada PATUNG rasmi\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Pakaian jenama rasmi\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Dan buku bergambar berlesen rasmi\n"
	.string "“{STR_VAR_1}”.\p"
	.string "Hehe, semua saya punya! Saya takkan\n"
	.string "kongsi dengan kamu!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "MENGENAL PASTI\n"
	.string "“{STR_VAR_1}” BAIK &\l"
	.string "“{STR_VAR_1}” BURUK…\p"
	.string "KAITAN ANTARA\n"
	.string "“{STR_VAR_1}” DAN\l"
	.string "POKéMON…\p"
	.string "“{STR_VAR_1}”\n"
	.string "YANG BERGUNA…\p"
	.string "Rak ni penuh dengan buku tentang\n"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_TrendsScream:
	.string "Tajuknya “JERITAN\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "Tajuknya “SENYUMAN\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Tajuknya “{STR_VAR_1}\n"
	.string "YANG TERAKHIR”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Tajuknya “KELAHIRAN\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Saya nampak “{STR_VAR_1}”!\n"
	.string "Hebat, kan?\p"
	.string "Itulah benda paling hebat sekarang!\p"
	.string "Memang mengagumkan! Yang betul-betul\n"
	.string "asli, oh yeah!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Oh, tidak, tidak, tidak.\p"
	.string "Yang kononnya\n"
	.string "“{STR_VAR_1}”\l"
	.string "yang kamu nampak tu… bukan yang asli.\p"
	.string "Yang asli jauh lebih…\n"
	.string "Macam mana nak cakap, ya?\l"
	.string "Lebih tajam, tapi lebih lembut!\p"
	.string "Ah, tak mengapa. Memang menakjubkan!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Hei, dengar ni, saya cipta lagu tema\n"
	.string "untuk “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}”\n"
	.string "memang popular sekarang ni.\p"
	.string "Okey, dengar!\n"
	.string "… …\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Hebatnya\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "Maaf cakap, kawan, lebih baik kamu\n"
	.string "perbaiki nyanyian kamu dulu sebelum\l"
	.string "main-main dengan\l"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Apa-apa pun, macam saya cakap tadi,\n"
	.string "kita patut berkumpul dan anjurkan\l"
	.string "parti “{STR_VAR_1}”\l"
	.string "di pulau ni.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Oh, idea yang sungguh hebat!\p"
	.string "Ia akan tentukan sekali untuk\n"
	.string "selamanya siapa yang terbaik dalam\l"
	.string "“{STR_VAR_1}.”\l"
	.string "Bijak sungguh!\p"
	.string "Mulai hari ni, hidup kita akan berkisar\n"
	.string "tentang “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Tapi saya terfikir…\p"
	.string "Tidakkah kamu setuju yang\n"
	.string "“{STR_VAR_1}” dah\l"
	.string "berubah daripada sekadar trend\l"
	.string "kepada sebahagian hidup harian kita?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Maaf? Sampai macam tu sekali?\p"
	.string "Tapi memang betul\n"
	.string "“{STR_VAR_1}”\l"
	.string "sentiasa bermain di fikiran, sama ada\l"
	.string "kita berjaga atau tidur.\p"
	.string "Memang tak syak lagi, kamulah PROFESOR\n"
	.string "“{STR_VAR_1}”,\l"
	.string "kawan lamaku!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Kalau kamu dan saya bergabung,\n"
	.string "kita takkan dapat dikalahkan dalam\l"
	.string "semua hal “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Tepat sekali, kawan!\p"
	.string "Kita akan jadi DUO\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Hebat bunyinya, kan? Hahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Bagi saya, BOM TOKSIK sedang di puncak\n"
	.string "populariti. Itulah dia.\p"
	.string "Hah? Kamu kata kamu tak tahu tentang\n"
	.string "BOM TOKSIK?\p"
	.string "Kasihan betul. Saya beri kamu satu.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Saya suka BOM TOKSIK.\p"
	.string "Tapi POKéMON yang ada move\n"
	.string "“{STR_VAR_1}”\l"
	.string "pun tengah popular juga.$"

