//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("weapon rack");
    addAlias("rack");
    addAlias("arms rack");

    addAdjectives(({ "wooden", "sturdy", "well-stocked", "military", "organized" }));
    addDescriptionTemplate("a ##Adjective## weapons rack holding an array of arms");

    addItemTemplate(
        "The weapon rack is a sturdy wooden frame, fitted with pegs and slots "
        "for holding swords, spears, and axes. Several weapons are neatly "
        "arranged, their blades gleaming in the light. The wood is scarred "
        "from years of use, and the rack stands ready for the next round of "
        "training."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a weapon rack is barely visible, with only the faintest "
        "glint from metal blades"
    );
    addLowLightDescriptionTemplate(
        "a weapon rack stands in the gloom, its weapons little more than "
        "shadows"
    );
    addDimLightDescriptionTemplate(
        "the weapon rack is faintly illuminated, the shapes of swords and "
        "spears just visible"
    );
    addSomeLightDescriptionTemplate(
        "the weapon rack is clearly visible, with several weapons arranged "
        "neatly on its pegs"
    );
    addDescriptionTemplate(
        "sunlight shines on the weapon rack, making the blades and hafts gleam"
    );
}
