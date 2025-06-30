//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("balsam fir stand");
    addAdjectives(({ "aromatic", "towering", "tall", "fragrant" }));

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
    addSeasonDescription("summer", ({ " with branches laden with upright "
        "cones", " covered with a thick blanket of fragrant needles" }));
    addSeasonDescription("autumn", ({ " with cone scales fallen to the "
        "ground", " releasing seeds and scales on the autumn breeze" }));

    addAlias("balsam fir");
    addAlias("balsam firs");
    addAlias("stand of balsam firs");
    addAlias("trees");
    addAlias("tree");
    addAlias("balsam fir tree");
    addAlias("balsam fir trees");

    addDescriptionTemplate("a stand of ##Adjective## balsam fir trees");
    addItemTemplate("The stand of balsam firs is composed of several "
        "straight-trunked, pyramid-shaped evergreen trees with "
        "distinctive flat needles that have a pleasant balsamic "
        "fragrance when crushed. Their bark is smooth and gray with "
        "resin blisters, and their branches spread in regular whorls "
        "with dark green needles marked by two white stripes beneath. "
        "In season, purple upright cones sit atop the branches like "
        "candles, and the air is filled with the sweet, Christmas-"
        "tree scent of balsam. Moss and lichen cling to the roots, "
        "and the filtered light creates shifting patterns on the "
        "forest floor. Occasionally, you spot a bird or woodland "
        "creature among these aromatic northern trees.");

    harvestableResource("balsam fir", 25, 
        "/lib/instances/items/materials/wood/balsam-fir.c",
        "a heavily-forested stand of balsam fir trees. Several trees "
        "remain", ({ "conifer", "evergreen", "balsam fir tree", "tree" }));
    harvestRequiresTool("balsam fir", "axe");

    harvestableResource("balsam fir cone", 20,
        "/lib/instances/items/food/plants/seeds/balsam-fir-cone.c", 0,
        ({ "cone", "conifer cone" }));
    limitHarvestBySeason("balsam fir cone", "summer");

    harvestableResource("balsam resin", 15,
        "/lib/instances/items/materials/resin/balsam-resin.c", 0,
        ({ "resin", "sap" }));
}
