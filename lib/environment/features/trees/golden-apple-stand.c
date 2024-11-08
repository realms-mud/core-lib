//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("golden apple stand");
    addAdjectives(({ "majestic", "towering", "tall", "slender" }));
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

    addDescriptionTemplate("a stand of ##Adjective## golden apple trees");

    harvestableResource("golden apple tree", 25, "/lib/instances/items/materials/wood/apple.c",
        "a heavily-forested stand of golden apple trees. Several trees remain",
        ({ "apple tree", "tree" }));
    harvestRequiresTool("golden apple tree", "axe");

    harvestableResource("golden apple", 10,
        "/lib/instances/items/food/plants/fruit/golden-apple.c", 0,
        ({ "apple" }));
    limitHarvestBySeason("golden apple", "summer");
}
