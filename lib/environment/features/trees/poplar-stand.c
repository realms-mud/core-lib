//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("poplar stand");
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

    addDescriptionTemplate("a stand of ##Adjective## poplar trees");

    harvestableResource("poplar", 25, "/lib/instances/items/materials/wood/poplar.c",
        "a heavily-forested stand of poplar trees. Several trees remain",
        ({ "deciduous tree", "poplar tree", "tree" }));
    harvestRequiresTool("poplar", "axe");

    harvestableResource("poplar catkin", 25,
        "/lib/instances/items/food/plants/seeds/poplar-catkin.c",
        ({ "catkin" }));
    limitHarvestBySeason("poplar catkin", "summer");
}
