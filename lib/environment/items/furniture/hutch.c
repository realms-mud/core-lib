//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hutch");
    addAlias("cabinet");
    addAlias("dresser");
    addAlias("wooden hutch");

    addAdjectives(({ "wooden", "broad", "carved", "old", "sturdy", "panelled",
        "plain", "functional", "tall", "well-made" }));

    addDescriptionTemplate("a ##Adjective## hutch with shelves and cabinets");

    addItemTemplate(
        "This hutch is a tall, broad cabinet with shelves above and cabinets "
        "below. The shelves are open for displaying dishes or pottery, while "
        "the lower cabinets are closed with wooden doors."
    );

    addSomeLightDescriptionTemplate(
        "a wooden hutch stands against the wall, its shelves lined with dishes"
    );
    addDimLightDescriptionTemplate(
        "a hutch is visible in the gloom, its outline tall and broad"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a hutch can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a hutch is present, but details are lost in "
        "the darkness"
    );
}
