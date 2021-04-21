//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/fighter/techniques/defensive-stance.c");
    addResearchElement("/guilds/fighter/techniques/offensive-stance.c");
    addResearchElement("/guilds/fighter/techniques/occupy-foe.c");

    addChild("/guilds/fighter/techniques/defensive-stance.c",
        "/guilds/fighter/techniques/root.c");
    addChild("/guilds/fighter/techniques/offensive-stance.c",
        "/guilds/fighter/techniques/root.c");
    addChild("/guilds/fighter/techniques/occupy-foe.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/fighter/techniques/evade.c");

    addChild("/guilds/fighter/techniques/evade.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/fighter/techniques/precision-attack.c");
    addResearchElement("/guilds/fighter/techniques/parry.c");
    addResearchElement("/guilds/fighter/techniques/press-attack.c");

    addChild("/guilds/fighter/techniques/precision-attack.c",
        "/guilds/fighter/techniques/root.c");
    addChild("/guilds/fighter/techniques/parry.c",
        "/guilds/fighter/techniques/root.c");
    addChild("/guilds/fighter/techniques/press-attack.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/fighter/techniques/calculated-attack.c");

    addChild("/guilds/fighter/techniques/calculated-attack.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/fighter/techniques/feint.c");

    addChild("/guilds/fighter/techniques/feint.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/fighter/techniques/goad.c");

    addChild("/guilds/fighter/techniques/goad.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/fighter/techniques/pliant-armor-techniques.c");

    addChild("/guilds/fighter/techniques/pliant-armor-techniques.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/fighter/techniques/rigid-armor-techniques.c");

    addChild("/guilds/fighter/techniques/rigid-armor-techniques.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/fighter/techniques/advanced-evasion.c");

    addChild("/guilds/fighter/techniques/advanced-evasion.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/fighter/techniques/into-the-fray.c");

    addChild("/guilds/fighter/techniques/into-the-fray.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/fighter/techniques/defense-tactics.c");

    addChild("/guilds/fighter/techniques/defense-tactics.c",
        "/guilds/fighter/techniques/advanced-evasion.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/fighter/techniques/breach-defense.c");

    addChild("/guilds/fighter/techniques/breach-defense.c",
        "/guilds/fighter/techniques/press-attack.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/fighter/techniques/skirmish-tactics.c");

    addChild("/guilds/fighter/techniques/skirmish-tactics.c",
        "/guilds/fighter/techniques/into-the-fray.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/fighter/techniques/advanced-defense-tactics.c");

    addChild("/guilds/fighter/techniques/advanced-defense-tactics.c",
        "/guilds/fighter/techniques/defense-tactics.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/fighter/techniques/pliant-armor-mastery.c");
    addResearchElement("/guilds/fighter/techniques/rigid-armor-mastery.c");

    addChild("/guilds/fighter/techniques/pliant-armor-mastery.c",
        "/guilds/fighter/techniques/pliant-armor-techniques.c");
    addChild("/guilds/fighter/techniques/rigid-armor-mastery.c",
        "/guilds/fighter/techniques/rigid-armor-techniques.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/fighter/techniques/soldiers-tumult.c");

    addChild("/guilds/fighter/techniques/soldiers-tumult.c",
        "/guilds/fighter/techniques/skirmish-tactics.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/fighter/techniques/incite-ineptitude.c");

    addChild("/guilds/fighter/techniques/incite-ineptitude.c",
        "/guilds/fighter/techniques/goad.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/fighter/techniques/untapped-reserve.c");

    addChild("/guilds/fighter/techniques/untapped-reserve.c",
        "/guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/fighter/techniques/combat-mastery.c");

    addChild("/guilds/fighter/techniques/combat-mastery.c",
        "/guilds/fighter/techniques/soldiers-tumult.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/fighter/techniques/defense-mastery.c");

    addChild("/guilds/fighter/techniques/defense-mastery.c",
        "/guilds/fighter/techniques/advanced-defense-tactics.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Combat Techniques");
    Description("");
    Source("fighter");
    addResearchElement("/guilds/fighter/techniques/root.c");
    TreeRoot("/guilds/fighter/techniques/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    TenthLevel();
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
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
}
