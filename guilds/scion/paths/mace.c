//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/mauling.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/striking.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/from-the-roof.c");

    addChild("lib/guilds/scion/paths/mace/forms/mauling.c",
        "lib/guilds/scion/paths/mace/root.c");
    addChild("lib/guilds/scion/paths/mace/forms/striking.c",
        "lib/guilds/scion/paths/mace/root.c");
    addChild("lib/guilds/scion/paths/mace/forms/from-the-roof.c",
        "lib/guilds/scion/paths/mace/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/the-ox.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/the-stag.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/the-unicorn.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/wechsel.c");

    addChild("lib/guilds/scion/paths/mace/forms/the-ox.c",
        "lib/guilds/scion/paths/mace/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/mace/forms/the-stag.c",
        "lib/guilds/scion/paths/mace/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/mace/forms/the-unicorn.c",
        "lib/guilds/scion/paths/mace/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/mace/forms/wechsel.c",
        "lib/guilds/scion/paths/mace/forms/from-the-roof.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/evade.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/over-bash.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/undercut.c");

    addChild("lib/guilds/scion/paths/mace/forms/evade.c",
        "lib/guilds/scion/paths/mace/root.c");
    addChild("lib/guilds/scion/paths/mace/forms/over-bash.c",
        "lib/guilds/scion/paths/mace/root.c");
    addChild("lib/guilds/scion/paths/mace/forms/undercut.c",
        "lib/guilds/scion/paths/mace/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/the-plough.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/the-crown.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/near-guard.c");

    addChild("lib/guilds/scion/paths/mace/forms/the-plough.c",
        "lib/guilds/scion/paths/mace/forms/the-ox.c");
    addChild("lib/guilds/scion/paths/mace/forms/the-crown.c",
        "lib/guilds/scion/paths/mace/forms/the-ox.c");
    addChild("lib/guilds/scion/paths/mace/forms/near-guard.c",
        "lib/guilds/scion/paths/mace/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/barrier-guard.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/wrath-guard.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/hanging-fist.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/smite.c");

    addChild("lib/guilds/scion/paths/mace/forms/barrier-guard.c",
        "lib/guilds/scion/paths/mace/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/mace/forms/wrath-guard.c",
        "lib/guilds/scion/paths/mace/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/mace/forms/hanging-fist.c",
        "lib/guilds/scion/paths/mace/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/mace/forms/smite.c",
        "lib/guilds/scion/paths/mace/forms/mauling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/the-fool.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/eisenport.c");

    addChild("lib/guilds/scion/paths/mace/forms/the-fool.c",
        "lib/guilds/scion/paths/mace/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/mace/forms/eisenport.c",
        "lib/guilds/scion/paths/mace/forms/the-plough.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/side-stepping.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/porta-di-ferro-alta.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/porta-di-ferro-e-stretta.c");

    addChild("lib/guilds/scion/paths/mace/forms/side-stepping.c",
        "lib/guilds/scion/paths/mace/forms/evade.c");
    addChild("lib/guilds/scion/paths/mace/forms/porta-di-ferro-alta.c",
        "lib/guilds/scion/paths/mace/forms/eisenport.c");
    addChild("lib/guilds/scion/paths/mace/forms/porta-di-ferro-e-stretta.c",
        "lib/guilds/scion/paths/mace/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/hanging-parry.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/langort.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/the-boar.c");

    addChild("lib/guilds/scion/paths/mace/forms/hanging-parry.c",
        "lib/guilds/scion/paths/mace/forms/the-fool.c");
    addChild("lib/guilds/scion/paths/mace/forms/langort.c",
        "lib/guilds/scion/paths/mace/forms/the-fool.c");
    addChild("lib/guilds/scion/paths/mace/forms/the-boar.c",
        "lib/guilds/scion/paths/mace/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/over-smite.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/middle-smite.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/under-smite.c");

    addChild("lib/guilds/scion/paths/mace/forms/over-smite.c",
        "lib/guilds/scion/paths/mace/forms/smite.c");
    addChild("lib/guilds/scion/paths/mace/forms/middle-smite.c",
        "lib/guilds/scion/paths/mace/forms/smite.c");
    addChild("lib/guilds/scion/paths/mace/forms/under-smite.c",
        "lib/guilds/scion/paths/mace/forms/smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/doubling.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/reverse-strike.c");

    addChild("lib/guilds/scion/paths/mace/forms/doubling.c",
        "lib/guilds/scion/paths/mace/forms/smite.c");
    addChild("lib/guilds/scion/paths/mace/forms/reverse-strike.c",
        "lib/guilds/scion/paths/mace/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/zerschlagen.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/displacement.c");

    addChild("lib/guilds/scion/paths/mace/forms/zerschlagen.c",
        "lib/guilds/scion/paths/mace/forms/smite.c");
    addChild("lib/guilds/scion/paths/mace/forms/displacement.c",
        "lib/guilds/scion/paths/mace/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/crooked-smite.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/dance-of-death.c");

    addChild("lib/guilds/scion/paths/mace/forms/crooked-smite.c",
        "lib/guilds/scion/paths/mace/forms/middle-smite.c");
    addChild("lib/guilds/scion/paths/mace/forms/dance-of-death.c",
        "lib/guilds/scion/paths/mace/forms/side-stepping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/mutating-attack.c");

    addChild("lib/guilds/scion/paths/mace/forms/mutating-attack.c",
        "lib/guilds/scion/paths/mace/forms/doubling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/wrath-smite.c");

    addChild("lib/guilds/scion/paths/mace/forms/wrath-smite.c",
        "lib/guilds/scion/paths/mace/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/nachreisen.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/over-running.c");

    addChild("lib/guilds/scion/paths/mace/forms/nachreisen.c",
        "lib/guilds/scion/paths/mace/forms/striking.c");
    addChild("lib/guilds/scion/paths/mace/forms/over-running.c",
        "lib/guilds/scion/paths/mace/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/off-setting.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/thwart-smite.c");

    addChild("lib/guilds/scion/paths/mace/forms/off-setting.c",
        "lib/guilds/scion/paths/mace/forms/dance-of-death.c");
    addChild("lib/guilds/scion/paths/mace/forms/thwart-smite.c",
        "lib/guilds/scion/paths/mace/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/changing-through.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/running-through.c");

    addChild("lib/guilds/scion/paths/mace/forms/changing-through.c",
        "lib/guilds/scion/paths/mace/forms/dance-of-death.c");
    addChild("lib/guilds/scion/paths/mace/forms/running-through.c",
        "lib/guilds/scion/paths/mace/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/squinting-smite.c");

    addChild("lib/guilds/scion/paths/mace/forms/squinting-smite.c",
        "lib/guilds/scion/paths/mace/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/part-smite.c");

    addChild("lib/guilds/scion/paths/mace/forms/part-smite.c",
        "lib/guilds/scion/paths/mace/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/zucken.c");
    addResearchElement("lib/guilds/scion/paths/mace/forms/winding.c");

    addChild("lib/guilds/scion/paths/mace/forms/zucken.c",
        "lib/guilds/scion/paths/mace/forms/changing-through.c");
    addChild("lib/guilds/scion/paths/mace/forms/winding.c",
        "lib/guilds/scion/paths/mace/forms/off-setting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/mordstreich.c");

    addChild("lib/guilds/scion/paths/mace/forms/mordstreich.c",
        "lib/guilds/scion/paths/mace/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/advanced-changing.c");

    addChild("lib/guilds/scion/paths/mace/forms/advanced-changing.c",
        "lib/guilds/scion/paths/mace/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("lib/guilds/scion/paths/mace/forms/pressing-of-hands.c");

    addChild("lib/guilds/scion/paths/mace/forms/pressing-of-hands.c",
        "lib/guilds/scion/paths/mace/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("The Way of the Mace");
        Description("");
        Source("Scion of Dhuras Guild");
        addResearchElement("lib/guilds/scion/paths/mace/root.c");

        TreeRoot("lib/guilds/scion/paths/mace/root.c");

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
