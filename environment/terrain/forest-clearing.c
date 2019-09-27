//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("forest clearing");
    addAdjectives(({ "clearing in a sprawling forest",
        "clearing in a forest thick with mighty trees",
        "clearing in a grove of many trees",
        "clearing in a towering forest",
        "clearing in a lush forest",
        "clearing in a serene forest"
    }));
    addTimeOfDayDescription("dawn", ({ 
        ", the sinuous mists of the early morning caressing their limbs",
        " just waking with the first light of dawn",
        " wrapped in the new morn's light",
        " shedding the shadows of its night-time slumber"
    }));
    addTimeOfDayDescription("morning", ({
        " lit from rays of light piercing through the canopy",
        " awash with the tender glow of the morning "
    }));
    addTimeOfDayDescription("noon", ({ 
        " bathed in the mid-day light",
        " lit by golden seams of light coming through the canopy"
    }));
    addTimeOfDayDescription("afternoon", ({
        " lit by the fullness of the day" }));
    addTimeOfDayDescription("evening", ({ 
        " still lit by the waning day's light" }));
    addTimeOfDayDescription("dusk", ({ 
        ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ 
        " outlined in the dark" }));
    addTimeOfDayDescription("late night", ({ 
        " outlined in the dark" }));
    addTimeOfDayDescription("midnight", ({ 
        " scarcely outlined in eery black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow" }));
    addSeasonDescription("spring", ({ "; the trees' leaves just beginning to bud" }));
    addSeasonDescription("summer", ({ "; the trees laden with leaves" }));
    addSeasonDescription("autumn", ({ ". The ground is carpeted with fallen leaves of red, yellow, and orange" }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a very dark clearing in a forest");
    addLowLightDescriptionTemplate("a barely-lit clearing in a forest");
    addDimLightDescriptionTemplate("a dimly-lit clearing in a forest");
    addSomeLightDescriptionTemplate("a clearing in a forest");
}
