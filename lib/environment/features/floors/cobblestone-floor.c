//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cobblestone floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("cobblestone");
    addAlias("cobblestones");
    addAlias("stones");

    addAdjectives(({ "of rounded stones fitted tightly together",
        "with smooth river rocks creating an uneven surface",
        "that feels bumpy and irregular underfoot",
        "showing wear patterns from countless footsteps",
        "with mortar filling the gaps between stones",
        "made from water-smoothed granite and limestone",
        "that creates interesting patterns of light and shadow",
        "with some stones loose or missing from their settings" }));

    addDescriptionTemplate("the floor is paved with cobblestones "
        "##Adjective##. The rounded stones create a rustic "
        "and durable surface");
    addSomeLightDescriptionTemplate("the floor is paved with cobblestones "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor consists of rounded stones. "
        "The uneven surface is apparent underfoot");
    addLowLightDescriptionTemplate("the floor is made of fitted stones. "
        "Their rounded shapes create an irregular pattern");
    addDimLightDescriptionTemplate("the floor is paved with cobblestones. "
        "The stones show the polish of long use");

    addItemTemplate("The floor is constructed of cobblestones, rounded "
        "stones that have been fitted together to create a durable paving. "
        "Each stone has been naturally smoothed by water or wear, and they "
        "interlock to form an uneven but stable surface that has withstood "
        "years of traffic while maintaining its rustic character.");
}
