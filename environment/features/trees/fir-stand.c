//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fir stand");
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

    addDescriptionTemplate("a stand of ##Adjective## fir trees");

    harvestableResource("fir", 25, "/lib/instances/items/materials/wood/fir.c",
        "a heavily-forested stand of fir trees. Several trees remain");
    harvestRequiresTool("fir", "axe");
    harvestableResource("fir cone", 25,
        "/lib/instances/items/food/plants/seeds/fir-cone.c");
    limitHarvestBySeason("fir cone", "summer");
    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c");
    limitHarvestBySeason("pine nut", "summer");
}
