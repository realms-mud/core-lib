//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("purple heart stand");
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

    addDescriptionTemplate("a stand of ##Adjective## purple heart trees");

    harvestableResource("purple heart", 25, 
        "/lib/instances/items/materials/wood/purple-heart.c",
        "a heavily-forested stand of purple hear trees. Several trees remain",
        ({ "deciduous tree", "purple heart tree", "tree" }));
    harvestRequiresTool("purple heart", "axe");

    harvestableResource("purple heart seed pod", 25,
        "/lib/instances/items/food/plants/seeds/purple-heart-seed-pod.c", 0,
        ({ "seed", "pod", "seed pod" }));
    limitHarvestBySeason("purple heart seed pod", "summer");
}
