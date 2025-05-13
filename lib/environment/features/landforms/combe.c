//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("combe");
    addAdjectives(({ "gently sloping", "lush", "verdant", "small", "rolling" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({ " where the first rays of sunlight break over the crest, illuminating the soft, rolling hills of the combe" }));
    addTimeOfDayDescription("morning", ({ " where the sunlight spills into the valley, casting a warm glow on the dew-kissed grass and flowers" }));
    addTimeOfDayDescription("noon", ({ " where the mid-day sun bathes the combe in bright, even light, revealing the rich green of the grass and the wildflowers dotting the hills" }));
    addTimeOfDayDescription("afternoon", ({ " where the light softens, casting long shadows across the gentle slopes, making the combe appear even more peaceful" }));
    addTimeOfDayDescription("evening", ({ " where the last light of the day turns the hills a golden hue, with shadows lengthening and the air cooling" }));
    addTimeOfDayDescription("dusk", ({ " where the valley darkens, and the fading light of the sun leaves the combe bathed in soft twilight" }));
    addTimeOfDayDescription("night", ({ " where the combe lies under the quiet of the night sky, with stars dotting the heavens above the peaceful hills" }));
    addTimeOfDayDescription("late night", ({ " where the combe rests in the deep quiet of the night, the only sound the occasional rustling of wind through the grass" }));
    addTimeOfDayDescription("midnight", ({ " where the combe is blanketed in darkness, the outline of the hills barely visible against the star-filled sky" }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where a light dusting of snow covers the slopes, turning the combe into a winter wonderland, with frost on the trees at the edges",
        " where the grass lies dormant under a thin coat of frost, the air crisp and cold"
        }));

    addSeasonDescription("spring", ({
        " where fresh, green grass blankets the hills, and wildflowers bloom in vibrant patches of color across the combe",
        " where the scent of new growth fills the air, and the gentle breezes carry the sound of birdsong from the trees at the valley's edge"
        }));

    addSeasonDescription("summer", ({
        " where the combe is lush and full of life, with tall grasses swaying in the warm breeze and the air thick with the scent of wildflowers",
        " where the hills are covered in dense greenery, and the soft hum of insects fills the air"
        }));

    addSeasonDescription("autumn", ({
        " where the once-green grasses turn golden and brown, and the trees at the edges of the combe display a fiery array of red and orange leaves",
        " where the air is cool and crisp, with the sound of rustling leaves echoing through the hills"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Ajective## combe, covered with soft grasses and surrounded by lush, rolling hills");
}
