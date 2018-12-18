//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/stabbing.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/thrusting.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/from-the-roof.c");

    addChild("lib/guilds/scion/paths/dagger/forms/stabbing.c",
        "lib/guilds/scion/paths/dagger/root.c");
    addChild("lib/guilds/scion/paths/dagger/forms/thrusting.c",
        "lib/guilds/scion/paths/dagger/root.c");
    addChild("lib/guilds/scion/paths/dagger/forms/from-the-roof.c",
        "lib/guilds/scion/paths/dagger/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/the-ox.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/the-stag.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/the-unicorn.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/wechsel.c");

    addChild("lib/guilds/scion/paths/dagger/forms/the-ox.c",
        "lib/guilds/scion/paths/dagger/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/dagger/forms/the-stag.c",
        "lib/guilds/scion/paths/dagger/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/dagger/forms/the-unicorn.c",
        "lib/guilds/scion/paths/dagger/forms/from-the-roof.c");
    addChild("lib/guilds/scion/paths/dagger/forms/wechsel.c",
        "lib/guilds/scion/paths/dagger/forms/from-the-roof.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/evade.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/overcut.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/undercut.c");

    addChild("lib/guilds/scion/paths/dagger/forms/evade.c",
        "lib/guilds/scion/paths/dagger/root.c");
    addChild("lib/guilds/scion/paths/dagger/forms/overcut.c",
        "lib/guilds/scion/paths/dagger/root.c");
    addChild("lib/guilds/scion/paths/dagger/forms/undercut.c",
        "lib/guilds/scion/paths/dagger/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/the-plough.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/the-crown.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/near-guard.c");

    addChild("lib/guilds/scion/paths/dagger/forms/the-plough.c",
        "lib/guilds/scion/paths/dagger/forms/the-ox.c");
    addChild("lib/guilds/scion/paths/dagger/forms/the-crown.c",
        "lib/guilds/scion/paths/dagger/forms/the-ox.c");
    addChild("lib/guilds/scion/paths/dagger/forms/near-guard.c",
        "lib/guilds/scion/paths/dagger/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/barrier-guard.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/wrath-guard.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/hanging-point.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/plunge.c");

    addChild("lib/guilds/scion/paths/dagger/forms/barrier-guard.c",
        "lib/guilds/scion/paths/dagger/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/dagger/forms/wrath-guard.c",
        "lib/guilds/scion/paths/dagger/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/dagger/forms/hanging-point.c",
        "lib/guilds/scion/paths/dagger/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/dagger/forms/plunge.c",
        "lib/guilds/scion/paths/dagger/forms/stabbing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/the-fool.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/eisenport.c");

    addChild("lib/guilds/scion/paths/dagger/forms/the-fool.c",
        "lib/guilds/scion/paths/dagger/forms/the-plough.c");
    addChild("lib/guilds/scion/paths/dagger/forms/eisenport.c",
        "lib/guilds/scion/paths/dagger/forms/the-plough.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/side-stepping.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/porta-di-ferro-alta.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/porta-di-ferro-e-stretta.c");

    addChild("lib/guilds/scion/paths/dagger/forms/side-stepping.c",
        "lib/guilds/scion/paths/dagger/forms/evade.c");
    addChild("lib/guilds/scion/paths/dagger/forms/porta-di-ferro-alta.c",
        "lib/guilds/scion/paths/dagger/forms/eisenport.c");
    addChild("lib/guilds/scion/paths/dagger/forms/porta-di-ferro-e-stretta.c",
        "lib/guilds/scion/paths/dagger/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/hanging-parry.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/langort.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/the-boar.c");

    addChild("lib/guilds/scion/paths/dagger/forms/hanging-parry.c",
        "lib/guilds/scion/paths/dagger/forms/the-fool.c");
    addChild("lib/guilds/scion/paths/dagger/forms/langort.c",
        "lib/guilds/scion/paths/dagger/forms/the-fool.c");
    addChild("lib/guilds/scion/paths/dagger/forms/the-boar.c",
        "lib/guilds/scion/paths/dagger/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/over-strike.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/middle-strike.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/under-strike.c");

    addChild("lib/guilds/scion/paths/dagger/forms/over-strike.c",
        "lib/guilds/scion/paths/dagger/forms/plunge.c");
    addChild("lib/guilds/scion/paths/dagger/forms/middle-strike.c",
        "lib/guilds/scion/paths/dagger/forms/plunge.c");
    addChild("lib/guilds/scion/paths/dagger/forms/under-strike.c",
        "lib/guilds/scion/paths/dagger/forms/plunge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/doubling.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/reverse-thrust.c");

    addChild("lib/guilds/scion/paths/dagger/forms/doubling.c",
        "lib/guilds/scion/paths/dagger/forms/plunge.c");
    addChild("lib/guilds/scion/paths/dagger/forms/reverse-thrust.c",
        "lib/guilds/scion/paths/dagger/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/durchstechen.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/displacement.c");

    addChild("lib/guilds/scion/paths/dagger/forms/durchstechen.c",
        "lib/guilds/scion/paths/dagger/forms/plunge.c");
    addChild("lib/guilds/scion/paths/dagger/forms/displacement.c",
        "lib/guilds/scion/paths/dagger/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/crooked-strike.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/dance-of-death.c");

    addChild("lib/guilds/scion/paths/dagger/forms/crooked-strike.c",
        "lib/guilds/scion/paths/dagger/forms/middle-strike.c");
    addChild("lib/guilds/scion/paths/dagger/forms/dance-of-death.c",
        "lib/guilds/scion/paths/dagger/forms/side-stepping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/mutating-attack.c");

    addChild("lib/guilds/scion/paths/dagger/forms/mutating-attack.c",
        "lib/guilds/scion/paths/dagger/forms/doubling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/wrath-strike.c");

    addChild("lib/guilds/scion/paths/dagger/forms/wrath-strike.c",
        "lib/guilds/scion/paths/dagger/forms/over-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/nachreisen.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/over-running.c");

    addChild("lib/guilds/scion/paths/dagger/forms/nachreisen.c",
        "lib/guilds/scion/paths/dagger/forms/thrusting.c");
    addChild("lib/guilds/scion/paths/dagger/forms/over-running.c",
        "lib/guilds/scion/paths/dagger/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/off-setting.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/thwart-strike.c");

    addChild("lib/guilds/scion/paths/dagger/forms/off-setting.c",
        "lib/guilds/scion/paths/dagger/forms/dance-of-death.c");
    addChild("lib/guilds/scion/paths/dagger/forms/thwart-strike.c",
        "lib/guilds/scion/paths/dagger/forms/over-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/changing-through.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/running-through.c");

    addChild("lib/guilds/scion/paths/dagger/forms/changing-through.c",
        "lib/guilds/scion/paths/dagger/forms/dance-of-death.c");
    addChild("lib/guilds/scion/paths/dagger/forms/running-through.c",
        "lib/guilds/scion/paths/dagger/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/squinting-strike.c");

    addChild("lib/guilds/scion/paths/dagger/forms/squinting-strike.c",
        "lib/guilds/scion/paths/dagger/forms/over-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/part-strike.c");

    addChild("lib/guilds/scion/paths/dagger/forms/part-strike.c",
        "lib/guilds/scion/paths/dagger/forms/over-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/zucken.c");
    addResearchElement("lib/guilds/scion/paths/dagger/forms/winding.c");

    addChild("lib/guilds/scion/paths/dagger/forms/zucken.c",
        "lib/guilds/scion/paths/dagger/forms/changing-through.c");
    addChild("lib/guilds/scion/paths/dagger/forms/winding.c",
        "lib/guilds/scion/paths/dagger/forms/off-setting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/mordstreich.c");

    addChild("lib/guilds/scion/paths/dagger/forms/mordstreich.c",
        "lib/guilds/scion/paths/dagger/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/advanced-changing.c");

    addChild("lib/guilds/scion/paths/dagger/forms/advanced-changing.c",
        "lib/guilds/scion/paths/dagger/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/forms/pressing-of-hands.c");

    addChild("lib/guilds/scion/paths/dagger/forms/pressing-of-hands.c",
        "lib/guilds/scion/paths/dagger/forms/changing-through.c");
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
        addResearchElement("lib/guilds/scion/paths/dagger/root.c");
        TreeRoot("lib/guilds/scion/paths/dagger/root.c");

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
