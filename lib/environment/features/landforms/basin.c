//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("basin");

    addTimeOfDayDescription("dawn", ({
        ". The first light of dawn gently reflects off the still waters of the basin, casting a soft glow across the surface. Mist rises from the water, creating a serene, peaceful scene."
        }));
    addTimeOfDayDescription("morning", ({
        ". As the sun rises higher, the basin is bathed in a warm, golden light. The water sparkles, and the air is filled with the sound of birds chirping in the nearby trees."
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun is high above, casting clear, sharp light across the water. The basin's edges are sharp and distinct, and the water ripples slightly from a gentle breeze."
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The sun begins to dip lower, casting long shadows across the basin. The water remains calm, but the light now reflects off the surface with a soft, golden hue."
        }));
    addTimeOfDayDescription("evening", ({
        ". The sun sets behind the distant hills, and the basin is cloaked in soft twilight. The water glows faintly in the fading light, its surface mirroring the colors of the sky."
        }));
    addTimeOfDayDescription("dusk", ({
        ". As the light fades, the basin is nearly hidden in darkness. Only the faintest glimmer of water can be seen under the dimming sky."
        }));
    addTimeOfDayDescription("night", ({
        ". The basin is bathed in the soft light of the moon, the water shimmering faintly. The air is cool and still, and the sounds of the day are replaced by the quiet rustling of nocturnal creatures."
        }));
    addTimeOfDayDescription("late night", ({
        " with the basin shrouded in complete darkness, save for the moon's reflection on the water. The area is eerily quiet, as if the night itself has settled over it."
        }));
    addTimeOfDayDescription("midnight", ({
        ". The water of the basin reflects the silvery glow of the moon, shimmering like liquid silver under the starry sky. The world is quiet, save for the occasional rustle of leaves in the breeze."
        }));

    addSeasonDescription("winter", ({
        " where the water is still, occasionally covered by a thin layer of frost along the edges. The air is crisp and cold, and the surrounding plants are dormant, covered in snow."
        }));
    addSeasonDescription("spring", ({
        " where new shoots of grass and vibrant wildflowers begin to bloom around the water's edge. The basin is alive with the sounds of creatures stirring and the gentle rustling of leaves."
        }));
    addSeasonDescription("summer", ({
        " where the water is warm and inviting, the basin surrounded by lush greenery. The sun beats down, and the sounds of insects and birds are constant throughout the day."
        }));
    addSeasonDescription("autumn", ({
        " where the leaves of nearby trees turn vibrant shades of red and gold. The water reflects the changing colors, creating a beautiful mosaic of autumn hues on the surface."
        }));

    addDescriptionTemplate("a serene natural water basin nestled in a small valley or depression, surrounded by lush vegetation or rocky outcroppings");
    addNearDarkDescriptionTemplate("the outline of a water basin, barely visible against the darkening landscape");
    addLowLightDescriptionTemplate("a basin of water, the surface dimly reflecting the fading light of the evening");
    addDimLightDescriptionTemplate("a calm water basin, the surface shimmering faintly in the twilight");
    addSomeLightDescriptionTemplate("a tranquil water basin, glistening under the sunlight or moonlight, surrounded by a lush or rocky landscape");
}