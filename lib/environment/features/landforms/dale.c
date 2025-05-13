//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dale");
    addAdjectives(({ "gentle", "lush", "peaceful", "rolling", "green", "breezy" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where the first rays of light filter through the trees, casting a soft glow over the dew-covered grasses and rolling hills",
        " where the valley begins to awaken with a gentle light creeping across the hills, the air crisp and fresh"
        }));
    addTimeOfDayDescription("morning", ({
        " where the morning sun spreads warmth over the valley, lighting up the rich green of the grass and the colors of the wildflowers",
        " where a gentle breeze stirs the soft grass, and the sky above is clear, bringing a feeling of calm and serenity"
        }));
    addTimeOfDayDescription("noon", ({
        " where the sun sits high, casting even light over the dale, making the grasses shimmer and the air feel warm and still",
        " where the midday sun bakes the earth, but the shade of the trees offers respite from the heat, and the air is filled with the sounds of birds"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the sunlight softens and the shadows grow longer, lending the dale a peaceful, almost sleepy atmosphere",
        " where the breeze picks up a little, rustling the leaves in the trees and causing the grass to sway gently"
        }));
    addTimeOfDayDescription("evening", ({
        " where the sky is painted in hues of orange and pink, and the cool air of evening begins to settle over the rolling hills",
        " where the light fades and the dale becomes a quiet, serene place, the chirping of crickets filling the air as the sun sets"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the valley grows darker, and the last light of day casts long shadows over the gentle slopes, giving the landscape an ethereal quality",
        " where the hills are bathed in soft twilight, and the sounds of the day give way to the soft rustling of nightfall"
        }));
    addTimeOfDayDescription("night", ({
        " where the dale is quiet, the stars above twinkling in the clear night sky, and the air cool and still",
        " where the world is at peace, the soft night winds gently moving the grasses as the moonlight spills over the hills"
        }));
    addTimeOfDayDescription("late night", ({
        " where the dale is deep in slumber, the quiet of the night broken only by the occasional rustling of the wind through the trees",
        " where the air is cool and still, the dale bathed in soft moonlight, offering a serene, almost mystical atmosphere"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the dale lies in complete silence, the stars above glowing brightly, and the landscape shrouded in the softest darkness",
        " where the hills are dark silhouettes against the night sky, and the only sound is the distant rustling of leaves"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where the dale lies beneath a blanket of snow, the soft white covering the rolling hills and making the landscape feel peaceful and still",
        " where the trees are bare and frost coats the grass, the air cold and crisp, but the valley feels sheltered and protected"
        }));

    addSeasonDescription("spring", ({
        " where new growth begins to sprout, the valley turning a vibrant green, and wildflowers bloom in colorful patches across the dale",
        " where the air is filled with the scent of fresh blossoms, and the gentle breeze carries the sounds of birds and rustling leaves"
        }));

    addSeasonDescription("summer", ({
        " where the dale is lush and full of life, the grass tall and swaying in the warm breeze, and the air thick with the scent of blooming flowers",
        " where the sun beats down on the valley, making the green grasses appear almost to glow with life, and the trees provide welcome shade"
        }));

    addSeasonDescription("autumn", ({
        " where the grasses turn golden and brown, and the trees on the hillsides display a fiery array of red, orange, and yellow leaves",
        " where the air is crisp and fresh, and the gentle rustling of fallen leaves echoes through the valley, signaling the end of the growing season"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## dale, nestled between rolling hills and covered with soft grasses, where wildflowers bloom in vibrant colors and the air is always fresh and breezy");
}
