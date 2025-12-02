//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("holly stand");
    addAdjectives(({ "majestic", "towering", "tall", "slender" }));

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
        " sprouting new growth", " with branches laden with small "
        "flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with berries",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in berries "
        "and fallen leaves of yellow and brown", " with leaves in a "
        "vivid array of yellow and brown colors" }));

    addAlias("holly");
    addAlias("hollies");
    addAlias("stand of hollies");
    addAlias("trees");
    addAlias("tree");
    addAlias("holly tree");
    addAlias("holly trees");

    addDescriptionTemplate("a stand of ##Adjective## holly trees");
    addItemTemplate("The stand of hollies is composed of several "
        "evergreen trees with distinctive spiny, glossy leaves. Their "
        "bark is smooth and grayish, and their branches spread "
        "densely, forming a protective canopy overhead. In season, "
        "bright red berries dot the branches, and the air is filled "
        "with the fresh scent of evergreen foliage. Moss and lichen "
        "cling to the roots, and the filtered light creates shifting "
        "patterns on the forest floor. Occasionally, you spot a bird "
        "or small creature moving carefully among the thorny branches.");

    harvestableResource("holly", 25, 
        "/lib/instances/items/materials/wood/holly.c",
        "a heavily-forested stand of holly trees. Several trees remain",
        ({ "evergreen tree", "holly tree", "tree" }));
    harvestRequiresTool("holly", "axe");

    harvestableResource("holly berry", 25,
        "/lib/instances/items/food/plants/fruit/holly-berry.c", 0,
        ({ "berry", "fruit" }));
    limitHarvestBySeason("holly berry", "summer");
}
