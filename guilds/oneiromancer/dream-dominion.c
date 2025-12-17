//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-dominion/sovereign-will.c");

    addChild("/guilds/oneiromancer/dream-dominion/sovereign-will.c",
        "/guilds/oneiromancer/dream-dominion/dominion-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-dominion/absolute-command.c");
    addResearchElement("/guilds/oneiromancer/dream-dominion/reality-warp.c");

    addChild("/guilds/oneiromancer/dream-dominion/absolute-command.c",
        "/guilds/oneiromancer/dream-dominion/sovereign-will.c");
    addChild("/guilds/oneiromancer/dream-dominion/reality-warp.c",
        "/guilds/oneiromancer/dream-dominion/sovereign-will.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-dominion/mind-crush.c");

    addChild("/guilds/oneiromancer/dream-dominion/mind-crush.c",
        "/guilds/oneiromancer/dream-dominion/absolute-command.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-dominion/enhanced-dominion.c");
    addResearchElement("/guilds/oneiromancer/dream-dominion/dream-mastery.c");

    addChild("/guilds/oneiromancer/dream-dominion/enhanced-dominion.c",
        "/guilds/oneiromancer/dream-dominion/mind-crush.c");
    addChild("/guilds/oneiromancer/dream-dominion/dream-mastery.c",
        "/guilds/oneiromancer/dream-dominion/reality-warp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-dominion/absolute-dominion.c");

    addChild("/guilds/oneiromancer/dream-dominion/absolute-dominion.c",
        "/guilds/oneiromancer/dream-dominion/enhanced-dominion.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Dream Dominion");
    Description("This research tree provides knowledge of absolute mastery "
        "over the dream realm. These techniques represent the pinnacle of "
        "oneiromantic power. Available only to masters.");
    Source("oneiromancer");
    addResearchElement("/guilds/oneiromancer/dream-dominion/dominion-root.c");
    TreeRoot("/guilds/oneiromancer/dream-dominion/dominion-root.c");

    FirstLevel();
    FifthLevel();
    NinthLevel();
    ThirteenthLevel();
    SeventeenthLevel();
}
