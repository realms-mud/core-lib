//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    addAdjectives(({ "that ascends in a direct line",
        "with evenly spaced wooden steps",
        "that has been worn smooth by countless footfalls",
        "with a simple wooden handrail along one side",
        "that creaks softly under weight",
        "made of sturdy oak planks",
        "with steps that sag slightly in the middle",
        "that leads directly to the upper floor" }));

    addDescriptionTemplate("a straight staircase ##Adjective## "
        "provides access to other level");
    addSomeLightDescriptionTemplate("a straight staircase ##Adjective## "
        "leads upward in clear view");
    addNearDarkDescriptionTemplate("a staircase can be dimly perceived "
        "leading upward in a straight line");
    addLowLightDescriptionTemplate("a straight staircase "
        "with simple construction leads upward");
    addDimLightDescriptionTemplate("a straight staircase ##Adjective## "
        "ascends to the floor above");

    addItemTemplate("The straight staircase consists of evenly spaced "
        "steps that climb directly upward without turns or curves. "
        "A simple handrail provides support along one side, while the "
        "steps themselves show the wear of regular use. The construction "
        "is practical and efficient, designed for easy daily access "
        "between floors.");
}
