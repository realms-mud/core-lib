//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wood floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("wood");
    addAlias("wooden");

    addAdjectives(({ "of polished hardwood gleaming in the light",
        "with a warm honey-colored finish",
        "that creaks softly underfoot",
        "showing the natural grain of the timber",
        "with subtle variations in wood color and pattern",
        "that has been worn smooth by countless footsteps",
        "with small gaps between some of the boards",
        "that gives slightly under pressure" }));

    addDescriptionTemplate("the floor is made of wood "
        "##Adjective##. The timber provides warmth and comfort "
        "beneath your feet");
    addSomeLightDescriptionTemplate("the floor is made of wood "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor appears to be made of wood. "
        "It feels warm and slightly yielding underfoot");
    addLowLightDescriptionTemplate("the floor is constructed of wooden "
        "boards. Faint lines mark the joints between timbers");
    addDimLightDescriptionTemplate("the floor is made of wood boards. "
        "The timber shows the patina of age and use");

    addItemTemplate("The floor is constructed of carefully fitted wooden "
        "boards, each piece selected for its quality and grain. The wood "
        "has been finished to a smooth surface that feels warm underfoot, "
        "though some boards show signs of age with small gaps and gentle "
        "warping from years of use.");
}
