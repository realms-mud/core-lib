//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hazel stand");
    addAdjectives(({ "dense", "bushy", "tall", "slender" }));

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
    addSeasonDescription("summer", ({ " with branches laden with nuts",
        " covered with a thick blanket of leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in nuts and "
        "fallen leaves of yellow and brown", " with leaves in a vivid "
        "array of yellow and brown colors" }));

    addAlias("hazel");
    addAlias("hazels");
    addAlias("stand of hazels");
    addAlias("hazelnut");
    addAlias("hazelnuts");
    addAlias("trees");
    addAlias("tree");
    addAlias("hazel tree");
    addAlias("hazel trees");

    addDescriptionTemplate("a stand of ##Adjective## hazel trees");
    addItemTemplate("The stand of hazels is composed of several "
        "multi-stemmed, shrub-like trees with heart-shaped leaves. "
        "Their bark is smooth and light brown, and their branches "
        "spread densely, forming a thick understory. In season, "
        "hazelnuts in their papery husks hang from the branches, and "
        "the air is filled with the fresh scent of woodland growth. "
        "Moss and lichen cling to the roots, and the filtered light "
        "creates shifting patterns on the forest floor. Occasionally, "
        "you spot a squirrel or jay gathering the prized hazelnuts "
        "among the branches.");

    harvestableResource("hazel", 25, 
        "/lib/instances/items/materials/wood/hazel.c",
        "a heavily-forested stand of hazel trees. Several trees remain",
        ({ "deciduous tree", "hazel tree", "tree" }));
    harvestRequiresTool("hazel", "axe");

    harvestableResource("hazelnut", 25,
        "/lib/instances/items/food/plants/nuts/hazelnut.c", 0,
        ({ "nut" }));
    limitHarvestBySeason("hazelnut", "autumn");
}
