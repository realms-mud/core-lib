//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("drill field marker");
    addAlias("marker");
    addAlias("field marker");

    addItemTemplate(
        "The drill field marker is a brightly painted post driven into the "
        "ground. It marks the boundaries and positions for military drills and "
        "formations. "
    );

    addNearDarkDescriptionTemplate(
        "the outline of a drill field marker is barely visible, its color lost "
        "in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a drill field marker stands in the shadows, its paint just visible"
    );
    addDimLightDescriptionTemplate(
        "the drill field marker is faintly illuminated, its position apparent"
    );
    addSomeLightDescriptionTemplate(
        "the drill field marker is clearly visible, its bright paint standing "
        "out"
    );
    addAdjectives(({ "painted", "wooden", "upright", "training", "field" }));
    addDescriptionTemplate("a ##Adjective## drill field marker set in the ground");
}
