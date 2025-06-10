//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aeromancer/air/gust.c");
    addChild("/guilds/aeromancer/air/gust.c",
        "/guilds/aeromancer/air/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/aeromancer/air/blast-of-wind.c");
    addChild("/guilds/aeromancer/air/blast-of-wind.c",
        "/guilds/aeromancer/air/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aeromancer/air/arctic-blast.c");
    addChild("/guilds/aeromancer/air/arctic-blast.c",
        "/guilds/aeromancer/air/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aeromancer/air/arctic-focus.c");
    addChild("/guilds/aeromancer/air/arctic-focus.c",
        "/guilds/aeromancer/air/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    //addResearchElement("/guilds/aeromancer/air/zephyr.c");
    //addResearchElement("/guilds/aeromancer/air/wind-blades.c");
    //addResearchElement("/guilds/aeromancer/air/cyclone.c");
    //addResearchElement("/guilds/aeromancer/air/frostweaving.c");

    //addChild("/guilds/aeromancer/air/zephyr.c",
    //    "/guilds/aeromancer/air/gust.c");
    //addChild("/guilds/aeromancer/air/wind-blades.c",
    //    "/guilds/aeromancer/air/root.c");
    //addChild("/guilds/aeromancer/air/cyclone.c",
    //    "/guilds/aeromancer/air/gust.c");
    //addChild("/guilds/aeromancer/air/frostweaving.c",
    //    "/guilds/aeromancer/air/arctic-blast.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    //addResearchElement("/guilds/aeromancer/air/gale-force.c");
    //addChild("/guilds/aeromancer/air/gale-force.c",
    //    "/guilds/aeromancer/air/cyclone.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    //addResearchElement("/guilds/aeromancer/air/air-shield.c");
    //addResearchElement("/guilds/aeromancer/air/vortex.c");

    //addChild("/guilds/aeromancer/air/air-shield.c",
    //    "/guilds/aeromancer/air/cyclone.c");
    //addChild("/guilds/aeromancer/air/vortex.c",
    //    "/guilds/aeromancer/air/blast-of-wind.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    //addResearchElement("/guilds/aeromancer/air/tornado.c");
    //addChild("/guilds/aeromancer/air/tornado.c",
    //    "/guilds/aeromancer/air/zephyr.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    //addResearchElement("/guilds/aeromancer/air/hurricane.c");
    //addChild("/guilds/aeromancer/air/hurricane.c",
    //    "/guilds/aeromancer/air/arctic-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    //addResearchElement("/guilds/aeromancer/air/wind-mastery.c");
    //addChild("/guilds/aeromancer/air/wind-mastery.c",
    //    "/guilds/aeromancer/air/cyclone.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    //addResearchElement("/guilds/aeromancer/air/air-barrier.c");
    //addResearchElement("/guilds/aeromancer/air/storm-call.c");

    //addChild("/guilds/aeromancer/air/air-barrier.c",
    //    "/guilds/aeromancer/air/tornado.c");
    //addChild("/guilds/aeromancer/air/storm-call.c",
    //    "/guilds/aeromancer/air/gale-force.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    //addResearchElement("/guilds/aeromancer/air/wind-walk.c");
    //addChild("/guilds/aeromancer/air/wind-walk.c",
    //    "/guilds/aeromancer/air/air-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    //addResearchElement("/guilds/aeromancer/air/updraft.c");
    //addChild("/guilds/aeromancer/air/updraft.c",
    //    "/guilds/aeromancer/air/air-barrier.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    //addResearchElement("/guilds/aeromancer/air/jetstream.c");
    //addChild("/guilds/aeromancer/air/jetstream.c",
    //    "/guilds/aeromancer/air/wind-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    //addResearchElement("/guilds/aeromancer/air/maelstrom.c");
    //addChild("/guilds/aeromancer/air/maelstrom.c",
    //    "/guilds/aeromancer/air/storm-call.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Air");
    Description("");
    Source("aeromancer");
    addResearchElement("/guilds/aeromancer/air/root.c");
    TreeRoot("/guilds/aeromancer/air/root.c");

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
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
}
