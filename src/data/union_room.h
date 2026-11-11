ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("Sila mulakan semula dari awal.");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("Carian SISTEM KOMUNIKASI\nWAYARLES telah dibatalkan.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("Menunggu komunikasi\ndaripada pemain lain."); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}! Menunggu\nkomunikasi daripada pemain lain.");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Menunggu link!\nTekan START bila semua sudah sedia.");
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("Perlu 1\npemain.");
static const u8 sText_2PlayersNeeded[] = _("Perlu 2\npemain.");
static const u8 sText_3PlayersNeeded[] = _("Perlu 3\npemain.");
static const u8 sText_4PlayersNeeded[] = _("Perlu 4\npemain.");
static const u8 sText_2PlayerMode[] = _("MOD\n2 PEMAIN");
static const u8 sText_3PlayerMode[] = _("MOD\n3 PEMAIN");
static const u8 sText_4PlayerMode[] = _("MOD\n4 PEMAIN");
static const u8 sText_5PlayerMode[] = _("MOD\n5 PEMAIN");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}BATAL");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} menghubungi anda\nuntuk {STR_VAR_1}. Terima?");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2} menghubungi anda.\nMahu kongsi {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} menghubungi anda.\nTambah sebagai ahli?");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}!\nAhli-ahli ini okey?");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("Batalkan MOD {STR_VAR_1}\ndengan ahli-ahli ini?");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("“OK” dihantar ke\n{STR_VAR_1}.");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("JURULATIH itu nampaknya tidak\ndapat dihubungi sekarang…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("Anda tak dapat berhubung dengan\nJURULATIH yang terlalu jauh.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("JURULATIH lain belum\nbersedia lagi.\p");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("MOD {STR_VAR_1} dengan ahli-ahli\nini akan dibatalkan.{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("Ada ahli yang tidak dapat\nmeneruskan lagi.\p");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("JURULATIH itu nampaknya\ntidak dapat dihubungi…\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1} membalas “OK”!");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1} meluluskan pendaftaran\nanda sebagai ahli.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} menjawab, “Tak…”\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nMenunggu ahli lain!");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("Berhenti menjadi ahli?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Anda berhenti menjadi ahli.\p");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("Link SISTEM KOMUNIKASI\nWAYARLES telah diwujudkan.");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("Link SISTEM KOMUNIKASI\nWAYARLES telah terputus…");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("Link dengan kawan anda telah\nterputus…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} menjawab, “Tak…”");

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Anda mahu MOD\n{STR_VAR_2}?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Anda mahu MOD\n{STR_VAR_2}?");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("Berhubung…\nSila tunggu."); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("Menunggu jawapan {STR_VAR_1}\ntentang pertukaran…");
ALIGNED(4) static const u8 sText_Communicating[] = _("Berhubung{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                     "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("Berhubung dengan {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                               "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("Sila tunggu sebentar{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                        "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Hai! Ada apa-apa yang kamu\nmahu buat?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Helo!\nKamu mahu buat sesuatu?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Hai, jumpa lagi kita!\nKali ni nak buat apa pula?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Oh! {PLAYER}, helo!\nKamu mahu buat sesuatu?");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Nak buat sesuatu?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Kamu mahu buat sesuatu?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: Kamu mahu buat\napa sekarang?");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}: Nak buat apa-apa lagi?"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Ada orang menghubungi anda.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} menghubungi anda.{PAUSE 60}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("Menunggu jawapan daripada\nJURULATIH itu…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("Menunggu jawapan daripada\n{STR_VAR_1}…");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("JURULATIH itu menunjukkan\nKAD JURULATIHnya.\pAnda mahu tunjukkan\nKAD JURULATIH anda?");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("JURULATIH itu mencabar anda\nbertarung.\pAnda terima cabaran\npertarungan itu?");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("JURULATIH itu mengajak anda\nbersembang.\pAnda terima jemputan\nsembang itu?");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("Ada tawaran untuk menukar\nLv. {DYNAMIC 0} {DYNAMIC 1} berdaftar anda\pdengan\nLv. {DYNAMIC 2} {DYNAMIC 3}.\pAnda terima tawaran\npertukaran ini?");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("Ada tawaran untuk menukar\nTELUR berdaftar anda.\lAnda terima tawaran ini?");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("Sembang telah terputus.\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("Anda menolak tawaran itu.\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("Anda menolak tawaran itu.\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("Sembang telah tamat.\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("Oh, hei! Kami tengah bersembang.\nNak sertai kami?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Hei, {PLAYER}!\nKami tengah bersembang.\lNak sertai kami?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Oh, hai! Kami sedang bersembang.\nKamu mahu sertai kami?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Oh, hai, {PLAYER}!\nKami sedang bersembang.\lKamu mahu sertai kami?");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……\nJURULATIH itu nampak sibuk…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("Bertarung, ya?\nBaiklah, beri saya sedikit masa.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Nak bersembang, ya?\nBoleh, tunggu sekejap.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Boleh! Sebagai “Salam,”\nini KAD JURULATIH saya.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("Bertarung? Boleh, tapi saya\nperlu masa untuk bersedia.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Kamu mahu bersembang?\nBaiklah, tapi tunggu sebentar.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("Sebagai perkenalan, saya tunjukkan\nKAD JURULATIH saya.");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("Nak bersembang, ya?\nBoleh, tunggu sekejap."); // Unused
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Terima kasih kerana menunggu!\nJom mula bertarung!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("Baiklah!\nJom bual!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Maaf buat kamu tunggu!\nMari kita mula!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Maaf buat kamu tunggu!\nMari bersembang.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("Pertukaran akan dimulakan.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("Pertarungan akan dimulakan.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Memasuki sembang…{PAUSE 60}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Maaf! POKéMON saya macam tak\nberapa sihat sekarang.\lKita bertarung lain kali, ya.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Maaf sangat, tapi POKéMON saya\ntak berapa sihat…\pKita bertarung lain kali, ya.\p");

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Eh? KAD JURULATIH saya…\nMana perginya?\lMaaf! Lain kali saya tunjuk!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Oh? Mana saya letak\nKAD JURULATIH saya?…\lMaaf! Nanti saya tunjuk!\p");

static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Kalau nak buat apa-apa dengan\nsaya, panggil saja!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Kalau nak buat apa-apa dengan\nsaya, jangan malu-malu.\p");

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("Alamak! Maaf, saya ada hal\nlain nak buat.\lLain kali, okey?\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("Kalau nak bertarung, kamu perlu\ndua POKéMON yang di bawah\lLv. 30.\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("Untuk bertarung, kamu perlu dua\nPOKéMON di bawah Lv. 30.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Oh, baiklah.\nJumpa saya bila-bila, okey?\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Oh…\nDatanglah bila-bila masa.\p");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Oh, maaf!\nSaya tak boleh sekarang ni.\lKita sembang lain kali.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Oh, maafkan saya.\nSaya terlalu sibuk sekarang.\lKita sembang lain kali, ya.\p");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Wah!\nKamu memang hebat!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("Kamu guna move itu?\nStrategi yang bagus!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Hebat!\nBuka mata betul!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Oh! Macam mana kamu boleh guna\nPOKéMON itu masa begitu?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("POKéMON itu…\nMemang dibela dengan baik!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("Itu dia!\nInilah move yang tepat!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("Hebatnya!\nBoleh bertarung macam tu?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("Masa kamu menukar POKéMON\nmemang tepat sekali!\p");

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Oh, begitu!\nBanyak saya belajar!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Jangan buat lawak lagi!\nSakit perut saya ketawa!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Oh?\nAda benda macam tu berlaku.\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Hmm… Apa?\nJadi itu yang kamu maksudkan?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Betul ke?\nSaya tak tahu pula.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Ahaha!\nApa maksudnya tu?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Ya, betul sekali!\nItulah maksud saya.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("Dengan kata lain…\nYa! Betul tu!\p");

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("Saya tunjuk KAD JURULATIH saya\nsebagai tanda salam.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("Harap kita dapat kenal lebih rapat!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("Kami bertukar KAD JURULATIH\nuntuk berkenalan.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Gembira berkenalan.\nJangan malu-malu, ya!\p");

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Yeahah!\nSaya memang nak POKéMON ini!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Akhirnya, saya dapat POKéMON\nyang lama saya idamkan.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("Saya sedang tukar POKéMON.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("Akhirnya saya dapat POKéMON\nidaman melalui pertukaran!\p");

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1} memeriksa\nPAPAN TUKARAN.\p");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("Selamat datang ke PAPAN TUKARAN.\pAnda boleh mendaftarkan POKéMON\ndan menawarkannya untuk ditukar.\pAnda mahu mendaftarkan salah satu\nPOKéMON anda?");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("PAPAN TUKARAN ini digunakan untuk\n"
                                                        "menawarkan POKéMON untuk ditukar.\p"
                                                        "Anda cuma perlu mendaftarkan\n"
                                                        "POKéMON untuk ditukar.\p"
                                                        "JURULATIH lain boleh menawarkan\n"
                                                        "POKéMON pasukannya sebagai ganti.\p"
                                                        "Kami harap anda akan mendaftarkan\n"
                                                        "POKéMON dan menukarnya dengan\l"
                                                        "ramai lagi JURULATIH lain.\p"
                                                        "Anda mahu mendaftarkan salah satu\nPOKéMON anda?");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("POKéMON anda telah didaftarkan untuk\nditukar di PAPAN TUKARAN.\pTerima kasih kerana menggunakan\nperkhidmatan ini!\p"); // unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("Tiada sesiapa mendaftarkan POKéMON\nuntuk ditukar di PAPAN TUKARAN.\p\n"); // unused
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("Sila pilih jenis POKéMON\nyang anda mahu dalam pertukaran.\n");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("POKéMON pasukan yang mana anda\nmahu tawarkan untuk ditukar?\p");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("Pendaftaran telah dibatalkan.\p");
ALIGNED(4) static const u8 sText_RegistrationCompleted[] = _("Pendaftaran telah selesai.\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("Pertukaran telah dibatalkan.\p");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("Batalkan pendaftaran\nLv. {STR_VAR_2} {STR_VAR_1} anda?");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("Batalkan pendaftaran\nTELUR anda?");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("Pendaftaran itu telah dibatalkan.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("JURULATIH yang mahu bertukar\nakan disenaraikan."); // unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("Sila pilih JURULATIH yang anda\nmahu bertukar POKéMON."); // unused
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("Anda mahu minta {STR_VAR_1}\nbuat pertukaran?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("Menunggu jawapan daripada\nJURULATIH itu…"); // unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("Anda belum mendaftarkan POKéMON\nuntuk ditukar.\p"); // unused
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("Anda tiada POKéMON jenis {STR_VAR_2}\nyang {STR_VAR_1} mahu.\p");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("Anda tiada TELUR yang\n{STR_VAR_1} mahu.\p");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} tak dapat menukar\nPOKéMON anda sekarang.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("Anda tak dapat menukar POKéMON\n{STR_VAR_1} sekarang.\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("Tawaran pertukaran anda ditolak.\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("TUKAR TELUR");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}PILIH  {A_BUTTON}SERTAI  {B_BUTTON}BATAL");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("Sila pilih JURULATIH.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Sila pilih JURULATIH untuk\nTARUNG TUNGGAL.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Sila pilih JURULATIH untuk\nTARUNG GANDA.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Sila pilih KETUA untuk\nTARUNG MULTI.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Sila pilih JURULATIH untuk\nbertukar.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Sila pilih JURULATIH yang\nberkongsi KAD AJAIB.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Sila pilih JURULATIH yang\nberkongsi BERITA AJAIB.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Lompat dengan POKéMON mini!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("HANCUR BERI!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("PETIK BERI DODRIO!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("PENGISAR BERI!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("SUDUT REKOD!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("PERTANDINGAN KESEGAKAN!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("PERTANDINGAN KECANTIKAN!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("PERTANDINGAN KECOMELAN!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("PERTANDINGAN KEBIJAKSANAAN!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("PERTANDINGAN KETEGAPAN!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("BATTLE TOWER TAHAP 50!\nSila pilih KETUA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("BATTLE TOWER LV. TERBUKA!\nSila pilih KETUA.");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("Mencari SISTEM KOMUNIKASI\nWAYARLES. Tunggu...");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("Untuk TARUNG GANDA, anda perlu\nsekurang-kurangnya dua POKéMON.\p"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("Menunggu jawapan {STR_VAR_1}…");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1} telah diminta mendaftar\nanda sebagai ahli. Sila tunggu.");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("Menunggu jawapan daripada\nSISTEM KOMUNIKASI WAYARLES.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Sila tunggu JURULATIH lain\nberkumpul dan bersedia."); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Tiada KAD dikongsi\nbuat masa ini.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("Tiada BERITA dikongsi\nbuat masa ini.");

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) static const u8 sText_Battle[] = _("TARUNG");
ALIGNED(4) static const u8 sText_Chat2[] = _("SEMBANG");
ALIGNED(4) static const u8 sText_Greetings[] = _("SALAM");
ALIGNED(4) static const u8 sText_Exit[] = _("KELUAR");
ALIGNED(4) static const u8 sText_Exit2[] = _("KELUAR");
ALIGNED(4) static const u8 sText_Info[] = _("INFO");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("NAMA{CLEAR_TO 60}DIMINTA{CLEAR_TO 110}TAWARAN{CLEAR_TO 198}LV.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("TARUNG TUNGGAL");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("TARUNG GANDA");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("TARUNG MULTI");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("TUKAR POKéMON");
ALIGNED(4) static const u8 sText_Chat[] = _("SEMBANG");
ALIGNED(4) static const u8 sText_Cards[] = _("KAD");
ALIGNED(4) static const u8 sText_WonderCards[] = _("KAD AJAIB");
ALIGNED(4) static const u8 sText_WonderNews[] = _("BERITA AJAIB");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("LOMPAT POKéMON");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("HANCUR BERI");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("PETIK BERI");
ALIGNED(4) static const u8 sText_Search[] = _("CARI");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("PENGISAR BERI");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("SUDUT REKOD");
ALIGNED(4) static const u8 sText_CoolContest[] = _("CONTEST SEGAK");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("CONTEST CANTIK");
ALIGNED(4) static const u8 sText_CuteContest[] = _("CONTEST COMEL");
ALIGNED(4) static const u8 sText_SmartContest[] = _("CONTEST BIJAK");
ALIGNED(4) static const u8 sText_ToughContest[] = _("CONTEST TEGAP");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("BATTLE TOWER LV. 50");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("BATTLE TOWER LV. TERBUKA");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("Ini KAD BIASA.");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("Ini KAD GANGSA!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("Ini KAD TEMBAGA!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("Ini KAD PERAK!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("Ini KAD EMAS!");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("KAD JURULATIH\n{DYNAMIC 0} {DYNAMIC 1}…\l{DYNAMIC 2}\pPOKéDEX: {DYNAMIC 3}\nMASA:    {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("TARUNG: MENANG: {DYNAMIC 0}  KALAH: {DYNAMIC 2}\nTUKAR: {DYNAMIC 3}\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Gembira jumpa kamu!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Gembira berkenalan!{PAUSE 60}");

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("Selesai melihat KAD\nJURULATIH {DYNAMIC 1}.{PAUSE 60}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max) (((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity) (capacity & 0x0F)
#define GROUP_MIN(capacity) (capacity >> 4)
#define GROUP_MIN2(capacity) (capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES] = {
    { gTypeNames[TYPE_NORMAL],   TYPE_NORMAL         },
    { gTypeNames[TYPE_FIRE],     TYPE_FIRE           },
    { gTypeNames[TYPE_WATER],    TYPE_WATER          },
    { gTypeNames[TYPE_ELECTRIC], TYPE_ELECTRIC       },
    { gTypeNames[TYPE_GRASS],    TYPE_GRASS          },
    { gTypeNames[TYPE_ICE],      TYPE_ICE            },
    { gTypeNames[TYPE_GROUND],   TYPE_GROUND         },
    { gTypeNames[TYPE_ROCK],     TYPE_ROCK           },
    { gTypeNames[TYPE_FLYING],   TYPE_FLYING         },
    { gTypeNames[TYPE_PSYCHIC],  TYPE_PSYCHIC        },
    { gTypeNames[TYPE_FIGHTING], TYPE_FIGHTING       },
    { gTypeNames[TYPE_POISON],   TYPE_POISON         },
    { gTypeNames[TYPE_BUG],      TYPE_BUG            },
    { gTypeNames[TYPE_GHOST],    TYPE_GHOST          },
    { gTypeNames[TYPE_DRAGON],   TYPE_DRAGON         },
    { gTypeNames[TYPE_STEEL],    TYPE_STEEL          },
    { gTypeNames[TYPE_DARK],     TYPE_DARK           },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, LIST_HEADER },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};
