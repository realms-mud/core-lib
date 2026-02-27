//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";
/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("apothecary interior");

    addItemTemplate(
        "The apothecary is a cluttered but carefully organized space. Shelves "
        "line every wall from floor to ceiling, packed with glass vials, "
        "ceramic jars, and small wooden boxes, each neatly labeled in a "
        "spidery hand. Bundles of dried herbs hang from the rafters, filling "
        "the air with a complex blend of lavender, sage, and something faintly "
        "astringent. A heavy oak workbench in the center holds a mortar and "
        "pestle, a set of brass scales, and several open books. A curtain at "
        "the back conceals what appears to be a private preparation room."
    );

    addNearDarkDescriptionTemplate(
        "the apothecary is nearly black, with only the faintest glint off "
        "glass bottles hinting at the shelves that crowd the walls"
    );
    addLowLightDescriptionTemplate(
        "the apothecary shelves are dim outlines, the shapes of jars and "
        "vials just barely distinguishable from the shadows"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the rows of labeled jars and the bundles of "
        "dried herbs suspended from the apothecary's rafters"
    );
    addSomeLightDescriptionTemplate(
        "the apothecary is bright enough to read the labels on the jars "
        "and make out the titles of the open books on the workbench"
    );
    addDescriptionTemplate(
        "light fills the apothecary, illuminating the colorful array of "
        "tinctures, dried herbs, and neatly arranged remedies"
    );
}
