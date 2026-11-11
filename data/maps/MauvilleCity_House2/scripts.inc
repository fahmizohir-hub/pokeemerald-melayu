MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applywaitmovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	applywaitmovement VAR_LAST_TALKED, Common_Movement_Delay48
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "Kalau saya ada BASIKAL, senang nak\n"
	.string "berbasikal ke SLATEPORT untuk\l"
	.string "membeli-belah.\p"
	.string "Saya boleh beli SURAT DERMAGA di\n"
	.string "POKé MART SLATEPORT…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Oh! Kamu ada SURAT DERMAGA?\n"
	.string "Nak tukar dengan BEKAS SYILING?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Oh, gembiranya saya!\n"
	.string "Baiklah, saya bagi BEKAS SYILING!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "BEKAS SYILING tu boleh diguna di\n"
	.string "SUDUT PERMAINAN.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Oh, kecewanya.\p"
	.string "BEKAS SYILING diperlukan untuk\n"
	.string "SUDUT PERMAINAN.$"

