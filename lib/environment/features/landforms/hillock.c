//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hillock");
    addAdjectives(({ "small", "rounded", "gentle", "modest", "grassy", "subtle", "unassuming", "solitary" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where soft light gradually reveals its modest contours, dew glistening on grass stems like scattered gems",
        " where morning mist clings to its gentle slopes, creating a dreamy halo in the first light"
        }));
    addTimeOfDayDescription("morning", ({
        " where sunlight bathes its rounded form, casting a short but distinct shadow across the surrounding land",
        " where birds hop among the grasses covering its gentle rise, their songs carried on the morning breeze"
        }));
    addTimeOfDayDescription("noon", ({
        " where the hillock stands fully illuminated under the midday sun, a subtle rise in an otherwise flat landscape",
        " where heat shimmers above its grassy crown, creating a wavering haze against the bright sky"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the low sun accentuates every small undulation and texture across its modest surface",
        " where butterflies flutter between wildflowers that speckle its sun-warmed slopes"
        }));
    addTimeOfDayDescription("evening", ({
        " where the setting sun casts a golden glow across its western face while shadow claims the eastern side",
        " where cooling air settles around its base while the summit remains touched by fading light"
        }));
    addTimeOfDayDescription("dusk", ({
        " where twilight softens its outline into a gentle silhouette against the darkening sky",
        " where the last birds settle among its grasses as stars begin to appear overhead"
        }));
    addTimeOfDayDescription("night", ({
        " where moonlight transforms the hillock into a subtle mound of silver rising from shadow-dark surroundings",
        " where night dew begins to form on its grasses, catching starlight in countless tiny reflections"
        }));
    addTimeOfDayDescription("late night", ({
        " where the small rise is barely discernible in darkness, more sensed than seen against the night sky",
        " where nocturnal creatures rustle through its protective cover, safe in its modest shelter"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the hillock stands as a darker shape against the star-filled sky, silent and watchful",
        " where cool night air flows around its form, creating subtle currents in the midnight stillness"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where a thin blanket of snow highlights its gentle curves against the winter landscape",
        " where frost coats each blade of grass, turning the humble rise into a sparkling mound"
        }));

    addSeasonDescription("spring", ({
        " where new shoots push through the soil, dotting the hillock with fresh green and tiny wildflowers",
        " where spring rain has awakened dormant seeds, covering the small rise in vibrant young growth"
        }));

    addSeasonDescription("summer", ({
        " where tall summer grasses bow and wave across its form, creating rippling patterns in the breeze",
        " where insects buzz lazily above flowers that cluster across its sun-baked surface"
        }));

    addSeasonDescription("autumn", ({
        " where the grasses have turned golden-brown, rustling dryly in the cool autumn winds",
        " where morning frost begins to touch its crown while fallen leaves gather around its base"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## hillock, a small elevation rising just enough to distinguish itself from the surrounding terrain, covered in short vegetation and providing a modest vantage point");
}
