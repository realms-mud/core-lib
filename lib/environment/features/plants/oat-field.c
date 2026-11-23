//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tenant oat field");
    addAlias("oat field");
    addAlias("oats");
    addAdjectives(({ "green", "silver-green", "wind-bent", "ripe",
        "well-tended", "dew-darkened" }));

    addDescriptionTemplate("a ##Adjective## tenant oat field");
    addNearDarkDescriptionTemplate("low rows of grain in the dark");
    addLowLightDescriptionTemplate("an oat field along the road");
    addDimLightDescriptionTemplate("rows of oats beyond the field edge");
    addSomeLightDescriptionTemplate("a tenant field of oats");
    addItemTemplate("The oat crop is planted in long, narrow rows for an "
        "Eolach tenant. Its lighter heads ripple above the furrows, which "
        "carry runoff toward a shallow field drain.");

    addTimeOfDayDescription("dawn", ({ " silvered with dew" }));
    addTimeOfDayDescription("morning", ({ " moving in the cool breeze" }));
    addTimeOfDayDescription("noon", ({ " pale beneath the open sky" }));
    addTimeOfDayDescription("afternoon", ({ " casting fine shadows" }));
    addTimeOfDayDescription("evening", ({ " gold at the edges" }));
    addTimeOfDayDescription("dusk", ({ " blending into the farmland" }));
    addTimeOfDayDescription("night", ({ " whispering in the darkness" }));
    addTimeOfDayDescription("midnight", ({ " still beneath the night sky" }));

    addSeasonDescription("spring", ({ " lined with fresh green shoots" }));
    addSeasonDescription("summer", ({ " bearing pale, ripening heads" }));
    addSeasonDescription("autumn", ({ " reaped above the cut stubble" }));
    addSeasonDescription("winter", ({ " lying fallow beneath the frost" }));

    harvestableResource("oat", 12,
        "/lib/instances/items/food/plants/grains/oat.c",
        "an oat field cut to short stubble");
    limitHarvestBySeason("oat", "autumn");
}
