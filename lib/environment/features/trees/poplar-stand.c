//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("poplar stand");
    addAdjectives(({ "towering", "tall", "massive" }));

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
        " sprouting new growth", "with wisps of cotton-like material "
        "littering the ground below"  }));
    addSeasonDescription("summer", ({ " with branches laden with catkins",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in leaves of "
        "yellow and brown", " with leaves in of yellow and brown" }));

    addAlias("poplar");
    addAlias("poplars");
    addAlias("stand of poplars");
    addAlias("trees");
    addAlias("tree");
    addAlias("poplar tree");
    addAlias("poplar trees");

    addDescriptionTemplate("a stand of ##Adjective## poplar trees");
    addItemTemplate("The stand of poplars is composed of several "
        "tall, fast-growing trees with distinctive triangular leaves. "
        "Their bark is smooth and grayish-white, and their branches "
        "spread wide, forming a rustling canopy overhead. In season, "
        "catkins dangle from the branches, and the air is filled with "
        "the fresh scent of new growth and cotton-like seeds. Moss "
        "and lichen cling to the roots, and the filtered light creates "
        "shifting patterns on the ground. Occasionally, you spot a "
        "bird or small creature darting among the quick-growing "
        "branches.");

    harvestableResource("poplar", 25, 
        "/lib/instances/items/materials/wood/poplar.c",
        "a heavily-forested stand of poplar trees. Several trees remain",
        ({ "deciduous tree", "poplar tree", "tree" }));
    harvestRequiresToool("poplar", "axe");

    harvestableResource("poplar catkin", 25,
        "/lib/instances/items/food/plants/seeds/poplar-catkin.c", 0,
        ({ "catkin" }));
    limitHarvestBySeason("poplar catkin", "summer");
}
