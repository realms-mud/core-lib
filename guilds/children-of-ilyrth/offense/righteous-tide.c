//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/waters-rebuke.c");

    addChild("/guilds/children-of-ilyrth/offense/waters-rebuke.c",
        "/guilds/children-of-ilyrth/offense/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/crashing-wave.c");
    addResearchElement("/guilds/children-of-ilyrth/offense/righteous-strike.c");

    addChild("/guilds/children-of-ilyrth/offense/crashing-wave.c",
        "/guilds/children-of-ilyrth/offense/waters-rebuke.c");
    addChild("/guilds/children-of-ilyrth/offense/righteous-strike.c",
        "/guilds/children-of-ilyrth/offense/waters-rebuke.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/tidal-surge.c");
    addResearchElement("/guilds/children-of-ilyrth/offense/holy-deluge.c");

    addChild("/guilds/children-of-ilyrth/offense/tidal-surge.c",
        "/guilds/children-of-ilyrth/offense/crashing-wave.c");
    addChild("/guilds/children-of-ilyrth/offense/holy-deluge.c",
        "/guilds/children-of-ilyrth/offense/righteous-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/drowning-grasp.c");
    addResearchElement("/guilds/children-of-ilyrth/offense/divine-torrent.c");

    addChild("/guilds/children-of-ilyrth/offense/drowning-grasp.c",
        "/guilds/children-of-ilyrth/offense/tidal-surge.c");
    addChild("/guilds/children-of-ilyrth/offense/divine-torrent.c",
        "/guilds/children-of-ilyrth/offense/holy-deluge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/riptide.c");

    addChild("/guilds/children-of-ilyrth/offense/riptide.c",
        "/guilds/children-of-ilyrth/offense/drowning-grasp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/ocean-fury.c");
    addResearchElement("/guilds/children-of-ilyrth/offense/sacred-flood.c");

    addChild("/guilds/children-of-ilyrth/offense/ocean-fury.c",
        "/guilds/children-of-ilyrth/offense/riptide.c");
    addChild("/guilds/children-of-ilyrth/offense/sacred-flood.c",
        "/guilds/children-of-ilyrth/offense/divine-torrent.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/wrath-of-the-deep.c");

    addChild("/guilds/children-of-ilyrth/offense/wrath-of-the-deep.c",
        "/guilds/children-of-ilyrth/offense/ocean-fury.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/crushing-depths.c");
    addResearchElement("/guilds/children-of-ilyrth/offense/ilryths-judgment.c");

    addChild("/guilds/children-of-ilyrth/offense/crushing-depths.c",
        "/guilds/children-of-ilyrth/offense/wrath-of-the-deep.c");
    addChild("/guilds/children-of-ilyrth/offense/ilryths-judgment.c",
        "/guilds/children-of-ilyrth/offense/sacred-flood.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/churning-vortex.c");
    addResearchElement("/guilds/children-of-ilyrth/offense/divine-retribution.c");

    addChild("/guilds/children-of-ilyrth/offense/churning-vortex.c",
        "/guilds/children-of-ilyrth/offense/crushing-depths.c");
    addChild("/guilds/children-of-ilyrth/offense/divine-retribution.c",
        "/guilds/children-of-ilyrth/offense/ilryths-judgment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/abyssal-pressure.c");

    addChild("/guilds/children-of-ilyrth/offense/abyssal-pressure.c",
        "/guilds/children-of-ilyrth/offense/churning-vortex.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/ilryths-tide.c");
    addResearchElement("/guilds/children-of-ilyrth/offense/righteous-tempest.c");

    addChild("/guilds/children-of-ilyrth/offense/ilryths-tide.c",
        "/guilds/children-of-ilyrth/offense/abyssal-pressure.c");
    addChild("/guilds/children-of-ilyrth/offense/righteous-tempest.c",
        "/guilds/children-of-ilyrth/offense/divine-retribution.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/oceans-wrath.c");

    addChild("/guilds/children-of-ilyrth/offense/oceans-wrath.c",
        "/guilds/children-of-ilyrth/offense/ilryths-tide.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/divine-inundation.c");
    addResearchElement("/guilds/children-of-ilyrth/offense/primordial-flood.c");

    addChild("/guilds/children-of-ilyrth/offense/divine-inundation.c",
        "/guilds/children-of-ilyrth/offense/righteous-tempest.c");
    addChild("/guilds/children-of-ilyrth/offense/primordial-flood.c",
        "/guilds/children-of-ilyrth/offense/oceans-wrath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/wrath-of-ilyrth.c");

    addChild("/guilds/children-of-ilyrth/offense/wrath-of-ilyrth.c",
        "/guilds/children-of-ilyrth/offense/divine-inundation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/cataclysmic-deluge.c");

    addChild("/guilds/children-of-ilyrth/offense/cataclysmic-deluge.c",
        "/guilds/children-of-ilyrth/offense/primordial-flood.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/apocalyptic-tide.c");

    addChild("/guilds/children-of-ilyrth/offense/apocalyptic-tide.c",
        "/guilds/children-of-ilyrth/offense/wrath-of-ilyrth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/divine-annihilation.c");

    addChild("/guilds/children-of-ilyrth/offense/divine-annihilation.c",
        "/guilds/children-of-ilyrth/offense/cataclysmic-deluge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/offense/ilryths-final-judgment.c");

    addChild("/guilds/children-of-ilyrth/offense/ilryths-final-judgment.c",
        "/guilds/children-of-ilyrth/offense/apocalyptic-tide.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of the Righteous Tide");
    Description("This research tree provides knowledge of offensive magic "
        "channeled through the divine power of Ilyrth, goddess of the sea. "
        "Though Ilyrth teaches mercy and healing, she also teaches that "
        "doing good sometimes requires action against evil. Her followers "
        "learn to wield the crushing power of the ocean and divine wrath "
        "against those who threaten the innocent.");
    Source("Children of Ilyrth");
    addResearchElement("/guilds/children-of-ilyrth/offense/root.c");
    TreeRoot("/guilds/children-of-ilyrth/offense/root.c");

    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
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
