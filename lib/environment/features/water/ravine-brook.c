//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ravine brook");
    addAdjectives(({ "babbling", "gentle", "peaceful", "tiny", "musical" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching the faint dawn light",
        "outlined against the brightening ravine",
        "emerging from morning mist",
        "touched by the first rays filtering down",
        "shimmering in the pale morning light",
        "awakening with gentle whispers"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight dancing on tiny ripples",
        "sparkling in the fresh morning air",
        "alive with delicate morning sounds",
        "bright with reflected morning sun",
        "peaceful in the morning calm"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "crystal clear in the noon sun",
        "dazzling in the bright daylight",
        "delicate in the ravine's depths",
        "brilliant under the high sun",
        "charming in the midday light"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with waters trickling in the afternoon warmth",
        "peaceful in the late afternoon calm",
        "warmed by the gentle afternoon sun",
        "serene in the softening light",
        "comfortable in the afternoon breeze",
        "soothing in the afternoon glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in the golden evening light",
        "as the sun sets behind the ravine walls",
        "painted in gentle sunset colors",
        "beautiful in the evening glow",
        "romantic in the fading daylight",
        "enchanted by the golden hour"
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
        "discernable by its gentle babble",
        "outlined by moonlight on the water",
        "mysterious in the darkness",
        "peaceful under the starry sky",
        "quiet with its gentle song",
        "enchanted by the night sounds"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the deep ravine shadows",
        "hidden in the profound darkness",
        "present as gentle sounds in the night",
        "mysterious in the midnight hour",
        "embraced by the darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " partially frozen with delicate ice formations",
        " trickling beneath thin ice sheets", " bordered by frost-covered pebbles",
        " running gently through winter's embrace", " peaceful in winter's quiet",
        " standing as winter's gentle lifeline" }));
    addSeasonDescription("spring", ({ " swollen with gentle spring rains",
        " surrounded by tender ravine vegetation", " flowing briskly with spring energy",
        " alive with returning small wildlife", " bordered by delicate spring flowers",
        " renewed by seasonal moisture" }));
    addSeasonDescription("summer", ({ " trickling peacefully through summer heat",
        " surrounded by lush small plants", " perfect for quiet contemplation",
        " alive with tiny aquatic creatures", " soothing with its gentle presence",
        " peaceful in summer's embrace" }));
    addSeasonDescription("autumn", ({ " reflecting autumn's gentle colors",
        " flowing past small autumn plants", " beautiful in autumn's soft light",
        " peaceful in the cooling air", " contemplative as seasons change",
        " carrying tiny leaves downstream" }));

    addAlias("brook");
    addAlias("water");
    addAlias("flowing water");
    addAlias("ravine");
    addAlias("stream");

    addDescriptionTemplate("a ##Adjective## ravine brook");
    addItemTemplate("The ravine brook trickles gently through the narrow "
        "gorge with quiet determination, its shallow waters creating "
        "a delicate melody as they flow over smooth pebbles and "
        "around tiny obstacles. This intimate waterway has carved "
        "the smallest of channels through the ravine floor, creating "
        "miniature pools where water striders dance and small fish "
        "hide. Delicate mosses and tiny ferns cluster along its "
        "banks, thriving in the gentle moisture. The brook's soft "
        "babbling provides a peaceful soundtrack that soothes the "
        "soul and invites quiet contemplation in this hidden corner "
        "of the natural world where time seems to slow.");
}
