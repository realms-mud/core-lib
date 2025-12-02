//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("meadow");

    addAdjectives(({
        "lush green meadow dotted with wildflowers",
        "open meadow where grasses sway in the breeze",
        "sunlit meadow alive with the hum of insects",
        "rolling meadow bordered by distant trees",
        "broad expanse of grass and blooming flowers",
        "peaceful meadow where butterflies flit from bloom to bloom",
        "meadow carpeted in a riot of color",
        "serene meadow where the air is sweet with clover",
        "meadow where the grass is soft and inviting",
        "open field where the sky seems endless"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the golden light of sunrise",
        " where dew sparkles on every blade of grass",
        " as birds begin their morning songs"
        }));

    addTimeOfDayDescription("morning", ({
        " alive with the bustle of bees and butterflies",
        " as the sun rises higher over the field",
        " with the scent of fresh grass and wildflowers"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " with grasses waving in the warm breeze",
        " as the meadow is filled with the sounds of life"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun begins to dip toward the horizon",
        " with long shadows stretching across the grass",
        " where the day's heat begins to wane"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the meadow quiets and the air cools",
        " with the scent of clover lingering"
        }));

    addTimeOfDayDescription("night", ({
        " under a blanket of stars",
        " where the field is quiet and peaceful",
        " as crickets and frogs begin their nightly chorus"
        }));

    addSeasonDescription("winter", ({
        " lying dormant beneath a layer of frost",
        " where the grass is brown and the flowers are gone"
        }));

    addSeasonDescription("spring", ({
        " bursting with new growth and wildflowers",
        " as the meadow comes alive with color and scent"
        }));

    addSeasonDescription("summer", ({
        " at the height of its beauty, lush and green",
        " with flowers blooming in abundance"
        }));

    addSeasonDescription("autumn", ({
        " golden with ripening seed heads",
        " as the grasses turn brown and the air grows crisp"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy meadow where only the outlines of grass and flowers are visible");
    addLowLightDescriptionTemplate("a barely-lit meadow where the field is little more than a silhouette");
    addDimLightDescriptionTemplate("a dimly-lit meadow where the land is painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit meadow where every flower and blade of grass is clear");
}
