//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("shield rack");
    addAlias("rack");
    addAlias("shield stand");

    addAdjectives(({ "wooden", "sturdy", "well-stocked", "military", "organized" }));
    addDescriptionTemplate("a ##Adjective## shield rack holding several shields");

    addItemTemplate(
        "The shield rack is a heavy wooden frame, fitted with pegs for holding "
        "shields of various sizes. Several shields are displayed, their "
        "surfaces bearing the marks of battle. The rack stands ready for "
        "training or defense."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a shield rack is barely visible, with only the faintest "
        "glint from metal rims"
    );
    addLowLightDescriptionTemplate(
        "a shield rack stands in the gloom, its shields little more than "
        "shadows"
    );
    addDimLightDescriptionTemplate(
        "the shield rack is faintly illuminated, the shapes of shields just "
        "visible"
    );
    addSomeLightDescriptionTemplate(
        "the shield rack is clearly visible, with several shields arranged "
        "neatly on its pegs"
    );
    addDescriptionTemplate(
        "sunlight shines on the shield rack, making the painted surfaces and "
        "metal rims gleam"
    );
}
