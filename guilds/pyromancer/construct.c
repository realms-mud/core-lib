//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/pyromancer/construct/construct-spell.c");

    addChild("/guilds/pyromancer/construct/construct-spell.c",
        "/guilds/pyromancer/construct/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/pyromancer/construct/efficient-casting.c");

    addChild("/guilds/pyromancer/construct/efficient-casting.c",
        "/guilds/pyromancer/construct/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/pyromancer/construct/spell-focus.c");

    addChild("/guilds/pyromancer/construct/spell-focus.c",
        "/guilds/pyromancer/construct/efficient-casting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/pyromancer/construct/improved-efficiency.c");

    addChild("/guilds/pyromancer/construct/improved-efficiency.c",
        "/guilds/pyromancer/construct/efficient-casting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/pyromancer/construct/enhanced-focus.c");

    addChild("/guilds/pyromancer/construct/enhanced-focus.c",
        "/guilds/pyromancer/construct/spell-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/construct/expert-efficiency.c");

    addChild("/guilds/pyromancer/construct/expert-efficiency.c",
        "/guilds/pyromancer/construct/improved-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/pyromancer/construct/spell-amplification.c");

    addChild("/guilds/pyromancer/construct/spell-amplification.c",
        "/guilds/pyromancer/construct/enhanced-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/pyromancer/construct/master-efficiency.c");

    addChild("/guilds/pyromancer/construct/master-efficiency.c",
        "/guilds/pyromancer/construct/expert-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/pyromancer/construct/spell-mastery.c");

    addChild("/guilds/pyromancer/construct/spell-mastery.c",
        "/guilds/pyromancer/construct/spell-amplification.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/pyromancer/construct/grandmaster-efficiency.c");

    addChild("/guilds/pyromancer/construct/grandmaster-efficiency.c",
        "/guilds/pyromancer/construct/master-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/construct/arcane-precision.c");

    addChild("/guilds/pyromancer/construct/arcane-precision.c",
        "/guilds/pyromancer/construct/spell-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/pyromancer/construct/legendary-efficiency.c");

    addChild("/guilds/pyromancer/construct/legendary-efficiency.c",
        "/guilds/pyromancer/construct/grandmaster-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/pyromancer/construct/spell-perfection.c");

    addChild("/guilds/pyromancer/construct/spell-perfection.c",
        "/guilds/pyromancer/construct/arcane-precision.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Construction");
    Description("This research tree provides knowledge of constructing custom "
        "pyromancer spells and enhancing their effectiveness.");
    Source("pyromancer");
    addResearchElement("/guilds/pyromancer/construct/root.c");
    TreeRoot("/guilds/pyromancer/construct/root.c");

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
