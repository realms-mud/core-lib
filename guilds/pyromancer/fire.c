//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/pyromancer/fire/spark.c");

    addChild("/guilds/pyromancer/fire/spark.c",
        "/guilds/pyromancer/fire/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/pyromancer/fire/fire-blast.c");
    addResearchElement("/guilds/pyromancer/fire/ember.c");

    addChild("/guilds/pyromancer/fire/fire-blast.c",
        "/guilds/pyromancer/fire/spark.c");
    addChild("/guilds/pyromancer/fire/ember.c",
        "/guilds/pyromancer/fire/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/searing-blast.c");
    addResearchElement("/guilds/pyromancer/fire/smoke-screen.c");

    addChild("/guilds/pyromancer/fire/searing-blast.c",
        "/guilds/pyromancer/fire/root.c");
    addChild("/guilds/pyromancer/fire/smoke-screen.c",
        "/guilds/pyromancer/fire/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/pyromancer/fire/blazing-focus.c");
    addResearchElement("/guilds/pyromancer/fire/burning-grasp.c");
    addResearchElement("/guilds/pyromancer/fire/firestorm.c");

    addChild("/guilds/pyromancer/fire/blazing-focus.c",
        "/guilds/pyromancer/fire/searing-blast.c");
    addChild("/guilds/pyromancer/fire/burning-grasp.c",
        "/guilds/pyromancer/fire/spark.c");
    addChild("/guilds/pyromancer/fire/firestorm.c",
        "/guilds/pyromancer/fire/spark.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/heat-wave.c");
    addResearchElement("/guilds/pyromancer/fire/fire-blades.c");
    addResearchElement("/guilds/pyromancer/fire/flameweaving.c");
    addResearchElement("/guilds/pyromancer/fire/talons-of-fire.c");

    addChild("/guilds/pyromancer/fire/heat-wave.c",
        "/guilds/pyromancer/fire/spark.c");
    addChild("/guilds/pyromancer/fire/fire-blades.c",
        "/guilds/pyromancer/fire/root.c");
    addChild("/guilds/pyromancer/fire/flameweaving.c",
        "/guilds/pyromancer/fire/searing-blast.c");
    addChild("/guilds/pyromancer/fire/talons-of-fire.c",
        "/guilds/pyromancer/fire/spark.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/pyromancer/fire/infernal-force.c");
    addResearchElement("/guilds/pyromancer/fire/ash-cloud.c");
    addResearchElement("/guilds/pyromancer/fire/battering-flames.c");

    addChild("/guilds/pyromancer/fire/infernal-force.c",
        "/guilds/pyromancer/fire/firestorm.c");
    addChild("/guilds/pyromancer/fire/ash-cloud.c",
        "/guilds/pyromancer/fire/smoke-screen.c");
    addChild("/guilds/pyromancer/fire/battering-flames.c",
        "/guilds/pyromancer/fire/spark.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/fire-shield.c");
    addResearchElement("/guilds/pyromancer/fire/inferno.c");
    addResearchElement("/guilds/pyromancer/fire/flame-pillar.c");

    addChild("/guilds/pyromancer/fire/fire-shield.c",
        "/guilds/pyromancer/fire/firestorm.c");
    addChild("/guilds/pyromancer/fire/inferno.c",
        "/guilds/pyromancer/fire/fire-blast.c");
    addChild("/guilds/pyromancer/fire/flame-pillar.c",
        "/guilds/pyromancer/fire/firestorm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/conflagration.c");
    addResearchElement("/guilds/pyromancer/fire/burning-touch.c");

    addChild("/guilds/pyromancer/fire/conflagration.c",
        "/guilds/pyromancer/fire/blazing-focus.c");
    addChild("/guilds/pyromancer/fire/burning-touch.c",
        "/guilds/pyromancer/fire/burning-grasp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/blazing-convergence.c");
    addResearchElement("/guilds/pyromancer/fire/corrosive-flame.c");

    addChild("/guilds/pyromancer/fire/blazing-convergence.c",
        "/guilds/pyromancer/fire/flameweaving.c");
    addChild("/guilds/pyromancer/fire/corrosive-flame.c",
        "/guilds/pyromancer/fire/ash-cloud.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/fire-mastery.c");
    addResearchElement("/guilds/pyromancer/fire/volcanic-call.c");

    addChild("/guilds/pyromancer/fire/fire-mastery.c",
        "/guilds/pyromancer/fire/firestorm.c");
    addChild("/guilds/pyromancer/fire/volcanic-call.c",
        "/guilds/pyromancer/fire/infernal-force.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/fire/fire-barrier.c");
    addResearchElement("/guilds/pyromancer/fire/backdraft.c");

    addChild("/guilds/pyromancer/fire/fire-barrier.c",
        "/guilds/pyromancer/fire/fire-shield.c");
    addChild("/guilds/pyromancer/fire/backdraft.c",
        "/guilds/pyromancer/fire/heat-wave.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/pyromancer/fire/fire-walk.c");

    addChild("/guilds/pyromancer/fire/fire-walk.c",
        "/guilds/pyromancer/fire/fire-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/fire-channeling.c");
    addResearchElement("/guilds/pyromancer/fire/eruption.c");

    addChild("/guilds/pyromancer/fire/fire-channeling.c",
        "/guilds/pyromancer/fire/fire-mastery.c");
    addChild("/guilds/pyromancer/fire/eruption.c",
        "/guilds/pyromancer/fire/flame-pillar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/pyromancer/fire/molten-core.c");
    addResearchElement("/guilds/pyromancer/fire/great-inferno.c");

    addChild("/guilds/pyromancer/fire/molten-core.c",
        "/guilds/pyromancer/fire/blazing-convergence.c");
    addChild("/guilds/pyromancer/fire/great-inferno.c",
        "/guilds/pyromancer/fire/volcanic-call.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/daggers-of-fire.c");
    addResearchElement("/guilds/pyromancer/fire/immolating-depths.c");

    addChild("/guilds/pyromancer/fire/daggers-of-fire.c",
        "/guilds/pyromancer/fire/backdraft.c");
    addChild("/guilds/pyromancer/fire/immolating-depths.c",
        "/guilds/pyromancer/fire/burning-touch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/pyromancer/fire/pyretic-flow.c");
    addResearchElement("/guilds/pyromancer/fire/disrupt-inferno.c");

    addChild("/guilds/pyromancer/fire/pyretic-flow.c",
        "/guilds/pyromancer/fire/fire-channeling.c");
    addChild("/guilds/pyromancer/fire/disrupt-inferno.c",
        "/guilds/pyromancer/fire/great-inferno.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/pyromancer/fire/scorching-tide.c");
    addResearchElement("/guilds/pyromancer/fire/encircling-flames.c");

    addChild("/guilds/pyromancer/fire/scorching-tide.c",
        "/guilds/pyromancer/fire/molten-core.c");
    addChild("/guilds/pyromancer/fire/encircling-flames.c",
        "/guilds/pyromancer/fire/fire-walk.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/heart-of-the-flame.c");
    addResearchElement("/guilds/pyromancer/fire/immolating-embrace.c");

    addChild("/guilds/pyromancer/fire/heart-of-the-flame.c",
        "/guilds/pyromancer/fire/pyretic-flow.c");
    addChild("/guilds/pyromancer/fire/immolating-embrace.c",
        "/guilds/pyromancer/fire/immolating-depths.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/elemental-ignition.c");
    addResearchElement("/guilds/pyromancer/fire/whirling-flames.c");

    addChild("/guilds/pyromancer/fire/elemental-ignition.c",
        "/guilds/pyromancer/fire/heart-of-the-flame.c");
    addChild("/guilds/pyromancer/fire/whirling-flames.c",
        "/guilds/pyromancer/fire/disrupt-inferno.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/pyromancer/fire/ember-veil.c");

    addChild("/guilds/pyromancer/fire/ember-veil.c",
        "/guilds/pyromancer/fire/scorching-tide.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/fire/inferno-mastery.c");
    addResearchElement("/guilds/pyromancer/fire/gather-the-flames.c");
    addResearchElement("/guilds/pyromancer/fire/hellfire-orb.c");

    addChild("/guilds/pyromancer/fire/inferno-mastery.c",
        "/guilds/pyromancer/fire/elemental-ignition.c");
    addChild("/guilds/pyromancer/fire/gather-the-flames.c",
        "/guilds/pyromancer/fire/encircling-flames.c");
    addChild("/guilds/pyromancer/fire/hellfire-orb.c",
        "/guilds/pyromancer/fire/immolating-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/pyromancer/fire/hellfire-orb-intensity.c");

    addChild("/guilds/pyromancer/fire/hellfire-orb-intensity.c",
        "/guilds/pyromancer/fire/hellfire-orb.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/pyromancer/fire/pyromantic-insight.c");
    addResearchElement("/guilds/pyromancer/fire/withering-flames.c");

    addChild("/guilds/pyromancer/fire/pyromantic-insight.c",
        "/guilds/pyromancer/fire/inferno-mastery.c");
    addChild("/guilds/pyromancer/fire/withering-flames.c",
        "/guilds/pyromancer/fire/whirling-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/fire/withering-flames-intensity.c");

    addChild("/guilds/pyromancer/fire/withering-flames-intensity.c",
        "/guilds/pyromancer/fire/withering-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/pyromancer/fire/fire-dominion.c");

    addChild("/guilds/pyromancer/fire/fire-dominion.c",
        "/guilds/pyromancer/fire/pyromantic-insight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/pyromancer/fire/apocalypse.c");

    addChild("/guilds/pyromancer/fire/apocalypse.c",
        "/guilds/pyromancer/fire/withering-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/fire/apocalypse-intensity.c");

    addChild("/guilds/pyromancer/fire/apocalypse-intensity.c",
        "/guilds/pyromancer/fire/apocalypse.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Fire");
    Description("This research tree provides knowledge of fire-based spells "
        "and abilities for the pyromancer.");
    Source("pyromancer");
    addResearchElement("/guilds/pyromancer/fire/root.c");
    TreeRoot("/guilds/pyromancer/fire/root.c");

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
    FiftyFifthLevel();
    FiftySeventhLevel();
    SixtyFirstLevel();
    SixtyThirdLevel();
    SixtySeventhLevel();
    SeventyFirstLevel();
}
