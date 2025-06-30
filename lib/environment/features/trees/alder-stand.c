//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("alder stand");
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
        " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with catkins",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen "
        "leaves of red, yellow, and orange", " with leaves in a vivid "
        "array of yellow, red, and orange colors" }));

    addAlias("alder");
    addAlias("alders");
    addAlias("stand of alders");
    addAlias("trees");
    addAlias("tree");
    addAlias("alder tree");
    addAlias("alder trees");

    addDescriptionTemplate("a stand of ##Adjective## alder trees");
    addItemTemplate("The stand of alders is composed of several "
        "medium-sized, water-loving trees with distinctive toothed "
        "leaves. Their bark is smooth and grayish-brown, and their "
        "branches spread gracefully, forming a pleasant canopy "
        "overhead. In season, catkins dangle from the branches, and "
        "the air is filled with the fresh scent of wetland growth. "
        "Moss and lichen cling to the roots, and the filtered light "
        "creates shifting patterns on the moist forest floor. "
        "Occasionally, you spot a bird or small amphibian moving "
        "among the moisture-loving branches.");

    harvestableResource("alder", 25, 
        "/lib/instances/items/materials/wood/alder.c",
        "a heavily-forested stand of alder trees. Several trees remain",
        ({ "deciduous tree", "alder tree", "tree" }));
    harvestRequiresTool("alder", "axe");

    harvestableResource("alder catkin", 25, 
        "/lib/instances/items/food/plants/seeds/alder-catkin.c", 0,
        ({ "catkin" }));
    limitHarvestBySeason("alder catkin", "summer");
}
