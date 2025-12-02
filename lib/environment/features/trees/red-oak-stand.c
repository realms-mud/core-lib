//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("red oak stand");
    addAdjectives(({ "majestic", "towering", "tall", "ancient" }));

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
        " sprouting new growth" }));
    addSeasonDescription("summer", ({ " with branches laden with acorns",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen "
        "leaves of red and orange", " with leaves in a vivid array of "
        "red and orange colors" }));

    addAlias("red oak");
    addAlias("red oaks");
    addAlias("stand of red oaks");
    addAlias("oak");
    addAlias("oaks");
    addAlias("trees");
    addAlias("tree");
    addAlias("red oak tree");
    addAlias("red oak trees");
    addAlias("oak tree");
    addAlias("oak trees");

    addDescriptionTemplate("a stand of ##Adjective## red oak trees");
    addItemTemplate("The stand of red oaks is composed of several "
        "thick-trunked, ancient trees with distinctive lobed leaves. "
        "Their bark is deeply furrowed and grayish-brown, and their "
        "branches spread wide, forming a dense canopy overhead. In "
        "season, acorns litter the ground beneath, and the air is "
        "filled with the earthy scent of oak leaves and wood. Moss "
        "and lichen cling to the roots, and the filtered light creates "
        "shifting patterns on the forest floor. Occasionally, you spot "
        "a squirrel or jay gathering acorns among the branches.");

    harvestableResource("red oak", 25, 
        "/lib/instances/items/materials/wood/oak.c",
        "a heavily-forested stand of red oak trees. Several trees "
        "remain", ({ "deciduous tree", "red oak tree", "oak tree", 
        "oak", "tree" }));
    harvestRequiresTool("red oak", "axe");

    harvestableResource("acorn", 25,
        "/lib/instances/items/food/plants/nuts/acorn.c", 0,
        ({ "acorn nut", "nut" }));
    limitHarvestBySeason("acorn", "summer");
}
