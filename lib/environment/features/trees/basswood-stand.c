//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("basswood stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth", " with branches laden with small green flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with many nuts",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and fallen leaves of yellow and brown",
        " with leaves in a vivid array of yellow and brown colors" }));

    addDescriptionTemplate("a stand of ##Adjective## basswood trees");

    harvestableResource("basswood", 25, "/lib/instances/items/materials/wood/basswood.c",
        "a heavily-forested stand of basswood trees. Several trees remain",
        ({ "deciduous tree", "basswood tree", "tree" }));
    harvestRequiresTool("basswood", "axe");

    harvestableResource("basswood nut", 25,
        "/lib/instances/items/food/plants/nuts/basswood-nut.c", 0,
        ({ "nut" }));
    limitHarvestBySeason("basswood nut", "summer");

}
