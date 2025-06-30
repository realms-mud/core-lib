//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("elm stand");
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
        "leaves of yellow and orange", " with leaves in a vivid array "
        "of yellow orange colors" }));

    addAlias("elm");
    addAlias("elms");
    addAlias("stand of elms");
    addAlias("trees");
    addAlias("tree");
    addAlias("elm tree");
    addAlias("elm trees");

    addDescriptionTemplate("a stand of ##Adjective## elm trees");
    addItemTemplate("The stand of elms is composed of several "
        "thick-trunked, graceful trees with distinctive vase-shaped "
        "crowns. Their bark is deeply furrowed and grayish-brown, and "
        "their branches spread in an elegant fan pattern, forming a "
        "broad canopy overhead. In season, winged samaras hang from "
        "the branches, and the air is filled with the earthy scent "
        "of leaves and wood. Moss and lichen cling to the roots, and "
        "the filtered light creates shifting patterns on the forest "
        "floor. Occasionally, you spot a bird or squirrel moving "
        "among the stately branches.");

    harvestableResource("elm", 25, 
        "/lib/instances/items/materials/wood/elm.c",
        "a heavily-forested stand of elm trees. Several trees remain",
        ({ "deciduous tree", "elm tree", "tree" }));
    harvestRequiresTool("elm", "axe");

    harvestableResource("elm samara", 25,
        "/lib/instances/items/food/plants/seeds/elm-samara.c", 0,
        ({ "samara" }));
    limitHarvestBySeason("elm samara", "summer");
}
