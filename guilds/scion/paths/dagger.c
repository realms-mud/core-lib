//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/stabbing.c");
    addResearchElement("guilds/scion/paths/dagger/forms/thrusting.c");
    addResearchElement("guilds/scion/paths/dagger/forms/from-the-roof.c");

    addChild("guilds/scion/paths/dagger/forms/stabbing.c",
        "guilds/scion/paths/dagger/root.c");
    addChild("guilds/scion/paths/dagger/forms/thrusting.c",
        "guilds/scion/paths/dagger/root.c");
    addChild("guilds/scion/paths/dagger/forms/from-the-roof.c",
        "guilds/scion/paths/dagger/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/the-ox.c");
    addResearchElement("guilds/scion/paths/dagger/forms/the-stag.c");
    addResearchElement("guilds/scion/paths/dagger/forms/the-unicorn.c");
    addResearchElement("guilds/scion/paths/dagger/forms/wechsel.c");

    addChild("guilds/scion/paths/dagger/forms/the-ox.c",
        "guilds/scion/paths/dagger/forms/from-the-roof.c");
    addChild("guilds/scion/paths/dagger/forms/the-stag.c",
        "guilds/scion/paths/dagger/forms/from-the-roof.c");
    addChild("guilds/scion/paths/dagger/forms/the-unicorn.c",
        "guilds/scion/paths/dagger/forms/from-the-roof.c");
    addChild("guilds/scion/paths/dagger/forms/wechsel.c",
        "guilds/scion/paths/dagger/forms/from-the-roof.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/evade.c");
    addResearchElement("guilds/scion/paths/dagger/forms/overcut.c");
    addResearchElement("guilds/scion/paths/dagger/forms/undercut.c");

    addChild("guilds/scion/paths/dagger/forms/evade.c",
        "guilds/scion/paths/dagger/root.c");
    addChild("guilds/scion/paths/dagger/forms/overcut.c",
        "guilds/scion/paths/dagger/root.c");
    addChild("guilds/scion/paths/dagger/forms/undercut.c",
        "guilds/scion/paths/dagger/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/the-plough.c");
    addResearchElement("guilds/scion/paths/dagger/forms/the-crown.c");
    addResearchElement("guilds/scion/paths/dagger/forms/near-guard.c");

    addChild("guilds/scion/paths/dagger/forms/the-plough.c",
        "guilds/scion/paths/dagger/forms/the-ox.c");
    addChild("guilds/scion/paths/dagger/forms/the-crown.c",
        "guilds/scion/paths/dagger/forms/the-ox.c");
    addChild("guilds/scion/paths/dagger/forms/near-guard.c",
        "guilds/scion/paths/dagger/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/barrier-guard.c");
    addResearchElement("guilds/scion/paths/dagger/forms/wrath-guard.c");
    addResearchElement("guilds/scion/paths/dagger/forms/hanging-point.c");
    addResearchElement("guilds/scion/paths/dagger/forms/plunge.c");

    addChild("guilds/scion/paths/dagger/forms/barrier-guard.c",
        "guilds/scion/paths/dagger/forms/the-plough.c");
    addChild("guilds/scion/paths/dagger/forms/wrath-guard.c",
        "guilds/scion/paths/dagger/forms/the-plough.c");
    addChild("guilds/scion/paths/dagger/forms/hanging-point.c",
        "guilds/scion/paths/dagger/forms/the-plough.c");
    addChild("guilds/scion/paths/dagger/forms/plunge.c",
        "guilds/scion/paths/dagger/forms/stabbing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/the-fool.c");
    addResearchElement("guilds/scion/paths/dagger/forms/eisenport.c");

    addChild("guilds/scion/paths/dagger/forms/the-fool.c",
        "guilds/scion/paths/dagger/forms/the-plough.c");
    addChild("guilds/scion/paths/dagger/forms/eisenport.c",
        "guilds/scion/paths/dagger/forms/the-plough.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/side-stepping.c");
    addResearchElement("guilds/scion/paths/dagger/forms/porta-di-ferro-alta.c");
    addResearchElement("guilds/scion/paths/dagger/forms/porta-di-ferro-e-stretta.c");

    addChild("guilds/scion/paths/dagger/forms/side-stepping.c",
        "guilds/scion/paths/dagger/forms/evade.c");
    addChild("guilds/scion/paths/dagger/forms/porta-di-ferro-alta.c",
        "guilds/scion/paths/dagger/forms/eisenport.c");
    addChild("guilds/scion/paths/dagger/forms/porta-di-ferro-e-stretta.c",
        "guilds/scion/paths/dagger/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/hanging-parry.c");
    addResearchElement("guilds/scion/paths/dagger/forms/langort.c");
    addResearchElement("guilds/scion/paths/dagger/forms/the-boar.c");

    addChild("guilds/scion/paths/dagger/forms/hanging-parry.c",
        "guilds/scion/paths/dagger/forms/the-fool.c");
    addChild("guilds/scion/paths/dagger/forms/langort.c",
        "guilds/scion/paths/dagger/forms/the-fool.c");
    addChild("guilds/scion/paths/dagger/forms/the-boar.c",
        "guilds/scion/paths/dagger/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/over-strike.c");
    addResearchElement("guilds/scion/paths/dagger/forms/middle-strike.c");
    addResearchElement("guilds/scion/paths/dagger/forms/under-strike.c");

    addChild("guilds/scion/paths/dagger/forms/over-strike.c",
        "guilds/scion/paths/dagger/forms/plunge.c");
    addChild("guilds/scion/paths/dagger/forms/middle-strike.c",
        "guilds/scion/paths/dagger/forms/plunge.c");
    addChild("guilds/scion/paths/dagger/forms/under-strike.c",
        "guilds/scion/paths/dagger/forms/plunge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/doubling.c");
    addResearchElement("guilds/scion/paths/dagger/forms/reverse-thrust.c");

    addChild("guilds/scion/paths/dagger/forms/doubling.c",
        "guilds/scion/paths/dagger/forms/plunge.c");
    addChild("guilds/scion/paths/dagger/forms/reverse-thrust.c",
        "guilds/scion/paths/dagger/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/durchstechen.c");
    addResearchElement("guilds/scion/paths/dagger/forms/displacement.c");

    addChild("guilds/scion/paths/dagger/forms/durchstechen.c",
        "guilds/scion/paths/dagger/forms/plunge.c");
    addChild("guilds/scion/paths/dagger/forms/displacement.c",
        "guilds/scion/paths/dagger/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/crooked-strike.c");
    addResearchElement("guilds/scion/paths/dagger/forms/dance-of-death.c");

    addChild("guilds/scion/paths/dagger/forms/crooked-strike.c",
        "guilds/scion/paths/dagger/forms/middle-strike.c");
    addChild("guilds/scion/paths/dagger/forms/dance-of-death.c",
        "guilds/scion/paths/dagger/forms/side-stepping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/mutating-attack.c");

    addChild("guilds/scion/paths/dagger/forms/mutating-attack.c",
        "guilds/scion/paths/dagger/forms/doubling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/wrath-strike.c");

    addChild("guilds/scion/paths/dagger/forms/wrath-strike.c",
        "guilds/scion/paths/dagger/forms/over-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/nachreisen.c");
    addResearchElement("guilds/scion/paths/dagger/forms/over-running.c");

    addChild("guilds/scion/paths/dagger/forms/nachreisen.c",
        "guilds/scion/paths/dagger/forms/thrusting.c");
    addChild("guilds/scion/paths/dagger/forms/over-running.c",
        "guilds/scion/paths/dagger/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/off-setting.c");
    addResearchElement("guilds/scion/paths/dagger/forms/thwart-strike.c");

    addChild("guilds/scion/paths/dagger/forms/off-setting.c",
        "guilds/scion/paths/dagger/forms/dance-of-death.c");
    addChild("guilds/scion/paths/dagger/forms/thwart-strike.c",
        "guilds/scion/paths/dagger/forms/over-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/changing-through.c");
    addResearchElement("guilds/scion/paths/dagger/forms/running-through.c");

    addChild("guilds/scion/paths/dagger/forms/changing-through.c",
        "guilds/scion/paths/dagger/forms/dance-of-death.c");
    addChild("guilds/scion/paths/dagger/forms/running-through.c",
        "guilds/scion/paths/dagger/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/squinting-strike.c");

    addChild("guilds/scion/paths/dagger/forms/squinting-strike.c",
        "guilds/scion/paths/dagger/forms/over-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/part-strike.c");

    addChild("guilds/scion/paths/dagger/forms/part-strike.c",
        "guilds/scion/paths/dagger/forms/over-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/zucken.c");
    addResearchElement("guilds/scion/paths/dagger/forms/winding.c");

    addChild("guilds/scion/paths/dagger/forms/zucken.c",
        "guilds/scion/paths/dagger/forms/changing-through.c");
    addChild("guilds/scion/paths/dagger/forms/winding.c",
        "guilds/scion/paths/dagger/forms/off-setting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/mordstreich.c");

    addChild("guilds/scion/paths/dagger/forms/mordstreich.c",
        "guilds/scion/paths/dagger/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/advanced-changing.c");

    addChild("guilds/scion/paths/dagger/forms/advanced-changing.c",
        "guilds/scion/paths/dagger/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("guilds/scion/paths/dagger/forms/pressing-of-hands.c");

    addChild("guilds/scion/paths/dagger/forms/pressing-of-hands.c",
        "guilds/scion/paths/dagger/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("The Way of the Dagger");
        Description("");
        Source("Scion of Dhuras Guild");
        addResearchElement("guilds/scion/paths/dagger/root.c");
        TreeRoot("guilds/scion/paths/dagger/root.c");

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
