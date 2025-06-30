//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("olive stand");
    addAdjectives(({ "ancient", "gnarled", "silvery", "Mediterranean" }));

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
    addSeasonDescription("winter", ({ " with silvery leaves shimmering "
        "in winter light", " maintaining their evergreen foliage" }));
    addSeasonDescription("spring", ({ " with new silver-green growth",
        " sprouting fresh leaves", " with branches laden with small "
        "white flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with olives",
        " covered with a thick blanket of silvery leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in olives "
        "and occasional fallen leaves", " heavy with the olive harvest" }));

    addAlias("olive");
    addAlias("olives");
    addAlias("stand of olives");
    addAlias("trees");
    addAlias("tree");
    addAlias("olive tree");
    addAlias("olive trees");

    addDescriptionTemplate("a stand of ##Adjective## olive trees");
    addItemTemplate("The stand of olives is composed of several "
        "ancient-looking trees with distinctive gnarled trunks and "
        "silvery-green leaves. Their bark is deeply furrowed and "
        "gray-brown, and their branches spread with an ancient "
        "dignity, forming a Mediterranean canopy overhead. In season, "
        "small green and black olives hang from the branches, and the "
        "air is filled with the distinctive, slightly bitter scent of "
        "olive wood and fruit. Moss and lichen cling to the roots, "
        "and the filtered light creates shifting patterns on the grove "
        "floor. Occasionally, you spot a bird or harvester working "
        "among the valuable fruit-bearing branches.");

    harvestableResource("olive tree", 25, 
        "/lib/instances/items/materials/wood/olive.c",
        "a heavily-forested stand of olive trees. Several trees remain",
        ({ "evergreen tree", "olive tree", "tree" }));
    harvestRequiresTool("olive tree", "axe");

    harvestableResource("olive", 20,
        "/lib/instances/items/food/plants/fruit/olive.c", 0,
        ({ "fruit" }));
    limitHarvestBySeason("olive", "autumn");
}
