//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-i.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-i.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-i.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-i.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-i.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-i.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-i.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-i.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-i.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-i.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/searing-strikes.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/searing-strikes.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-i.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-ii.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-ii.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-i.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-ii.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-ii.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-i.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-ii.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-ii.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-i.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-ii.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-ii.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-i.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-ii.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-ii.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-i.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/blazing-wrath.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/blazing-wrath.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/searing-strikes.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-iii.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-iii.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-iii.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-iii.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-iii.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-iii.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-iii.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-iii.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-iii.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-iii.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/divine-immolation.c");

    addChild("/guilds/disciple-of-ferianth/divine-conflagration/divine-immolation.c",
        "/guilds/disciple-of-ferianth/divine-conflagration/blazing-wrath.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Divine Conflagration");
    Description("This research tree provides knowledge of summoning and "
        "enhancing a flame guardian - a divine servant of Ferianth formed "
        "of sacred fire.");
    Source("disciple of ferianth");
    addResearchElement("/guilds/disciple-of-ferianth/divine-conflagration/root.c");
    TreeRoot("/guilds/disciple-of-ferianth/divine-conflagration/root.c");

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
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
}
