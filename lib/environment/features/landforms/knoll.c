//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("knoll");
    addAdjectives(({ "grassy", "rounded", "prominent", "smooth", "distinct", "verdant", "elevated", "scenic" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where early light strikes its crown first, leaving its base in lingering shadow as day begins",
        " where morning dew creates a glistening mantle across its smooth, rounded top"
        }));
    addTimeOfDayDescription("morning", ({
        " where the knoll stands distinct against the morning sky, its grassy slopes catching the strengthening light",
        " where birdsong rises from the thickets at its base as the sun climbs higher over its curved profile"
        }));
    addTimeOfDayDescription("noon", ({
        " where the midday sun illuminates every feature of the knoll, leaving no shadow on its exposed summit",
        " where insects buzz among the sun-warmed grasses that carpet its distinctive rise"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the rounded top catches afternoon light, glowing warmly against the lengthening shadows",
        " where the breeze creates waves across the grasses covering its smooth contours"
        }));
    addTimeOfDayDescription("evening", ({
        " where sunset light burnishes the knoll's western slope to gold while eastern shadows deepen",
        " where the elevated mound stands silhouetted against an evening sky painted in fiery hues"
        }));
    addTimeOfDayDescription("dusk", ({
        " where fading light softly outlines its distinctive shape as darkness gathers around its base",
        " where a few last rays touch the summit while the surrounding land has already surrendered to night"
        }));
    addTimeOfDayDescription("night", ({
        " where moonlight reveals the knoll's smooth silhouette rising distinctly above the darkened landscape",
        " where stars wheel above its silent form, the grasses silver-tinged in the gentle night light"
        }));
    addTimeOfDayDescription("late night", ({
        " where the rounded prominence remains visible even in darkness, a deeper shadow against the night sky",
        " where nocturnal creatures venture across its slopes, their movements barely perceptible in the darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the knoll stands sentinel under the midnight sky, its outline softened by darkness",
        " where dew forms on every blade of grass, invisible now but waiting to sparkle at dawn's return"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow smooths its already rounded form, creating an unblemished white dome",
        " where winter winds sweep across its exposed crown, sometimes revealing frozen ground beneath"
        }));

    addSeasonDescription("spring", ({
        " where wildflowers bloom in profusion across its slopes, creating patches of color among fresh grass",
        " where spring rains have awakened the knoll to vibrant life, birds and insects returning to its shelter"
        }));

    addSeasonDescription("summer", ({
        " where the grasses grow tall and lush under the summer sun, creating a verdant crown",
        " where butterflies and bees move from flower to flower across its sun-warmed slopes"
        }));

    addSeasonDescription("autumn", ({
        " where the grasses have turned to gold and russet, moving in waves under the autumn winds",
        " where morning mist often clings to its base while the summit stands clear in the crisp air"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## knoll rising above the surrounding terrain, its distinctly rounded top creating a natural landmark visible from some distance, covered in grasses that respond to every passing breeze");
}
