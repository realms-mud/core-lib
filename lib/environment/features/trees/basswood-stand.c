//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("basswood stand");
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
        " sprouting new growth", " with branches laden with small green "
        "flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with many nuts",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and "
        "fallen leaves of yellow and brown", " with leaves in a vivid "
        "array of yellow and brown colors" }));

    addAlias("basswood");
    addAlias("basswoods");
    addAlias("stand of basswoods");
    addAlias("trees");
    addAlias("tree");
    addAlias("basswood tree");
    addAlias("basswood trees");

    addDescriptionTemplate("a stand of ##Adjective## basswood trees");
    addItemTemplate("The stand of basswoods is composed of several "
        "thick-trunked, stately trees with distinctive heart-shaped "
        "leaves. Their bark is smooth and grayish-brown, and their "
        "branches spread wide, forming a dense canopy overhead. In "
        "season, small fragrant flowers bloom followed by small nuts, "
        "and the air is filled with the sweet scent of basswood "
        "blossoms. Moss and lichen cling to the roots, and the "
        "filtered light creates shifting patterns on the forest floor. "
        "Occasionally, you spot a bee or bird visiting among the "
        "fragrant flowering branches.");

    harvestableResource("basswood", 25, 
        "/lib/instances/items/materials/wood/basswood.c",
        "a heavily-forested stand of basswood trees. Several trees "
        "remain", ({ "deciduous tree", "basswood tree", "tree" }));
    harvestRequiresTool("basswood", "axe");

    harvestableResource("basswood nut", 25,
        "/lib/instances/items/food/plants/nuts/basswood-nut.c", 0,
        ({ "nut" }));
    limitHarvestBySeason("basswood nut", "summer");
}
