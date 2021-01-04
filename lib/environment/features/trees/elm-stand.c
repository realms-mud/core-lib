//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("elm stand");
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
        "of yellow and orange",
        " with leaves in a vivid array of yellow orange colors" }));

    addDescriptionTemplate("a stand of ##Adjective## elm trees");

    harvestableResource("elm", 25, "/lib/instances/items/materials/wood/elm.c",
        "a heavily-forested stand of elm trees. Several trees remain",
        ({ "deciduous tree", "elm tree", "tree" }));
    harvestRequiresTool("elm", "axe");

    harvestableResource("elm samara", 25,
        "/lib/instances/items/food/plants/seeds/elm-samara.c", 0,
        ({ "samara" }));
    limitHarvestBySeason("elm samara", "summer");
}
