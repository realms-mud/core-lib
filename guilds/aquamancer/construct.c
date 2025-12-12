//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aquamancer/construct/construct-spell.c");

    addChild("/guilds/aquamancer/construct/construct-spell.c",
        "/guilds/aquamancer/construct/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aquamancer/construct/efficient-casting.c");

    addChild("/guilds/aquamancer/construct/efficient-casting.c",
        "/guilds/aquamancer/construct/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aquamancer/construct/spell-focus.c");

    addChild("/guilds/aquamancer/construct/spell-focus.c",
        "/guilds/aquamancer/construct/efficient-casting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aquamancer/construct/improved-efficiency.c");

    addChild("/guilds/aquamancer/construct/improved-efficiency.c",
        "/guilds/aquamancer/construct/efficient-casting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aquamancer/construct/enhanced-focus.c");

    addChild("/guilds/aquamancer/construct/enhanced-focus.c",
        "/guilds/aquamancer/construct/spell-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/construct/expert-efficiency.c");

    addChild("/guilds/aquamancer/construct/expert-efficiency.c",
        "/guilds/aquamancer/construct/improved-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/aquamancer/construct/spell-amplification.c");

    addChild("/guilds/aquamancer/construct/spell-amplification.c",
        "/guilds/aquamancer/construct/enhanced-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/aquamancer/construct/master-efficiency.c");

    addChild("/guilds/aquamancer/construct/master-efficiency.c",
        "/guilds/aquamancer/construct/expert-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/aquamancer/construct/spell-mastery.c");

    addChild("/guilds/aquamancer/construct/spell-mastery.c",
        "/guilds/aquamancer/construct/spell-amplification.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/aquamancer/construct/grandmaster-efficiency.c");

    addChild("/guilds/aquamancer/construct/grandmaster-efficiency.c",
        "/guilds/aquamancer/construct/master-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/construct/arcane-precision.c");

    addChild("/guilds/aquamancer/construct/arcane-precision.c",
        "/guilds/aquamancer/construct/spell-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/aquamancer/construct/legendary-efficiency.c");

    addChild("/guilds/aquamancer/construct/legendary-efficiency.c",
        "/guilds/aquamancer/construct/grandmaster-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/aquamancer/construct/spell-perfection.c");

    addChild("/guilds/aquamancer/construct/spell-perfection.c",
        "/guilds/aquamancer/construct/arcane-precision.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Construction");
    Description("This research tree provides knowledge of constructing custom "
        "aquamancer spells and enhancing their effectiveness.");
    Source("aquamancer");
    addResearchElement("/guilds/aquamancer/construct/root.c");
    TreeRoot("/guilds/aquamancer/construct/root.c");

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