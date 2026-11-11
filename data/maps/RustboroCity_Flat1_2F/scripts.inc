RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applywaitmovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Aduh, susahnya setiap hari…\p"
	.string "Apa yang susah? Tak payah tanyalah.\p"
	.string "Nak fikir masak apa setiap hari.\p"
	.string "Bukan senang nak fikir menu\n"
	.string "setiap hari.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oh, helo! Selamat datang ke rumah\n"
	.string "keluarga PEPPER.\p"
	.string "Saya ada soalan untuk kamu. Kamu\n"
	.string "pernah jaga budak kecil?\p"
	.string "Saya baru jadi bapa, jadi jaga anak ni\n"
	.string "semuanya baru bagi saya.\p"
	.string "Dan saya ada masalah. Anak perempuan\n"
	.string "saya, WALDA, jarang ketawa.\p"
	.string "Saya rasa dia akan ketawa kalau saya\n"
	.string "cakap sesuatu yang lucu.\p"
	.string "Kamu tahu tak apa-apa perkataan atau\n"
	.string "frasa lucu? Boleh beritahu saya?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Kebelakangan ni saya sebut\n"
	.string "“{STR_VAR_1}” untuk hiburkan dia.\p"
	.string "Kamu tahu perkataan atau frasa yang\n"
	.string "lebih baik?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, bagusnya. Jadi, apa cadangan kamu?$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Oh, begitu?\p"
	.string "Kalau kamu ada cadangan yang bagus,\n"
	.string "saya sedia mendengar.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, begitu. Jom kita cuba, ya?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}. {STR_VAR_1}.\p"
	.string "Oh, ya! Dia ketawa! Saya pun\n"
	.string "gembira sama!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, begitu. Jom kita cuba, ya?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Dia langsung tak senyum. Mungkin\n"
	.string "WALDA ni budak yang serius…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Oh, jadi kamu tak tahu perkataan yang\n"
	.string "bagus. Kalau begitu, saya\l"
	.string "fikir sendirilah.\p"
	.string "Hmm… Apa kata “{STR_VAR_1}”? Jom cuba,\n"
	.string "menjadi ke tak.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Dia langsung tak senyum. Mungkin\n"
	.string "WALDA ni budak yang serius…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Oh, jadi kamu tak tahu perkataan yang\n"
	.string "bagus. Saya cuba hiburkan dia dengan\l"
	.string "ayat lama sajalah.\p"
	.string "Apa-apa pun, kalau kamu ada cadangan\n"
	.string "yang bagus, jangan segan beritahu\l"
	.string "saya, okey?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Terima kasih!\p"
	.string "Berkat kamu, WALDA kesayangan\n"
	.string "saya ketawa!\p"
	.string "Nampak macam orang biasa, tapi\n"
	.string "sebenarnya saya ni salah seorang\l"
	.string "penyelidik utama DEVON CORPORATION.\p"
	.string "Jadi, apa kata saya balas jasa kamu?\p"
	.string "Haa, saya tambah corak kertas dinding\n"
	.string "baru untuk KOTAK PC dalam Sistem\l"
	.string "Simpanan POKéMON.\p"
	.string "Dalam menu corak kertas dinding,\n"
	.string "pilih “KAWAN.”\p"
	.string "Lepas tu, kamu boleh guna corak kertas\n"
	.string "dinding yang baru.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "Ini PATUNG POKéMON yang gebu!$"

