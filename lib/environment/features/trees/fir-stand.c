//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fir stand");
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

    addAlias("fir");
    addAlias("firs");
    addAlias("stand of firs");
    addAlias("trees");
    addAlias("tree");
    addAlias("fir tree");
    addAlias("fir trees");

    addDescriptionTemplate("a stand of ##Adjective## fir trees");
    addItemTemplate("The stand of firs is composed of several "
        "thick-trunked, towering evergreen trees. Their bark is "
        "smooth and grayish with resin pockets, and their branches "
        "form symmetrical whorls with flat, needle-like leaves. In "
        "season, upright cones stand tall on the branches, and the "
        "air is filled with the fresh scent of evergreen resin. Moss "
        "and lichen cling to the roots, and the filtered light "
        "creates shifting patterns on the forest floor. Occasionally, "
        "you spot a bird or small creature moving among the orderly "
        "branches.");

    harvestableResource("fir", 25, 
        "/lib/instances/items/materials/wood/fir.c",
        "a heavily-forested stand of fir trees. Several trees remain",
        ({ "conifer", "evergreen", "fir tree", "tree" }));
    harvestRequiresTool("fir", "axe");

    harvestableResource("fir cone", 25,
        "/lib/instances/items/food/plants/seeds/fir-cone.c", 0,
        ({ "cone", "pinecone", "conifer cone", "pine cone" }));
    limitHarvestBySeason("fir cone", "summer");

    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c", 0,
        ({ "nut", "fir nut" }));
    limitHarvestBySeason("pine nut", "summer");
}
