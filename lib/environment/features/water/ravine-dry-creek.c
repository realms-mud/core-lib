//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ravine dry creek");
    addAdjectives(({ "empty", "seasonal", "silent", "weathered", "waiting" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with stones catching the faint dawn light",
        "outlined against the brightening ravine",
        "emerging from morning shadows",
        "touched by the first rays filtering down",
        "revealed in the pale morning light",
        "awakening to another quiet day"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight illuminating dry stones",
        "bright in the fresh morning air",
        "peaceful in its silent emptiness",
        "clear in the reflected morning sun",
        "serene despite its absence of water"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "stark and empty at midday",
        "warmed by the noon sun",
        "prominent in the bright daylight",
        "exposed under the high sun",
        "dramatic in its waterless state"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with warmth radiating from sun-warmed stones",
        "silent in the afternoon calm",
        "peaceful in its empty tranquility",
        "warmed by the afternoon sun",
        "contemplative in the softening light",
        "beautiful despite its emptiness"
        }));
    addTimeOfDayDescription("evening", ({
        "with stones glowing in the golden evening light",
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
        "barely visible in the darkness",
        "outlined by moonlight on dry stones",
        "mysterious in the night silence",
        "peaceful under the starry sky",
        "quiet in its waterless state",
        "enchanted by the night stillness"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the deep ravine shadows",
        "hidden in the profound darkness",
        "silent in the midnight hour",
        "mysterious in its emptiness",
        "embraced by the darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " dusted with snow in its empty channel",
        " marked by frost on exposed stones", " peaceful in winter's quiet embrace",
        " transformed by winter's coating", " beautiful in its stark simplicity",
        " waiting for spring's return" }));
    addSeasonDescription("spring", ({ " showing signs of recent spring floods",
        " hopeful for returning spring waters", " marked by new vegetation growth",
        " alive with sprouting ravine plants", " promising future water flow",
        " renewed by spring's potential" }));
    addSeasonDescription("summer", ({ " dry in the summer's warm embrace",
        " completely waterless during summer's peak", " waiting for autumn rains",
        " beautiful despite its emptiness", " peaceful in summer's drought",
        " contemplative in its quiet state" }));
    addSeasonDescription("autumn", ({ " scattered with fallen autumn leaves",
        " hoping for autumn's returning rains", " beautiful in autumn's light",
        " peaceful in the cooling air", " contemplative as seasons change",
        " preparing for potential winter flows" }));

    addAlias("creek");
    addAlias("dry creek");
    addAlias("creek bed");
    addAlias("ravine");
    addAlias("channel");

    addDescriptionTemplate("a ##Adjective## dry creek running through a ravine");
    addItemTemplate("The ravine dry creek winds through the narrow gorge "
        "as a testament to water's seasonal nature, its channel carved by "
        "spring floods and autumn rains that flow through this natural "
        "corridor during wetter times of year. Smooth stones and weathered "
        "boulders line the empty bed, polished by waters that rush through "
        "during snowmelt and heavy rains. Forest plants and moisture-seeking "
        "vegetation line the banks, their roots extending into the sandy "
        "bottom where they can access residual moisture and await the "
        "return of flowing water. The creek bed tells stories of seasonal "
        "cycles through the patterns worn into stone and the arrangement "
        "of deposited leaves and debris that mark high water lines on "
        "the ravine walls.");
}
