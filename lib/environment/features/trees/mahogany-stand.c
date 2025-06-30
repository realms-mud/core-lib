//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mahogany stand");
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
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and "
        "fallen leaves of red, yellow, and orange", " with leaves in a "
        "vivid array of yellow, red, and orange colors" }));

    addAlias("mahogany");
    addAlias("mahoganies");
    addAlias("stand of mahoganies");
    addAlias("trees");
    addAlias("tree");
    addAlias("mahogany tree");
    addAlias("mahogany trees");

    addDescriptionTemplate("a stand of ##Adjective## mahogany trees");
    addItemTemplate("The stand of mahoganies is composed of several "
        "tall, straight-trunked tropical trees with distinctive "
        "reddish-brown heartwood. Their bark is smooth and grayish, "
        "and their branches spread wide, forming a dense canopy "
        "overhead. In season, small fruits dot the branches, and the "
        "air is filled with the rich scent of tropical hardwood. Moss "
        "and lichen cling to the roots, and the filtered light creates "
        "shifting patterns on the forest floor. Occasionally, you spot "
        "a bird or small creature moving among the valuable branches.");

    harvestableResource("mahogany", 25, 
        "/lib/instances/items/materials/wood/mahogany.c",
        "a heavily-forested stand of mahogany trees. Several trees "
        "remain", ({ "deciduous tree", "mahogany tree", "tree" }));
    harvestRequiresTool("mahogany", "axe");

    harvestableResource("mahogany fruit", 25,
        "/lib/instances/items/food/plants/fruit/mahogany-fruit.c", 0,
        ({ "fruit" }));
    limitHarvestBySeason("mahogany fruit", "summer");
}
