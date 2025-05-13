//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hill");
    addAdjectives(({ "grassy", "rolling", "windswept", "gently sloping", "sunlit", "open", "broad", "lonely" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where the first light creeps over the crest, casting a soft glow on the dewy grass and painting the sky in gentle pastels",
        " where the hill stands quiet in the hush before sunrise, the horizon tinged with gold and the world slowly coming awake"
        }));
    addTimeOfDayDescription("morning", ({
        " where the sun lights the hilltop in gold, and the breeze stirs the wildflowers and tall grass that blanket the slopes",
        " where shadows retreat across the land, and birdsong echoes through the clear, open air"
        }));
    addTimeOfDayDescription("noon", ({
        " where the hill basks under the full brightness of the sun, the grasses swaying in the warm wind and the air filled with the hum of insects",
        " where the sky stretches wide and clear above, and heat shimmers in the distance across the open slopes"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the sun casts longer shadows and the light softens, giving the hill a golden hue",
        " where a warm breeze rustles through the grasses and the land seems quiet and content beneath the blue sky"
        }));
    addTimeOfDayDescription("evening", ({
        " where the last light of the day lingers on the crest, turning the hill into a silhouette against a flaming sky",
        " where the air cools and the slopes glow in amber and rose, the wind whispering across the grass"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the colors of the sky fade into dusk and the hill darkens slowly under the rising stars",
        " where the horizon softens and night begins to fall gently across the landscape"
        }));
    addTimeOfDayDescription("night", ({
        " where the hill lies beneath the stars, quiet and windswept, with only the faint sound of wind brushing through the grass",
        " where moonlight silvers the hilltop, and the open land feels vast and peaceful beneath the night sky"
        }));
    addTimeOfDayDescription("late night", ({
        " where the hill is still and open to the sky, the grass dark and swaying gently in the night breeze",
        " where the crest is just a shadow beneath the stars, and the land feels timeless and vast"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the hill lies in deep shadow, the sky ablaze with stars above, and the land is silent save for the whispering wind",
        " where the midnight moon casts faint silver light across the slopes, giving the hill an ethereal glow"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where frost clings to the blades of grass and the hill is dusted with snow, the wind sharp and clear",
        " where the slopes lie bare and white under a pale sky, and the chill air carries the scent of ice and stillness"
        }));

    addSeasonDescription("spring", ({
        " where fresh green grass returns to the hill, dotted with wildflowers, and the wind carries the scent of new growth",
        " where the land feels alive again, with buzzing insects and the songs of returning birds filling the air"
        }));

    addSeasonDescription("summer", ({
        " where the hill is vibrant and warm, the grass long and golden in the sun, and butterflies dance over the flowers",
        " where the air is hot and full of sound; the whir of wings, the hum of bees, and the rustling of the tall, dry grass"
        }));

    addSeasonDescription("autumn", ({
        " where the hill is painted in russet and gold, the grass fading to amber and the wind cooler with each passing day",
        " where leaves from scattered trees tumble across the slopes and the sky carries the scent of distant rain"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## hill rising gently above the surrounding land, its slopes covered in grasses and wildflowers, offering a wide view of the sky and distant horizon");
}
