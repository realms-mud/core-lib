//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("montmorency cherry stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth", " with branches laden with white flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with fruit",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fruit and fallen leaves of red, yellow, and orange",
        " with leaves in a vivid array of yellow, red, and orange colors" }));

    addDescriptionTemplate("a stand of ##Adjective## montmorency cherry trees");

    harvestableResource("montmorency cherry tree", 25, "/lib/instances/items/materials/wood/cherry.c",
        "a heavily-forested stand of montmorency cherry trees. Several trees remain",
        ({ "deciduous tree", "cherry tree", "tree" }));
    harvestRequiresTool("montmorency cherry tree", "axe");

    harvestableResource("montmorency cherry", 20,
        "/lib/instances/items/food/plants/fruit/montmorency-cherry.c", 0,
        ({ "cherry", "fruit" }));
    limitHarvestBySeason("montmorency cherry", "summer");
}
