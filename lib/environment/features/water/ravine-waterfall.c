//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ravine waterfall");
    addAdjectives(({ "cascading", "thundering", "misty", "powerful", "spectacular" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching the faint dawn light",
        "outlined against the brightening ravine",
        "emerging from morning mist and spray",
        "touched by the first rays filtering down",
        "shimmering in the pale morning light",
        "awakening with the new day's roar"
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
        "as the sun sets behind the ravine walls",
        "painted in magnificent sunset colors",
        "beautiful in the evening glow",
        "romantic in the fading daylight",
        "transformed by the golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the last light of day",
        "becoming mysterious as dusk settles",
        "outlined against the darkening ravine",
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
        "lost in the deep ravine shadows",
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
        " surrounded by budding ravine vegetation", " thundering with spring runoff",
        " alive with returning wildlife", " bordered by spring wildflowers",
        " renewed by seasonal flooding" }));
    addSeasonDescription("summer", ({ " creating cooling mist in the summer heat",
        " surrounded by lush ravine vegetation", " perfect for summer contemplation",
        " alive with rainbow displays", " inviting with its cooling spray",
        " magnificent in summer's embrace" }));
    addSeasonDescription("autumn", ({ " framed by brilliant autumn foliage",
        " surrounded by ravine walls of fall colors", " beautiful in autumn's light",
        " peaceful despite its power", " contemplative as seasons change",
        " dramatic against autumn's backdrop" }));

    addAlias("waterfall");
    addAlias("falls");
    addAlias("cascade");
    addAlias("water");
    addAlias("ravine");

    addDescriptionTemplate("a ##Adjective## ravine waterfall");
    addItemTemplate("The ravine waterfall plunges dramatically down the "
        "steep walls of the narrow gorge, its waters thundering into "
        "the pool below with tremendous force. Mist rises constantly "
        "from the impact zone, creating rainbows when sunlight "
        "penetrates the ravine's depths. The surrounding rock walls "
        "are slick with spray and adorned with moss and ferns that "
        "thrive in the perpetual moisture. The waterfall has carved "
        "its path through solid stone over countless centuries, "
        "creating a natural amphitheater where the sound echoes and "
        "amplifies. Birds nest in the protected alcoves while hardy "
        "plants cling to the mist-soaked cliff face.");
}
