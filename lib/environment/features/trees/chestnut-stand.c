//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("chestnut stand");
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
        " sprouting new growth", " with branches laden with white "
        "flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with nuts",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and "
        "fallen leaves of red, yellow, and orange", " with leaves in a "
        "vivid array of yellow, red, and orange colors" }));

    addAlias("chestnut");
    addAlias("chestnuts");
    addAlias("stand of chestnuts");
    addAlias("trees");
    addAlias("tree");
    addAlias("chestnut tree");
    addAlias("chestnut trees");

    addDescriptionTemplate("a stand of ##Adjective## chestnut trees");
    addItemTemplate("The stand of chestnuts is composed of several "
        "thick-trunked, stately trees with distinctive serrated "
        "leaves. Their bark is deeply furrowed and dark brown, and "
        "their branches spread wide, forming a dense canopy overhead. "
        "In season, spiny burrs containing glossy brown chestnuts "
        "litter the ground beneath, and the air is filled with the "
        "earthy scent of leaves and nuts. Moss and lichen cling to "
        "the roots, and the filtered light creates shifting patterns "
        "on the forest floor. Occasionally, you spot a squirrel or "
        "wild boar gathering the nutritious chestnuts among the "
        "branches.");

    harvestableResource("chestnut", 25, 
        "/lib/instances/items/materials/wood/chestnut.c",
        "a heavily-forested stand of chestnut trees. Several trees "
        "remain", ({ "deciduous tree", "chestnut tree", "tree" }));
    harvestRequiresTool("chestnut", "axe");

    harvestableResource("chestnut nut", 25,
        "/lib/instances/items/food/plants/nuts/chestnut.c", 0,
        ({ "chestnut", "nut" }));
    limitHarvestBySeason("chestnut nut", "autumn");
}
