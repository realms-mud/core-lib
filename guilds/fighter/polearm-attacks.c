//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/fighter/polearms/skewer.c");

    addChild("/guilds/fighter/polearms/skewer.c",
        "/guilds/fighter/polearms/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/fighter/polearms/gash.c");

    addChild("/guilds/fighter/polearms/gash.c",
        "/guilds/fighter/polearms/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/fighter/polearms/polearm-guarding.c");
    addResearchElement("/guilds/fighter/polearms/basic-skewers.c");

    addChild("/guilds/fighter/polearms/polearm-guarding.c",
        "/guilds/fighter/polearms/root.c");
    addChild("/guilds/fighter/polearms/basic-skewers.c",
        "/guilds/fighter/polearms/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/fighter/polearms/polemasters-boon.c");

    addChild("/guilds/fighter/polearms/polemasters-boon.c",
        "/guilds/fighter/polearms/skewer.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/fighter/polearms/forceful-thrust.c");

    addChild("/guilds/fighter/polearms/forceful-thrust.c",
        "/guilds/fighter/polearms/skewer.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/fighter/polearms/polemasters-reserve.c");

    addChild("/guilds/fighter/polearms/polemasters-reserve.c",
        "/guilds/fighter/polearms/skewer.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/fighter/polearms/impale.c");

    addChild("/guilds/fighter/polearms/impale.c",
        "/guilds/fighter/polearms/skewer.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/fighter/polearms/fools-bayonet.c");

    addChild("/guilds/fighter/polearms/fools-bayonet.c",
        "/guilds/fighter/polearms/forceful-thrust.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/fighter/polearms/polemasters-speed.c");

    addChild("/guilds/fighter/polearms/polemasters-speed.c",
        "/guilds/fighter/polearms/polemasters-boon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/fighter/polearms/sweeping-strike.c");

    addChild("/guilds/fighter/polearms/sweeping-strike.c",
        "/guilds/fighter/polearms/impale.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/fighter/polearms/hooking-thrust.c");
    addResearchElement("/guilds/fighter/polearms/polemasters-call.c");

    addChild("/guilds/fighter/polearms/hooking-thrust.c",
        "/guilds/fighter/polearms/fools-bayonet.c");
    addChild("/guilds/fighter/polearms/polemasters-call.c",
        "/guilds/fighter/polearms/polemasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/fighter/polearms/perforation.c");
    addResearchElement("/guilds/fighter/polearms/polemasters-endurance.c");

    addChild("/guilds/fighter/polearms/perforation.c",
        "/guilds/fighter/polearms/hooking-thrust.c");
    addChild("/guilds/fighter/polearms/polemasters-endurance.c",
        "/guilds/fighter/polearms/polemasters-speed.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/fighter/polearms/gore.c");

    addChild("/guilds/fighter/polearms/gore.c",
        "/guilds/fighter/polearms/gash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/fighter/polearms/polemasters-might.c");

    addChild("/guilds/fighter/polearms/polemasters-might.c",
        "/guilds/fighter/polearms/polemasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/fighter/polearms/transfix.c");

    addChild("/guilds/fighter/polearms/transfix.c",
        "/guilds/fighter/polearms/perforation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/fighter/polearms/polemasters-strength.c");

    addChild("/guilds/fighter/polearms/polemasters-strength.c",
        "/guilds/fighter/polearms/polemasters-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/fighter/polearms/piercing-blow.c");

    addChild("/guilds/fighter/polearms/piercing-blow.c",
        "/guilds/fighter/polearms/transfix.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/fighter/polearms/polemasters-fury.c");

    addChild("/guilds/fighter/polearms/polemasters-fury.c",
        "/guilds/fighter/polearms/polemasters-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/fighter/polearms/penetration.c");

    addChild("/guilds/fighter/polearms/penetration.c",
        "/guilds/fighter/polearms/piercing-blow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/fighter/polearms/slicing-stroke.c");

    addChild("/guilds/fighter/polearms/slicing-stroke.c",
        "/guilds/fighter/polearms/penetration.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/fighter/polearms/lunging-strike.c");

    addChild("/guilds/fighter/polearms/lunging-strike.c",
        "/guilds/fighter/polearms/slicing-stroke.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/fighter/polearms/master-skewer.c");

    addChild("/guilds/fighter/polearms/master-skewer.c",
        "/guilds/fighter/polearms/lunging-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Polearm Attacks");
    Description("");
    Source("fighter");
    addResearchElement("/guilds/fighter/polearms/root.c");
    TreeRoot("/guilds/fighter/polearms/root.c");

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
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFifthLevel();
    FiftyFirstLevel();
    FiftySeventhLevel();
    SixtyThirdLevel();
}
