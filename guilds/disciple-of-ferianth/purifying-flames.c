//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/cauterize.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/cauterize.c",
        "/guilds/disciple-of-ferianth/purifying-flames/purifying-flames-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/warmth.c");
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/soothing-flame.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/warmth.c",
        "/guilds/disciple-of-ferianth/purifying-flames/cauterize.c");
    addChild("/guilds/disciple-of-ferianth/purifying-flames/soothing-flame.c",
        "/guilds/disciple-of-ferianth/purifying-flames/cauterize.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/healing-mastery.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/healing-mastery.c",
        "/guilds/disciple-of-ferianth/purifying-flames/cauterize.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/cleansing-fire.c");
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/flame-mend.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/cleansing-fire.c",
        "/guilds/disciple-of-ferianth/purifying-flames/warmth.c");
    addChild("/guilds/disciple-of-ferianth/purifying-flames/flame-mend.c",
        "/guilds/disciple-of-ferianth/purifying-flames/soothing-flame.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/burning-renewal.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/burning-renewal.c",
        "/guilds/disciple-of-ferianth/purifying-flames/flame-mend.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/purge-affliction.c");
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/sacred-warmth.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/purge-affliction.c",
        "/guilds/disciple-of-ferianth/purifying-flames/cleansing-fire.c");
    addChild("/guilds/disciple-of-ferianth/purifying-flames/sacred-warmth.c",
        "/guilds/disciple-of-ferianth/purifying-flames/burning-renewal.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/purifying-potency.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/purifying-potency.c",
        "/guilds/disciple-of-ferianth/purifying-flames/healing-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/phoenix-tears.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/phoenix-tears.c",
        "/guilds/disciple-of-ferianth/purifying-flames/sacred-warmth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/flame-ward.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/flame-ward.c",
        "/guilds/disciple-of-ferianth/purifying-flames/purge-affliction.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/rejuvenating-blaze.c");
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/sanctified-restoration.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/rejuvenating-blaze.c",
        "/guilds/disciple-of-ferianth/purifying-flames/phoenix-tears.c");
    addChild("/guilds/disciple-of-ferianth/purifying-flames/sanctified-restoration.c",
        "/guilds/disciple-of-ferianth/purifying-flames/flame-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/divine-healing-potency.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/divine-healing-potency.c",
        "/guilds/disciple-of-ferianth/purifying-flames/purifying-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/purgatory-embrace.c");
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/burning-sanctuary.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/purgatory-embrace.c",
        "/guilds/disciple-of-ferianth/purifying-flames/rejuvenating-blaze.c");
    addChild("/guilds/disciple-of-ferianth/purifying-flames/burning-sanctuary.c",
        "/guilds/disciple-of-ferianth/purifying-flames/sanctified-restoration.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/sacred-immolation.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/sacred-immolation.c",
        "/guilds/disciple-of-ferianth/purifying-flames/purgatory-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/restorative-focus.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/restorative-focus.c",
        "/guilds/disciple-of-ferianth/purifying-flames/divine-healing-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/cleansing-conflagration.c");
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/phoenix-blessing.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/cleansing-conflagration.c",
        "/guilds/disciple-of-ferianth/purifying-flames/burning-sanctuary.c");
    addChild("/guilds/disciple-of-ferianth/purifying-flames/phoenix-blessing.c",
        "/guilds/disciple-of-ferianth/purifying-flames/sacred-immolation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/fires-of-renewal.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/fires-of-renewal.c",
        "/guilds/disciple-of-ferianth/purifying-flames/phoenix-blessing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/empowered-restoration.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/empowered-restoration.c",
        "/guilds/disciple-of-ferianth/purifying-flames/restorative-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/holy-pyre.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/holy-pyre.c",
        "/guilds/disciple-of-ferianth/purifying-flames/cleansing-conflagration.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/sanctum-of-flame.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/sanctum-of-flame.c",
        "/guilds/disciple-of-ferianth/purifying-flames/holy-pyre.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/divine-restoration.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/divine-restoration.c",
        "/guilds/disciple-of-ferianth/purifying-flames/empowered-restoration.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/ferianths-embrace.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/ferianths-embrace.c",
        "/guilds/disciple-of-ferianth/purifying-flames/sanctum-of-flame.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/divine-absolution.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/divine-absolution.c",
        "/guilds/disciple-of-ferianth/purifying-flames/ferianths-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/master-healer.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/master-healer.c",
        "/guilds/disciple-of-ferianth/purifying-flames/divine-restoration.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/phoenix-ascension.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/phoenix-ascension.c",
        "/guilds/disciple-of-ferianth/purifying-flames/divine-absolution.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/ferianths-salvation.c");

    addChild("/guilds/disciple-of-ferianth/purifying-flames/ferianths-salvation.c",
        "/guilds/disciple-of-ferianth/purifying-flames/phoenix-ascension.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Purifying Flames");
    Description("This research tree provides knowledge of healing and cleansing "
        "magic - the restorative aspect of Ferianth's sacred fire. Through study "
        "of purifying flames, practitioners learn to mend wounds, cure ailments, "
        "and even restore life itself using the god's divine warmth.");
    Source("disciple of ferianth");
    addResearchElement("/guilds/disciple-of-ferianth/purifying-flames/purifying-flames-root.c");
    TreeRoot("/guilds/disciple-of-ferianth/purifying-flames/purifying-flames-root.c");

    FirstLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FortySeventhLevel();
    FiftyFirstLevel();
    FiftyThirdLevel();
    FiftyFifthLevel();
    FiftyNinthLevel();
}
