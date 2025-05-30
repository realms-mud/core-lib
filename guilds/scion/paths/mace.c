//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/mauling.c");
    addResearchElement("/guilds/scion/paths/mace/forms/striking.c");
    addResearchElement("/guilds/scion/paths/mace/forms/from-the-roof.c");

    addChild("/guilds/scion/paths/mace/forms/mauling.c",
        "/guilds/scion/paths/mace/root.c");
    addChild("/guilds/scion/paths/mace/forms/striking.c",
        "/guilds/scion/paths/mace/root.c");
    addChild("/guilds/scion/paths/mace/forms/from-the-roof.c",
        "/guilds/scion/paths/mace/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/the-ox.c");
    addResearchElement("/guilds/scion/paths/mace/forms/the-stag.c");
    addResearchElement("/guilds/scion/paths/mace/forms/the-unicorn.c");
    addResearchElement("/guilds/scion/paths/mace/forms/wechsel.c");

    addChild("/guilds/scion/paths/mace/forms/the-ox.c",
        "/guilds/scion/paths/mace/forms/from-the-roof.c");
    addChild("/guilds/scion/paths/mace/forms/the-stag.c",
        "/guilds/scion/paths/mace/forms/from-the-roof.c");
    addChild("/guilds/scion/paths/mace/forms/the-unicorn.c",
        "/guilds/scion/paths/mace/forms/from-the-roof.c");
    addChild("/guilds/scion/paths/mace/forms/wechsel.c",
        "/guilds/scion/paths/mace/forms/from-the-roof.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/evade.c");
    addResearchElement("/guilds/scion/paths/mace/forms/over-bash.c");
    addResearchElement("/guilds/scion/paths/mace/forms/undercut.c");

    addChild("/guilds/scion/paths/mace/forms/evade.c",
        "/guilds/scion/paths/mace/root.c");
    addChild("/guilds/scion/paths/mace/forms/over-bash.c",
        "/guilds/scion/paths/mace/root.c");
    addChild("/guilds/scion/paths/mace/forms/undercut.c",
        "/guilds/scion/paths/mace/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/the-plough.c");
    addResearchElement("/guilds/scion/paths/mace/forms/the-crown.c");
    addResearchElement("/guilds/scion/paths/mace/forms/near-guard.c");

    addChild("/guilds/scion/paths/mace/forms/the-plough.c",
        "/guilds/scion/paths/mace/forms/the-ox.c");
    addChild("/guilds/scion/paths/mace/forms/the-crown.c",
        "/guilds/scion/paths/mace/forms/the-ox.c");
    addChild("/guilds/scion/paths/mace/forms/near-guard.c",
        "/guilds/scion/paths/mace/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/barrier-guard.c");
    addResearchElement("/guilds/scion/paths/mace/forms/wrath-guard.c");
    addResearchElement("/guilds/scion/paths/mace/forms/hanging-fist.c");
    addResearchElement("/guilds/scion/paths/mace/forms/smite.c");

    addChild("/guilds/scion/paths/mace/forms/barrier-guard.c",
        "/guilds/scion/paths/mace/forms/the-plough.c");
    addChild("/guilds/scion/paths/mace/forms/wrath-guard.c",
        "/guilds/scion/paths/mace/forms/the-plough.c");
    addChild("/guilds/scion/paths/mace/forms/hanging-fist.c",
        "/guilds/scion/paths/mace/forms/the-plough.c");
    addChild("/guilds/scion/paths/mace/forms/smite.c",
        "/guilds/scion/paths/mace/forms/mauling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/the-fool.c");
    addResearchElement("/guilds/scion/paths/mace/forms/eisenport.c");

    addChild("/guilds/scion/paths/mace/forms/the-fool.c",
        "/guilds/scion/paths/mace/forms/the-plough.c");
    addChild("/guilds/scion/paths/mace/forms/eisenport.c",
        "/guilds/scion/paths/mace/forms/the-plough.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/side-stepping.c");
    addResearchElement("/guilds/scion/paths/mace/forms/porta-di-ferro-alta.c");
    addResearchElement("/guilds/scion/paths/mace/forms/porta-di-ferro-e-stretta.c");

    addChild("/guilds/scion/paths/mace/forms/side-stepping.c",
        "/guilds/scion/paths/mace/forms/evade.c");
    addChild("/guilds/scion/paths/mace/forms/porta-di-ferro-alta.c",
        "/guilds/scion/paths/mace/forms/eisenport.c");
    addChild("/guilds/scion/paths/mace/forms/porta-di-ferro-e-stretta.c",
        "/guilds/scion/paths/mace/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/hanging-parry.c");
    addResearchElement("/guilds/scion/paths/mace/forms/langort.c");
    addResearchElement("/guilds/scion/paths/mace/forms/the-boar.c");

    addChild("/guilds/scion/paths/mace/forms/hanging-parry.c",
        "/guilds/scion/paths/mace/forms/the-fool.c");
    addChild("/guilds/scion/paths/mace/forms/langort.c",
        "/guilds/scion/paths/mace/forms/the-fool.c");
    addChild("/guilds/scion/paths/mace/forms/the-boar.c",
        "/guilds/scion/paths/mace/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/over-smite.c");
    addResearchElement("/guilds/scion/paths/mace/forms/middle-smite.c");
    addResearchElement("/guilds/scion/paths/mace/forms/under-smite.c");

    addChild("/guilds/scion/paths/mace/forms/over-smite.c",
        "/guilds/scion/paths/mace/forms/smite.c");
    addChild("/guilds/scion/paths/mace/forms/middle-smite.c",
        "/guilds/scion/paths/mace/forms/smite.c");
    addChild("/guilds/scion/paths/mace/forms/under-smite.c",
        "/guilds/scion/paths/mace/forms/smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/doubling.c");
    addResearchElement("/guilds/scion/paths/mace/forms/reverse-strike.c");

    addChild("/guilds/scion/paths/mace/forms/doubling.c",
        "/guilds/scion/paths/mace/forms/smite.c");
    addChild("/guilds/scion/paths/mace/forms/reverse-strike.c",
        "/guilds/scion/paths/mace/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/zerschlagen.c");
    addResearchElement("/guilds/scion/paths/mace/forms/displacement.c");

    addChild("/guilds/scion/paths/mace/forms/zerschlagen.c",
        "/guilds/scion/paths/mace/forms/smite.c");
    addChild("/guilds/scion/paths/mace/forms/displacement.c",
        "/guilds/scion/paths/mace/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/crooked-smite.c");
    addResearchElement("/guilds/scion/paths/mace/forms/dance-of-death.c");

    addChild("/guilds/scion/paths/mace/forms/crooked-smite.c",
        "/guilds/scion/paths/mace/forms/middle-smite.c");
    addChild("/guilds/scion/paths/mace/forms/dance-of-death.c",
        "/guilds/scion/paths/mace/forms/side-stepping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/mutating-attack.c");

    addChild("/guilds/scion/paths/mace/forms/mutating-attack.c",
        "/guilds/scion/paths/mace/forms/doubling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/wrath-smite.c");

    addChild("/guilds/scion/paths/mace/forms/wrath-smite.c",
        "/guilds/scion/paths/mace/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/nachreisen.c");
    addResearchElement("/guilds/scion/paths/mace/forms/over-running.c");

    addChild("/guilds/scion/paths/mace/forms/nachreisen.c",
        "/guilds/scion/paths/mace/forms/striking.c");
    addChild("/guilds/scion/paths/mace/forms/over-running.c",
        "/guilds/scion/paths/mace/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/off-setting.c");
    addResearchElement("/guilds/scion/paths/mace/forms/thwart-smite.c");

    addChild("/guilds/scion/paths/mace/forms/off-setting.c",
        "/guilds/scion/paths/mace/forms/dance-of-death.c");
    addChild("/guilds/scion/paths/mace/forms/thwart-smite.c",
        "/guilds/scion/paths/mace/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/changing-through.c");
    addResearchElement("/guilds/scion/paths/mace/forms/running-through.c");

    addChild("/guilds/scion/paths/mace/forms/changing-through.c",
        "/guilds/scion/paths/mace/forms/dance-of-death.c");
    addChild("/guilds/scion/paths/mace/forms/running-through.c",
        "/guilds/scion/paths/mace/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/squinting-smite.c");

    addChild("/guilds/scion/paths/mace/forms/squinting-smite.c",
        "/guilds/scion/paths/mace/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/part-smite.c");

    addChild("/guilds/scion/paths/mace/forms/part-smite.c",
        "/guilds/scion/paths/mace/forms/over-smite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/zucken.c");
    addResearchElement("/guilds/scion/paths/mace/forms/winding.c");

    addChild("/guilds/scion/paths/mace/forms/zucken.c",
        "/guilds/scion/paths/mace/forms/changing-through.c");
    addChild("/guilds/scion/paths/mace/forms/winding.c",
        "/guilds/scion/paths/mace/forms/off-setting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/mordstreich.c");

    addChild("/guilds/scion/paths/mace/forms/mordstreich.c",
        "/guilds/scion/paths/mace/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/advanced-changing.c");

    addChild("/guilds/scion/paths/mace/forms/advanced-changing.c",
        "/guilds/scion/paths/mace/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/scion/paths/mace/forms/pressing-of-hands.c");

    addChild("/guilds/scion/paths/mace/forms/pressing-of-hands.c",
        "/guilds/scion/paths/mace/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("The Way of the Mace");
    Description("");
    Source("Scion of Dhuras Guild");
    addResearchElement("/guilds/scion/paths/mace/root.c");

    TreeRoot("/guilds/scion/paths/mace/root.c");

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
