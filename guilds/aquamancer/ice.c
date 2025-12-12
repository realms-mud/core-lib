//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aquamancer/ice/chill.c");

    addChild("/guilds/aquamancer/ice/chill.c",
        "/guilds/aquamancer/ice/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/aquamancer/ice/ice-lash.c");

    addChild("/guilds/aquamancer/ice/ice-lash.c",
        "/guilds/aquamancer/ice/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aquamancer/ice/frost-snap.c");

    addChild("/guilds/aquamancer/ice/frost-snap.c",
        "/guilds/aquamancer/ice/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aquamancer/ice/freezing-mist.c");

    addChild("/guilds/aquamancer/ice/freezing-mist.c",
        "/guilds/aquamancer/ice/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aquamancer/ice/ice-shards.c");
    addResearchElement("/guilds/aquamancer/ice/frost-blades.c");
    addResearchElement("/guilds/aquamancer/ice/ice-bolt.c");

    addChild("/guilds/aquamancer/ice/ice-shards.c",
        "/guilds/aquamancer/ice/chill.c");
    addChild("/guilds/aquamancer/ice/frost-blades.c",
        "/guilds/aquamancer/ice/root.c");
    addChild("/guilds/aquamancer/ice/ice-bolt.c",
        "/guilds/aquamancer/ice/chill.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aquamancer/ice/frostmasters-reserve.c");

    addChild("/guilds/aquamancer/ice/frostmasters-reserve.c",
        "/guilds/aquamancer/ice/ice-bolt.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aquamancer/ice/frostmasters-boon.c");
    addResearchElement("/guilds/aquamancer/ice/ice-whip.c");

    addChild("/guilds/aquamancer/ice/frostmasters-boon.c",
        "/guilds/aquamancer/ice/ice-bolt.c");
    addChild("/guilds/aquamancer/ice/ice-whip.c",
        "/guilds/aquamancer/ice/ice-lash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aquamancer/ice/cryostatics.c");

    addChild("/guilds/aquamancer/ice/cryostatics.c",
        "/guilds/aquamancer/ice/ice-shards.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aquamancer/ice/freezing-wave.c");

    addChild("/guilds/aquamancer/ice/freezing-wave.c",
        "/guilds/aquamancer/ice/freezing-mist.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/aquamancer/ice/frost-discharge.c");

    addChild("/guilds/aquamancer/ice/frost-discharge.c",
        "/guilds/aquamancer/ice/ice-bolt.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/ice/crystallization.c");
    addResearchElement("/guilds/aquamancer/ice/frostmasters-call.c");

    addChild("/guilds/aquamancer/ice/crystallization.c",
        "/guilds/aquamancer/ice/cryostatics.c");
    addChild("/guilds/aquamancer/ice/frostmasters-call.c",
        "/guilds/aquamancer/ice/frostmasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/aquamancer/ice/frostmasters-finesse.c");

    addChild("/guilds/aquamancer/ice/frostmasters-finesse.c",
        "/guilds/aquamancer/ice/frostmasters-boon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/aquamancer/ice/enhanced-frost.c");

    addChild("/guilds/aquamancer/ice/enhanced-frost.c",
        "/guilds/aquamancer/ice/crystallization.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/aquamancer/ice/hailstorm.c");

    addChild("/guilds/aquamancer/ice/hailstorm.c",
        "/guilds/aquamancer/ice/frost-discharge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/ice/frostmasters-might.c");

    addChild("/guilds/aquamancer/ice/frostmasters-might.c",
        "/guilds/aquamancer/ice/frostmasters-call.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/aquamancer/ice/cryogenic-induction.c");
    addResearchElement("/guilds/aquamancer/ice/frostmasters-endurance.c");

    addChild("/guilds/aquamancer/ice/cryogenic-induction.c",
        "/guilds/aquamancer/ice/enhanced-frost.c");
    addChild("/guilds/aquamancer/ice/frostmasters-endurance.c",
        "/guilds/aquamancer/ice/frostmasters-finesse.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/aquamancer/ice/raging-blizzard.c");

    addChild("/guilds/aquamancer/ice/raging-blizzard.c",
        "/guilds/aquamancer/ice/hailstorm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/aquamancer/ice/enhanced-freezing.c");

    addChild("/guilds/aquamancer/ice/enhanced-freezing.c",
        "/guilds/aquamancer/ice/cryogenic-induction.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/ice/frostmasters-fury.c");

    addChild("/guilds/aquamancer/ice/frostmasters-fury.c",
        "/guilds/aquamancer/ice/frostmasters-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/aquamancer/ice/frostmasters-strength.c");

    addChild("/guilds/aquamancer/ice/frostmasters-strength.c",
        "/guilds/aquamancer/ice/frostmasters-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/aquamancer/ice/cryogenic-condenser.c");

    addChild("/guilds/aquamancer/ice/cryogenic-condenser.c",
        "/guilds/aquamancer/ice/enhanced-freezing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/ice/glacial-burst.c");

    addChild("/guilds/aquamancer/ice/glacial-burst.c",
        "/guilds/aquamancer/ice/cryogenic-condenser.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/aquamancer/ice/permafrost-eruption.c");

    addChild("/guilds/aquamancer/ice/permafrost-eruption.c",
        "/guilds/aquamancer/ice/glacial-burst.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/aquamancer/ice/glacier-condenser.c");

    addChild("/guilds/aquamancer/ice/glacier-condenser.c",
        "/guilds/aquamancer/ice/permafrost-eruption.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/aquamancer/ice/frozen-swarm.c");

    addChild("/guilds/aquamancer/ice/frozen-swarm.c",
        "/guilds/aquamancer/ice/raging-blizzard.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Ice");
    Description("This research tree provides knowledge of ice-based "
        "spells and abilities for the aquamancer.");
    Source("aquamancer");
    addResearchElement("/guilds/aquamancer/ice/root.c");
    TreeRoot("/guilds/aquamancer/ice/root.c");

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
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFirstLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FiftyFirstLevel();
    FiftySeventhLevel();
    SixtyThirdLevel();
    SixtySeventhLevel();
}