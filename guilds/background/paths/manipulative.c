//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/background/paths/manipulative/silver-tongue.c");
    addResearchElement("/guilds/background/paths/manipulative/keen-observer.c");
    addResearchElement("/guilds/background/paths/manipulative/social-chameleon.c");

    addChild("/guilds/background/paths/manipulative/silver-tongue.c",
        "/guilds/background/paths/manipulative/root.c");
    addChild("/guilds/background/paths/manipulative/keen-observer.c",
        "/guilds/background/paths/manipulative/root.c");
    addChild("/guilds/background/paths/manipulative/social-chameleon.c",
        "/guilds/background/paths/manipulative/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/background/paths/manipulative/persuader.c");
    addResearchElement("/guilds/background/paths/manipulative/hidden-motives.c");
    addResearchElement("/guilds/background/paths/manipulative/quick-lie.c");

    addChild("/guilds/background/paths/manipulative/persuader.c",
        "/guilds/background/paths/manipulative/silver-tongue.c");
    addChild("/guilds/background/paths/manipulative/hidden-motives.c",
        "/guilds/background/paths/manipulative/keen-observer.c");
    // quick-lie does not build off a first-level, so parent to root
    addChild("/guilds/background/paths/manipulative/quick-lie.c",
        "/guilds/background/paths/manipulative/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/background/paths/manipulative/master-negotiator.c");
    addResearchElement("/guilds/background/paths/manipulative/insightful.c");
    addResearchElement("/guilds/background/paths/manipulative/false-face.c");

    addChild("/guilds/background/paths/manipulative/master-negotiator.c",
        "/guilds/background/paths/manipulative/persuader.c");
    // insightful does not build off a second-level, so parent to root
    addChild("/guilds/background/paths/manipulative/insightful.c",
        "/guilds/background/paths/manipulative/root.c");
    addChild("/guilds/background/paths/manipulative/false-face.c",
        "/guilds/background/paths/manipulative/quick-lie.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/background/paths/manipulative/political-savvy.c");
    addResearchElement("/guilds/background/paths/manipulative/puppetmaster.c");
    addResearchElement("/guilds/background/paths/manipulative/hidden-in-plain-sight.c");

    addChild("/guilds/background/paths/manipulative/political-savvy.c",
        "/guilds/background/paths/manipulative/master-negotiator.c");
    addChild("/guilds/background/paths/manipulative/puppetmaster.c",
        "/guilds/background/paths/manipulative/insightful.c");
    // hidden-in-plain-sight does not build off a third-level, so parent to root
    addChild("/guilds/background/paths/manipulative/hidden-in-plain-sight.c",
        "/guilds/background/paths/manipulative/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/background/paths/manipulative/kingmaker.c");
    addResearchElement("/guilds/background/paths/manipulative/untouchable.c");
    addResearchElement("/guilds/background/paths/manipulative/legendary-influence.c");

    addChild("/guilds/background/paths/manipulative/kingmaker.c",
        "/guilds/background/paths/manipulative/political-savvy.c");
    // untouchable does not build off a fourth-level, so parent to root
    addChild("/guilds/background/paths/manipulative/untouchable.c",
        "/guilds/background/paths/manipulative/root.c");
    addChild("/guilds/background/paths/manipulative/legendary-influence.c",
        "/guilds/background/paths/manipulative/hidden-in-plain-sight.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("A Manipulative Little Shit");
    Description("You discovered early on that words and influence could be as powerful "
        "as any weapon. Whether charming, deceiving, or persuading, you learned to "
        "shape outcomes to your advantage. The manipulative path is for those who "
        "excel at reading people, navigating social situations, and bending others "
        "to their will.");
    Source("background");
    addResearchElement("/guilds/background/paths/manipulative/root.c");
    TreeRoot("/guilds/background/paths/manipulative/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
}
