//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aeromancer/air/gust.c");

    addChild("/guilds/aeromancer/air/gust.c",
        "/guilds/aeromancer/air/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/aeromancer/air/blast-of-wind.c");
    addResearchElement("/guilds/aeromancer/air/breeze.c");

    addChild("/guilds/aeromancer/air/blast-of-wind.c",
        "/guilds/aeromancer/air/gust.c");
    addChild("/guilds/aeromancer/air/breeze.c",
        "/guilds/aeromancer/air/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aeromancer/air/arctic-blast.c");
    addResearchElement("/guilds/aeromancer/air/blinding-mist.c");

    addChild("/guilds/aeromancer/air/arctic-blast.c",
        "/guilds/aeromancer/air/root.c");
    addChild("/guilds/aeromancer/air/blinding-mist.c",
        "/guilds/aeromancer/air/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aeromancer/air/arctic-focus.c");
    addResearchElement("/guilds/aeromancer/air/stolen-breath.c");
    addResearchElement("/guilds/aeromancer/air/cyclone.c");

    addChild("/guilds/aeromancer/air/arctic-focus.c",
        "/guilds/aeromancer/air/arctic-blast.c");
    addChild("/guilds/aeromancer/air/stolen-breath.c",
        "/guilds/aeromancer/air/gust.c");
    addChild("/guilds/aeromancer/air/cyclone.c",
        "/guilds/aeromancer/air/gust.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aeromancer/air/zephyr.c");
    addResearchElement("/guilds/aeromancer/air/wind-blades.c");
    addResearchElement("/guilds/aeromancer/air/frostweaving.c");
    addResearchElement("/guilds/aeromancer/air/talons-of-wind.c");

    addChild("/guilds/aeromancer/air/zephyr.c",
        "/guilds/aeromancer/air/gust.c");
    addChild("/guilds/aeromancer/air/wind-blades.c",
        "/guilds/aeromancer/air/root.c");
    addChild("/guilds/aeromancer/air/frostweaving.c",
        "/guilds/aeromancer/air/arctic-blast.c");
    addChild("/guilds/aeromancer/air/talons-of-wind.c",
        "/guilds/aeromancer/air/gust.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aeromancer/air/gale-force.c");
    addResearchElement("/guilds/aeromancer/air/fog.c");
    addResearchElement("/guilds/aeromancer/air/buffeting-wind.c");

    addChild("/guilds/aeromancer/air/gale-force.c",
        "/guilds/aeromancer/air/cyclone.c");
    addChild("/guilds/aeromancer/air/fog.c",
        "/guilds/aeromancer/air/blinding-mist.c");
    addChild("/guilds/aeromancer/air/buffeting-wind.c",
        "/guilds/aeromancer/air/gust.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aeromancer/air/air-shield.c");
    addResearchElement("/guilds/aeromancer/air/vortex.c");
    addResearchElement("/guilds/aeromancer/air/tornado.c");

    addChild("/guilds/aeromancer/air/air-shield.c",
        "/guilds/aeromancer/air/cyclone.c");
    addChild("/guilds/aeromancer/air/vortex.c",
        "/guilds/aeromancer/air/blast-of-wind.c");
    addChild("/guilds/aeromancer/air/tornado.c",
        "/guilds/aeromancer/air/cyclone.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aeromancer/air/hurricane.c");
    addResearchElement("/guilds/aeromancer/air/noxious-breath.c");

    addChild("/guilds/aeromancer/air/hurricane.c",
        "/guilds/aeromancer/air/arctic-focus.c");
    addChild("/guilds/aeromancer/air/noxious-breath.c",
        "/guilds/aeromancer/air/stolen-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aeromancer/air/icy-convergence.c");
    addResearchElement("/guilds/aeromancer/air/caustic-mist.c");

    addChild("/guilds/aeromancer/air/icy-convergence.c",
        "/guilds/aeromancer/air/frostweaving.c");
    addChild("/guilds/aeromancer/air/caustic-mist.c",
        "/guilds/aeromancer/air/fog.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/aeromancer/air/wind-mastery.c");
    addResearchElement("/guilds/aeromancer/air/storm-call.c");

    addChild("/guilds/aeromancer/air/wind-mastery.c",
        "/guilds/aeromancer/air/cyclone.c");
    addChild("/guilds/aeromancer/air/storm-call.c",
        "/guilds/aeromancer/air/gale-force.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/air/air-barrier.c");
    addResearchElement("/guilds/aeromancer/air/jetstream.c");

    addChild("/guilds/aeromancer/air/air-barrier.c",
        "/guilds/aeromancer/air/air-shield.c");
    addChild("/guilds/aeromancer/air/jetstream.c",
        "/guilds/aeromancer/air/zephyr.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/aeromancer/air/wind-walk.c");

    addChild("/guilds/aeromancer/air/wind-walk.c",
        "/guilds/aeromancer/air/air-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/aeromancer/air/air-channeling.c");
    addResearchElement("/guilds/aeromancer/air/updraft.c");

    addChild("/guilds/aeromancer/air/air-channeling.c",
        "/guilds/aeromancer/air/wind-mastery.c");
    addChild("/guilds/aeromancer/air/updraft.c",
        "/guilds/aeromancer/air/tornado.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/aeromancer/air/glacial-winds.c");
    addResearchElement("/guilds/aeromancer/air/maelstrom.c");

    addChild("/guilds/aeromancer/air/glacial-winds.c",
        "/guilds/aeromancer/air/icy-convergence.c");
    addChild("/guilds/aeromancer/air/maelstrom.c",
        "/guilds/aeromancer/air/storm-call.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/aeromancer/air/daggers-of-the-wind.c");
    addResearchElement("/guilds/aeromancer/air/choking-wind.c");

    addChild("/guilds/aeromancer/air/daggers-of-the-wind.c",
        "/guilds/aeromancer/air/jetstream.c");
    addChild("/guilds/aeromancer/air/choking-wind.c",
        "/guilds/aeromancer/air/noxious-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/aeromancer/air/zephyric-flow.c");
    addResearchElement("/guilds/aeromancer/air/disrupt-storm.c");

    addChild("/guilds/aeromancer/air/zephyric-flow.c",
        "/guilds/aeromancer/air/air-channeling.c");
    addChild("/guilds/aeromancer/air/disrupt-storm.c",
        "/guilds/aeromancer/air/maelstrom.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/aeromancer/air/freezing-tide.c");
    addResearchElement("/guilds/aeromancer/air/encircling-winds.c");

    addChild("/guilds/aeromancer/air/freezing-tide.c",
        "/guilds/aeromancer/air/glacial-winds.c");
    addChild("/guilds/aeromancer/air/encircling-winds.c",
        "/guilds/aeromancer/air/wind-walk.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/aeromancer/air/eye-of-the-tempest.c");
    addResearchElement("/guilds/aeromancer/air/foul-gasp.c");

    addChild("/guilds/aeromancer/air/eye-of-the-tempest.c",
        "/guilds/aeromancer/air/zephyric-flow.c");
    addChild("/guilds/aeromancer/air/foul-gasp.c",
        "/guilds/aeromancer/air/choking-wind.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/aeromancer/air/elemental-attunement.c");
    addResearchElement("/guilds/aeromancer/air/whirling-wind.c");

    addChild("/guilds/aeromancer/air/elemental-attunement.c",
        "/guilds/aeromancer/air/eye-of-the-tempest.c");
    addChild("/guilds/aeromancer/air/whirling-wind.c",
        "/guilds/aeromancer/air/disrupt-storm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/aeromancer/air/frost-veil.c");

    addChild("/guilds/aeromancer/air/frost-veil.c",
        "/guilds/aeromancer/air/freezing-tide.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/air/tempest-mastery.c");
    addResearchElement("/guilds/aeromancer/air/gather-the-storm.c");
    addResearchElement("/guilds/aeromancer/air/void-orb.c");

    addChild("/guilds/aeromancer/air/tempest-mastery.c",
        "/guilds/aeromancer/air/elemental-attunement.c");
    addChild("/guilds/aeromancer/air/gather-the-storm.c",
        "/guilds/aeromancer/air/encircling-winds.c");
    addChild("/guilds/aeromancer/air/void-orb.c",
        "/guilds/aeromancer/air/foul-gasp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/aeromancer/air/aeromantic-insight.c");
    addResearchElement("/guilds/aeromancer/air/withering-air.c");

    addChild("/guilds/aeromancer/air/aeromantic-insight.c",
        "/guilds/aeromancer/air/tempest-mastery.c");
    addChild("/guilds/aeromancer/air/withering-air.c",
        "/guilds/aeromancer/air/whirling-wind.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/aeromancer/air/air-dominion.c");

    addChild("/guilds/aeromancer/air/air-dominion.c",
        "/guilds/aeromancer/air/aeromantic-insight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/aeromancer/air/tempest.c");

    addChild("/guilds/aeromancer/air/tempest.c",
        "/guilds/aeromancer/air/withering-air.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Air");
    Description("This research tree provides knowledge of air-based spells "
        "and abilities for the aeromancer.");
    Source("aeromancer");
    addResearchElement("/guilds/aeromancer/air/root.c");
    TreeRoot("/guilds/aeromancer/air/root.c");

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
