//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/pyromancer/forms/arc.c");
    addResearchElement("/guilds/pyromancer/forms/touch.c");
    addResearchElement("/guilds/pyromancer/forms/flare.c");

    addChild("/guilds/pyromancer/forms/arc.c",
        "/guilds/pyromancer/forms/root.c");
    addChild("/guilds/pyromancer/forms/touch.c",
        "/guilds/pyromancer/forms/root.c");
    addChild("/guilds/pyromancer/forms/flare.c",
        "/guilds/pyromancer/forms/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/pyromancer/forms/bolt.c");
    addResearchElement("/guilds/pyromancer/forms/cloud.c");
    addResearchElement("/guilds/pyromancer/forms/spark.c");

    addChild("/guilds/pyromancer/forms/bolt.c",
        "/guilds/pyromancer/forms/arc.c");
    addChild("/guilds/pyromancer/forms/cloud.c",
        "/guilds/pyromancer/forms/touch.c");
    addChild("/guilds/pyromancer/forms/spark.c",
        "/guilds/pyromancer/forms/flare.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/pyromancer/forms/blade.c");
    addResearchElement("/guilds/pyromancer/forms/tendril.c");

    addChild("/guilds/pyromancer/forms/blade.c",
        "/guilds/pyromancer/forms/bolt.c");
    addChild("/guilds/pyromancer/forms/tendril.c",
        "/guilds/pyromancer/forms/spark.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/pyromancer/forms/ball.c");
    addResearchElement("/guilds/pyromancer/forms/spear.c");
    addResearchElement("/guilds/pyromancer/forms/spray.c");

    addChild("/guilds/pyromancer/forms/ball.c",
        "/guilds/pyromancer/forms/bolt.c");
    addChild("/guilds/pyromancer/forms/spear.c",
        "/guilds/pyromancer/forms/blade.c");
    addChild("/guilds/pyromancer/forms/spray.c",
        "/guilds/pyromancer/forms/cloud.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/pyromancer/forms/blast.c");
    addResearchElement("/guilds/pyromancer/forms/wave.c");
    addResearchElement("/guilds/pyromancer/forms/razor.c");

    addChild("/guilds/pyromancer/forms/blast.c",
        "/guilds/pyromancer/forms/ball.c");
    addChild("/guilds/pyromancer/forms/wave.c",
        "/guilds/pyromancer/forms/cloud.c");
    addChild("/guilds/pyromancer/forms/razor.c",
        "/guilds/pyromancer/forms/tendril.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/pyromancer/forms/orb.c");
    addResearchElement("/guilds/pyromancer/forms/ring.c");

    addChild("/guilds/pyromancer/forms/orb.c",
        "/guilds/pyromancer/forms/blast.c");
    addChild("/guilds/pyromancer/forms/ring.c",
        "/guilds/pyromancer/forms/wave.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/pyromancer/forms/wall.c");
    addResearchElement("/guilds/pyromancer/forms/cage.c");
    addResearchElement("/guilds/pyromancer/forms/lance.c");

    addChild("/guilds/pyromancer/forms/wall.c",
        "/guilds/pyromancer/forms/wave.c");
    addChild("/guilds/pyromancer/forms/cage.c",
        "/guilds/pyromancer/forms/ring.c");
    addChild("/guilds/pyromancer/forms/lance.c",
        "/guilds/pyromancer/forms/spear.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/pyromancer/forms/eruption.c");
    addResearchElement("/guilds/pyromancer/forms/strike.c");

    addChild("/guilds/pyromancer/forms/eruption.c",
        "/guilds/pyromancer/forms/orb.c");
    addChild("/guilds/pyromancer/forms/strike.c",
        "/guilds/pyromancer/forms/lance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/pyromancer/forms/coil.c");
    addResearchElement("/guilds/pyromancer/forms/vortex.c");

    addChild("/guilds/pyromancer/forms/coil.c",
        "/guilds/pyromancer/forms/cage.c");
    addChild("/guilds/pyromancer/forms/vortex.c",
        "/guilds/pyromancer/forms/eruption.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/pyromancer/forms/pulse.c");
    addResearchElement("/guilds/pyromancer/forms/inferno.c");

    addChild("/guilds/pyromancer/forms/pulse.c",
        "/guilds/pyromancer/forms/coil.c");
    addChild("/guilds/pyromancer/forms/inferno.c",
        "/guilds/pyromancer/forms/vortex.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/forms/cataclysm.c");

    addChild("/guilds/pyromancer/forms/cataclysm.c",
        "/guilds/pyromancer/forms/strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/pyromancer/forms/firestorm.c");

    addChild("/guilds/pyromancer/forms/firestorm.c",
        "/guilds/pyromancer/forms/inferno.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Forms");
    Description("This research tree provides knowledge of the various forms "
        "that constructed pyromancer spells can take.");
    Source("pyromancer");
    addResearchElement("/guilds/pyromancer/forms/root.c");
    TreeRoot("/guilds/pyromancer/forms/root.c");

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
