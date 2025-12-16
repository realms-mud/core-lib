//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/gift-of-ilyrth.c");

    addChild("/guilds/children-of-ilyrth/devotion/gift-of-ilyrth.c",
        "/guilds/children-of-ilyrth/devotion/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/impenetrable-waters.c");

    addChild("/guilds/children-of-ilyrth/devotion/impenetrable-waters.c",
        "/guilds/children-of-ilyrth/devotion/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/boon-of-ilyrth.c");
    addResearchElement("/guilds/children-of-ilyrth/devotion/currents-embrace.c");

    addChild("/guilds/children-of-ilyrth/devotion/boon-of-ilyrth.c",
        "/guilds/children-of-ilyrth/devotion/gift-of-ilyrth.c");
    addChild("/guilds/children-of-ilyrth/devotion/currents-embrace.c",
        "/guilds/children-of-ilyrth/devotion/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/waters-screen.c");

    addChild("/guilds/children-of-ilyrth/devotion/waters-screen.c",
        "/guilds/children-of-ilyrth/devotion/impenetrable-waters.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/seas-shroud.c");

    addChild("/guilds/children-of-ilyrth/devotion/seas-shroud.c",
        "/guilds/children-of-ilyrth/devotion/boon-of-ilyrth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/veil-of-the-deep.c");

    addChild("/guilds/children-of-ilyrth/devotion/veil-of-the-deep.c",
        "/guilds/children-of-ilyrth/devotion/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/might-of-ilyrth.c");

    addChild("/guilds/children-of-ilyrth/devotion/might-of-ilyrth.c",
        "/guilds/children-of-ilyrth/devotion/boon-of-ilyrth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/tides-embrace.c");
    addResearchElement("/guilds/children-of-ilyrth/devotion/veil-of-currents.c");

    addChild("/guilds/children-of-ilyrth/devotion/tides-embrace.c",
        "/guilds/children-of-ilyrth/devotion/seas-shroud.c");
    addChild("/guilds/children-of-ilyrth/devotion/veil-of-currents.c",
        "/guilds/children-of-ilyrth/devotion/currents-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/waters-bulwark.c");

    addChild("/guilds/children-of-ilyrth/devotion/waters-bulwark.c",
        "/guilds/children-of-ilyrth/devotion/waters-screen.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/blessing-of-ilyrth.c");

    addChild("/guilds/children-of-ilyrth/devotion/blessing-of-ilyrth.c",
        "/guilds/children-of-ilyrth/devotion/tides-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/shroud-of-the-deep.c");

    addChild("/guilds/children-of-ilyrth/devotion/shroud-of-the-deep.c",
        "/guilds/children-of-ilyrth/devotion/veil-of-the-deep.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/veil-of-the-goddess.c");

    addChild("/guilds/children-of-ilyrth/devotion/veil-of-the-goddess.c",
        "/guilds/children-of-ilyrth/devotion/might-of-ilyrth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/mantle-of-currents.c");

    addChild("/guilds/children-of-ilyrth/devotion/mantle-of-currents.c",
        "/guilds/children-of-ilyrth/devotion/veil-of-currents.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/mantle-of-the-aegis.c");

    addChild("/guilds/children-of-ilyrth/devotion/mantle-of-the-aegis.c",
        "/guilds/children-of-ilyrth/devotion/waters-bulwark.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/mantle-of-the-deep.c");

    addChild("/guilds/children-of-ilyrth/devotion/mantle-of-the-deep.c",
        "/guilds/children-of-ilyrth/devotion/shroud-of-the-deep.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/mantle-of-ilyrth.c");

    addChild("/guilds/children-of-ilyrth/devotion/mantle-of-ilyrth.c",
        "/guilds/children-of-ilyrth/devotion/veil-of-the-goddess.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/bulwark-of-currents.c");

    addChild("/guilds/children-of-ilyrth/devotion/bulwark-of-currents.c",
        "/guilds/children-of-ilyrth/devotion/mantle-of-currents.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/aegis-of-the-abyss.c");

    addChild("/guilds/children-of-ilyrth/devotion/aegis-of-the-abyss.c",
        "/guilds/children-of-ilyrth/devotion/mantle-of-the-aegis.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/bulwark-of-the-deep.c");

    addChild("/guilds/children-of-ilyrth/devotion/bulwark-of-the-deep.c",
        "/guilds/children-of-ilyrth/devotion/mantle-of-the-deep.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/devotion/bulwark-of-ilyrth.c");

    addChild("/guilds/children-of-ilyrth/devotion/bulwark-of-ilyrth.c",
        "/guilds/children-of-ilyrth/devotion/mantle-of-ilyrth.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Depths of Devotion");
    Description("This research tree provides knowledge of protective magic "
        "channeled through the divine power of Ilyrth, goddess of the sea. "
        "Her followers learn to wrap themselves in the protective embrace "
        "of sacred waters, shielding themselves from harm.");
    Source("Children of Ilyrth");
    addResearchElement("/guilds/children-of-ilyrth/devotion/root.c");
    TreeRoot("/guilds/children-of-ilyrth/devotion/root.c");

    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFirstLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FortyNinthLevel();
    FiftyThirdLevel();
    FiftySeventhLevel();
}
