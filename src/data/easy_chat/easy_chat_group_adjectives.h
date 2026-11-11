const u8 gEasyChatWord_Wandering[] = _("MERAYAU");
const u8 gEasyChatWord_Rickety[] = _("REYOT");
const u8 gEasyChatWord_RockSolid[] = _("KUKUH");
const u8 gEasyChatWord_Hungry[] = _("LAPAR");
const u8 gEasyChatWord_Tight[] = _("KETAT");
const u8 gEasyChatWord_Ticklish[] = _("GELI");
const u8 gEasyChatWord_Twirling[] = _("BERPUSING");
const u8 gEasyChatWord_Spiraling[] = _("BERPUSAR");
const u8 gEasyChatWord_Thirsty[] = _("DAHAGA");
const u8 gEasyChatWord_Lolling[] = _("TERJELIR");
const u8 gEasyChatWord_Silky[] = _("HALUS");
const u8 gEasyChatWord_Sadly[] = _("SAYANGNYA");
const u8 gEasyChatWord_Hopeless[] = _("TAK BERHARAP");
const u8 gEasyChatWord_Useless[] = _("TAK BERGUNA");
const u8 gEasyChatWord_Drooling[] = _("BERLIUR");
const u8 gEasyChatWord_Exciting[] = _("MENGUJAKAN");
const u8 gEasyChatWord_Thick[] = _("TEBAL");
const u8 gEasyChatWord_Smooth[] = _("LICIN");
const u8 gEasyChatWord_Slimy[] = _("BERLENDIR");
const u8 gEasyChatWord_Thin[] = _("NIPIS");
const u8 gEasyChatWord_Break[] = _("PECAH");
const u8 gEasyChatWord_Voracious[] = _("GELOJOH");
const u8 gEasyChatWord_Scatter[] = _("BERSELERAK");
const u8 gEasyChatWord_Awesome[] = _("GEMPAK");
const u8 gEasyChatWord_Wimpy[] = _("LEMBIK");
const u8 gEasyChatWord_Wobbly[] = _("BERGOYANG");
const u8 gEasyChatWord_Shaky[] = _("GOYAH");
const u8 gEasyChatWord_Ripped[] = _("KOYAK");
const u8 gEasyChatWord_Shredded[] = _("RABAK");
const u8 gEasyChatWord_Increasing[] = _("MENINGKAT");
const u8 gEasyChatWord_Yet[] = _("MASIH");
const u8 gEasyChatWord_Destroyed[] = _("MUSNAH");
const u8 gEasyChatWord_Fiery[] = _("BERAPI");
const u8 gEasyChatWord_LoveyDovey[] = _("ASYIK MASYUK");
const u8 gEasyChatWord_Happily[] = _("RIANG RIA");
const u8 gEasyChatWord_Anticipation[] = _("PENANTIAN");

const struct EasyChatWordInfo gEasyChatGroup_Adjectives[] = {
    [EC_INDEX(EC_WORD_WANDERING)] =
    {
        .text = gEasyChatWord_Wandering,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOVEY_DOVEY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RICKETY)] =
    {
        .text = gEasyChatWord_Rickety,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROCK_SOLID)] =
    {
        .text = gEasyChatWord_RockSolid,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOBBLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUNGRY)] =
    {
        .text = gEasyChatWord_Hungry,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLIMY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIGHT)] =
    {
        .text = gEasyChatWord_Tight,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DROOLING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TICKLISH)] =
    {
        .text = gEasyChatWord_Ticklish,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPIRALING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TWIRLING)] =
    {
        .text = gEasyChatWord_Twirling,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TWIRLING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPIRALING)] =
    {
        .text = gEasyChatWord_Spiraling,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCATTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIRSTY)] =
    {
        .text = gEasyChatWord_Thirsty,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIRSTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOLLING)] =
    {
        .text = gEasyChatWord_Lolling,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TICKLISH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SILKY)] =
    {
        .text = gEasyChatWord_Silky,
        .alphabeticalOrder = EC_INDEX(EC_WORD_VORACIOUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SADLY)] =
    {
        .text = gEasyChatWord_Sadly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWESOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOPELESS)] =
    {
        .text = gEasyChatWord_Hopeless,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHAKY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USELESS)] =
    {
        .text = gEasyChatWord_Useless,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SILKY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DROOLING)] =
    {
        .text = gEasyChatWord_Drooling,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIGHT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCITING)] =
    {
        .text = gEasyChatWord_Exciting,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIPPED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THICK)] =
    {
        .text = gEasyChatWord_Thick,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROCK_SOLID),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMOOTH)] =
    {
        .text = gEasyChatWord_Smooth,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUNGRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLIMY)] =
    {
        .text = gEasyChatWord_Slimy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIMPY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIN)] =
    {
        .text = gEasyChatWord_Thin,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMOOTH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BREAK)] =
    {
        .text = gEasyChatWord_Break,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VORACIOUS)] =
    {
        .text = gEasyChatWord_Voracious,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCITING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCATTER)] =
    {
        .text = gEasyChatWord_Scatter,
        .alphabeticalOrder = EC_INDEX(EC_WORD_INCREASING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWESOME)] =
    {
        .text = gEasyChatWord_Awesome,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANDERING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIMPY)] =
    {
        .text = gEasyChatWord_Wimpy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESTROYED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOBBLY)] =
    {
        .text = gEasyChatWord_Wobbly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHAKY)] =
    {
        .text = gEasyChatWord_Shaky,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BREAK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIPPED)] =
    {
        .text = gEasyChatWord_Ripped,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANTICIPATION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHREDDED)] =
    {
        .text = gEasyChatWord_Shredded,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHREDDED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INCREASING)] =
    {
        .text = gEasyChatWord_Increasing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RICKETY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YET)] =
    {
        .text = gEasyChatWord_Yet,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPILY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESTROYED)] =
    {
        .text = gEasyChatWord_Destroyed,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SADLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIERY)] =
    {
        .text = gEasyChatWord_Fiery,
        .alphabeticalOrder = EC_INDEX(EC_WORD_USELESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOVEY_DOVEY)] =
    {
        .text = gEasyChatWord_LoveyDovey,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOPELESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPILY)] =
    {
        .text = gEasyChatWord_Happily,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THICK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANTICIPATION)] =
    {
        .text = gEasyChatWord_Anticipation,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOLLING),
        .enabled = TRUE,
    },
};
