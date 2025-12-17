//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/oneiromancer/lucid-control/clarity-of-purpose.c");

    addChild("/guilds/oneiromancer/lucid-control/clarity-of-purpose.c",
        "/guilds/oneiromancer/lucid-control/lucid-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/lucid-control/focused-dreaming.c");
    addResearchElement("/guilds/oneiromancer/lucid-control/waking-trance.c");

    addChild("/guilds/oneiromancer/lucid-control/focused-dreaming.c",
        "/guilds/oneiromancer/lucid-control/clarity-of-purpose.c");
    addChild("/guilds/oneiromancer/lucid-control/waking-trance.c",
        "/guilds/oneiromancer/lucid-control/clarity-of-purpose.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/lucid-control/lucid-burst.c");

    addChild("/guilds/oneiromancer/lucid-control/lucid-burst.c",
        "/guilds/oneiromancer/lucid-control/focused-dreaming.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/oneiromancer/lucid-control/enhanced-clarity.c");
    addResearchElement("/guilds/oneiromancer/lucid-control/sustained-focus.c");

    addChild("/guilds/oneiromancer/lucid-control/enhanced-clarity.c",
        "/guilds/oneiromancer/lucid-control/lucid-burst.c");
    addChild("/guilds/oneiromancer/lucid-control/sustained-focus.c",
        "/guilds/oneiromancer/lucid-control/waking-trance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/lucid-control/perfect-lucidity.c");

    addChild("/guilds/oneiromancer/lucid-control/perfect-lucidity.c",
        "/guilds/oneiromancer/lucid-control/enhanced-clarity.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Lucid Control");
    Description("This research tree provides knowledge of maintaining lucid "
        "awareness while channeling dream energy. These techniques improve "
        "spell efficiency and mental clarity. Available only to adepts and "
        "higher ranks.");
    Source("oneiromancer");
    addResearchElement("/guilds/oneiromancer/lucid-control/lucid-root.c");
    TreeRoot("/guilds/oneiromancer/lucid-control/lucid-root.c");

    FirstLevel();
    ThirdLevel();
    SeventhLevel();
    EleventhLevel();
    FifteenthLevel();
}
