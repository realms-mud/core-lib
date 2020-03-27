//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("black locust stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with seed pods",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen leaves of red, yellow, and orange",
        " with leaves in a vivid array of yellow and brown colors" }));

    addDescriptionTemplate("a stand of ##Adjective## black locust trees");

    harvestableResource("black locust", 25, "/lib/instances/items/materials/wood/black-locust.c",
        "a heavily-forested stand of black locust trees. Several trees remain",
        ({ "deciduous tree", "black locust tree", "locust", "locust tree", "tree" }));
    harvestRequiresTool("black locust", "axe");

    harvestableResource("black locust seed pod", 25,
        "/lib/instances/items/food/plants/seeds/black-locust-seed-pod.c",
        ({ "locust seed pod", "seed pod", "pod", "seed" }));
    limitHarvestBySeason("black locust seed pod", "summer");
}
