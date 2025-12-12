//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aquamancer/water/splash.c");

    addChild("/guilds/aquamancer/water/splash.c",
        "/guilds/aquamancer/water/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/aquamancer/water/water-blast.c");
    addResearchElement("/guilds/aquamancer/water/trickle.c");

    addChild("/guilds/aquamancer/water/water-blast.c",
        "/guilds/aquamancer/water/splash.c");
    addChild("/guilds/aquamancer/water/trickle.c",
        "/guilds/aquamancer/water/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aquamancer/water/scalding-blast.c");
    addResearchElement("/guilds/aquamancer/water/obscuring-spray.c");

    addChild("/guilds/aquamancer/water/scalding-blast.c",
        "/guilds/aquamancer/water/root.c");
    addChild("/guilds/aquamancer/water/obscuring-spray.c",
        "/guilds/aquamancer/water/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aquamancer/water/boiling-focus.c");
    addResearchElement("/guilds/aquamancer/water/drowning-grasp.c");
    addResearchElement("/guilds/aquamancer/water/whirlpool.c");

    addChild("/guilds/aquamancer/water/boiling-focus.c",
        "/guilds/aquamancer/water/scalding-blast.c");
    addChild("/guilds/aquamancer/water/drowning-grasp.c",
        "/guilds/aquamancer/water/splash.c");
    addChild("/guilds/aquamancer/water/whirlpool.c",
        "/guilds/aquamancer/water/splash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aquamancer/water/current.c");
    addResearchElement("/guilds/aquamancer/water/water-blades.c");
    addResearchElement("/guilds/aquamancer/water/steamweaving.c");
    addResearchElement("/guilds/aquamancer/water/talons-of-water.c");

    addChild("/guilds/aquamancer/water/current.c",
        "/guilds/aquamancer/water/splash.c");
    addChild("/guilds/aquamancer/water/water-blades.c",
        "/guilds/aquamancer/water/root.c");
    addChild("/guilds/aquamancer/water/steamweaving.c",
        "/guilds/aquamancer/water/scalding-blast.c");
    addChild("/guilds/aquamancer/water/talons-of-water.c",
        "/guilds/aquamancer/water/splash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aquamancer/water/tidal-force.c");
    addResearchElement("/guilds/aquamancer/water/sea-fog.c");
    addResearchElement("/guilds/aquamancer/water/battering-waves.c");

    addChild("/guilds/aquamancer/water/tidal-force.c",
        "/guilds/aquamancer/water/whirlpool.c");
    addChild("/guilds/aquamancer/water/sea-fog.c",
        "/guilds/aquamancer/water/obscuring-spray.c");
    addChild("/guilds/aquamancer/water/battering-waves.c",
        "/guilds/aquamancer/water/splash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aquamancer/water/water-shield.c");
    addResearchElement("/guilds/aquamancer/water/maelstrom.c");
    addResearchElement("/guilds/aquamancer/water/waterspout.c");

    addChild("/guilds/aquamancer/water/water-shield.c",
        "/guilds/aquamancer/water/whirlpool.c");
    addChild("/guilds/aquamancer/water/maelstrom.c",
        "/guilds/aquamancer/water/water-blast.c");
    addChild("/guilds/aquamancer/water/waterspout.c",
        "/guilds/aquamancer/water/whirlpool.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aquamancer/water/tsunami.c");
    addResearchElement("/guilds/aquamancer/water/toxic-waters.c");

    addChild("/guilds/aquamancer/water/tsunami.c",
        "/guilds/aquamancer/water/boiling-focus.c");
    addChild("/guilds/aquamancer/water/toxic-waters.c",
        "/guilds/aquamancer/water/drowning-grasp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aquamancer/water/boiling-convergence.c");
    addResearchElement("/guilds/aquamancer/water/corrosive-spray.c");

    addChild("/guilds/aquamancer/water/boiling-convergence.c",
        "/guilds/aquamancer/water/steamweaving.c");
    addChild("/guilds/aquamancer/water/corrosive-spray.c",
        "/guilds/aquamancer/water/sea-fog.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/aquamancer/water/water-mastery.c");
    addResearchElement("/guilds/aquamancer/water/tempest-call.c");

    addChild("/guilds/aquamancer/water/water-mastery.c",
        "/guilds/aquamancer/water/whirlpool.c");
    addChild("/guilds/aquamancer/water/tempest-call.c",
        "/guilds/aquamancer/water/tidal-force.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/water/water-barrier.c");
    addResearchElement("/guilds/aquamancer/water/riptide.c");

    addChild("/guilds/aquamancer/water/water-barrier.c",
        "/guilds/aquamancer/water/water-shield.c");
    addChild("/guilds/aquamancer/water/riptide.c",
        "/guilds/aquamancer/water/current.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/aquamancer/water/water-walk.c");

    addChild("/guilds/aquamancer/water/water-walk.c",
        "/guilds/aquamancer/water/water-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/aquamancer/water/water-channeling.c");
    addResearchElement("/guilds/aquamancer/water/geyser.c");

    addChild("/guilds/aquamancer/water/water-channeling.c",
        "/guilds/aquamancer/water/water-mastery.c");
    addChild("/guilds/aquamancer/water/geyser.c",
        "/guilds/aquamancer/water/waterspout.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/aquamancer/water/frozen-depths.c");
    addResearchElement("/guilds/aquamancer/water/great-maelstrom.c");

    addChild("/guilds/aquamancer/water/frozen-depths.c",
        "/guilds/aquamancer/water/boiling-convergence.c");
    addChild("/guilds/aquamancer/water/great-maelstrom.c",
        "/guilds/aquamancer/water/tempest-call.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/aquamancer/water/daggers-of-water.c");
    addResearchElement("/guilds/aquamancer/water/suffocating-depths.c");

    addChild("/guilds/aquamancer/water/daggers-of-water.c",
        "/guilds/aquamancer/water/riptide.c");
    addChild("/guilds/aquamancer/water/suffocating-depths.c",
        "/guilds/aquamancer/water/toxic-waters.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/aquamancer/water/aquatic-flow.c");
    addResearchElement("/guilds/aquamancer/water/disrupt-tempest.c");

    addChild("/guilds/aquamancer/water/aquatic-flow.c",
        "/guilds/aquamancer/water/water-channeling.c");
    addChild("/guilds/aquamancer/water/disrupt-tempest.c",
        "/guilds/aquamancer/water/great-maelstrom.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/aquamancer/water/crushing-tide.c");
    addResearchElement("/guilds/aquamancer/water/encircling-waters.c");

    addChild("/guilds/aquamancer/water/crushing-tide.c",
        "/guilds/aquamancer/water/frozen-depths.c");
    addChild("/guilds/aquamancer/water/encircling-waters.c",
        "/guilds/aquamancer/water/water-walk.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/aquamancer/water/eye-of-the-storm.c");
    addResearchElement("/guilds/aquamancer/water/drowning-embrace.c");

    addChild("/guilds/aquamancer/water/eye-of-the-storm.c",
        "/guilds/aquamancer/water/aquatic-flow.c");
    addChild("/guilds/aquamancer/water/drowning-embrace.c",
        "/guilds/aquamancer/water/suffocating-depths.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/aquamancer/water/elemental-attunement.c");
    addResearchElement("/guilds/aquamancer/water/whirling-waters.c");

    addChild("/guilds/aquamancer/water/elemental-attunement.c",
        "/guilds/aquamancer/water/eye-of-the-storm.c");
    addChild("/guilds/aquamancer/water/whirling-waters.c",
        "/guilds/aquamancer/water/disrupt-tempest.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/aquamancer/water/mist-veil.c");

    addChild("/guilds/aquamancer/water/mist-veil.c",
        "/guilds/aquamancer/water/crushing-tide.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/water/ocean-mastery.c");
    addResearchElement("/guilds/aquamancer/water/gather-the-tides.c");
    addResearchElement("/guilds/aquamancer/water/abyssal-orb.c");

    addChild("/guilds/aquamancer/water/ocean-mastery.c",
        "/guilds/aquamancer/water/elemental-attunement.c");
    addChild("/guilds/aquamancer/water/gather-the-tides.c",
        "/guilds/aquamancer/water/encircling-waters.c");
    addChild("/guilds/aquamancer/water/abyssal-orb.c",
        "/guilds/aquamancer/water/drowning-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/aquamancer/water/aquamantic-insight.c");
    addResearchElement("/guilds/aquamancer/water/withering-waters.c");

    addChild("/guilds/aquamancer/water/aquamantic-insight.c",
        "/guilds/aquamancer/water/ocean-mastery.c");
    addChild("/guilds/aquamancer/water/withering-waters.c",
        "/guilds/aquamancer/water/whirling-waters.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/aquamancer/water/water-dominion.c");

    addChild("/guilds/aquamancer/water/water-dominion.c",
        "/guilds/aquamancer/water/aquamantic-insight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/aquamancer/water/cataclysm.c");

    addChild("/guilds/aquamancer/water/cataclysm.c",
        "/guilds/aquamancer/water/withering-waters.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Water");
    Description("This research tree provides knowledge of water-based spells "
        "and abilities for the aquamancer.");
    Source("aquamancer");
    addResearchElement("/guilds/aquamancer/water/root.c");
    TreeRoot("/guilds/aquamancer/water/root.c");

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
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFifthLevel();
    FortySeventhLevel();
    FiftyFirstLevel();
    FiftySeventhLevel();
    SixtyThirdLevel();
    SixtySeventhLevel();
}
