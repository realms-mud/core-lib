//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("white pine stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));

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
    addSeasonDescription("summer", ({ " with branches laden with long "
        "cones", " covered with a thick blanket of soft needles" }));
    addSeasonDescription("autumn", ({ " with cones fallen to the ground "
        "wide open", " with cones and some needles carpeting the "
        "ground" }));

    addAlias("white pine");
    addAlias("white pines");
    addAlias("stand of white pines");
    addAlias("trees");
    addAlias("tree");
    addAlias("white pine tree");
    addAlias("white pine trees");

    addDescriptionTemplate("a stand of ##Adjective## white pine trees");
    addItemTemplate("The stand of white pines is composed of several "
        "massive-trunked, towering evergreen trees with distinctive "
        "five-needle clusters. Their bark is smooth and greenish-gray "
        "when young, becoming deeply furrowed with age, and their "
        "branches spread in horizontal whorls with soft, blue-green "
        "needles. In season, long cylindrical cones hang from the "
        "branch tips, and the air is filled with the sweet, resinous "
        "scent of pine. Moss and lichen cling to the roots, and the "
        "filtered light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a bird or small creature moving among "
        "these giants of the northern forest.");

    harvestableResource("white pine", 25, 
        "/lib/instances/items/materials/wood/white-pine.c",
        "a heavily-forested stand of white pine trees. Several trees "
        "remain", ({ "conifer", "evergreen", "white pine tree", "tree" }));
    harvestRequiresTool("white pine", "axe");

    harvestableResource("white pine cone", 25,
        "/lib/instances/items/food/plants/seeds/white-pine-cone.c", 0,
        ({ "cone", "pinecone", "conifer cone", "pine cone" }));
    limitHarvestBySeason("white pine cone", "summer");

    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c", 0,
        ({ "nut", "white pine nut" }));
    limitHarvestBySeason("pine nut", "summer");
}
