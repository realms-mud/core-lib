//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/aquatic-shield.c");

    addChild("/guilds/children-of-ilyrth/protection/aquatic-shield.c",
        "/guilds/children-of-ilyrth/protection/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/waters-ward.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/flowing-defense.c");

    addChild("/guilds/children-of-ilyrth/protection/waters-ward.c",
        "/guilds/children-of-ilyrth/protection/aquatic-shield.c");
    addChild("/guilds/children-of-ilyrth/protection/flowing-defense.c",
        "/guilds/children-of-ilyrth/protection/aquatic-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/tidal-barrier.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/ilryths-protection.c");

    addChild("/guilds/children-of-ilyrth/protection/tidal-barrier.c",
        "/guilds/children-of-ilyrth/protection/waters-ward.c");
    addChild("/guilds/children-of-ilyrth/protection/ilryths-protection.c",
        "/guilds/children-of-ilyrth/protection/flowing-defense.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/reef-armor.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/pressure-ward.c");

    addChild("/guilds/children-of-ilyrth/protection/reef-armor.c",
        "/guilds/children-of-ilyrth/protection/tidal-barrier.c");
    addChild("/guilds/children-of-ilyrth/protection/pressure-ward.c",
        "/guilds/children-of-ilyrth/protection/tidal-barrier.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/current-deflection.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/shell-of-the-deep.c");

    addChild("/guilds/children-of-ilyrth/protection/current-deflection.c",
        "/guilds/children-of-ilyrth/protection/reef-armor.c");
    addChild("/guilds/children-of-ilyrth/protection/shell-of-the-deep.c",
        "/guilds/children-of-ilyrth/protection/ilryths-protection.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/wave-wall.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/undertow-resistance.c");

    addChild("/guilds/children-of-ilyrth/protection/wave-wall.c",
        "/guilds/children-of-ilyrth/protection/current-deflection.c");
    addChild("/guilds/children-of-ilyrth/protection/undertow-resistance.c",
        "/guilds/children-of-ilyrth/protection/pressure-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/oceanic-fortitude.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/depths-embrace.c");

    addChild("/guilds/children-of-ilyrth/protection/oceanic-fortitude.c",
        "/guilds/children-of-ilyrth/protection/shell-of-the-deep.c");
    addChild("/guilds/children-of-ilyrth/protection/depths-embrace.c",
        "/guilds/children-of-ilyrth/protection/wave-wall.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/maelstrom-barrier.c");

    addChild("/guilds/children-of-ilyrth/protection/maelstrom-barrier.c",
        "/guilds/children-of-ilyrth/protection/undertow-resistance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/tidal-resilience.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/crushing-depths.c");

    addChild("/guilds/children-of-ilyrth/protection/tidal-resilience.c",
        "/guilds/children-of-ilyrth/protection/oceanic-fortitude.c");
    addChild("/guilds/children-of-ilyrth/protection/crushing-depths.c",
        "/guilds/children-of-ilyrth/protection/depths-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/ilryths-aegis.c");

    addChild("/guilds/children-of-ilyrth/protection/ilryths-aegis.c",
        "/guilds/children-of-ilyrth/protection/maelstrom-barrier.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/abyssal-ward.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/sea-hardened.c");

    addChild("/guilds/children-of-ilyrth/protection/abyssal-ward.c",
        "/guilds/children-of-ilyrth/protection/tidal-resilience.c");
    addChild("/guilds/children-of-ilyrth/protection/sea-hardened.c",
        "/guilds/children-of-ilyrth/protection/crushing-depths.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/sanctuary-of-waves.c");

    addChild("/guilds/children-of-ilyrth/protection/sanctuary-of-waves.c",
        "/guilds/children-of-ilyrth/protection/ilryths-aegis.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/ocean-bastion.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/tidal-fortification.c");

    addChild("/guilds/children-of-ilyrth/protection/ocean-bastion.c",
        "/guilds/children-of-ilyrth/protection/abyssal-ward.c");
    addChild("/guilds/children-of-ilyrth/protection/tidal-fortification.c",
        "/guilds/children-of-ilyrth/protection/sea-hardened.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/divine-bulwark.c");

    addChild("/guilds/children-of-ilyrth/protection/divine-bulwark.c",
        "/guilds/children-of-ilyrth/protection/sanctuary-of-waves.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/trench-armor.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/primordial-ward.c");

    addChild("/guilds/children-of-ilyrth/protection/trench-armor.c",
        "/guilds/children-of-ilyrth/protection/ocean-bastion.c");
    addChild("/guilds/children-of-ilyrth/protection/primordial-ward.c",
        "/guilds/children-of-ilyrth/protection/tidal-fortification.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/tsunami-shield.c");

    addChild("/guilds/children-of-ilyrth/protection/tsunami-shield.c",
        "/guilds/children-of-ilyrth/protection/divine-bulwark.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/leviathan-hide.c");
    addResearchElement("/guilds/children-of-ilyrth/protection/eternal-depths.c");

    addChild("/guilds/children-of-ilyrth/protection/leviathan-hide.c",
        "/guilds/children-of-ilyrth/protection/trench-armor.c");
    addChild("/guilds/children-of-ilyrth/protection/eternal-depths.c",
        "/guilds/children-of-ilyrth/protection/primordial-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/ilryths-sanctuary.c");

    addChild("/guilds/children-of-ilyrth/protection/ilryths-sanctuary.c",
        "/guilds/children-of-ilyrth/protection/tsunami-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/oceanic-immortality.c");

    addChild("/guilds/children-of-ilyrth/protection/oceanic-immortality.c",
        "/guilds/children-of-ilyrth/protection/leviathan-hide.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/avatar-of-protection.c");

    addChild("/guilds/children-of-ilyrth/protection/avatar-of-protection.c",
        "/guilds/children-of-ilyrth/protection/ilryths-sanctuary.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/divine-carapace.c");

    addChild("/guilds/children-of-ilyrth/protection/divine-carapace.c",
        "/guilds/children-of-ilyrth/protection/oceanic-immortality.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/protection/mantle-of-ilyrth.c");

    addChild("/guilds/children-of-ilyrth/protection/mantle-of-ilyrth.c",
        "/guilds/children-of-ilyrth/protection/divine-carapace.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Tidal Protection");
    Description("This research tree provides knowledge of protective magic "
        "channeled through the divine power of Ilyrth, goddess of the sea. "
        "Her followers learn to create barriers of sacred water, armor "
        "themselves with the pressure of the deep, and shield allies from "
        "harm through the goddess's protective embrace.");
    Source("Children of Ilyrth");
    addResearchElement("/guilds/children-of-ilyrth/protection/root.c");
    TreeRoot("/guilds/children-of-ilyrth/protection/root.c");

    FirstLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentyNinthLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    FortyFirstLevel();
    FortyFifthLevel();
    FiftyFirstLevel();
    FiftySeventhLevel();
    SixtyThirdLevel();
    SixtySeventhLevel();
}
