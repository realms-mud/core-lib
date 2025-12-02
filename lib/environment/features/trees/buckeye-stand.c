//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("buckeye stand");
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
        " sprouting new growth", " with branches laden with catkins" }));
    addSeasonDescription("summer", ({ " with branches laden with many large "
        "globose", " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and "
        "fallen leaves of red, yellow, and orange", " with leaves in a "
        "vivid array of yellow, red, and orange colors" }));

    addAlias("buckeye");
    addAlias("buckeyes");
    addAlias("stand of buckeyes");
    addAlias("trees");
    addAlias("tree");
    addAlias("buckeye tree");
    addAlias("buckeye trees");

    addDescriptionTemplate("a stand of ##Adjective## buckeye trees");
    addItemTemplate("The stand of buckeyes is composed of several "
        "thick-trunked, stately trees with distinctive palmate leaves. "
        "Their bark is grayish-brown and slightly rough, and their "
        "branches spread wide, forming a dense canopy overhead. In "
        "season, large spiny seed cases containing glossy brown nuts "
        "dot the branches, and the air is filled with the earthy "
        "scent of leaves and nuts. Moss and lichen cling to the roots, "
        "and the filtered light creates shifting patterns on the "
        "forest floor. Occasionally, you spot a squirrel or small "
        "creature gathering the distinctive nuts among the branches.");

    harvestableResource("buckeye", 25, 
        "/lib/instances/items/materials/wood/buckeye.c",
        "a heavily-forested stand of buckeye trees. Several trees "
        "remain", ({ "deciduous tree", "buckeye tree", "tree" }));
    harvestRequiresTool("buckeye", "axe");

    harvestableResource("buckeye globose", 25,
        "/lib/instances/items/food/plants/seeds/buckeye-globose.c", 0,
        ({ "globose" }));
    limitHarvestBySeason("buckeye globose", "summer");
}
