//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mystical stairway");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("stairway");
    addAlias("stair");
    addAlias("mystical");
    addAlias("ethereal");
    addAlias("otherworldly");

    addAdjectives(({ "woven from solidified moonbeams and starlight",
        "that exists only when someone believes in them",
        "carved from the dreams of sleeping gods",
        "made of crystallized music from celestial spheres",
        "that phase between multiple planes of existence",
        "constructed from the tears of weeping angels",
        "formed from the echo of the first spoken word",
        "that bend space and time with every step" }));

    addDescriptionTemplate("a mystical stairway ##Adjective## "
        "transcends the boundaries of mortal comprehension");
    addSomeLightDescriptionTemplate("a mystical stairway ##Adjective## "
        "radiates pure supernatural essence");
    addNearDarkDescriptionTemplate("an otherworldly stairway "
        "exists as much in dreams as in reality");
    addLowLightDescriptionTemplate("a transcendent stairway "
        "glows with the light of dying stars");
    addDimLightDescriptionTemplate("a mystical stairway ##Adjective## "
        "defies all natural law and reason");
    addSourceOfLight(6);

    addItemTemplate("The mystical stairway exists at the intersection of "
        "reality and impossibility, a structure that should not be yet "
        "undeniably is. Each step appears to be cut from a different "
        "gemstone that has never existed - colors that have no names "
        "shift and flow like liquid light. The stairway itself breathes, "
        "expanding and contracting with a rhythm that matches the heartbeat "
        "of the universe. Those who dare to climb it report experiencing "
        "visions of their past, future, and alternate selves, while the "
        "air around the stairs tastes of copper and eternity. Some steps "
        "lead upward, others downward, and a few seem to lead sideways "
        "into dimensions that mortal minds cannot grasp.");
}
