//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/pyromancer/effects/damage-hp.c");
    addResearchElement("/guilds/pyromancer/effects/add-hp.c");

    addChild("/guilds/pyromancer/effects/damage-hp.c",
        "/guilds/pyromancer/effects/root.c");
    addChild("/guilds/pyromancer/effects/add-hp.c",
        "/guilds/pyromancer/effects/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/pyromancer/effects/damage-sp.c");
    addResearchElement("/guilds/pyromancer/effects/add-sp.c");

    addChild("/guilds/pyromancer/effects/damage-sp.c",
        "/guilds/pyromancer/effects/damage-hp.c");
    addChild("/guilds/pyromancer/effects/add-sp.c",
        "/guilds/pyromancer/effects/add-hp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/pyromancer/effects/damage-stamina.c");
    addResearchElement("/guilds/pyromancer/effects/add-stamina.c");

    addChild("/guilds/pyromancer/effects/damage-stamina.c",
        "/guilds/pyromancer/effects/damage-sp.c");
    addChild("/guilds/pyromancer/effects/add-stamina.c",
        "/guilds/pyromancer/effects/add-sp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/pyromancer/effects/siphon-hp.c");
    addResearchElement("/guilds/pyromancer/effects/enhance-attack.c");
    addResearchElement("/guilds/pyromancer/effects/reduce-attack.c");

    addChild("/guilds/pyromancer/effects/siphon-hp.c",
        "/guilds/pyromancer/effects/damage-hp.c");
    addChild("/guilds/pyromancer/effects/enhance-attack.c",
        "/guilds/pyromancer/effects/add-hp.c");
    addChild("/guilds/pyromancer/effects/reduce-attack.c",
        "/guilds/pyromancer/effects/damage-hp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/pyromancer/effects/siphon-sp.c");
    addResearchElement("/guilds/pyromancer/effects/enhance-damage.c");
    addResearchElement("/guilds/pyromancer/effects/reduce-damage.c");

    addChild("/guilds/pyromancer/effects/siphon-sp.c",
        "/guilds/pyromancer/effects/siphon-hp.c");
    addChild("/guilds/pyromancer/effects/enhance-damage.c",
        "/guilds/pyromancer/effects/enhance-attack.c");
    addChild("/guilds/pyromancer/effects/reduce-damage.c",
        "/guilds/pyromancer/effects/reduce-attack.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/pyromancer/effects/siphon-stamina.c");
    addResearchElement("/guilds/pyromancer/effects/enhance-defense.c");
    addResearchElement("/guilds/pyromancer/effects/reduce-defense.c");

    addChild("/guilds/pyromancer/effects/siphon-stamina.c",
        "/guilds/pyromancer/effects/siphon-sp.c");
    addChild("/guilds/pyromancer/effects/enhance-defense.c",
        "/guilds/pyromancer/effects/enhance-damage.c");
    addChild("/guilds/pyromancer/effects/reduce-defense.c",
        "/guilds/pyromancer/effects/reduce-damage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/pyromancer/effects/enhance-soak.c");
    addResearchElement("/guilds/pyromancer/effects/reduce-soak.c");

    addChild("/guilds/pyromancer/effects/enhance-soak.c",
        "/guilds/pyromancer/effects/enhance-defense.c");
    addChild("/guilds/pyromancer/effects/reduce-soak.c",
        "/guilds/pyromancer/effects/reduce-defense.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/pyromancer/effects/enhance-dodge.c");
    addResearchElement("/guilds/pyromancer/effects/reduce-dodge.c");
    addResearchElement("/guilds/pyromancer/effects/apply-slow.c");

    addChild("/guilds/pyromancer/effects/enhance-dodge.c",
        "/guilds/pyromancer/effects/enhance-soak.c");
    addChild("/guilds/pyromancer/effects/reduce-dodge.c",
        "/guilds/pyromancer/effects/reduce-soak.c");
    addChild("/guilds/pyromancer/effects/apply-slow.c",
        "/guilds/pyromancer/effects/reduce-soak.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/pyromancer/effects/enhance-parry.c");
    addResearchElement("/guilds/pyromancer/effects/reduce-parry.c");
    addResearchElement("/guilds/pyromancer/effects/enhance-speed.c");
    addResearchElement("/guilds/pyromancer/effects/apply-enfeebled.c");

    addChild("/guilds/pyromancer/effects/enhance-parry.c",
        "/guilds/pyromancer/effects/enhance-dodge.c");
    addChild("/guilds/pyromancer/effects/reduce-parry.c",
        "/guilds/pyromancer/effects/reduce-dodge.c");
    addChild("/guilds/pyromancer/effects/enhance-speed.c",
        "/guilds/pyromancer/effects/enhance-dodge.c");
    addChild("/guilds/pyromancer/effects/apply-enfeebled.c",
        "/guilds/pyromancer/effects/apply-slow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/pyromancer/effects/staggering-damage.c");
    addResearchElement("/guilds/pyromancer/effects/debilitating-damage.c");
    addResearchElement("/guilds/pyromancer/effects/disorienting-damage.c");
    addResearchElement("/guilds/pyromancer/effects/invigorating-siphon.c");

    addChild("/guilds/pyromancer/effects/staggering-damage.c",
        "/guilds/pyromancer/effects/reduce-parry.c");
    addChild("/guilds/pyromancer/effects/debilitating-damage.c",
        "/guilds/pyromancer/effects/reduce-parry.c");
    addChild("/guilds/pyromancer/effects/disorienting-damage.c",
        "/guilds/pyromancer/effects/reduce-parry.c");
    addChild("/guilds/pyromancer/effects/invigorating-siphon.c",
        "/guilds/pyromancer/effects/enhance-speed.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/effects/hampering-damage.c");
    addResearchElement("/guilds/pyromancer/effects/exhausting-damage.c");
    addResearchElement("/guilds/pyromancer/effects/fortifying-siphon.c");

    addChild("/guilds/pyromancer/effects/hampering-damage.c",
        "/guilds/pyromancer/effects/apply-slow.c");
    addChild("/guilds/pyromancer/effects/exhausting-damage.c",
        "/guilds/pyromancer/effects/apply-enfeebled.c");
    addChild("/guilds/pyromancer/effects/fortifying-siphon.c",
        "/guilds/pyromancer/effects/invigorating-siphon.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Effects");
    Description("This research tree provides knowledge of the various effects "
        "that constructed pyromancer spells can produce.");
    Source("pyromancer");
    addResearchElement("/guilds/pyromancer/effects/root.c");
    TreeRoot("/guilds/pyromancer/effects/root.c");

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
