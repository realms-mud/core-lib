//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ravine creek");
    addAdjectives(({ "rushing", "narrow", "winding", "clear", "bubbling" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching the faint dawn light",
        "outlined against the brightening ravine",
        "emerging from morning mist",
        "touched by the first rays filtering down",
        "shimmering in the pale morning light",
        "awakening with gentle murmurs"
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
        "crystal clear in the noon sun",
        "dazzling in the bright daylight",
        "prominent in the ravine's depths",
        "brilliant under the high sun",
        "magnificent in the midday light"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with waters flowing in the afternoon warmth",
        "peaceful in the late afternoon calm",
        "warmed by the gentle afternoon sun",
        "serene in the softening light",
        "comfortable in the afternoon breeze",
        "beautiful in the afternoon glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in the golden evening light",
        "as the sun sets behind the ravine walls",
        "painted in sunset colors",
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
        "discernable by its gentle murmur",
        "outlined by moonlight on the water",
        "mysterious in the darkness",
        "peaceful under the starry sky",
        "quiet save for its flowing song",
        "enchanted by the night sounds"
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
    addSeasonDescription("winter", ({ " partially frozen with ice along the edges",
        " flowing beneath thin sheets of ice", " bordered by frost-covered stones",
        " running cold through winter's grip", " carved through winter's landscape",
        " standing as winter's flowing lifeline" }));
    addSeasonDescription("spring", ({ " running high with snowmelt",
        " surrounded by budding ravine vegetation", " flowing swiftly with spring runoff",
        " alive with returning wildlife", " bordered by spring wildflowers",
        " renewed by seasonal flooding" }));
    addSeasonDescription("summer", ({ " running clear through summer heat",
        " surrounded by lush ravine vegetation", " perfect for summer contemplation",
        " alive with aquatic life", " inviting with its cooling presence",
        " peaceful in summer's embrace" }));
    addSeasonDescription("autumn", ({ " reflecting autumn's brilliant colors",
        " flowing past ravine walls of fall foliage", " beautiful in autumn's light",
        " peaceful in the cooling air", " contemplative as seasons change",
        " carrying scattered leaves downstream" }));

    addAlias("creek");
    addAlias("water");
    addAlias("flowing water");
    addAlias("ravine");
    addAlias("stream");

    addDescriptionTemplate("a ##Adjective## ravine creek");
    addItemTemplate("The ravine creek winds its way through the narrow "
        "gorge with determined purpose, its clear waters navigating "
        "between moss-covered boulders and weathered stone. The "
        "creek has carved its channel over countless years, creating "
        "small pools and cascades as it descends through the ravine. "
        "Ferns and moisture-loving plants thrive along its banks, "
        "while small fish dart between the stones in the deeper "
        "sections. The sound of flowing water echoes off the ravine "
        "walls, creating a natural symphony that speaks of patience, "
        "persistence, and the gentle power of water to shape even "
        "the hardest stone through time and determination.");
}
