//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fig stand");
    addAdjectives(({ "spreading", "broad", "tall", "Mediterranean" }));

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
    addSeasonDescription("winter", ({ " dormant with bare branches",
        " standing leafless in the cold", " resting through winter" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud",
        " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with fruit",
        " covered with a thick blanket of large leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fruit and "
        "fallen leaves", " with leaves in warm shades of yellow" }));

    addAlias("fig");
    addAlias("figs");
    addAlias("stand of figs");
    addAlias("trees");
    addAlias("tree");
    addAlias("fig tree");
    addAlias("fig trees");

    addDescriptionTemplate("a stand of ##Adjective## fig trees");
    addItemTemplate("The stand of figs is composed of several "
        "broad-canopied trees with distinctive large, lobed leaves. "
        "Their bark is smooth and light gray, and their branches "
        "spread wide, forming dense shade overhead. In season, small "
        "green and purple figs hang from the branches, and the air is "
        "filled with the sweet, honeyed scent of ripening fruit. Moss "
        "and lichen cling to the roots, and the filtered light creates "
        "shifting patterns on the orchard floor. Occasionally, you "
        "spot a bird or bee visiting among the abundant fruit-laden "
        "branches.");

    harvestableResource("fig tree", 25, 
        "/lib/instances/items/materials/wood/fig.c",
        "a heavily-forested stand of fig trees. Several trees remain",
        ({ "deciduous tree", "fig tree", "tree" }));
    harvestRequiresTool("fig tree", "axe");

    harvestableResource("fig", 20,
        "/lib/instances/items/food/plants/fruit/fig.c", 0,
        ({ "fruit" }));
    limitHarvestBySeason("fig", "summer");
}
