//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lake");
    addAdjectives(({ "peaceful", "pristine", "serene", "tranquil", "mirror-like" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with surface catching the faint dawn light",
        "reflecting the soft colors of lake sunrise",
        "emerging from gentle morning lake mist",
        "touched by the first rays over calm waters",
        "shimmering in the pale dawn light",
        "awakening with peaceful ripples"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight dancing on calm lake waters",
        "sparkling in the fresh morning air",
        "alive with morning lake activity",
        "bright with reflected morning sun",
        "peaceful in the morning stillness"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible stretching across the landscape",
        "brilliant blue in the noon sun",
        "dazzling in the bright daylight",
        "perfect mirror at midday",
        "inviting under the high sun",
        "magnificent in the midday brightness"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with gentle waves lapping the shores",
        "peaceful in the late afternoon calm",
        "warmed by the gentle afternoon sun",
        "serene in the softening light",
        "comfortable in the afternoon lake breeze",
        "beautiful in the afternoon glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with surface glowing in the golden evening light",
        "reflecting the magnificent sunset",
        "painted in spectacular evening colors",
        "beautiful beyond description in evening light",
        "romantic in the fading lake daylight",
        "transformed by the golden lake hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the last light of day",
        "becoming mysterious as lake dusk settles",
        "peaceful as night approaches the waters",
        "cool in the evening lake shadows",
        "contemplative in the deepening lake dusk",
        "serene in the gathering lake darkness"
        }));
    addTimeOfDayDescription("night", ({
        "reflecting moonlight on still waters",
        "peaceful under the starry lake sky",
        "silvered by moonlight across its expanse",
        "mysterious in the gentle lake darkness",
        "enchanted by the night lake sounds",
        "magnificent in the night's embrace"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the gentle lake darkness",
        "hidden in the tranquil midnight",
        "present as gentle lapping sounds",
        "mysterious in the midnight lake hour",
        "embraced by the peaceful darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " partially frozen with beautiful ice patterns",
        " reflecting winter's stark beauty", " peaceful in winter's quiet embrace",
        " transformed by winter's icy touch", " beautiful in winter's pristine simplicity",
        " standing as winter's frozen mirror" }));
    addSeasonDescription("spring", ({ " alive with returning lake life",
        " surrounded by budding lakeside vegetation", " renewed by spring rains and snowmelt",
        " vibrant with migrating waterfowl", " refreshed by spring's warming touch",
        " awakened by spring's gentle energy" }));
    addSeasonDescription("summer", ({ " perfect for summer recreation",
        " surrounded by lush lakeside vegetation", " alive with abundant summer life",
        " inviting in the warm weather", " beautiful in summer's embrace",
        " teeming with summer lake activity" }));
    addSeasonDescription("autumn", ({ " reflecting brilliant autumn colors",
        " surrounded by spectacular fall foliage", " beautiful in autumn's golden light",
        " peaceful in the cooling air", " contemplative as seasons change",
        " scattered with floating autumn leaves" }));

    addAlias("water");
    addAlias("lake");
    addAlias("waters");
    addAlias("pond");

    addDescriptionTemplate("a ##Adjective## lake");
    addItemTemplate("The lake stretches peacefully across the landscape, "
        "its calm waters serving as a perfect mirror for the sky "
        "above and the surrounding terrain. Fed by streams and "
        "springs, this substantial body of water provides a vital "
        "ecosystem where countless species of fish, birds, and "
        "aquatic life thrive in harmony. Gentle waves lap against "
        "varied shorelines - some sandy, some rocky, some lined "
        "with reeds and cattails that sway in the lake breeze. "
        "The lake's seasonal changes paint an ever-evolving portrait "
        "of natural beauty, from ice-covered winter serenity to "
        "summer's vibrant activity, making it a cornerstone of "
        "the regional ecosystem and a source of peace for all "
        "who visit its tranquil shores.");
}
