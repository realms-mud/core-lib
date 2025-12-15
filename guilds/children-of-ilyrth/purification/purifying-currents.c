//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/cleansing-waters.c");

    addChild("/guilds/children-of-ilyrth/purification/cleansing-waters.c",
        "/guilds/children-of-ilyrth/purification/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/waters-purity.c");
    addResearchElement("/guilds/children-of-ilyrth/purification/toxin-dilution.c");

    addChild("/guilds/children-of-ilyrth/purification/waters-purity.c",
        "/guilds/children-of-ilyrth/purification/cleansing-waters.c");
    addChild("/guilds/children-of-ilyrth/purification/toxin-dilution.c",
        "/guilds/children-of-ilyrth/purification/cleansing-waters.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/cure-poison.c");
    addResearchElement("/guilds/children-of-ilyrth/purification/soothing-flow.c");

    addChild("/guilds/children-of-ilyrth/purification/cure-poison.c",
        "/guilds/children-of-ilyrth/purification/toxin-dilution.c");
    addChild("/guilds/children-of-ilyrth/purification/soothing-flow.c",
        "/guilds/children-of-ilyrth/purification/waters-purity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/disease-ward.c");
    addResearchElement("/guilds/children-of-ilyrth/purification/tidal-cleansing.c");

    addChild("/guilds/children-of-ilyrth/purification/disease-ward.c",
        "/guilds/children-of-ilyrth/purification/cure-poison.c");
    addChild("/guilds/children-of-ilyrth/purification/tidal-cleansing.c",
        "/guilds/children-of-ilyrth/purification/soothing-flow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/cure-disease.c");
    addResearchElement("/guilds/children-of-ilyrth/purification/purifying-stream.c");

    addChild("/guilds/children-of-ilyrth/purification/cure-disease.c",
        "/guilds/children-of-ilyrth/purification/disease-ward.c");
    addChild("/guilds/children-of-ilyrth/purification/purifying-stream.c",
        "/guilds/children-of-ilyrth/purification/tidal-cleansing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/poison-immunity.c");
    addResearchElement("/guilds/children-of-ilyrth/purification/invigorate.c");

    addChild("/guilds/children-of-ilyrth/purification/poison-immunity.c",
        "/guilds/children-of-ilyrth/purification/cure-poison.c");
    addChild("/guilds/children-of-ilyrth/purification/invigorate.c",
        "/guilds/children-of-ilyrth/purification/purifying-stream.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/paralysis-ward.c");
    addResearchElement("/guilds/children-of-ilyrth/purification/sacred-cleansing.c");

    addChild("/guilds/children-of-ilyrth/purification/paralysis-ward.c",
        "/guilds/children-of-ilyrth/purification/cure-disease.c");
    addChild("/guilds/children-of-ilyrth/purification/sacred-cleansing.c",
        "/guilds/children-of-ilyrth/purification/purifying-stream.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/remove-paralysis.c");

    addChild("/guilds/children-of-ilyrth/purification/remove-paralysis.c",
        "/guilds/children-of-ilyrth/purification/paralysis-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/disease-immunity.c");
    addResearchElement("/guilds/children-of-ilyrth/purification/deep-purification.c");

    addChild("/guilds/children-of-ilyrth/purification/disease-immunity.c",
        "/guilds/children-of-ilyrth/purification/cure-disease.c");
    addChild("/guilds/children-of-ilyrth/purification/deep-purification.c",
        "/guilds/children-of-ilyrth/purification/sacred-cleansing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/corruption-ward.c");
    addResearchElement("/guilds/children-of-ilyrth/purification/ocean-purge.c");

    addChild("/guilds/children-of-ilyrth/purification/corruption-ward.c",
        "/guilds/children-of-ilyrth/purification/remove-paralysis.c");
    addChild("/guilds/children-of-ilyrth/purification/ocean-purge.c",
        "/guilds/children-of-ilyrth/purification/deep-purification.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/paralysis-immunity.c");

    addChild("/guilds/children-of-ilyrth/purification/paralysis-immunity.c",
        "/guilds/children-of-ilyrth/purification/corruption-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/remove-curse.c");
    addResearchElement("/guilds/children-of-ilyrth/purification/ilryths-cleansing.c");

    addChild("/guilds/children-of-ilyrth/purification/remove-curse.c",
        "/guilds/children-of-ilyrth/purification/paralysis-immunity.c");
    addChild("/guilds/children-of-ilyrth/purification/ilryths-cleansing.c",
        "/guilds/children-of-ilyrth/purification/ocean-purge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/psionic-ward.c");

    addChild("/guilds/children-of-ilyrth/purification/psionic-ward.c",
        "/guilds/children-of-ilyrth/purification/remove-curse.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/curse-immunity.c");
    addResearchElement("/guilds/children-of-ilyrth/purification/divine-purification.c");

    addChild("/guilds/children-of-ilyrth/purification/curse-immunity.c",
        "/guilds/children-of-ilyrth/purification/remove-curse.c");
    addChild("/guilds/children-of-ilyrth/purification/divine-purification.c",
        "/guilds/children-of-ilyrth/purification/ilryths-cleansing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/mental-clarity.c");

    addChild("/guilds/children-of-ilyrth/purification/mental-clarity.c",
        "/guilds/children-of-ilyrth/purification/psionic-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/psionic-immunity.c");

    addChild("/guilds/children-of-ilyrth/purification/psionic-immunity.c",
        "/guilds/children-of-ilyrth/purification/mental-clarity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/primordial-purity.c");

    addChild("/guilds/children-of-ilyrth/purification/primordial-purity.c",
        "/guilds/children-of-ilyrth/purification/divine-purification.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/avatar-of-purity.c");

    addChild("/guilds/children-of-ilyrth/purification/avatar-of-purity.c",
        "/guilds/children-of-ilyrth/purification/psionic-immunity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/purification/absolute-purification.c");

    addChild("/guilds/children-of-ilyrth/purification/absolute-purification.c",
        "/guilds/children-of-ilyrth/purification/avatar-of-purity.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Purifying Currents");
    Description("This research tree provides knowledge of cleansing and "
        "purification magic channeled through the divine power of Ilyrth, "
        "goddess of the sea. Her followers learn to wash away poison, cure "
        "disease, remove curses, and protect against all forms of corruption "
        "through the sacred purity of water.");
    Source("Children of Ilyrth");
    addResearchElement("/guilds/children-of-ilyrth/purification/root.c");
    TreeRoot("/guilds/children-of-ilyrth/purification/root.c");

    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyFifthLevel();
    TwentyNinthLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    FortyFirstLevel();
    FortyFifthLevel();
    FiftyFirstLevel();
    FiftySeventhLevel();
    SixtyThirdLevel();
    SixtySeventhLevel();
}
