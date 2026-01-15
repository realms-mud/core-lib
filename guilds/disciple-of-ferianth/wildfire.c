//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/smolder.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/smolder.c",
        "/guilds/disciple-of-ferianth/wildfire/wildfire-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/wildfire-mastery.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/wildfire-mastery.c",
        "/guilds/disciple-of-ferianth/wildfire/smolder.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/kindling.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/kindling.c",
        "/guilds/disciple-of-ferianth/wildfire/wildfire-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/burning-brand.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/burning-brand.c",
        "/guilds/disciple-of-ferianth/wildfire/smolder.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/wildfire-potency.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/wildfire-potency.c",
        "/guilds/disciple-of-ferianth/wildfire/wildfire-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/smolder-efficiency.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/burning-brand-potency.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/smolder-efficiency.c",
        "/guilds/disciple-of-ferianth/wildfire/kindling.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/burning-brand-potency.c",
        "/guilds/disciple-of-ferianth/wildfire/burning-brand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/spreading-flames.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/spreading-flames.c",
        "/guilds/disciple-of-ferianth/wildfire/burning-brand.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c",
        "/guilds/disciple-of-ferianth/wildfire/wildfire-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/smolder-swiftness.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/burning-brand-efficiency.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/smolder-swiftness.c",
        "/guilds/disciple-of-ferianth/wildfire/smolder-efficiency.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/burning-brand-efficiency.c",
        "/guilds/disciple-of-ferianth/wildfire/burning-brand-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/spreading-flames-potency.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/burning-brand-swiftness.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/spreading-flames-potency.c",
        "/guilds/disciple-of-ferianth/wildfire/spreading-flames.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/burning-brand-swiftness.c",
        "/guilds/disciple-of-ferianth/wildfire/burning-brand-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/conflagration.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/burning-brand-intensity.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/conflagration.c",
        "/guilds/disciple-of-ferianth/wildfire/spreading-flames.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c",
        "/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/burning-brand-intensity.c",
        "/guilds/disciple-of-ferianth/wildfire/burning-brand-swiftness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/spreading-flames-efficiency.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/smolder-intensity.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/spreading-flames-efficiency.c",
        "/guilds/disciple-of-ferianth/wildfire/spreading-flames-potency.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/smolder-intensity.c",
        "/guilds/disciple-of-ferianth/wildfire/smolder-swiftness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/conflagration-potency.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/spreading-flames-swiftness.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/wildfire-intensity.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/conflagration-potency.c",
        "/guilds/disciple-of-ferianth/wildfire/conflagration.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/spreading-flames-swiftness.c",
        "/guilds/disciple-of-ferianth/wildfire/spreading-flames-efficiency.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/wildfire-intensity.c",
        "/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/raging-wildfire.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/spreading-flames-intensity.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/raging-wildfire.c",
        "/guilds/disciple-of-ferianth/wildfire/conflagration.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/spreading-flames-intensity.c",
        "/guilds/disciple-of-ferianth/wildfire/spreading-flames-swiftness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/conflagration-efficiency.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/conflagration-efficiency.c",
        "/guilds/disciple-of-ferianth/wildfire/conflagration-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/raging-wildfire-potency.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/conflagration-swiftness.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/raging-wildfire-potency.c",
        "/guilds/disciple-of-ferianth/wildfire/raging-wildfire.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/conflagration-swiftness.c",
        "/guilds/disciple-of-ferianth/wildfire/conflagration-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/conflagration-intensity.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/conflagration-intensity.c",
        "/guilds/disciple-of-ferianth/wildfire/conflagration-swiftness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/raging-wildfire-efficiency.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire.c",
        "/guilds/disciple-of-ferianth/wildfire/raging-wildfire.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/raging-wildfire-efficiency.c",
        "/guilds/disciple-of-ferianth/wildfire/raging-wildfire-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/raging-wildfire-swiftness.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/raging-wildfire-swiftness.c",
        "/guilds/disciple-of-ferianth/wildfire/raging-wildfire-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-potency.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/raging-wildfire-intensity.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-potency.c",
        "/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/raging-wildfire-intensity.c",
        "/guilds/disciple-of-ferianth/wildfire/raging-wildfire-swiftness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-efficiency.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/supreme-wildfire.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-efficiency.c",
        "/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-potency.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/supreme-wildfire.c",
        "/guilds/disciple-of-ferianth/wildfire/wildfire-intensity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-swiftness.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-swiftness.c",
        "/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/searing-devastation.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-intensity.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/searing-devastation.c",
        "/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-intensity.c",
        "/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-swiftness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/searing-devastation-potency.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/searing-devastation-potency.c",
        "/guilds/disciple-of-ferianth/wildfire/searing-devastation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/searing-devastation-efficiency.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/searing-devastation-efficiency.c",
        "/guilds/disciple-of-ferianth/wildfire/searing-devastation-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/searing-devastation-swiftness.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/searing-devastation-swiftness.c",
        "/guilds/disciple-of-ferianth/wildfire/searing-devastation-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/searing-devastation-intensity.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm.c",
        "/guilds/disciple-of-ferianth/wildfire/searing-devastation.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/searing-devastation-intensity.c",
        "/guilds/disciple-of-ferianth/wildfire/searing-devastation-swiftness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/divine-wildfire-mastery.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/divine-wildfire-mastery.c",
        "/guilds/disciple-of-ferianth/wildfire/supreme-wildfire.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-potency.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-potency.c",
        "/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-efficiency.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-efficiency.c",
        "/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-swiftness.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-swiftness.c",
        "/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-intensity.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre.c",
        "/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-intensity.c",
        "/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-swiftness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-potency.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-efficiency.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-swiftness.c");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-intensity.c");

    addChild("/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-potency.c",
        "/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-efficiency.c",
        "/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-potency.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-swiftness.c",
        "/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-efficiency.c");
    addChild("/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-intensity.c",
        "/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-swiftness.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Wildfire");
    Description("This research tree provides knowledge of wildfire magic - "
        "the burning, spreading aspect of Ferianth's sacred flames. Through "
        "study of wildfire, practitioners learn to ignite enemies with flames "
        "that burn over time and spread to consume all in their path.");
    Source("disciple of ferianth");
    addResearchElement("/guilds/disciple-of-ferianth/wildfire/wildfire-root.c");
    TreeRoot("/guilds/disciple-of-ferianth/wildfire/wildfire-root.c");

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
    FiftyFirstLevel();
    FiftyThirdLevel();
    FiftyFifthLevel();
    FiftySeventhLevel();
    FiftyNinthLevel();
    SixtyFirstLevel();
    SixtyThirdLevel();
    SixtyFifthLevel();
    SixtySeventhLevel();
}
