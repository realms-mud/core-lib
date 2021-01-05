//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/mauling.c");
    addResearchElement("guilds/scion/paths/staff/forms/striking.c");
    addResearchElement("guilds/scion/paths/staff/forms/from-the-roof.c");

    addChild("guilds/scion/paths/staff/forms/mauling.c",
        "guilds/scion/paths/staff/root.c");
    addChild("guilds/scion/paths/staff/forms/striking.c",
        "guilds/scion/paths/staff/root.c");
    addChild("guilds/scion/paths/staff/forms/from-the-roof.c",
        "guilds/scion/paths/staff/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/the-ox.c");
    addResearchElement("guilds/scion/paths/staff/forms/the-stag.c");
    addResearchElement("guilds/scion/paths/staff/forms/the-unicorn.c");
    addResearchElement("guilds/scion/paths/staff/forms/wechsel.c");

    addChild("guilds/scion/paths/staff/forms/the-ox.c",
        "guilds/scion/paths/staff/forms/from-the-roof.c");
    addChild("guilds/scion/paths/staff/forms/the-stag.c",
        "guilds/scion/paths/staff/forms/from-the-roof.c");
    addChild("guilds/scion/paths/staff/forms/the-unicorn.c",
        "guilds/scion/paths/staff/forms/from-the-roof.c");
    addChild("guilds/scion/paths/staff/forms/wechsel.c",
        "guilds/scion/paths/staff/forms/from-the-roof.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/evade.c");
    addResearchElement("guilds/scion/paths/staff/forms/over-bash.c");
    addResearchElement("guilds/scion/paths/staff/forms/undercut.c");

    addChild("guilds/scion/paths/staff/forms/evade.c",
        "guilds/scion/paths/staff/root.c");
    addChild("guilds/scion/paths/staff/forms/over-bash.c",
        "guilds/scion/paths/staff/root.c");
    addChild("guilds/scion/paths/staff/forms/undercut.c",
        "guilds/scion/paths/staff/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/the-plough.c");
    addResearchElement("guilds/scion/paths/staff/forms/the-crown.c");
    addResearchElement("guilds/scion/paths/staff/forms/near-guard.c");

    addChild("guilds/scion/paths/staff/forms/the-plough.c",
        "guilds/scion/paths/staff/forms/the-ox.c");
    addChild("guilds/scion/paths/staff/forms/the-crown.c",
        "guilds/scion/paths/staff/forms/the-ox.c");
    addChild("guilds/scion/paths/staff/forms/near-guard.c",
        "guilds/scion/paths/staff/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/barrier-guard.c");
    addResearchElement("guilds/scion/paths/staff/forms/wrath-guard.c");
    addResearchElement("guilds/scion/paths/staff/forms/hanging-fist.c");
    addResearchElement("guilds/scion/paths/staff/forms/smite.c");

    addChild("guilds/scion/paths/staff/forms/barrier-guard.c",
        "guilds/scion/paths/staff/forms/the-plough.c");
    addChild("guilds/scion/paths/staff/forms/wrath-guard.c",
        "guilds/scion/paths/staff/forms/the-plough.c");
    addChild("guilds/scion/paths/staff/forms/hanging-fist.c",
        "guilds/scion/paths/staff/forms/the-plough.c");
    addChild("guilds/scion/paths/staff/forms/smite.c",
        "guilds/scion/paths/staff/forms/mauling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/the-fool.c");
    addResearchElement("guilds/scion/paths/staff/forms/eisenport.c");

    addChild("guilds/scion/paths/staff/forms/the-fool.c",
        "guilds/scion/paths/staff/forms/the-plough.c");
    addChild("guilds/scion/paths/staff/forms/eisenport.c",
        "guilds/scion/paths/staff/forms/the-plough.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/side-stepping.c");
    addResearchElement("guilds/scion/paths/staff/forms/porta-di-ferro-alta.c");
    addResearchElement("guilds/scion/paths/staff/forms/porta-di-ferro-e-stretta.c");

    addChild("guilds/scion/paths/staff/forms/side-stepping.c",
        "guilds/scion/paths/staff/forms/evade.c");
    addChild("guilds/scion/paths/staff/forms/porta-di-ferro-alta.c",
        "guilds/scion/paths/staff/forms/eisenport.c");
    addChild("guilds/scion/paths/staff/forms/porta-di-ferro-e-stretta.c",
        "guilds/scion/paths/staff/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/hanging-parry.c");
    addResearchElement("guilds/scion/paths/staff/forms/langort.c");
    addResearchElement("guilds/scion/paths/staff/forms/the-boar.c");

    addChild("guilds/scion/paths/staff/forms/hanging-parry.c",
        "guilds/scion/paths/staff/forms/the-fool.c");
    addChild("guilds/scion/paths/staff/forms/langort.c",
        "guilds/scion/paths/staff/forms/the-fool.c");
    addChild("guilds/scion/paths/staff/forms/the-boar.c",
        "guilds/scion/paths/staff/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/over-smite.c");
    addResearchElement("guilds/scion/paths/staff/forms/middle-smite.c");
    addResearchElement("guilds/scion/paths/staff/forms/under-smite.c");

    addChild("guilds/scion/paths/staff/forms/over-smite.c",
        "guilds/scion/paths/staff/forms/smite.c");
    addChild("guilds/scion/paths/staff/forms/middle-smite.c",
        "guilds/scion/paths/staff/forms/smite.c");
    addChild("guilds/scion/paths/staff/forms/under-smite.c",
        "guilds/scion/paths/staff/forms/smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/doubling.c");
    addResearchElement("guilds/scion/paths/staff/forms/reverse-strike.c");

    addChild("guilds/scion/paths/staff/forms/doubling.c",
        "guilds/scion/paths/staff/forms/smite.c");
    addChild("guilds/scion/paths/staff/forms/reverse-strike.c",
        "guilds/scion/paths/staff/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/zerschlagen.c");
    addResearchElement("guilds/scion/paths/staff/forms/displacement.c");

    addChild("guilds/scion/paths/staff/forms/zerschlagen.c",
        "guilds/scion/paths/staff/forms/smite.c");
    addChild("guilds/scion/paths/staff/forms/displacement.c",
        "guilds/scion/paths/staff/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/crooked-smite.c");
    addResearchElement("guilds/scion/paths/staff/forms/dance-of-death.c");

    addChild("guilds/scion/paths/staff/forms/crooked-smite.c",
        "guilds/scion/paths/staff/forms/middle-smite.c");
    addChild("guilds/scion/paths/staff/forms/dance-of-death.c",
        "guilds/scion/paths/staff/forms/side-stepping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/mutating-attack.c");

    addChild("guilds/scion/paths/staff/forms/mutating-attack.c",
        "guilds/scion/paths/staff/forms/doubling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/wrath-smite.c");

    addChild("guilds/scion/paths/staff/forms/wrath-smite.c",
        "guilds/scion/paths/staff/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/nachreisen.c");
    addResearchElement("guilds/scion/paths/staff/forms/over-running.c");

    addChild("guilds/scion/paths/staff/forms/nachreisen.c",
        "guilds/scion/paths/staff/forms/striking.c");
    addChild("guilds/scion/paths/staff/forms/over-running.c",
        "guilds/scion/paths/staff/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/off-setting.c");
    addResearchElement("guilds/scion/paths/staff/forms/thwart-smite.c");

    addChild("guilds/scion/paths/staff/forms/off-setting.c",
        "guilds/scion/paths/staff/forms/dance-of-death.c");
    addChild("guilds/scion/paths/staff/forms/thwart-smite.c",
        "guilds/scion/paths/staff/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/changing-through.c");
    addResearchElement("guilds/scion/paths/staff/forms/running-through.c");

    addChild("guilds/scion/paths/staff/forms/changing-through.c",
        "guilds/scion/paths/staff/forms/dance-of-death.c");
    addChild("guilds/scion/paths/staff/forms/running-through.c",
        "guilds/scion/paths/staff/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/squinting-smite.c");

    addChild("guilds/scion/paths/staff/forms/squinting-smite.c",
        "guilds/scion/paths/staff/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/part-smite.c");

    addChild("guilds/scion/paths/staff/forms/part-smite.c",
        "guilds/scion/paths/staff/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/zucken.c");
    addResearchElement("guilds/scion/paths/staff/forms/winding.c");

    addChild("guilds/scion/paths/staff/forms/zucken.c",
        "guilds/scion/paths/staff/forms/changing-through.c");
    addChild("guilds/scion/paths/staff/forms/winding.c",
        "guilds/scion/paths/staff/forms/off-setting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/mordstreich.c");

    addChild("guilds/scion/paths/staff/forms/mordstreich.c",
        "guilds/scion/paths/staff/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/advanced-changing.c");

    addChild("guilds/scion/paths/staff/forms/advanced-changing.c",
        "guilds/scion/paths/staff/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("guilds/scion/paths/staff/forms/pressing-of-hands.c");

    addChild("guilds/scion/paths/staff/forms/pressing-of-hands.c",
        "guilds/scion/paths/staff/forms/changing-through.c");
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
        addResearchElement("guilds/scion/paths/staff/root.c");

        TreeRoot("guilds/scion/paths/staff/root.c");

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
        ThirteenthLevel();
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
