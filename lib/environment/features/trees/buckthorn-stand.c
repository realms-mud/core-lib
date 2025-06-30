//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("buckthorn stand");
    addAdjectives(({ "broad", "short", "tall", "slender" }));

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
    addSeasonDescription("summer", ({ " with branches laden with many fruit",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and "
        "fallen leaves of red, yellow, and orange", " with leaves in a "
        "vivid array of yellow, red, and orange colors" }));

    addAlias("buckthorn");
    addAlias("buckthorns");
    addAlias("stand of buckthorns");
    addAlias("trees");
    addAlias("tree");
    addAlias("buckthorn tree");
    addAlias("buckthorn trees");

    addDescriptionTemplate("a stand of ##Adjective## buckthorn trees");
    addItemTemplate("The stand of buckthorns is composed of several "
        "small to medium-sized, hardy shrub-like trees with thorny "
        "branches. Their bark is dark and rough, and their branches "
        "spread densely, forming a protective thicket. In season, "
        "small dark berries cluster on the branches, and the air is "
        "filled with the earthy scent of wild growth. Moss and lichen "
        "cling to the roots, and the filtered light creates shifting "
        "patterns on the undergrowth. Occasionally, you spot a bird "
        "or small creature carefully navigating among the thorny "
        "branches.");

    harvestableResource("buckthorn", 25, 
        "/lib/instances/items/materials/wood/buckthorn.c",
        "a heavily-forested stand of buckthorn trees. Several trees "
        "remain", ({ "deciduous tree", "buckthorn tree", "tree" }));
    harvestRequiresTool("buckthorn", "axe");

    harvestableResource("buckthorn fruit", 25,
        "/lib/instances/items/food/plants/fruit/buckthorn-fruit.c", 0,
        ({ "fruit" }));
    limitHarvestBySeason("buckthorn fruit", "summer");
}
