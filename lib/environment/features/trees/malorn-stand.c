//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("malorn stand");
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
        " sprouting new growth", " with branches laden with beautiful "
        "golden flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with fruit",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fruit and "
        "fallen leaves of purple, red, yellow, and orange", " with "
        "leaves in a vivid array of yellow, purple, red, and orange "
        "colors" }));

    addAlias("malorn");
    addAlias("malorns");
    addAlias("stand of malorns");
    addAlias("trees");
    addAlias("tree");
    addAlias("malorn tree");
    addAlias("malorn trees");

    addDescriptionTemplate("a stand of ##Adjective## malorn trees");
    addItemTemplate("The stand of malorns is composed of several "
        "elegant, mystical trees with distinctive golden-tinged bark. "
        "Their branches spread gracefully, forming a shimmering canopy "
        "overhead. In season, golden flowers and magical fruit adorn "
        "the branches, and the air is filled with an otherworldly "
        "fragrance. Moss and lichen cling to the roots, and the "
        "filtered light creates shifting patterns of gold and silver "
        "on the forest floor. Occasionally, you spot magical creatures "
        "or woodland sprites moving among these enchanted branches.");

    harvestableResource("malorn", 25, 
        "/lib/instances/items/materials/wood/malorn.c",
        "a heavily-forested stand of malorn trees. Several trees remain");
    harvestRequiresTool("malorn", "axe");

    harvestableResource("malorn fruit", 25,
        "/lib/instances/items/food/plants/fruit/malorn-fruit.c", 0,
        ({ "deciduous tree", "malorn tree", "tree" }));
    limitHarvestBySeason("malorn fruit", "summer");

    harvestableResource("malorn flower", 25,
        "/lib/instances/items/food/plants/flowers/malorn-flower.c", 0,
        ({ "flower" }));
    limitHarvestBySeason("malorn flower", "spring");
}
