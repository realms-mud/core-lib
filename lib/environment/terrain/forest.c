//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("forest");
    addAdjectives(({ "sprawling forest",
        "forest thick with mighty trees; knotted arms rising upward",
        "grove of many trees",
        "towering forest",
        "lush forest",
        "serene forest"
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
    addSeasonDescription("spring", ({ " with leaves just beginning to bud" }));
    addSeasonDescription("summer", ({ " with branches laden with leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen leaves of red, yellow, and orange" }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a very dark forest");
    addLowLightDescriptionTemplate("a barely-lit forest");
    addDimLightDescriptionTemplate("a dimly-lit forest");
    addSomeLightDescriptionTemplate("a forest");
}
