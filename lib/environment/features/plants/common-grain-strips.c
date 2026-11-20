//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("common grain strips");
    addAlias("grain");
    addAlias("grain strips");
    addDescriptionTemplate("short gleaning strips of barley, oats, and rye");
    addNearDarkDescriptionTemplate("low strips of cultivated ground");
    addLowLightDescriptionTemplate("narrow grain strips");
    addDimLightDescriptionTemplate("grain strips beside a threshing margin");
    addSomeLightDescriptionTemplate("marked common grain strips for gleaning");
    addTimeOfDayDescription("dawn", ({ " touched by dew" }));
    addTimeOfDayDescription("morning", ({ " stirring in the breeze" }));
    addTimeOfDayDescription("noon", ({ " exposed to the open light" }));
    addTimeOfDayDescription("afternoon", ({ " shadowed along the field margin" }));
    addTimeOfDayDescription("evening", ({ " quiet beside the threshing floor" }));
    addTimeOfDayDescription("dusk", ({ " fading against the fields" }));
    addTimeOfDayDescription("night", ({ " rustling softly" }));
    addTimeOfDayDescription("midnight", ({ " still under the dark sky" }));
    addItemTemplate("Narrow strips remain beside the common threshing "
        "floor. A notice permits gleaning here after the main crop is "
        "gathered. The larger tenant fields beyond are not included.");
    addSeasonDescription("spring", ({ " green with young shoots" }));
    addSeasonDescription("summer", ({ " turning gold around the edges" }));
    addSeasonDescription("autumn", ({ " left for permitted gleaning" }));
    addSeasonDescription("winter", ({ " reduced to stubble" }));
    foreach (string crop in ({ "barley", "oat", "rye" }))
    {
        harvestableResource(crop, 5,
            "/lib/instances/items/food/plants/grains/" + crop + ".c",
            "gleaning strips with most of their remaining heads gathered");
        limitHarvestBySeason(crop, "autumn");
    }
}
