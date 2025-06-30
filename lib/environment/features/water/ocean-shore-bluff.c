//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ocean shore bluff");
    addAdjectives(({ "towering", "magnificent", "windswept", "dramatic", "imposing" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with cliffs catching the faint oceanic dawn",
        "outlined against the infinite ocean horizon",
        "emerging from morning oceanic mist",
        "touched by the first rays over endless waters",
        "silhouetted against the oceanic dawn",
        "awakening to face the eternal ocean"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight illuminating the ocean-facing cliff",
        "bright with morning oceanic spray",
        "alive with morning oceanic energy",
        "sparkling with reflected ocean sun",
        "fresh in the powerful morning ocean breeze"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible against the endless ocean",
        "stark and magnificent at midday",
        "brilliant white in the noon ocean sun",
        "imposing under the vast oceanic sky",
        "dazzling with ocean spray and brilliant light",
        "magnificent under the high ocean sun"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with powerful waves crashing far below",
        "sculptured by the mighty afternoon ocean",
        "enduring the relentless oceanic assault",
        "carved by countless afternoon ocean storms",
        "standing firm against oceanic power",
        "weathered by the eternal ocean rhythm"
        }));
    addTimeOfDayDescription("evening", ({
        "with cliffs glowing in oceanic sunset light",
        "as the sun sets over the infinite ocean",
        "painted in magnificent oceanic sunset colors",
        "beautiful against the evening ocean expanse",
        "transformed by the golden oceanic hour",
        "romantic in the fading ocean light"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in oceanic twilight",
        "becoming silhouettes against the ocean dusk",
        "mysterious in the gathering ocean darkness",
        "outlined against the darkening ocean waters",
        "peaceful as night approaches the ocean",
        "contemplative in the oceanic twilight"
        }));
    addTimeOfDayDescription("night", ({
        "outlined against the moonlit ocean expanse",
        "discernable by the thunder of ocean waves below",
        "silvered by moonlight on the vast ocean",
        "mysterious in the oceanic darkness",
        "peaceful under the infinite ocean night sky",
        "enchanted by the eternal ocean symphony"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight ocean sky",
        "lost in the profound oceanic darkness",
        "hidden in the vast ocean night",
        "merged with the infinite dark waters below",
        "invisible save for thundering ocean waves",
        "embraced by the midnight ocean vastness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " battered by massive winter ocean storms",
        " carved by towering winter ocean swells", " reshaped by winter's oceanic fury",
        " enduring the brutal winter ocean assault", " transformed by oceanic winter violence",
        " standing against winter's oceanic power" }));
    addSeasonDescription("spring", ({ " alive with spring oceanic currents",
        " visited by migrating ocean wildlife", " refreshed by changing ocean patterns",
        " renewed by spring's oceanic energy", " awakened by warming ocean waters",
        " vibrant with spring ocean life" }));
    addSeasonDescription("summer", ({ " magnificent in summer's oceanic glory",
        " perfect for oceanic observation", " alive with summer ocean creatures below",
        " inviting despite the ocean's power", " beautiful in summer's ocean light",
        " teeming with oceanic summer life" }));
    addSeasonDescription("autumn", ({ " swept by powerful autumn ocean storms",
        " dramatic in autumn's oceanic light", " carved by autumn's oceanic swells",
        " magnificent as seasons change over the ocean", " sculptured by autumn's ocean power",
        " preparing for winter's oceanic fury" }));

    addAlias("bluff");
    addAlias("cliff");
    addAlias("cliffs");
    addAlias("ocean shore");
    addAlias("shore");
    addAlias("coastline");

    addDescriptionTemplate("a ##Adjective## ocean shore bluff");
    addItemTemplate("The ocean shore bluff rises majestically from the "
        "churning oceanic waters far below, its weathered face "
        "carved by countless millennia of oceanic assault. These "
        "towering cliffs bear witness to the eternal struggle between "
        "immovable stone and the irresistible force of the endless "
        "ocean. Seabirds nest in the rocky alcoves while hardy "
        "coastal vegetation clings to the cliff face, both adapted "
        "to life in this harsh oceanic environment. The constant "
        "thunder of massive swells crashing against the base creates "
        "geysers of spray that reach impossible heights, while the "
        "bluff provides a dramatic vantage point over the infinite "
        "oceanic expanse that stretches beyond the horizon.");
}
