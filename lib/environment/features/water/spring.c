//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rock spring");
    addAlias("spring");
    addAlias("clear spring");
    addDescriptionTemplate("a spring welling from a shaded rock lip");
    addItemTemplate("Water wells from a seam in the rock and runs "
        "over a shallow stone basin. The ground immediately "
        "around it is kept clear. A water inquiry can investigate "
        "the clear spring without disturbing its source.");
    addNearDarkDescriptionTemplate("a faint glimmer beneath the rock");
    addLowLightDescriptionTemplate("water moving beneath a rock lip");
    addDimLightDescriptionTemplate("a spring spilling into a shallow basin");
    addSomeLightDescriptionTemplate("clear spring water over a stone basin");
    addTimeOfDayDescription("dawn", ({ " veiled in faint mist" }));
    addTimeOfDayDescription("morning", ({ " catching stray light on its ripples" }));
    addTimeOfDayDescription("noon", ({ " cool beneath the shaded lip" }));
    addTimeOfDayDescription("afternoon", ({ " trickling across the basin" }));
    addTimeOfDayDescription("evening", ({ " darkening beneath the rock" }));
    addTimeOfDayDescription("dusk", ({ " audible in the falling light" }));
    addTimeOfDayDescription("night", ({ " murmuring under the rock" }));
    addTimeOfDayDescription("midnight", ({ " flowing through the quiet" }));
    addSeasonDescription("spring", ({ " fuller after the rains" }));
    addSeasonDescription("summer", ({ " cool despite the warm air" }));
    addSeasonDescription("autumn", ({ " edged with fallen leaves" }));
    addSeasonDescription("winter", ({ " flowing beneath an icy basin rim" }));
}
