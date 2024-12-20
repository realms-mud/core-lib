//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/cleaving.c");
    addResearchElement("/guilds/scion/paths/axe/forms/striking.c");
    addResearchElement("/guilds/scion/paths/axe/forms/from-the-roof.c");

    addChild("/guilds/scion/paths/axe/forms/cleaving.c",
        "/guilds/scion/paths/axe/root.c");
    addChild("/guilds/scion/paths/axe/forms/striking.c",
        "/guilds/scion/paths/axe/root.c");
    addChild("/guilds/scion/paths/axe/forms/from-the-roof.c",
        "/guilds/scion/paths/axe/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/the-ox.c");
    addResearchElement("/guilds/scion/paths/axe/forms/the-stag.c");
    addResearchElement("/guilds/scion/paths/axe/forms/the-unicorn.c");
    addResearchElement("/guilds/scion/paths/axe/forms/wechsel.c");

    addChild("/guilds/scion/paths/axe/forms/the-ox.c",
        "/guilds/scion/paths/axe/forms/from-the-roof.c");
    addChild("/guilds/scion/paths/axe/forms/the-stag.c",
        "/guilds/scion/paths/axe/forms/from-the-roof.c");
    addChild("/guilds/scion/paths/axe/forms/the-unicorn.c",
        "/guilds/scion/paths/axe/forms/from-the-roof.c");
    addChild("/guilds/scion/paths/axe/forms/wechsel.c",
        "/guilds/scion/paths/axe/forms/from-the-roof.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/evade.c");
    addResearchElement("/guilds/scion/paths/axe/forms/over-chop.c");
    addResearchElement("/guilds/scion/paths/axe/forms/undercut.c");

    addChild("/guilds/scion/paths/axe/forms/evade.c",
        "/guilds/scion/paths/axe/root.c");
    addChild("/guilds/scion/paths/axe/forms/over-chop.c",
        "/guilds/scion/paths/axe/root.c");
    addChild("/guilds/scion/paths/axe/forms/undercut.c",
        "/guilds/scion/paths/axe/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/the-plough.c");
    addResearchElement("/guilds/scion/paths/axe/forms/the-crown.c");
    addResearchElement("/guilds/scion/paths/axe/forms/near-guard.c");

    addChild("/guilds/scion/paths/axe/forms/the-plough.c",
        "/guilds/scion/paths/axe/forms/the-ox.c");
    addChild("/guilds/scion/paths/axe/forms/the-crown.c",
        "/guilds/scion/paths/axe/forms/the-ox.c");
    addChild("/guilds/scion/paths/axe/forms/near-guard.c",
        "/guilds/scion/paths/axe/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/barrier-guard.c");
    addResearchElement("/guilds/scion/paths/axe/forms/wrath-guard.c");
    addResearchElement("/guilds/scion/paths/axe/forms/hanging-blade.c");
    addResearchElement("/guilds/scion/paths/axe/forms/hew.c");

    addChild("/guilds/scion/paths/axe/forms/barrier-guard.c",
        "/guilds/scion/paths/axe/forms/the-plough.c");
    addChild("/guilds/scion/paths/axe/forms/wrath-guard.c",
        "/guilds/scion/paths/axe/forms/the-plough.c");
    addChild("/guilds/scion/paths/axe/forms/hanging-blade.c",
        "/guilds/scion/paths/axe/forms/the-plough.c");
    addChild("/guilds/scion/paths/axe/forms/hew.c",
        "/guilds/scion/paths/axe/forms/cleaving.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/the-fool.c");
    addResearchElement("/guilds/scion/paths/axe/forms/eisenport.c");

    addChild("/guilds/scion/paths/axe/forms/the-fool.c",
        "/guilds/scion/paths/axe/forms/the-plough.c");
    addChild("/guilds/scion/paths/axe/forms/eisenport.c",
        "/guilds/scion/paths/axe/forms/the-plough.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/side-stepping.c");
    addResearchElement("/guilds/scion/paths/axe/forms/porta-di-ferro-alta.c");
    addResearchElement("/guilds/scion/paths/axe/forms/porta-di-ferro-e-stretta.c");

    addChild("/guilds/scion/paths/axe/forms/side-stepping.c",
        "/guilds/scion/paths/axe/forms/evade.c");
    addChild("/guilds/scion/paths/axe/forms/porta-di-ferro-alta.c",
        "/guilds/scion/paths/axe/forms/eisenport.c");
    addChild("/guilds/scion/paths/axe/forms/porta-di-ferro-e-stretta.c",
        "/guilds/scion/paths/axe/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/hanging-parry.c");
    addResearchElement("/guilds/scion/paths/axe/forms/langort.c");
    addResearchElement("/guilds/scion/paths/axe/forms/the-boar.c");

    addChild("/guilds/scion/paths/axe/forms/hanging-parry.c",
        "/guilds/scion/paths/axe/forms/the-fool.c");
    addChild("/guilds/scion/paths/axe/forms/langort.c",
        "/guilds/scion/paths/axe/forms/the-fool.c");
    addChild("/guilds/scion/paths/axe/forms/the-boar.c",
        "/guilds/scion/paths/axe/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/over-hew.c");
    addResearchElement("/guilds/scion/paths/axe/forms/middle-hew.c");
    addResearchElement("/guilds/scion/paths/axe/forms/under-hew.c");

    addChild("/guilds/scion/paths/axe/forms/over-hew.c",
        "/guilds/scion/paths/axe/forms/hew.c");
    addChild("/guilds/scion/paths/axe/forms/middle-hew.c",
        "/guilds/scion/paths/axe/forms/hew.c");
    addChild("/guilds/scion/paths/axe/forms/under-hew.c",
        "/guilds/scion/paths/axe/forms/hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/doubling.c");
    addResearchElement("/guilds/scion/paths/axe/forms/reverse-strike.c");

    addChild("/guilds/scion/paths/axe/forms/doubling.c",
        "/guilds/scion/paths/axe/forms/hew.c");
    addChild("/guilds/scion/paths/axe/forms/reverse-strike.c",
        "/guilds/scion/paths/axe/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/abschneiden.c");
    addResearchElement("/guilds/scion/paths/axe/forms/displacement.c");

    addChild("/guilds/scion/paths/axe/forms/abschneiden.c",
        "/guilds/scion/paths/axe/forms/hew.c");
    addChild("/guilds/scion/paths/axe/forms/displacement.c",
        "/guilds/scion/paths/axe/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/crooked-hew.c");
    addResearchElement("/guilds/scion/paths/axe/forms/dance-of-death.c");

    addChild("/guilds/scion/paths/axe/forms/crooked-hew.c",
        "/guilds/scion/paths/axe/forms/middle-hew.c");
    addChild("/guilds/scion/paths/axe/forms/dance-of-death.c",
        "/guilds/scion/paths/axe/forms/side-stepping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/mutating-attack.c");

    addChild("/guilds/scion/paths/axe/forms/mutating-attack.c",
        "/guilds/scion/paths/axe/forms/doubling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/wrath-hew.c");

    addChild("/guilds/scion/paths/axe/forms/wrath-hew.c",
        "/guilds/scion/paths/axe/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/nachreisen.c");
    addResearchElement("/guilds/scion/paths/axe/forms/over-running.c");

    addChild("/guilds/scion/paths/axe/forms/nachreisen.c",
        "/guilds/scion/paths/axe/forms/striking.c");
    addChild("/guilds/scion/paths/axe/forms/over-running.c",
        "/guilds/scion/paths/axe/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/off-setting.c");
    addResearchElement("/guilds/scion/paths/axe/forms/thwart-hew.c");

    addChild("/guilds/scion/paths/axe/forms/off-setting.c",
        "/guilds/scion/paths/axe/forms/dance-of-death.c");
    addChild("/guilds/scion/paths/axe/forms/thwart-hew.c",
        "/guilds/scion/paths/axe/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/changing-through.c");
    addResearchElement("/guilds/scion/paths/axe/forms/running-through.c");

    addChild("/guilds/scion/paths/axe/forms/changing-through.c",
        "/guilds/scion/paths/axe/forms/dance-of-death.c");
    addChild("/guilds/scion/paths/axe/forms/running-through.c",
        "/guilds/scion/paths/axe/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/squinting-hew.c");

    addChild("/guilds/scion/paths/axe/forms/squinting-hew.c",
        "/guilds/scion/paths/axe/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/part-hew.c");

    addChild("/guilds/scion/paths/axe/forms/part-hew.c",
        "/guilds/scion/paths/axe/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/zucken.c");
    addResearchElement("/guilds/scion/paths/axe/forms/winding.c");

    addChild("/guilds/scion/paths/axe/forms/zucken.c",
        "/guilds/scion/paths/axe/forms/changing-through.c");
    addChild("/guilds/scion/paths/axe/forms/winding.c",
        "/guilds/scion/paths/axe/forms/off-setting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/mordstreich.c");

    addChild("/guilds/scion/paths/axe/forms/mordstreich.c",
        "/guilds/scion/paths/axe/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/advanced-changing.c");

    addChild("/guilds/scion/paths/axe/forms/advanced-changing.c",
        "/guilds/scion/paths/axe/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/scion/paths/axe/forms/pressing-of-hands.c");

    addChild("/guilds/scion/paths/axe/forms/pressing-of-hands.c",
        "/guilds/scion/paths/axe/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("The Way of the Axe");
    Description("");
    Source("Scion of Dhuras Guild");
    addResearchElement("/guilds/scion/paths/axe/root.c");

    TreeRoot("/guilds/scion/paths/axe/root.c");

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
