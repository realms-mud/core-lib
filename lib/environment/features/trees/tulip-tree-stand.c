//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tulip tree stand");
    addAdjectives(({ "majestic", "towering", "tall", "magnificent" }));

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
    addSeasonDescription("winter", ({ " standing bare with straight "
        "trunks reaching skyward", " dormant with distinctive bark "
        "patterns", " resting leafless through winter" }));
    addSeasonDescription("spring", ({ " with distinctive four-lobed "
        "leaves just beginning to bud", " sprouting new growth", " with "
        "branches laden with tulip-shaped flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with cone-"
        "like seed clusters", " covered with a thick blanket of "
        "distinctive leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen "
        "leaves of brilliant golden yellow", " with leaves in "
        "spectacular shades of bright yellow" }));

    addAlias("tulip tree");
    addAlias("tulip trees");
    addAlias("stand of tulip trees");
    addAlias("yellow poplar");
    addAlias("tulip poplar");
    addAlias("trees");
    addAlias("tree");

    addDescriptionTemplate("a stand of ##Adjective## tulip trees");
    addItemTemplate("The stand of tulip trees is composed of several "
        "magnificent, straight-trunked trees with distinctive four-"
        "lobed leaves resembling tulip flowers. Their bark is gray "
        "and furrowed, and their massive trunks rise to impressive "
        "heights, forming a cathedral-like canopy overhead. In season, "
        "tulip-shaped orange and yellow flowers bloom high in the "
        "canopy, and the air is filled with the clean scent of one of "
        "the forest's largest hardwoods. Moss and lichen cling to the "
        "roots, and the filtered light creates shifting patterns on "
        "the forest floor. Occasionally, you spot a bird or woodland "
        "creature among these giants of the eastern forest.");

    harvestableResource("tulip tree", 30, 
        "/lib/instances/items/materials/wood/tulip-tree.c",
        "a heavily-forested stand of tulip trees. Several trees "
        "remain", ({ "deciduous tree", "tulip tree", "tree" }));
    harvestRequiresTool("tulip tree", "axe");

    harvestableResource("tulip tree seed", 15,
        "/lib/instances/items/food/plants/seeds/tulip-tree-seed.c", 0,
        ({ "seed" }));
    limitHarvestBySeason("tulip tree seed", "autumn");
}
