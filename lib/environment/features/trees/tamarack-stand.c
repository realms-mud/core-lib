//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tamarack stand");
    addAdjectives(({ "slender", "graceful", "tall", "northern" }));

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
        "as the sun sets behind the sparse canopy"
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
        "beginning to emerge", " sprouting new needle growth in "
        "clusters" }));
    addSeasonDescription("summer", ({ " with branches laden with small "
        "cones", " covered with a thick blanket of soft green needles" }));
    addSeasonDescription("autumn", ({ " with brilliant yellow needles "
        "carpeting the ground", " turning golden yellow before "
        "dropping all needles" }));

    addAlias("tamarack");
    addAlias("tamaracks");
    addAlias("stand of tamaracks");
    addAlias("larch");
    addAlias("larches");
    addAlias("trees");
    addAlias("tree");
    addAlias("tamarack tree");
    addAlias("tamarack trees");

    addDescriptionTemplate("a stand of ##Adjective## tamarack trees");
    addItemTemplate("The stand of tamaracks is composed of several "
        "slender-trunked, deciduous conifers with distinctive soft "
        "needles that grow in clusters and turn brilliant yellow "
        "before dropping each autumn. Their bark is thin and scaly, "
        "and their branches spread with a delicate, almost feathery "
        "appearance unique among conifers. In season, small oval "
        "cones dot the branches, and the air is filled with the fresh "
        "scent of northern wetland forest. Moss and lichen cling to "
        "the roots, and the filtered light creates shifting patterns "
        "on the boggy forest floor. Occasionally, you spot a bird or "
        "wetland creature among these unique deciduous evergreens of "
        "the northern swamps.");

    harvestableResource("tamarack", 25, 
        "/lib/instances/items/materials/wood/tamarack.c",
        "a heavily-forested stand of tamarack trees. Several trees "
        "remain", ({ "conifer", "deciduous tree", "tamarack tree", 
        "tree" }));
    harvestRequiresTool("tamarack", "axe");

    harvestableResource("tamarack cone", 20,
        "/lib/instances/items/food/plants/seeds/tamarack-cone.c", 0,
        ({ "cone", "conifer cone" }));
    limitHarvestBySeason("tamarack cone", "summer");
}
