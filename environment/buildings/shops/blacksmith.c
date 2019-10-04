//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("blacksmith");
    InteriorType("limestone building");
    setFloorPlanType("shop");

    addTimeOfDayDescription("dawn", ({
        ". It has a closed sign in the window. A light is shining out from the windows"
    }));
    addTimeOfDayDescription("morning", ({ ". The two massive doors are open, revealing the smithy" }));
    addTimeOfDayDescription("noon", ({ ". The two massive doors are open, revealing the smithy" }));
    addTimeOfDayDescription("afternoon", ({
        ". The two massive doors are open, revealing the smithy" }));
    addTimeOfDayDescription("evening", ({
        ". The two massive doors are open; the light flooding the area" }));
    addTimeOfDayDescription("dusk", ({
        ". A sign in the window states that it is closed" }));
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

    addSourceOfLight(7, "default", "night");

    addDescriptionTemplate("a blacksmith's shop made of limestone with two large sliding doors");
    addNearDarkDescriptionTemplate("the silhouette of a building");
    addLowLightDescriptionTemplate("the silhouette of a two-story building");
    addDimLightDescriptionTemplate("a dark, possibly stone two-story building");
    addSomeLightDescriptionTemplate("a two-story limestone building");
}
