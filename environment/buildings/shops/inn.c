//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("inn");
    setFloorPlanType("inn");

    addTimeOfDayDescription("dawn", ({
        ". It has a closed sign in the window. A light is shining out from the windows"
    }));
    addTimeOfDayDescription("morning", ({ ". There is an open sign in the window" }));
    addTimeOfDayDescription("noon", ({ ". There is an open sign in the window" }));
    addTimeOfDayDescription("afternoon", ({
        ". There is an open sign in the window" }));
    addTimeOfDayDescription("evening", ({
        ". The open sign in the window is lit by the waning day's light" }));
    addTimeOfDayDescription("dusk", ({
        ". A sign in the window states that it is open and a light invitingly shines out into the street from its window" }));
    addTimeOfDayDescription("night", ({
        ". A sign in the window states that it is open and a light invitingly shines out into the street from its windows" }));
    addTimeOfDayDescription("late night", ({
        " with a closed sign in the window looking in upon an unlit building" }));
    addTimeOfDayDescription("midnight", ({
        ". A sign in the window states that it is open and a light invitingly shines out into the street from its windows" }));

    addSourceOfLight(7, "default", "night");
    addSourceOfLight(7, "default", "midnight");

    addSeasonDescription("winter", ({ " that has a layer of snow sitting atop its sign and covering its awning" }));
    addSeasonDescription("spring", ({ " that has new springs of ivy just beginning to climb the building" }));
    addSeasonDescription("summer", ({ " that has ivy climbing high up its walls" }));
    addSeasonDescription("autumn", ({ " with ivy whose leaves are turning a deep red color still clinging to the walls" }));

    addDescriptionTemplate("an inn in a large brick and wood building");
    addNearDarkDescriptionTemplate("the silhouette of a large building");
    addLowLightDescriptionTemplate("the silhouette of a large two-story building");
    addDimLightDescriptionTemplate("a dark, possibly brick two-story building");
    addSomeLightDescriptionTemplate("a large, brick two-story building");
}
