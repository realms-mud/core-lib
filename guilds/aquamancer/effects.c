//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aquamancer/effects/damage-hp.c");
    addResearchElement("/guilds/aquamancer/effects/add-hp.c");

    addChild("/guilds/aquamancer/effects/damage-hp.c",
        "/guilds/aquamancer/effects/root.c");
    addChild("/guilds/aquamancer/effects/add-hp.c",
        "/guilds/aquamancer/effects/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/aquamancer/effects/damage-sp.c");
    addResearchElement("/guilds/aquamancer/effects/add-sp.c");

    addChild("/guilds/aquamancer/effects/damage-sp.c",
        "/guilds/aquamancer/effects/damage-hp.c");
    addChild("/guilds/aquamancer/effects/add-sp.c",
        "/guilds/aquamancer/effects/add-hp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aquamancer/effects/damage-stamina.c");
    addResearchElement("/guilds/aquamancer/effects/add-stamina.c");

    addChild("/guilds/aquamancer/effects/damage-stamina.c",
        "/guilds/aquamancer/effects/damage-sp.c");
    addChild("/guilds/aquamancer/effects/add-stamina.c",
        "/guilds/aquamancer/effects/add-sp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aquamancer/effects/siphon-hp.c");
    addResearchElement("/guilds/aquamancer/effects/enhance-attack.c");
    addResearchElement("/guilds/aquamancer/effects/reduce-attack.c");

    addChild("/guilds/aquamancer/effects/siphon-hp.c",
        "/guilds/aquamancer/effects/damage-hp.c");
    addChild("/guilds/aquamancer/effects/enhance-attack.c",
        "/guilds/aquamancer/effects/add-hp.c");
    addChild("/guilds/aquamancer/effects/reduce-attack.c",
        "/guilds/aquamancer/effects/damage-hp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aquamancer/effects/siphon-sp.c");
    addResearchElement("/guilds/aquamancer/effects/enhance-damage.c");
    addResearchElement("/guilds/aquamancer/effects/reduce-damage.c");

    addChild("/guilds/aquamancer/effects/siphon-sp.c",
        "/guilds/aquamancer/effects/siphon-hp.c");
    addChild("/guilds/aquamancer/effects/enhance-damage.c",
        "/guilds/aquamancer/effects/enhance-attack.c");
    addChild("/guilds/aquamancer/effects/reduce-damage.c",
        "/guilds/aquamancer/effects/reduce-attack.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aquamancer/effects/siphon-stamina.c");
    addResearchElement("/guilds/aquamancer/effects/enhance-defense.c");
    addResearchElement("/guilds/aquamancer/effects/reduce-defense.c");

    addChild("/guilds/aquamancer/effects/siphon-stamina.c",
        "/guilds/aquamancer/effects/siphon-sp.c");
    addChild("/guilds/aquamancer/effects/enhance-defense.c",
        "/guilds/aquamancer/effects/enhance-damage.c");
    addChild("/guilds/aquamancer/effects/reduce-defense.c",
        "/guilds/aquamancer/effects/reduce-damage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aquamancer/effects/enhance-soak.c");
    addResearchElement("/guilds/aquamancer/effects/reduce-soak.c");

    addChild("/guilds/aquamancer/effects/enhance-soak.c",
        "/guilds/aquamancer/effects/enhance-defense.c");
    addChild("/guilds/aquamancer/effects/reduce-soak.c",
        "/guilds/aquamancer/effects/reduce-defense.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aquamancer/effects/enhance-dodge.c");
    addResearchElement("/guilds/aquamancer/effects/reduce-dodge.c");
    addResearchElement("/guilds/aquamancer/effects/apply-slow.c");

    addChild("/guilds/aquamancer/effects/enhance-dodge.c",
        "/guilds/aquamancer/effects/enhance-soak.c");
    addChild("/guilds/aquamancer/effects/reduce-dodge.c",
        "/guilds/aquamancer/effects/reduce-soak.c");
    addChild("/guilds/aquamancer/effects/apply-slow.c",
        "/guilds/aquamancer/effects/reduce-soak.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aquamancer/effects/enhance-parry.c");
    addResearchElement("/guilds/aquamancer/effects/reduce-parry.c");
    addResearchElement("/guilds/aquamancer/effects/enhance-speed.c");
    addResearchElement("/guilds/aquamancer/effects/apply-enfeebled.c");

    addChild("/guilds/aquamancer/effects/enhance-parry.c",
        "/guilds/aquamancer/effects/enhance-dodge.c");
    addChild("/guilds/aquamancer/effects/reduce-parry.c",
        "/guilds/aquamancer/effects/reduce-dodge.c");
    addChild("/guilds/aquamancer/effects/enhance-speed.c",
        "/guilds/aquamancer/effects/enhance-dodge.c");
    addChild("/guilds/aquamancer/effects/apply-enfeebled.c",
        "/guilds/aquamancer/effects/apply-slow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/aquamancer/effects/staggering-damage.c");
    addResearchElement("/guilds/aquamancer/effects/debilitating-damage.c");
    addResearchElement("/guilds/aquamancer/effects/disorienting-damage.c");
    addResearchElement("/guilds/aquamancer/effects/invigorating-siphon.c");

    addChild("/guilds/aquamancer/effects/staggering-damage.c",
        "/guilds/aquamancer/effects/reduce-parry.c");
    addChild("/guilds/aquamancer/effects/debilitating-damage.c",
        "/guilds/aquamancer/effects/reduce-parry.c");
    addChild("/guilds/aquamancer/effects/disorienting-damage.c",
        "/guilds/aquamancer/effects/reduce-parry.c");
    addChild("/guilds/aquamancer/effects/invigorating-siphon.c",
        "/guilds/aquamancer/effects/enhance-speed.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aquamancer/effects/hampering-damage.c");
    addResearchElement("/guilds/aquamancer/effects/exhausting-damage.c");
    addResearchElement("/guilds/aquamancer/effects/fortifying-siphon.c");

    addChild("/guilds/aquamancer/effects/hampering-damage.c",
        "/guilds/aquamancer/effects/apply-slow.c");
    addChild("/guilds/aquamancer/effects/exhausting-damage.c",
        "/guilds/aquamancer/effects/apply-enfeebled.c");
    addChild("/guilds/aquamancer/effects/fortifying-siphon.c",
        "/guilds/aquamancer/effects/invigorating-siphon.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Effects");
    Description("This research tree provides knowledge of the various effects "
        "that constructed aquamancer spells can produce.");
    Source("aquamancer");
    addResearchElement("/guilds/aquamancer/effects/root.c");
    TreeRoot("/guilds/aquamancer/effects/root.c");

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
