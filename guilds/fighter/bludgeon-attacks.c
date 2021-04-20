//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/pummel.c");

    addChild("/guilds/fighter/bludgeon/pummel.c",
        "/guilds/fighter/bludgeon/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/cudgel.c");

    addChild("/guilds/fighter/bludgeon/cudgel.c",
        "/guilds/fighter/bludgeon/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/haft-guarding.c");
    addResearchElement("/guilds/fighter/bludgeon/basic-hits.c");

    addChild("/guilds/fighter/bludgeon/haft-guarding.c",
        "/guilds/fighter/bludgeon/root.c");
    addChild("/guilds/fighter/bludgeon/basic-hits.c",
        "/guilds/fighter/bludgeon/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/bludgeoners-boon.c");

    addChild("/guilds/fighter/bludgeon/bludgeoners-boon.c",
        "/guilds/fighter/bludgeon/pummel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/under-striking.c");

    addChild("/guilds/fighter/bludgeon/under-striking.c",
        "/guilds/fighter/bludgeon/pummel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/bludgeoners-reserve.c");

    addChild("/guilds/fighter/bludgeon/bludgeoners-reserve.c",
        "/guilds/fighter/bludgeon/pummel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/crush.c");

    addChild("/guilds/fighter/bludgeon/crush.c",
        "/guilds/fighter/bludgeon/pummel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/reverse-bash.c");

    addChild("/guilds/fighter/bludgeon/reverse-bash.c",
        "/guilds/fighter/bludgeon/under-striking.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/bludgeoners-speed.c");

    addChild("/guilds/fighter/bludgeon/bludgeoners-speed.c",
        "/guilds/fighter/bludgeon/bludgeoners-boon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/battering-arc.c");

    addChild("/guilds/fighter/bludgeon/battering-arc.c",
        "/guilds/fighter/bludgeon/crush.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/redoubled-push.c");
    addResearchElement("/guilds/fighter/bludgeon/bludgeoners-call.c");

    addChild("/guilds/fighter/bludgeon/redoubled-push.c",
        "/guilds/fighter/bludgeon/reverse-bash.c");
    addChild("/guilds/fighter/bludgeon/bludgeoners-call.c",
        "/guilds/fighter/bludgeon/bludgeoners-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/unrelenting-strike.c");
    addResearchElement("/guilds/fighter/bludgeon/bludgeoners-endurance.c");

    addChild("/guilds/fighter/bludgeon/unrelenting-strike.c",
        "/guilds/fighter/bludgeon/redoubled-push.c");
    addChild("/guilds/fighter/bludgeon/bludgeoners-endurance.c",
        "/guilds/fighter/bludgeon/bludgeoners-speed.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/crushing-strike.c");

    addChild("/guilds/fighter/bludgeon/crushing-strike.c",
        "/guilds/fighter/bludgeon/cudgel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/bludgeoners-might.c");

    addChild("/guilds/fighter/bludgeon/bludgeoners-might.c",
        "/guilds/fighter/bludgeon/bludgeoners-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/reversing-the-swing.c");

    addChild("/guilds/fighter/bludgeon/reversing-the-swing.c",
        "/guilds/fighter/bludgeon/unrelenting-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/bludgeoners-strength.c");

    addChild("/guilds/fighter/bludgeon/bludgeoners-strength.c",
        "/guilds/fighter/bludgeon/bludgeoners-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/over-driving.c");

    addChild("/guilds/fighter/bludgeon/over-driving.c",
        "/guilds/fighter/bludgeon/reversing-the-swing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/bludgeoners-fury.c");

    addChild("/guilds/fighter/bludgeon/bludgeoners-fury.c",
        "/guilds/fighter/bludgeon/bludgeoners-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/cross-driving.c");

    addChild("/guilds/fighter/bludgeon/cross-driving.c",
        "/guilds/fighter/bludgeon/over-driving.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/dancing-cudgel.c");

    addChild("/guilds/fighter/bludgeon/dancing-cudgel.c",
        "/guilds/fighter/bludgeon/cross-driving.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/hanging-stroke.c");

    addChild("/guilds/fighter/bludgeon/hanging-stroke.c",
        "/guilds/fighter/bludgeon/dancing-cudgel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/fighter/bludgeon/master-bludgeon.c");

    addChild("/guilds/fighter/bludgeon/master-bludgeon.c",
        "/guilds/fighter/bludgeon/hanging-stroke.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Bludgeon Attacks");
    Description("");
    Source("fighter");
    addResearchElement("/guilds/fighter/bludgeon/root.c");
    TreeRoot("/guilds/fighter/bludgeon/root.c");

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
