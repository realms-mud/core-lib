//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("shuttered window");
    addAlias("window");
    addAlias("shutters");

    addItemTemplate(
        "The window is fitted with sturdy wooden shutters, their surfaces worn "
        "smooth by years of use. Iron hinges and a simple latch hold them in "
        "place, and the wood bears the marks of sun and rain."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a shuttered window is barely visible, the shutters "
        "closed tightly against the night"
    );
    addLowLightDescriptionTemplate(
        "a shuttered window is a dim rectangle, its wooden panels blocking "
        "most of the outside light"
    );
    addDimLightDescriptionTemplate(
        "a shuttered window lets in only a faint glow through cracks in the "
        "wood"
    );
    addSomeLightDescriptionTemplate(
        "a shuttered window admits slivers of daylight through gaps in the "
        "panels"
    );
    addDescriptionTemplate(
        "sunlight peeks through the shuttered window, casting narrow beams "
        "across the room"
    );
    useExteriorLighting();
}
