//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ravine pond");
    addAdjectives(({ "hidden", "secluded", "peaceful", "protected", "intimate" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with surface catching filtered dawn light",
        "reflecting the soft colors visible through the ravine",
        "emerging from morning mist",
        "touched by indirect rays filtering down",
        "shimmering in the pale morning light",
        "awakening in its protected hollow"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle filtered morning light",
        "with sunlight creating dappled patterns",
        "peaceful in the morning shadows",
        "alive with sheltered morning activity",
        "bright with reflected indirect sun",
        "serene in the morning stillness"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible when sunlight penetrates",
        "cool and shaded at midday",
        "peaceful in the ravine's protection",
        "perfect mirror in its hidden basin",
        "brilliant when touched by high sun",
        "inviting in its cool refuge"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with gentle ripples in the afternoon calm",
        "peaceful in the protected afternoon shade",
        "cool despite the afternoon warmth above",
        "serene in the filtered light",
        "comfortable in the ravine's embrace",
        "beautiful in the dappled afternoon glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with surface glowing in filtered evening light",
        "reflecting what sunset light reaches down",
        "painted in muted evening colors",
        "beautiful in the gentle evening glow",
        "romantic in the protected twilight",
        "enchanted by the filtered golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the ravine shadows",
        "becoming mysterious as dusk deepens",
        "peaceful in its protected hollow",
        "cool in the evening ravine shadows",
        "contemplative in the gathering darkness",
        "serene in the deepening ravine dusk"
        }));
    addTimeOfDayDescription("night", ({
        "reflecting stars visible through the ravine opening",
        "peaceful in its hidden sanctuary",
        "mysterious in the protected darkness",
        "quiet in the ravine night",
        "enchanted by amplified night sounds",
        "secretive in the gentle darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible in the deep ravine shadows",
        "lost in the profound darkness",
        "hidden in its protected midnight",
        "peaceful in the secret hour",
        "mysterious and still",
        "embraced by the ravine's darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " protected from winter's harshest effects",
        " partially frozen in its sheltered basin", " peaceful in winter's protected embrace",
        " beautiful in its hidden winter sanctuary", " serene in winter's quiet refuge",
        " standing as winter's secret mirror" }));
    addSeasonDescription("spring", ({ " alive with protected spring life",
        " surrounded by sheltered budding vegetation", " renewed by spring rains collecting",
        " busy with wildlife seeking shelter", " adorned with protected spring flowers",
        " refreshed by seasonal runoff" }));
    addSeasonDescription("summer", ({ " providing cool summer refuge",
        " surrounded by lush protected vegetation", " perfect for secluded contemplation",
        " alive with sheltered summer wildlife", " inviting in its cool protection",
        " peaceful in summer's hidden embrace" }));
    addSeasonDescription("autumn", ({ " reflecting autumn colors visible above",
        " surrounded by protected fall vegetation", " beautiful in its autumn sanctuary",
        " peaceful in the cooling ravine air", " contemplative in seasonal change",
        " scattered with leaves fallen from above" }));

    addAlias("water");
    addAlias("pond");
    addAlias("pool");
    addAlias("ravine");
    addAlias("hidden pond");

    addDescriptionTemplate("a ##Adjective## ravine pond");
    addItemTemplate("The ravine pond nestles secretly within the protective "
        "walls of the narrow gorge, its still waters creating a "
        "hidden sanctuary away from the world above. Fed by seeping "
        "springs and seasonal runoff, this intimate body of water "
        "provides a crucial refuge for wildlife seeking shelter from "
        "the elements. Ferns and moisture-loving plants thrive in "
        "the constantly humid environment created by the pond's "
        "presence, while the ravine walls provide protection from "
        "wind and harsh weather. The pond's surface reflects the "
        "narrow strip of sky visible between the ravine walls, "
        "creating a perfect window to the heavens from this earthbound "
        "sanctuary of peace and solitude.");
}
