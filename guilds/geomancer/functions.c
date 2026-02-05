//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/geomancer/functions/stone.c");
    addResearchElement("/guilds/geomancer/functions/earth.c");

    addChild("/guilds/geomancer/functions/stone.c",
        "/guilds/geomancer/functions/root.c");
    addChild("/guilds/geomancer/functions/earth.c",
        "/guilds/geomancer/functions/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/geomancer/functions/gravel.c");

    addChild("/guilds/geomancer/functions/gravel.c",
        "/guilds/geomancer/functions/earth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/geomancer/functions/weight.c");

    addChild("/guilds/geomancer/functions/weight.c",
        "/guilds/geomancer/functions/earth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/geomancer/functions/crystal.c");

    addChild("/guilds/geomancer/functions/crystal.c",
        "/guilds/geomancer/functions/stone.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/geomancer/functions/sand.c");

    addChild("/guilds/geomancer/functions/sand.c",
        "/guilds/geomancer/functions/gravel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/geomancer/functions/entombing.c");

    addChild("/guilds/geomancer/functions/entombing.c",
        "/guilds/geomancer/functions/gravel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/geomancer/functions/crushing.c");

    addChild("/guilds/geomancer/functions/crushing.c",
        "/guilds/geomancer/functions/entombing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/geomancer/functions/tectonic.c");

    addChild("/guilds/geomancer/functions/tectonic.c",
        "/guilds/geomancer/functions/crystal.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/geomancer/functions/magma.c");

    addChild("/guilds/geomancer/functions/magma.c",
        "/guilds/geomancer/functions/sand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/geomancer/functions/seismic.c");

    addChild("/guilds/geomancer/functions/seismic.c",
        "/guilds/geomancer/functions/tectonic.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Kinetics");
    Description("This research tree provides knowledge of the various damage "
        "types and propulsion mechanisms for constructed geomancer spells.");
    Source("geomancer");
    addResearchElement("/guilds/geomancer/functions/root.c");
    TreeRoot("/guilds/geomancer/functions/root.c");

    FirstLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
}
