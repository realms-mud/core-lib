//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("window");

    addItemTemplate(
        "The window is set into a thick stone wall, its glass panes slightly "
        "warped and flecked with age. A wooden frame, weathered by years of "
        "sun and rain, holds the glass in place. Faint drafts slip through "
        "the cracks, and the sill is cool to the touch."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a window is barely visible, with only the faintest "
        "trace of light seeping through the glass"
    );
    addLowLightDescriptionTemplate(
        "a window is visible as a dim rectangle, its glass catching a hint "
        "of starlight or the distant moon"
    );
    addDimLightDescriptionTemplate(
        "a window lets in a pale, silvery glow, the outside world little more "
        "than shifting shadows"
    );
    addSomeLightDescriptionTemplate(
        "a window admits soft daylight, illuminating dust motes that drift "
        "through the air"
    );
    addDescriptionTemplate(
        "sunlight streams through the window, casting bright patterns on the "
        "floor and walls"
    );
    useExteriorLighting();
}
