//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("alp");
    setFloorPlanType("rugged mountain or steep hill");

    addTimeOfDayDescription("dawn", ({
        ". The first light of dawn paints the snowy peaks of the alp in soft pinks and purples, casting long shadows over the rocky terrain below."
        }));
    addTimeOfDayDescription("morning", ({
        ". As the sun rises higher, the alp is bathed in bright, clear light. The jagged rocks and snow-covered slopes shine under the morning sun, while the air is crisp and fresh."
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun is directly overhead, casting a harsh, brilliant light over the alp. The snow on the upper slopes glitters, and the shadow of the peak looms large over the land below."
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The sun begins to sink, casting long shadows across the alp. The light turns golden, illuminating the rocky outcroppings and snowy patches with a warm, gentle glow."
        }));
    addTimeOfDayDescription("evening", ({
        ". The alp is bathed in the soft, fading light of the evening, with the snow reflecting shades of pink and purple as the sun sets behind distant peaks."
        }));
    addTimeOfDayDescription("dusk", ({
        ". The alp is shrouded in twilight, the fading light casting eerie shadows over the rugged terrain. The air cools, and the wind begins to pick up, whispering across the slopes."
        }));
    addTimeOfDayDescription("night", ({
        ". The alp is quiet and still under the moonlight, with snow reflecting the cold, pale light. The silhouette of the jagged peak looms against the star-filled sky."
        }));
    addTimeOfDayDescription("late night", ({
        " with the alp cloaked in darkness, save for the faint glow of distant stars and the occasional flicker of light from far below. The wind howls faintly, echoing across the mountain."
        }));
    addTimeOfDayDescription("midnight", ({
        ". The moonlight casts long shadows across the icy slopes, and the peak of the alp seems almost ethereal in the silver glow of the night sky."
        }));

    addSeasonDescription("winter", ({
        " where the alp is covered in a thick blanket of snow, the air cold and biting. Winds whip around the slopes, and the peak is often obscured by clouds or snowstorms."
        }));
    addSeasonDescription("spring", ({
        " where the snow begins to melt on the lower slopes, revealing patches of green grass. The upper reaches of the alp remain snow-covered, and the air is crisp and fresh."
        }));
    addSeasonDescription("summer", ({
        " where the snow on the lower slopes has melted, leaving rocky ground and sparse grass. The sun beats down fiercely on the exposed terrain, making the climb difficult."
        }));
    addSeasonDescription("autumn", ({
        " where the lower reaches of the alp are dotted with golden, crimson, and orange foliage, while the upper slopes remain covered with the last remnants of snow from the previous winter."
        }));

    addDescriptionTemplate("a high, rugged alp with jagged rocks and snow-covered peaks");
    addNearDarkDescriptionTemplate("the dark silhouette of a mountain peak");
    addLowLightDescriptionTemplate("the outline of an alp, bathed in the fading light of dusk or twilight");
    addDimLightDescriptionTemplate("a dark, towering alp, the rocky terrain faintly visible under the waning light");
    addSomeLightDescriptionTemplate("a snow-covered alp, the terrain illuminated by bright daylight or soft moonlight, with sharp cliffs and rocky outcroppings");
}
