//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("redbud stand");
    addAdjectives(({ "graceful", "flowering", "slender", "ornamental" }));

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
    addSeasonDescription("winter", ({ " standing bare with dark branches",
        " dormant with smooth bark visible", " resting leafless "
        "through winter" }));
    addSeasonDescription("spring", ({ " with heart-shaped leaves just "
        "beginning to bud", " sprouting new growth", " with branches "
        "covered in brilliant pink flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with seed "
        "pods", " covered with a thick blanket of heart-shaped leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in seed "
        "pods and fallen leaves of bright yellow", " with leaves in "
        "brilliant shades of golden yellow" }));

    addAlias("redbud");
    addAlias("redbuds");
    addAlias("stand of redbuds");
    addAlias("trees");
    addAlias("tree");
    addAlias("redbud tree");
    addAlias("redbud trees");

    addDescriptionTemplate("a stand of ##Adjective## redbud trees");
    addItemTemplate("The stand of redbuds is composed of several "
        "small, graceful trees with distinctive heart-shaped leaves. "
        "Their bark is smooth and dark gray, and their branches "
        "spread in an elegant, vase-like pattern. In season, flat "
        "brown seed pods hang from the branches, and the air is "
        "filled with the sweet memory of spring's spectacular pink "
        "bloom display. Moss and lichen cling to the roots, and the "
        "filtered light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a butterfly or bee visiting among the "
        "ornamental branches, or admiring the spectacular spring "
        "flower show.");

    harvestableResource("redbud tree", 20, 
        "/lib/instances/items/materials/wood/redbud.c",
        "a heavily-forested stand of redbud trees. Several trees "
        "remain", ({ "deciduous tree", "redbud tree", "tree" }));
    harvestRequiresTool("redbud tree", "axe");

    harvestableResource("redbud pod", 15,
        "/lib/instances/items/food/plants/seeds/redbud-pod.c", 0,
        ({ "pod", "seed pod", "seed" }));
    limitHarvestBySeason("redbud pod", "autumn");
}
