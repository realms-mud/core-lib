//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("raspberry canes");
    addAlias("raspberries");
    addAlias("canes");
    addDescriptionTemplate("a patch of raspberry canes");
    addNearDarkDescriptionTemplate("a tangle at the woodland edge");
    addLowLightDescriptionTemplate("a patch of slender stems");
    addDimLightDescriptionTemplate("raspberry canes beside the path");
    addSomeLightDescriptionTemplate("raspberry canes with pale-backed leaves");
    addTimeOfDayDescription("dawn", ({ " wet with woodland dew" }));
    addTimeOfDayDescription("morning", ({ " catching light along the leaves" }));
    addTimeOfDayDescription("noon", ({ " warm at the clearing edge" }));
    addTimeOfDayDescription("afternoon", ({ " shaded below the upper growth" }));
    addTimeOfDayDescription("evening", ({ " rustling in the cooling air" }));
    addTimeOfDayDescription("dusk", ({ " becoming indistinct" }));
    addTimeOfDayDescription("night", ({ " dark beside the trees" }));
    addTimeOfDayDescription("midnight", ({ " quiet beneath the canopy" }));
    addItemTemplate("Slender canes rise from the sunny woodland edge. "
        "The leaves show pale undersides when the wind stirs them. "
        "In summer, red berries hang beneath the new growth.");
    addSeasonDescription("spring", ({ " putting out pale green leaves" }));
    addSeasonDescription("summer", ({ " laden with red berries" }));
    addSeasonDescription("autumn", ({ " yellowing at the woodland edge" }));
    addSeasonDescription("winter", ({ " bare above the leaf litter" }));
    harvestableResource("raspberry", 6,
        "/lib/instances/items/food/plants/fruit/raspberry.c",
        "raspberry canes with empty fruit stalks among their leaves",
        ({ "raspberries" }));
    limitHarvestBySeason("raspberry", "summer");
}
