//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("walnut stand");
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
    addSeasonDescription("summer", ({ " with branches laden with many large globose",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and fallen leaves of red, yellow, and orange",
        " with leaves in a vivid array of yellow, red, and orange colors" }));

    addAlias("walnut");
    addAlias("walnuts");
    addAlias("stand of walnuts");
    addAlias("trees");
    addAlias("tree");
    addAlias("walnut tree");
    addAlias("walnut trees");

    addDescriptionTemplate("a stand of ##Adjective## walnut trees");
    addItemTemplate("The stand of walnuts is composed of several thick-trunked, stately trees. "
        "Their bark is deeply furrowed and dark gray, and their branches spread wide, forming a dense canopy overhead. "
        "In season, walnuts in their husks dot the branches, and the air is filled with the earthy scent of leaves and nuts. "
        "Moss and lichen cling to the roots, and the filtered light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a squirrel or jay gathering nuts among the branches.");

    harvestableResource("walnut tree", 25, "/lib/instances/items/materials/wood/walnut.c",
        "a heavily-forested stand of walnut trees. Several trees remain",
        ({ "deciduous tree", "tree" }));
    harvestRequiresTool("walnut tree", "axe");

    harvestableResource("walnut", 25,
        "/lib/instances/items/food/plants/nuts/walnut.c", 0,
        ({ "nut" }));
    limitHarvestBySeason("walnut", "summer");
}
