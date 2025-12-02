//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("serviceberry stand");
    addAdjectives(({ "graceful", "slender", "tall", "delicate" }));

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
    addSeasonDescription("summer", ({ " with branches laden with berries",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in berries "
        "and fallen leaves of red, yellow, and orange", " with leaves "
        "in a vivid array of yellow, red, and orange colors" }));

    addAlias("serviceberry");
    addAlias("serviceberries");
    addAlias("stand of serviceberries");
    addAlias("juneberry");
    addAlias("juneberries");
    addAlias("saskatoon");
    addAlias("trees");
    addAlias("tree");
    addAlias("serviceberry tree");
    addAlias("serviceberry trees");

    addDescriptionTemplate("a stand of ##Adjective## serviceberry trees");
    addItemTemplate("The stand of serviceberries is composed of several "
        "slender-trunked, small trees with oval, serrated leaves. "
        "Their bark is smooth and grayish, and their branches spread "
        "gracefully, forming a light canopy overhead. In season, "
        "clusters of dark purple berries hang from the branches, and "
        "the air is filled with the sweet scent of ripening fruit. "
        "Moss and lichen cling to the roots, and the filtered light "
        "creates shifting patterns on the forest floor. Occasionally, "
        "you spot a bird or small creature feeding on the nutritious "
        "berries among the branches.");

    harvestableResource("serviceberry", 20, 
        "/lib/instances/items/materials/wood/serviceberry.c",
        "a heavily-forested stand of serviceberry trees. Several trees "
        "remain", ({ "deciduous tree", "serviceberry tree", "tree" }));
    harvestRequiresTool("serviceberry", "axe");

    harvestableResource("serviceberry fruit", 20,
        "/lib/instances/items/food/plants/fruit/serviceberry.c", 0,
        ({ "berry", "fruit" }));
    limitHarvestBySeason("serviceberry fruit", "summer");
}
