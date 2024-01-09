//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("aspen stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with catkins",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen leaves of red, yellow, and orange",
        " with leaves in a vivid array of yellow, red, and orange colors" }));

    addDescriptionTemplate("a stand of ##Adjective## aspen trees");

    harvestableResource("aspen", 25, "/lib/instances/items/materials/wood/aspen.c",
        "a heavily-forested stand of aspen trees. Several trees remain",
        ({ "deciduous tree", "aspen tree", "tree" }));
    harvestRequiresTool("aspen", "axe");

    harvestableResource("aspen catkin", 25,
        "/lib/instances/items/food/plants/seeds/aspen-catkin.c", 0,
        ({ "catkin" }));
    limitHarvestBySeason("aspen catkin", "summer");
}
