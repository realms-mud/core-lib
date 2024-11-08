//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("red oak stand");
    addAdjectives(({ "majestic", "towering", "tall", "ancient" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with acorns",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen leaves of red and orange",
        " with leaves in a vivid array of red and orange colors" }));

    addDescriptionTemplate("a stand of ##Adjective## red oak trees");

    harvestableResource("red oak", 25, "/lib/instances/items/materials/wood/oak.c",
        "a heavily-forested stand of red oak trees. Several trees remain",
        ({ "deciduous tree", "red oak tree", "oak tree", "oak", "tree" }));
    harvestRequiresTool("red oak", "axe");

    harvestableResource("acorn", 25,
        "/lib/instances/items/food/plants/nuts/acorn.c", 0,
        ({ "acorn nut", "nut" }));
    limitHarvestBySeason("acorn", "summer");
}
