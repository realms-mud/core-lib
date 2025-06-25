//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/background/paths/learning/mental-refresh.c");
    addResearchElement("/guilds/background/paths/learning/curious-mind.c");
    addResearchElement("/guilds/background/paths/learning/attentive-listener.c");

    addChild("/guilds/background/paths/learning/mental-refresh.c",
        "/guilds/background/paths/learning/root.c");
    addChild("/guilds/background/paths/learning/curious-mind.c",
        "/guilds/background/paths/learning/root.c");
    addChild("/guilds/background/paths/learning/attentive-listener.c",
        "/guilds/background/paths/learning/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/background/paths/learning/clarifying-thought.c");
    addResearchElement("/guilds/background/paths/learning/quick-learner.c");
    addResearchElement("/guilds/background/paths/learning/keen-memory.c");

    addChild("/guilds/background/paths/learning/clarifying-thought.c",
        "/guilds/background/paths/learning/mental-refresh.c");
    addChild("/guilds/background/paths/learning/quick-learner.c",
        "/guilds/background/paths/learning/curious-mind.c");
    // keen-memory does not build off a first-level, so parent to root
    addChild("/guilds/background/paths/learning/keen-memory.c",
        "/guilds/background/paths/learning/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/background/paths/learning/mental-vigor.c");
    addResearchElement("/guilds/background/paths/learning/patient-study.c");
    addResearchElement("/guilds/background/paths/learning/analytical.c");

    addChild("/guilds/background/paths/learning/mental-vigor.c",
        "/guilds/background/paths/learning/clarifying-thought.c");
    // patient-study does not build off a second-level, so parent to root
    addChild("/guilds/background/paths/learning/patient-study.c",
        "/guilds/background/paths/learning/root.c");
    addChild("/guilds/background/paths/learning/analytical.c",
        "/guilds/background/paths/learning/keen-memory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/background/paths/learning/total-recall.c");
    addResearchElement("/guilds/background/paths/learning/encyclopedic.c");
    addResearchElement("/guilds/background/paths/learning/critical-thinking.c");

    addChild("/guilds/background/paths/learning/total-recall.c",
        "/guilds/background/paths/learning/mental-vigor.c");
    addChild("/guilds/background/paths/learning/encyclopedic.c",
        "/guilds/background/paths/learning/analytical.c");
    // critical-thinking does not build off a third-level, so parent to root
    addChild("/guilds/background/paths/learning/critical-thinking.c",
        "/guilds/background/paths/learning/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/background/paths/learning/genius.c");
    addResearchElement("/guilds/background/paths/learning/wise-counsel.c");
    addResearchElement("/guilds/background/paths/learning/innovator.c");

    addChild("/guilds/background/paths/learning/genius.c",
        "/guilds/background/paths/learning/total-recall.c");
    // wise-counsel does not build off a fourth-level, so parent to root
    addChild("/guilds/background/paths/learning/wise-counsel.c",
        "/guilds/background/paths/learning/root.c");
    addChild("/guilds/background/paths/learning/innovator.c",
        "/guilds/background/paths/learning/critical-thinking.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("A Studious Childhood");
    Description("Curiosity and a thirst for knowledge shaped your upbringing. You spent "
        "your time reading, studying, and seeking out new ideas—whether in a formal "
        "school, a mentor’s tutelage, or self-driven exploration. The learning path "
        "is for those who value intellect, wisdom, and the pursuit of understanding.");
    Source("background");
    addResearchElement("/guilds/background/paths/learning/root.c");
    TreeRoot("/guilds/background/paths/learning/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
}
