//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("paper birch stand");
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

    addAlias("paper birch");
    addAlias("paper birches");
    addAlias("stand of paper birches");
    addAlias("birch");
    addAlias("birches");
    addAlias("trees");
    addAlias("tree");
    addAlias("paper birch tree");
    addAlias("paper birch trees");
    addAlias("birch tree");
    addAlias("birch trees");

    addDescriptionTemplate("a stand of ##Adjective## paper birch trees");
    addItemTemplate("The stand of paper birches is composed of several "
        "slender-trunked trees with distinctive white bark that peels "
        "in papery layers. Their branches spread gracefully, forming "
        "a light canopy overhead. In season, catkins dangle from the "
        "branches, and the air is filled with the fresh scent of new "
        "growth. Moss and lichen cling to the roots, and the filtered "
        "light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a bird or small creature darting among "
        "the elegant white trunks.");

    harvestableResource("paper birch", 25, 
        "/lib/instances/items/materials/wood/birch.c",
        "a heavily-forested stand of paper birch trees. Several trees "
        "remain", ({ "deciduous tree", "paper birch tree", "birch tree", 
        "birch", "tree" }));
    harvestRequiresTool("paper birch", "axe");

    harvestableResource("paper birch catkin", 25,
        "/lib/instances/items/food/plants/seeds/paper-birch-catkin.c", 0,
        ({ "birch catkin", "catkin" }));
    limitHarvestBySeason("paper birch catkin", "summer");

    harvestableResource("paper birch bark", 10,
        "/lib/instances/items/materials/wood/paper-birch-bark.c", 0,
        ({ "birch bark", "bark" }));
}
