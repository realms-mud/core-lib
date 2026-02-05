//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/geomancer/construct/construct-spell.c");

    addChild("/guilds/geomancer/construct/construct-spell.c",
        "/guilds/geomancer/construct/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/geomancer/construct/efficient-casting.c");

    addChild("/guilds/geomancer/construct/efficient-casting.c",
        "/guilds/geomancer/construct/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/geomancer/construct/spell-focus.c");

    addChild("/guilds/geomancer/construct/spell-focus.c",
        "/guilds/geomancer/construct/efficient-casting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/geomancer/construct/improved-efficiency.c");

    addChild("/guilds/geomancer/construct/improved-efficiency.c",
        "/guilds/geomancer/construct/efficient-casting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/geomancer/construct/enhanced-focus.c");

    addChild("/guilds/geomancer/construct/enhanced-focus.c",
        "/guilds/geomancer/construct/spell-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/geomancer/construct/expert-efficiency.c");

    addChild("/guilds/geomancer/construct/expert-efficiency.c",
        "/guilds/geomancer/construct/improved-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/geomancer/construct/spell-amplification.c");

    addChild("/guilds/geomancer/construct/spell-amplification.c",
        "/guilds/geomancer/construct/enhanced-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/geomancer/construct/master-efficiency.c");

    addChild("/guilds/geomancer/construct/master-efficiency.c",
        "/guilds/geomancer/construct/expert-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/geomancer/construct/spell-mastery.c");

    addChild("/guilds/geomancer/construct/spell-mastery.c",
        "/guilds/geomancer/construct/spell-amplification.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/geomancer/construct/grandmaster-efficiency.c");

    addChild("/guilds/geomancer/construct/grandmaster-efficiency.c",
        "/guilds/geomancer/construct/master-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/geomancer/construct/arcane-precision.c");

    addChild("/guilds/geomancer/construct/arcane-precision.c",
        "/guilds/geomancer/construct/spell-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/geomancer/construct/legendary-efficiency.c");

    addChild("/guilds/geomancer/construct/legendary-efficiency.c",
        "/guilds/geomancer/construct/grandmaster-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/geomancer/construct/spell-perfection.c");

    addChild("/guilds/geomancer/construct/spell-perfection.c",
        "/guilds/geomancer/construct/arcane-precision.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Construction");
    Description("This research tree provides knowledge of constructing custom "
        "geomancer spells and enhancing their effectiveness.");
    Source("geomancer");
    addResearchElement("/guilds/geomancer/construct/root.c");
    TreeRoot("/guilds/geomancer/construct/root.c");

    FirstLevel();
    FifthLevel();
    NinthLevel();
    ThirteenthLevel();
    SeventeenthLevel();
    TwentyFirstLevel();
    TwentyFifthLevel();
    TwentyNinthLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    FortyFirstLevel();
    FortyFifthLevel();
    FortyNinthLevel();
}
