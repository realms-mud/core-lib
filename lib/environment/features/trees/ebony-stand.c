//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ebony stand");
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

    addAlias("ebony");
    addAlias("ebonies");
    addAlias("stand of ebonies");
    addAlias("trees");
    addAlias("tree");
    addAlias("ebony tree");
    addAlias("ebony trees");

    addDescriptionTemplate("a stand of ##Adjective## ebony trees");
    addItemTemplate("The stand of ebonies is composed of several "
        "tall, dense tropical trees with distinctively black "
        "heartwood. Their bark is smooth and dark, and their branches "
        "spread wide, forming a dense canopy overhead. In season, "
        "seed pods hang from the branches, and the air is filled with "
        "the rich scent of precious hardwood. Moss and lichen cling "
        "to the roots, and the filtered light creates shifting "
        "patterns on the forest floor. Occasionally, you spot a bird "
        "or small creature moving among these valuable, dark-wooded "
        "branches.");

    harvestableResource("ebony", 25, 
        "/lib/instances/items/materials/wood/ebony.c",
        "a heavily-forested stand of ebony trees. Several trees remain",
        ({ "deciduous tree", "ebony tree", "tree" }));
    harvestRequiresTool("ebony", "axe");

    harvestableResource("ebony seed pod", 25,
        "/lib/instances/items/food/plants/seeds/ebony-seed-pod.c", 0,
        ({ "seed pod", "pod", "seed" }));
    limitHarvestBySeason("ebony seed pod", "summer");
}
