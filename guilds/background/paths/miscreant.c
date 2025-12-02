//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/background/paths/miscreant/sly-tricks.c");
    addResearchElement("/guilds/background/paths/miscreant/quick-hands.c");
    addResearchElement("/guilds/background/paths/miscreant/shadow-walker.c");

    addChild("/guilds/background/paths/miscreant/sly-tricks.c",
        "/guilds/background/paths/miscreant/root.c");
    addChild("/guilds/background/paths/miscreant/quick-hands.c",
        "/guilds/background/paths/miscreant/root.c");
    addChild("/guilds/background/paths/miscreant/shadow-walker.c",
        "/guilds/background/paths/miscreant/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/background/paths/miscreant/urban-survivor.c");
    addResearchElement("/guilds/background/paths/miscreant/escape-artist.c");
    addResearchElement("/guilds/background/paths/miscreant/keen-observation.c");

    addChild("/guilds/background/paths/miscreant/urban-survivor.c",
        "/guilds/background/paths/miscreant/sly-tricks.c");
    addChild("/guilds/background/paths/miscreant/escape-artist.c",
        "/guilds/background/paths/miscreant/quick-hands.c");
    // keen-observation does not build off a first-level, so parent to root
    addChild("/guilds/background/paths/miscreant/keen-observation.c",
        "/guilds/background/paths/miscreant/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/background/paths/miscreant/dirty-fighting.c");
    addResearchElement("/guilds/background/paths/miscreant/poison-affinity.c");
    addResearchElement("/guilds/background/paths/miscreant/quick-thinking.c");

    addChild("/guilds/background/paths/miscreant/dirty-fighting.c",
        "/guilds/background/paths/miscreant/urban-survivor.c");
    // poison-affinity does not build off a second-level, so parent to root
    addChild("/guilds/background/paths/miscreant/poison-affinity.c",
        "/guilds/background/paths/miscreant/root.c");
    addChild("/guilds/background/paths/miscreant/quick-thinking.c",
        "/guilds/background/paths/miscreant/keen-observation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/background/paths/miscreant/underworld-contacts.c");
    addResearchElement("/guilds/background/paths/miscreant/lockbreaker.c");
    addResearchElement("/guilds/background/paths/miscreant/second-wind.c");

    addChild("/guilds/background/paths/miscreant/underworld-contacts.c",
        "/guilds/background/paths/miscreant/dirty-fighting.c");
    addChild("/guilds/background/paths/miscreant/lockbreaker.c",
        "/guilds/background/paths/miscreant/poison-affinity.c");
    // second-wind does not build off a third-level, so parent to root
    addChild("/guilds/background/paths/miscreant/second-wind.c",
        "/guilds/background/paths/miscreant/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/background/paths/miscreant/master-of-disguise.c");
    addResearchElement("/guilds/background/paths/miscreant/uncanny-luck.c");
    addResearchElement("/guilds/background/paths/miscreant/escape-death.c");

    addChild("/guilds/background/paths/miscreant/master-of-disguise.c",
        "/guilds/background/paths/miscreant/underworld-contacts.c");
    // uncanny-luck does not build off a fourth-level, so parent to root
    addChild("/guilds/background/paths/miscreant/uncanny-luck.c",
        "/guilds/background/paths/miscreant/root.c");
    addChild("/guilds/background/paths/miscreant/escape-death.c",
        "/guilds/background/paths/miscreant/second-wind.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("A Miscreant");
    Description("You grew up on the fringes, learning to survive by your wits and "
        "sometimes bending or breaking the rules. Whether as a prankster, a thief, "
        "or simply a rebel, you developed cunning, resourcefulness, and a knack "
        "for getting into (and out of) trouble. The miscreant path is for those "
        "who thrive in the shadows and live by their own code.");
    Source("background");
    addResearchElement("/guilds/background/paths/miscreant/root.c");
    TreeRoot("/guilds/background/paths/miscreant/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
}
