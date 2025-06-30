//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("beech stand");
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
    addSeasonDescription("summer", ({ " with branches laden with nuts",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen "
        "leaves of red, yellow, and orange", " with leaves in a vivid "
        "array of yellow, red, and orange colors" }));

    addAlias("beech");
    addAlias("beeches");
    addAlias("stand of beeches");
    addAlias("trees");
    addAlias("tree");
    addAlias("beech tree");
    addAlias("beech trees");

    addDescriptionTemplate("a stand of ##Adjective## beech trees");
    addItemTemplate("The stand of beeches is composed of several "
        "thick-trunked, stately trees with distinctive smooth, gray "
        "bark. Their branches spread wide, forming a dense canopy "
        "overhead. In season, triangular nuts enclosed in spiny husks "
        "dot the branches, and the air is filled with the earthy scent "
        "of leaves and nuts. Moss and lichen cling to the roots, and "
        "the filtered light creates shifting patterns on the forest "
        "floor. Occasionally, you spot a squirrel or jay gathering "
        "the nutritious beechnuts among the branches.");

    harvestableResource("beech", 25, 
        "/lib/instances/items/materials/wood/beech.c",
        "a heavily-forested stand of beech trees. Several trees remain",
        ({ "deciduous tree", "beech tree", "tree" }));
    harvestRequiresTool("beech", "axe");

    harvestableResource("beech nut", 25,
        "/lib/instances/items/food/plants/nuts/beech-nut.c", 0,
        ({ "nut" }));
    limitHarvestBySeason("beech nut", "summer");
}
