//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("willow stand");
    addAdjectives(({ "towering", "tall", "massive" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with branches just catching the faint dawn light",
        "outlined softly as the day begins"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight filtering through the drooping leaves"
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
        "as the sun sets behind the drooping canopy"
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
    addSeasonDescription("spring", ({ " with thin leaves just beginning to bud",
        " sprouting new growth"  }));
    addSeasonDescription("summer", ({ " with branches laden with catkins",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in leaves of yellow and brown",
        " with leaves in of yellow and brown" }));

    addAlias("willow");
    addAlias("willows");
    addAlias("stand of willows");
    addAlias("willow tree");
    addAlias("willow trees");
    addAlias("tree");
    addAlias("trees");

    addDescriptionTemplate("a stand of ##Adjective## willow trees");
    addItemTemplate("The stand of willows is composed of several "
        "graceful-trunked trees with distinctive drooping branches. "
        "Their bark is grayish-brown and deeply grooved, and their long, "
        "slender branches hang down like curtains. In season, catkins "
        "dangle from the branches, and the air is filled with the fresh "
        "scent of new growth. Moss and lichen cling to the roots, and "
        "the filtered light creates shifting patterns on the ground. "
        "Occasionally, you spot a bird or small creature darting among "
        "the drooping branches.");

    harvestableResource("willow", 25, "/lib/instances/items/materials/wood/willow.c",
        "a heavily-forested stand of willow trees. Several trees remain",
        ({ "deciduous tree", "willow tree", "tree" }));
    harvestRequiresTool("willow", "axe");

    harvestableResource("willow catkin", 25,
        "/lib/instances/items/food/plants/seeds/willow-catkin.c", 0,
        ({ "catkin" }));
    limitHarvestBySeason("willow catkin", "summer");

    harvestableResource("willow bark", 25,
        "/lib/instances/items/food/plants/bark/willow-bark.c", 0,
        ({ "bark" }));
}
