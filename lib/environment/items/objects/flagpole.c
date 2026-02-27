//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("flagpole");
    addAlias("pole");
    addAlias("banner pole");
    addAlias("standard");

    addAdjectives(({ "tall", "wooden", "iron-capped", "weathered",
        "sturdy", "proud", "straight", "old", "paint-peeled", "stout" }));

    addDescriptionTemplate("a ##Adjective## flagpole flying a banner");

    addItemTemplate(
        "The flagpole is a tall, straight timber capped with an iron finial. "
        "A banner hangs from a crossbar near the top, its fabric faded by "
        "sun and snapped ragged by the wind. A rope and cleat system allows "
        "the banner to be raised and lowered."
    );

    addSomeLightDescriptionTemplate(
        "a flagpole stands tall, its banner fluttering in the breeze"
    );
    addDimLightDescriptionTemplate(
        "a tall pole is visible, something fluttering at its top"
    );
    addLowLightDescriptionTemplate(
        "a tall vertical shape rises above the roofline"
    );
    addNearDarkDescriptionTemplate(
        "the snap of fabric in the wind suggests a banner overhead"
    );
}
