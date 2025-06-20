//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("arrow slit");
    addAlias("arrow-slit");
    addAlias("loophole");
    addAlias("narrow window");

    addItemTemplate(
        "The arrow slit is a narrow vertical opening set deep into the thick "
        "stone wall. Its sides are splayed outward, allowing defenders to aim "
        "out while remaining protected. The stone around the slit is worn "
        "smooth by years of use."
    );

    addNearDarkDescriptionTemplate(
        "the outline of an arrow slit is barely visible, a thin shadow in the "
        "wall"
    );
    addLowLightDescriptionTemplate(
        "a narrow arrow slit is visible, letting in only the faintest glimmer "
        "of light"
    );
    addDimLightDescriptionTemplate(
        "a thin shaft of pale light enters through the arrow slit, barely "
        "illuminating the wall"
    );
    addSomeLightDescriptionTemplate(
        "a narrow beam of daylight shines through the arrow slit, casting a "
        "thin line across the floor"
    );
    addDescriptionTemplate(
        "sunlight streams through the arrow slit, creating a bright, narrow "
        "stripe on the opposite wall"
    );
    useExteriorLighting();
}
