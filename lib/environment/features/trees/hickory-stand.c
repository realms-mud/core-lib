//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hickory stand");
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
    addSeasonDescription("summer", ({ " with branches laden with nuts",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and "
        "fallen leaves of red, yellow, and orange", " with leaves in a "
        "vivid array of yellow, red, and orange colors" }));

    addAlias("hickory");
    addAlias("hickories");
    addAlias("stand of hickories");
    addAlias("trees");
    addAlias("tree");
    addAlias("hickory tree");
    addAlias("hickory trees");

    addDescriptionTemplate("a stand of ##Adjective## hickory trees");
    addItemTemplate("The stand of hickories is composed of several "
        "thick-trunked, sturdy trees. Their bark is deeply furrowed "
        "and grayish-brown, and their branches spread wide, forming "
        "a dense canopy overhead. In season, hickory nuts in their "
        "husks dot the branches, and the air is filled with the earthy "
        "scent of leaves and nuts. Moss and lichen cling to the roots, "
        "and the filtered light creates shifting patterns on the "
        "forest floor. Occasionally, you spot a squirrel or jay "
        "gathering nuts among the branches.");

    harvestableResource("hickory", 25, 
        "/lib/instances/items/materials/wood/hickory.c",
        "a heavily-forested stand of hickory trees. Several trees "
        "remain", ({ "deciduous tree", "hickory tree", "tree" }));
    harvestRequiresTool("hickory", "axe");

    harvestableResource("hickory globose", 25,
        "/lib/instances/items/food/plants/nuts/hickory-globose.c", 0,
        ({ "globose" }));
    limitHarvestBySeason("hickory globose", "summer");
}
