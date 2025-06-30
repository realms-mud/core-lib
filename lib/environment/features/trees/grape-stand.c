//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("grape stand");
    addAdjectives(({ "majestic", "towering", "tall", "slender" }));

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
    addSeasonDescription("summer", ({ " with branches laden with fruit",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fruit and "
        "fallen leaves of red, yellow, and orange", " with leaves in a "
        "vivid array of yellow, red, and orange colors" }));

    addAlias("grape");
    addAlias("grapes");
    addAlias("stand of grapes");
    addAlias("trees");
    addAlias("tree");
    addAlias("grape tree");
    addAlias("grape trees");

    addDescriptionTemplate("a stand of ##Adjective## grape trees");
    addItemTemplate("The stand of grapes is composed of several "
        "climbing, vine-like trees with twisted trunks and sprawling "
        "branches. Their bark is rough and fibrous, and their "
        "branches spread widely with large, lobed leaves. In season, "
        "clusters of purple and green grapes hang from the vines, and "
        "the air is filled with the sweet scent of ripening fruit. "
        "Moss and lichen cling to the gnarled trunks, and the "
        "filtered light creates shifting patterns on the vineyard "
        "floor. Occasionally, you spot a bird or bee visiting among "
        "the heavy grape clusters.");

    harvestableResource("grape tree", 25, 
        "/lib/instances/items/materials/wood/grape.c",
        "a heavily-forested stand of grape trees. Several trees remain",
        ({ "deciduous tree", "tree" }));
    harvestRequiresTool("grape tree", "axe");

    harvestableResource("grape", 10,
        "/lib/instances/items/food/plants/fruit/grape.c", 0,
        ({ "fruit" }));
    limitHarvestBySeason("grape", "summer");
}
