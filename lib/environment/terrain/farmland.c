//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("farmland");
    addAdjectives(({
        "expansive farmland with neat rows of crops",
        "patchwork of fields stretching to the horizon",
        "fertile farmland dotted with haystacks and scarecrows",
        "rolling farmland bordered by low stone walls",
        "well-tended fields with rich, dark soil",
        "farmland alive with the sounds of birds and insects",
        "broad fields where farmers work beneath the sun",
        "lush farmland with crops swaying in the breeze",
        "productive farmland with irrigation ditches and furrows",
        "open farmland where the scent of earth is strong"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the golden light of sunrise",
        " where dew sparkles on every blade of grass",
        " as farmers begin their day's work",
        " with the air fresh and cool"
        }));

    addTimeOfDayDescription("morning", ({
        " alive with the bustle of activity",
        " as the sun rises higher over the fields",
        " with the scent of fresh earth and growing plants",
        " where birds sing from fence posts and hedgerows"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " with crops reaching for the sky",
        " as the fields shimmer with heat",
        " where the air is filled with the hum of insects"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun begins to dip toward the horizon",
        " with long shadows stretching across the fields",
        " where the day's work nears completion",
        " as the breeze stirs the crops"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the fields quiet and the workers head home",
        " with the scent of cut hay lingering in the air",
        " where the sky is painted in hues of orange and pink"
        }));

    addTimeOfDayDescription("dusk", ({
        " as the last light fades from the sky",
        " with the fields settling into stillness",
        " where the air cools and the land rests",
        " as night creatures begin to stir"
        }));

    addTimeOfDayDescription("night", ({
        " under a blanket of stars",
        " where the fields are quiet and peaceful",
        " with the distant sound of crickets",
        " as the land sleeps beneath the moon"
        }));

    addTimeOfDayDescription("late night", ({
        " shrouded in deep silence",
        " where the only movement is the wind in the crops",
        " as the world rests in darkness"
        }));

    addTimeOfDayDescription("midnight", ({
        " in the deepest part of night",
        " where the fields are still and the air is cool"
        }));

    addSeasonDescription("winter", ({
        " lying fallow beneath a blanket of snow",
        " where the earth rests and prepares for spring",
        " with bare fields and empty furrows"
        }));

    addSeasonDescription("spring", ({
        " bursting with new growth",
        " as young crops push through the soil",
        " where the air is filled with the scent of blossoms"
        }));

    addSeasonDescription("summer", ({
        " at the height of productivity",
        " with fields lush and green",
        " as crops ripen beneath the sun"
        }));

    addSeasonDescription("autumn", ({
        " golden with ripened grain",
        " as harvesters gather the season's bounty",
        " where the air is crisp and cool"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy farmland where only the outlines of fields are visible");
    addLowLightDescriptionTemplate("a barely-lit farmland where crops are little more than shapes in the gloom");
    addDimLightDescriptionTemplate("a dimly-lit farmland where the land is painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit farmland where every row and furrow is clear");
}
