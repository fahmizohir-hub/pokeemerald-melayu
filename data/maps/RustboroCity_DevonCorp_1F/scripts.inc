RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Helo dan selamat datang ke DEVON\n"
	.string "CORPORATION.\p"
	.string "Kami pengeluar barang dan ubat-ubatan\n"
	.string "yang menceriakan hidup anda.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Salah seorang staf penyelidik kami dah\n"
	.string "bodoh-bodoh kena rompak bungkusan\l"
	.string "penting.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Eh, KASUT LARI tu! Itu salah satu\n"
	.string "produk kami!\p"
	.string "Saya gembira bila nampak orang guna\n"
	.string "barang yang kami buat.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Bungkusan yang dicuri tu…\p"
	.string "Memanglah ia penting, tapi bukannya\n"
	.string "benda yang sesiapa boleh guna.\p"
	.string "Pada pendapat saya, perompak tu mesti\n"
	.string "tak berapa cerdik.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Nampaknya BARANG DEVON yang dicuri tu\n"
	.string "dah dapat balik.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Maaf, hanya orang yang dibenarkan\n"
	.string "boleh masuk ke sini.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Bodoh betul. Macam mana kita boleh kena\n"
	.string "rompak?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Hai! Kamu sentiasa dialu-alukan di sini!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Sampel batu dan logam dipamerkan dalam\n"
	.string "bekas kaca.\p"
	.string "Ada papan dengan tulisan…\p"
	.string "“DEVON CORPORATION bermula sebagai\n"
	.string "pengeluar batu dari kuari.\p"
	.string "“Syarikat ini juga menghasilkan besi\n"
	.string "daripada serbuk besi dalam pasir.\p"
	.string "“Dari permulaan sederhana sebagai\n"
	.string "pengeluar bahan mentah, DEVON terus\l"
	.string "berkembang.\p"
	.string "“DEVON kini pengilang pelbagai jenis\n"
	.string "produk perindustrian.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Prototaip dan produk ujian memenuhi\n"
	.string "bekas pameran kaca.\p"
	.string "Ada papan dengan penerangan…\p"
	.string "“Selain produk perindustrian, DEVON\n"
	.string "kini memasarkan barang runcit dan\l"
	.string "farmaseutikal untuk gaya hidup lebih\l"
	.string "baik.\p"
	.string "“Baru-baru ini, DEVON mula memasarkan\n"
	.string "alatan untuk JURULATIH POKéMON,\l"
	.string "termasuk POKé BALL dan sistem\l"
	.string "POKéNAV.”$"

