//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pawpaw stand");
    addAdjectives(({ "tropical", "exotic", "slender", "unusual" }));

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
    addSeasonDescription("winter", ({ " standing bare with smooth branches",
        " dormant with no leaves", " resting leafless through winter" }));
    addSeasonDescription("spring", ({ " with large leaves just beginning "
        "to unfurl", " sprouting tropical-looking new growth", " with "
        "branches laden with dark purple flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with fruit",
        " covered with a thick blanket of large tropical leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fruit and "
        "fallen leaves of yellow", " with leaves in brilliant shades "
        "of golden yellow" }));

    addAlias("pawpaw");
    addAlias("pawpaws");
    addAlias("stand of pawpaws");
    addAlias("papaw");
    addAlias("papaws");
    addAlias("trees");
    addAlias("tree");
    addAlias("pawpaw tree");
    addAlias("pawpaw trees");

    addDescriptionTemplate("a stand of ##Adjective## pawpaw trees");
    addItemTemplate("The stand of pawpaws is composed of several "
        "small, understory trees with distinctive large, tropical-"
        "looking leaves. Their bark is smooth and brown, and their "
        "branches spread with an exotic appearance unusual for "
        "temperate forests. In season, large green fruits resembling "
        "small papayas hang from the branches, and the air is filled "
        "with the sweet, tropical scent of ripening pawpaws. Moss and "
        "lichen cling to the roots, and the filtered light creates "
        "shifting patterns on the forest floor. Occasionally, you "
        "spot a bird or curious forager sampling the unusual native "
        "fruit among the branches.");

    harvestableResource("pawpaw tree", 20, 
        "/lib/instances/items/materials/wood/pawpaw.c",
        "a heavily-forested stand of pawpaw trees. Several trees "
        "remain", ({ "deciduous tree", "pawpaw tree", "tree" }));
    harvestRequiresTool("pawpaw tree", "axe");

    harvestableResource("pawpaw", 15,
        "/lib/instances/items/food/plants/fruit/pawpaw.c", 0,
        ({ "fruit" }));
    limitHarvestBySeason("pawpaw", "autumn");
}
