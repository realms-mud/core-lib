//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rocky mountain");

    addAdjectives(({
        "towering rocky mountain with jagged peaks",
        "craggy mountain where boulders litter the slopes",
        "steep mountain with sheer cliffs and rocky outcrops",
        "mountain of bare stone and scree",
        "windswept peak where little grows but lichen",
        "mountain where the air is thin and cold",
        "rocky mountain with deep ravines and narrow ledges",
        "mountain where eagles nest among the cliffs",
        "rugged mountain where the wind howls between the rocks",
        "mountain where snow lingers in shadowed crevices"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the first light of day",
        " where the peaks glow pink and gold",
        " as the mountain awakens in silence"
        }));

    addTimeOfDayDescription("morning", ({
        " with sunlight striking the upper slopes",
        " as the rocks warm under a clear sky",
        " where the air is crisp and cold"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where the rocks radiate heat and the shadows are short",
        " as the mountain stands stark against the sky"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the slopes",
        " with long shadows stretching over the rocks",
        " where the wind whistles between the crags"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the mountain cools and the sky turns orange and purple",
        " where the peaks are silhouetted against the fading light"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with stars",
        " where the mountain is silent and the air is cold",
        " as the rocks are bathed in moonlight"
        }));

    addSeasonDescription("winter", ({
        " covered in snow and ice",
        " where the wind is biting and the slopes are treacherous"
        }));

    addSeasonDescription("spring", ({
        " with melting snow and rushing streams",
        " as hardy plants begin to bloom in sheltered crevices"
        }));

    addSeasonDescription("summer", ({
        " at its warmest, with clear skies and long days",
        " where the rocks are hot and the air is thin"
        }));

    addSeasonDescription("autumn", ({
        " with cold winds and early snows",
        " as the mountain prepares for winter"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy rocky mountain where only the outlines of peaks are visible");
    addLowLightDescriptionTemplate("a barely-lit rocky mountain where the land is little more than a silhouette");
    addDimLightDescriptionTemplate("a dimly-lit rocky mountain where the rocks are painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit rocky mountain where every crag and ledge is clear");
}
