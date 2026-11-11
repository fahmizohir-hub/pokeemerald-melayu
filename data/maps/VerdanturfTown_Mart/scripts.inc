VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "Dalam apa-apa perlawanan POKéMON,\n"
	.string "X KHAS memang penting.\p"
	.string "Ia naikkan kuasa sesetengah move\n"
	.string "walaupun untuk satu pertarungan saja.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Nampaknya mereka tak jual buku\n"
	.string "panduan strategi menang untuk\l"
	.string "KHEMAH BATTLE…\p"
	.string "Nampaknya kita kena harapkan akal\n"
	.string "sendiri juga…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "NEST BALL lebih berkesan pada POKéMON\n"
	.string "yang lemah.\p"
	.string "VERDANTURF satu-satunya tempat kamu\n"
	.string "boleh beli NEST BALL.$"

