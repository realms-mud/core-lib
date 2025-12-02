//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("waterfall");
    addAdjectives(({ "cascading", "thundering", "magnificent", "misty", "powerful" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching the faint dawn light",
        "outlined against the brightening sky",
        "emerging from morning mist and spray",
        "touched by the first rays of sunlight",
        "shimmering in the pale morning light",
        "awakening with thunderous roars"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight creating rainbows in the spray",
        "sparkling in the fresh morning air",
        "alive with morning's cascading energy",
        "bright with reflected morning sun",
        "peaceful despite its thunderous voice"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "brilliant white in the noon sun",
        "dazzling in the bright daylight",
        "creating prismatic displays at midday",
        "magnificent in the harsh noon light",
        "imposing under the high sun"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with spray dancing in the afternoon warmth",
        "peaceful despite its constant roar",
        "warmed by the gentle afternoon sun",
        "serene in the softening light",
        "comfortable in the cooling mist",
        "beautiful in the afternoon glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in the golden evening light",
        "as the sun sets behind the cascade",
        "painted in magnificent sunset colors",
        "beautiful in the evening glow",
        "romantic in the fading daylight",
        "transformed by the golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the last light of day",
        "becoming mysterious as dusk settles",
        "outlined against the darkening sky",
        "peaceful as night approaches",
        "cool in the evening shadows",
        "contemplative in the deepening dusk"
        }));
    addTimeOfDayDescription("night", ({
        "discernable only by its thunderous roar",
        "outlined by moonlight on the spray",
        "mysterious in the darkness",
        "peaceful under the starry sky",
        "enchanted by the night sounds",
        "hidden save for its eternal song"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the deep shadows",
        "hidden in the profound darkness",
        "present only as sound in the night",
        "mysterious in the midnight hour",
        "embraced by the darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " frozen into spectacular ice formations",
        " creating cathedral-like ice sculptures", " partially frozen with icicle curtains",
        " transformed into winter's frozen art", " carved into crystalline beauty",
        " standing as winter's frozen monument" }));
    addSeasonDescription("spring", ({ " swollen with snowmelt and spring rains",
        " surrounded by budding vegetation", " thundering with spring runoff",
        " alive with returning wildlife", " bordered by spring wildflowers",
        " renewed by seasonal flooding" }));
    addSeasonDescription("summer", ({ " creating cooling mist in the summer heat",
        " surrounded by lush vegetation", " perfect for summer contemplation",
        " alive with rainbow displays", " inviting with its cooling spray",
        " magnificent in summer's embrace" }));
    addSeasonDescription("autumn", ({ " framed by brilliant autumn foliage",
        " surrounded by walls of fall colors", " beautiful in autumn's light",
        " peaceful despite its power", " contemplative as seasons change",
        " dramatic against autumn's backdrop" }));

    addAlias("waterfall");
    addAlias("falls");
    addAlias("cascade");
    addAlias("water");

    addDescriptionTemplate("a ##Adjective## waterfall");
    addItemTemplate("The waterfall plunges dramatically from its rocky "
        "precipice, its waters cascading with tremendous force into "
        "the pool below. Mist rises constantly from the impact zone, "
        "creating rainbows when sunlight penetrates the spray. The "
        "surrounding rock face is slick with moisture and adorned "
        "with moss and ferns that thrive in the perpetual dampness. "
        "The waterfall's thunderous voice echoes across the landscape, "
        "audible from great distances as a testament to water's "
        "awesome power. Birds nest in the protected alcoves behind "
        "the falling water while hardy plants cling to the mist-"
        "soaked cliff face, creating a unique ecosystem centered "
        "around this spectacular display of nature's raw energy.");
}
