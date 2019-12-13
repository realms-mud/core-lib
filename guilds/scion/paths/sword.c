//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/stabbing.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/thrusting.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/from-the-roof.c");

    addChild("lib/guilds/scion/paths/sword/forms/stabbing.c",
        "lib/guilds/scion/paths/sword/root.c");
    addChild("lib/guilds/scion/paths/sword/forms/thrusting.c",
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
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/evade.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/overcut.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/undercut.c");

    addChild("lib/guilds/scion/paths/sword/forms/evade.c",
        "lib/guilds/scion/paths/sword/root.c");
    addChild("lib/guilds/scion/paths/sword/forms/overcut.c",
        "lib/guilds/scion/paths/sword/root.c");
    addChild("lib/guilds/scion/paths/sword/forms/undercut.c",
        "lib/guilds/scion/paths/sword/root.c");
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
    addResearchElement("lib/guilds/scion/paths/sword/forms/side-stepping.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/porta-di-ferro-alta.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/porta-di-ferro-e-stretta.c");

    addChild("lib/guilds/scion/paths/sword/forms/side-stepping.c",
        "lib/guilds/scion/paths/sword/forms/evade.c");
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
    addResearchElement("lib/guilds/scion/paths/sword/forms/doubling.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/reverse-thrust.c");

    addChild("lib/guilds/scion/paths/sword/forms/doubling.c",
        "lib/guilds/scion/paths/sword/forms/hew.c");
    addChild("lib/guilds/scion/paths/sword/forms/reverse-thrust.c",
        "lib/guilds/scion/paths/sword/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/abschneiden.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/displacement.c");

    addChild("lib/guilds/scion/paths/sword/forms/abschneiden.c",
        "lib/guilds/scion/paths/sword/forms/hew.c");
    addChild("lib/guilds/scion/paths/sword/forms/displacement.c",
        "lib/guilds/scion/paths/sword/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/crooked-hew.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/dance-of-death.c");

    addChild("lib/guilds/scion/paths/sword/forms/crooked-hew.c",
        "lib/guilds/scion/paths/sword/forms/middle-hew.c");
    addChild("lib/guilds/scion/paths/sword/forms/dance-of-death.c",
        "lib/guilds/scion/paths/sword/forms/side-stepping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/mutating-attack.c");

    addChild("lib/guilds/scion/paths/sword/forms/mutating-attack.c",
        "lib/guilds/scion/paths/sword/forms/doubling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/wrath-hew.c");

    addChild("lib/guilds/scion/paths/sword/forms/wrath-hew.c",
        "lib/guilds/scion/paths/sword/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/nachreisen.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/over-running.c");

    addChild("lib/guilds/scion/paths/sword/forms/nachreisen.c",
        "lib/guilds/scion/paths/sword/forms/thrusting.c");
    addChild("lib/guilds/scion/paths/sword/forms/over-running.c",
        "lib/guilds/scion/paths/sword/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/off-setting.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/thwart-hew.c");

    addChild("lib/guilds/scion/paths/sword/forms/off-setting.c",
        "lib/guilds/scion/paths/sword/forms/dance-of-death.c");
    addChild("lib/guilds/scion/paths/sword/forms/thwart-hew.c",
        "lib/guilds/scion/paths/sword/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/changing-through.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/running-through.c");

    addChild("lib/guilds/scion/paths/sword/forms/changing-through.c",
        "lib/guilds/scion/paths/sword/forms/dance-of-death.c");
    addChild("lib/guilds/scion/paths/sword/forms/running-through.c",
        "lib/guilds/scion/paths/sword/forms/dance-of-death.c");
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
private void TwentyFifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/zucken.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/winding.c");

    addChild("lib/guilds/scion/paths/sword/forms/zucken.c",
        "lib/guilds/scion/paths/sword/forms/changing-through.c");
    addChild("lib/guilds/scion/paths/sword/forms/winding.c",
        "lib/guilds/scion/paths/sword/forms/off-setting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/mordstreich.c");

    addChild("lib/guilds/scion/paths/sword/forms/mordstreich.c",
        "lib/guilds/scion/paths/sword/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/advanced-changing.c");

    addChild("lib/guilds/scion/paths/sword/forms/advanced-changing.c",
        "lib/guilds/scion/paths/sword/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/pressing-of-hands.c");

    addChild("lib/guilds/scion/paths/sword/forms/pressing-of-hands.c",
        "lib/guilds/scion/paths/sword/forms/changing-through.c");
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
        ThirdLevel();
        FourthLevel();
        FifthLevel();
        SixthLevel();
        SeventhLevel();
        EighthLevel();
        NinthLevel();
        TenthLevel();
        TwelfthLevel();
        ThirteenLevel();
        FourteenLevel();
        FifteenthLevel();
        SixteenthLevel();
        SeventeenthLevel();
        NineteenthLevel();
        TwentiethLevel();
        TwentyThirdLevel();
        TwentyFifthLevel();
        TwentySeventhLevel();
        TwentyNinthLevel();
        ThirtiethLevel();
    }
}
