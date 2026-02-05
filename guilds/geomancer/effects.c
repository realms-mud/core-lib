//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/geomancer/effects/damage-hp.c");
    addResearchElement("/guilds/geomancer/effects/add-hp.c");

    addChild("/guilds/geomancer/effects/damage-hp.c",
        "/guilds/geomancer/effects/root.c");
    addChild("/guilds/geomancer/effects/add-hp.c",
        "/guilds/geomancer/effects/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/geomancer/effects/damage-sp.c");
    addResearchElement("/guilds/geomancer/effects/add-sp.c");

    addChild("/guilds/geomancer/effects/damage-sp.c",
        "/guilds/geomancer/effects/damage-hp.c");
    addChild("/guilds/geomancer/effects/add-sp.c",
        "/guilds/geomancer/effects/add-hp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/geomancer/effects/damage-stamina.c");
    addResearchElement("/guilds/geomancer/effects/add-stamina.c");

    addChild("/guilds/geomancer/effects/damage-stamina.c",
        "/guilds/geomancer/effects/damage-sp.c");
    addChild("/guilds/geomancer/effects/add-stamina.c",
        "/guilds/geomancer/effects/add-sp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/geomancer/effects/siphon-hp.c");
    addResearchElement("/guilds/geomancer/effects/enhance-attack.c");
    addResearchElement("/guilds/geomancer/effects/reduce-attack.c");

    addChild("/guilds/geomancer/effects/siphon-hp.c",
        "/guilds/geomancer/effects/damage-hp.c");
    addChild("/guilds/geomancer/effects/enhance-attack.c",
        "/guilds/geomancer/effects/add-hp.c");
    addChild("/guilds/geomancer/effects/reduce-attack.c",
        "/guilds/geomancer/effects/damage-hp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/geomancer/effects/siphon-sp.c");
    addResearchElement("/guilds/geomancer/effects/enhance-damage.c");
    addResearchElement("/guilds/geomancer/effects/reduce-damage.c");

    addChild("/guilds/geomancer/effects/siphon-sp.c",
        "/guilds/geomancer/effects/siphon-hp.c");
    addChild("/guilds/geomancer/effects/enhance-damage.c",
        "/guilds/geomancer/effects/enhance-attack.c");
    addChild("/guilds/geomancer/effects/reduce-damage.c",
        "/guilds/geomancer/effects/reduce-attack.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/geomancer/effects/siphon-stamina.c");
    addResearchElement("/guilds/geomancer/effects/enhance-defense.c");
    addResearchElement("/guilds/geomancer/effects/reduce-defense.c");

    addChild("/guilds/geomancer/effects/siphon-stamina.c",
        "/guilds/geomancer/effects/siphon-sp.c");
    addChild("/guilds/geomancer/effects/enhance-defense.c",
        "/guilds/geomancer/effects/enhance-damage.c");
    addChild("/guilds/geomancer/effects/reduce-defense.c",
        "/guilds/geomancer/effects/reduce-damage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/geomancer/effects/enhance-soak.c");
    addResearchElement("/guilds/geomancer/effects/reduce-soak.c");

    addChild("/guilds/geomancer/effects/enhance-soak.c",
        "/guilds/geomancer/effects/enhance-defense.c");
    addChild("/guilds/geomancer/effects/reduce-soak.c",
        "/guilds/geomancer/effects/reduce-defense.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/geomancer/effects/enhance-dodge.c");
    addResearchElement("/guilds/geomancer/effects/reduce-dodge.c");
    addResearchElement("/guilds/geomancer/effects/apply-slow.c");

    addChild("/guilds/geomancer/effects/enhance-dodge.c",
        "/guilds/geomancer/effects/enhance-soak.c");
    addChild("/guilds/geomancer/effects/reduce-dodge.c",
        "/guilds/geomancer/effects/reduce-soak.c");
    addChild("/guilds/geomancer/effects/apply-slow.c",
        "/guilds/geomancer/effects/reduce-soak.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/geomancer/effects/enhance-parry.c");
    addResearchElement("/guilds/geomancer/effects/reduce-parry.c");
    addResearchElement("/guilds/geomancer/effects/enhance-speed.c");
    addResearchElement("/guilds/geomancer/effects/apply-enfeebled.c");

    addChild("/guilds/geomancer/effects/enhance-parry.c",
        "/guilds/geomancer/effects/enhance-dodge.c");
    addChild("/guilds/geomancer/effects/reduce-parry.c",
        "/guilds/geomancer/effects/reduce-dodge.c");
    addChild("/guilds/geomancer/effects/enhance-speed.c",
        "/guilds/geomancer/effects/enhance-dodge.c");
    addChild("/guilds/geomancer/effects/apply-enfeebled.c",
        "/guilds/geomancer/effects/apply-slow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/geomancer/effects/staggering-damage.c");
    addResearchElement("/guilds/geomancer/effects/debilitating-damage.c");
    addResearchElement("/guilds/geomancer/effects/disorienting-damage.c");
    addResearchElement("/guilds/geomancer/effects/invigorating-siphon.c");

    addChild("/guilds/geomancer/effects/staggering-damage.c",
        "/guilds/geomancer/effects/reduce-parry.c");
    addChild("/guilds/geomancer/effects/debilitating-damage.c",
        "/guilds/geomancer/effects/reduce-parry.c");
    addChild("/guilds/geomancer/effects/disorienting-damage.c",
        "/guilds/geomancer/effects/reduce-parry.c");
    addChild("/guilds/geomancer/effects/invigorating-siphon.c",
        "/guilds/geomancer/effects/enhance-speed.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/geomancer/effects/hampering-damage.c");
    addResearchElement("/guilds/geomancer/effects/exhausting-damage.c");
    addResearchElement("/guilds/geomancer/effects/fortifying-siphon.c");

    addChild("/guilds/geomancer/effects/hampering-damage.c",
        "/guilds/geomancer/effects/apply-slow.c");
    addChild("/guilds/geomancer/effects/exhausting-damage.c",
        "/guilds/geomancer/effects/apply-enfeebled.c");
    addChild("/guilds/geomancer/effects/fortifying-siphon.c",
        "/guilds/geomancer/effects/invigorating-siphon.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Effects");
    Description("This research tree provides knowledge of the various effects "
        "that constructed geomancer spells can produce.");
    Source("geomancer");
    addResearchElement("/guilds/geomancer/effects/root.c");
    TreeRoot("/guilds/geomancer/effects/root.c");

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
}
