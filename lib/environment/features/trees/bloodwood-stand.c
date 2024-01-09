//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bloodwood stand");
    addAdjectives(({ "majestic", "towering", "tall", "slender" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth", " with branches laden with small flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with many seeds",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and fallen leaves of yellow and brown",
        " with leaves in a vivid array of yellow and brown colors" }));

    addDescriptionTemplate("a stand of ##Adjective## bloodwood trees");

    harvestableResource("bloodwood", 25, "/lib/instances/items/materials/wood/bloodwood.c",
        "a heavily-forested stand of bloodwood trees. Several trees remain",
        ({ "deciduous tree", "bloodwood tree", "tree" }));
    harvestRequiresTool("bloodwood", "axe");

    harvestableResource("bloodwood seed", 25,
        "/lib/instances/items/food/plants/seeds/bloodwood-seed.c", 0,
        ({ "seed" }));
    limitHarvestBySeason("bloodwood seed", "summer");
}
