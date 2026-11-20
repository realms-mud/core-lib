//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("common pulse rows");
    addAlias("pulse rows");
    addDescriptionTemplate("common rows of peas and climbing beans");
    addNearDarkDescriptionTemplate("thin supports above low rows");
    addLowLightDescriptionTemplate("a fence and climbing frames");
    addDimLightDescriptionTemplate("pulse rows supported by hazel poles");
    addSomeLightDescriptionTemplate("common pea rows and climbing bean frames");
    addTimeOfDayDescription("dawn", ({ " beaded with dew" }));
    addTimeOfDayDescription("morning", ({ " moving gently against their poles" }));
    addTimeOfDayDescription("noon", ({ " casting thin shadows across the rows" }));
    addTimeOfDayDescription("afternoon", ({ " sheltered beside the fence" }));
    addTimeOfDayDescription("evening", ({ " quiet in the cooling air" }));
    addTimeOfDayDescription("dusk", ({ " fading beneath their frames" }));
    addTimeOfDayDescription("night", ({ " dark against the fence" }));
    addTimeOfDayDescription("midnight", ({ " still beneath the sky" }));
    addItemTemplate("Peas run along a low fence and beans climb a "
        "frame of hazel poles. These few rows are maintained for "
        "travelers and neighbors; the household plots lie elsewhere.");
    addSeasonDescription("spring", ({ " flowering along the low fence" }));
    addSeasonDescription("summer", ({ " bearing pods among the leaves" }));
    addSeasonDescription("autumn", ({ " drying on their supporting poles" }));
    addSeasonDescription("winter", ({ " cleared down to their bare frames" }));
    harvestableResource("snow pea", 5,
        "/lib/instances/items/food/plants/legumes/snow-pea.c",
        "pulse rows with empty pod stalks along the fence",
        ({ "snow peas" }));
    limitHarvestBySeason("snow pea", "summer");
    harvestableResource("runner bean", 5,
        "/lib/instances/items/food/plants/legumes/runner-bean.c",
        "bean poles with their reachable pods already picked",
        ({ "runner beans" }));
    limitHarvestBySeason("runner bean", "summer");
}
