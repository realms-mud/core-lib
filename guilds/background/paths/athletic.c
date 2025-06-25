//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/background/paths/athletic/iron-grip.c");
    addResearchElement("/guilds/background/paths/athletic/fleet-footed.c");
    addResearchElement("/guilds/background/paths/athletic/steady-balance.c");

    addChild("/guilds/background/paths/athletic/iron-grip.c",
        "/guilds/background/paths/athletic/root.c");
    addChild("/guilds/background/paths/athletic/fleet-footed.c",
        "/guilds/background/paths/athletic/root.c");
    addChild("/guilds/background/paths/athletic/steady-balance.c",
        "/guilds/background/paths/athletic/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/background/paths/athletic/long-distance.c");
    addResearchElement("/guilds/background/paths/athletic/quick-recovery.c");
    addResearchElement("/guilds/background/paths/athletic/verticality.c");

    addChild("/guilds/background/paths/athletic/long-distance.c",
        "/guilds/background/paths/athletic/iron-grip.c");
    addChild("/guilds/background/paths/athletic/quick-recovery.c",
        "/guilds/background/paths/athletic/fleet-footed.c");
    // verticality does not build off a first-level, so parent to root
    addChild("/guilds/background/paths/athletic/verticality.c",
        "/guilds/background/paths/athletic/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/background/paths/athletic/powerful-leap.c");
    addResearchElement("/guilds/background/paths/athletic/relentless.c");
    addResearchElement("/guilds/background/paths/athletic/rolling-landing.c");

    addChild("/guilds/background/paths/athletic/powerful-leap.c",
        "/guilds/background/paths/athletic/long-distance.c");
    // relentless does not build off a second-level, so parent to root
    addChild("/guilds/background/paths/athletic/relentless.c",
        "/guilds/background/paths/athletic/root.c");
    addChild("/guilds/background/paths/athletic/rolling-landing.c",
        "/guilds/background/paths/athletic/verticality.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/background/paths/athletic/unstoppable-force.c");
    addResearchElement("/guilds/background/paths/athletic/iron-endurance.c");
    addResearchElement("/guilds/background/paths/athletic/peak-performance.c");

    addChild("/guilds/background/paths/athletic/unstoppable-force.c",
        "/guilds/background/paths/athletic/powerful-leap.c");
    addChild("/guilds/background/paths/athletic/iron-endurance.c",
        "/guilds/background/paths/athletic/relentless.c");
    // peak-performance does not build off a third-level, so parent to root
    addChild("/guilds/background/paths/athletic/peak-performance.c",
        "/guilds/background/paths/athletic/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/background/paths/athletic/athletic-legend.c");
    addResearchElement("/guilds/background/paths/athletic/limitless-energy.c");
    addResearchElement("/guilds/background/paths/athletic/indomitable.c");

    addChild("/guilds/background/paths/athletic/athletic-legend.c",
        "/guilds/background/paths/athletic/unstoppable-force.c");
    // limitless-energy does not build off a fourth-level, so parent to root
    addChild("/guilds/background/paths/athletic/limitless-energy.c",
        "/guilds/background/paths/athletic/root.c");
    addChild("/guilds/background/paths/athletic/indomitable.c",
        "/guilds/background/paths/athletic/peak-performance.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("An Athlete");
    Description("You spent your formative years in constant motion—running, climbing, "
        "and testing the limits of your body. Whether through sport, labor, or "
        "adventure, you honed your physical prowess and developed a keen sense "
        "of coordination, endurance, and strength. The athletic path is for those "
        "who thrive on action and physical challenge.");
    Source("background");
    addResearchElement("/guilds/background/paths/athletic/root.c");
    TreeRoot("/guilds/background/paths/athletic/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
}
