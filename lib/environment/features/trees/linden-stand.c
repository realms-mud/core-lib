//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("linden stand");
    addAdjectives(({ "majestic", "towering", "tall", "broad" }));

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
    addSeasonDescription("summer", ({ " with branches laden with fragrant "
        "flowers", " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen "
        "leaves of golden yellow", " with leaves in a vivid array of "
        "golden yellow colors" }));

    addAlias("linden");
    addAlias("lindens");
    addAlias("stand of lindens");
    addAlias("lime tree");
    addAlias("lime trees");
    addAlias("trees");
    addAlias("tree");
    addAlias("linden tree");
    addAlias("linden trees");

    addDescriptionTemplate("a stand of ##Adjective## linden trees");
    addItemTemplate("The stand of lindens is composed of several "
        "thick-trunked, stately trees with distinctive heart-shaped "
        "leaves. Their bark is smooth and grayish-brown, and their "
        "branches spread wide, forming a dense canopy overhead. In "
        "season, clusters of small, fragrant yellow flowers bloom, "
        "and the air is filled with the sweet, honey-like scent of "
        "linden blossoms. Moss and lichen cling to the roots, and the "
        "filtered light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a bee or bird visiting among the "
        "aromatic flowering branches.");

    harvestableResource("linden", 25, 
        "/lib/instances/items/materials/wood/linden.c",
        "a heavily-forested stand of linden trees. Several trees "
        "remain", ({ "deciduous tree", "linden tree", "tree" }));
    harvestRequiresTool("linden", "axe");

    harvestableResource("linden flower", 25,
        "/lib/instances/items/food/plants/flowers/linden-flower.c", 0,
        ({ "flower" }));
    limitHarvestBySeason("linden flower", "summer");
}
