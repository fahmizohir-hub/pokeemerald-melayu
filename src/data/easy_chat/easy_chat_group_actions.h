const u8 gEasyChatWord_Meets[] = _("BERJUMPA");
const u8 gEasyChatWord_Concede[] = _("MENGALAH");
const u8 gEasyChatWord_Give[] = _("BERI");
const u8 gEasyChatWord_Gives[] = _("MEMBERI");
const u8 gEasyChatWord_Played[] = _("DAH BERMAIN");
const u8 gEasyChatWord_Plays[] = _("BERMAIN");
const u8 gEasyChatWord_Collect[] = _("KUMPUL");
const u8 gEasyChatWord_Walking[] = _("BERSIAR-SIAR");
const u8 gEasyChatWord_Walks[] = _("BERJALAN");
const u8 gEasyChatWord_Says[] = _("BERKATA");
const u8 gEasyChatWord_Went[] = _("DAH PERGI");
const u8 gEasyChatWord_Said[] = _("KATANYA");
const u8 gEasyChatWord_WakeUp[] = _("BANGUN");
const u8 gEasyChatWord_WakesUp[] = _("TERJAGA");
const u8 gEasyChatWord_Angers[] = _("MEMARAHKAN");
const u8 gEasyChatWord_Teach[] = _("AJAR");
const u8 gEasyChatWord_Teaches[] = _("MENGAJAR");
const u8 gEasyChatWord_Please[] = _("TOLONGLAH");
const u8 gEasyChatWord_Learn[] = _("BELAJAR");
const u8 gEasyChatWord_Change[] = _("UBAH");
const u8 gEasyChatWord_Story[] = _("CERITA");
const u8 gEasyChatWord_Trust[] = _("MEMPERCAYAI");
const u8 gEasyChatWord_Lavish[] = _("MEWAH");
const u8 gEasyChatWord_Listens[] = _("MENDENGARKAN");
const u8 gEasyChatWord_Hearing[] = _("PENDENGARAN");
const u8 gEasyChatWord_Trains[] = _("BERLATIH");
const u8 gEasyChatWord_Choose[] = _("PILIH");
const u8 gEasyChatWord_Come[] = _("DATANG");
const u8 gEasyChatWord_Came[] = _("DAH DATANG");
const u8 gEasyChatWord_Search[] = _("CARI");
const u8 gEasyChatWord_Make[] = _("BUAT");
const u8 gEasyChatWord_Cause[] = _("MENYEBABKAN");
const u8 gEasyChatWord_Know[] = _("TAHU");
const u8 gEasyChatWord_Knows[] = _("MENGETAHUI");
const u8 gEasyChatWord_Refuse[] = _("ENGGAN");
const u8 gEasyChatWord_Stores[] = _("MENYIMPAN");
const u8 gEasyChatWord_Brag[] = _("BERMEGAH");
const u8 gEasyChatWord_Ignorant[] = _("JAHIL");
const u8 gEasyChatWord_Thinks[] = _("BERFIKIR");
const u8 gEasyChatWord_Believe[] = _("PERCAYA");
const u8 gEasyChatWord_Slide[] = _("GELONGSOR");
const u8 gEasyChatWord_Eats[] = _("MEMAKAN");
const u8 gEasyChatWord_Use[] = _("GUNA");
const u8 gEasyChatWord_Uses[] = _("MENGGUNAKAN");
const u8 gEasyChatWord_Using[] = _("SEDANG GUNA");
const u8 gEasyChatWord_Couldnt[] = _("TAK DAPAT");
const u8 gEasyChatWord_Capable[] = _("MAMPU");
const u8 gEasyChatWord_Disappear[] = _("LENYAP");
const u8 gEasyChatWord_Appear[] = _("MUNCUL");
const u8 gEasyChatWord_Throw[] = _("BALING");
const u8 gEasyChatWord_Worry[] = _("RISAU");
const u8 gEasyChatWord_Slept[] = _("DAH TIDUR");
const u8 gEasyChatWord_Sleep[] = _("TIDUR");
const u8 gEasyChatWord_Release[] = _("LEPASKAN");
const u8 gEasyChatWord_Drinks[] = _("MEMINUM");
const u8 gEasyChatWord_Runs[] = _("BERLARI");
const u8 gEasyChatWord_Run[] = _("LARI");
const u8 gEasyChatWord_Works[] = _("BEKERJA");
const u8 gEasyChatWord_Working[] = _("SEDANG KERJA");
const u8 gEasyChatWord_Talking[] = _("BERBUAL");
const u8 gEasyChatWord_Talk[] = _("CAKAP");
const u8 gEasyChatWord_Sink[] = _("TENGGELAM");
const u8 gEasyChatWord_Smack[] = _("TAMPAR");
const u8 gEasyChatWord_Pretend[] = _("BERPURA-PURA");
const u8 gEasyChatWord_Praise[] = _("PUJI");
const u8 gEasyChatWord_Overdo[] = _("MELAMPAU");
const u8 gEasyChatWord_Show[] = _("TUNJUK");
const u8 gEasyChatWord_Looks[] = _("NAMPAK");
const u8 gEasyChatWord_Sees[] = _("MELIHAT");
const u8 gEasyChatWord_Seek[] = _("MENCARI");
const u8 gEasyChatWord_Own[] = _("MEMILIKI");
const u8 gEasyChatWord_Take[] = _("AMBIL");
const u8 gEasyChatWord_Allow[] = _("BENARKAN");
const u8 gEasyChatWord_Forget[] = _("LUPA");
const u8 gEasyChatWord_Forgets[] = _("MELUPAKAN");
const u8 gEasyChatWord_Appears[] = _("MENJELMA");
const u8 gEasyChatWord_Faint[] = _("PENGSAN");
const u8 gEasyChatWord_Fainted[] = _("DAH PENGSAN");

const struct EasyChatWordInfo gEasyChatGroup_Actions[] = {
    [EC_INDEX(EC_WORD_MEETS)] =
    {
        .text = gEasyChatWord_Meets,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONCEDE)] =
    {
        .text = gEasyChatWord_Concede,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE)] =
    {
        .text = gEasyChatWord_Give,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THROW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVES)] =
    {
        .text = gEasyChatWord_Gives,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAKE_UP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAYED)] =
    {
        .text = gEasyChatWord_Played,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAYS)] =
    {
        .text = gEasyChatWord_Plays,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEARN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLLECT)] =
    {
        .text = gEasyChatWord_Collect,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WALKING)] =
    {
        .text = gEasyChatWord_Walking,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALKING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WALKS)] =
    {
        .text = gEasyChatWord_Walks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAYS)] =
    {
        .text = gEasyChatWord_Says,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WENT)] =
    {
        .text = gEasyChatWord_Went,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAID)] =
    {
        .text = gEasyChatWord_Said,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEETS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAKE_UP)] =
    {
        .text = gEasyChatWord_WakeUp,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAYS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAKES_UP)] =
    {
        .text = gEasyChatWord_WakesUp,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUNS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANGERS)] =
    {
        .text = gEasyChatWord_Angers,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAINS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACH)] =
    {
        .text = gEasyChatWord_Teach,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAYS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACHES)] =
    {
        .text = gEasyChatWord_Teaches,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BRAG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLEASE)] =
    {
        .text = gEasyChatWord_Please,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRETEND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEARN)] =
    {
        .text = gEasyChatWord_Learn,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALKING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHANGE)] =
    {
        .text = gEasyChatWord_Change,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORY)] =
    {
        .text = gEasyChatWord_Story,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRUST)] =
    {
        .text = gEasyChatWord_Trust,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEARCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LAVISH)] =
    {
        .text = gEasyChatWord_Lavish,
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LISTENS)] =
    {
        .text = gEasyChatWord_Listens,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAYED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEARING)] =
    {
        .text = gEasyChatWord_Hearing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAINS)] =
    {
        .text = gEasyChatWord_Trains,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAINTED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOOSE)] =
    {
        .text = gEasyChatWord_Choose,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME)] =
    {
        .text = gEasyChatWord_Come,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLEPT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAME)] =
    {
        .text = gEasyChatWord_Came,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEARCH)] =
    {
        .text = gEasyChatWord_Search,
        .alphabeticalOrder = EC_INDEX(EC_WORD_REFUSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAKE)] =
    {
        .text = gEasyChatWord_Make,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAUSE)] =
    {
        .text = gEasyChatWord_Cause,
        .alphabeticalOrder = EC_INDEX(EC_WORD_USE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOW)] =
    {
        .text = gEasyChatWord_Know,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IGNORANT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOWS)] =
    {
        .text = gEasyChatWord_Knows,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAID),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REFUSE)] =
    {
        .text = gEasyChatWord_Refuse,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLLECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORES)] =
    {
        .text = gEasyChatWord_Stores,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BRAG)] =
    {
        .text = gEasyChatWord_Brag,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IGNORANT)] =
    {
        .text = gEasyChatWord_Ignorant,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RELEASE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINKS)] =
    {
        .text = gEasyChatWord_Thinks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELIEVE)] =
    {
        .text = gEasyChatWord_Believe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAPABLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLIDE)] =
    {
        .text = gEasyChatWord_Slide,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERDO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EATS)] =
    {
        .text = gEasyChatWord_Eats,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USE)] =
    {
        .text = gEasyChatWord_Use,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGETS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USES)] =
    {
        .text = gEasyChatWord_Uses,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EATS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USING)] =
    {
        .text = gEasyChatWord_Using,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANGERS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COULDN_T)] =
    {
        .text = gEasyChatWord_Couldnt,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAPABLE)] =
    {
        .text = gEasyChatWord_Capable,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OWN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPEAR)] =
    {
        .text = gEasyChatWord_Disappear,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRINKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPEAR)] =
    {
        .text = gEasyChatWord_Appear,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRUST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THROW)] =
    {
        .text = gEasyChatWord_Throw,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEEK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORRY)] =
    {
        .text = gEasyChatWord_Worry,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTENS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLEPT)] =
    {
        .text = gEasyChatWord_Slept,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACHES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLEEP)] =
    {
        .text = gEasyChatWord_Sleep,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONCEDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RELEASE)] =
    {
        .text = gEasyChatWord_Release,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOWS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DRINKS)] =
    {
        .text = gEasyChatWord_Drinks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_USES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUNS)] =
    {
        .text = gEasyChatWord_Runs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEARS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUN)] =
    {
        .text = gEasyChatWord_Run,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAUSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORKS)] =
    {
        .text = gEasyChatWord_Works,
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORKING)] =
    {
        .text = gEasyChatWord_Working,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LAVISH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALKING)] =
    {
        .text = gEasyChatWord_Talking,
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALK)] =
    {
        .text = gEasyChatWord_Talk,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOOKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SINK)] =
    {
        .text = gEasyChatWord_Sink,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEARING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMACK)] =
    {
        .text = gEasyChatWord_Smack,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAINT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRETEND)] =
    {
        .text = gEasyChatWord_Pretend,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELIEVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRAISE)] =
    {
        .text = gEasyChatWord_Praise,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHOOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERDO)] =
    {
        .text = gEasyChatWord_Overdo,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRAISE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOW)] =
    {
        .text = gEasyChatWord_Show,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOOKS)] =
    {
        .text = gEasyChatWord_Looks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_USING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEES)] =
    {
        .text = gEasyChatWord_Sees,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORKING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEEK)] =
    {
        .text = gEasyChatWord_Seek,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OWN)] =
    {
        .text = gEasyChatWord_Own,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COULDN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TAKE)] =
    {
        .text = gEasyChatWord_Take,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMACK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLOW)] =
    {
        .text = gEasyChatWord_Allow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SINK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGET)] =
    {
        .text = gEasyChatWord_Forget,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAKES_UP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGETS)] =
    {
        .text = gEasyChatWord_Forgets,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLEEP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPEARS)] =
    {
        .text = gEasyChatWord_Appears,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLEASE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAINT)] =
    {
        .text = gEasyChatWord_Faint,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAINTED)] =
    {
        .text = gEasyChatWord_Fainted,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHANGE),
        .enabled = TRUE,
    },
};
