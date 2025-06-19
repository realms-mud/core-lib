//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("livery cupboard");
    addAlias("cupboard");
    addAlias("wooden livery cupboard");
    addAlias("open cupboard");

    addAdjectives(({ "wooden", "open", "broad", "carved", "old", "sturdy",
        "plain", "functional", "panelled", "tall" }));

    addDescriptionTemplate("a ##Adjective## livery cupboard with open shelves");

    addItemTemplate(
        "This livery cupboard is made from wood, with open shelves for storing "
        "food, drink, or tableware. The frame is sturdy, and the shelves are "
        "broad and deep."
    );

    addSomeLightDescriptionTemplate(
        "a wooden livery cupboard stands against the wall, its shelves open"
    );
    addDimLightDescriptionTemplate(
        "a livery cupboard is visible in the gloom, its outline broad and open"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a livery cupboard can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a livery cupboard is present, but details are lost "
        "in the darkness"
    );
}
