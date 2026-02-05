//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/pyromancer/flame/ignite.c");

    addChild("/guilds/pyromancer/flame/ignite.c",
        "/guilds/pyromancer/flame/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/pyromancer/flame/flame-lash.c");

    addChild("/guilds/pyromancer/flame/flame-lash.c",
        "/guilds/pyromancer/flame/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/pyromancer/flame/flash-fire.c");

    addChild("/guilds/pyromancer/flame/flash-fire.c",
        "/guilds/pyromancer/flame/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/pyromancer/flame/scorching-mist.c");

    addChild("/guilds/pyromancer/flame/scorching-mist.c",
        "/guilds/pyromancer/flame/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/pyromancer/flame/flame-shards.c");
    addResearchElement("/guilds/pyromancer/flame/blazing-blades.c");
    addResearchElement("/guilds/pyromancer/flame/flame-bolt.c");

    addChild("/guilds/pyromancer/flame/flame-shards.c",
        "/guilds/pyromancer/flame/ignite.c");
    addChild("/guilds/pyromancer/flame/blazing-blades.c",
        "/guilds/pyromancer/flame/root.c");
    addChild("/guilds/pyromancer/flame/flame-bolt.c",
        "/guilds/pyromancer/flame/ignite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/pyromancer/flame/flamemasters-reserve.c");

    addChild("/guilds/pyromancer/flame/flamemasters-reserve.c",
        "/guilds/pyromancer/flame/flame-bolt.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/pyromancer/flame/flamemasters-boon.c");
    addResearchElement("/guilds/pyromancer/flame/flame-whip.c");

    addChild("/guilds/pyromancer/flame/flamemasters-boon.c",
        "/guilds/pyromancer/flame/flame-bolt.c");
    addChild("/guilds/pyromancer/flame/flame-whip.c",
        "/guilds/pyromancer/flame/flame-lash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/pyromancer/flame/pyrostatics.c");

    addChild("/guilds/pyromancer/flame/pyrostatics.c",
        "/guilds/pyromancer/flame/flame-shards.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/pyromancer/flame/blazing-wave.c");

    addChild("/guilds/pyromancer/flame/blazing-wave.c",
        "/guilds/pyromancer/flame/scorching-mist.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/pyromancer/flame/flame-discharge.c");

    addChild("/guilds/pyromancer/flame/flame-discharge.c",
        "/guilds/pyromancer/flame/flame-bolt.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/flame/combustion.c");
    addResearchElement("/guilds/pyromancer/flame/flamemasters-call.c");

    addChild("/guilds/pyromancer/flame/combustion.c",
        "/guilds/pyromancer/flame/pyrostatics.c");
    addChild("/guilds/pyromancer/flame/flamemasters-call.c",
        "/guilds/pyromancer/flame/flamemasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/pyromancer/flame/flamemasters-finesse.c");

    addChild("/guilds/pyromancer/flame/flamemasters-finesse.c",
        "/guilds/pyromancer/flame/flamemasters-boon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/pyromancer/flame/enhanced-blaze.c");

    addChild("/guilds/pyromancer/flame/enhanced-blaze.c",
        "/guilds/pyromancer/flame/combustion.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/pyromancer/flame/firestorm.c");

    addChild("/guilds/pyromancer/flame/firestorm.c",
        "/guilds/pyromancer/flame/flame-discharge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/flame/flamemasters-might.c");

    addChild("/guilds/pyromancer/flame/flamemasters-might.c",
        "/guilds/pyromancer/flame/flamemasters-call.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/pyromancer/flame/pyrogenic-induction.c");
    addResearchElement("/guilds/pyromancer/flame/flamemasters-endurance.c");

    addChild("/guilds/pyromancer/flame/pyrogenic-induction.c",
        "/guilds/pyromancer/flame/enhanced-blaze.c");
    addChild("/guilds/pyromancer/flame/flamemasters-endurance.c",
        "/guilds/pyromancer/flame/flamemasters-finesse.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/pyromancer/flame/raging-inferno.c");

    addChild("/guilds/pyromancer/flame/raging-inferno.c",
        "/guilds/pyromancer/flame/firestorm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/pyromancer/flame/enhanced-burning.c");

    addChild("/guilds/pyromancer/flame/enhanced-burning.c",
        "/guilds/pyromancer/flame/pyrogenic-induction.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/flame/flamemasters-fury.c");

    addChild("/guilds/pyromancer/flame/flamemasters-fury.c",
        "/guilds/pyromancer/flame/flamemasters-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/pyromancer/flame/flamemasters-strength.c");

    addChild("/guilds/pyromancer/flame/flamemasters-strength.c",
        "/guilds/pyromancer/flame/flamemasters-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/pyromancer/flame/pyrogenic-condenser.c");

    addChild("/guilds/pyromancer/flame/pyrogenic-condenser.c",
        "/guilds/pyromancer/flame/enhanced-burning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/flame/volcanic-burst.c");

    addChild("/guilds/pyromancer/flame/volcanic-burst.c",
        "/guilds/pyromancer/flame/pyrogenic-condenser.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/pyromancer/flame/hellfire-eruption.c");

    addChild("/guilds/pyromancer/flame/hellfire-eruption.c",
        "/guilds/pyromancer/flame/volcanic-burst.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/pyromancer/flame/inferno-condenser.c");

    addChild("/guilds/pyromancer/flame/inferno-condenser.c",
        "/guilds/pyromancer/flame/hellfire-eruption.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/pyromancer/flame/blazing-swarm.c");

    addChild("/guilds/pyromancer/flame/blazing-swarm.c",
        "/guilds/pyromancer/flame/raging-inferno.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Flame");
    Description("This research tree provides knowledge of flame-based "
        "spells and abilities for the pyromancer.");
    Source("pyromancer");
    addResearchElement("/guilds/pyromancer/flame/root.c");
    TreeRoot("/guilds/pyromancer/flame/root.c");

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
