//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aeromancer/forms/arc.c");
    addResearchElement("/guilds/aeromancer/forms/touch.c");
    addResearchElement("/guilds/aeromancer/forms/gust.c");

    addChild("/guilds/aeromancer/forms/arc.c",
        "/guilds/aeromancer/forms/root.c");
    addChild("/guilds/aeromancer/forms/touch.c",
        "/guilds/aeromancer/forms/root.c");
    addChild("/guilds/aeromancer/forms/gust.c",
        "/guilds/aeromancer/forms/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/aeromancer/forms/bolt.c");
    addResearchElement("/guilds/aeromancer/forms/mist.c");
    addResearchElement("/guilds/aeromancer/forms/spark.c");

    addChild("/guilds/aeromancer/forms/bolt.c",
        "/guilds/aeromancer/forms/arc.c");
    addChild("/guilds/aeromancer/forms/mist.c",
        "/guilds/aeromancer/forms/touch.c");
    addChild("/guilds/aeromancer/forms/spark.c",
        "/guilds/aeromancer/forms/gust.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aeromancer/forms/blade.c");
    addResearchElement("/guilds/aeromancer/forms/whip.c");

    addChild("/guilds/aeromancer/forms/blade.c",
        "/guilds/aeromancer/forms/bolt.c");
    addChild("/guilds/aeromancer/forms/whip.c",
        "/guilds/aeromancer/forms/spark.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aeromancer/forms/ball.c");
    addResearchElement("/guilds/aeromancer/forms/spear.c");
    addResearchElement("/guilds/aeromancer/forms/breath.c");

    addChild("/guilds/aeromancer/forms/ball.c",
        "/guilds/aeromancer/forms/bolt.c");
    addChild("/guilds/aeromancer/forms/spear.c",
        "/guilds/aeromancer/forms/blade.c");
    addChild("/guilds/aeromancer/forms/breath.c",
        "/guilds/aeromancer/forms/mist.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aeromancer/forms/blast.c");
    addResearchElement("/guilds/aeromancer/forms/wave.c");
    addResearchElement("/guilds/aeromancer/forms/razor.c");

    addChild("/guilds/aeromancer/forms/blast.c",
        "/guilds/aeromancer/forms/ball.c");
    addChild("/guilds/aeromancer/forms/wave.c",
        "/guilds/aeromancer/forms/mist.c");
    addChild("/guilds/aeromancer/forms/razor.c",
        "/guilds/aeromancer/forms/whip.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aeromancer/forms/orb.c");
    addResearchElement("/guilds/aeromancer/forms/ring.c");

    addChild("/guilds/aeromancer/forms/orb.c",
        "/guilds/aeromancer/forms/blast.c");
    addChild("/guilds/aeromancer/forms/ring.c",
        "/guilds/aeromancer/forms/wave.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aeromancer/forms/wall.c");
    addResearchElement("/guilds/aeromancer/forms/cage.c");
    addResearchElement("/guilds/aeromancer/forms/lance.c");

    addChild("/guilds/aeromancer/forms/wall.c",
        "/guilds/aeromancer/forms/wave.c");
    addChild("/guilds/aeromancer/forms/cage.c",
        "/guilds/aeromancer/forms/ring.c");
    addChild("/guilds/aeromancer/forms/lance.c",
        "/guilds/aeromancer/forms/spear.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aeromancer/forms/eruption.c");
    addResearchElement("/guilds/aeromancer/forms/strike.c");

    addChild("/guilds/aeromancer/forms/eruption.c",
        "/guilds/aeromancer/forms/orb.c");
    addChild("/guilds/aeromancer/forms/strike.c",
        "/guilds/aeromancer/forms/lance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aeromancer/forms/coil.c");
    addResearchElement("/guilds/aeromancer/forms/vortex.c");

    addChild("/guilds/aeromancer/forms/coil.c",
        "/guilds/aeromancer/forms/cage.c");
    addChild("/guilds/aeromancer/forms/vortex.c",
        "/guilds/aeromancer/forms/eruption.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/aeromancer/forms/pulse.c");
    addResearchElement("/guilds/aeromancer/forms/cyclone.c");

    addChild("/guilds/aeromancer/forms/pulse.c",
        "/guilds/aeromancer/forms/coil.c");
    addChild("/guilds/aeromancer/forms/cyclone.c",
        "/guilds/aeromancer/forms/vortex.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/forms/nova.c");

    addChild("/guilds/aeromancer/forms/nova.c",
        "/guilds/aeromancer/forms/strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/aeromancer/forms/tornado.c");

    addChild("/guilds/aeromancer/forms/tornado.c",
        "/guilds/aeromancer/forms/cyclone.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Forms");
    Description("This research tree provides knowledge of the various forms "
        "that constructed aeromancer spells can take.");
    Source("aeromancer");
    addResearchElement("/guilds/aeromancer/forms/root.c");
    TreeRoot("/guilds/aeromancer/forms/root.c");

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
