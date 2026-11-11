Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "TEROWONG RUSTURF tu…\p"
	.string "Mula-mula, kami ada ramai pekerja\n"
	.string "menebuk batu dengan mesin terkini. Tapi\l"
	.string "kami terpaksa berhenti.\p"
	.string "Rupa-rupanya kerja kami boleh beri\n"
	.string "kesan buruk kepada POKéMON liar di\l"
	.string "kawasan tu.\p"
	.string "Jadi, kami tak ada apa nak buat, cuma\n"
	.string "melepak di sini saja.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Ada seorang lelaki menggali jalan ke\n"
	.string "VERDANTURF seorang diri. Dia\l"
	.string "betul-betul nak tembus.\p"
	.string "Katanya, kalau dia gali sikit-sikit\n"
	.string "tanpa mesin, dia takkan ganggu\l"
	.string "POKéMON, dan takkan rosakkan alam\l"
	.string "semula jadi.\p"
	.string "Agaknya dah tembus belum?$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Untuk ke VERDANTURF tanpa guna\n"
	.string "TEROWONG ni, kamu kena seberang laut ke\l"
	.string "DEWFORD, belayar ke SLATEPORT,\l"
	.string "kemudian lalu MAUVILLE.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Dah dengar? TEROWONG ke VERDANTURF\n"
	.string "dah tembus!\p"
	.string "Kadang-kadang, kalau kita berharap\n"
	.string "sungguh-sungguh, impian memang jadi\l"
	.string "kenyataan.$"

