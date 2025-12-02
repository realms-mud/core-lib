//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("small barricade");
    addAlias("barricade");
    addAlias("makeshift barrier");

    addAdjectives(({ "makeshift", "wooden", "low", "defensive", "hastily-built" }));
    addDescriptionTemplate("a ##Adjective## small barricade blocking the path");

    addItemTemplate(
        "The small barricade is constructed from wooden planks, barrels, and "
        "crates, hastily arranged to provide cover. Gaps between the boards "
        "offer limited protection, and the structure bears the marks of recent "
        "battle."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a small barricade is barely visible, its shape lost in "
        "the gloom"
    );
    addLowLightDescriptionTemplate(
        "a small barricade stands in the shadows, its construction hard to "
        "discern"
    );
    addDimLightDescriptionTemplate(
        "the small barricade is faintly illuminated, its planks and barrels "
        "just visible"
    );
    addSomeLightDescriptionTemplate(
        "the small barricade is clearly visible, its makeshift nature apparent"
    );
    addDescriptionTemplate(
        "sunlight shines on the small barricade, highlighting every gap and "
        "rough edge"
    );
}
