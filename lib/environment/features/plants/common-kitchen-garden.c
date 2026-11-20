//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("common kitchen garden");
    addAlias("kitchen garden");
    addDescriptionTemplate("a sheltered common kitchen garden");
    addNearDarkDescriptionTemplate("low shapes behind a windbreak");
    addLowLightDescriptionTemplate("small beds behind a woven hurdle");
    addDimLightDescriptionTemplate("a sheltered vegetable garden");
    addSomeLightDescriptionTemplate("common vegetable beds beside a nursery");
    addTimeOfDayDescription("dawn", ({ " beaded with dew" }));
    addTimeOfDayDescription("morning", ({ " freshly tended between its rows" }));
    addTimeOfDayDescription("noon", ({ " shaded along the windbreak" }));
    addTimeOfDayDescription("afternoon", ({ " warm in its sheltered corner" }));
    addTimeOfDayDescription("evening", ({ " quiet after the day's tending" }));
    addTimeOfDayDescription("dusk", ({ " darkening behind the hurdle" }));
    addTimeOfDayDescription("night", ({ " still in the sheltered common" }));
    addTimeOfDayDescription("midnight", ({ " resting beneath the sky" }));
    addItemTemplate("The town's surplus plot has low cabbages, tall "
        "kale, and a sunny bed of small pumpkins. A wooden board asks "
        "visitors to take only from these beds, keeping the nursery "
        "and household gardens untouched.");
    addSeasonDescription("spring", ({ " protected by woven windbreaks" }));
    addSeasonDescription("summer", ({ " crowded with broad green leaves" }));
    addSeasonDescription("autumn", ({ " bearing its last heavy produce" }));
    addSeasonDescription("winter", ({ " mulched around dormant beds" }));
    harvestableResource("cabbage", 4,
        "/lib/instances/items/food/plants/greens/cabbage.c",
        "garden beds with cut cabbage stalks and picked leaves",
        ({ "cabbages" }));
    limitHarvestBySeason("cabbage", "summer");
    limitHarvestBySeason("cabbage", "autumn");
    harvestableResource("kale", 6,
        "/lib/instances/items/food/plants/greens/kale.c",
        "garden beds with cut cabbage stalks and picked leaves");
    limitHarvestBySeason("kale", "summer");
    limitHarvestBySeason("kale", "autumn");
    harvestableResource("pumpkin", 3,
        "/lib/instances/items/food/plants/fruit/pumpkin.c",
        "a pumpkin bed with severed stalks between the trailing vines",
        ({ "pumpkins" }));
    limitHarvestBySeason("pumpkin", "autumn");
}
