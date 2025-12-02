//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("river");
    addAdjectives(({ "flowing", "mighty", "winding", "broad", "swift" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching the faint dawn light",
        "reflecting the soft colors of sunrise",
        "emerging from the morning river mist",
        "touched by the first rays of daylight",
        "awakening with the flowing current",
        "shimmering in the pale dawn light"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight dancing on the current",
        "sparkling in the fresh morning air",
        "alive with morning river activity",
        "bright with reflected morning sun",
        "peaceful in the morning stillness"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "sparkling brilliantly at midday",
        "flowing steadily under the high sun",
        "crystal clear in the noon light",
        "dazzling in the bright daylight",
        "magnificent in the midday brightness"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with currents flowing in the afternoon warmth",
        "peaceful in the late afternoon calm",
        "warmed by the gentle afternoon sun",
        "serene in the softening light",
        "comfortable in the afternoon breeze",
        "meandering through the afternoon landscape"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in the golden evening light",
        "as the sun sets reflected in the current",
        "painted in magnificent sunset colors",
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
        "discernable by the sound of flowing current",
        "silvered by the moon's reflection",
        "peaceful under the starry sky",
        "quiet save for the water's song",
        "enchanted by the night river sounds"
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
    addSeasonDescription("winter", ({ " partially frozen with ice floes drifting",
        " flowing beneath thin sheets of ice", " bordered by frost-covered banks",
        " running cold and clear through winter", " carved through winter's landscape",
        " standing as winter's flowing highway" }));
    addSeasonDescription("spring", ({ " running high with snowmelt and spring rains",
        " surrounded by budding riverside vegetation", " flowing swiftly with spring runoff",
        " alive with returning aquatic life", " bordered by spring wildflowers",
        " renewed by seasonal flooding" }));
    addSeasonDescription("summer", ({ " running clear and steady through summer heat",
        " bordered by lush green riverside growth", " perfect for summer recreation",
        " alive with abundant aquatic life", " inviting in the warm weather",
        " peaceful in summer's gentle embrace" }));
    addSeasonDescription("autumn", ({ " reflecting the brilliant colors of autumn foliage",
        " flowing past banks covered in fall colors", " carrying scattered leaves downstream",
        " beautiful in autumn's golden light", " peaceful in the cooling air",
        " preparing for winter's icy touch" }));

    addAlias("water");
    addAlias("river");
    addAlias("flowing water");
    addAlias("current");
    addAlias("waterway");
    addAlias("stream");

    addDescriptionTemplate("a ##Adjective## river");
    addItemTemplate("The river flows with purpose and power through the "
        "landscape, its broad current carrying the collected waters "
        "of countless tributaries toward distant seas. Ancient "
        "willows and cottonwoods line its banks, their roots drinking "
        "deeply from the life-giving flow. Fish leap and splash in "
        "the deeper pools while herons stand motionless in the "
        "shallows, waiting with infinite patience. The river serves "
        "as nature's highway, supporting diverse ecosystems along its "
        "meandering path and providing sustenance to all who depend "
        "upon its generous bounty. Its constant flow speaks of "
        "permanence and change, carrying both memory and promise "
        "in its eternal journey.");
}
