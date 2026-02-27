//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sundial");
    addAlias("dial");
    addAlias("stone sundial");

    addAdjectives(({ "stone", "ornate", "weathered", "mossy", "ancient",
        "precise", "carved", "elegant", "old", "pedestal-mounted" }));

    addDescriptionTemplate("a ##Adjective## sundial on a stone pedestal");

    addItemTemplate(
        "The sundial sits atop a carved stone pedestal, its brass plate "
        "marked with carefully engraved hour lines. The gnomon casts a "
        "thin shadow across the face, and the brass has gone green with "
        "verdigris. Roman numerals ring the edge, their lines still sharp "
        "despite the years."
    );

    addSomeLightDescriptionTemplate(
        "a sundial stands on its pedestal, its gnomon casting a clear shadow"
    );
    addDimLightDescriptionTemplate(
        "a sundial on a pedestal is visible, though its shadow is faint"
    );
    addLowLightDescriptionTemplate(
        "a carved pedestal with something on top is barely visible"
    );
    addNearDarkDescriptionTemplate(
        "a stone pedestal is just barely discernible in the darkness"
    );
}
