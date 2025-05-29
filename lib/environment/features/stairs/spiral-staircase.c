//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("spiral staircase");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("staircase");
    addAlias("stair");
    addAlias("spiral");

    addAdjectives(({ "that winds tightly upward",
        "made of worn stone steps",
        "with steps that have been polished smooth from use",
        "carved directly into the stone of the tower wall",
        "with an elaborate stone banister",
        "that creaks slightly when weight is placed upon it",
        "with steps that are narrow at the center and widen toward the wall",
        "that climbs steeply through the tower interior" }));

    addDescriptionTemplate("a spiral staircase ##Adjective## "
        "provides access to the upper levels of the tower. The steps are "
        "worn in the center from years of use");
    addSomeLightDescriptionTemplate("a spiral staircase ##Adjective## "
        "winds upward, partially hidden in shadow");
    addNearDarkDescriptionTemplate("a shadowy spiral staircase "
        "can be seen leading upward through the darkness");
    addLowLightDescriptionTemplate("a spiral staircase "
        "with worn steps leads upward, faintly visible in the dim light");
    addDimLightDescriptionTemplate("a spiral staircase ##Adjective## "
        "leads upward, its details shrouded in the dim light");

    // Staircase itself doesn't emit light but might reflect ambient light
    addSourceOfLight(1);

    addItemTemplate("The spiral staircase winds tightly around "
        "a central stone column, with steps that narrow as they approach "
        "the center. Years of use have left the stones worn smooth in the middle "
        "of each step. Iron brackets along the wall once held torches "
        "to light the way up");
}
