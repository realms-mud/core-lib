//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("almond stand");
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
        " sprouting new growth", " with branches laden with catkins" }));
    addSeasonDescription("summer", ({ " with branches laden with many large "
        "globose", " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and "
        "fallen leaves of red, yellow, and orange", " with leaves in a "
        "vivid array of yellow, red, and orange colors" }));

    addAlias("almond");
    addAlias("almonds");
    addAlias("stand of almonds");
    addAlias("trees");
    addAlias("tree");
    addAlias("almond tree");
    addAlias("almond trees");

    addDescriptionTemplate("a stand of ##Adjective## almond trees");
    addItemTemplate("The stand of almonds is composed of several "
        "medium-sized, productive trees with smooth, dark gray bark. "
        "Their branches spread gracefully, forming a pleasant canopy "
        "overhead. In season, almond nuts in their green hulls hang "
        "from the branches, and the air is filled with the sweet scent "
        "of almond blossoms and developing nuts. Moss and lichen cling "
        "to the roots, and the filtered light creates shifting patterns "
        "on the orchard floor. Occasionally, you spot a bird or bee "
        "visiting among the nut-bearing branches.");

    harvestableResource("almond tree", 25, 
        "/lib/instances/items/materials/wood/almond.c",
        "a heavily-forested stand of almond trees. Several trees remain",
        ({ "deciduous tree","tree" }));
    harvestRequiresTool("almond tree", "axe");

    harvestableResource("almond", 10,
        "/lib/instances/items/food/plants/nuts/almond.c", 0,
        ({ "nut" }));
    limitHarvestBySeason("almond", "summer");
}
