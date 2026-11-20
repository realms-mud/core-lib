//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("common root beds");
    addAlias("root beds");
    addDescriptionTemplate("small communal beds of root vegetables");
    addNearDarkDescriptionTemplate("low rows in the ground");
    addLowLightDescriptionTemplate("small cultivated beds");
    addDimLightDescriptionTemplate("neatly marked vegetable rows");
    addSomeLightDescriptionTemplate("communal root beds with marked seed rows");
    addTimeOfDayDescription("dawn", ({ " damp with dew" }));
    addTimeOfDayDescription("morning", ({ " neatly weeded between the rows" }));
    addTimeOfDayDescription("noon", ({ " bright across their open ground" }));
    addTimeOfDayDescription("afternoon", ({ " edged by long marker shadows" }));
    addTimeOfDayDescription("evening", ({ " quiet after the day's garden work" }));
    addTimeOfDayDescription("dusk", ({ " fading into the common" }));
    addTimeOfDayDescription("night", ({ " still beneath the dark sky" }));
    addTimeOfDayDescription("midnight", ({ " resting beside the path" }));
    addItemTemplate("Carrot tops, beet leaves, and turnip greens grow "
        "in short rows beside an open basket. A board identifies these "
        "as the common's surplus beds: visitors may lift a few roots "
        "in season, leaving the seed rows alone.");
    addSeasonDescription("spring", ({ " marked by newly planted rows" }));
    addSeasonDescription("summer", ({ " thick with green tops" }));
    addSeasonDescription("autumn", ({ " ready for the lifting season" }));
    addSeasonDescription("winter", ({ " resting beneath a mulch of straw" }));
    foreach (string crop in ({ "carrot", "beet", "turnip", "parsnip" }))
    {
        harvestableResource(crop, 4,
            "/lib/instances/items/food/plants/roots/" + crop + ".c",
            "root beds with lifted plants and neatly refilled holes",
            ({ crop + "s" }));
        limitHarvestBySeason(crop, "autumn");
    }
}
