//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("city hall");
    setFloorPlanType("administrative building");

    addDescriptionTemplate("a large granite building with the carved words, "
        "`City Hall' above the massive double doors");
    addNearDarkDescriptionTemplate("the silhouette of a large building");
    addLowLightDescriptionTemplate("the silhouette of a large, three-story building");
    addDimLightDescriptionTemplate("a large and dark - possibly stone - building");
    addSomeLightDescriptionTemplate("a large, three-story, granite building");

    addSeasonDescription("winter", ({ " that has a dusting of snow sitting atop it" }));

    addTimeOfDayDescription("dawn", ({ ". Light is shining out from the windows" }));
    addTimeOfDayDescription("morning", ({ ". Activity can be seen through the windows" }));
    addTimeOfDayDescription("noon", ({ ". Activity can be seen through the windows" }));
    addTimeOfDayDescription("afternoon", ({
        ". Activity can be seen through the windows" }));
    addTimeOfDayDescription("evening", ({
        ". Light can be seen coming out of its windows" }));
    addTimeOfDayDescription("dusk", ({
        ". No light can be seen coming from its windows" }));
}
