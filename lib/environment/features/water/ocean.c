//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ocean");
    addAdjectives(({ "vast", "endless", "mighty", "infinite", "eternal" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching the faint dawn light",
        "stretching endlessly to the brightening horizon",
        "emerging from morning oceanic mist",
        "touched by the first rays over endless waters",
        "shimmering across the infinite morning expanse",
        "awakening with the rhythm of eternal tides"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight dancing on countless waves",
        "sparkling across the morning expanse",
        "alive with morning oceanic energy",
        "bright with reflected morning sun",
        "peaceful despite its immense power"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible stretching to infinity",
        "brilliant blue under the noon sun",
        "dazzling in the intense oceanic light",
        "magnificent in its endless expanse",
        "imposing under the blazing sun",
        "breathtaking in the midday brightness"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with swells rolling endlessly",
        "peaceful in its afternoon rhythm",
        "warmed by the gentle afternoon sun",
        "serene despite its vast power",
        "comfortable in the afternoon oceanic breeze",
        "beautiful in the afternoon glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in the golden evening light",
        "reflecting the magnificent sunset across infinity",
        "painted in spectacular evening colors",
        "beautiful beyond description in evening light",
        "romantic in the fading oceanic daylight",
        "transformed by the golden oceanic hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with horizon fading in the last light of day",
        "becoming mysterious as oceanic dusk settles",
        "peaceful as night approaches the waters",
        "cool in the evening oceanic shadows",
        "contemplative in the deepening oceanic dusk",
        "serene in the gathering oceanic darkness"
        }));
    addTimeOfDayDescription("night", ({
        "reflecting moonlight across endless waters",
        "peaceful under the infinite starry sky",
        "silvered by moonlight to the horizon",
        "mysterious in the oceanic darkness",
        "enchanted by the eternal oceanic rhythm",
        "magnificent in the night's embrace"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the profound oceanic darkness",
        "hidden in the infinite night",
        "present as eternal sound and movement",
        "mysterious in the midnight oceanic hour",
        "embraced by the endless darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " churning with powerful winter storms",
        " displaying winter's awesome oceanic power", " carved by massive winter swells",
        " demonstrating nature's winter fury", " transformed by winter's oceanic violence",
        " standing as winter's ultimate force" }));
    addSeasonDescription("spring", ({ " alive with spring oceanic currents",
        " renewed by changing seasonal patterns", " awakened by spring's oceanic energy",
        " vibrant with migrating marine life", " refreshed by spring's oceanic renewal",
        " celebrating spring's infinite potential" }));
    addSeasonDescription("summer", ({ " perfect in summer's oceanic glory",
        " magnificent in summer's endless blue", " alive with abundant summer marine life",
        " inviting despite its awesome power", " beautiful in summer's oceanic embrace",
        " teeming with summer's oceanic abundance" }));
    addSeasonDescription("autumn", ({ " dramatic with autumn's oceanic storms",
        " beautiful in autumn's changing light", " powerful with autumn's oceanic swells",
        " magnificent as seasons change over infinity", " sculptured by autumn's oceanic energy",
        " preparing for winter's oceanic fury" }));

    addAlias("water");
    addAlias("ocean");
    addAlias("sea");
    addAlias("waters");
    addAlias("deep");

    addDescriptionTemplate("the ##Adjective## ocean");
    addItemTemplate("The ocean stretches endlessly toward the horizon, "
        "its vast expanse representing the ultimate expression of "
        "water's power and mystery. Countless waves rise and fall "
        "in an eternal rhythm that has persisted since the world's "
        "beginning, each swell carrying stories from distant shores "
        "and foreign lands. The ocean's depths harbor creatures "
        "beyond imagination while its surface dances with light and "
        "shadow, creating an ever-changing tapestry of blue and "
        "silver. Seabirds patrol its endless expanse while marine "
        "life thrives in its nurturing embrace, making the ocean "
        "both mother and mystery, source of all life and keeper "
        "of countless secrets in its infinite depths.");
}
