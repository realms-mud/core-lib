//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/invocation-of-the-pyre.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/invocation-of-the-pyre.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/liturgical-knowledge.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/liturgical-knowledge.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/sacred-flames.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/sacred-flames.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/invocation-of-the-pyre.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/holy-blessing.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/holy-blessing.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/amplified-invocation.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/amplified-invocation.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/invocation-of-the-pyre.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/sacred-understanding.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/sacred-understanding.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/liturgical-knowledge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/intensified-sacred-flames.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/intensified-sacred-flames.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/sacred-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/hastened-invocation.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/hastened-invocation.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/amplified-invocation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/sacred-fortitude.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/sacred-fortitude.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/holy-blessing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/hastened-sacred-flames.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/hastened-sacred-flames.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/intensified-sacred-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFourthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/divine-wisdom.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/divine-wisdom.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/sacred-understanding.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/divine-invocation.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/divine-invocation.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/amplified-invocation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/overwhelming-sacred-flames.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/overwhelming-sacred-flames.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/intensified-sacred-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyEighthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/divine-favor.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/divine-favor.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/sacred-fortitude.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySecondLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/ferianths-insight.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/ferianths-insight.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/divine-wisdom.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySixthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/sanctified-body.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/sanctified-body.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/divine-favor.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/ardent-mastery.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/ardent-mastery.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/ferianths-insight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFourthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/holy-vessel.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/holy-vessel.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/sanctified-body.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyEighthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/divine-focus.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/divine-focus.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/ardent-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftiethLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/sacred-protection.c");

    addChild("/guilds/disciple-of-ferianth/sacred-pyre/sacred-protection.c",
        "/guilds/disciple-of-ferianth/sacred-pyre/holy-vessel.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Sacred Pyre");
    Description("This research tree provides knowledge of Ferianth's sacred "
        "rituals and prayers. Through study of the sacred pyre, practitioners "
        "learn to perform powerful divine rites and gain permanent blessings.");
    Source("disciple of ferianth");
    addResearchElement("/guilds/disciple-of-ferianth/sacred-pyre/root.c");
    TreeRoot("/guilds/disciple-of-ferianth/sacred-pyre/root.c");

    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SixteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentiethLevel();
    TwentyThirdLevel();
    TwentyFourthLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyEighthLevel();
    ThirtySecondLevel();
    ThirtySixthLevel();
    FortiethLevel();
    FortyFourthLevel();
    FortyEighthLevel();
    FiftiethLevel();
}
