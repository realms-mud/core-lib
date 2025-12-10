//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aeromancer/construct/construct-spell.c");

    addChild("/guilds/aeromancer/construct/construct-spell.c",
        "/guilds/aeromancer/construct/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aeromancer/construct/efficient-casting.c");

    addChild("/guilds/aeromancer/construct/efficient-casting.c",
        "/guilds/aeromancer/construct/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aeromancer/construct/spell-focus.c");

    addChild("/guilds/aeromancer/construct/spell-focus.c",
        "/guilds/aeromancer/construct/efficient-casting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aeromancer/construct/improved-efficiency.c");

    addChild("/guilds/aeromancer/construct/improved-efficiency.c",
        "/guilds/aeromancer/construct/efficient-casting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aeromancer/construct/enhanced-focus.c");

    addChild("/guilds/aeromancer/construct/enhanced-focus.c",
        "/guilds/aeromancer/construct/spell-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/construct/expert-efficiency.c");

    addChild("/guilds/aeromancer/construct/expert-efficiency.c",
        "/guilds/aeromancer/construct/improved-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/aeromancer/construct/spell-amplification.c");

    addChild("/guilds/aeromancer/construct/spell-amplification.c",
        "/guilds/aeromancer/construct/enhanced-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/aeromancer/construct/master-efficiency.c");

    addChild("/guilds/aeromancer/construct/master-efficiency.c",
        "/guilds/aeromancer/construct/expert-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/aeromancer/construct/spell-mastery.c");

    addChild("/guilds/aeromancer/construct/spell-mastery.c",
        "/guilds/aeromancer/construct/spell-amplification.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/aeromancer/construct/grandmaster-efficiency.c");

    addChild("/guilds/aeromancer/construct/grandmaster-efficiency.c",
        "/guilds/aeromancer/construct/master-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/construct/arcane-precision.c");

    addChild("/guilds/aeromancer/construct/arcane-precision.c",
        "/guilds/aeromancer/construct/spell-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/aeromancer/construct/legendary-efficiency.c");

    addChild("/guilds/aeromancer/construct/legendary-efficiency.c",
        "/guilds/aeromancer/construct/grandmaster-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/aeromancer/construct/spell-perfection.c");

    addChild("/guilds/aeromancer/construct/spell-perfection.c",
        "/guilds/aeromancer/construct/arcane-precision.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Construction");
    Description("This research tree provides knowledge of constructing custom "
        "aeromancer spells and enhancing their effectiveness.");
    Source("aeromancer");
    addResearchElement("/guilds/aeromancer/construct/root.c");
    TreeRoot("/guilds/aeromancer/construct/root.c");

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
