//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("redwood stand");
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
        "as the sun sets behind the towering canopy"
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

    addAlias("redwood");
    addAlias("redwoods");
    addAlias("stand of redwoods");
    addAlias("trees");
    addAlias("tree");
    addAlias("redwood tree");
    addAlias("redwood trees");

    addDescriptionTemplate("a stand of ##Adjective## redwood trees");
    addItemTemplate("The stand of redwoods is composed of several "
        "enormous-trunked, ancient evergreen trees reaching incredible "
        "heights. Their bark is thick, fibrous, and reddish-brown, and "
        "their branches spread wide high above, forming a cathedral-like "
        "canopy. In season, small cones dot the upper branches, and the "
        "air is filled with the earthy scent of ancient forest. Ferns "
        "and moss carpet the ground, and shafts of filtered light create "
        "an almost mystical atmosphere. Occasionally, you spot wildlife "
        "moving quietly among these giants.");

    harvestableResource("redwood", 25, 
        "/lib/instances/items/materials/wood/redwood.c",
        "a heavily-forested stand of redwood trees. Several trees remain",
        ({ "conifer", "evergreen", "redwood tree", "tree" }));
    harvestRequiresTool("redwood", "axe");

    harvestableResource("redwood cone", 25,
        "/lib/instances/items/food/plants/seeds/redwood-cone.c", 0,
        ({ "cone", "pinecone", "conifer cone", "pine cone" }));
    limitHarvestBySeason("redwood cone", "summer");

    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c", 0,
        ({ "nut", "redwood nut" }));
    limitHarvestBySeason("pine nut", "summer");
}
