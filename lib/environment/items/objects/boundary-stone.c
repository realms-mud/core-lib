//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("boundary stone");
    addAlias("stone");
    addAlias("boundary");
    addDescriptionTemplate("a carved boundary stone beside the path");
    addItemTemplate("A deeply cut line distinguishes common ground "
        "from managed land beyond it. Moss fills the shallowest "
        "marks without obscuring the principal boundary. A posted "
        "survey can be checked with investigate boundary stone.");
    addNearDarkDescriptionTemplate("a squat shape beside the path");
    addLowLightDescriptionTemplate("a low standing stone");
    addDimLightDescriptionTemplate("a stone bearing weathered carvings");
    addSomeLightDescriptionTemplate("a boundary stone with a deeply carved line");
    addTimeOfDayDescription("dawn", ({ " dark with dew" }));
    addTimeOfDayDescription("morning", ({ " clear beside the worn path" }));
    addTimeOfDayDescription("noon", ({ " casting a short shadow" }));
    addTimeOfDayDescription("afternoon", ({ " shaded along its carved face" }));
    addTimeOfDayDescription("evening", ({ " standing against the low light" }));
    addTimeOfDayDescription("dusk", ({ " fading beside the track" }));
    addTimeOfDayDescription("night", ({ " a dark landmark at the path edge" }));
    addTimeOfDayDescription("midnight", ({ " still beneath the trees" }));
    addSeasonDescription("spring", ({ " with wet moss around its base" }));
    addSeasonDescription("summer", ({ " surrounded by short grass" }));
    addSeasonDescription("autumn", ({ " with fallen leaves caught against it" }));
    addSeasonDescription("winter", ({ " frosted across its carved face" }));
}
