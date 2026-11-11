VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applywaitmovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applywaitmovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Papa saya yang beritahu.\p"
	.string "Katanya terowong ni penuh dengan\n"
	.string "POKéMON yang penakut.\p"
	.string "Mereka takut dengan bunyi bising dan\n"
	.string "buat kecoh besar.\p"
	.string "Jadi projek terowong besar tu terpaksa\n"
	.string "dihentikan.\p"
	.string "Tapi ada seorang lelaki. Dia cuba gali\n"
	.string "terowong tu seorang diri!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Ada seorang lelaki gali terowong untuk\n"
	.string "wanita yang dia cintai.\p"
	.string "Saya tak berapa faham, tapi, hei!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Ikut arah tiupan angin, abu gunung\n"
	.string "berapi tak pernah ditiup ke sini.\p"
	.string "Udara di sini bersih dan nyaman. Tinggal\n"
	.string "di sini mesti bagus walaupun untuk\l"
	.string "orang yang lemah dan sakit.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Saya dan POKéMON saya tengah menang\n"
	.string "berturut-turut.\p"
	.string "Jadi saya putuskan untuk buat\n"
	.string "penampilan sulung di KHEMAH BATTLE\l"
	.string "pekan ni.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Kamu nampak gua sebelah POKé MART?\p"
	.string "Ada seorang lelaki di dalam yang cuba\n"
	.string "pecahkan batu besar supaya dapat\l"
	.string "tembus ke seberang.\p"
	.string "Bagus kalau kita boleh lalu… Senang nak\n"
	.string "ke RUSTBORO.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Gua sebelah POKé MART tu sekarang dah\n"
	.string "jadi terowong ke seberang.\p"
	.string "Bagus betul, sekarang senang nak pergi\n"
	.string "beli produk baru DEVON di RUSTBORO.$"

VerdanturfTown_Text_TownSign:
	.string "PEKAN VERDANTURF\p"
	.string "“Tanah tinggi berangin dengan haruman\n"
	.string "rumput yang manis.”$"

VerdanturfTown_Text_WandasHouse:
	.string "RUMAH WANDA$"

VerdanturfTown_Text_BattleTentSign:
	.string "KHEMAH BATTLE VERDANTURF\n"
	.string "“Saksikan Pertarungan Hebat!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "TEROWONG RUSTURF\n"
	.string "“Menghubungkan RUSTBORO dan\l"
	.string "VERDANTURF\p"
	.string "“Projek terowong telah dibatalkan.”$"

