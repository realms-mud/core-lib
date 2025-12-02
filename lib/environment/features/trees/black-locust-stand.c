//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("black locust stand");
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
    addSeasonDescription("summer", ({ " with branches laden with seed pods",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen "
        "leaves of red, yellow, and orange", " with leaves in a vivid "
        "array of yellow and brown colors" }));

    addAlias("black locust");
    addAlias("black locusts");
    addAlias("stand of black locusts");
    addAlias("locust");
    addAlias("locusts");
    addAlias("trees");
    addAlias("tree");
    addAlias("black locust tree");
    addAlias("black locust trees");
    addAlias("locust tree");
    addAlias("locust trees");

    addDescriptionTemplate("a stand of ##Adjective## black locust trees");
    addItemTemplate("The stand of black locusts is composed of several "
        "tall, fast-growing trees with deeply furrowed, dark bark. "
        "Their branches spread with compound leaves and occasional "
        "thorns, forming a dense canopy overhead. In season, fragrant "
        "white flower clusters bloom, followed by long seed pods, and "
        "the air is filled with the sweet scent of locust blossoms. "
        "Moss and lichen cling to the roots, and the filtered light "
        "creates shifting patterns on the forest floor. Occasionally, "
        "you spot a bird or bee visiting among the fragrant flowering "
        "branches.");

    harvestableResource("black locust", 25, 
        "/lib/instances/items/materials/wood/black-locust.c",
        "a heavily-forested stand of black locust trees. Several trees "
        "remain", ({ "deciduous tree", "black locust tree", "locust", 
        "locust tree", "tree" }));
    harvestRequiresTool("black locust", "axe");

    harvestableResource("black locust seed pod", 25,
        "/lib/instances/items/food/plants/seeds/black-locust-seed-pod.c", 0,
        ({ "locust seed pod", "seed pod", "pod", "seed" }));
    limitHarvestBySeason("black locust seed pod", "summer");
}
