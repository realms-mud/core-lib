//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/fighter/axes/chop.c");

    addChild("/guilds/fighter/axes/chop.c",
        "/guilds/fighter/axes/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/fighter/axes/thrash.c");

    addChild("/guilds/fighter/axes/thrash.c",
        "/guilds/fighter/axes/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/fighter/axes/axe-guarding.c");
    addResearchElement("/guilds/fighter/axes/basic-chops.c");

    addChild("/guilds/fighter/axes/axe-guarding.c",
        "/guilds/fighter/axes/root.c");
    addChild("/guilds/fighter/axes/basic-chops.c",
        "/guilds/fighter/axes/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/fighter/axes/axemasters-boon.c");

    addChild("/guilds/fighter/axes/axemasters-boon.c",
        "/guilds/fighter/axes/chop.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/fighter/axes/strike-the-blood.c");

    addChild("/guilds/fighter/axes/strike-the-blood.c",
        "/guilds/fighter/axes/chop.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/fighter/axes/axemasters-reserve.c");

    addChild("/guilds/fighter/axes/axemasters-reserve.c",
        "/guilds/fighter/axes/chop.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/fighter/axes/hack.c");

    addChild("/guilds/fighter/axes/hack.c",
        "/guilds/fighter/axes/chop.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/fighter/axes/fools-strike.c");

    addChild("/guilds/fighter/axes/fools-strike.c",
        "/guilds/fighter/axes/strike-the-blood.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/fighter/axes/axemasters-speed.c");

    addChild("/guilds/fighter/axes/axemasters-speed.c",
        "/guilds/fighter/axes/axemasters-boon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/fighter/axes/sweeping-hew.c");

    addChild("/guilds/fighter/axes/sweeping-hew.c",
        "/guilds/fighter/axes/hack.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/fighter/axes/hooking-strike.c");
    addResearchElement("/guilds/fighter/axes/axemasters-call.c");

    addChild("/guilds/fighter/axes/hooking-strike.c",
        "/guilds/fighter/axes/fools-strike.c");
    addChild("/guilds/fighter/axes/axemasters-call.c",
        "/guilds/fighter/axes/axemasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/fighter/axes/horn-thrust.c");
    addResearchElement("/guilds/fighter/axes/axemasters-endurance.c");

    addChild("/guilds/fighter/axes/horn-thrust.c",
        "/guilds/fighter/axes/hooking-strike.c");
    addChild("/guilds/fighter/axes/axemasters-endurance.c",
        "/guilds/fighter/axes/axemasters-speed.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/fighter/axes/punishing-hack.c");

    addChild("/guilds/fighter/axes/punishing-hack.c",
        "/guilds/fighter/axes/thrash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/fighter/axes/axemasters-might.c");

    addChild("/guilds/fighter/axes/axemasters-might.c",
        "/guilds/fighter/axes/axemasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/fighter/axes/haft-strike.c");

    addChild("/guilds/fighter/axes/haft-strike.c",
        "/guilds/fighter/axes/horn-thrust.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/fighter/axes/axemasters-strength.c");

    addChild("/guilds/fighter/axes/axemasters-strength.c",
        "/guilds/fighter/axes/axemasters-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/fighter/axes/arresting-blow.c");

    addChild("/guilds/fighter/axes/arresting-blow.c",
        "/guilds/fighter/axes/haft-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/fighter/axes/axemasters-fury.c");

    addChild("/guilds/fighter/axes/axemasters-fury.c",
        "/guilds/fighter/axes/axemasters-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/fighter/axes/arc-strike.c");

    addChild("/guilds/fighter/axes/arc-strike.c",
        "/guilds/fighter/axes/arresting-blow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/fighter/axes/broad-stroke.c");

    addChild("/guilds/fighter/axes/broad-stroke.c",
        "/guilds/fighter/axes/arc-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/fighter/axes/uplifting-sweep.c");

    addChild("/guilds/fighter/axes/uplifting-sweep.c",
        "/guilds/fighter/axes/broad-stroke.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/fighter/axes/master-chop.c");

    addChild("/guilds/fighter/axes/master-chop.c",
        "/guilds/fighter/axes/uplifting-sweep.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Axe Attacks");
    Description("");
    Source("fighter");
    addResearchElement("/guilds/fighter/axes/root.c");
    TreeRoot("/guilds/fighter/axes/root.c");

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
