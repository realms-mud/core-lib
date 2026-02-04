//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/exarchs-resolve.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/divine-favor.c");

    addChild("/guilds/disciple-of-ferianth/ferianths-grace/exarchs-resolve.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/root.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/divine-favor.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/ferianthian-blessing.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/ferianthian-judgment.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/exarchs-fortitude.c");

    addChild("/guilds/disciple-of-ferianth/ferianths-grace/ferianthian-blessing.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/exarchs-resolve.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/ferianthian-judgment.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/exarchs-resolve.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/exarchs-fortitude.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/exarchs-resolve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/rebirth-from-ashes.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/grace-potency.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/divine-resilience.c");

    addChild("/guilds/disciple-of-ferianth/ferianths-grace/rebirth-from-ashes.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/exarchs-fortitude.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/grace-potency.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/ferianthian-blessing.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/divine-resilience.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/ferianthian-judgment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/exalted-blessing.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/righteous-fury.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/divine-sanctuary.c");

    addChild("/guilds/disciple-of-ferianth/ferianths-grace/exalted-blessing.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/grace-potency.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/righteous-fury.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/divine-resilience.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/divine-sanctuary.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/rebirth-from-ashes.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/exarchs-blessing.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/divine-wrath.c");

    addChild("/guilds/disciple-of-ferianth/ferianths-grace/exarchs-blessing.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/exalted-blessing.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/divine-wrath.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/righteous-fury.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/divine-judgment.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/eternal-protection.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/holy-bastion.c");

    addChild("/guilds/disciple-of-ferianth/ferianths-grace/divine-judgment.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/divine-wrath.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/eternal-protection.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/exarchs-blessing.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/holy-bastion.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/divine-sanctuary.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/harbinger-of-ferianth.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/grace-mastery.c");

    addChild("/guilds/disciple-of-ferianth/ferianths-grace/harbinger-of-ferianth.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/divine-judgment.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/grace-mastery.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/eternal-protection.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/ferianths-chosen.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/divine-vessel.c");

    addChild("/guilds/disciple-of-ferianth/ferianths-grace/ferianths-chosen.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/harbinger-of-ferianth.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/divine-vessel.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/holy-bastion.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/eternal-flame.c");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/apocalyptic-judgment.c");

    addChild("/guilds/disciple-of-ferianth/ferianths-grace/eternal-flame.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/divine-vessel.c");
    addChild("/guilds/disciple-of-ferianth/ferianths-grace/apocalyptic-judgment.c",
        "/guilds/disciple-of-ferianth/ferianths-grace/ferianths-chosen.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Ferianth's Grace");
    Description("This research tree provides knowledge of Ferianth's most "
        "powerful divine blessings - miracles granted only to those who "
        "have achieved the rank of Exarch.");
    Source("disciple of ferianth");
    addResearchElement("/guilds/disciple-of-ferianth/ferianths-grace/root.c");
    TreeRoot("/guilds/disciple-of-ferianth/ferianths-grace/root.c");

    ThirtyFifthLevel();
    ThirtySeventhLevel();
    FortyFirstLevel();
    FortyFifthLevel();
    FortyNinthLevel();
    FiftyThirdLevel();
    FiftySeventhLevel();
    SixtyFirstLevel();
    SixtyFifthLevel();
}
