//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cedar stand");
    addAdjectives(({ "majestic", "towering", "tall", "gnarled" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with brilliant green new growth sprouting",
        " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with tiny, closed cones",
        " covered with a thick blanket of needles" }));
    addSeasonDescription("autumn", ({ " with cones fallen to the ground wide open" }));

    addDescriptionTemplate("a stand of ##Adjective## cedar trees");

    harvestableResource("cedar", 25, "/lib/instances/items/materials/wood/cedar.c",
        "a heavily-forested stand of cedar trees. Several trees remain",
        ({ "conifer", "evergreen", "cedar tree", "tree" }));
    harvestRequiresTool("cedar", "axe");

    harvestableResource("cedar cone", 25,
        "/lib/instances/items/food/plants/seeds/cedar-cone.c", 0,
        ({ "cone", "conifer cone" }));
    limitHarvestBySeason("cedar cone", "summer");
}
