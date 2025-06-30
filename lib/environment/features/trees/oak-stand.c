//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("oak stand");
    addAdjectives(({ "majestic", "towering", "ancient", "broad", "sprawling" }));

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
    addSeasonDescription("winter", ({
        "with branches layered in snow",
        "encased in a delicate film of frost",
        "standing bare and silent through the cold"
        }));
    addSeasonDescription("spring", ({
        "with leaves just beginning to bud",
        "sprouting new growth along every branch",
        "alive with the promise of spring"
        }));
    addSeasonDescription("summer", ({
        "with branches laden with acorns",
        "covered in a thick blanket of green leaves",
        "offering deep shade in the summer heat"
        }));
    addSeasonDescription("autumn", ({
        "carpeting the ground in fallen leaves of red, yellow, and orange",
        "with leaves in a vivid array of autumn colors",
        "dropping acorns and leaves as the season turns"
        }));

    addAlias("oak");
    addAlias("oaks");
    addAlias("stand of oaks");
    addAlias("trees");
    addAlias("tree");
    addAlias("oak trees");
    addAlias("oak tree");

    addDescriptionTemplate("a stand of ##Adjective## oak trees");
    addItemTemplate("The stand of oaks is composed of several thick-trunked, ancient trees. "
        "Their bark is deeply furrowed and their branches spread wide, forming a dense canopy overhead. "
        "In season, acorns litter the ground beneath, and the air is filled with the earthy scent of leaves and wood. "
        "Moss and lichen cling to the roots, and the filtered light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a squirrel or jay darting among the branches.");

    harvestableResource("oak", 25, "/lib/instances/items/materials/wood/oak.c",
        "a heavily-forested stand of oak trees. Several trees remain",
        ({ "deciduous tree", "oak tree", "tree" }));
    harvestRequiresTool("oak", "axe");

    harvestableResource("acorn", 25,
        "/lib/instances/items/food/plants/nuts/acorn.c", 0,
        ({ "acorn nut", "nut" }));
    limitHarvestBySeason("acorn", "summer");
}
