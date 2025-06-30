//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cortland apple stand");
    addAdjectives(({ "majestic", "towering", "tall", "slender" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with branches just catching the faint dawn light",
        "outlined softly as the day begins"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight filtering through the leaves"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "casting dappled shade at midday"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with shadows stretching beneath the branches",
        "standing quietly in the afternoon warmth"
        }));
    addTimeOfDayDescription("evening", ({
        "with leaves glowing in the golden evening light",
        "as the sun sets behind the broad canopy"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the last light of day",
        "becoming silhouettes as dusk settles"
        }));
    addTimeOfDayDescription("night", ({
        "outlined in the darkness",
        "discernable only as a darker shape against the night"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the deep shadows of night"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth", " with branches laden with white "
        "flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with fruit",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fruit and "
        "fallen leaves of red, yellow, and orange", " with leaves in a "
        "vivid array of yellow, red, and orange colors" }));

    addAlias("cortland apple");
    addAlias("cortland apples");
    addAlias("stand of cortland apples");
    addAlias("apple");
    addAlias("apples");
    addAlias("trees");
    addAlias("tree");
    addAlias("cortland apple tree");
    addAlias("cortland apple trees");
    addAlias("apple tree");
    addAlias("apple trees");

    addDescriptionTemplate("a stand of ##Adjective## cortland apple trees");
    addItemTemplate("The stand of cortland apples is composed of several "
        "sturdy-trunked, productive trees. Their bark is smooth and "
        "grayish-brown, and their branches spread wide, forming a "
        "pleasant canopy overhead. In season, red and green striped "
        "apples hang from the branches, and the air is filled with the "
        "sweet scent of ripening fruit. Moss and lichen cling to the "
        "roots, and the filtered light creates shifting patterns on "
        "the orchard floor. Occasionally, you spot a bird or bee "
        "visiting among the branches.");

    harvestableResource("cortland apple tree", 25, 
        "/lib/instances/items/materials/wood/apple.c",
        "a heavily-forested stand of cortland apple trees. Several "
        "trees remain", ({ "apple tree", "tree" }));
    harvestRequiresTool("cortland apple tree", "axe");

    harvestableResource("cortland apple", 10,
        "/lib/instances/items/food/plants/fruit/cortland-apple.c", 0,
        ({ "apple" }));
    limitHarvestBySeason("cortland apple", "summer");
}
