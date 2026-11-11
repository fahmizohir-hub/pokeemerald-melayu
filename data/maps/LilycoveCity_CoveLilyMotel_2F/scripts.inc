LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Saya PEREKA GAME.\p"
	.string "Oh, betul ke?\n"
	.string "Kamu tengah lengkapkan POKéDEX?\p"
	.string "Memang susah nak lengkapkannya, tapi\n"
	.string "jangan putus asa.\p"
	.string "Kalau dah lengkap, datanglah tunjuk\n"
	.string "pada saya.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wah! Hebatnya!\n"
	.string "Ya, memang hebat sungguh!\p"
	.string "POKéDEX ni dah penuh sepenuhnya!\n"
	.string "Kamu memang sayang POKéMON!\p"
	.string "Saya sangat kagum!\p"
	.string "Biar saya beri sesuatu sebagai\n"
	.string "penghargaan atas kejayaan kamu!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Saya? Kamu cakap dengan saya?\n"
	.string "Saya PENGATURCARA.\p"
	.string "Macam mana agaknya MESIN SLOT di sini.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Saya PELUKIS GRAFIK! POKéMON di HOENN\n"
	.string "menarik, kan?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Budak berpelampung tu comel, kan?\n"
	.string "Lawan budak berpelampung yang comel…\p"
	.string "Wuhuu, memang hebat!\p"
	.string "Budak kembar pula! Comel, kan?\n"
	.string "Pertarungan 2 lawan 2 dengan kembar…\p"
	.string "Wuhuu, seronok tak terkata!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "Bayu laut menggeletek hati saya.\n"
	.string "Seronoknya di sini!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Kita tak tahu bila dan di mana orang\n"
	.string "akan cabar kita.\p"
	.string "Sebab tu saya tak pernah keluar rumah\n"
	.string "tanpa GAME BOY ADVANCE saya.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Hah?!\n"
	.string "Oh, maaf, maaf! Saya terlelap!\p"
	.string "Saya datang nak tengok PERTANDINGAN\n"
	.string "POKéMON ni.\p"
	.string "Saya akui, ia memang nampak\n"
	.string "menghiburkan, tapi…\p"
	.string "Saya ni orang tradisional, saya lebih\n"
	.string "suka pertarungan dan JURULATIH yang\l"
	.string "kuat.\p"
	.string "Tapi itu saya sajalah.\p"
	.string "{PLAYER}{KUN}, saya harap kamu nikmati\n"
	.string "semuanya, GIM, PERTANDINGAN, KHEMAH\l"
	.string "BATTLE, semuanya!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: Saya rasa memang perlukan\n"
	.string "strategi untuk menang PERTANDINGAN.\p"
	.string "Merangka strategi PERTANDINGAN ialah\n"
	.string "satu cara untuk jadi JURULATIH yang\l"
	.string "lebih baik, pada saya.$"

