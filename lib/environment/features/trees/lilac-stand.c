//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lilac stand");
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
        " sprouting new growth", " with branches laden with violet "
        "flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with fruit",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fruit and "
        "fallen leaves of red, yellow, and orange", " with leaves in a "
        "vivid array of yellow, red, and orange colors" }));

    addAlias("lilac");
    addAlias("lilacs");
    addAlias("stand of lilacs");
    addAlias("trees");
    addAlias("tree");
    addAlias("lilac tree");
    addAlias("lilac trees");

    addDescriptionTemplate("a stand of ##Adjective## lilac trees");
    addItemTemplate("The stand of lilacs is composed of several "
        "medium-sized, graceful trees with heart-shaped leaves. Their "
        "bark is smooth and grayish-brown, and their branches spread "
        "elegantly, forming a pleasant canopy overhead. In season, "
        "clusters of fragrant purple flowers bloom profusely, and the "
        "air is filled with the intoxicating floral scent. Moss and "
        "lichen cling to the roots, and the filtered light creates "
        "shifting patterns on the garden floor. Occasionally, you spot "
        "a butterfly or bee visiting among the aromatic blossoms.");

    harvestableResource("lilac", 25, 
        "/lib/instances/items/materials/wood/lilac.c",
        "a heavily-forested stand of lilac trees. Several trees remain",
        ({ "deciduous tree", "lilac tree", "tree" }));
    harvestRequiresTool("lilac", "axe");

    harvestableResource("lilac fruit", 25,
        "/lib/instances/items/food/plants/fruit/lilac-fruit.c", 0,
        ({ "fruit" }));
    limitHarvestBySeason("lilac fruit", "summer");

    harvestableResource("lilac flower", 25,
        "/lib/instances/items/food/plants/flowers/lilac-flower.c", 0,
        ({ "flower" }));
    limitHarvestBySeason("lilac flower", "spring");
}
