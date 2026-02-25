//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cartographer interior");

    addItemTemplate(
        "The cartographer's shop is a quiet, scholarly space dominated by "
        "a massive drafting table tilted at a slight angle beneath a broad "
        "window. Partially finished maps are pinned to its surface, their "
        "coastlines drawn in fine ink and territories tinted with watercolor "
        "washes. Rolled charts and bound atlases fill cubbyholes along the "
        "walls, while framed maps of famous regions hang above them. A shelf "
        "holds the tools of the trade: compasses, straight-edges, dividers, "
        "bottles of India ink, and fine-pointed quills. The air carries the "
        "dry, pleasant smell of vellum and ink."
    );

    addNearDarkDescriptionTemplate(
        "the cartographer's shop is lost in shadow, the rolled charts in "
        "their cubbyholes barely distinguishable from the dark walls"
    );
    addLowLightDescriptionTemplate(
        "the cartographer's drafting table is a pale shape beneath the "
        "window, the framed maps on the walls just dark rectangles"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the drafting table and its pinned maps, and "
        "the outlines of the framed charts on the walls"
    );
    addSomeLightDescriptionTemplate(
        "the cartographer's shop is bright enough to read the labels on "
        "the maps and appreciate the fine detail of the coastlines"
    );
    addDescriptionTemplate(
        "light from the broad window illuminates the cartographer's shop, "
        "making the ink lines and watercolor washes vivid and precise"
    );
}
