//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("straight staircase");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("staircase");
    addAlias("stair");
    addAlias("steps");

    addAdjectives(({ "that runs in a direct line between levels",
        "with evenly spaced wooden steps",
        "that has been worn smooth by countless footfalls",
        "with a simple wooden handrail along one side",
        "that creaks softly under weight",
        "made of sturdy oak planks",
        "with steps that sag slightly in the middle",
        "that connects the floors directly" }));

    addDescriptionTemplate("a straight staircase ##Adjective## "
        "provides access between levels");
    addSomeLightDescriptionTemplate("a straight staircase ##Adjective## "
        "connects the floors in clear view");
    addNearDarkDescriptionTemplate("a staircase can be dimly perceived "
        "running in a straight line");
    addLowLightDescriptionTemplate("a straight staircase "
        "with simple construction connects the levels");
    addDimLightDescriptionTemplate("a straight staircase ##Adjective## "
        "links the different floors");

    addItemTemplate("The straight staircase consists of evenly spaced "
        "steps that connect floors directly without turns or curves. "
        "A simple handrail provides support along one side, while the "
        "steps themselves show the wear of regular use. The construction "
        "is practical and efficient, designed for easy daily access "
        "between different levels.");
}
