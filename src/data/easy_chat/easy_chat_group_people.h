const u8 gEasyChatWord_Opponent[] = _("PIHAK LAWAN");
const u8 gEasyChatWord_I[] = _("SAYA");
const u8 gEasyChatWord_You[] = _("KAMU");
const u8 gEasyChatWord_Yours[] = _("MILIKMU");
const u8 gEasyChatWord_Son[] = _("ANAK LELAKI");
const u8 gEasyChatWord_Your[] = _("MILIK KAMU");
const u8 gEasyChatWord_Youre[] = _("KAMU INI");
const u8 gEasyChatWord_Youve[] = _("KAMU DAH");
const u8 gEasyChatWord_Mother[] = _("IBU");
const u8 gEasyChatWord_Grandfather[] = _("DATUK");
const u8 gEasyChatWord_Uncle[] = _("PAKCIK");
const u8 gEasyChatWord_Father[] = _("AYAH");
const u8 gEasyChatWord_Boy[] = _("BUDAK LELAKI");
const u8 gEasyChatWord_Adult[] = _("DEWASA");
const u8 gEasyChatWord_Brother[] = _("ABANG");
const u8 gEasyChatWord_Sister[] = _("KAKAK");
const u8 gEasyChatWord_Grandmother[] = _("NENEK");
const u8 gEasyChatWord_Aunt[] = _("MAKCIK");
const u8 gEasyChatWord_Parent[] = _("IBU BAPA");
const u8 gEasyChatWord_Man[] = _("LELAKI");
const u8 gEasyChatWord_Me[] = _("AKU");
const u8 gEasyChatWord_Girl[] = _("GADIS");
const u8 gEasyChatWord_Babe[] = _("AWEK");
const u8 gEasyChatWord_Family[] = _("KELUARGA");
const u8 gEasyChatWord_Her[] = _("SI GADIS");
const u8 gEasyChatWord_Him[] = _("DIRINYA");
const u8 gEasyChatWord_He[] = _("DIA");
const u8 gEasyChatWord_Place[] = _("TEMPAT");
const u8 gEasyChatWord_Daughter[] = _("ANAK GADIS");
const u8 gEasyChatWord_His[] = _("MILIKNYA");
const u8 gEasyChatWord_Hes[] = _("DIA INI");
const u8 gEasyChatWord_Arent[] = _("BUKANKAH");
const u8 gEasyChatWord_Siblings[] = _("ADIK-BERADIK");
const u8 gEasyChatWord_Kid[] = _("BUDAK");
const u8 gEasyChatWord_Children[] = _("KANAK-KANAK");
const u8 gEasyChatWord_Mr[] = _("ENCIK");
const u8 gEasyChatWord_Mrs[] = _("PUAN");
const u8 gEasyChatWord_Myself[] = _("DIRI SAYA");
const u8 gEasyChatWord_IWas[] = _("SAYA DULU");
const u8 gEasyChatWord_ToMe[] = _("PADA SAYA");
const u8 gEasyChatWord_My[] = _("MILIK SAYA");
const u8 gEasyChatWord_IAm[] = _("SAYA INI");
const u8 gEasyChatWord_Ive[] = _("SAYA DAH");
const u8 gEasyChatWord_Who[] = _("SIAPA");
const u8 gEasyChatWord_Someone[] = _("SESEORANG");
const u8 gEasyChatWord_WhoWas[] = _("SIAPA TADI");
const u8 gEasyChatWord_ToWhom[] = _("PADA SIAPA");
const u8 gEasyChatWord_Whose[] = _("SIAPA PUNYA");
const u8 gEasyChatWord_WhoIs[] = _("SIAPA DIA");
const u8 gEasyChatWord_Its[] = _("IA MEMANG");
const u8 gEasyChatWord_Lady[] = _("WANITA");
const u8 gEasyChatWord_Friend[] = _("KAWAN");
const u8 gEasyChatWord_Ally[] = _("SEKUTU");
const u8 gEasyChatWord_Person[] = _("ORANG");
const u8 gEasyChatWord_Dude[] = _("BRO");
const u8 gEasyChatWord_They[] = _("MEREKA");
const u8 gEasyChatWord_TheyWere[] = _("MEREKA DULU");
const u8 gEasyChatWord_ToThem[] = _("PADA MEREKA");
const u8 gEasyChatWord_Their[] = _("MILIK MEREKA");
const u8 gEasyChatWord_Theyre[] = _("MEREKA INI");
const u8 gEasyChatWord_Theyve[] = _("MEREKA DAH");
const u8 gEasyChatWord_We[] = _("KITA");
const u8 gEasyChatWord_Been[] = _("TELAH");
const u8 gEasyChatWord_ToUs[] = _("PADA KITA");
const u8 gEasyChatWord_Our[] = _("MILIK KITA");
const u8 gEasyChatWord_WeRe[] = _("KITA INI");
const u8 gEasyChatWord_Rival[] = _("SAINGAN");
const u8 gEasyChatWord_Weve[] = _("KITA DAH");
const u8 gEasyChatWord_Woman[] = _("PEREMPUAN");
const u8 gEasyChatWord_She[] = _("SI DIA");
const u8 gEasyChatWord_SheWas[] = _("SI DIA DULU");
const u8 gEasyChatWord_ToHer[] = _("PADA SI DIA");
const u8 gEasyChatWord_Hers[] = _("MILIK SI DIA");
const u8 gEasyChatWord_SheIs[] = _("SI DIA INI");
const u8 gEasyChatWord_Some[] = _("BEBERAPA");

const struct EasyChatWordInfo gEasyChatGroup_People[] = {
    [EC_INDEX(EC_WORD_OPPONENT)] =
    {
        .text = gEasyChatWord_Opponent,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BROTHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I)] =
    {
        .text = gEasyChatWord_I,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIBLINGS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOU)] =
    {
        .text = gEasyChatWord_You,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOURS)] =
    {
        .text = gEasyChatWord_Yours,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAUGHTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SON)] =
    {
        .text = gEasyChatWord_Son,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOUR)] =
    {
        .text = gEasyChatWord_Your,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BABE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOU_RE)] =
    {
        .text = gEasyChatWord_Youre,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FATHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOU_VE)] =
    {
        .text = gEasyChatWord_Youve,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOTHER)] =
    {
        .text = gEasyChatWord_Mother,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DUDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRANDFATHER)] =
    {
        .text = gEasyChatWord_Grandfather,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KID),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNCLE)] =
    {
        .text = gEasyChatWord_Uncle,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BOY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FATHER)] =
    {
        .text = gEasyChatWord_Father,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AREN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BOY)] =
    {
        .text = gEasyChatWord_Boy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRANDFATHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ADULT)] =
    {
        .text = gEasyChatWord_Adult,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ADULT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BROTHER)] =
    {
        .text = gEasyChatWord_Brother,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SISTER)] =
    {
        .text = gEasyChatWord_Sister,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HE_S),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRANDMOTHER)] =
    {
        .text = gEasyChatWord_Grandmother,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MYSELF),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AUNT)] =
    {
        .text = gEasyChatWord_Aunt,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARENT)] =
    {
        .text = gEasyChatWord_Parent,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAN)] =
    {
        .text = gEasyChatWord_Man,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIRL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ME)] =
    {
        .text = gEasyChatWord_Me,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IT_S),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIRL)] =
    {
        .text = gEasyChatWord_Girl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOTHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BABE)] =
    {
        .text = gEasyChatWord_Babe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAMILY)] =
    {
        .text = gEasyChatWord_Family,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SISTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HER)] =
    {
        .text = gEasyChatWord_Her,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIM)] =
    {
        .text = gEasyChatWord_Him,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU_VE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HE)] =
    {
        .text = gEasyChatWord_He,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU_RE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLACE)] =
    {
        .text = gEasyChatWord_Place,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHILDREN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAUGHTER)] =
    {
        .text = gEasyChatWord_Daughter,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRIEND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIS)] =
    {
        .text = gEasyChatWord_His,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAMILY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HE_S)] =
    {
        .text = gEasyChatWord_Hes,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AREN_T)] =
    {
        .text = gEasyChatWord_Arent,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE_VE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIBLINGS)] =
    {
        .text = gEasyChatWord_Siblings,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE_RE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KID)] =
    {
        .text = gEasyChatWord_Kid,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHILDREN)] =
    {
        .text = gEasyChatWord_Children,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AUNT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MR)] =
    {
        .text = gEasyChatWord_Mr,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MRS)] =
    {
        .text = gEasyChatWord_Mrs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_VE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MYSELF)] =
    {
        .text = gEasyChatWord_Myself,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_WAS)] =
    {
        .text = gEasyChatWord_IWas,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_RE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_ME)] =
    {
        .text = gEasyChatWord_ToMe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOUR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MY)] =
    {
        .text = gEasyChatWord_My,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_AM)] =
    {
        .text = gEasyChatWord_IAm,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEIR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_VE)] =
    {
        .text = gEasyChatWord_Ive,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHO)] =
    {
        .text = gEasyChatWord_Who,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMEONE)] =
    {
        .text = gEasyChatWord_Someone,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOURS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHO_WAS)] =
    {
        .text = gEasyChatWord_WhoWas,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_WHOM)] =
    {
        .text = gEasyChatWord_ToWhom,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRANDMOTHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHOSE)] =
    {
        .text = gEasyChatWord_Whose,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERSON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHO_IS)] =
    {
        .text = gEasyChatWord_WhoIs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_US),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IT_S)] =
    {
        .text = gEasyChatWord_Its,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_THEM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LADY)] =
    {
        .text = gEasyChatWord_Lady,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_ME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRIEND)] =
    {
        .text = gEasyChatWord_Friend,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_HER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLY)] =
    {
        .text = gEasyChatWord_Ally,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_WHOM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERSON)] =
    {
        .text = gEasyChatWord_Person,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNCLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DUDE)] =
    {
        .text = gEasyChatWord_Dude,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOMAN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY)] =
    {
        .text = gEasyChatWord_They,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OPPONENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY_WERE)] =
    {
        .text = gEasyChatWord_TheyWere,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MRS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_THEM)] =
    {
        .text = gEasyChatWord_ToThem,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIVAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEIR)] =
    {
        .text = gEasyChatWord_Their,
        .alphabeticalOrder = EC_INDEX(EC_WORD_I),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY_RE)] =
    {
        .text = gEasyChatWord_Theyre,
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_VE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY_VE)] =
    {
        .text = gEasyChatWord_Theyve,
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WE)] =
    {
        .text = gEasyChatWord_We,
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_AM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEEN)] =
    {
        .text = gEasyChatWord_Been,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_US)] =
    {
        .text = gEasyChatWord_ToUs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMEONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUR)] =
    {
        .text = gEasyChatWord_Our,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WE_RE)] =
    {
        .text = gEasyChatWord_WeRe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIVAL)] =
    {
        .text = gEasyChatWord_Rival,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE_IS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WE_VE)] =
    {
        .text = gEasyChatWord_Weve,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOMAN)] =
    {
        .text = gEasyChatWord_Woman,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHE)] =
    {
        .text = gEasyChatWord_She,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO_IS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHE_WAS)] =
    {
        .text = gEasyChatWord_SheWas,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_HER)] =
    {
        .text = gEasyChatWord_ToHer,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERS)] =
    {
        .text = gEasyChatWord_Hers,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHE_IS)] =
    {
        .text = gEasyChatWord_SheIs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLACE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOME)] =
    {
        .text = gEasyChatWord_Some,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LADY),
        .enabled = TRUE,
    },
};
