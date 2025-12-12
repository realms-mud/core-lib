//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aquamancer/functions/chill.c");
    addResearchElement("/guilds/aquamancer/functions/water.c");

    addChild("/guilds/aquamancer/functions/chill.c",
        "/guilds/aquamancer/functions/root.c");
    addChild("/guilds/aquamancer/functions/water.c",
        "/guilds/aquamancer/functions/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aquamancer/functions/current.c");

    addChild("/guilds/aquamancer/functions/current.c",
        "/guilds/aquamancer/functions/water.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aquamancer/functions/pressure.c");

    addChild("/guilds/aquamancer/functions/pressure.c",
        "/guilds/aquamancer/functions/water.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aquamancer/functions/ice.c");

    addChild("/guilds/aquamancer/functions/ice.c",
        "/guilds/aquamancer/functions/chill.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aquamancer/functions/steam.c");

    addChild("/guilds/aquamancer/functions/steam.c",
        "/guilds/aquamancer/functions/current.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aquamancer/functions/drowning.c");

    addChild("/guilds/aquamancer/functions/drowning.c",
        "/guilds/aquamancer/functions/current.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aquamancer/functions/crushing.c");

    addChild("/guilds/aquamancer/functions/crushing.c",
        "/guilds/aquamancer/functions/drowning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aquamancer/functions/tempest.c");

    addChild("/guilds/aquamancer/functions/tempest.c",
        "/guilds/aquamancer/functions/ice.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/aquamancer/functions/acid.c");

    addChild("/guilds/aquamancer/functions/acid.c",
        "/guilds/aquamancer/functions/steam.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/functions/brine.c");

    addChild("/guilds/aquamancer/functions/brine.c",
        "/guilds/aquamancer/functions/tempest.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Kinetics");
    Description("This research tree provides knowledge of the various damage "
        "types and propulsion mechanisms for constructed aquamancer spells.");
    Source("aquamancer");
    addResearchElement("/guilds/aquamancer/functions/root.c");
    TreeRoot("/guilds/aquamancer/functions/root.c");

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
