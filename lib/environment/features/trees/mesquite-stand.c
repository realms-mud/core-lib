//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mesquite stand");
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
        "leaves of red, yellow, and orange", " with leaves in a vivid "
        "array of yellow and brown colors" }));

    addAlias("mesquite");
    addAlias("mesquites");
    addAlias("stand of mesquites");
    addAlias("trees");
    addAlias("tree");
    addAlias("mesquite tree");
    addAlias("mesquite trees");

    addDescriptionTemplate("a stand of ##Adjective## mesquite trees");
    addItemTemplate("The stand of mesquites is composed of several "
        "drought-adapted trees with distinctive thorny branches. Their "
        "bark is dark brown and deeply furrowed, and their branches "
        "spread wide with small, compound leaves. In season, long seed "
        "pods hang from the branches, and the air is filled with the "
        "earthy scent of desert vegetation. Moss and lichen cling to "
        "the roots, and the filtered light creates shifting patterns "
        "on the arid ground. Occasionally, you spot a bird or small "
        "desert creature moving among the thorny branches.");

    harvestableResource("mesquite", 25, 
        "/lib/instances/items/materials/wood/mesquite.c",
        "a heavily-forested stand of mesquite trees. Several trees "
        "remain", ({ "deciduous tree", "mesquite tree", "tree" }));
    harvestRequiresTool("mesquite", "axe");

    harvestableResource("mesquite seed pod", 25,
        "/lib/instances/items/food/plants/seeds/mesquite-seed-pod.c", 0,
        ({ "seed pod", "pod", "seed" }));
    limitHarvestBySeason("mesquite seed pod", "summer");
}
