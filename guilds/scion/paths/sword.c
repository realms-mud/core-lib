//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/stabbing.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/from-the-roof.c");

    addChild("lib/guilds/scion/paths/sword/forms/stabbing.c",
        "lib/guilds/scion/paths/sword/root.c");
    addChild("lib/guilds/scion/paths/sword/forms/from-the-roof.c",
        "lib/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/the-ox.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/the-stag.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/the-unicorn.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/wechsel.c");

    addChild("lib/guilds/scion/paths/sword/forms/the-ox.c",
        "lib/guilds/scion/paths/sword/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/sword/forms/the-stag.c",
        "lib/guilds/scion/paths/sword/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/sword/forms/the-unicorn.c",
        "lib/guilds/scion/paths/sword/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/sword/forms/wechsel.c",
        "lib/guilds/scion/paths/sword/forms/from-the-roof.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/the-plough.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/the-crown.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/near-guard.c");

    addChild("lib/guilds/scion/paths/sword/forms/the-plough.c",
        "lib/guilds/scion/paths/sword/forms/the-ox.c");
    addChild("lib/guilds/scion/paths/sword/forms/the-crown.c",
        "lib/guilds/scion/paths/sword/forms/the-ox.c");
    addChild("lib/guilds/scion/paths/sword/forms/near-guard.c",
        "lib/guilds/scion/paths/sword/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/barrier-guard.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/wrath-guard.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/hanging-point.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/hew.c");

    addChild("lib/guilds/scion/paths/sword/forms/barrier-guard.c",
        "lib/guilds/scion/paths/sword/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/sword/forms/wrath-guard.c",
        "lib/guilds/scion/paths/sword/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/sword/forms/hanging-point.c",
        "lib/guilds/scion/paths/sword/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/sword/forms/hew.c",
        "lib/guilds/scion/paths/sword/forms/stabbing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/the-fool.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/eisenport.c");

    addChild("lib/guilds/scion/paths/sword/forms/the-fool.c",
        "lib/guilds/scion/paths/sword/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/sword/forms/eisenport.c",
        "lib/guilds/scion/paths/sword/forms/the-plough.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/porta-di-ferro-alta.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/porta-di-ferro-e-stretta.c");

    addChild("lib/guilds/scion/paths/sword/forms/porta-di-ferro-alta.c",
        "lib/guilds/scion/paths/sword/forms/eisenport.c");
    addChild("lib/guilds/scion/paths/sword/forms/porta-di-ferro-e-stretta.c",
        "lib/guilds/scion/paths/sword/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/hanging-parry.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/langort.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/the-boar.c");

    addChild("lib/guilds/scion/paths/sword/forms/hanging-parry.c",
        "lib/guilds/scion/paths/sword/forms/the-fool.c");
    addChild("lib/guilds/scion/paths/sword/forms/langort.c",
        "lib/guilds/scion/paths/sword/forms/the-fool.c");
    addChild("lib/guilds/scion/paths/sword/forms/the-boar.c",
        "lib/guilds/scion/paths/sword/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/over-hew.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/middle-hew.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/under-hew.c");

    addChild("lib/guilds/scion/paths/sword/forms/over-hew.c",
        "lib/guilds/scion/paths/sword/forms/hew.c");
    addChild("lib/guilds/scion/paths/sword/forms/middle-hew.c",
        "lib/guilds/scion/paths/sword/forms/hew.c");
    addChild("lib/guilds/scion/paths/sword/forms/under-hew.c",
        "lib/guilds/scion/paths/sword/forms/hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/reverse-thrust.c");

    addChild("lib/guilds/scion/paths/sword/forms/reverse-thrust.c",
        "lib/guilds/scion/paths/sword/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/abschneiden.c");

    addChild("lib/guilds/scion/paths/sword/forms/abschneiden.c",
        "lib/guilds/scion/paths/sword/forms/hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/crooked-hew.c");

    addChild("lib/guilds/scion/paths/sword/forms/crooked-hew.c",
        "lib/guilds/scion/paths/sword/forms/middle-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/wrath-hew.c");

    addChild("lib/guilds/scion/paths/sword/forms/wrath-hew.c",
        "lib/guilds/scion/paths/sword/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/thwart-hew.c");

    addChild("lib/guilds/scion/paths/sword/forms/thwart-hew.c",
        "lib/guilds/scion/paths/sword/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/squinting-hew.c");

    addChild("lib/guilds/scion/paths/sword/forms/squinting-hew.c",
        "lib/guilds/scion/paths/sword/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/part-hew.c");

    addChild("lib/guilds/scion/paths/sword/forms/part-hew.c",
        "lib/guilds/scion/paths/sword/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("The Way of the Sword");
        Description("");
        Source("Scion of Dhuras Guild");
        addResearchElement("lib/guilds/scion/paths/sword/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/root.c");

        FirstLevel();
        SecondLevel();
        FourthLevel();
        FifthLevel();
        SixthLevel();
        SeventhLevel();
        EighthLevel();
        NinthLevel();
        TenthLevel();
        TwelfthLevel();
        ThirteenLevel();
        FifteenthLevel();
        SeventeenthLevel();
        TwentiethLevel();
        TwentyThirdLevel();
    }
}
