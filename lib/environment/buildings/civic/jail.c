//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("jail");
    setFloorPlanType("jail");

    addDescriptionTemplate("a sturdy brick jail with metal bars reinforcing the windows");

    addNearDarkDescriptionTemplate("the silhouette of a building");
    addLowLightDescriptionTemplate("the silhouette of a sturdy building building");
    addDimLightDescriptionTemplate("a large and dark - possibly brick - building");
    addSomeLightDescriptionTemplate("a sturdy brick building");

    addSeasonDescription("winter", ({ " that has a dusting of snow sitting atop it" }));

    addTimeOfDayDescription("dawn", ({ ". Light is shining out from the windows" }));
    addTimeOfDayDescription("morning", ({ ". Activity can be seen through the windows" }));
    addTimeOfDayDescription("noon", ({ ". Activity can be seen through the windows" }));
    addTimeOfDayDescription("afternoon", ({
        ". Activity can be seen through the windows" }));
    addTimeOfDayDescription("evening", ({
        ". Light can be seen coming out of its windows" }));
    addTimeOfDayDescription("dusk", ({
        ". Light can be seen coming out of its windows" }));
    addTimeOfDayDescription("night", ({
        ". Light can be seen coming out of its windows" }));
    addTimeOfDayDescription("midnight", ({
        ". Light can be seen coming out of its windows" }));
    addTimeOfDayDescription("late night", ({
        ". Light can be seen coming out of its windows" }));
    addSourceOfLight(7);
}
