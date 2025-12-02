//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hornbeam stand");
    addAdjectives(({ "sturdy", "dense", "tall", "muscled" }));

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
    addSeasonDescription("summer", ({ " with branches laden with winged "
        "nutlets", " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nutlets "
        "and fallen leaves of yellow", " with leaves in a vivid array "
        "of yellow and brown colors" }));

    addAlias("hornbeam");
    addAlias("hornbeams");
    addAlias("stand of hornbeams");
    addAlias("ironwood");
    addAlias("musclewood");
    addAlias("trees");
    addAlias("tree");
    addAlias("hornbeam tree");
    addAlias("hornbeam trees");

    addDescriptionTemplate("a stand of ##Adjective## hornbeam trees");
    addItemTemplate("The stand of hornbeams is composed of several "
        "sturdy-trunked trees with distinctive smooth, muscled bark. "
        "Their bark is blue-gray and fluted, resembling flexed "
        "muscles, and their branches spread with serrated leaves. In "
        "season, small winged nutlets hang from the branches, and the "
        "air is filled with the earthy scent of hardwood forest. Moss "
        "and lichen cling to the roots, and the filtered light creates "
        "shifting patterns on the forest floor. Occasionally, you spot "
        "a woodpecker or craftsman seeking this incredibly hard wood "
        "among the branches.");

    harvestableResource("hornbeam", 25, 
        "/lib/instances/items/materials/wood/hornbeam.c",
        "a heavily-forested stand of hornbeam trees. Several trees "
        "remain", ({ "deciduous tree", "hornbeam tree", "tree" }));
    harvestRequiresTool("hornbeam", "axe");

    harvestableResource("hornbeam nutlet", 20,
        "/lib/instances/items/food/plants/nuts/hornbeam-nutlet.c", 0,
        ({ "nutlet", "nut" }));
    limitHarvestBySeason("hornbeam nutlet", "autumn");
}
