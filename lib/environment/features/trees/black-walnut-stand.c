//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("black walnut stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));

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
        " sprouting new growth", " with branches laden with catkins" }));
    addSeasonDescription("summer", ({ " with branches laden with nuts in "
        "thick husks", " covered with a thick blanket of compound "
        "leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and "
        "fallen leaves of yellow", " with leaves in a vivid array of "
        "yellow colors" }));

    addAlias("black walnut");
    addAlias("black walnuts");
    addAlias("stand of black walnuts");
    addAlias("walnut");
    addAlias("walnuts");
    addAlias("trees");
    addAlias("tree");
    addAlias("black walnut tree");
    addAlias("black walnut trees");
    addAlias("walnut tree");
    addAlias("walnut trees");

    addDescriptionTemplate("a stand of ##Adjective## black walnut trees");
    addItemTemplate("The stand of black walnuts is composed of several "
        "thick-trunked, majestic trees with distinctive compound "
        "leaves and dark, deeply furrowed bark. Their branches spread "
        "wide, forming a dense canopy overhead that few plants can "
        "grow beneath due to the tree's natural allelopathic "
        "properties. In season, large green husked walnuts litter the "
        "ground beneath, and the air is filled with the rich, earthy "
        "scent of walnut leaves and the valuable dark heartwood. Moss "
        "and lichen cling to the roots, and the filtered light creates "
        "shifting patterns on the forest floor. Occasionally, you spot "
        "a squirrel or woodworker seeking these prized nuts and lumber "
        "among the branches.");

    harvestableResource("black walnut tree", 25, 
        "/lib/instances/items/materials/wood/black-walnut.c",
        "a heavily-forested stand of black walnut trees. Several trees "
        "remain", ({ "deciduous tree", "black walnut tree", "walnut "
        "tree", "tree" }));
    harvestRequiresTool("black walnut tree", "axe");

    harvestableResource("black walnut", 25,
        "/lib/instances/items/food/plants/nuts/black-walnut.c", 0,
        ({ "walnut", "nut" }));
    limitHarvestBySeason("black walnut", "autumn");
}
