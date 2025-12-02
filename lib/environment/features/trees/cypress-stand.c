//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cypress stand");
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
        "wide open", " with cones and some needles carpeting the "
        "ground" }));

    addAlias("cypress");
    addAlias("cypresses");
    addAlias("stand of cypresses");
    addAlias("trees");
    addAlias("tree");
    addAlias("cypress tree");
    addAlias("cypress trees");

    addDescriptionTemplate("a stand of ##Adjective## cypress trees");
    addItemTemplate("The stand of cypresses is composed of several "
        "tall, stately evergreen trees with distinctive pyramid "
        "shapes. Their bark is fibrous and reddish-brown, and their "
        "branches spread with scale-like needle foliage. In season, "
        "small round cones dot the branches, and the air is filled "
        "with the aromatic scent of cypress wood. Moss and lichen "
        "cling to the roots, and the filtered light creates shifting "
        "patterns on the forest floor. Occasionally, you spot a bird "
        "or small creature moving among the aromatic branches.");

    harvestableResource("cypress", 25, 
        "/lib/instances/items/materials/wood/cypress.c",
        "a heavily-forested stand of cypress trees. Several trees "
        "remain", ({ "conifer", "evergreen", "cypress tree", "tree" }));
    harvestRequiresTool("cypress", "axe");

    harvestableResource("cypress cone", 25,
        "/lib/instances/items/food/plants/seeds/cypress-cone.c", 0,
        ({ "cone", "pinecone", "conifer cone", "pine cone" }));
    limitHarvestBySeason("cypress cone", "summer");

    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c", 0,
        ({ "nut", "cypress nut" }));
    limitHarvestBySeason("pine nut", "summer");
}
