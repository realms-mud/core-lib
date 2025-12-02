//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cedar stand");
    addAdjectives(({ "majestic", "towering", "tall", "gnarled" }));

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
    addSeasonDescription("summer", ({ " with branches laden with tiny, "
        "closed cones", " covered with a thick blanket of needles" }));
    addSeasonDescription("autumn", ({ " with cones fallen to the ground "
        "wide open" }));

    addAlias("cedar");
    addAlias("cedars");
    addAlias("stand of cedars");
    addAlias("trees");
    addAlias("tree");
    addAlias("cedar tree");
    addAlias("cedar trees");

    addDescriptionTemplate("a stand of ##Adjective## cedar trees");
    addItemTemplate("The stand of cedars is composed of several "
        "thick-trunked, aromatic evergreen trees. Their bark is "
        "fibrous and reddish-brown, and their branches spread with "
        "scale-like needle foliage that releases a distinctive "
        "fragrance. In season, small cones dot the branches, and the "
        "air is filled with the rich, cedar scent that repels insects. "
        "Moss and lichen cling to the roots, and the filtered light "
        "creates shifting patterns on the forest floor. Occasionally, "
        "you spot a bird or small creature moving among the fragrant "
        "branches.");

    harvestableResource("cedar", 25, 
        "/lib/instances/items/materials/wood/cedar.c",
        "a heavily-forested stand of cedar trees. Several trees remain",
        ({ "conifer", "evergreen", "cedar tree", "tree" }));
    harvestRequiresTool("cedar", "axe");

    harvestableResource("cedar cone", 25,
        "/lib/instances/items/food/plants/seeds/cedar-cone.c", 0,
        ({ "cone", "conifer cone" }));
    limitHarvestBySeason("cedar cone", "summer");
}
