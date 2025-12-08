//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aeromancer/functions/shock.c");
    addResearchElement("/guilds/aeromancer/functions/air.c");

    addChild("/guilds/aeromancer/functions/shock.c",
        "/guilds/aeromancer/functions/root.c");
    addChild("/guilds/aeromancer/functions/air.c",
        "/guilds/aeromancer/functions/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aeromancer/functions/wind.c");

    addChild("/guilds/aeromancer/functions/wind.c",
        "/guilds/aeromancer/functions/air.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aeromancer/functions/thunder.c");

    addChild("/guilds/aeromancer/functions/thunder.c",
        "/guilds/aeromancer/functions/air.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aeromancer/functions/lightning.c");

    addChild("/guilds/aeromancer/functions/lightning.c",
        "/guilds/aeromancer/functions/shock.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aeromancer/functions/chill.c");

    addChild("/guilds/aeromancer/functions/chill.c",
        "/guilds/aeromancer/functions/wind.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aeromancer/functions/vacuum.c");

    addChild("/guilds/aeromancer/functions/vacuum.c",
        "/guilds/aeromancer/functions/wind.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aeromancer/functions/pressure.c");

    addChild("/guilds/aeromancer/functions/pressure.c",
        "/guilds/aeromancer/functions/vacuum.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aeromancer/functions/storm.c");

    addChild("/guilds/aeromancer/functions/storm.c",
        "/guilds/aeromancer/functions/lightning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/functions/plasma.c");

    addChild("/guilds/aeromancer/functions/plasma.c",
        "/guilds/aeromancer/functions/storm.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Kinetics");
    Description("This research tree provides knowledge of the various damage "
        "types and propulsion mechanisms for constructed aeromancer spells.");
    Source("aeromancer");
    addResearchElement("/guilds/aeromancer/functions/root.c");
    TreeRoot("/guilds/aeromancer/functions/root.c");

    FirstLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    TwentyFirstLevel();
}
