//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("magnolia stand");
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
    addSeasonDescription("autumn", ({ " carpeting the ground in fruit and "
        "fallen leaves of red, yellow, and orange", " with leaves in a "
        "vivid array of yellow, red, and orange colors" }));

    addAlias("magnolia");
    addAlias("magnolias");
    addAlias("stand of magnolias");
    addAlias("trees");
    addAlias("tree");
    addAlias("magnolia tree");
    addAlias("magnolia trees");

    addDescriptionTemplate("a stand of ##Adjective## magnolia trees");
    addItemTemplate("The stand of magnolias is composed of several "
        "elegant trees with distinctive large, waxy leaves. Their bark "
        "is smooth and grayish-brown, and their branches spread "
        "gracefully, forming a beautiful canopy overhead. In season, "
        "large fragrant flowers and cone-like fruits adorn the "
        "branches, and the air is filled with the sweet floral "
        "fragrance. Moss and lichen cling to the roots, and the "
        "filtered light creates shifting patterns on the garden floor. "
        "Occasionally, you spot a bird or butterfly visiting among the "
        "spectacular blooms.");

    harvestableResource("magnolia", 25, 
        "/lib/instances/items/materials/wood/magnolia.c",
        "a heavily-forested stand of magnolia trees. Several trees "
        "remain", ({ "deciduous tree", "magnolia tree", "tree" }));
    harvestRequiresTool("magnolia", "axe");

    harvestableResource("magnolia fruit", 25,
        "/lib/instances/items/food/plants/fruit/magnolia-fruit.c", 0,
        ({ "fruit" }));
    limitHarvestBySeason("magnolia fruit", "summer");

    harvestableResource("magnolia flower", 25,
        "/lib/instances/items/food/plants/flowers/magnolia-flower.c", 0,
        ({ "flower" }));
    limitHarvestBySeason("magnolia flower", "spring");
}
