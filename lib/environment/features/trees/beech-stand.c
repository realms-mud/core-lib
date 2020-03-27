//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("beech stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with nuts",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen leaves of red, yellow, and orange",
        " with leaves in a vivid array of yellow, red, and orange colors" }));

    addDescriptionTemplate("a stand of ##Adjective## beech trees");

    harvestableResource("beech", 25, "/lib/instances/items/materials/wood/beech.c",
        "a heavily-forested stand of beech trees. Several trees remain",
        ({ "deciduous tree", "beech tree", "tree" }));
    harvestRequiresTool("beech", "axe");

    harvestableResource("beech nut", 25,
        "/lib/instances/items/food/plants/nuts/beech-nut.c",
        ({ "nut" }));
    limitHarvestBySeason("beech nut", "summer");
}
