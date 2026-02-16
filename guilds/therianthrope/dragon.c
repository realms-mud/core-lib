//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/draconic-precision.c");
    addResearchElement("/guilds/therianthrope/dragon/silver-scales.c");

    addChild("/guilds/therianthrope/dragon/draconic-precision.c",
        "/guilds/therianthrope/dragon/dragon-root.c");
    addChild("/guilds/therianthrope/dragon/silver-scales.c",
        "/guilds/therianthrope/dragon/dragon-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/frost-claw.c");
    addResearchElement("/guilds/therianthrope/dragon/draconic-resilience.c");

    addChild("/guilds/therianthrope/dragon/frost-claw.c",
        "/guilds/therianthrope/dragon/draconic-precision.c");
    addChild("/guilds/therianthrope/dragon/draconic-resilience.c",
        "/guilds/therianthrope/dragon/silver-scales.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/glacial-fangs.c");
    addResearchElement("/guilds/therianthrope/dragon/tail-lash.c");

    addChild("/guilds/therianthrope/dragon/glacial-fangs.c",
        "/guilds/therianthrope/dragon/frost-claw.c");
    addChild("/guilds/therianthrope/dragon/tail-lash.c",
        "/guilds/therianthrope/dragon/draconic-resilience.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/frost-breath.c");
    addResearchElement("/guilds/therianthrope/dragon/dragons-fortitude.c");

    addChild("/guilds/therianthrope/dragon/frost-breath.c",
        "/guilds/therianthrope/dragon/glacial-fangs.c");
    addChild("/guilds/therianthrope/dragon/dragons-fortitude.c",
        "/guilds/therianthrope/dragon/draconic-resilience.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/wyrms-cunning.c");
    addResearchElement("/guilds/therianthrope/dragon/silver-aegis.c");

    addChild("/guilds/therianthrope/dragon/wyrms-cunning.c",
        "/guilds/therianthrope/dragon/frost-breath.c");
    addChild("/guilds/therianthrope/dragon/silver-aegis.c",
        "/guilds/therianthrope/dragon/dragons-fortitude.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/rime-mastery.c");
    addResearchElement("/guilds/therianthrope/dragon/draconic-efficiency.c");

    addChild("/guilds/therianthrope/dragon/rime-mastery.c",
        "/guilds/therianthrope/dragon/wyrms-cunning.c");
    addChild("/guilds/therianthrope/dragon/draconic-efficiency.c",
        "/guilds/therianthrope/dragon/dragons-fortitude.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/soul-freeze.c");
    addResearchElement("/guilds/therianthrope/dragon/frost-ward.c");

    addChild("/guilds/therianthrope/dragon/soul-freeze.c",
        "/guilds/therianthrope/dragon/rime-mastery.c");
    addChild("/guilds/therianthrope/dragon/frost-ward.c",
        "/guilds/therianthrope/dragon/silver-aegis.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/frozen-heart.c");
    addResearchElement("/guilds/therianthrope/dragon/draconic-celerity.c");

    addChild("/guilds/therianthrope/dragon/frozen-heart.c",
        "/guilds/therianthrope/dragon/soul-freeze.c");
    addChild("/guilds/therianthrope/dragon/draconic-celerity.c",
        "/guilds/therianthrope/dragon/draconic-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/frozen-blight.c");
    addResearchElement("/guilds/therianthrope/dragon/adamantine-scales.c");

    addChild("/guilds/therianthrope/dragon/frozen-blight.c",
        "/guilds/therianthrope/dragon/frozen-heart.c");
    addChild("/guilds/therianthrope/dragon/adamantine-scales.c",
        "/guilds/therianthrope/dragon/frost-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/permafrost.c");
    addResearchElement("/guilds/therianthrope/dragon/hoarfrost-mantle.c");

    addChild("/guilds/therianthrope/dragon/permafrost.c",
        "/guilds/therianthrope/dragon/frozen-blight.c");
    addChild("/guilds/therianthrope/dragon/hoarfrost-mantle.c",
        "/guilds/therianthrope/dragon/adamantine-scales.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/boreal-fury.c");
    addResearchElement("/guilds/therianthrope/dragon/glacial-tempest.c");

    addChild("/guilds/therianthrope/dragon/boreal-fury.c",
        "/guilds/therianthrope/dragon/permafrost.c");
    addChild("/guilds/therianthrope/dragon/glacial-tempest.c",
        "/guilds/therianthrope/dragon/hoarfrost-mantle.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/ancient-wyrm.c");
    addResearchElement("/guilds/therianthrope/dragon/winter-ward.c");

    addChild("/guilds/therianthrope/dragon/ancient-wyrm.c",
        "/guilds/therianthrope/dragon/boreal-fury.c");
    addChild("/guilds/therianthrope/dragon/winter-ward.c",
        "/guilds/therianthrope/dragon/glacial-tempest.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/dragon-apotheosis.c");
    addResearchElement("/guilds/therianthrope/dragon/frostfall.c");

    addChild("/guilds/therianthrope/dragon/dragon-apotheosis.c",
        "/guilds/therianthrope/dragon/ancient-wyrm.c");
    addChild("/guilds/therianthrope/dragon/frostfall.c",
        "/guilds/therianthrope/dragon/winter-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/primordial-dragon.c");
    addResearchElement("/guilds/therianthrope/dragon/silver-dominion.c");

    addChild("/guilds/therianthrope/dragon/primordial-dragon.c",
        "/guilds/therianthrope/dragon/dragon-apotheosis.c");
    addChild("/guilds/therianthrope/dragon/silver-dominion.c",
        "/guilds/therianthrope/dragon/frostfall.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/elder-wyrm.c");
    addResearchElement("/guilds/therianthrope/dragon/eternal-winter.c");

    addChild("/guilds/therianthrope/dragon/elder-wyrm.c",
        "/guilds/therianthrope/dragon/primordial-dragon.c");
    addChild("/guilds/therianthrope/dragon/eternal-winter.c",
        "/guilds/therianthrope/dragon/silver-dominion.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/silver-dragon-ascendant.c");
    addResearchElement("/guilds/therianthrope/dragon/wyrms-legacy.c");

    addChild("/guilds/therianthrope/dragon/silver-dragon-ascendant.c",
        "/guilds/therianthrope/dragon/elder-wyrm.c");
    addChild("/guilds/therianthrope/dragon/wyrms-legacy.c",
        "/guilds/therianthrope/dragon/eternal-winter.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/mythic-dragon.c");

    addChild("/guilds/therianthrope/dragon/mythic-dragon.c",
        "/guilds/therianthrope/dragon/silver-dragon-ascendant.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EightyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/dragon/silver-dragon-sovereign.c");

    addChild("/guilds/therianthrope/dragon/silver-dragon-sovereign.c",
        "/guilds/therianthrope/dragon/mythic-dragon.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Dragon Form");
    Description("This research tree provides knowledge of transforming into "
        "a magnificent silver dragon. The dragon form excels at devastating "
        "frost attacks, life-draining siphons, and overwhelming physical "
        "power. Progressive mastery unlocks freezing breath, soul-chilling "
        "frost, and eventually the power of the silver dragon sovereign.");
    Source("therianthrope");
    addResearchElement("/guilds/therianthrope/dragon/dragon-root.c");
    TreeRoot("/guilds/therianthrope/dragon/dragon-root.c");

    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFirstLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FortySeventhLevel();
    FortyNinthLevel();
    FiftyThirdLevel();
    FiftySeventhLevel();
    SixtyFirstLevel();
    SixtySeventhLevel();
    SeventyThirdLevel();
    SeventyNinthLevel();
    EightyFifthLevel();
}
