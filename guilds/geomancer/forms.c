//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/geomancer/forms/arc.c");
    addResearchElement("/guilds/geomancer/forms/touch.c");
    addResearchElement("/guilds/geomancer/forms/burst.c");

    addChild("/guilds/geomancer/forms/arc.c",
        "/guilds/geomancer/forms/root.c");
    addChild("/guilds/geomancer/forms/touch.c",
        "/guilds/geomancer/forms/root.c");
    addChild("/guilds/geomancer/forms/burst.c",
        "/guilds/geomancer/forms/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/geomancer/forms/bolt.c");
    addResearchElement("/guilds/geomancer/forms/cloud.c");
    addResearchElement("/guilds/geomancer/forms/pebble.c");

    addChild("/guilds/geomancer/forms/bolt.c",
        "/guilds/geomancer/forms/arc.c");
    addChild("/guilds/geomancer/forms/cloud.c",
        "/guilds/geomancer/forms/touch.c");
    addChild("/guilds/geomancer/forms/pebble.c",
        "/guilds/geomancer/forms/burst.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/geomancer/forms/blade.c");
    addResearchElement("/guilds/geomancer/forms/tendril.c");

    addChild("/guilds/geomancer/forms/blade.c",
        "/guilds/geomancer/forms/bolt.c");
    addChild("/guilds/geomancer/forms/tendril.c",
        "/guilds/geomancer/forms/pebble.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/geomancer/forms/ball.c");
    addResearchElement("/guilds/geomancer/forms/spear.c");
    addResearchElement("/guilds/geomancer/forms/spray.c");

    addChild("/guilds/geomancer/forms/ball.c",
        "/guilds/geomancer/forms/bolt.c");
    addChild("/guilds/geomancer/forms/spear.c",
        "/guilds/geomancer/forms/blade.c");
    addChild("/guilds/geomancer/forms/spray.c",
        "/guilds/geomancer/forms/cloud.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/geomancer/forms/blast.c");
    addResearchElement("/guilds/geomancer/forms/wave.c");
    addResearchElement("/guilds/geomancer/forms/razor.c");

    addChild("/guilds/geomancer/forms/blast.c",
        "/guilds/geomancer/forms/ball.c");
    addChild("/guilds/geomancer/forms/wave.c",
        "/guilds/geomancer/forms/cloud.c");
    addChild("/guilds/geomancer/forms/razor.c",
        "/guilds/geomancer/forms/tendril.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/geomancer/forms/orb.c");
    addResearchElement("/guilds/geomancer/forms/ring.c");

    addChild("/guilds/geomancer/forms/orb.c",
        "/guilds/geomancer/forms/blast.c");
    addChild("/guilds/geomancer/forms/ring.c",
        "/guilds/geomancer/forms/wave.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/geomancer/forms/wall.c");
    addResearchElement("/guilds/geomancer/forms/cage.c");
    addResearchElement("/guilds/geomancer/forms/lance.c");

    addChild("/guilds/geomancer/forms/wall.c",
        "/guilds/geomancer/forms/wave.c");
    addChild("/guilds/geomancer/forms/cage.c",
        "/guilds/geomancer/forms/ring.c");
    addChild("/guilds/geomancer/forms/lance.c",
        "/guilds/geomancer/forms/spear.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/geomancer/forms/eruption.c");
    addResearchElement("/guilds/geomancer/forms/strike.c");

    addChild("/guilds/geomancer/forms/eruption.c",
        "/guilds/geomancer/forms/orb.c");
    addChild("/guilds/geomancer/forms/strike.c",
        "/guilds/geomancer/forms/lance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/geomancer/forms/coil.c");
    addResearchElement("/guilds/geomancer/forms/vortex.c");

    addChild("/guilds/geomancer/forms/coil.c",
        "/guilds/geomancer/forms/cage.c");
    addChild("/guilds/geomancer/forms/vortex.c",
        "/guilds/geomancer/forms/eruption.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/geomancer/forms/pulse.c");
    addResearchElement("/guilds/geomancer/forms/quake.c");

    addChild("/guilds/geomancer/forms/pulse.c",
        "/guilds/geomancer/forms/coil.c");
    addChild("/guilds/geomancer/forms/quake.c",
        "/guilds/geomancer/forms/vortex.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/geomancer/forms/avalanche.c");

    addChild("/guilds/geomancer/forms/avalanche.c",
        "/guilds/geomancer/forms/strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/geomancer/forms/cataclysm.c");

    addChild("/guilds/geomancer/forms/cataclysm.c",
        "/guilds/geomancer/forms/quake.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Forms");
    Description("This research tree provides knowledge of the various forms "
        "that constructed geomancer spells can take.");
    Source("geomancer");
    addResearchElement("/guilds/geomancer/forms/root.c");
    TreeRoot("/guilds/geomancer/forms/root.c");

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
}
