//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("yew stand");
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
    addSeasonDescription("spring", ({ " with brilliant green new growth sprouting",
        " sprouting new growth", "with tiny red flowers blossoming" }));
    addSeasonDescription("summer", ({ " with branches laden with tiny, closed cones",
        " covered with a thick blanket of needles" }));
    addSeasonDescription("autumn", ({ " with cones fallen to the ground wide open" }));

    addAlias("yew");
    addAlias("yews");
    addAlias("stand of yews");
    addAlias("trees");
    addAlias("tree");

    addDescriptionTemplate("a stand of ##Adjective## yew trees");
    addItemTemplate("The stand of yews is composed of several thick-trunked, ancient evergreen trees. "
        "Their bark is reddish-brown and fibrous, and their branches spread wide with dense needle foliage. "
        "In season, small cones dot the branches, and the air is filled with the resinous scent of evergreen. "
        "Moss and lichen cling to the roots, and the filtered light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a bird or small creature darting among the branches.");

    harvestableResource("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain", 
        ({ "conifer", "evergreen", "yew tree", "tree" }));
    harvestRequiresTool("yew", "axe");

    harvestableResource("yew cone", 25,
        "/lib/instances/items/food/plants/seeds/yew-cone.c", 0,
        ({ "cone", "pinecone", "conifer cone", "pine cone" }));
    limitHarvestBySeason("yew cone", "summer");

    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c", 0,
        ({ "nut", "yew nut" }));
    limitHarvestBySeason("pine nut", "summer");
}
