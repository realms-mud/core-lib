//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("distant mountain peak");
    addAdjectives(({ "towering", "rugged", "snow-capped", "majestic", "remote", "isolated", "formidable", "imposing" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where the first light of day touches the peak's snowy summit, casting long shadows and illuminating the jagged ridges with a soft, golden glow",
        " where the mountain stands silent and distant, bathed in the faintest light of dawn, the peak barely visible against the pale sky"
        }));
    addTimeOfDayDescription("morning", ({
        " where the sun rises higher, spilling warm light across the sharp cliffs and icy ridgelines, making the distant peak appear even more formidable",
        " where the mountain looms, its sharp silhouette framed by a clear blue sky, the light of morning bringing out the snow-covered slopes and rocky ledges"
        }));
    addTimeOfDayDescription("noon", ({
        " where the mountain peak stands clear and bright under the full light of the midday sun, its snow-covered summit gleaming in the harsh light, surrounded by clear skies",
        " where the peak's jagged outline cuts sharply against the cloudless sky, a silhouette of unyielding strength under the intense midday sun"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the afternoon sun casts a golden hue over the distant mountain, softening the shadows on its rocky surface and making the snow shimmer",
        " where the mountain's towering peaks seem to change in the fading afternoon light, casting long, dramatic shadows over the ridges and valleys below"
        }));
    addTimeOfDayDescription("evening", ({
        " where the mountain peak is bathed in the soft, warm hues of the setting sun, turning the snow-covered slopes into a shimmering display of gold and rose",
        " where the fading light of evening casts the peak in deep shadow, giving the rugged slopes a mysterious, almost otherworldly appearance"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the last rays of light fade, and the mountain stands in stark silhouette against the darkening sky, its peak barely discernible in the twilight",
        " where the mountain is shrouded in the deepening darkness, its jagged features softened by the twilight, but still imposing and unreachable"
        }));
    addTimeOfDayDescription("night", ({
        " where the mountain peak is cloaked in darkness, its sharp ridgelines lost in the black void of night, the stars above twinkling faintly in the cold air",
        " where the moonlight spills over the snow-covered summit, casting a pale, ghostly light on the towering peaks, making the mountain appear even more remote"
        }));
    addTimeOfDayDescription("late night", ({
        " where the mountain stands silent in the dark, the only movement the occasional gust of wind that stirs the snow, its towering presence silent and eternal",
        " where the cold night air wraps around the distant peak, and the mountain lies still, bathed in the faintest moonlight, a sentinel in the night"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the peak is hidden in the blackness of midnight, its outline lost against the starry sky, an immovable and isolated presence in the vast landscape",
        " where the snow on the summit reflects the moonlight faintly, but the mountain remains distant and implacable, its towering height lost in the shadows of the night"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where the mountain is a silent, frozen sentinel, its snow-covered slopes gleaming in the sunlight and its jagged ridges cutting sharply into the sky",
        " where the bitter cold grips the mountain, its summit permanently capped with snow, and the air is thin and crisp, leaving the peak seemingly untouched by time"
        }));

    addSeasonDescription("spring", ({
        " where the lower slopes of the mountain begin to show signs of life, with patches of green creeping up the rocky terrain, while the peak remains crowned with snow",
        " where the mountain stands stark and unchanging, the snow lingering at the summit while the valleys below slowly begin to thaw and bloom with new life"
        }));

    addSeasonDescription("summer", ({
        " where the mountain's peak still wears its crown of snow, but the lower slopes are bathed in sunlight, their rocky faces growing warmer under the summer sun",
        " where the air around the peak is still and cool, the summer heat not reaching the heights, leaving the mountain isolated from the warmth of the valleys below"
        }));

    addSeasonDescription("autumn", ({
        " where the lower valleys are painted with the warm hues of autumn, but the peak remains frosted with snow, an eternal winter amidst the changing seasons",
        " where the mountain's rugged ridges stand out against the colorful backdrop of autumn, with the snow at the summit contrasting with the fiery colors below"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## mountain peak, towering above the landscape with snow-capped ridges and jagged cliffs that stretch toward the sky, isolated and distant from the world below");
}
