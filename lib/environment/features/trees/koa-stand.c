//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("koa stand");
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

    addAlias("koa");
    addAlias("koas");
    addAlias("stand of koas");
    addAlias("trees");
    addAlias("tree");
    addAlias("koa tree");
    addAlias("koa trees");

    addDescriptionTemplate("a stand of ##Adjective## koa trees");
    addItemTemplate("The stand of koas is composed of several tall, "
        "noble Hawaiian trees with distinctive curved grain patterns. "
        "Their bark is smooth and grayish, and their branches spread "
        "wide, forming a dense tropical canopy overhead. In season, "
        "seed pods hang from the branches, and the air is filled with "
        "the rich scent of island hardwood. Moss and lichen cling to "
        "the roots, and the filtered light creates shifting patterns "
        "on the forest floor. Occasionally, you spot a bird or small "
        "creature moving among these prized tropical branches.");

    harvestableResource("koa", 25, 
        "/lib/instances/items/materials/wood/koa.c",
        "a heavily-forested stand of koa trees. Several trees remain",
        ({ "deciduous tree", "koa tree", "tree" }));
    harvestRequiresTool("koa", "axe");

    harvestableResource("koa seed pod", 25,
        "/lib/instances/items/food/plants/seeds/koa-seed-pod.c", 0,
        ({ "seed pod", "pod", "seed" }));
    limitHarvestBySeason("koa seed pod", "summer");
}
