//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("broken window");
    addAlias("window");
    addAlias("shattered window");

    addItemTemplate(
        "The window's glass is shattered, jagged shards clinging to the frame "
        "while others litter the sill. Cold drafts slip through the gaps, and "
        "the outside world is visible through the broken panes. "
        "##UseDescriptionSet##"
    );

    addNearDarkDescriptionTemplate(
        "the outline of a broken window is barely visible, the damage lost in "
        "the darkness"
    );
    addLowLightDescriptionTemplate(
        "a broken window is a dim rectangle, its shattered glass catching a "
        "faint glint"
    );
    addDimLightDescriptionTemplate(
        "a broken window lets in a pale, uneven glow through jagged gaps"
    );
    addSomeLightDescriptionTemplate(
        "soft daylight filters through the broken window, highlighting the "
        "jagged edges"
    );
    addDescriptionTemplate(
        "sunlight streams through the broken window, casting sharp patterns "
        "on the floor"
    );
    useExteriorLighting();
}
