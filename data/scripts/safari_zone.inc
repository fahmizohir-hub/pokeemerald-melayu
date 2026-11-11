SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Kamu nak keluar dari ZON SAFARI\n"
	.string "sekarang?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! Masa dah tamat!\n"
	.string "Permainan SAFARI kamu dah berakhir.$"

SafariZone_Text_OutOfBalls:
	.string "SAFARI BALL kamu dah habis.\n"
	.string "Permainan SAFARI kamu dah berakhir.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Kamu nak letak {POKEBLOCK} di atas\n"
	.string "PENYUAP {POKEBLOCK}?$"

SafariZone_Text_PokeblockStillHere:
	.string "{STR_VAR_1} yang kamu tinggalkan\n"
	.string "tadi masih ada di sini.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "{STR_VAR_1} diletakkan di atas\n"
	.string "PENYUAP {POKEBLOCK}.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Selamat datang ke ZON SAFARI!\p"
	.string "Di sini, kamu boleh lihat pelbagai jenis\n"
	.string "POKéMON yang jarang dilihat di HOENN.\p"
	.string "Malah, kamu akan lihat mereka dalam\n"
	.string "keadaan liar di habitat semula jadi.\p"
	.string "Lebih hebat lagi, pintu kami terbuka\n"
	.string "luas untuk JURULATIH POKéMON.\p"
	.string "Kamu digalakkan menangkap POKéMON\n"
	.string "untuk disimpan!\p"
	.string "Masuklah dan berseronok di ZON SAFARI!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Selamat datang ke ZON SAFARI!\n"
	.string "Ini kali pertama kamu ke sini?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Masuklah dan berseronok di ZON SAFARI!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Bila masuk ke ZON SAFARI, kamu bermula\n"
	.string "dengan 30 SAFARI BALL untuk menangkap\l"
	.string "POKéMON.\p"
	.string "Permainan SAFARI tamat bila SAFARI\n"
	.string "BALL kamu habis, atau bila kamu dah\l"
	.string "berjalan 500 langkah.\p"
	.string "Masuklah dan berseronok di ZON SAFARI!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Selamat datang ke ZON SAFARI!\p"
	.string "Tangkap sepuas hati, hanya ¥500!\n"
	.string "Kamu nak main Permainan SAFARI?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Baiklah.\n"
	.string "Sila main lain kali!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Wang kamu tak cukup.\n"
	.string "Maaf.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Semuanya ¥500, ya.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Ini SAFARI BALL kamu.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} menerima 30 SAFARI BALL.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Kami akan beritahu kamu bila permainan\n"
	.string "kamu tamat.\p"
	.string "Jadi, sementara itu, berseronoklah!\n"
	.string "Selamat menjelajah alam liar!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Maaf!\n"
	.string "KOTAK PC kamu dah penuh.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Maaf!\n"
	.string "Nampaknya kamu tiada BEKAS {POKEBLOCK}.\p"
	.string "Permainan SAFARI kamu akan lebih\n"
	.string "berhasil kalau kamu guna {POKEBLOCK}.\p"
	.string "Sila datang balik dengan BEKAS {POKEBLOCK}.\p"
	.string "Kamu boleh dapatkan BEKAS {POKEBLOCK} di\n"
	.string "DEWAN PERTANDINGAN LILYCOVE.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Kamu masih ada masa lagi. Kamu nak\n"
	.string "keluar dari ZON SAFARI sekarang?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Selamat meneruskan pengembaraan liar\n"
	.string "kamu!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Baiklah.\p"
	.string "Saya ambil balik baki SAFARI BALL kamu.\p"
	.string "Terima kasih kerana bermain.\n"
	.string "Kami harap dapat jumpa kamu lagi.$"

SafariZone_South_Text_GoodLuck:
	.string "Semoga berjaya!\p"
	.string "Kalau perlukan apa-apa, jangan segan\n"
	.string "beritahu saya, ya!$"

SafariZone_South_Text_Boy:
	.string "Kamu tahu tak?\p"
	.string "Kalau kamu letak {POKEBLOCK} dalam kotak\n"
	.string "segi empat itu, POKéMON akan berkumpul.$"

SafariZone_South_Text_Man:
	.string "Saya nak terus masuk lebih dalam, tapi\n"
	.string "saya terlupa bawa BASIKAL.\p"
	.string "Saya rasa POKéMON nadir tinggal di\n"
	.string "kawasan pinggir.$"

SafariZone_Southwest_Text_Woman:
	.string "Kadang-kadang, bila saya baling {POKEBLOCK}\n"
	.string "pada POKéMON, ia tak dipedulikan.\p"
	.string "POKéMON ada makanan yang mereka suka\n"
	.string "dan tak suka ke?$"

SafariZone_Northwest_Text_Man:
	.string "Hah… Hah…\n"
	.string "Saya…sampai juga ke sini…tapi…\p"
	.string "Saya penat… Dah tak ada tenaga nak\n"
	.string "tangkap POKéMON…$"

SafariZone_North_Text_Fisherman:
	.string "Saya sedang mencari POKéMON AIR yang\n"
	.string "tak ada di HOENN.\p"
	.string "Kamu tahu tak di mana tasik itu?$"

SafariZone_North_Text_Man:
	.string "Saya nak tangkap banyak POKéMON nadir\n"
	.string "di sini dan tukar dengan kawan-kawan\l"
	.string "saya!$"

SafariZone_South_Text_Youngster:
	.string "Saya letak {POKEBLOCK} di atas PENYUAP\n"
	.string "{POKEBLOCK}. Tapi nampaknya ia dah hilang.\p"
	.string "Mesti POKéMON dah makan tanpa saya\n"
	.string "sedar.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "PETUA JURULATIH ZON SAFARI!\p"
	.string "Baling {POKEBLOCK} pada POKéMON liar supaya\n"
	.string "mereka kurang cenderung melarikan diri.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Rehatkan kaki kamu yang penat.”\n"
	.string "RUMAH REHAT$"

SafariZone_RestHouse_Text_Youngster:
	.string "Saya tak ada {POKEBLOCK}, tapi saya dapat\n"
	.string "tangkap banyak juga POKéMON.\p"
	.string "Peluang kamu menangkap boleh\n"
	.string "meningkat kalau kamu dekati mereka\l"
	.string "sebelum membaling SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Kalau kamu guna {POKEBLOCK}, POKéMON liar\n"
	.string "tak akan cepat lari.\p"
	.string "Tak banyak gunanya beri {POKEBLOCK} kepada\n"
	.string "POKéMON yang memang tak mudah lari.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Kalau kamu letak {POKEBLOCK} di atas\n"
	.string "PENYUAP, POKéMON akan tertarik\l"
	.string "kepadanya.\p"
	.string "Saya rasa POKéMON yang sama sifatnya\n"
	.string "akan tertarik kepada {POKEBLOCK} tertentu.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Kawasan ini masih dalam pembinaan.\n"
	.string "Tak boleh masuk, maaf!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Projek pembesaran ZON SAFARI kini\n"
	.string "sudah siap.\p"
	.string "Kami harap kamu seronok di kawasan\n"
	.string "baru ini.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Kawasan ini masih dalam pembinaan.\n"
	.string "Tak boleh masuk, maaf!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Wah! Yeay! Saya tak pernah nampak\n"
	.string "POKéMON-POKéMON ini!$"

SafariZone_Southeast_Text_FatMan:
	.string "POKéMON di kawasan ini semuanya baru\n"
	.string "bagi saya.\p"
	.string "Dan saya dibenarkan tangkap POKéMON\n"
	.string "nadir ini! Hebatnya!$"

SafariZone_Southeast_Text_RichBoy:
	.string "POKéMON di sekitar sini nampaknya\n"
	.string "datang dari tempat selain HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "SAFARI BALL saya tinggal beberapa biji\n"
	.string "saja.\p"
	.string "Susahnya nak tentukan POKéMON mana\n"
	.string "yang patut saya tangkap.$"

SafariZone_Northeast_Text_Woman:
	.string "Kata orang, PIKACHU ada di sini.\n"
	.string "Di mana agaknya?$"

SafariZone_Northeast_Text_Girl:
	.string "Alahai!\n"
	.string "Saya tak dapat tangkap apa-apa pun!\p"
	.string "Membazir saja duit masuk kalau saya tak\n"
	.string "tangkap sesuatu!$"
