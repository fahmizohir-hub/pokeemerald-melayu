VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Biar saya tengok POKéMON kamu.\n"
	.string "Saya periksa sejauh mana ia suka kamu.\p"
	.string "Oh.\n"
	.string "POKéMON kamu…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Ia sangat sayangkan kamu.\n"
	.string "Sayangnya dah tak boleh lebih lagi.\l"
	.string "Saya pun gembira tengok ia.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Ia nampak sangat gembira.\n"
	.string "Jelas ia sangat suka kamu.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Ia agak suka kamu.\n"
	.string "Nampaknya ia nak dimanja sedikit.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "Ia makin biasa dengan kamu.\n"
	.string "Nampaknya ia percayakan kamu.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Ia belum begitu biasa dengan kamu.\n"
	.string "Ia tak sayang dan tak benci kamu.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "Ia sangat berwaspada.\n"
	.string "Matanya garang menakutkan.\l"
	.string "Ia langsung tak suka kamu.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "Susah sikit saya nak cakap…\p"
	.string "POKéMON kamu memang bencikan kamu.\n"
	.string "Kamu tak rasa tak selesa ke?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"

