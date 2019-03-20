//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/mauling.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/striking.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/from-the-roof.c");

    addChild("lib/guilds/scion/paths/staff/forms/mauling.c",
        "lib/guilds/scion/paths/staff/root.c");
    addChild("lib/guilds/scion/paths/staff/forms/striking.c",
        "lib/guilds/scion/paths/staff/root.c");
    addChild("lib/guilds/scion/paths/staff/forms/from-the-roof.c",
        "lib/guilds/scion/paths/staff/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/the-ox.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/the-stag.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/the-unicorn.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/wechsel.c");

    addChild("lib/guilds/scion/paths/staff/forms/the-ox.c",
        "lib/guilds/scion/paths/staff/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/staff/forms/the-stag.c",
        "lib/guilds/scion/paths/staff/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/staff/forms/the-unicorn.c",
        "lib/guilds/scion/paths/staff/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/staff/forms/wechsel.c",
        "lib/guilds/scion/paths/staff/forms/from-the-roof.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/evade.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/over-bash.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/undercut.c");

    addChild("lib/guilds/scion/paths/staff/forms/evade.c",
        "lib/guilds/scion/paths/staff/root.c");
    addChild("lib/guilds/scion/paths/staff/forms/over-bash.c",
        "lib/guilds/scion/paths/staff/root.c");
    addChild("lib/guilds/scion/paths/staff/forms/undercut.c",
        "lib/guilds/scion/paths/staff/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/the-plough.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/the-crown.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/near-guard.c");

    addChild("lib/guilds/scion/paths/staff/forms/the-plough.c",
        "lib/guilds/scion/paths/staff/forms/the-ox.c");
    addChild("lib/guilds/scion/paths/staff/forms/the-crown.c",
        "lib/guilds/scion/paths/staff/forms/the-ox.c");
    addChild("lib/guilds/scion/paths/staff/forms/near-guard.c",
        "lib/guilds/scion/paths/staff/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/barrier-guard.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/wrath-guard.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/hanging-fist.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/smite.c");

    addChild("lib/guilds/scion/paths/staff/forms/barrier-guard.c",
        "lib/guilds/scion/paths/staff/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/staff/forms/wrath-guard.c",
        "lib/guilds/scion/paths/staff/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/staff/forms/hanging-fist.c",
        "lib/guilds/scion/paths/staff/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/staff/forms/smite.c",
        "lib/guilds/scion/paths/staff/forms/mauling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/the-fool.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/eisenport.c");

    addChild("lib/guilds/scion/paths/staff/forms/the-fool.c",
        "lib/guilds/scion/paths/staff/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/staff/forms/eisenport.c",
        "lib/guilds/scion/paths/staff/forms/the-plough.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/side-stepping.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/porta-di-ferro-alta.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/porta-di-ferro-e-stretta.c");

    addChild("lib/guilds/scion/paths/staff/forms/side-stepping.c",
        "lib/guilds/scion/paths/staff/forms/evade.c");
    addChild("lib/guilds/scion/paths/staff/forms/porta-di-ferro-alta.c",
        "lib/guilds/scion/paths/staff/forms/eisenport.c");
    addChild("lib/guilds/scion/paths/staff/forms/porta-di-ferro-e-stretta.c",
        "lib/guilds/scion/paths/staff/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/hanging-parry.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/langort.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/the-boar.c");

    addChild("lib/guilds/scion/paths/staff/forms/hanging-parry.c",
        "lib/guilds/scion/paths/staff/forms/the-fool.c");
    addChild("lib/guilds/scion/paths/staff/forms/langort.c",
        "lib/guilds/scion/paths/staff/forms/the-fool.c");
    addChild("lib/guilds/scion/paths/staff/forms/the-boar.c",
        "lib/guilds/scion/paths/staff/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/over-smite.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/middle-smite.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/under-smite.c");

    addChild("lib/guilds/scion/paths/staff/forms/over-smite.c",
        "lib/guilds/scion/paths/staff/forms/smite.c");
    addChild("lib/guilds/scion/paths/staff/forms/middle-smite.c",
        "lib/guilds/scion/paths/staff/forms/smite.c");
    addChild("lib/guilds/scion/paths/staff/forms/under-smite.c",
        "lib/guilds/scion/paths/staff/forms/smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/doubling.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/reverse-strike.c");

    addChild("lib/guilds/scion/paths/staff/forms/doubling.c",
        "lib/guilds/scion/paths/staff/forms/smite.c");
    addChild("lib/guilds/scion/paths/staff/forms/reverse-strike.c",
        "lib/guilds/scion/paths/staff/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/zerschlagen.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/displacement.c");

    addChild("lib/guilds/scion/paths/staff/forms/zerschlagen.c",
        "lib/guilds/scion/paths/staff/forms/smite.c");
    addChild("lib/guilds/scion/paths/staff/forms/displacement.c",
        "lib/guilds/scion/paths/staff/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/crooked-smite.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/dance-of-death.c");

    addChild("lib/guilds/scion/paths/staff/forms/crooked-smite.c",
        "lib/guilds/scion/paths/staff/forms/middle-smite.c");
    addChild("lib/guilds/scion/paths/staff/forms/dance-of-death.c",
        "lib/guilds/scion/paths/staff/forms/side-stepping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/mutating-attack.c");

    addChild("lib/guilds/scion/paths/staff/forms/mutating-attack.c",
        "lib/guilds/scion/paths/staff/forms/doubling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/wrath-smite.c");

    addChild("lib/guilds/scion/paths/staff/forms/wrath-smite.c",
        "lib/guilds/scion/paths/staff/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/nachreisen.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/over-running.c");

    addChild("lib/guilds/scion/paths/staff/forms/nachreisen.c",
        "lib/guilds/scion/paths/staff/forms/striking.c");
    addChild("lib/guilds/scion/paths/staff/forms/over-running.c",
        "lib/guilds/scion/paths/staff/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/off-setting.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/thwart-smite.c");

    addChild("lib/guilds/scion/paths/staff/forms/off-setting.c",
        "lib/guilds/scion/paths/staff/forms/dance-of-death.c");
    addChild("lib/guilds/scion/paths/staff/forms/thwart-smite.c",
        "lib/guilds/scion/paths/staff/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/changing-through.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/running-through.c");

    addChild("lib/guilds/scion/paths/staff/forms/changing-through.c",
        "lib/guilds/scion/paths/staff/forms/dance-of-death.c");
    addChild("lib/guilds/scion/paths/staff/forms/running-through.c",
        "lib/guilds/scion/paths/staff/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/squinting-smite.c");

    addChild("lib/guilds/scion/paths/staff/forms/squinting-smite.c",
        "lib/guilds/scion/paths/staff/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/part-smite.c");

    addChild("lib/guilds/scion/paths/staff/forms/part-smite.c",
        "lib/guilds/scion/paths/staff/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/zucken.c");
    addResearchElement("lib/guilds/scion/paths/staff/forms/winding.c");

    addChild("lib/guilds/scion/paths/staff/forms/zucken.c",
        "lib/guilds/scion/paths/staff/forms/changing-through.c");
    addChild("lib/guilds/scion/paths/staff/forms/winding.c",
        "lib/guilds/scion/paths/staff/forms/off-setting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/mordstreich.c");

    addChild("lib/guilds/scion/paths/staff/forms/mordstreich.c",
        "lib/guilds/scion/paths/staff/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/advanced-changing.c");

    addChild("lib/guilds/scion/paths/staff/forms/advanced-changing.c",
        "lib/guilds/scion/paths/staff/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("lib/guilds/scion/paths/staff/forms/pressing-of-hands.c");

    addChild("lib/guilds/scion/paths/staff/forms/pressing-of-hands.c",
        "lib/guilds/scion/paths/staff/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("The Way of the Staff");
        Description("");
        Source("Scion of Dhuras Guild");
        addResearchElement("lib/guilds/scion/paths/staff/root.c");

        TreeRoot("lib/guilds/scion/paths/staff/root.c");

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
