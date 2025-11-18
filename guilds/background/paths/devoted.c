//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/background/paths/devoted/inner-peace.c");
    addResearchElement("/guilds/background/paths/devoted/faithful-heart.c");
    addResearchElement("/guilds/background/paths/devoted/spiritual-awareness.c");

    addChild("/guilds/background/paths/devoted/inner-peace.c",
        "/guilds/background/paths/devoted/root.c");
    addChild("/guilds/background/paths/devoted/faithful-heart.c",
        "/guilds/background/paths/devoted/root.c");
    addChild("/guilds/background/paths/devoted/spiritual-awareness.c",
        "/guilds/background/paths/devoted/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/background/paths/devoted/meditative-focus.c");
    addResearchElement("/guilds/background/paths/devoted/spiritual-resilience.c");
    addResearchElement("/guilds/background/paths/devoted/humble-servant.c");

    addChild("/guilds/background/paths/devoted/meditative-focus.c",
        "/guilds/background/paths/devoted/inner-peace.c");
    addChild("/guilds/background/paths/devoted/spiritual-resilience.c",
        "/guilds/background/paths/devoted/faithful-heart.c");
    // humble-servant does not build off a first-level, so parent to root
    addChild("/guilds/background/paths/devoted/humble-servant.c",
        "/guilds/background/paths/devoted/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/background/paths/devoted/enlightened-mind.c");
    addResearchElement("/guilds/background/paths/devoted/divine-purpose.c");
    addResearchElement("/guilds/background/paths/devoted/spiritual-fortitude.c");

    addChild("/guilds/background/paths/devoted/enlightened-mind.c",
        "/guilds/background/paths/devoted/meditative-focus.c");
    // divine-purpose does not build off a second-level, so parent to root
    addChild("/guilds/background/paths/devoted/divine-purpose.c",
        "/guilds/background/paths/devoted/root.c");
    addChild("/guilds/background/paths/devoted/spiritual-fortitude.c",
        "/guilds/background/paths/devoted/humble-servant.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/background/paths/devoted/transcendent-wisdom.c");
    addResearchElement("/guilds/background/paths/devoted/unshakeable-faith.c");
    addResearchElement("/guilds/background/paths/devoted/spiritual-clarity.c");

    addChild("/guilds/background/paths/devoted/transcendent-wisdom.c",
        "/guilds/background/paths/devoted/enlightened-mind.c");
    addChild("/guilds/background/paths/devoted/unshakeable-faith.c",
        "/guilds/background/paths/devoted/spiritual-fortitude.c");
    // spiritual-clarity does not build off a third-level, so parent to root
    addChild("/guilds/background/paths/devoted/spiritual-clarity.c",
        "/guilds/background/paths/devoted/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/background/paths/devoted/ascended-soul.c");
    addResearchElement("/guilds/background/paths/devoted/divine-vessel.c");
    addResearchElement("/guilds/background/paths/devoted/spiritual-mastery.c");

    addChild("/guilds/background/paths/devoted/ascended-soul.c",
        "/guilds/background/paths/devoted/transcendent-wisdom.c");
    // divine-vessel does not build off a fourth-level, so parent to root
    addChild("/guilds/background/paths/devoted/divine-vessel.c",
        "/guilds/background/paths/devoted/root.c");
    addChild("/guilds/background/paths/devoted/spiritual-mastery.c",
        "/guilds/background/paths/devoted/spiritual-clarity.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("A Devoted Seeker");
    Description("Your childhood was marked by questions of meaning and purpose. Whether "
        "raised in a religious order, mentored by a mystic, or driven by personal "
        "seeking, you developed a deep connection to something greater than yourself. "
        "The devoted path is for those who find strength in faith, seek wisdom through "
        "contemplation, and believe that spiritual growth is as important as physical prowess.");
    Source("background");
    addResearchElement("/guilds/background/paths/devoted/root.c");
    TreeRoot("/guilds/background/paths/devoted/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
}
