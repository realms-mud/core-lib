//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ironwood stand");
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
        "leaves of yellow", " with leaves in a vivid array of yellow "
        "and brown colors" }));

    addAlias("ironwood");
    addAlias("ironwoods");
    addAlias("stand of ironwoods");
    addAlias("trees");
    addAlias("tree");
    addAlias("ironwood tree");
    addAlias("ironwood trees");

    addDescriptionTemplate("a stand of ##Adjective## ironwood trees");
    addItemTemplate("The stand of ironwoods is composed of several "
        "extremely dense, durable trees with incredibly hard wood. "
        "Their bark is dark and deeply furrowed, and their branches "
        "spread with sturdy strength, forming an almost impenetrable "
        "canopy overhead. In season, seed pods hang from the branches, "
        "and the air is filled with the earthy scent of the hardest "
        "wood. Moss and lichen cling to the roots, and the filtered "
        "light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a bird or small creature moving among "
        "these incredibly strong branches.");

    harvestableResource("ironwood", 25, 
        "/lib/instances/items/materials/wood/ironwood.c",
        "a heavily-forested stand of ironwood trees. Several trees "
        "remain", ({ "deciduous tree", "ironwood tree", "tree" }));
    harvestRequiresTool("ironwood", "axe");

    harvestableResource("ironwood seed pod", 25,
        "/lib/instances/items/food/plants/seeds/ironwood-seed-pod.c", 0,
        ({ "seed pod", "pod", "seed" }));
    limitHarvestBySeason("ironwood seed pod", "summer");
}
