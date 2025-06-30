//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("spruce stand");
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
    addSeasonDescription("summer", ({ " with branches laden with closed "
        "cones", " covered with a thick blanket of needles" }));
    addSeasonDescription("autumn", ({ " with cones fallen to the ground "
        "wide open", " with cones and some needles carpeting the ground" }));

    addAlias("spruce");
    addAlias("spruces");
    addAlias("stand of spruces");
    addAlias("trees");
    addAlias("tree");
    addAlias("spruce trees");
    addAlias("spruce tree");

    addDescriptionTemplate("a stand of ##Adjective## spruce trees");
    addItemTemplate("The stand of spruces is composed of several "
        "thick-trunked, towering evergreen trees. Their bark is "
        "reddish-brown and scaly, and their branches spread wide with "
        "dense needle foliage. In season, cones hang from the branches, "
        "and the air is filled with the resinous scent of evergreen. "
        "Moss and lichen cling to the roots, and the filtered light "
        "creates shifting patterns on the forest floor. Occasionally, "
        "you spot a bird or small creature darting among the branches.");

    harvestableResource("spruce", 25, 
        "/lib/instances/items/materials/wood/spruce.c",
        "a heavily-forested stand of spruce trees. Several trees remain",
        ({ "conifer", "evergreen", "spruce tree", "tree" }));
    harvestRequiresTool("spruce", "axe");

    harvestableResource("spruce cone", 25,
        "/lib/instances/items/food/plants/seeds/spruce-cone.c", 0,
        ({ "cone", "pinecone", "conifer cone", "pine cone" }));
    limitHarvestBySeason("spruce cone", "summer");

    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c", 0,
        ({ "nut", "spruce nut" }));
    limitHarvestBySeason("pine nut", "summer");
}
