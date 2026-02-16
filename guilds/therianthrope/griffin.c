//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/eagle-sight.c");
    addResearchElement("/guilds/therianthrope/griffin/golden-plumage.c");

    addChild("/guilds/therianthrope/griffin/eagle-sight.c",
        "/guilds/therianthrope/griffin/griffin-root.c");
    addChild("/guilds/therianthrope/griffin/golden-plumage.c",
        "/guilds/therianthrope/griffin/griffin-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/talon-rake.c");
    addResearchElement("/guilds/therianthrope/griffin/wing-buffet.c");

    addChild("/guilds/therianthrope/griffin/talon-rake.c",
        "/guilds/therianthrope/griffin/eagle-sight.c");
    addChild("/guilds/therianthrope/griffin/wing-buffet.c",
        "/guilds/therianthrope/griffin/golden-plumage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/diving-strike.c");
    addResearchElement("/guilds/therianthrope/griffin/raptor-fury.c");

    addChild("/guilds/therianthrope/griffin/diving-strike.c",
        "/guilds/therianthrope/griffin/wing-buffet.c");
    addChild("/guilds/therianthrope/griffin/raptor-fury.c",
        "/guilds/therianthrope/griffin/talon-rake.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/iron-feathers.c");
    addResearchElement("/guilds/therianthrope/griffin/hunters-instinct.c");

    addChild("/guilds/therianthrope/griffin/iron-feathers.c",
        "/guilds/therianthrope/griffin/wing-buffet.c");
    addChild("/guilds/therianthrope/griffin/hunters-instinct.c",
        "/guilds/therianthrope/griffin/raptor-fury.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/shrieking-gale.c");
    addResearchElement("/guilds/therianthrope/griffin/soaring-efficiency.c");

    addChild("/guilds/therianthrope/griffin/shrieking-gale.c",
        "/guilds/therianthrope/griffin/hunters-instinct.c");
    addChild("/guilds/therianthrope/griffin/soaring-efficiency.c",
        "/guilds/therianthrope/griffin/iron-feathers.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/sky-mastery.c");
    addResearchElement("/guilds/therianthrope/griffin/aerial-vigilance.c");

    addChild("/guilds/therianthrope/griffin/sky-mastery.c",
        "/guilds/therianthrope/griffin/shrieking-gale.c");
    addChild("/guilds/therianthrope/griffin/aerial-vigilance.c",
        "/guilds/therianthrope/griffin/iron-feathers.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/sky-hammer.c");

    addChild("/guilds/therianthrope/griffin/sky-hammer.c",
        "/guilds/therianthrope/griffin/sky-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/hippogriff.c");
    addResearchElement("/guilds/therianthrope/griffin/gale-ward.c");

    addChild("/guilds/therianthrope/griffin/hippogriff.c",
        "/guilds/therianthrope/griffin/shrieking-gale.c");
    addChild("/guilds/therianthrope/griffin/gale-ward.c",
        "/guilds/therianthrope/griffin/aerial-vigilance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/aerial-celerity.c");

    addChild("/guilds/therianthrope/griffin/aerial-celerity.c",
        "/guilds/therianthrope/griffin/soaring-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/sky-sovereign.c");
    addResearchElement("/guilds/therianthrope/griffin/tempest.c");

    addChild("/guilds/therianthrope/griffin/sky-sovereign.c",
        "/guilds/therianthrope/griffin/hippogriff.c");
    addChild("/guilds/therianthrope/griffin/tempest.c",
        "/guilds/therianthrope/griffin/gale-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/griffin-apotheosis.c");
    addResearchElement("/guilds/therianthrope/griffin/storm-pinion.c");

    addChild("/guilds/therianthrope/griffin/griffin-apotheosis.c",
        "/guilds/therianthrope/griffin/sky-sovereign.c");
    addChild("/guilds/therianthrope/griffin/storm-pinion.c",
        "/guilds/therianthrope/griffin/tempest.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/zephyr-swiftness.c");
    addResearchElement("/guilds/therianthrope/griffin/empyrean-ward.c");

    addChild("/guilds/therianthrope/griffin/zephyr-swiftness.c",
        "/guilds/therianthrope/griffin/griffin-apotheosis.c");
    addChild("/guilds/therianthrope/griffin/empyrean-ward.c",
        "/guilds/therianthrope/griffin/storm-pinion.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/sky-warden.c");
    addResearchElement("/guilds/therianthrope/griffin/celestial-aegis.c");

    addChild("/guilds/therianthrope/griffin/sky-warden.c",
        "/guilds/therianthrope/griffin/zephyr-swiftness.c");
    addChild("/guilds/therianthrope/griffin/celestial-aegis.c",
        "/guilds/therianthrope/griffin/empyrean-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/eternal-griffin.c");

    addChild("/guilds/therianthrope/griffin/eternal-griffin.c",
        "/guilds/therianthrope/griffin/sky-warden.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/griffin-ascendant.c");

    addChild("/guilds/therianthrope/griffin/griffin-ascendant.c",
        "/guilds/therianthrope/griffin/eternal-griffin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/griffin/lord-of-the-skies.c");

    addChild("/guilds/therianthrope/griffin/lord-of-the-skies.c",
        "/guilds/therianthrope/griffin/griffin-ascendant.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Griffin Form");
    Description("This research tree provides knowledge of transforming into "
        "a majestic griffin. The griffin form excels at aerial attacks, "
        "keen precision, and wind-based abilities. Progressive mastery "
        "unlocks devastating diving strikes, howling gales, and eventually "
        "the power of the mythical lord of the skies.");
    Source("therianthrope");
    addResearchElement("/guilds/therianthrope/griffin/griffin-root.c");
    TreeRoot("/guilds/therianthrope/griffin/griffin-root.c");

    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    FortyFirstLevel();
    FortyFifthLevel();
    FortyNinthLevel();
    FiftyFifthLevel();
    SixtyFirstLevel();
    SixtySeventhLevel();
}
