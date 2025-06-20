//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("oriel window");
    addAlias("window");
    addAlias("bay window");

    addItemTemplate(
        "The oriel window projects outward from the wall, supported by ornate "
        "stone corbels. Its glass panes are set in a decorative wooden frame, "
        "offering a broad view of the world outside. Cushions line the sill, "
        "inviting one to sit and gaze."
    );

    addNearDarkDescriptionTemplate(
        "the outline of an oriel window is barely visible, its shape lost in "
        "the shadows"
    );
    addLowLightDescriptionTemplate(
        "a dim oriel window juts from the wall, its glass catching a faint "
        "gleam"
    );
    addDimLightDescriptionTemplate(
        "the oriel window lets in a pale glow, the outside world a blur of "
        "shapes"
    );
    addSomeLightDescriptionTemplate(
        "soft daylight filters through the oriel window, brightening the "
        "alcove"
    );
    addDescriptionTemplate(
        "sunlight streams through the oriel window, flooding the alcove with "
        "warmth and light"
    );
    useExteriorLighting();
}
