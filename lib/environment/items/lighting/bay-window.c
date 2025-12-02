//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bay window");
    addAlias("window");
    addAlias("oriel window");

    addItemTemplate(
        "The bay window projects outward from the wall, its glass panes set in "
        "a graceful arc. Cushions line the broad sill, inviting one to sit and "
        "gaze out. Sunlight or moonlight streams in, filling the alcove with "
        "light."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a bay window is barely visible, its shape lost in the "
        "shadows"
    );
    addLowLightDescriptionTemplate(
        "a bay window juts from the wall, its glass catching a faint gleam"
    );
    addDimLightDescriptionTemplate(
        "the bay window lets in a pale glow, the outside world a blur of shapes"
    );
    addSomeLightDescriptionTemplate(
        "soft daylight filters through the bay window, brightening the alcove"
    );
    addDescriptionTemplate(
        "sunlight streams through the bay window, flooding the alcove with "
        "warmth and light"
    );
    useExteriorLighting();
}
