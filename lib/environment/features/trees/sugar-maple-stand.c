//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sugar maple stand");
    addAdjectives(({ "stout", "towering", "tall", "broad" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just "
        "beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last "
        "failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", 
        " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with samaras and leaves",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen leaves "
        "of red, yellow, and orange",
        " with leaves in a vivid array of yellow, red, and orange colors" }));

    addDescriptionTemplate("a stand of ##Adjective## sugar maple trees");

    harvestableResource("sugar maple", 25, "/lib/instances/items/materials/wood/maple.c",
        "a heavily-forested stand of sugar maple trees. Several trees remain",
        ({ "deciduous tree", "sugar maple tree", "maple tree", "maple", "tree" }));
    harvestRequiresTool("sugar maple", "axe");

    harvestableResource("maple sap", 25,
        "/lib/instances/items/food/plants/sap/maple-sap.c", 0,
        ({ "sap" }));

    harvestableResource("maple samara", 25,
        "/lib/instances/items/food/plants/seeds/maple-samara.c", 0,
        ({ "samara" }));
    limitHarvestBySeason("maple samara", "summer");
}
