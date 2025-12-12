//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aquamancer/forms/arc.c");
    addResearchElement("/guilds/aquamancer/forms/touch.c");
    addResearchElement("/guilds/aquamancer/forms/splash.c");

    addChild("/guilds/aquamancer/forms/arc.c",
        "/guilds/aquamancer/forms/root.c");
    addChild("/guilds/aquamancer/forms/touch.c",
        "/guilds/aquamancer/forms/root.c");
    addChild("/guilds/aquamancer/forms/splash.c",
        "/guilds/aquamancer/forms/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/aquamancer/forms/bolt.c");
    addResearchElement("/guilds/aquamancer/forms/mist.c");
    addResearchElement("/guilds/aquamancer/forms/droplet.c");

    addChild("/guilds/aquamancer/forms/bolt.c",
        "/guilds/aquamancer/forms/arc.c");
    addChild("/guilds/aquamancer/forms/mist.c",
        "/guilds/aquamancer/forms/touch.c");
    addChild("/guilds/aquamancer/forms/droplet.c",
        "/guilds/aquamancer/forms/splash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aquamancer/forms/blade.c");
    addResearchElement("/guilds/aquamancer/forms/tendril.c");

    addChild("/guilds/aquamancer/forms/blade.c",
        "/guilds/aquamancer/forms/bolt.c");
    addChild("/guilds/aquamancer/forms/tendril.c",
        "/guilds/aquamancer/forms/droplet.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aquamancer/forms/ball.c");
    addResearchElement("/guilds/aquamancer/forms/spear.c");
    addResearchElement("/guilds/aquamancer/forms/spray.c");

    addChild("/guilds/aquamancer/forms/ball.c",
        "/guilds/aquamancer/forms/bolt.c");
    addChild("/guilds/aquamancer/forms/spear.c",
        "/guilds/aquamancer/forms/blade.c");
    addChild("/guilds/aquamancer/forms/spray.c",
        "/guilds/aquamancer/forms/mist.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aquamancer/forms/blast.c");
    addResearchElement("/guilds/aquamancer/forms/wave.c");
    addResearchElement("/guilds/aquamancer/forms/razor.c");

    addChild("/guilds/aquamancer/forms/blast.c",
        "/guilds/aquamancer/forms/ball.c");
    addChild("/guilds/aquamancer/forms/wave.c",
        "/guilds/aquamancer/forms/mist.c");
    addChild("/guilds/aquamancer/forms/razor.c",
        "/guilds/aquamancer/forms/tendril.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aquamancer/forms/orb.c");
    addResearchElement("/guilds/aquamancer/forms/ring.c");

    addChild("/guilds/aquamancer/forms/orb.c",
        "/guilds/aquamancer/forms/blast.c");
    addChild("/guilds/aquamancer/forms/ring.c",
        "/guilds/aquamancer/forms/wave.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aquamancer/forms/wall.c");
    addResearchElement("/guilds/aquamancer/forms/cage.c");
    addResearchElement("/guilds/aquamancer/forms/lance.c");

    addChild("/guilds/aquamancer/forms/wall.c",
        "/guilds/aquamancer/forms/wave.c");
    addChild("/guilds/aquamancer/forms/cage.c",
        "/guilds/aquamancer/forms/ring.c");
    addChild("/guilds/aquamancer/forms/lance.c",
        "/guilds/aquamancer/forms/spear.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aquamancer/forms/geyser.c");
    addResearchElement("/guilds/aquamancer/forms/strike.c");

    addChild("/guilds/aquamancer/forms/geyser.c",
        "/guilds/aquamancer/forms/orb.c");
    addChild("/guilds/aquamancer/forms/strike.c",
        "/guilds/aquamancer/forms/lance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aquamancer/forms/coil.c");
    addResearchElement("/guilds/aquamancer/forms/whirlpool.c");

    addChild("/guilds/aquamancer/forms/coil.c",
        "/guilds/aquamancer/forms/cage.c");
    addChild("/guilds/aquamancer/forms/whirlpool.c",
        "/guilds/aquamancer/forms/geyser.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/aquamancer/forms/pulse.c");
    addResearchElement("/guilds/aquamancer/forms/maelstrom.c");

    addChild("/guilds/aquamancer/forms/pulse.c",
        "/guilds/aquamancer/forms/coil.c");
    addChild("/guilds/aquamancer/forms/maelstrom.c",
        "/guilds/aquamancer/forms/whirlpool.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/forms/tsunami.c");

    addChild("/guilds/aquamancer/forms/tsunami.c",
        "/guilds/aquamancer/forms/strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/aquamancer/forms/waterspout.c");

    addChild("/guilds/aquamancer/forms/waterspout.c",
        "/guilds/aquamancer/forms/maelstrom.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Forms");
    Description("This research tree provides knowledge of the various forms "
        "that constructed aquamancer spells can take.");
    Source("aquamancer");
    addResearchElement("/guilds/aquamancer/forms/root.c");
    TreeRoot("/guilds/aquamancer/forms/root.c");

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
