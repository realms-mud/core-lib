//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tenant rye field");
    addAlias("rye field");
    addAlias("rye");
    addAdjectives(({ "green", "tall", "sturdy", "wind-bent", "ripe",
        "well-tended" }));

    addDescriptionTemplate("a ##Adjective## tenant rye field");
    addNearDarkDescriptionTemplate("dark rows of grain");
    addLowLightDescriptionTemplate("a rye field along the road");
    addDimLightDescriptionTemplate("tall rye beyond the field edge");
    addSomeLightDescriptionTemplate("a tenant field of rye");
    addItemTemplate("The rye stands taller and darker than the neighboring "
        "grain. Its field belongs to an Eolach tenant, and a low earth bank "
        "keeps runoff from carrying soil onto the road.");

    addTimeOfDayDescription("dawn", ({ " beaded with cold dew" }));
    addTimeOfDayDescription("morning", ({ " bending under the breeze" }));
    addTimeOfDayDescription("noon", ({ " standing in full sunlight" }));
    addTimeOfDayDescription("afternoon", ({ " casting narrow shadows" }));
    addTimeOfDayDescription("evening", ({ " darkening in the low light" }));
    addTimeOfDayDescription("dusk", ({ " fading against the fields" }));
    addTimeOfDayDescription("night", ({ " stirring in the night wind" }));
    addTimeOfDayDescription("midnight", ({ " still beneath the dark sky" }));

    addSeasonDescription("spring", ({ " showing firm green growth" }));
    addSeasonDescription("summer", ({ " carrying heavy seed heads" }));
    addSeasonDescription("autumn", ({ " cut down to rough stubble" }));
    addSeasonDescription("winter", ({ " resting beneath a light frost" }));

    harvestableResource("rye", 12,
        "/lib/instances/items/food/plants/grains/rye.c",
        "a rye field cut to short stubble");
    limitHarvestBySeason("rye", "autumn");
}
