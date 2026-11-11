SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Err… Kalau yang ni di sini, dan yang tu di\n"
	.string "sana…\p"
	.string "Habis, benda ni letak di mana? Dan alat\n"
	.string "tu pula?\p"
	.string "Aaargh! Saya langsung tak faham benda\n"
	.string "ni!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hm?\n"
	.string "Hai, saya DOCK.\p"
	.string "KAPT. STERN upah saya untuk mereka\n"
	.string "bentuk sebuah feri.\p"
	.string "Oh! Itu…\n"
	.string "Itu BARANG DEVON ke?\p"
	.string "Tapi, hmm…\n"
	.string "Tak boleh jadi…\p"
	.string "KAPT. STERN dah pergi entah ke mana.\n"
	.string "Katanya dia ada kerja.\p"
	.string "Boleh tak kamu tolong cari KAPT. STERN\n"
	.string "dan serahkan barang tu kepadanya?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK: Ke mana agaknya KAPT. STERN\n"
	.string "pergi?\p"
	.string "Boleh tak kamu cari KAPT. STERN dan\n"
	.string "serahkan bungkusan tu kepadanya?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK: Membina kapal ialah satu seni.\p"
	.string "Banyak perkara tak boleh diselesaikan\n"
	.string "dengan kiraan saja.\p"
	.string "Saya betul-betul perlukan nasihat\n"
	.string "orang berpengalaman yang kenal lautan…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "DOCK: Hai! ENCIK BRINEY dah sertai kami\n"
	.string "untuk membantu.\p"
	.string "Terima kasih kepada pelaut\n"
	.string "berpengalaman tu, feri ni makin siap.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK: Akhirnya feri dah siap!\p"
	.string "S.S. TIDAL yang baru ni memang\n"
	.string "keajaiban teknologi!\p"
	.string "Tapi saya rasa kami boleh buat sesuatu\n"
	.string "yang lebih baik lagi.\p"
	.string "Kamu tahu, kemajuan teknologi tak\n"
	.string "pernah berpenghujung.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "ENCIK BRINEY: Ah, {PLAYER}{KUN}!\n"
	.string "Lama tak jumpa!\p"
	.string "Ya, sejak jumpa kamu, pelaut tua ni rasa\n"
	.string "bersemangat semula!\p"
	.string "Jadi saya putuskan untuk tolong DOCK\n"
	.string "bina feri.\p"
	.string "Ya, lagipun, feri boleh bawa ramai orang.\p"
	.string "Tapi, kamu tahu, DOCK tu memang\n"
	.string "istimewa.\p"
	.string "Dengan bakat teknologinya dan\n"
	.string "pengalaman saya, saya pasti kami boleh\l"
	.string "bina sebuah kapal yang hebat, ya!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Musim, cuaca, kedudukan bulan di\n"
	.string "langit…\p"
	.string "Semua ni dan keadaan lain buat wajah\n"
	.string "laut berubah.\p"
	.string "Betul tu!\n"
	.string "Laut ni macam benda hidup!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Saya senang sangat mabuk laut.\n"
	.string "Jadi saya tolong di sini saja.$"

