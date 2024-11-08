//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hemlock stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));
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

    addDescriptionTemplate("a stand of ##Adjective## hemlock trees");

    harvestableResource("hemlock", 25, "/lib/instances/items/materials/wood/hemlock.c",
        "a heavily-forested stand of hemlock trees. Several trees remain",
        ({ "conifer", "evergreen", "hemlock tree", "tree" }));
    harvestRequiresTool("hemlock", "axe");

    harvestableResource("hemlock cone", 25,
        "/lib/instances/items/food/plants/seeds/hemlock-cone.c", 0,
        ({ "cone", "pinecone", "conifer cone", "pine cone" }));
    limitHarvestBySeason("hemlock cone", "summer");

    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c", 0,
        ({ "nut", "hemlock nut" }));
    limitHarvestBySeason("pine nut", "summer");
}
