//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("butte");
    addAdjectives(({ "isolated", "towering", "flat-topped", "rugged", "barren" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({ " where the first light of day slowly spills over the flat top, casting long shadows across the steep sides of the butte" }));
    addTimeOfDayDescription("morning", ({ " where the sun rises higher, casting a warm glow on the jagged edges and making the flat top appear as if it were glowing" }));
    addTimeOfDayDescription("noon", ({ " where the harsh midday sun beats down on the exposed surface, creating stark shadows along the cliffs of the butte" }));
    addTimeOfDayDescription("afternoon", ({ " where the sun begins to dip, casting a softer golden light on the sides of the butte, making it seem almost otherworldly" }));
    addTimeOfDayDescription("evening", ({ " where the sinking sun bathes the butte in shades of orange and red, turning the rocky surface into an inferno of color" }));
    addTimeOfDayDescription("dusk", ({ " where the last rays of light fade from the sky, leaving the butte in silhouette, its sharp edges cutting against the darkening sky" }));
    addTimeOfDayDescription("night", ({ " where the butte looms dark and silent under the cold moonlight, its flat top stark against the endless sky of stars" }));
    addTimeOfDayDescription("late night", ({ " where the butte stands as a shadow in the darkness, its form barely discernible under the pale light of distant stars" }));
    addTimeOfDayDescription("midnight", ({ " where the moon casts eerie light on the butte's flat top, giving it an almost spectral glow against the black sky" }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where the butte's flat top is covered with a thin layer of snow, and a bitter wind sweeps across its bare rock surface",
        " where the chill of winter has hardened the rocky surface, and frost clings to its steep sides"
        }));

    addSeasonDescription("spring", ({
        " where the first signs of life begin to appear around the base, with sparse grasses poking through the soil and small flowers growing along cracks",
        " where the air feels fresher, though the flat top remains bare and exposed to the elements"
        }));

    addSeasonDescription("summer", ({
        " where the butte stands heat-baked and dry, with cracked rock surfaces and no shade to be found anywhere on its flat top",
        " where the heat of the summer sun makes the rocky surface shimmer with heat waves"
        }));

    addSeasonDescription("autumn", ({
        " where the winds of autumn blow dust and fallen leaves across the flat top, and the surrounding terrain takes on a muted brown and gold hue",
        " where the leaves from distant trees far below flutter in the breeze, yet the butte's rocky surface remains impervious to the season\'s change"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## butte rising sharply from the flat plains with a flat, expansive top and steep cliffs around it");
}
