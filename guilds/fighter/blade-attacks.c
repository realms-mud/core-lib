//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/fighter/blades/slash.c");

    addChild("guilds/fighter/blades/slash.c",
        "guilds/fighter/blades/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/fighter/blades/thrust.c");

    addChild("guilds/fighter/blades/thrust.c",
        "guilds/fighter/blades/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("guilds/fighter/blades/calculated-attack.c");

    addChild("guilds/fighter/blades/calculated-attack.c",
        "guilds/fighter/blades/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/fighter/blades/blademasters-boon.c");

    addChild("guilds/fighter/blades/blademasters-boon.c",
        "guilds/fighter/blades/slash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/fighter/blades/under-cutting.c");

    addChild("guilds/fighter/blades/under-cutting.c",
        "guilds/fighter/blades/slash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("guilds/fighter/blades/blademasters-reserve.c");

    addChild("guilds/fighter/blades/blademasters-reserve.c",
        "guilds/fighter/blades/slash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("guilds/fighter/blades/cleave.c");

    addChild("guilds/fighter/blades/cleave.c",
        "guilds/fighter/blades/slash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/fighter/blades/reverse-cut.c");

    addChild("guilds/fighter/blades/reverse-cut.c",
        "guilds/fighter/blades/under-cutting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/fighter/blades/blademasters-speed.c");

    addChild("guilds/fighter/blades/blademasters-speed.c",
        "guilds/fighter/blades/blademasters-boon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/fighter/blades/whirlwind.c");

    addChild("guilds/fighter/blades/whirlwind.c",
        "guilds/fighter/blades/cleave.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("guilds/fighter/blades/double-back.c");
    addResearchElement("guilds/fighter/blades/blademasters-call.c");

    addChild("guilds/fighter/blades/double-back.c",
        "guilds/fighter/blades/reverse-cut.c");
    addChild("guilds/fighter/blades/blademasters-call.c",
        "guilds/fighter/blades/blademasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("guilds/fighter/blades/riposte.c");
    addResearchElement("guilds/fighter/blades/blademasters-endurance.c");

    addChild("guilds/fighter/blades/riposte.c",
        "guilds/fighter/blades/double-back.c");
    addChild("guilds/fighter/blades/blademasters-endurance.c",
        "guilds/fighter/blades/blademasters-speed.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/fighter/blades/piercing-strike.c");

    addChild("guilds/fighter/blades/piercing-strike.c",
        "guilds/fighter/blades/thrust.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("guilds/fighter/blades/blademasters-might.c");

    addChild("guilds/fighter/blades/blademasters-might.c",
        "guilds/fighter/blades/blademasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("guilds/fighter/blades/reversing-the-blade.c");

    addChild("guilds/fighter/blades/reversing-the-blade.c",
        "guilds/fighter/blades/riposte.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("guilds/fighter/blades/blademasters-strength.c");

    addChild("guilds/fighter/blades/blademasters-strength.c",
        "guilds/fighter/blades/blademasters-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("guilds/fighter/blades/over-cutting.c");

    addChild("guilds/fighter/blades/over-cutting.c",
        "guilds/fighter/blades/reversing-the-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("guilds/fighter/blades/blademasters-fury.c");

    addChild("guilds/fighter/blades/blademasters-fury.c",
        "guilds/fighter/blades/blademasters-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("guilds/fighter/blades/cross-cutting.c");

    addChild("guilds/fighter/blades/cross-cutting.c",
        "guilds/fighter/blades/over-cutting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("guilds/fighter/blades/dancing-blade.c");

    addChild("guilds/fighter/blades/dancing-blade.c",
        "guilds/fighter/blades/cross-cutting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("guilds/fighter/blades/hanging-cut.c");

    addChild("guilds/fighter/blades/hanging-cut.c",
        "guilds/fighter/blades/dancing-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("guilds/fighter/blades/master-stroke.c");

    addChild("guilds/fighter/blades/master-stroke.c",
        "guilds/fighter/blades/hanging-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Blade Attacks");
    Description("");
    Source("fighter");
    addResearchElement("guilds/fighter/blades/root.c");
    TreeRoot("guilds/fighter/blades/root.c");

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
