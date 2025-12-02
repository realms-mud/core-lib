//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("curved staircase");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("staircase");
    addAlias("stair");
    addAlias("curved");

    addAdjectives(({ "that follows a graceful arc between levels",
        "with steps that widen toward the outer edge",
        "carved to match the building's circular tower",
        "that curves gently around supporting pillars",
        "built with elegant mathematical precision",
        "showing the skill of master stonemasons",
        "that flows between floors in a graceful line",
        "with balustrades that echo the curve" }));

    addDescriptionTemplate("a curved staircase ##Adjective## "
        "follows the contours of the architecture");
    addSomeLightDescriptionTemplate("a curved staircase ##Adjective## "
        "flows between levels in an elegant arc");
    addNearDarkDescriptionTemplate("a curving staircase can be felt "
        "following an arc through the darkness");
    addLowLightDescriptionTemplate("a curved staircase "
        "with flowing lines connects the floors");
    addDimLightDescriptionTemplate("a curved staircase ##Adjective## "
        "arcs gracefully between levels");
    addSourceOfLight(1);

    addItemTemplate("The curved staircase represents sophisticated "
        "architectural planning, with each step carefully calculated to "
        "maintain consistent proportions while following a gentle arc. "
        "The outer edge of each step is wider than the inner, accommodating "
        "the curve while providing stable footing. Master craftsmen shaped "
        "both steps and balustrades to flow as a unified whole, creating "
        "a sense of movement frozen in stone.");
}
