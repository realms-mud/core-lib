//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("scots pine stand");
    addAdjectives(({ "hardy", "towering", "tall", "rugged" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with branches just catching the faint dawn light",
        "outlined softly as the day begins"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight filtering through the needles"
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
        "with needles glowing in the golden evening light",
        "as the sun sets behind the dense canopy"
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
    addSeasonDescription("spring", ({ " with brilliant green new growth "
        "sprouting", " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with small "
        "cones", " covered with a thick blanket of blue-green needles" }));
    addSeasonDescription("autumn", ({ " with cones fallen to the ground "
        "wide open", " with cones and some needles carpeting the "
        "ground" }));

    addAlias("scots pine");
    addAlias("scots pines");
    addAlias("stand of scots pines");
    addAlias("scotch pine");
    addAlias("scotch pines");
    addAlias("trees");
    addAlias("tree");
    addAlias("scots pine tree");
    addAlias("scots pine trees");

    addDescriptionTemplate("a stand of ##Adjective## scots pine trees");
    addItemTemplate("The stand of scots pines is composed of several "
        "sturdy-trunked, hardy evergreen trees with distinctive "
        "orange-red bark on the upper trunk and branches. Their lower "
        "bark is deeply furrowed and grayish-brown, and their branches "
        "spread with blue-green needles in pairs. In season, small "
        "oval cones dot the branches, and the air is filled with the "
        "sharp, resinous scent of northern pine. Moss and lichen cling "
        "to the roots, and the filtered light creates shifting patterns "
        "on the forest floor. Occasionally, you spot a bird or small "
        "creature moving among these resilient trees of the Scottish "
        "highlands.");

    harvestableResource("scots pine", 25, 
        "/lib/instances/items/materials/wood/scots-pine.c",
        "a heavily-forested stand of scots pine trees. Several trees "
        "remain", ({ "conifer", "evergreen", "scots pine tree", "tree" }));
    harvestRequiresTool("scots pine", "axe");

    harvestableResource("scots pine cone", 25,
        "/lib/instances/items/food/plants/seeds/scots-pine-cone.c", 0,
        ({ "cone", "pinecone", "conifer cone", "pine cone" }));
    limitHarvestBySeason("scots pine cone", "summer");

    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c", 0,
        ({ "nut", "scots pine nut" }));
    limitHarvestBySeason("pine nut", "summer");
}
