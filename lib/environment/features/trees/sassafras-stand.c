//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sassafras stand");
    addAdjectives(({ "aromatic", "slender", "tall", "fragrant" }));

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
    addSeasonDescription("winter", ({ " standing bare with aromatic bark",
        " dormant but still fragrant", " resting leafless through "
        "winter" }));
    addSeasonDescription("spring", ({ " with distinctively shaped leaves "
        "just beginning to bud", " sprouting new growth", " with "
        "branches laden with small yellow flowers" }));
    addSeasonDescription("summer", ({ " with branches laden with berries",
        " covered with a thick blanket of varied-shaped leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in berries "
        "and fallen leaves of brilliant orange and red", " with leaves "
        "in vivid shades of orange, red, and yellow" }));

    addAlias("sassafras");
    addAlias("stand of sassafras");
    addAlias("trees");
    addAlias("tree");
    addAlias("sassafras tree");
    addAlias("sassafras trees");

    addDescriptionTemplate("a stand of ##Adjective## sassafras trees");
    addItemTemplate("The stand of sassafras is composed of several "
        "slender trees with distinctive three-lobed leaves that come "
        "in various shapes - some oval, some mitten-shaped, some with "
        "three lobes. Their bark is reddish-brown and deeply "
        "furrowed, and their branches spread with an aromatic "
        "presence. In season, small blue berries on red stems hang "
        "from the branches, and the air is filled with the spicy, "
        "root-beer scent of sassafras wood and leaves. Moss and "
        "lichen cling to the roots, and the filtered light creates "
        "shifting patterns on the forest floor. Occasionally, you "
        "spot an herbalist or curious creature investigating the "
        "medicinal properties among the fragrant branches.");

    harvestableResource("sassafras tree", 25, 
        "/lib/instances/items/materials/wood/sassafras.c",
        "a heavily-forested stand of sassafras trees. Several trees "
        "remain", ({ "deciduous tree", "sassafras tree", "tree" }));
    harvestRequiresTool("sassafras tree", "axe");

    harvestableResource("sassafras berry", 15,
        "/lib/instances/items/food/plants/fruit/sassafras-berry.c", 0,
        ({ "berry", "fruit" }));
    limitHarvestBySeason("sassafras berry", "autumn");

    harvestableResource("sassafras root", 10,
        "/lib/instances/items/food/plants/roots/sassafras-root.c", 0,
        ({ "root" }));
}
