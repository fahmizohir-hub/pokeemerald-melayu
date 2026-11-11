const u8 gEasyChatWord_KthxBye[] = _("OK TQ, BAI.");
const u8 gEasyChatWord_YesSirExcl[] = _("BAIK, TUAN!");
const u8 gEasyChatWord_AvantGarde[] = _("PELOPOR");
const u8 gEasyChatWord_Couple[] = _("SEPASANG");
const u8 gEasyChatWord_MuchObliged[] = _("BERJUTA TQ");
const u8 gEasyChatWord_YeehawExcl[] = _("YIHAA!");
const u8 gEasyChatWord_Mega[] = _("MEGA");
const u8 gEasyChatWord_1HitKOExcl[] = _("KO SEKALI!");
const u8 gEasyChatWord_Destiny[] = _("TAKDIR");
const u8 gEasyChatWord_Cancel[] = _("BATAL");
const u8 gEasyChatWord_New[] = _("BARU");
const u8 gEasyChatWord_Flatten[] = _("LENYEK");
const u8 gEasyChatWord_Kidding[] = _("MAIN-MAIN");
const u8 gEasyChatWord_Loser[] = _("PECUNDANG");
const u8 gEasyChatWord_Losing[] = _("SEDANG KALAH");
const u8 gEasyChatWord_Happening[] = _("MERIAH");
const u8 gEasyChatWord_HipAnd[] = _("HIP DAN");
const u8 gEasyChatWord_Shake[] = _("GONCANG");
const u8 gEasyChatWord_Shady[] = _("MENCURIGAKAN");
const u8 gEasyChatWord_Upbeat[] = _("RANCAK");
const u8 gEasyChatWord_Modern[] = _("MODEN");
const u8 gEasyChatWord_SmellYa[] = _("BAU LAGI");
const u8 gEasyChatWord_Bang[] = _("DUM");
const u8 gEasyChatWord_Knockout[] = _("TUMBANG");
const u8 gEasyChatWord_Hassle[] = _("LECEH");
const u8 gEasyChatWord_Winner[] = _("PEMENANG");
const u8 gEasyChatWord_Fever[] = _("DEMAM");
const u8 gEasyChatWord_Wannabe[] = _("PERASAN");
const u8 gEasyChatWord_Baby[] = _("BAYI");
const u8 gEasyChatWord_Heart[] = _("HATI");
const u8 gEasyChatWord_Old[] = _("TUA");
const u8 gEasyChatWord_Young[] = _("MUDA");
const u8 gEasyChatWord_Ugly[] = _("HODOH");

const struct EasyChatWordInfo gEasyChatGroup_TrendySaying[] = {
    [EC_INDEX(EC_WORD_KTHX_BYE)] =
    {
        .text = gEasyChatWord_KthxBye,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YES_SIR_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YES_SIR_EXCL)] =
    {
        .text = gEasyChatWord_YesSirExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AVANT_GARDE)] =
    {
        .text = gEasyChatWord_AvantGarde,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CANCEL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COUPLE)] =
    {
        .text = gEasyChatWord_Couple,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMELL_YA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH_OBLIGED)] =
    {
        .text = gEasyChatWord_MuchObliged,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BABY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEEHAW_EXCL)] =
    {
        .text = gEasyChatWord_YeehawExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH_OBLIGED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEGA)] =
    {
        .text = gEasyChatWord_Mega,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_1_HIT_KO_EXCL)] =
    {
        .text = gEasyChatWord_1HitKOExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BANG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESTINY)] =
    {
        .text = gEasyChatWord_Destiny,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CANCEL)] =
    {
        .text = gEasyChatWord_Cancel,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEART),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEW)] =
    {
        .text = gEasyChatWord_New,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIP_AND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLATTEN)] =
    {
        .text = gEasyChatWord_Flatten,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UGLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIDDING)] =
    {
        .text = gEasyChatWord_Kidding,
        .alphabeticalOrder = EC_INDEX(EC_WORD_1_HIT_KO_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSER)] =
    {
        .text = gEasyChatWord_Loser,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HASSLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSING)] =
    {
        .text = gEasyChatWord_Losing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLATTEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPENING)] =
    {
        .text = gEasyChatWord_Happening,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIDDING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIP_AND)] =
    {
        .text = gEasyChatWord_HipAnd,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEGA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHAKE)] =
    {
        .text = gEasyChatWord_Shake,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHADY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHADY)] =
    {
        .text = gEasyChatWord_Shady,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPENING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPBEAT)] =
    {
        .text = gEasyChatWord_Upbeat,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MODERN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MODERN)] =
    {
        .text = gEasyChatWord_Modern,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOUNG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMELL_YA)] =
    {
        .text = gEasyChatWord_SmellYa,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KTHX_BYE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BANG)] =
    {
        .text = gEasyChatWord_Bang,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOCKOUT)] =
    {
        .text = gEasyChatWord_Knockout,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AVANT_GARDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HASSLE)] =
    {
        .text = gEasyChatWord_Hassle,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WINNER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WINNER)] =
    {
        .text = gEasyChatWord_Winner,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANNABE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEVER)] =
    {
        .text = gEasyChatWord_Fever,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPBEAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANNABE)] =
    {
        .text = gEasyChatWord_Wannabe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BABY)] =
    {
        .text = gEasyChatWord_Baby,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COUPLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEART)] =
    {
        .text = gEasyChatWord_Heart,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESTINY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OLD)] =
    {
        .text = gEasyChatWord_Old,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OLD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOUNG)] =
    {
        .text = gEasyChatWord_Young,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOCKOUT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UGLY)] =
    {
        .text = gEasyChatWord_Ugly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEEHAW_EXCL),
        .enabled = TRUE,
    },
};
