//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("malorn stand");
    addAdjectives(({ "majestic", "towering", "tall", "slender" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth", " with branches laden with beautiful golden flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with fruit",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fruit and fallen leaves of purple, red, yellow, and orange",
        " with leaves in a vivid array of yellow, purple, red, and orange colors" }));

    addDescriptionTemplate("a stand of ##Adjective## malorn trees");

    harvestableResource("malorn", 25, "/lib/instances/items/materials/wood/malorn.c",
        "a heavily-forested stand of malorn trees. Several trees remain");
    harvestRequiresTool("malorn", "axe");
    harvestableResource("malorn fruit", 25,
        "/lib/instances/items/food/plants/fruit/malorn-fruit.c");
    limitHarvestBySeason("malorn fruit", "summer");

    harvestableResource("malorn flower", 25,
        "/lib/instances/items/food/plants/flowers/malorn-flower.c");
    limitHarvestBySeason("malorn flower", "spring");
}
