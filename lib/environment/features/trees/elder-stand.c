//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("elder stand");
    addAdjectives(({ "dense", "bushy", "tall", "fragrant" }));

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
    addSeasonDescription("summer", ({ " with branches laden with flowers "
        "and berries", " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in berries "
        "and fallen leaves of yellow", " with leaves in a vivid array "
        "of yellow and brown colors" }));

    addAlias("elder");
    addAlias("elders");
    addAlias("stand of elders");
    addAlias("elderberry");
    addAlias("elderberries");
    addAlias("trees");
    addAlias("tree");
    addAlias("elder tree");
    addAlias("elder trees");

    addDescriptionTemplate("a stand of ##Adjective## elder trees");
    addItemTemplate("The stand of elders is composed of several "
        "multi-stemmed, shrub-like trees with compound leaves. Their "
        "bark is light gray and corky, and their branches spread "
        "densely, forming a thick understory. In season, large flat "
        "clusters of small white flowers bloom, followed by dark "
        "purple berries, and the air is filled with the sweet, musty "
        "scent of elderflowers. Moss and lichen cling to the roots, "
        "and the filtered light creates shifting patterns on the "
        "forest floor. Occasionally, you spot a bird or herbalist "
        "gathering the medicinal flowers and berries among the "
        "branches.");

    harvestableResource("elder", 20, 
        "/lib/instances/items/materials/wood/elder.c",
        "a heavily-forested stand of elder trees. Several trees remain",
        ({ "deciduous tree", "elder tree", "tree" }));
    harvestRequiresTool("elder", "axe");

    harvestableResource("elderberry", 25,
        "/lib/instances/items/food/plants/fruit/elderberry.c", 0,
        ({ "berry", "fruit" }));
    limitHarvestBySeason("elderberry", "autumn");

    harvestableResource("elderflower", 25,
        "/lib/instances/items/food/plants/flowers/elderflower.c", 0,
        ({ "flower" }));
    limitHarvestBySeason("elderflower", "summer");
}
