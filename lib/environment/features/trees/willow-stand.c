//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("willow stand");
    addAdjectives(({ "towering", "tall", "massive" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with thin leaves just beginning to bud",
        " sprouting new growth"  }));
    addSeasonDescription("summer", ({ " with branches laden with catkins",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in leaves of yellow and brown",
        " with leaves in of yellow and brown" }));

    addDescriptionTemplate("a stand of ##Adjective## willow trees");

    harvestableResource("willow", 25, "/lib/instances/items/materials/wood/willow.c",
        "a heavily-forested stand of willow trees. Several trees remain",
        ({ "deciduous tree", "willow tree", "tree" }));
    harvestRequiresTool("willow", "axe");
    harvestableResource("willow catkin", 25,
        "/lib/instances/items/food/plants/seeds/willow-catkin.c",
        ({ "catkin" }));
    limitHarvestBySeason("willow catkin", "summer");

    harvestableResource("willow bark", 25,
        "/lib/instances/items/food/plants/bark/willow-bark.c",
        ({ "bark" }));
}
