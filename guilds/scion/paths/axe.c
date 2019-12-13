//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/cleaving.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/striking.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/from-the-roof.c");

    addChild("lib/guilds/scion/paths/axe/forms/cleaving.c",
        "lib/guilds/scion/paths/axe/root.c");
    addChild("lib/guilds/scion/paths/axe/forms/striking.c",
        "lib/guilds/scion/paths/axe/root.c");
    addChild("lib/guilds/scion/paths/axe/forms/from-the-roof.c",
        "lib/guilds/scion/paths/axe/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/the-ox.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/the-stag.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/the-unicorn.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/wechsel.c");

    addChild("lib/guilds/scion/paths/axe/forms/the-ox.c",
        "lib/guilds/scion/paths/axe/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/axe/forms/the-stag.c",
        "lib/guilds/scion/paths/axe/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/axe/forms/the-unicorn.c",
        "lib/guilds/scion/paths/axe/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/axe/forms/wechsel.c",
        "lib/guilds/scion/paths/axe/forms/from-the-roof.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/evade.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/over-chop.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/undercut.c");

    addChild("lib/guilds/scion/paths/axe/forms/evade.c",
        "lib/guilds/scion/paths/axe/root.c");
    addChild("lib/guilds/scion/paths/axe/forms/over-chop.c",
        "lib/guilds/scion/paths/axe/root.c");
    addChild("lib/guilds/scion/paths/axe/forms/undercut.c",
        "lib/guilds/scion/paths/axe/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/the-plough.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/the-crown.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/near-guard.c");

    addChild("lib/guilds/scion/paths/axe/forms/the-plough.c",
        "lib/guilds/scion/paths/axe/forms/the-ox.c");
    addChild("lib/guilds/scion/paths/axe/forms/the-crown.c",
        "lib/guilds/scion/paths/axe/forms/the-ox.c");
    addChild("lib/guilds/scion/paths/axe/forms/near-guard.c",
        "lib/guilds/scion/paths/axe/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/barrier-guard.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/wrath-guard.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/hanging-blade.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/hew.c");

    addChild("lib/guilds/scion/paths/axe/forms/barrier-guard.c",
        "lib/guilds/scion/paths/axe/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/axe/forms/wrath-guard.c",
        "lib/guilds/scion/paths/axe/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/axe/forms/hanging-blade.c",
        "lib/guilds/scion/paths/axe/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/axe/forms/hew.c",
        "lib/guilds/scion/paths/axe/forms/cleaving.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/the-fool.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/eisenport.c");

    addChild("lib/guilds/scion/paths/axe/forms/the-fool.c",
        "lib/guilds/scion/paths/axe/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/axe/forms/eisenport.c",
        "lib/guilds/scion/paths/axe/forms/the-plough.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/side-stepping.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/porta-di-ferro-alta.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/porta-di-ferro-e-stretta.c");

    addChild("lib/guilds/scion/paths/axe/forms/side-stepping.c",
        "lib/guilds/scion/paths/axe/forms/evade.c");
    addChild("lib/guilds/scion/paths/axe/forms/porta-di-ferro-alta.c",
        "lib/guilds/scion/paths/axe/forms/eisenport.c");
    addChild("lib/guilds/scion/paths/axe/forms/porta-di-ferro-e-stretta.c",
        "lib/guilds/scion/paths/axe/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/hanging-parry.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/langort.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/the-boar.c");

    addChild("lib/guilds/scion/paths/axe/forms/hanging-parry.c",
        "lib/guilds/scion/paths/axe/forms/the-fool.c");
    addChild("lib/guilds/scion/paths/axe/forms/langort.c",
        "lib/guilds/scion/paths/axe/forms/the-fool.c");
    addChild("lib/guilds/scion/paths/axe/forms/the-boar.c",
        "lib/guilds/scion/paths/axe/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/over-hew.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/middle-hew.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/under-hew.c");

    addChild("lib/guilds/scion/paths/axe/forms/over-hew.c",
        "lib/guilds/scion/paths/axe/forms/hew.c");
    addChild("lib/guilds/scion/paths/axe/forms/middle-hew.c",
        "lib/guilds/scion/paths/axe/forms/hew.c");
    addChild("lib/guilds/scion/paths/axe/forms/under-hew.c",
        "lib/guilds/scion/paths/axe/forms/hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/doubling.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/reverse-strike.c");

    addChild("lib/guilds/scion/paths/axe/forms/doubling.c",
        "lib/guilds/scion/paths/axe/forms/hew.c");
    addChild("lib/guilds/scion/paths/axe/forms/reverse-strike.c",
        "lib/guilds/scion/paths/axe/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/abschneiden.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/displacement.c");

    addChild("lib/guilds/scion/paths/axe/forms/abschneiden.c",
        "lib/guilds/scion/paths/axe/forms/hew.c");
    addChild("lib/guilds/scion/paths/axe/forms/displacement.c",
        "lib/guilds/scion/paths/axe/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/crooked-hew.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/dance-of-death.c");

    addChild("lib/guilds/scion/paths/axe/forms/crooked-hew.c",
        "lib/guilds/scion/paths/axe/forms/middle-hew.c");
    addChild("lib/guilds/scion/paths/axe/forms/dance-of-death.c",
        "lib/guilds/scion/paths/axe/forms/side-stepping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/mutating-attack.c");

    addChild("lib/guilds/scion/paths/axe/forms/mutating-attack.c",
        "lib/guilds/scion/paths/axe/forms/doubling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/wrath-hew.c");

    addChild("lib/guilds/scion/paths/axe/forms/wrath-hew.c",
        "lib/guilds/scion/paths/axe/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/nachreisen.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/over-running.c");

    addChild("lib/guilds/scion/paths/axe/forms/nachreisen.c",
        "lib/guilds/scion/paths/axe/forms/striking.c");
    addChild("lib/guilds/scion/paths/axe/forms/over-running.c",
        "lib/guilds/scion/paths/axe/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/off-setting.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/thwart-hew.c");

    addChild("lib/guilds/scion/paths/axe/forms/off-setting.c",
        "lib/guilds/scion/paths/axe/forms/dance-of-death.c");
    addChild("lib/guilds/scion/paths/axe/forms/thwart-hew.c",
        "lib/guilds/scion/paths/axe/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/changing-through.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/running-through.c");

    addChild("lib/guilds/scion/paths/axe/forms/changing-through.c",
        "lib/guilds/scion/paths/axe/forms/dance-of-death.c");
    addChild("lib/guilds/scion/paths/axe/forms/running-through.c",
        "lib/guilds/scion/paths/axe/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/squinting-hew.c");

    addChild("lib/guilds/scion/paths/axe/forms/squinting-hew.c",
        "lib/guilds/scion/paths/axe/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/part-hew.c");

    addChild("lib/guilds/scion/paths/axe/forms/part-hew.c",
        "lib/guilds/scion/paths/axe/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/zucken.c");
    addResearchElement("lib/guilds/scion/paths/axe/forms/winding.c");

    addChild("lib/guilds/scion/paths/axe/forms/zucken.c",
        "lib/guilds/scion/paths/axe/forms/changing-through.c");
    addChild("lib/guilds/scion/paths/axe/forms/winding.c",
        "lib/guilds/scion/paths/axe/forms/off-setting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/mordstreich.c");

    addChild("lib/guilds/scion/paths/axe/forms/mordstreich.c",
        "lib/guilds/scion/paths/axe/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/advanced-changing.c");

    addChild("lib/guilds/scion/paths/axe/forms/advanced-changing.c",
        "lib/guilds/scion/paths/axe/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("lib/guilds/scion/paths/axe/forms/pressing-of-hands.c");

    addChild("lib/guilds/scion/paths/axe/forms/pressing-of-hands.c",
        "lib/guilds/scion/paths/axe/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("The Way of the Axe");
        Description("");
        Source("Scion of Dhuras Guild");
        addResearchElement("lib/guilds/scion/paths/axe/root.c");

        TreeRoot("lib/guilds/scion/paths/axe/root.c");

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
