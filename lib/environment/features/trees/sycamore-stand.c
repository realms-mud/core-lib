//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sycamore stand");
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
    addSeasonDescription("summer", ({ " with branches laden with their small fruit",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in leaves of yellow and orange",
        " with leaves in a vivid array of yellow and orange colors" }));

    addAlias("sycamore");
    addAlias("sycamores");
    addAlias("stand of sycamores");
    addAlias("trees");
    addAlias("tree");
    addAlias("sycamore tree");
    addAlias("sycamore trees");

    addDescriptionTemplate("a stand of ##Adjective## sycamore trees");
    addItemTemplate("The stand of sycamores is composed of several "
        "thick-trunked, stately trees. Their bark is distinctively mottled "
        "with patches of brown, gray, and cream that peel away in irregular plates. "
        "In season, small round fruits hang from the branches, and the air is "
        "filled with the earthy scent of leaves and bark. Moss and lichen "
        "cling to the roots, and the filtered light creates shifting patterns "
        "on the forest floor. Occasionally, you spot a bird or small creature "
        "darting among the branches.");

    harvestableResource("sycamore", 25, "/lib/instances/items/materials/wood/sycamore.c",
        "a heavily-forested stand of sycamore trees. Several trees remain",
        ({ "deciduous tree", "sycamore tree", "tree" }));
    harvestRequiresTool("sycamore", "axe");

    harvestableResource("sycamore fruit", 25,
        "/lib/instances/items/food/plants/fruit/sycamore-fruit.c", 0,
        ({ "fruit" }));
    limitHarvestBySeason("sycamore fruit", "summer");
}
