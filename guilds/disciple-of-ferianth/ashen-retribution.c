//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/ashen-ward.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/ashen-ward.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/smoldering-defense.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/smoldering-defense.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/retributive-flames.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/retributive-flames.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/ashen-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/enhanced-ward.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/enhanced-ward.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/ashen-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/burning-resolve.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/burning-resolve.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/smoldering-defense.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/intensified-flames.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/intensified-flames.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/retributive-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/quickened-ward.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/quickened-ward.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/enhanced-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/ember-fortitude.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/ember-fortitude.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/burning-resolve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/efficient-flames.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/efficient-flames.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/intensified-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/greater-ward.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/greater-ward.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/enhanced-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySecondLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/ashen-resilience.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/ashen-resilience.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/ember-fortitude.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/hastened-flames.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/hastened-flames.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/efficient-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/searing-retribution.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/searing-retribution.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/intensified-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySixthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/flame-keepers-aegis.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/flame-keepers-aegis.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/ashen-resilience.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/wrath-of-the-pyre.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/wrath-of-the-pyre.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/flame-keepers-aegis.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFourthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/unyielding-flame.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/unyielding-flame.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/wrath-of-the-pyre.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyEighthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/divine-aegis.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/divine-aegis.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/unyielding-flame.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySecondLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/ferianths-bulwark.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/ferianths-bulwark.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/divine-aegis.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySixthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/avatar-of-ash.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/avatar-of-ash.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/ferianths-bulwark.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftiethLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/eternal-guardian.c");

    addChild("/guilds/disciple-of-ferianth/ashen-retribution/eternal-guardian.c",
        "/guilds/disciple-of-ferianth/ashen-retribution/avatar-of-ash.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Ashen Retribution");
    Description("This research tree provides knowledge of defensive fire magic "
        "and the protective aspect of Ferianth's sacred flames.");
    Source("disciple of ferianth");
    addResearchElement("/guilds/disciple-of-ferianth/ashen-retribution/root.c");
    TreeRoot("/guilds/disciple-of-ferianth/ashen-retribution/root.c");

    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FourteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    EighteenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentySecondLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySixthLevel();
    ThirtiethLevel();
    ThirtyFourthLevel();
    ThirtyEighthLevel();
    FortySecondLevel();
    FortySixthLevel();
    FiftiethLevel();
}