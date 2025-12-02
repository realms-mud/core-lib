//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("juniper shrubs");
    addAdjectives(({ "dense", "sprawling", "low", "aromatic" }));

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
        "as the sun sets behind the dense thicket"
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
    addSeasonDescription("spring", ({ " with new growth sprouting from "
        "the tips", " sprouting fresh needle growth" }));
    addSeasonDescription("summer", ({ " with branches laden with berries",
        " covered with a thick blanket of blue-green needles" }));
    addSeasonDescription("autumn", ({ " with dark blue berries dotting "
        "the branches", " showing off their aromatic berry harvest" }));

    addAlias("juniper");
    addAlias("junipers");
    addAlias("juniper shrubs");
    addAlias("shrubs");
    addAlias("shrub");
    addAlias("juniper bush");
    addAlias("juniper bushes");

    addDescriptionTemplate("a thicket of ##Adjective## juniper shrubs");
    addItemTemplate("The juniper shrubs form a dense, low-growing "
        "thicket of evergreen bushes with scale-like needles. Their "
        "bark is fibrous and reddish-brown, and their branches spread "
        "in irregular, twisted patterns close to the ground. In "
        "season, small blue berries with a waxy coating dot the "
        "branches, and the air is filled with the sharp, gin-like "
        "fragrance of juniper. Moss and lichen cling to the base, and "
        "the filtered light creates shifting patterns through the "
        "dense foliage. Occasionally, you spot a small bird or "
        "creature taking shelter among the aromatic branches.");

    harvestableResource("juniper", 15, 
        "/lib/instances/items/materials/wood/juniper.c",
        "a dense thicket of juniper shrubs. Several bushes remain",
        ({ "evergreen shrub", "juniper shrub", "shrub" }));
    harvestRequiresTool("juniper", "axe");

    harvestableResource("juniper berry", 25,
        "/lib/instances/items/food/plants/fruit/juniper-berry.c", 0,
        ({ "berry", "fruit" }));
    limitHarvestBySeason("juniper berry", "autumn");
}
