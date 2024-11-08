//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cottonwood stand");
    addAdjectives(({ "towering", "tall", "massive" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth", "with wisps of cotton-like material littering the ground below"  }));
    addSeasonDescription("summer", ({ " with branches laden with catkins",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in leaves of yellow and brown",
        " with leaves in of yellow and brown" }));

    addDescriptionTemplate("a stand of ##Adjective## cottonwood trees");

    harvestableResource("cottonwood", 25, "/lib/instances/items/materials/wood/cottonwood.c",
        "a heavily-forested stand of cottonwood trees. Several trees remain",
        ({ "deciduous tree", "cottonwood tree", "tree" }));
    harvestRequiresTool("cottonwood", "axe");

    harvestableResource("cottonwood catkin", 25,
        "/lib/instances/items/food/plants/seeds/cottonwood-catkin.c", 0,
        ({ "catkin" }));
    limitHarvestBySeason("cottonwood catkin", "summer");
}
