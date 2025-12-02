//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("boarded window");
    addAlias("window");
    addAlias("boarded-up window");

    addItemTemplate(
        "The window has been hastily boarded up, rough planks nailed across "
        "the frame. Only thin slivers of light manage to slip through the "
        "gaps between the boards."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a boarded window is barely visible, the boards "
        "blocking nearly all light"
    );
    addLowLightDescriptionTemplate(
        "a boarded window is a dim rectangle, with only the faintest glimmer "
        "of light between the planks"
    );
    addDimLightDescriptionTemplate(
        "a boarded window lets in a pale, uneven glow through narrow gaps"
    );
    addSomeLightDescriptionTemplate(
        "soft daylight filters through the boarded window, striping the room "
        "with thin lines of light"
    );
    addDescriptionTemplate(
        "sunlight streams through the boarded window, casting sharp, narrow "
        "beams across the floor"
    );
    useExteriorLighting();
}
