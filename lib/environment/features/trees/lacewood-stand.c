//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lacewood stand");
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
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen leaves of yellow",
        " with leaves in a vivid array of yellow and brown colors" }));

    addDescriptionTemplate("a stand of ##Adjective## lacewood trees");

    harvestableResource("lacewood", 25, "/lib/instances/items/materials/wood/lacewood.c",
        "a heavily-forested stand of lacewood trees. Several trees remain",
        ({ "deciduous tree", "lacewood tree", "tree" }));
    harvestRequiresTool("lacewood", "axe");

    harvestableResource("lacewood seed pod", 25,
        "/lib/instances/items/food/plants/seeds/lacewood-seed-pod.c", 0,
        ({ "seed pod", "pod", "seed" }));
    limitHarvestBySeason("lacewood seed pod", "summer");
}
