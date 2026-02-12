//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/therianthrope/bear/thick-hide.c");
    addResearchElement("/guilds/therianthrope/bear/primal-strength.c");

    addChild("/guilds/therianthrope/bear/thick-hide.c",
        "/guilds/therianthrope/bear/bear-root.c");
    addChild("/guilds/therianthrope/bear/primal-strength.c",
        "/guilds/therianthrope/bear/bear-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/therianthrope/bear/bear-claws.c");
    addResearchElement("/guilds/therianthrope/bear/ursine-endurance.c");

    addChild("/guilds/therianthrope/bear/bear-claws.c",
        "/guilds/therianthrope/bear/primal-strength.c");
    addChild("/guilds/therianthrope/bear/ursine-endurance.c",
        "/guilds/therianthrope/bear/thick-hide.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/therianthrope/bear/crushing-bite.c");

    addChild("/guilds/therianthrope/bear/crushing-bite.c",
        "/guilds/therianthrope/bear/ursine-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/therianthrope/bear/iron-fur.c");
    addResearchElement("/guilds/therianthrope/bear/mighty-swipe.c");

    addChild("/guilds/therianthrope/bear/iron-fur.c",
        "/guilds/therianthrope/bear/ursine-endurance.c");
    addChild("/guilds/therianthrope/bear/mighty-swipe.c",
        "/guilds/therianthrope/bear/bear-claws.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/therianthrope/bear/bear-charge.c");

    addChild("/guilds/therianthrope/bear/bear-charge.c",
        "/guilds/therianthrope/bear/mighty-swipe.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/therianthrope/bear/ursine-fury.c");
    addResearchElement("/guilds/therianthrope/bear/den-mother.c");

    addChild("/guilds/therianthrope/bear/ursine-fury.c",
        "/guilds/therianthrope/bear/mighty-swipe.c");
    addChild("/guilds/therianthrope/bear/den-mother.c",
        "/guilds/therianthrope/bear/iron-fur.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/therianthrope/bear/claw-mastery.c");
    addResearchElement("/guilds/therianthrope/bear/defensive-stance.c");

    addChild("/guilds/therianthrope/bear/claw-mastery.c",
        "/guilds/therianthrope/bear/bear-charge.c");
    addChild("/guilds/therianthrope/bear/defensive-stance.c",
        "/guilds/therianthrope/bear/den-mother.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/therianthrope/bear/savage-instinct.c");
    addResearchElement("/guilds/therianthrope/bear/hardened-bones.c");

    addChild("/guilds/therianthrope/bear/savage-instinct.c",
        "/guilds/therianthrope/bear/ursine-fury.c");
    addChild("/guilds/therianthrope/bear/hardened-bones.c",
        "/guilds/therianthrope/bear/den-mother.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/therianthrope/bear/maul.c");
    addResearchElement("/guilds/therianthrope/bear/attack-efficiency.c");

    addChild("/guilds/therianthrope/bear/maul.c",
        "/guilds/therianthrope/bear/savage-instinct.c");
    addChild("/guilds/therianthrope/bear/attack-efficiency.c",
        "/guilds/therianthrope/bear/claw-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/bear/apex-predator.c");
    addResearchElement("/guilds/therianthrope/bear/mountain-hide.c");

    addChild("/guilds/therianthrope/bear/apex-predator.c",
        "/guilds/therianthrope/bear/savage-instinct.c");
    addChild("/guilds/therianthrope/bear/mountain-hide.c",
        "/guilds/therianthrope/bear/hardened-bones.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/bear/thunderous-roar.c");
    addResearchElement("/guilds/therianthrope/bear/regeneration.c");

    addChild("/guilds/therianthrope/bear/thunderous-roar.c",
        "/guilds/therianthrope/bear/apex-predator.c");
    addChild("/guilds/therianthrope/bear/regeneration.c",
        "/guilds/therianthrope/bear/mountain-hide.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/bear/attack-speed.c");

    addChild("/guilds/therianthrope/bear/attack-speed.c",
        "/guilds/therianthrope/bear/attack-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/bear/primordial-beast.c");
    addResearchElement("/guilds/therianthrope/bear/earthen-resilience.c");

    addChild("/guilds/therianthrope/bear/primordial-beast.c",
        "/guilds/therianthrope/bear/apex-predator.c");
    addChild("/guilds/therianthrope/bear/earthen-resilience.c",
        "/guilds/therianthrope/bear/regeneration.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/bear/titanic-bear.c");

    addChild("/guilds/therianthrope/bear/titanic-bear.c",
        "/guilds/therianthrope/bear/primordial-beast.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Bear Form");
    Description("This research tree provides knowledge of transforming into "
        "a massive bear. The bear form excels at absorbing damage and dealing "
        "devastating physical attacks through raw strength. Progressive "
        "mastery unlocks thicker hide, more powerful attacks, and eventually "
        "a titanic form of unmatched power and resilience.");
    Source("therianthrope");
    addResearchElement("/guilds/therianthrope/bear/bear-root.c");
    TreeRoot("/guilds/therianthrope/bear/bear-root.c");

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
