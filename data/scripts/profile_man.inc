ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Helo, JURULATIH!\n"
	.string "Senyuman kamu memang menawan.\p"
	.string "Saya ada hobi--mengumpul profil\n"
	.string "JURULATIH POKéMON.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Jadi, macam mana?\n"
	.string "Boleh saya tengok profil kamu?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Kamu buat profil sendiri dengan\n"
	.string "menggabungkan empat perkataan atau\l"
	.string "frasa.\p"
	.string "Nah, saya tunjukkan contoh profil yang\n"
	.string "guna empat cebisan teks.\p"
	.string "Kamu boleh tukar empat cebisan itu\n"
	.string "dengan cebisan teks lain ikut suka hati\l"
	.string "untuk buat profil sendiri.\p"
	.string "Ada banyak cebisan teks yang boleh\n"
	.string "kamu guna.\p"
	.string "Semuanya disusun dalam kumpulan\n"
	.string "seperti POKéMON, gaya hidup dan hobi\l"
	.string "supaya senang dicari.\p"
	.string "Jadi, mula-mula, pilih kumpulan cebisan\n"
	.string "teks untuk paparkan senarai pilihan.\p"
	.string "Kemudian, pilih yang kamu mahu.\p"
	.string "Ulang untuk pilihan teks yang\n"
	.string "selebihnya, dan siaplah profil kamu\l"
	.string "sendiri.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Ya! Terima kasih!\n"
	.string "Jadi, mari kita tengok.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Alamak, betul ke?\p"
	.string "Saya bayangkan orang macam kamu mesti\n"
	.string "ada profil yang hebat…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Oh? Kamu tak berminat sekarang?\p"
	.string "Takpe, bila-bila masa pun saya okey!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Helo, JURULATIH!\n"
	.string "Senyuman kamu memang menawan.$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Boleh saya tengok profil baru kamu?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Ya! Terima kasih!\p"
	.string "Saya harap ia lebih baik daripada profil\n"
	.string "yang kamu tunjuk dulu.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Oh, kamu suka profil kamu macam\n"
	.string "sekarang.\p"
	.string "Saya tak salahkan kamu--profil kamu\n"
	.string "sekarang memang hebat.$"

ProfileMan_Text_FantasticProfile:
	.string "H-hebat!\p"
	.string "Profil kamu memang menakjubkan!\n"
	.string "Ia betul-betul menggambarkan kamu.\p"
	.string "Sesiapa yang dengar profil ini pasti\n"
	.string "terpikat dengan kamu!\p"
	.string "Terima kasih!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Oh?\n"
	.string "Kamu tahu ungkapan rahsia itu!\p"
	.string "Maknanya kamu kini ahli KELAB ACARA\n"
	.string "MISTERI!$"
