//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aeromancer/effects/damage-hp.c");
    addResearchElement("/guilds/aeromancer/effects/add-hp.c");

    addChild("/guilds/aeromancer/effects/damage-hp.c",
        "/guilds/aeromancer/effects/root.c");
    addChild("/guilds/aeromancer/effects/add-hp.c",
        "/guilds/aeromancer/effects/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/aeromancer/effects/damage-sp.c");
    addResearchElement("/guilds/aeromancer/effects/add-sp.c");

    addChild("/guilds/aeromancer/effects/damage-sp.c",
        "/guilds/aeromancer/effects/damage-hp.c");
    addChild("/guilds/aeromancer/effects/add-sp.c",
        "/guilds/aeromancer/effects/add-hp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aeromancer/effects/damage-stamina.c");
    addResearchElement("/guilds/aeromancer/effects/add-stamina.c");

    addChild("/guilds/aeromancer/effects/damage-stamina.c",
        "/guilds/aeromancer/effects/damage-sp.c");
    addChild("/guilds/aeromancer/effects/add-stamina.c",
        "/guilds/aeromancer/effects/add-sp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aeromancer/effects/siphon-hp.c");
    addResearchElement("/guilds/aeromancer/effects/enhance-attack.c");
    addResearchElement("/guilds/aeromancer/effects/reduce-attack.c");

    addChild("/guilds/aeromancer/effects/siphon-hp.c",
        "/guilds/aeromancer/effects/damage-hp.c");
    addChild("/guilds/aeromancer/effects/enhance-attack.c",
        "/guilds/aeromancer/effects/add-hp.c");
    addChild("/guilds/aeromancer/effects/reduce-attack.c",
        "/guilds/aeromancer/effects/damage-hp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aeromancer/effects/siphon-sp.c");
    addResearchElement("/guilds/aeromancer/effects/enhance-damage.c");
    addResearchElement("/guilds/aeromancer/effects/reduce-damage.c");

    addChild("/guilds/aeromancer/effects/siphon-sp.c",
        "/guilds/aeromancer/effects/siphon-hp.c");
    addChild("/guilds/aeromancer/effects/enhance-damage.c",
        "/guilds/aeromancer/effects/enhance-attack.c");
    addChild("/guilds/aeromancer/effects/reduce-damage.c",
        "/guilds/aeromancer/effects/reduce-attack.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aeromancer/effects/siphon-stamina.c");
    addResearchElement("/guilds/aeromancer/effects/enhance-defense.c");
    addResearchElement("/guilds/aeromancer/effects/reduce-defense.c");

    addChild("/guilds/aeromancer/effects/siphon-stamina.c",
        "/guilds/aeromancer/effects/siphon-sp.c");
    addChild("/guilds/aeromancer/effects/enhance-defense.c",
        "/guilds/aeromancer/effects/enhance-damage.c");
    addChild("/guilds/aeromancer/effects/reduce-defense.c",
        "/guilds/aeromancer/effects/reduce-damage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aeromancer/effects/enhance-soak.c");
    addResearchElement("/guilds/aeromancer/effects/reduce-soak.c");

    addChild("/guilds/aeromancer/effects/enhance-soak.c",
        "/guilds/aeromancer/effects/enhance-defense.c");
    addChild("/guilds/aeromancer/effects/reduce-soak.c",
        "/guilds/aeromancer/effects/reduce-defense.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aeromancer/effects/reduce-sp-cost.c");
    addResearchElement("/guilds/aeromancer/effects/reduce-stamina-cost.c");

    addChild("/guilds/aeromancer/effects/reduce-sp-cost.c",
        "/guilds/aeromancer/effects/enhance-soak.c");
    addChild("/guilds/aeromancer/effects/reduce-stamina-cost.c",
        "/guilds/aeromancer/effects/enhance-soak.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Effects");
    Description("This research tree provides knowledge of the various effects "
        "that constructed aeromancer spells can produce.");
    Source("aeromancer");
    addResearchElement("/guilds/aeromancer/effects/root.c");
    TreeRoot("/guilds/aeromancer/effects/root.c");

    FirstLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
}
