//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rowan stand");
    addAdjectives(({ "graceful", "slender", "tall", "elegant" }));

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
        " sprouting new growth", " with branches laden with white "
        "flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with berries",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in berries "
        "and fallen leaves of red, yellow, and orange", " with leaves "
        "in a vivid array of yellow, red, and orange colors" }));

    addAlias("rowan");
    addAlias("rowans");
    addAlias("stand of rowans");
    addAlias("mountain ash");
    addAlias("mountain ashes");
    addAlias("trees");
    addAlias("tree");
    addAlias("rowan tree");
    addAlias("rowan trees");

    addDescriptionTemplate("a stand of ##Adjective## rowan trees");
    addItemTemplate("The stand of rowans is composed of several "
        "slender-trunked trees with distinctive compound leaves. "
        "Their bark is smooth and silvery-gray, and their branches "
        "spread gracefully, forming a light canopy overhead. In "
        "season, clusters of bright orange-red berries hang from the "
        "branches, and the air is filled with the fresh scent of "
        "mountain woodland. Moss and lichen cling to the roots, and "
        "the filtered light creates shifting patterns on the forest "
        "floor. Occasionally, you spot a bird or small creature "
        "feeding on the colorful berries among the branches.");

    harvestableResource("rowan", 25, 
        "/lib/instances/items/materials/wood/rowan.c",
        "a heavily-forested stand of rowan trees. Several trees remain",
        ({ "deciduous tree", "rowan tree", "tree" }));
    harvestRequiresTool("rowan", "axe");

    harvestableResource("rowan berry", 25,
        "/lib/instances/items/food/plants/fruit/rowan-berry.c", 0,
        ({ "berry", "fruit" }));
    limitHarvestBySeason("rowan berry", "autumn");
}
