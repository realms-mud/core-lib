//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("larch stand");
    addAdjectives(({ "majestic", "towering", "tall", "straight" }));

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
    addSeasonDescription("winter", ({ " standing bare with branches "
        "covered in snow", " layered with a dusting of snow on bare "
        "limbs", " encased in a film of ice on leafless branches" }));
    addSeasonDescription("spring", ({ " with bright green needles just "
        "beginning to emerge", " sprouting new needle growth" }));
    addSeasonDescription("summer", ({ " with branches laden with small "
        "cones", " covered with a thick blanket of soft needles" }));
    addSeasonDescription("autumn", ({ " with golden needles carpeting "
        "the ground", " turning brilliant gold before dropping needles" }));

    addAlias("larch");
    addAlias("larches");
    addAlias("stand of larches");
    addAlias("tamarack");
    addAlias("tamaracks");
    addAlias("trees");
    addAlias("tree");
    addAlias("larch tree");
    addAlias("larch trees");

    addDescriptionTemplate("a stand of ##Adjective## larch trees");
    addItemTemplate("The stand of larches is composed of several "
        "straight-trunked, deciduous conifers with distinctive soft "
        "needles. Their bark is scaly and reddish-brown, and their "
        "branches spread with delicate needle clusters. In season, "
        "small cones dot the branches, and the air is filled with the "
        "fresh scent of coniferous wood. Moss and lichen cling to the "
        "roots, and the filtered light creates shifting patterns on "
        "the forest floor. Occasionally, you spot a bird or small "
        "creature moving among these unique deciduous evergreens.");

    harvestableResource("larch", 25, 
        "/lib/instances/items/materials/wood/larch.c",
        "a heavily-forested stand of larch trees. Several trees remain",
        ({ "conifer", "deciduous tree", "larch tree", "tree" }));
    harvestRequiresTool("larch", "axe");

    harvestableResource("larch cone", 25,
        "/lib/instances/items/food/plants/seeds/larch-cone.c", 0,
        ({ "cone", "conifer cone" }));
    limitHarvestBySeason("larch cone", "summer");
}
