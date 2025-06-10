//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("plains");

    addAdjectives(({
        "vast open plains stretching to the horizon",
        "rolling grasslands dotted with wildflowers",
        "expansive plains where the wind ripples through the grass",
        "broad fields of swaying green and gold",
        "open prairie alive with the hum of insects",
        "endless grassland where herds roam freely",
        "plains where the sky seems impossibly wide",
        "sunlit fields where the grass is soft and inviting",
        "open steppe with scattered shrubs and wildflowers",
        "peaceful plains where the land meets the sky"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the golden light of sunrise",
        " where dew sparkles on every blade of grass",
        " as birds begin their morning songs"
        }));

    addTimeOfDayDescription("morning", ({
        " alive with the bustle of insects and birds",
        " as the sun rises higher over the fields",
        " where the grass glows in the morning light"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where the grass is warm and the air is filled with the scent of earth",
        " as the plains shimmer with heat"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the grasslands",
        " with long shadows stretching over the fields",
        " where the breeze stirs the tall grass"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the plains quiet and the air cools",
        " where the sky is painted in hues of orange and pink"
        }));

    addTimeOfDayDescription("night", ({
        " under a blanket of stars",
        " where the fields are quiet and peaceful",
        " as crickets and frogs begin their nightly chorus"
        }));

    addSeasonDescription("winter", ({
        " lying dormant beneath a layer of frost",
        " where the grass is brown and the wind is biting",
        " as snow sometimes blankets the land"
        }));

    addSeasonDescription("spring", ({
        " bursting with new growth and wildflowers",
        " as the plains come alive with color and scent"
        }));

    addSeasonDescription("summer", ({
        " at the height of its beauty, lush and green",
        " with grasses tall and waving in the breeze"
        }));

    addSeasonDescription("autumn", ({
        " golden with ripening seed heads",
        " as the grass turns brown and the air grows crisp"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy plain where only the outlines of grass are visible");
    addLowLightDescriptionTemplate("a barely-lit plain where the land is little more than a silhouette");
    addDimLightDescriptionTemplate("a dimly-lit plain where the grass is painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit plain where every blade of grass is clear");
}
