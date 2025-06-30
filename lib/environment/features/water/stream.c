//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stream");
    addAdjectives(({ "babbling", "meandering", "clear", "flowing", "gentle" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters just catching the faint dawn light",
        "reflecting the soft colors of morning",
        "emerging from the morning mist",
        "touched by the first rays of sunrise",
        "shimmering in the pale dawn light",
        "awakening with the new day"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight dancing on the ripples",
        "sparkling in the fresh morning air",
        "alive with morning activity",
        "bright with reflected morning sun",
        "peaceful in the morning stillness"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "sparkling brilliantly at midday",
        "crystal clear in the noon sun",
        "dazzling in the bright daylight",
        "flowing steadily under the high sun",
        "radiant in the midday brightness"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with shadows playing across the water",
        "flowing quietly in the afternoon warmth",
        "peaceful in the late afternoon calm",
        "warmed by the gentle afternoon sun",
        "serene in the softening light",
        "comfortable in the afternoon breeze"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in the golden evening light",
        "as the sun sets reflected in the current",
        "painted in sunset colors",
        "beautiful in the evening glow",
        "romantic in the fading daylight",
        "transformed by the golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the last light of day",
        "becoming a dark ribbon as dusk settles",
        "mysterious in the gathering twilight",
        "peaceful as night approaches",
        "cool in the evening shadows",
        "contemplative in the deepening dusk"
        }));
    addTimeOfDayDescription("night", ({
        "outlined by moonlight on the water",
        "discernable only by its gentle murmur",
        "silvered by the moon's reflection",
        "peaceful under the starry sky",
        "quiet in the darkness",
        "enchanted by the night sounds"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the deep shadows save for its sound",
        "hidden in the profound darkness",
        "flowing unseen through the night",
        "mysterious in the midnight hour",
        "embraced by the darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " partially frozen with ice along the edges",
        " flowing beneath a thin layer of ice", " with frost-covered banks",
        " bordered by snow-laden vegetation", " running cold and clear",
        " carved through winter's landscape" }));
    addSeasonDescription("spring", ({ " running high with snowmelt",
        " surrounded by budding vegetation", " flowing swiftly with spring runoff",
        " alive with returning wildlife", " bordered by spring wildflowers",
        " renewed by seasonal rains" }));
    addSeasonDescription("summer", ({ " running clear and steady",
        " bordered by lush green vegetation", " flowing gently through summer growth",
        " perfect for summer recreation", " alive with aquatic life",
        " inviting in the warm weather" }));
    addSeasonDescription("autumn", ({ " reflecting the colors of fallen leaves",
        " flowing past banks covered in autumn foliage", " carrying scattered leaves downstream",
        " beautiful in autumn's golden light", " peaceful in the cooling air",
        " preparing for winter's approach" }));

    addAlias("water");
    addAlias("stream");
    addAlias("flowing water");
    addAlias("current");
    addAlias("brook");

    addDescriptionTemplate("a ##Adjective## stream");
    addItemTemplate("The stream flows steadily along its course, its "
        "clear waters meandering between moss-covered rocks and verdant "
        "banks. Small fish dart through the shallows while water "
        "striders dance across the surface tension. The gentle babble "
        "of flowing water creates a soothing soundtrack, and occasional "
        "deeper pools reflect the sky above. Cattails and water grasses "
        "line the banks, while dragonflies patrol the water's edge. "
        "The stream's path winds naturally through the landscape, "
        "carrying the essence of distant mountains and forests.");
}
