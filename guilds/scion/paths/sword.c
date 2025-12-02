//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/stabbing.c");
    addResearchElement("/guilds/scion/paths/sword/forms/thrusting.c");
    addResearchElement("/guilds/scion/paths/sword/forms/from-the-roof.c");

    addChild("/guilds/scion/paths/sword/forms/stabbing.c",
        "/guilds/scion/paths/sword/root.c");
    addChild("/guilds/scion/paths/sword/forms/thrusting.c",
        "/guilds/scion/paths/sword/root.c");
    addChild("/guilds/scion/paths/sword/forms/from-the-roof.c",
        "/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/the-ox.c");
    addResearchElement("/guilds/scion/paths/sword/forms/the-stag.c");
    addResearchElement("/guilds/scion/paths/sword/forms/the-unicorn.c");
    addResearchElement("/guilds/scion/paths/sword/forms/wechsel.c");

    addChild("/guilds/scion/paths/sword/forms/the-ox.c",
        "/guilds/scion/paths/sword/forms/from-the-roof.c");
    addChild("/guilds/scion/paths/sword/forms/the-stag.c",
        "/guilds/scion/paths/sword/forms/from-the-roof.c");
    addChild("/guilds/scion/paths/sword/forms/the-unicorn.c",
        "/guilds/scion/paths/sword/forms/from-the-roof.c");
    addChild("/guilds/scion/paths/sword/forms/wechsel.c",
        "/guilds/scion/paths/sword/forms/from-the-roof.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/evade.c");
    addResearchElement("/guilds/scion/paths/sword/forms/overcut.c");
    addResearchElement("/guilds/scion/paths/sword/forms/undercut.c");

    addChild("/guilds/scion/paths/sword/forms/evade.c",
        "/guilds/scion/paths/sword/root.c");
    addChild("/guilds/scion/paths/sword/forms/overcut.c",
        "/guilds/scion/paths/sword/root.c");
    addChild("/guilds/scion/paths/sword/forms/undercut.c",
        "/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/the-plough.c");
    addResearchElement("/guilds/scion/paths/sword/forms/the-crown.c");
    addResearchElement("/guilds/scion/paths/sword/forms/near-guard.c");

    addChild("/guilds/scion/paths/sword/forms/the-plough.c",
        "/guilds/scion/paths/sword/forms/the-ox.c");
    addChild("/guilds/scion/paths/sword/forms/the-crown.c",
        "/guilds/scion/paths/sword/forms/the-ox.c");
    addChild("/guilds/scion/paths/sword/forms/near-guard.c",
        "/guilds/scion/paths/sword/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/barrier-guard.c");
    addResearchElement("/guilds/scion/paths/sword/forms/wrath-guard.c");
    addResearchElement("/guilds/scion/paths/sword/forms/hanging-point.c");
    addResearchElement("/guilds/scion/paths/sword/forms/hew.c");

    addChild("/guilds/scion/paths/sword/forms/barrier-guard.c",
        "/guilds/scion/paths/sword/forms/the-plough.c");
    addChild("/guilds/scion/paths/sword/forms/wrath-guard.c",
        "/guilds/scion/paths/sword/forms/the-plough.c");
    addChild("/guilds/scion/paths/sword/forms/hanging-point.c",
        "/guilds/scion/paths/sword/forms/the-plough.c");
    addChild("/guilds/scion/paths/sword/forms/hew.c",
        "/guilds/scion/paths/sword/forms/stabbing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/the-fool.c");
    addResearchElement("/guilds/scion/paths/sword/forms/eisenport.c");

    addChild("/guilds/scion/paths/sword/forms/the-fool.c",
        "/guilds/scion/paths/sword/forms/the-plough.c");
    addChild("/guilds/scion/paths/sword/forms/eisenport.c",
        "/guilds/scion/paths/sword/forms/the-plough.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/side-stepping.c");
    addResearchElement("/guilds/scion/paths/sword/forms/porta-di-ferro-alta.c");
    addResearchElement("/guilds/scion/paths/sword/forms/porta-di-ferro-e-stretta.c");

    addChild("/guilds/scion/paths/sword/forms/side-stepping.c",
        "/guilds/scion/paths/sword/forms/evade.c");
    addChild("/guilds/scion/paths/sword/forms/porta-di-ferro-alta.c",
        "/guilds/scion/paths/sword/forms/eisenport.c");
    addChild("/guilds/scion/paths/sword/forms/porta-di-ferro-e-stretta.c",
        "/guilds/scion/paths/sword/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/hanging-parry.c");
    addResearchElement("/guilds/scion/paths/sword/forms/langort.c");
    addResearchElement("/guilds/scion/paths/sword/forms/the-boar.c");

    addChild("/guilds/scion/paths/sword/forms/hanging-parry.c",
        "/guilds/scion/paths/sword/forms/the-fool.c");
    addChild("/guilds/scion/paths/sword/forms/langort.c",
        "/guilds/scion/paths/sword/forms/the-fool.c");
    addChild("/guilds/scion/paths/sword/forms/the-boar.c",
        "/guilds/scion/paths/sword/forms/eisenport.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/over-hew.c");
    addResearchElement("/guilds/scion/paths/sword/forms/middle-hew.c");
    addResearchElement("/guilds/scion/paths/sword/forms/under-hew.c");

    addChild("/guilds/scion/paths/sword/forms/over-hew.c",
        "/guilds/scion/paths/sword/forms/hew.c");
    addChild("/guilds/scion/paths/sword/forms/middle-hew.c",
        "/guilds/scion/paths/sword/forms/hew.c");
    addChild("/guilds/scion/paths/sword/forms/under-hew.c",
        "/guilds/scion/paths/sword/forms/hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/doubling.c");
    addResearchElement("/guilds/scion/paths/sword/forms/reverse-thrust.c");

    addChild("/guilds/scion/paths/sword/forms/doubling.c",
        "/guilds/scion/paths/sword/forms/hew.c");
    addChild("/guilds/scion/paths/sword/forms/reverse-thrust.c",
        "/guilds/scion/paths/sword/forms/the-boar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/abschneiden.c");
    addResearchElement("/guilds/scion/paths/sword/forms/displacement.c");

    addChild("/guilds/scion/paths/sword/forms/abschneiden.c",
        "/guilds/scion/paths/sword/forms/hew.c");
    addChild("/guilds/scion/paths/sword/forms/displacement.c",
        "/guilds/scion/paths/sword/forms/the-ox.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/crooked-hew.c");
    addResearchElement("/guilds/scion/paths/sword/forms/dance-of-death.c");

    addChild("/guilds/scion/paths/sword/forms/crooked-hew.c",
        "/guilds/scion/paths/sword/forms/middle-hew.c");
    addChild("/guilds/scion/paths/sword/forms/dance-of-death.c",
        "/guilds/scion/paths/sword/forms/side-stepping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/mutating-attack.c");

    addChild("/guilds/scion/paths/sword/forms/mutating-attack.c",
        "/guilds/scion/paths/sword/forms/doubling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/wrath-hew.c");

    addChild("/guilds/scion/paths/sword/forms/wrath-hew.c",
        "/guilds/scion/paths/sword/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/nachreisen.c");
    addResearchElement("/guilds/scion/paths/sword/forms/over-running.c");

    addChild("/guilds/scion/paths/sword/forms/nachreisen.c",
        "/guilds/scion/paths/sword/forms/thrusting.c");
    addChild("/guilds/scion/paths/sword/forms/over-running.c",
        "/guilds/scion/paths/sword/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/off-setting.c");
    addResearchElement("/guilds/scion/paths/sword/forms/thwart-hew.c");

    addChild("/guilds/scion/paths/sword/forms/off-setting.c",
        "/guilds/scion/paths/sword/forms/dance-of-death.c");
    addChild("/guilds/scion/paths/sword/forms/thwart-hew.c",
        "/guilds/scion/paths/sword/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/changing-through.c");
    addResearchElement("/guilds/scion/paths/sword/forms/running-through.c");

    addChild("/guilds/scion/paths/sword/forms/changing-through.c",
        "/guilds/scion/paths/sword/forms/dance-of-death.c");
    addChild("/guilds/scion/paths/sword/forms/running-through.c",
        "/guilds/scion/paths/sword/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/squinting-hew.c");

    addChild("/guilds/scion/paths/sword/forms/squinting-hew.c",
        "/guilds/scion/paths/sword/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/part-hew.c");

    addChild("/guilds/scion/paths/sword/forms/part-hew.c",
        "/guilds/scion/paths/sword/forms/over-hew.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/zucken.c");
    addResearchElement("/guilds/scion/paths/sword/forms/winding.c");

    addChild("/guilds/scion/paths/sword/forms/zucken.c",
        "/guilds/scion/paths/sword/forms/changing-through.c");
    addChild("/guilds/scion/paths/sword/forms/winding.c",
        "/guilds/scion/paths/sword/forms/off-setting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/mordstreich.c");

    addChild("/guilds/scion/paths/sword/forms/mordstreich.c",
        "/guilds/scion/paths/sword/forms/dance-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/advanced-changing.c");

    addChild("/guilds/scion/paths/sword/forms/advanced-changing.c",
        "/guilds/scion/paths/sword/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/scion/paths/sword/forms/pressing-of-hands.c");

    addChild("/guilds/scion/paths/sword/forms/pressing-of-hands.c",
        "/guilds/scion/paths/sword/forms/changing-through.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("The Way of the Sword");
    Description("");
    Source("Scion of Dhuras Guild");
    addResearchElement("/guilds/scion/paths/sword/root.c");
    TreeRoot("/guilds/scion/paths/sword/root.c");

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
