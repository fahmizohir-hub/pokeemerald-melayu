MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "PEMULIH memang hebat!\p"
	.string "Beri kepada POKéMON yang pengsan, dan\n"
	.string "POKéMON itu akan bangun semula.\p"
	.string "Tapi hati-hati, PEMULIH tak pulihkan PP\n"
	.string "move yang dah habis diguna.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "PENGHALAU MKS menghalau semua POKéMON\n"
	.string "yang lemah.\p"
	.string "Antara semua semburan PENGHALAU, ia\n"
	.string "yang paling lama tahan.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "NET BALL dan DIVE BALL ialah POKé BALL\n"
	.string "nadir yang hanya dibuat di MOSSDEEP.\p"
	.string "NET BALL berkesan terhadap POKéMON\n"
	.string "jenis SERANGGA dan AIR.\p"
	.string "DIVE BALL paling berkesan pada POKéMON\n"
	.string "di dasar laut.$"

