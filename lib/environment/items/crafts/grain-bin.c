//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("grain bin");
    addAlias("storage bin");
    addAlias("grain box");

    addAdjectives(({ "wooden", "large", "lidded", "dusty", "full",
        "sturdy", "mouse-gnawed", "old", "heavy", "well-sealed" }));

    addDescriptionTemplate("a ##Adjective## grain bin against the wall");

    addItemTemplate(
        "The grain bin is a large wooden box with a hinged lid, built to "
        "keep stores dry and safe from vermin. Despite its tight "
        "construction, a fine dust of flour coats the outside, and tiny "
        "gnaw marks along the base show that mice have tested its defenses."
    );

    addSomeLightDescriptionTemplate(
        "a large grain bin stands against the wall, flour dust on its lid"
    );
    addDimLightDescriptionTemplate(
        "a large lidded bin is visible against the wall"
    );
    addLowLightDescriptionTemplate(
        "a large boxy shape stands against the wall"
    );
    addNearDarkDescriptionTemplate(
        "the dry scent of stored grain comes from a large container nearby"
    );
}
