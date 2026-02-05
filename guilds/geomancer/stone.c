//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/geomancer/stone/pebble.c");

    addChild("/guilds/geomancer/stone/pebble.c",
        "/guilds/geomancer/stone/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/geomancer/stone/stone-lash.c");

    addChild("/guilds/geomancer/stone/stone-lash.c",
        "/guilds/geomancer/stone/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/geomancer/stone/rock-snap.c");

    addChild("/guilds/geomancer/stone/rock-snap.c",
        "/guilds/geomancer/stone/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/geomancer/stone/dust-cloud.c");

    addChild("/guilds/geomancer/stone/dust-cloud.c",
        "/guilds/geomancer/stone/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/geomancer/stone/stone-shards.c");
    addResearchElement("/guilds/geomancer/stone/stone-blades.c");
    addResearchElement("/guilds/geomancer/stone/stone-bolt.c");

    addChild("/guilds/geomancer/stone/stone-shards.c",
        "/guilds/geomancer/stone/pebble.c");
    addChild("/guilds/geomancer/stone/stone-blades.c",
        "/guilds/geomancer/stone/root.c");
    addChild("/guilds/geomancer/stone/stone-bolt.c",
        "/guilds/geomancer/stone/pebble.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/geomancer/stone/stonemasters-reserve.c");

    addChild("/guilds/geomancer/stone/stonemasters-reserve.c",
        "/guilds/geomancer/stone/stone-bolt.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/geomancer/stone/stonemasters-boon.c");
    addResearchElement("/guilds/geomancer/stone/stone-whip.c");

    addChild("/guilds/geomancer/stone/stonemasters-boon.c",
        "/guilds/geomancer/stone/stone-bolt.c");
    addChild("/guilds/geomancer/stone/stone-whip.c",
        "/guilds/geomancer/stone/stone-lash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/geomancer/stone/petrification.c");

    addChild("/guilds/geomancer/stone/petrification.c",
        "/guilds/geomancer/stone/stone-shards.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/geomancer/stone/grinding-wave.c");

    addChild("/guilds/geomancer/stone/grinding-wave.c",
        "/guilds/geomancer/stone/dust-cloud.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/geomancer/stone/rock-discharge.c");

    addChild("/guilds/geomancer/stone/rock-discharge.c",
        "/guilds/geomancer/stone/stone-bolt.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/geomancer/stone/ite.c");
    addResearchElement("/guilds/geomancer/stone/stonemasters-call.c");

    addChild("/guilds/geomancer/stone/ite.c",
        "/guilds/geomancer/stone/petrification.c");
    addChild("/guilds/geomancer/stone/stonemasters-call.c",
        "/guilds/geomancer/stone/stonemasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/geomancer/stone/stonemasters-finesse.c");

    addChild("/guilds/geomancer/stone/stonemasters-finesse.c",
        "/guilds/geomancer/stone/stonemasters-boon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/geomancer/stone/enhanced-stone.c");

    addChild("/guilds/geomancer/stone/enhanced-stone.c",
        "/guilds/geomancer/stone/ite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/geomancer/stone/boulder-storm.c");

    addChild("/guilds/geomancer/stone/boulder-storm.c",
        "/guilds/geomancer/stone/rock-discharge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/geomancer/stone/stonemasters-might.c");

    addChild("/guilds/geomancer/stone/stonemasters-might.c",
        "/guilds/geomancer/stone/stonemasters-call.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/geomancer/stone/geological-induction.c");
    addResearchElement("/guilds/geomancer/stone/stonemasters-endurance.c");

    addChild("/guilds/geomancer/stone/geological-induction.c",
        "/guilds/geomancer/stone/enhanced-stone.c");
    addChild("/guilds/geomancer/stone/stonemasters-endurance.c",
        "/guilds/geomancer/stone/stonemasters-finesse.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/geomancer/stone/raging-avalanche.c");

    addChild("/guilds/geomancer/stone/raging-avalanche.c",
        "/guilds/geomancer/stone/boulder-storm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/geomancer/stone/enhanced-crushing.c");

    addChild("/guilds/geomancer/stone/enhanced-crushing.c",
        "/guilds/geomancer/stone/geological-induction.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/geomancer/stone/stonemasters-fury.c");

    addChild("/guilds/geomancer/stone/stonemasters-fury.c",
        "/guilds/geomancer/stone/stonemasters-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/geomancer/stone/stonemasters-strength.c");

    addChild("/guilds/geomancer/stone/stonemasters-strength.c",
        "/guilds/geomancer/stone/stonemasters-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/geomancer/stone/tectonic-condenser.c");

    addChild("/guilds/geomancer/stone/tectonic-condenser.c",
        "/guilds/geomancer/stone/enhanced-crushing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/geomancer/stone/seismic-burst.c");

    addChild("/guilds/geomancer/stone/seismic-burst.c",
        "/guilds/geomancer/stone/tectonic-condenser.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/geomancer/stone/tectonic-eruption.c");

    addChild("/guilds/geomancer/stone/tectonic-eruption.c",
        "/guilds/geomancer/stone/seismic-burst.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/geomancer/stone/mountain-condenser.c");

    addChild("/guilds/geomancer/stone/mountain-condenser.c",
        "/guilds/geomancer/stone/tectonic-eruption.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/geomancer/stone/earthen-swarm.c");

    addChild("/guilds/geomancer/stone/earthen-swarm.c",
        "/guilds/geomancer/stone/raging-avalanche.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Stone");
    Description("This research tree provides knowledge of stone-based "
        "spells and abilities for the geomancer.");
    Source("geomancer");
    addResearchElement("/guilds/geomancer/stone/root.c");
    TreeRoot("/guilds/geomancer/stone/root.c");

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
