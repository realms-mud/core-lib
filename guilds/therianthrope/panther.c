//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/therianthrope/panther/keen-senses.c");
    addResearchElement("/guilds/therianthrope/panther/razor-claws.c");

    addChild("/guilds/therianthrope/panther/keen-senses.c",
        "/guilds/therianthrope/panther/panther-root.c");
    addChild("/guilds/therianthrope/panther/razor-claws.c",
        "/guilds/therianthrope/panther/panther-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/therianthrope/panther/pounce.c");
    addResearchElement("/guilds/therianthrope/panther/feline-agility.c");

    addChild("/guilds/therianthrope/panther/pounce.c",
        "/guilds/therianthrope/panther/razor-claws.c");
    addChild("/guilds/therianthrope/panther/feline-agility.c",
        "/guilds/therianthrope/panther/keen-senses.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/therianthrope/panther/hamstring.c");

    addChild("/guilds/therianthrope/panther/hamstring.c",
        "/guilds/therianthrope/panther/feline-agility.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/therianthrope/panther/sleek-coat.c");
    addResearchElement("/guilds/therianthrope/panther/vicious-rake.c");

    addChild("/guilds/therianthrope/panther/sleek-coat.c",
        "/guilds/therianthrope/panther/feline-agility.c");
    addChild("/guilds/therianthrope/panther/vicious-rake.c",
        "/guilds/therianthrope/panther/pounce.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/therianthrope/panther/predatory-surge.c");
    addResearchElement("/guilds/therianthrope/panther/rending-claws.c");

    addChild("/guilds/therianthrope/panther/predatory-surge.c",
        "/guilds/therianthrope/panther/vicious-rake.c");
    addChild("/guilds/therianthrope/panther/rending-claws.c",
        "/guilds/therianthrope/panther/vicious-rake.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/therianthrope/panther/predatory-grace.c");
    addResearchElement("/guilds/therianthrope/panther/nimble-recovery.c");

    addChild("/guilds/therianthrope/panther/predatory-grace.c",
        "/guilds/therianthrope/panther/vicious-rake.c");
    addChild("/guilds/therianthrope/panther/nimble-recovery.c",
        "/guilds/therianthrope/panther/sleek-coat.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/therianthrope/panther/precision-strikes.c");
    addResearchElement("/guilds/therianthrope/panther/offensive-stance.c");

    addChild("/guilds/therianthrope/panther/precision-strikes.c",
        "/guilds/therianthrope/panther/rending-claws.c");
    addChild("/guilds/therianthrope/panther/offensive-stance.c",
        "/guilds/therianthrope/panther/predatory-grace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/therianthrope/panther/killing-instinct.c");
    addResearchElement("/guilds/therianthrope/panther/evasive-maneuvers.c");

    addChild("/guilds/therianthrope/panther/killing-instinct.c",
        "/guilds/therianthrope/panther/predatory-grace.c");
    addChild("/guilds/therianthrope/panther/evasive-maneuvers.c",
        "/guilds/therianthrope/panther/nimble-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/therianthrope/panther/savage-frenzy.c");
    addResearchElement("/guilds/therianthrope/panther/hunting-efficiency.c");

    addChild("/guilds/therianthrope/panther/savage-frenzy.c",
        "/guilds/therianthrope/panther/killing-instinct.c");
    addChild("/guilds/therianthrope/panther/hunting-efficiency.c",
        "/guilds/therianthrope/panther/precision-strikes.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/panther/shadow-stalker.c");
    addResearchElement("/guilds/therianthrope/panther/lithe-form.c");

    addChild("/guilds/therianthrope/panther/shadow-stalker.c",
        "/guilds/therianthrope/panther/killing-instinct.c");
    addChild("/guilds/therianthrope/panther/lithe-form.c",
        "/guilds/therianthrope/panther/evasive-maneuvers.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/panther/throat-tear.c");
    addResearchElement("/guilds/therianthrope/panther/shadow-stalk.c");
    addResearchElement("/guilds/therianthrope/panther/night-eyes.c");

    addChild("/guilds/therianthrope/panther/throat-tear.c",
        "/guilds/therianthrope/panther/shadow-stalker.c");
    addChild("/guilds/therianthrope/panther/shadow-stalk.c",
        "/guilds/therianthrope/panther/shadow-stalker.c");
    addChild("/guilds/therianthrope/panther/night-eyes.c",
        "/guilds/therianthrope/panther/lithe-form.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/panther/blinding-speed.c");

    addChild("/guilds/therianthrope/panther/blinding-speed.c",
        "/guilds/therianthrope/panther/hunting-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/panther/phantasmal-panther.c");
    addResearchElement("/guilds/therianthrope/panther/ghostly-reflexes.c");

    addChild("/guilds/therianthrope/panther/phantasmal-panther.c",
        "/guilds/therianthrope/panther/shadow-stalker.c");
    addChild("/guilds/therianthrope/panther/ghostly-reflexes.c",
        "/guilds/therianthrope/panther/night-eyes.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/panther/lord-of-the-hunt.c");

    addChild("/guilds/therianthrope/panther/lord-of-the-hunt.c",
        "/guilds/therianthrope/panther/phantasmal-panther.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Panther Form");
    Description("This research tree provides knowledge of transforming into "
        "a sleek panther. The panther form excels at speed, evasion, and "
        "rapid strikes. Progressive mastery unlocks sharper claws, faster "
        "attacks, shadow-infused abilities, and eventually the ultimate "
        "predatory form.");
    Source("therianthrope");
    addResearchElement("/guilds/therianthrope/panther/panther-root.c");
    TreeRoot("/guilds/therianthrope/panther/panther-root.c");

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
    ThirtyFirstLevel();
}
