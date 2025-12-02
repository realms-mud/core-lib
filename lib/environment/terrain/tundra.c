//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tundra");

    addAdjectives(({
        "windswept tundra with patches of hardy grass",
        "bleak expanse of frozen earth and lichen",
        "vast tundra where the ground is hard and unyielding",
        "open plain of permafrost and scattered stones",
        "tundra dotted with low shrubs and moss",
        "chill landscape where the wind never ceases",
        "endless tundra where the sky meets the frozen ground",
        "barren tundra with only the hardiest life",
        "frostbitten plain where snow lingers even in summer",
        "lonely tundra where silence reigns"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the pale light of sunrise",
        " where the frost glitters on every blade of grass",
        " as the cold air bites at exposed skin"
        }));

    addTimeOfDayDescription("morning", ({
        " with the sun rising over the frozen ground",
        " as the wind stirs the sparse vegetation",
        " where the air is crisp and clear"
        }));

    addTimeOfDayDescription("noon", ({
        " under the cold, bright midday sun",
        " where the ground remains hard and icy",
        " as the tundra stretches endlessly in every direction"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the plain",
        " with long shadows stretching over the tundra",
        " where the wind grows colder"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the last light of day",
        " as the temperature drops rapidly",
        " where the sky is painted in icy hues"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with shimmering stars",
        " where the cold is at its most intense",
        " as the tundra is cloaked in darkness"
        }));

    addSeasonDescription("winter", ({
        " locked in deep freeze, with snow and ice everywhere",
        " where blizzards are common and the cold is relentless"
        }));

    addSeasonDescription("spring", ({
        " with patches of thawing ground and new growth",
        " as hardy plants begin to emerge"
        }));

    addSeasonDescription("summer", ({
        " with long days and a pale sun, but still cold",
        " where the ground softens and wildflowers bloom briefly"
        }));

    addSeasonDescription("autumn", ({
        " as the winds grow colder and the frost returns",
        " where the tundra prepares for the long winter ahead"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy tundra where only the outlines of the land are visible");
    addLowLightDescriptionTemplate("a barely-lit tundra where the ground is little more than a silhouette");
    addDimLightDescriptionTemplate("a dimly-lit tundra where the land is painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit tundra where every stone and patch of grass is clear");
}
