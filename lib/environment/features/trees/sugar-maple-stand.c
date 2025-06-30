//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sugar maple stand");
    addAdjectives(({ "stout", "towering", "tall", "broad" }));

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
    addSeasonDescription("summer", ({ " with branches laden with samaras "
        "and leaves", " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen "
        "leaves of red, yellow, and orange", " with leaves in a vivid "
        "array of yellow, red, and orange colors" }));

    addAlias("sugar maple");
    addAlias("sugar maples");
    addAlias("stand of sugar maples");
    addAlias("maple");
    addAlias("maples");
    addAlias("maple tree");
    addAlias("maple trees");
    addAlias("trees");
    addAlias("tree");

    addDescriptionTemplate("a stand of ##Adjective## sugar maple trees");
    addItemTemplate("The stand of sugar maples is composed of several "
        "thick-trunked, stately trees. Their bark is grayish-brown and "
        "deeply grooved, and their branches spread wide, forming a dense "
        "canopy overhead. In season, winged samaras hang from the "
        "branches, and the air is filled with the sweet scent of maple "
        "sap. Moss and lichen cling to the roots, and the filtered light "
        "creates shifting patterns on the forest floor. Occasionally, "
        "you spot a bird or squirrel darting among the branches.");

    harvestableResource("sugar maple", 25, 
        "/lib/instances/items/materials/wood/maple.c",
        "a heavily-forested stand of sugar maple trees. Several trees "
        "remain", ({ "deciduous tree", "sugar maple tree", "maple tree", 
        "maple", "tree" }));
    harvestRequiresTool("sugar maple", "axe");

    harvestableResource("maple sap", 25,
        "/lib/instances/items/food/plants/sap/maple-sap.c", 0,
        ({ "sap" }));

    harvestableResource("maple samara", 25,
        "/lib/instances/items/food/plants/seeds/maple-samara.c", 0,
        ({ "samara" }));
    limitHarvestBySeason("maple samara", "summer");
}

