//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("general store");
    setFloorPlanType("wooden shop");

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
        " with a closed sign in the window looking in upon an unlit shop. There is "
        "a light coming from its second story" }));
    addTimeOfDayDescription("late night", ({
        " with a closed sign in the window looking in upon an unlit shop" }));
    addTimeOfDayDescription("midnight", ({
        " with a closed sign in the window looking in upon an unlit shop" }));
    addSeasonDescription("winter", ({ " that has a layer of snow sitting atop its sign and covering its awning" }));
    addSeasonDescription("spring", ({ " that has new springs of ivy just beginning to climb the building" }));
    addSeasonDescription("summer", ({ " that has ivy climbing high up its walls" }));
    addSeasonDescription("autumn", ({ " with ivy whose leaves are turning a deep red color still clinging to the walls" }));

    addDescriptionTemplate("a general store in a wooden building");
    addSourceOfLight(7, "default", "night");

    addNearDarkDescriptionTemplate("the silhouette of a building");
    addLowLightDescriptionTemplate("the silhouette of a two-story building");
    addDimLightDescriptionTemplate("a dark, possibly wood two-story building");
    addSomeLightDescriptionTemplate("a two-story wooden building");
}
