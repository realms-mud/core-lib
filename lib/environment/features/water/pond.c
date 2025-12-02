//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pond");
    addAdjectives(({ "tranquil", "peaceful", "still", "mirror-like", "serene" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with surface catching the faint dawn light",
        "reflecting the soft colors of sunrise",
        "emerging from morning mist",
        "touched by the first rays of daylight",
        "shimmering in the pale dawn light",
        "awakening with gentle ripples"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight dancing on calm waters",
        "sparkling in the fresh morning air",
        "alive with morning pond activity",
        "bright with reflected morning sun",
        "peaceful in the morning stillness"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "crystal clear in the noon sun",
        "dazzling in the bright daylight",
        "perfect mirror at midday",
        "brilliant under the high sun",
        "inviting in the midday warmth"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with gentle ripples in the afternoon breeze",
        "peaceful in the late afternoon calm",
        "warmed by the gentle afternoon sun",
        "serene in the softening light",
        "comfortable in the afternoon warmth",
        "beautiful in the afternoon glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with surface glowing in the golden evening light",
        "reflecting the magnificent sunset",
        "painted in evening colors",
        "beautiful in the evening glow",
        "romantic in the fading daylight",
        "transformed by the golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the last light of day",
        "becoming mysterious as dusk settles",
        "peaceful as night approaches",
        "cool in the evening shadows",
        "contemplative in the deepening dusk",
        "serene in the gathering darkness"
        }));
    addTimeOfDayDescription("night", ({
        "reflecting moonlight on still waters",
        "peaceful under the starry sky",
        "silvered by the moon's reflection",
        "quiet in the darkness",
        "enchanted by the night sounds",
        "mysterious in the gentle darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the darkness save for reflections",
        "hidden in the profound night",
        "peaceful in the midnight hour",
        "mysterious and still",
        "embraced by the darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " partially frozen with delicate ice patterns",
        " reflecting winter's stark beauty", " bordered by frost-covered reeds",
        " peaceful in winter's quiet embrace", " beautiful in winter's simplicity",
        " standing as winter's mirror" }));
    addSeasonDescription("spring", ({ " alive with returning aquatic life",
        " surrounded by budding pond vegetation", " reflecting spring's renewal",
        " busy with mating wildlife activity", " bordered by spring wildflowers",
        " renewed by seasonal rains" }));
    addSeasonDescription("summer", ({ " perfect for summer contemplation",
        " surrounded by lush pond vegetation", " alive with abundant wildlife",
        " inviting in the warm weather", " peaceful in summer's embrace",
        " teeming with summer activity" }));
    addSeasonDescription("autumn", ({ " reflecting brilliant autumn colors",
        " surrounded by fall foliage", " beautiful in autumn's light",
        " peaceful in the cooling air", " contemplative as seasons change",
        " scattered with floating autumn leaves" }));

    addAlias("water");
    addAlias("pond");
    addAlias("pool");
    addAlias("lake");

    addDescriptionTemplate("a ##Adjective## pond");
    addItemTemplate("The pond sits peacefully in its natural basin, its "
        "still waters serving as a perfect mirror for the sky above. "
        "Cattails and water lilies border the edges while dragonflies "
        "patrol the surface in endless aerial dances. Fish rise "
        "occasionally to feed, creating gentle ripples that spread "
        "in perfect concentric circles. Frogs chorus from hidden "
        "spots among the reeds while herons stand motionless in the "
        "shallows, waiting with infinite patience. The pond provides "
        "a sanctuary of calm where wildlife gathers to drink and "
        "rest, creating a perfect ecosystem of interdependent life "
        "centered around this precious water source.");
}
