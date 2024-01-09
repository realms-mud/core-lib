//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/fighter/shields/block.c");

    addChild("/guilds/fighter/shields/block.c",
        "/guilds/fighter/shields/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/fighter/shields/shield-bash.c");
    addResearchElement("/guilds/fighter/shields/basic-shield-techniques.c");

    addChild("/guilds/fighter/shields/shield-bash.c",
        "/guilds/fighter/shields/root.c");
    addChild("/guilds/fighter/shields/basic-shield-techniques.c",
        "/guilds/fighter/shields/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/fighter/shields/stunning-blow.c");
    addResearchElement("/guilds/fighter/shields/prone-strike.c");

    addChild("/guilds/fighter/shields/stunning-blow.c",
        "/guilds/fighter/shields/root.c");
    addChild("/guilds/fighter/shields/prone-strike.c",
        "/guilds/fighter/shields/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/fighter/shields/shieldmasters-boon.c");
    addResearchElement("/guilds/fighter/shields/shield-bearing.c");

    addChild("/guilds/fighter/shields/shieldmasters-boon.c",
        "/guilds/fighter/shields/shield-bash.c");
    addChild("/guilds/fighter/shields/shield-bearing.c",
        "/guilds/fighter/shields/basic-shield-techniques.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/fighter/shields/improvised-attack.c");

    addChild("/guilds/fighter/shields/improvised-attack.c",
        "/guilds/fighter/shields/shield-bash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/fighter/shields/shieldmasters-reserve.c");

    addChild("/guilds/fighter/shields/shieldmasters-reserve.c",
        "/guilds/fighter/shields/shield-bash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/fighter/shields/intermediate-shield-techniques.c");

    addChild("/guilds/fighter/shields/intermediate-shield-techniques.c",
        "/guilds/fighter/shields/shield-bearing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/fighter/shields/reverse-sweep.c");

    addChild("/guilds/fighter/shields/reverse-sweep.c",
        "/guilds/fighter/shields/improvised-attack.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/fighter/shields/shieldmasters-speed.c");

    addChild("/guilds/fighter/shields/shieldmasters-speed.c",
        "/guilds/fighter/shields/shieldmasters-boon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/fighter/shields/shield-strike.c");

    addChild("/guilds/fighter/shields/shield-strike.c",
        "/guilds/fighter/shields/shield-bash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/fighter/shields/using-the-edge.c");
    addResearchElement("/guilds/fighter/shields/shieldmasters-call.c");

    addChild("/guilds/fighter/shields/using-the-edge.c",
        "/guilds/fighter/shields/reverse-sweep.c");
    addChild("/guilds/fighter/shields/shieldmasters-call.c",
        "/guilds/fighter/shields/shieldmasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/fighter/shields/offensive-techniques.c");

    addChild("/guilds/fighter/shields/offensive-techniques.c",
        "/guilds/fighter/shields/intermediate-shield-techniques.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/fighter/shields/advanced-shield-techniques.c");

    addChild("/guilds/fighter/shields/advanced-shield-techniques.c",
        "/guilds/fighter/shields/intermediate-shield-techniques.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/fighter/shields/breaking-through.c");
    addResearchElement("/guilds/fighter/shields/shieldmasters-endurance.c");

    addChild("/guilds/fighter/shields/breaking-through.c",
        "/guilds/fighter/shields/using-the-edge.c");
    addChild("/guilds/fighter/shields/shieldmasters-endurance.c",
        "/guilds/fighter/shields/shieldmasters-speed.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/fighter/shields/shieldmasters-might.c");

    addChild("/guilds/fighter/shields/shieldmasters-might.c",
        "/guilds/fighter/shields/shieldmasters-call.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/fighter/shields/shield-thrusting.c");

    addChild("/guilds/fighter/shields/shield-thrusting.c",
        "/guilds/fighter/shields/breaking-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/fighter/shields/shieldmasters-strength.c");

    addChild("/guilds/fighter/shields/shieldmasters-strength.c",
        "/guilds/fighter/shields/shieldmasters-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/fighter/shields/crushing-drive.c");

    addChild("/guilds/fighter/shields/crushing-drive.c",
        "/guilds/fighter/shields/shield-thrusting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/fighter/shields/shieldmasters-fury.c");

    addChild("/guilds/fighter/shields/shieldmasters-fury.c",
        "/guilds/fighter/shields/shieldmasters-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/fighter/shields/disruptive-striking.c");

    addChild("/guilds/fighter/shields/disruptive-striking.c",
        "/guilds/fighter/shields/crushing-drive.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/fighter/shields/edge-striking.c");

    addChild("/guilds/fighter/shields/edge-striking.c",
        "/guilds/fighter/shields/disruptive-striking.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/fighter/shields/face-striking.c");

    addChild("/guilds/fighter/shields/face-striking.c",
        "/guilds/fighter/shields/edge-striking.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/fighter/shields/shield-mastery.c");

    addChild("/guilds/fighter/shields/shield-mastery.c",
        "/guilds/fighter/shields/face-striking.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Shields");
    Description("");
    Source("fighter");
    addResearchElement("/guilds/fighter/shields/root.c");
    TreeRoot("/guilds/fighter/shields/root.c");

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
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFirstLevel();
    FortyFifthLevel();
    FiftyFirstLevel();
    FiftySeventhLevel();
    SixtyThirdLevel();
}
