//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/background/paths/dutiful/obedient-mind.c");
    addResearchElement("/guilds/background/paths/dutiful/steady-hand.c");
    addResearchElement("/guilds/background/paths/dutiful/early-riser.c");

    addChild("/guilds/background/paths/dutiful/obedient-mind.c",
        "/guilds/background/paths/dutiful/root.c");
    addChild("/guilds/background/paths/dutiful/steady-hand.c",
        "/guilds/background/paths/dutiful/root.c");
    addChild("/guilds/background/paths/dutiful/early-riser.c",
        "/guilds/background/paths/dutiful/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/background/paths/dutiful/loyal-companion.c");
    addResearchElement("/guilds/background/paths/dutiful/attentive-listener.c");
    addResearchElement("/guilds/background/paths/dutiful/cleanly-habits.c");

    addChild("/guilds/background/paths/dutiful/loyal-companion.c",
        "/guilds/background/paths/dutiful/obedient-mind.c");
    addChild("/guilds/background/paths/dutiful/attentive-listener.c",
        "/guilds/background/paths/dutiful/steady-hand.c");
    // cleanly-habits does not build off a first-level, so parent to root
    addChild("/guilds/background/paths/dutiful/cleanly-habits.c",
        "/guilds/background/paths/dutiful/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/background/paths/dutiful/steadfast.c");
    addResearchElement("/guilds/background/paths/dutiful/keen-memory.c");
    addResearchElement("/guilds/background/paths/dutiful/organized-mind.c");

    addChild("/guilds/background/paths/dutiful/steadfast.c",
        "/guilds/background/paths/dutiful/loyal-companion.c");
    // keen-memory does not build off a second-level, so parent to root
    addChild("/guilds/background/paths/dutiful/keen-memory.c",
        "/guilds/background/paths/dutiful/root.c");
    addChild("/guilds/background/paths/dutiful/organized-mind.c",
        "/guilds/background/paths/dutiful/cleanly-habits.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/background/paths/dutiful/iron-discipline.c");
    addResearchElement("/guilds/background/paths/dutiful/guardian-instinct.c");
    addResearchElement("/guilds/background/paths/dutiful/efficient-worker.c");

    addChild("/guilds/background/paths/dutiful/iron-discipline.c",
        "/guilds/background/paths/dutiful/steadfast.c");
    addChild("/guilds/background/paths/dutiful/guardian-instinct.c",
        "/guilds/background/paths/dutiful/keen-memory.c");
    // efficient-worker does not build off a third-level, so parent to root
    addChild("/guilds/background/paths/dutiful/efficient-worker.c",
        "/guilds/background/paths/dutiful/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/background/paths/dutiful/pillar-of-community.c");
    addResearchElement("/guilds/background/paths/dutiful/unbreakable-will.c");
    addResearchElement("/guilds/background/paths/dutiful/legacy-of-service.c");

    addChild("/guilds/background/paths/dutiful/pillar-of-community.c",
        "/guilds/background/paths/dutiful/iron-discipline.c");
    // unbreakable-will does not build off a fourth-level, so parent to root
    addChild("/guilds/background/paths/dutiful/unbreakable-will.c",
        "/guilds/background/paths/dutiful/root.c");
    addChild("/guilds/background/paths/dutiful/legacy-of-service.c",
        "/guilds/background/paths/dutiful/efficient-worker.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("A Dutiful Child");
    Description("Responsibility and service defined your early years. You learned the "
        "value of discipline, loyalty, and fulfilling obligations—whether to family, "
        "community, or a higher calling. The dutiful path is for those who find "
        "purpose in structure, order, and the satisfaction of a job well done.");
    Source("background");
    addResearchElement("/guilds/background/paths/dutiful/root.c");
    TreeRoot("/guilds/background/paths/dutiful/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
}
