MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Hai, JURULATIH!\n"
	.string "JORAN SUPER memang super!\p"
	.string "Cakaplah apa saja, tapi joran ni boleh\n"
	.string "tangkap POKéMON dari dasar laut!\p"
	.string "Macam mana?\n"
	.string "Kamu nak, kan?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Mestilah, mestilah!\n"
	.string "JORAN SUPER memang super!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Kalau ada air, cuba hulur JORAN kamu dan\n"
	.string "tengok apa yang makan umpan!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hah?\n"
	.string "Kamu tak suka memancing ke?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Buru POKéMON dasar laut dengan JORAN\n"
	.string "SUPER kamu.$"

