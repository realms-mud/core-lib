//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pine stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with brilliant green new growth sprouting",
        " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with closed cones",
        " covered with a thick blanket of needles" }));
    addSeasonDescription("autumn", ({ " with cones fallen to the ground wide open",
        " with cones and some needles carpeting the ground" }));

    addDescriptionTemplate("a stand of ##Adjective## pine trees");

    harvestableResource("pine", 25, "/lib/instances/items/materials/wood/pine.c",
        "a heavily-forested stand of pine trees. Several trees remain",
        ({ "conifer", "evergreen", "pine tree", "tree" }));
    harvestRequiresTool("pine", "axe");

    harvestableResource("pine cone", 25,
        "/lib/instances/items/food/plants/seeds/pine-cone.c", 0,
        ({ "cone", "pinecone", "conifer cone" }));
    limitHarvestBySeason("pine cone", "summer");

    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c", 0,
        ({ "nut" }));
    limitHarvestBySeason("pine nut", "summer");
}
