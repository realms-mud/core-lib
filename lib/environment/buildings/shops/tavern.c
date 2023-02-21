//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tavern");
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
        ". A sign in the window states that it is open and a light invitingly shines out into the street from its windows" }));
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

    addDescriptionTemplate("a tavern in a two-story wooden building");
    addNearDarkDescriptionTemplate("the silhouette of a building");
    addLowLightDescriptionTemplate("the silhouette of a two-story building");
    addDimLightDescriptionTemplate("a dark, possibly wooden two-story building");
    addSomeLightDescriptionTemplate("a wooden two-story building");
}
