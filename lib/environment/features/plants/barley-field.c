//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tenant barley field");
    addAlias("barley field");
    addAlias("barley");
    addAdjectives(({ "green", "golden", "ripe", "wind-stirred",
        "well-tended", "dew-darkened" }));

    addDescriptionTemplate("a ##Adjective## tenant barley field");
    addNearDarkDescriptionTemplate("low rows of grain in the dark");
    addLowLightDescriptionTemplate("a barley field along the road");
    addDimLightDescriptionTemplate("rows of barley beyond the field edge");
    addSomeLightDescriptionTemplate("a tenant field of barley");
    addItemTemplate("The closely sown barley belongs to an Eolach tenant. "
        "Furrows run down the gentle slope, and a narrow verge keeps the "
        "crop clear of the estate road.");

    addTimeOfDayDescription("dawn", ({ " darkened by dew" }));
    addTimeOfDayDescription("morning", ({ " stirred by the breeze" }));
    addTimeOfDayDescription("noon", ({ " bright beneath the open sky" }));
    addTimeOfDayDescription("afternoon", ({ " striped with long shadows" }));
    addTimeOfDayDescription("evening", ({ " warm in the lowering light" }));
    addTimeOfDayDescription("dusk", ({ " fading into the fields" }));
    addTimeOfDayDescription("night", ({ " rustling in the darkness" }));
    addTimeOfDayDescription("midnight", ({ " still beneath the night sky" }));

    addSeasonDescription("spring", ({ " green with new shoots" }));
    addSeasonDescription("summer", ({ " heavy with ripening heads" }));
    addSeasonDescription("autumn", ({ " cut back to stubble after harvest" }));
    addSeasonDescription("winter", ({ " resting as bare furrows" }));

    harvestableResource("barley", 12,
        "/lib/instances/items/food/plants/grains/barley.c",
        "a barley field cut to short stubble");
    limitHarvestBySeason("barley", "autumn");
}
