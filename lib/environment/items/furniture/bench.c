//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bench");
    addAlias("wooden bench");
    addAlias("long bench");
    addAlias("seat");

    addAdjectives(({ "wooden", "long", "plain", "old", "sturdy", "broad",
        "carved", "functional", "worn", "simple" }));

    addDescriptionTemplate("a ##Adjective## bench set along the wall");

    addItemTemplate(
        "This bench is made from sturdy wood, its long seat supported by thick "
        "legs. The surface is worn smooth by years of use, and the design is "
        "simple but functional."
    );

    addSomeLightDescriptionTemplate(
        "a wooden bench stands along the wall, its surface worn by use"
    );
    addDimLightDescriptionTemplate(
        "a bench is visible in the gloom, its outline long and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a bench can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a bench is present, but details are lost in "
        "the darkness"
    );
}
