//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rosewood stand");
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
        " sprouting new growth", " with branches laden with small "
        "flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with many "
        "seeds", " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and "
        "fallen leaves of yellow and brown", " with leaves in a vivid "
        "array of yellow and brown colors" }));

    addAlias("rosewood");
    addAlias("rosewoods");
    addAlias("stand of rosewoods");
    addAlias("trees");
    addAlias("tree");
    addAlias("rosewood tree");
    addAlias("rosewood trees");

    addDescriptionTemplate("a stand of ##Adjective## rosewood trees");
    addItemTemplate("The stand of rosewoods is composed of several "
        "tall, elegant trees with distinctive reddish-brown heartwood. "
        "Their bark is smooth and grayish, and their branches spread "
        "gracefully, forming a pleasant canopy overhead. In season, "
        "small seeds dot the branches, and the air is filled with a "
        "subtle floral fragrance. Moss and lichen cling to the roots, "
        "and the filtered light creates shifting patterns on the forest "
        "floor. Occasionally, you spot a bird or butterfly among the "
        "branches.");

    harvestableResource("rosewood", 25, 
        "/lib/instances/items/materials/wood/rosewood.c",
        "a heavily-forested stand of rosewood trees. Several trees "
        "remain", ({ "deciduous tree", "rosewood tree", "tree" }));
    harvestRequiresTool("rosewood", "axe");

    harvestableResource("rosewood seed", 25,
        "/lib/instances/items/food/plants/seeds/rosewood-seed.c", 0,
        ({ "seed" }));
    limitHarvestBySeason("rosewood seed", "summer");
}
