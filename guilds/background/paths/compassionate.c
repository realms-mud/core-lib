//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/background/paths/compassionate/gentle-touch.c");
    addResearchElement("/guilds/background/paths/compassionate/empathic-sense.c");
    addResearchElement("/guilds/background/paths/compassionate/calming-presence.c");

    addChild("/guilds/background/paths/compassionate/gentle-touch.c",
        "/guilds/background/paths/compassionate/root.c");
    addChild("/guilds/background/paths/compassionate/empathic-sense.c",
        "/guilds/background/paths/compassionate/root.c");
    addChild("/guilds/background/paths/compassionate/calming-presence.c",
        "/guilds/background/paths/compassionate/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/background/paths/compassionate/healers-instinct.c");
    addResearchElement("/guilds/background/paths/compassionate/understanding-heart.c");
    addResearchElement("/guilds/background/paths/compassionate/protective-nature.c");

    addChild("/guilds/background/paths/compassionate/healers-instinct.c",
        "/guilds/background/paths/compassionate/gentle-touch.c");
    addChild("/guilds/background/paths/compassionate/understanding-heart.c",
        "/guilds/background/paths/compassionate/empathic-sense.c");

    addChild("/guilds/background/paths/compassionate/protective-nature.c",
        "/guilds/background/paths/compassionate/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/background/paths/compassionate/shared-burden.c");
    addResearchElement("/guilds/background/paths/compassionate/merciful-soul.c");
    addResearchElement("/guilds/background/paths/compassionate/nurturer.c");

    addChild("/guilds/background/paths/compassionate/shared-burden.c",
        "/guilds/background/paths/compassionate/healers-instinct.c");

    addChild("/guilds/background/paths/compassionate/merciful-soul.c",
        "/guilds/background/paths/compassionate/root.c");
    addChild("/guilds/background/paths/compassionate/nurturer.c",
        "/guilds/background/paths/compassionate/protective-nature.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/background/paths/compassionate/selfless-devotion.c");
    addResearchElement("/guilds/background/paths/compassionate/life-ward.c");
    addResearchElement("/guilds/background/paths/compassionate/beacon-of-hope.c");

    addChild("/guilds/background/paths/compassionate/selfless-devotion.c",
        "/guilds/background/paths/compassionate/shared-burden.c");
    addChild("/guilds/background/paths/compassionate/life-ward.c",
        "/guilds/background/paths/compassionate/nurturer.c");
 
    addChild("/guilds/background/paths/compassionate/beacon-of-hope.c",
        "/guilds/background/paths/compassionate/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/background/paths/compassionate/saint.c");
    addResearchElement("/guilds/background/paths/compassionate/martyrs-resolve.c");
    addResearchElement("/guilds/background/paths/compassionate/healers-legacy.c");

    addChild("/guilds/background/paths/compassionate/saint.c",
        "/guilds/background/paths/compassionate/selfless-devotion.c");
 
    addChild("/guilds/background/paths/compassionate/martyrs-resolve.c",
        "/guilds/background/paths/compassionate/root.c");
    addChild("/guilds/background/paths/compassionate/healers-legacy.c",
        "/guilds/background/paths/compassionate/beacon-of-hope.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("A Compassionate Soul");
    Description("Your formative years were spent caring for others - tending the sick, "
        "comforting the grieving, or protecting the vulnerable. Whether through a "
        "healer's tutelage, family duty, or natural empathy, you learned that true "
        "strength lies in lifting others up. The compassionate path is for those who "
        "find purpose in easing suffering and believe that kindness is never weakness.");
    Source("background");
    addResearchElement("/guilds/background/paths/compassionate/root.c");
    TreeRoot("/guilds/background/paths/compassionate/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
}
