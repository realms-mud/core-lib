//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tidal pool");
    addAlias("pool");
    addAlias("tide pool");
    addDescriptionTemplate("a shallow tidal pool between worn shore rocks");
    addItemTemplate("Shell fragments and strands of weed lie in "
        "the shallow pool. Its rocky edge is slick, and the "
        "marked path stays above it. It is scenery, not an "
        "implemented fishing or shellfish-harvesting service.");
    addNearDarkDescriptionTemplate("a faint shine among dark rocks");
    addLowLightDescriptionTemplate("a shallow pool at the shore");
    addDimLightDescriptionTemplate("a pool reflecting the surrounding rocks");
    addSomeLightDescriptionTemplate("a tidal pool containing shells and weed");
    addTimeOfDayDescription("dawn", ({ " reflecting the pale sky" }));
    addTimeOfDayDescription("morning", ({ " bright along its wet edges" }));
    addTimeOfDayDescription("noon", ({ " glinting between the rocks" }));
    addTimeOfDayDescription("afternoon", ({ " shaded by the shore stones" }));
    addTimeOfDayDescription("evening", ({ " catching the last sky colors" }));
    addTimeOfDayDescription("dusk", ({ " darkening with the sky" }));
    addTimeOfDayDescription("night", ({ " reflecting scattered points of light" }));
    addTimeOfDayDescription("midnight", ({ " still between the stones" }));
    addSeasonDescription("spring", ({ " edged with fresh weed" }));
    addSeasonDescription("summer", ({ " warmed along its shallow rim" }));
    addSeasonDescription("autumn", ({ " scattered with storm-carried shells" }));
    addSeasonDescription("winter", ({ " cold beneath the salt spray" }));
}
