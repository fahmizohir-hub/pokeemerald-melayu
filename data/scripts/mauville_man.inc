MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hai, saya PENUKAR.\n"
	.string "Nak tukar barang hiasan dengan saya?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"
	.string "Kamu buat saya rasa sedih…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Tapi kita dah pun bertukar barang\n"
	.string "hiasan, kamu dan saya.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Kalau ada barang hiasan saya yang kamu\n"
	.string "berkenan, cakap saja.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Kamu tak nak apa-apa?\n"
	.string "Rasa macam tak dihargai pula…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Barang hiasan itu dulu milik\n"
	.string "{STR_VAR_1}.\p"
	.string "Kamu nak?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Eh… Sekejap. Kamu tak ada sebarang\n"
	.string "barang hiasan pun!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Okey, pilih barang hiasan yang kamu nak\n"
	.string "tukar dengan saya.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Kamu tak nak bertukar dengan saya?\n"
	.string "Rasa macam tak dihargai pula…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "{STR_VAR_2} kamu dah penuh, tak boleh\n"
	.string "simpan lagi. Tak ada ruang untuk ni.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Okey, jadi kita tukar {STR_VAR_3} saya\n"
	.string "dengan {STR_VAR_2} kamu?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Barang hiasan tu tengah diguna.\n"
	.string "Tak boleh tukar.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Okey, kita tukar!\n"
	.string "Saya hantar barang hiasan saya ke PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Alamak! Maaf! Itu barang hiasan yang\n"
	.string "sangat nadir.\l"
	.string "Yang itu saya tak boleh tukar!\p"
	.string "Kamu berminat dengan barang lain?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Saya TUKANG CERITA.\n"
	.string "Saya akan ceritakan kisah JURULATIH\l"
	.string "lagenda.\p"
	.string "Kamu nak dengar kisah saya?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"
	.string "Kamu buat saya rasa sedih…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Saya tahu lagenda-lagenda ini.\n"
	.string "Kisah mana yang kamu mahu dengar?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Tapi, saya tak kenal mana-mana\n"
	.string "JURULATIH lagenda.\l"
	.string "Jadi, saya tak tahu sebarang kisah.\p"
	.string "Di mana agaknya saya boleh jumpa\n"
	.string "JURULATIH yang layak jadi lagenda?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Apa?!\n"
	.string "Kamu… Kamu…\p"
	.string "{STR_VAR_2}\n"
	.string "sebanyak {STR_VAR_1} kali?!\p"
	.string "Hebat betul!\n"
	.string "Lahirlah satu lagenda baru!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Saya tertanya-tanya, agaknya ada\n"
	.string "tak JURULATIH lain yang lagendanya\l"
	.string "lebih hebat, yang belum saya jumpa?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Kamu JURULATIH?\p"
	.string "Kalau begitu, cuba cerita, kamu ada\n"
	.string "kisah yang layak digelar lagenda?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Oh ya… Kamu nak dengar satu lagi kisah\n"
	.string "lagenda?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"
	.string "Saya tak puas hati…\p"
	.string "Saya harap kamu bawa berita yang layak\n"
	.string "digelar lagenda.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Saya harap lebih ramai orang berminat\n"
	.string "mendengar kisah epik saya tentang\l"
	.string "JURULATIH lagenda.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "JURULATIH Kaki Simpan$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Menyimpan permainan$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menyimpan permainan\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "Tiada JURULATIH yang lebih cermat\n"
	.string "daripada {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "JURULATIH Pencetus Trend$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Mencetuskan trend$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini mencetuskan trend baru\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mencetuskan trend untuk\n"
	.string "seluruh wilayah HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "JURULATIH Penanam BERI$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Menanam BERI$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menanam BERI\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} ialah pencinta BERI\n"
	.string "yang lagenda!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "JURULATIH Kaki BASIKAL$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Menukar BASIKAL$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menukar BASIKAL\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti sayang BASIKAL\n"
	.string "sepenuh jiwa!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "JURULATIH Yang Ditemu Bual$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Ditemu bual$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini ditemu bual\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti JURULATIH yang\n"
	.string "menarik banyak perhatian!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "JURULATIH Kaki Tarung$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Bertarung$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini bertarung {STR_VAR_1}\n"
	.string "kali!\p"
	.string "{STR_VAR_3} mesti JURULATIH yang tak\n"
	.string "pernah menolak peluang bertarung!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "JURULATIH Penangkap POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Menangkap POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menangkap\n"
	.string "{STR_VAR_1} ekor POKéMON!\p"
	.string "{STR_VAR_3} ialah penangkap POKéMON\n"
	.string "liar yang lagenda!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "JURULATIH Pemancing$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Menangkap POKéMON dengan JORAN$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menangkap\n"
	.string "{STR_VAR_1} ekor POKéMON semasa\l"
	.string "memancing!\p"
	.string "{STR_VAR_3} ialah pakar memancing\n"
	.string "yang lagenda!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "JURULATIH Pemanas TELUR$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Menetaskan TELUR$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menetaskan {STR_VAR_1}\n"
	.string "ekor POKéMON daripada TELUR!\p"
	.string "{STR_VAR_3} ialah pemanas TELUR\n"
	.string "yang lagenda!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "JURULATIH Pengevolusi$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Mengevolusikan POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini membuat {STR_VAR_1} ekor\n"
	.string "POKéMON berevolusi!\p"
	.string "{STR_VAR_3} ialah pengevolusi POKéMON\n"
	.string "yang teragung!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "JURULATIH Kaki PUSAT POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Menggunakan PUSAT POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini memulihkan POKéMON\n"
	.string "{STR_VAR_1} kali di PUSAT POKéMON!\p"
	.string "Tiada pencinta PUSAT POKéMON yang\n"
	.string "lebih hebat daripada {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "JURULATIH Kaki Rumah$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Merehatkan POKéMON di rumah$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini memulihkan POKéMON\n"
	.string "{STR_VAR_1} kali di rumah!\p"
	.string "Tiada yang lebih suka duduk di rumah\n"
	.string "daripada {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "JURULATIH Kaki SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Memasuki ZON SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini masuk ke ZON SAFARI\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "Sisi liar {STR_VAR_3} pasti terserlah\n"
	.string "di ZON SAFARI!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "JURULATIH Gila POTONG$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "Menggunakan POTONG$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menggunakan POTONG\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti JURULATIH yang\n"
	.string "sangat suka MEMOTONG!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "JURULATIH PEMECAH BATU$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Menghancurkan batu$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini guna PEMECAH BATU\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti JURULATIH yang\n"
	.string "pantang nampak batu, mesti\l"
	.string "dihancurkan!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "JURULATIH Kaki Pindah$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "Memindahkan PANGKALAN RAHSIA$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini memindahkan PANGKALAN\n"
	.string "RAHSIA sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} ialah JURULATIH yang suka\n"
	.string "berpindah rumah!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "JURULATIH Kaki PERCIKAN$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Menggunakan PERCIKAN$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menggunakan PERCIKAN\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti JURULATIH yang suka\n"
	.string "BERPERCIKAN ke sana sini!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "JURULATIH Yang Tabah$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Terpaksa menggunakan RONTAAN$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini terpaksa guna RONTAAN\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} ialah JURULATIH tabah yang\n"
	.string "tak pernah mengalah walau susah!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "Juara MESIN SLOT$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Menang jackpot di MESIN SLOT$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menang jackpot di\n"
	.string "MESIN SLOT sebanyak {STR_VAR_1} kali.\p"
	.string "{STR_VAR_3} ialah JURULATIH yang\n"
	.string "bertuah di MESIN SLOT!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "Juara RULET$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Menang RULET berturut-turut$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menang RULET\n"
	.string "{STR_VAR_1} kali berturut-turut.\p"
	.string "{STR_VAR_3} bertuah bila bola\n"
	.string "melantun di RULET!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "Pencabar BATTLE TOWER$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Menyahut cabaran BATTLE TOWER$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menyahut cabaran BATTLE\n"
	.string "TOWER sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} ialah JURULATIH yang mahu\n"
	.string "cemerlang di BATTLE TOWER!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "JURULATIH Kaki Kisar$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Membuat {POKEBLOCK}$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini membuat {POKEBLOCK}\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "Tiada yang lebih mahir menggunakan\n"
	.string "PENGISAR BERI daripada {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "JURULATIH Kaki PERTANDINGAN$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Menyertai PERTANDINGAN$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menyertai PERTANDINGAN\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti suka menunjuk\n"
	.string "POKéMON kepada orang lain!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "Pakar PERTANDINGAN$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Menang PERTANDINGAN$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menang PERTANDINGAN\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti pakar PERTANDINGAN\n"
	.string "yang luar biasa!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "Kaki Membeli-belah$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Membeli-belah$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini membeli barang di kedai\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti antara orang yang\n"
	.string "memang lahir untuk membeli-belah.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "JURULATIH Pencari Barang$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Menggunakan PENGESAN$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menggunakan PENGESAN\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti suka menyelongkar\n"
	.string "tanah mencari barang tersembunyi!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "JURULATIH Basah Hujan$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Ditimpa hujan$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini basah ditimpa hujan\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "Karisma {STR_VAR_3} mesti sampai\n"
	.string "hujan pun tertarik!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "Pembaca POKéDEX Tegar$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Menyemak POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menyemak POKéDEX\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti suka meneliti\n"
	.string "POKéMON dalam POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "Pengumpul REBEN$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Menerima REBEN$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menerima REBEN\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti JURULATIH yang\n"
	.string "suka mengumpul REBEN!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "JURULATIH Kaki Lompat Tebing$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Melompat turun tebing$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini melompat turun tebing\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "Kalau ada tebing untuk dilompat,\n"
	.string "{STR_VAR_3} takkan melepaskannya!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "Penonton TV Lagenda$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Menonton TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menonton TV\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti suka menonton TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "JURULATIH Peka Masa$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Menyemak masa$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menyemak masa\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti JURULATIH yang\n"
	.string "tepat masa dan peka akan waktu.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "Pakar CABUTAN BERTUAH$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Menang CABUTAN BERTUAH$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menang CABUTAN BERTUAH\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti ada ramai kawan\n"
	.string "untuk bertukar POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "JURULATIH Kaki TASKA$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Menghantar POKéMON ke TASKA$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menghantar POKéMON ke\n"
	.string "TASKA sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti rajin betul\n"
	.string "membela POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "JURULATIH Kaki KERETA KABEL$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Menaiki KERETA KABEL$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini menaiki KERETA KABEL\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti JURULATIH sibuk\n"
	.string "yang asyik naik turun saja!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "JURULATIH Kaki Air Panas$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Berendam di kolam air panas$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Ini kisah seorang JURULATIH\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "JURULATIH ini berendam di kolam air\n"
	.string "panas sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} mesti JURULATIH yang\n"
	.string "kulitnya selembut kulit bayi!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Saya GIDDY!\n"
	.string "Saya ada cerita menarik untuk kamu!\p"
	.string "Kamu nak dengar cerita saya?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\n"
	.string "Kamu buat saya rasa sedih…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Lagi satu, saya terfikir…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Rasanya itu saja…\p"
	.string "Nanti kita borak lagi!\n"
	.string "Bai-bai!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Hai, saya PENYANYI.\n"
	.string "Kamu nak dengar lagu saya?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\n"
	.string "Kamu buat saya rasa sedih…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, lagu yang menyentuh hati…\n"
	.string "Kalaulah saya dapat nyanyikan lagu\l"
	.string "ni untuk orang lain…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Jadi?\n"
	.string "Apa pendapat kamu tentang lagu saya?\p"
	.string "Tapi saya kurang puas hati dengan\n"
	.string "liriknya.\p"
	.string "Kamu nak tulis lirik baru untuk saya?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\n"
	.string "Kamu buat saya rasa sedih…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Terima kasih banyak!\n"
	.string "Biar saya nyanyikan untuk kamu.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Macam tu ke lagu yang kamu nak?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Okey! Kalau macam tu, jadilah.\n"
	.string "Saya akan nyanyi lagu ni buat\l"
	.string "sementara waktu.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Hei, yo! Orang panggil saya HIPSTER.\n"
	.string "Saya ajar kamu apa yang hip dan terkini.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Tapi, hei, saya dah ajar kamu apa yang\n"
	.string "hip dan terkini.\p"
	.string "Saya nak sebarkan berita baik ini\n"
	.string "kepada orang lain pula.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Tapi, hei, kamu dah tahu banyak tentang\n"
	.string "apa yang hip dan terkini.\p"
	.string "Saya tak ada benda baru nak ajar kamu!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Hei, kamu pernah dengar tentang\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Apa maknanya? Hmm…\n"
	.string "Tanyalah ayah atau mak kamu, okey?$"
