//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dogwood stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));

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

    addAlias("dogwood");
    addAlias("dogwoods");
    addAlias("stand of dogwoods");
    addAlias("trees");
    addAlias("tree");
    addAlias("dogwood tree");
    addAlias("dogwood trees");

    addDescriptionTemplate("a stand of ##Adjective## dogwood trees");
    addItemTemplate("The stand of dogwoods is composed of several "
        "medium-sized, ornamental trees with distinctive four-petaled "
        "flowers. Their bark is blocky and dark gray, and their "
        "branches spread horizontally, forming a layered canopy "
        "overhead. In season, small red berries cluster on the "
        "branches, and the air is filled with the subtle scent of "
        "woodland blooms. Moss and lichen cling to the roots, and the "
        "filtered light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a bird or small creature visiting "
        "among the beautiful flowering branches.");

    harvestableResource("dogwood", 25, 
        "/lib/instances/items/materials/wood/dogwood.c",
        "a heavily-forested stand of dogwood trees. Several trees "
        "remain", ({ "deciduous tree", "dogwood tree", "tree" }));
    harvestRequiresTool("dogwood", "axe");

    harvestableResource("dogwood fruit", 25,
        "/lib/instances/items/food/plants/fruit/dogwood-fruit.c", 0,
        ({ "fruit" }));
    limitHarvestBySeason("dogwood fruit", "summer");
}
