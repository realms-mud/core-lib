//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pecan stand");
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

    addAlias("pecan");
    addAlias("pecans");
    addAlias("stand of pecans");
    addAlias("trees");
    addAlias("tree");
    addAlias("pecan tree");
    addAlias("pecan trees");

    addDescriptionTemplate("a stand of ##Adjective## pecan trees");
    addItemTemplate("The stand of pecans is composed of several "
        "thick-trunked, stately trees. Their bark is deeply furrowed "
        "and grayish-brown, and their branches spread wide, forming a "
        "dense canopy overhead. In season, pecans in their husks dot "
        "the branches, and the air is filled with the earthy scent of "
        "leaves and nuts. Moss and lichen cling to the roots, and the "
        "filtered light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a squirrel or jay gathering nuts among "
        "the branches.");

    harvestableResource("pecan tree", 25, 
        "/lib/instances/items/materials/wood/pecan.c",
        "a heavily-forested stand of pecan trees. Several trees remain",
        ({ "deciduous tree", "tree" }));
    harvestRequiresTool("pecan tree", "axe");

    harvestableResource("pecan", 10,
        "/lib/instances/items/food/plants/nuts/pecan.c", 0,
        ({ "nut" }));
    limitHarvestBySeason("pecan", "summer");
}
