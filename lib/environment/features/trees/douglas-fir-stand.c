//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("douglas fir stand");
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
    addSeasonDescription("summer", ({ " with branches laden with "
        "distinctive cones", " covered with a thick blanket of flat "
        "needles" }));
    addSeasonDescription("autumn", ({ " with cones fallen to the ground "
        "wide open", " with cones and some needles carpeting the "
        "ground" }));

    addAlias("douglas fir");
    addAlias("douglas firs");
    addAlias("stand of douglas firs");
    addAlias("trees");
    addAlias("tree");
    addAlias("douglas fir tree");
    addAlias("douglas fir trees");

    addDescriptionTemplate("a stand of ##Adjective## douglas fir trees");
    addItemTemplate("The stand of douglas firs is composed of several "
        "enormous-trunked, towering evergreen trees with distinctive "
        "flat needles and thick, deeply furrowed bark. Their branches "
        "spread in a pyramid shape with needles that spiral around "
        "the twigs, and their cones hang distinctively downward with "
        "three-pronged bracts protruding between the scales. In "
        "season, these unique cones dot the branches, and the air is "
        "filled with the fresh, sweet scent of douglas fir. Moss and "
        "lichen cling to the massive trunks, and the filtered light "
        "creates shifting patterns on the forest floor. Occasionally, "
        "you spot a bird or small creature among these giants of the "
        "Pacific Northwest.");

    harvestableResource("douglas fir", 30, 
        "/lib/instances/items/materials/wood/douglas-fir.c",
        "a heavily-forested stand of douglas fir trees. Several trees "
        "remain", ({ "conifer", "evergreen", "douglas fir tree", "tree" }));
    harvestRequiresTool("douglas fir", "axe");

    harvestableResource("douglas fir cone", 25,
        "/lib/instances/items/food/plants/seeds/douglas-fir-cone.c", 0,
        ({ "cone", "conifer cone" }));
    limitHarvestBySeason("douglas fir cone", "summer");

    harvestableResource("fir seed", 20,
        "/lib/instances/items/food/plants/seeds/fir-seed.c", 0,
        ({ "seed" }));
    limitHarvestBySeason("fir seed", "summer");
}
