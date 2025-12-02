//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/background/paths/martial/drill-discipline.c");
    addResearchElement("/guilds/background/paths/martial/weapon-familiarity.c");
    addResearchElement("/guilds/background/paths/martial/field-awareness.c");

    addChild("/guilds/background/paths/martial/drill-discipline.c",
        "/guilds/background/paths/martial/root.c");
    addChild("/guilds/background/paths/martial/weapon-familiarity.c",
        "/guilds/background/paths/martial/root.c");
    addChild("/guilds/background/paths/martial/field-awareness.c",
        "/guilds/background/paths/martial/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/background/paths/martial/armor-training.c");
    addResearchElement("/guilds/background/paths/martial/formation-tactics.c");
    addResearchElement("/guilds/background/paths/martial/quick-reaction.c");

    addChild("/guilds/background/paths/martial/armor-training.c",
        "/guilds/background/paths/martial/drill-discipline.c");
    addChild("/guilds/background/paths/martial/formation-tactics.c",
        "/guilds/background/paths/martial/weapon-familiarity.c");
    // quick-reaction does not build off a first-level, so parent to root
    addChild("/guilds/background/paths/martial/quick-reaction.c",
        "/guilds/background/paths/martial/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/background/paths/martial/weapon-mastery.c");
    addResearchElement("/guilds/background/paths/martial/battlefield-command.c");
    addResearchElement("/guilds/background/paths/martial/unyielding.c");

    addChild("/guilds/background/paths/martial/weapon-mastery.c",
        "/guilds/background/paths/martial/armor-training.c");
    // battlefield-command does not build off a second-level, so parent to root
    addChild("/guilds/background/paths/martial/battlefield-command.c",
        "/guilds/background/paths/martial/root.c");
    addChild("/guilds/background/paths/martial/unyielding.c",
        "/guilds/background/paths/martial/quick-reaction.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/background/paths/martial/strategic-mind.c");
    addResearchElement("/guilds/background/paths/martial/iron-wall.c");
    addResearchElement("/guilds/background/paths/martial/relentless-advance.c");

    addChild("/guilds/background/paths/martial/strategic-mind.c",
        "/guilds/background/paths/martial/weapon-mastery.c");
    addChild("/guilds/background/paths/martial/iron-wall.c",
        "/guilds/background/paths/martial/unyielding.c");
    // relentless-advance does not build off a third-level, so parent to root
    addChild("/guilds/background/paths/martial/relentless-advance.c",
        "/guilds/background/paths/martial/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/background/paths/martial/marshal-of-war.c");
    addResearchElement("/guilds/background/paths/martial/unbreakable.c");
    addResearchElement("/guilds/background/paths/martial/legendary-veteran.c");

    addChild("/guilds/background/paths/martial/marshal-of-war.c",
        "/guilds/background/paths/martial/strategic-mind.c");
    // unbreakable does not build off a fourth-level, so parent to root
    addChild("/guilds/background/paths/martial/unbreakable.c",
        "/guilds/background/paths/martial/root.c");
    addChild("/guilds/background/paths/martial/legendary-veteran.c",
        "/guilds/background/paths/martial/relentless-advance.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("A Childhood of Structured Military Learning");
    Description("From an early age, you were drawn to the art of combat. Whether through "
        "formal training, militia service, or personal ambition, you learned the "
        "ways of weapons, tactics, and discipline. The martial path is for those "
        "who see conflict as a crucible for growth and a means to protect or assert "
        "their will.");
    Source("background");
    addResearchElement("/guilds/background/paths/martial/root.c");
    TreeRoot("/guilds/background/paths/martial/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
}
