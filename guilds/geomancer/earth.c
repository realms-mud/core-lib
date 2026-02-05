//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/geomancer/earth/tremor.c");

    addChild("/guilds/geomancer/earth/tremor.c",
        "/guilds/geomancer/earth/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/geomancer/earth/earthen-might.c");
    addResearchElement("/guilds/geomancer/earth/mend.c");

    addChild("/guilds/geomancer/earth/earthen-might.c",
        "/guilds/geomancer/earth/tremor.c");
    addChild("/guilds/geomancer/earth/mend.c",
        "/guilds/geomancer/earth/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/geomancer/earth/mudslide.c");
    addResearchElement("/guilds/geomancer/earth/dust-shroud.c");

    addChild("/guilds/geomancer/earth/mudslide.c",
        "/guilds/geomancer/earth/root.c");
    addChild("/guilds/geomancer/earth/dust-shroud.c",
        "/guilds/geomancer/earth/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/geomancer/earth/earthen-focus.c");
    addResearchElement("/guilds/geomancer/earth/grasping-earth.c");
    addResearchElement("/guilds/geomancer/earth/quake.c");

    addChild("/guilds/geomancer/earth/earthen-focus.c",
        "/guilds/geomancer/earth/mudslide.c");
    addChild("/guilds/geomancer/earth/grasping-earth.c",
        "/guilds/geomancer/earth/tremor.c");
    addChild("/guilds/geomancer/earth/quake.c",
        "/guilds/geomancer/earth/tremor.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/geomancer/earth/fissure.c");
    addResearchElement("/guilds/geomancer/earth/earth-blades.c");
    addResearchElement("/guilds/geomancer/earth/sandweaving.c");
    addResearchElement("/guilds/geomancer/earth/talons-of-earth.c");

    addChild("/guilds/geomancer/earth/fissure.c",
        "/guilds/geomancer/earth/tremor.c");
    addChild("/guilds/geomancer/earth/earth-blades.c",
        "/guilds/geomancer/earth/root.c");
    addChild("/guilds/geomancer/earth/sandweaving.c",
        "/guilds/geomancer/earth/mudslide.c");
    addChild("/guilds/geomancer/earth/talons-of-earth.c",
        "/guilds/geomancer/earth/tremor.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/geomancer/earth/tectonic-force.c");
    addResearchElement("/guilds/geomancer/earth/dust-storm.c");
    addResearchElement("/guilds/geomancer/earth/battering-stones.c");

    addChild("/guilds/geomancer/earth/tectonic-force.c",
        "/guilds/geomancer/earth/quake.c");
    addChild("/guilds/geomancer/earth/dust-storm.c",
        "/guilds/geomancer/earth/dust-shroud.c");
    addChild("/guilds/geomancer/earth/battering-stones.c",
        "/guilds/geomancer/earth/tremor.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/geomancer/earth/earth-shield.c");
    addResearchElement("/guilds/geomancer/earth/earthmaw.c");
    addResearchElement("/guilds/geomancer/earth/stalagmite.c");

    addChild("/guilds/geomancer/earth/earth-shield.c",
        "/guilds/geomancer/earth/quake.c");
    addChild("/guilds/geomancer/earth/earthmaw.c",
        "/guilds/geomancer/earth/earthen-might.c");
    addChild("/guilds/geomancer/earth/stalagmite.c",
        "/guilds/geomancer/earth/quake.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/geomancer/earth/landslide.c");
    addResearchElement("/guilds/geomancer/earth/quicksand.c");

    addChild("/guilds/geomancer/earth/landslide.c",
        "/guilds/geomancer/earth/earthen-focus.c");
    addChild("/guilds/geomancer/earth/quicksand.c",
        "/guilds/geomancer/earth/grasping-earth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/geomancer/earth/earthen-convergence.c");
    addResearchElement("/guilds/geomancer/earth/corrosive-grit.c");

    addChild("/guilds/geomancer/earth/earthen-convergence.c",
        "/guilds/geomancer/earth/sandweaving.c");
    addChild("/guilds/geomancer/earth/corrosive-grit.c",
        "/guilds/geomancer/earth/dust-storm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/geomancer/earth/earth-mastery.c");
    addResearchElement("/guilds/geomancer/earth/seismic-call.c");

    addChild("/guilds/geomancer/earth/earth-mastery.c",
        "/guilds/geomancer/earth/quake.c");
    addChild("/guilds/geomancer/earth/seismic-call.c",
        "/guilds/geomancer/earth/tectonic-force.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/geomancer/earth/earth-barrier.c");
    addResearchElement("/guilds/geomancer/earth/upheaval.c");

    addChild("/guilds/geomancer/earth/earth-barrier.c",
        "/guilds/geomancer/earth/earth-shield.c");
    addChild("/guilds/geomancer/earth/upheaval.c",
        "/guilds/geomancer/earth/fissure.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/geomancer/earth/earth-walk.c");

    addChild("/guilds/geomancer/earth/earth-walk.c",
        "/guilds/geomancer/earth/earth-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/geomancer/earth/earth-channeling.c");
    addResearchElement("/guilds/geomancer/earth/eruption.c");

    addChild("/guilds/geomancer/earth/earth-channeling.c",
        "/guilds/geomancer/earth/earth-mastery.c");
    addChild("/guilds/geomancer/earth/eruption.c",
        "/guilds/geomancer/earth/stalagmite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/geomancer/earth/molten-depths.c");
    addResearchElement("/guilds/geomancer/earth/great-quake.c");

    addChild("/guilds/geomancer/earth/molten-depths.c",
        "/guilds/geomancer/earth/earthen-convergence.c");
    addChild("/guilds/geomancer/earth/great-quake.c",
        "/guilds/geomancer/earth/seismic-call.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/geomancer/earth/daggers-of-earth.c");
    addResearchElement("/guilds/geomancer/earth/entombing-depths.c");

    addChild("/guilds/geomancer/earth/daggers-of-earth.c",
        "/guilds/geomancer/earth/upheaval.c");
    addChild("/guilds/geomancer/earth/entombing-depths.c",
        "/guilds/geomancer/earth/quicksand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/geomancer/earth/telluric-flow.c");
    addResearchElement("/guilds/geomancer/earth/disrupt-seismic.c");

    addChild("/guilds/geomancer/earth/telluric-flow.c",
        "/guilds/geomancer/earth/earth-channeling.c");
    addChild("/guilds/geomancer/earth/disrupt-seismic.c",
        "/guilds/geomancer/earth/great-quake.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/geomancer/earth/crushing-weight.c");
    addResearchElement("/guilds/geomancer/earth/encircling-stones.c");

    addChild("/guilds/geomancer/earth/crushing-weight.c",
        "/guilds/geomancer/earth/molten-depths.c");
    addChild("/guilds/geomancer/earth/encircling-stones.c",
        "/guilds/geomancer/earth/earth-walk.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/geomancer/earth/heart-of-the-mountain.c");
    addResearchElement("/guilds/geomancer/earth/entombing-embrace.c");

    addChild("/guilds/geomancer/earth/heart-of-the-mountain.c",
        "/guilds/geomancer/earth/telluric-flow.c");
    addChild("/guilds/geomancer/earth/entombing-embrace.c",
        "/guilds/geomancer/earth/entombing-depths.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/geomancer/earth/elemental-resonance.c");
    addResearchElement("/guilds/geomancer/earth/whirling-stones.c");

    addChild("/guilds/geomancer/earth/elemental-resonance.c",
        "/guilds/geomancer/earth/heart-of-the-mountain.c");
    addChild("/guilds/geomancer/earth/whirling-stones.c",
        "/guilds/geomancer/earth/disrupt-seismic.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/geomancer/earth/granite-veil.c");

    addChild("/guilds/geomancer/earth/granite-veil.c",
        "/guilds/geomancer/earth/crushing-weight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/geomancer/earth/mountain-mastery.c");
    addResearchElement("/guilds/geomancer/earth/gather-the-stones.c");
    addResearchElement("/guilds/geomancer/earth/abyssal-stone.c");

    addChild("/guilds/geomancer/earth/mountain-mastery.c",
        "/guilds/geomancer/earth/elemental-resonance.c");
    addChild("/guilds/geomancer/earth/gather-the-stones.c",
        "/guilds/geomancer/earth/encircling-stones.c");
    addChild("/guilds/geomancer/earth/abyssal-stone.c",
        "/guilds/geomancer/earth/entombing-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/geomancer/earth/geomantic-insight.c");
    addResearchElement("/guilds/geomancer/earth/withering-earth.c");

    addChild("/guilds/geomancer/earth/geomantic-insight.c",
        "/guilds/geomancer/earth/mountain-mastery.c");
    addChild("/guilds/geomancer/earth/withering-earth.c",
        "/guilds/geomancer/earth/whirling-stones.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/geomancer/earth/earth-dominion.c");

    addChild("/guilds/geomancer/earth/earth-dominion.c",
        "/guilds/geomancer/earth/geomantic-insight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/geomancer/earth/cataclysm.c");

    addChild("/guilds/geomancer/earth/cataclysm.c",
        "/guilds/geomancer/earth/withering-earth.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Earth");
    Description("This research tree provides knowledge of earth-based spells "
        "and abilities for the geomancer.");
    Source("geomancer");
    addResearchElement("/guilds/geomancer/earth/root.c");
    TreeRoot("/guilds/geomancer/earth/root.c");

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
