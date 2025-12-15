//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/soothing-touch.c");

    addChild("/guilds/children-of-ilyrth/healing/soothing-touch.c",
        "/guilds/children-of-ilyrth/healing/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/waters-embrace.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/refreshing-mist.c");

    addChild("/guilds/children-of-ilyrth/healing/waters-embrace.c",
        "/guilds/children-of-ilyrth/healing/soothing-touch.c");
    addChild("/guilds/children-of-ilyrth/healing/refreshing-mist.c",
        "/guilds/children-of-ilyrth/healing/soothing-touch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/healing-stream.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/ilryths-gift.c");

    addChild("/guilds/children-of-ilyrth/healing/healing-stream.c",
        "/guilds/children-of-ilyrth/healing/waters-embrace.c");
    addChild("/guilds/children-of-ilyrth/healing/ilryths-gift.c",
        "/guilds/children-of-ilyrth/healing/refreshing-mist.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/mending-waters.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/ocean-balm.c");

    addChild("/guilds/children-of-ilyrth/healing/mending-waters.c",
        "/guilds/children-of-ilyrth/healing/healing-stream.c");
    addChild("/guilds/children-of-ilyrth/healing/ocean-balm.c",
        "/guilds/children-of-ilyrth/healing/healing-stream.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/tidal-renewal.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/healing-rain.c");

    addChild("/guilds/children-of-ilyrth/healing/tidal-renewal.c",
        "/guilds/children-of-ilyrth/healing/mending-waters.c");
    addChild("/guilds/children-of-ilyrth/healing/healing-rain.c",
        "/guilds/children-of-ilyrth/healing/ilryths-gift.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/restorative-torrent.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/lifegiving-waters.c");

    addChild("/guilds/children-of-ilyrth/healing/restorative-torrent.c",
        "/guilds/children-of-ilyrth/healing/tidal-renewal.c");
    addChild("/guilds/children-of-ilyrth/healing/lifegiving-waters.c",
        "/guilds/children-of-ilyrth/healing/ocean-balm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/healing-cascade.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/deep-restoration.c");

    addChild("/guilds/children-of-ilyrth/healing/healing-cascade.c",
        "/guilds/children-of-ilyrth/healing/healing-rain.c");
    addChild("/guilds/children-of-ilyrth/healing/deep-restoration.c",
        "/guilds/children-of-ilyrth/healing/restorative-torrent.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/wellspring-of-life.c");

    addChild("/guilds/children-of-ilyrth/healing/wellspring-of-life.c",
        "/guilds/children-of-ilyrth/healing/lifegiving-waters.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/ocean-surge.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/natures-renewal.c");

    addChild("/guilds/children-of-ilyrth/healing/ocean-surge.c",
        "/guilds/children-of-ilyrth/healing/healing-cascade.c");
    addChild("/guilds/children-of-ilyrth/healing/natures-renewal.c",
        "/guilds/children-of-ilyrth/healing/deep-restoration.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/ilryths-blessing.c");

    addChild("/guilds/children-of-ilyrth/healing/ilryths-blessing.c",
        "/guilds/children-of-ilyrth/healing/wellspring-of-life.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/tidal-mastery.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/seas-bounty.c");

    addChild("/guilds/children-of-ilyrth/healing/tidal-mastery.c",
        "/guilds/children-of-ilyrth/healing/ocean-surge.c");
    addChild("/guilds/children-of-ilyrth/healing/seas-bounty.c",
        "/guilds/children-of-ilyrth/healing/natures-renewal.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/deluge-of-healing.c");

    addChild("/guilds/children-of-ilyrth/healing/deluge-of-healing.c",
        "/guilds/children-of-ilyrth/healing/ilryths-blessing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/divine-waters.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/renewal-mastery.c");

    addChild("/guilds/children-of-ilyrth/healing/divine-waters.c",
        "/guilds/children-of-ilyrth/healing/tidal-mastery.c");
    addChild("/guilds/children-of-ilyrth/healing/renewal-mastery.c",
        "/guilds/children-of-ilyrth/healing/seas-bounty.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/oceans-embrace.c");

    addChild("/guilds/children-of-ilyrth/healing/oceans-embrace.c",
        "/guilds/children-of-ilyrth/healing/deluge-of-healing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/healing-maelstrom.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/divine-restoration.c");

    addChild("/guilds/children-of-ilyrth/healing/healing-maelstrom.c",
        "/guilds/children-of-ilyrth/healing/divine-waters.c");
    addChild("/guilds/children-of-ilyrth/healing/divine-restoration.c",
        "/guilds/children-of-ilyrth/healing/renewal-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/tidal-salvation.c");

    addChild("/guilds/children-of-ilyrth/healing/tidal-salvation.c",
        "/guilds/children-of-ilyrth/healing/oceans-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/avatar-of-restoration.c");
    addResearchElement("/guilds/children-of-ilyrth/healing/seas-eternal-gift.c");

    addChild("/guilds/children-of-ilyrth/healing/avatar-of-restoration.c",
        "/guilds/children-of-ilyrth/healing/healing-maelstrom.c");
    addChild("/guilds/children-of-ilyrth/healing/seas-eternal-gift.c",
        "/guilds/children-of-ilyrth/healing/divine-restoration.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/ilryths-miracle.c");

    addChild("/guilds/children-of-ilyrth/healing/ilryths-miracle.c",
        "/guilds/children-of-ilyrth/healing/tidal-salvation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/oceans-heart.c");

    addChild("/guilds/children-of-ilyrth/healing/oceans-heart.c",
        "/guilds/children-of-ilyrth/healing/avatar-of-restoration.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/tsunami-of-life.c");

    addChild("/guilds/children-of-ilyrth/healing/tsunami-of-life.c",
        "/guilds/children-of-ilyrth/healing/ilryths-miracle.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/divine-tides.c");

    addChild("/guilds/children-of-ilyrth/healing/divine-tides.c",
        "/guilds/children-of-ilyrth/healing/oceans-heart.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/healing/ilryths-embrace.c");

    addChild("/guilds/children-of-ilyrth/healing/ilryths-embrace.c",
        "/guilds/children-of-ilyrth/healing/divine-tides.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Healing Waters");
    Description("This research tree provides knowledge of healing magic "
        "channeled through the divine power of Ilyrth, goddess of the sea. "
        "Her followers learn to mend wounds, restore vitality, and bring "
        "comfort to the suffering through the sacred waters.");
    Source("Children of Ilyrth");
    addResearchElement("/guilds/children-of-ilyrth/healing/root.c");
    TreeRoot("/guilds/children-of-ilyrth/healing/root.c");

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
