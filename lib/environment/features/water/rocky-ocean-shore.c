//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rocky ocean shore");
    addAdjectives(({ "magnificent", "powerful", "endless", "wild", "untamed" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with rocks catching the faint oceanic dawn",
        "outlined against the infinite ocean horizon",
        "emerging from the vast morning ocean mist",
        "touched by the first rays over endless waters",
        "silhouetted against the oceanic dawn",
        "bathed in the pale ocean morning light"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight gleaming on ocean-carved rocks",
        "bright with morning ocean spray",
        "alive with morning oceanic energy",
        "sparkling with reflected ocean sun",
        "fresh in the powerful morning ocean breeze"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full oceanic light",
        "stark against the endless blue ocean",
        "brilliant in the noon ocean sun",
        "imposing under the vast oceanic sky",
        "dazzling with ocean spray and brilliant light",
        "magnificent under the high ocean sun"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with powerful waves crashing against stone",
        "sculptured by the mighty afternoon ocean",
        "enduring the relentless oceanic assault",
        "carved by countless afternoon ocean storms",
        "standing firm against oceanic power",
        "weathered by the eternal ocean rhythm"
        }));
    addTimeOfDayDescription("evening", ({
        "with rocks glowing in oceanic sunset light",
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
        "discernable by the thunder of ocean waves",
        "silvered by moonlight on the vast ocean",
        "mysterious in the oceanic darkness",
        "peaceful under the infinite ocean night sky",
        "enchanted by the eternal ocean symphony"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight ocean sky",
        "lost in the profound oceanic darkness",
        "hidden in the vast ocean night",
        "merged with the infinite dark waters",
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
        " perfect for oceanic exploration", " alive with summer ocean creatures",
        " inviting despite the ocean's power", " beautiful in summer's ocean light",
        " teeming with oceanic summer life" }));
    addSeasonDescription("autumn", ({ " swept by powerful autumn ocean storms",
        " dramatic in autumn's oceanic light", " carved by autumn's oceanic swells",
        " magnificent as seasons change", " sculptured by autumn's ocean power",
        " preparing for winter's oceanic fury" }));

    addAlias("rocks");
    addAlias("shore");
    addAlias("ocean shore");
    addAlias("coastline");
    addAlias("rocky shore");
    addAlias("oceanic coast");

    addDescriptionTemplate("a ##Adjective## rocky ocean shore");
    addItemTemplate("The rocky ocean shore stands as a testament to the "
        "eternal struggle between immovable stone and irresistible "
        "oceanic force. Massive granite headlands and volcanic "
        "formations rise defiantly from the churning waters, their "
        "surfaces polished smooth by millennia of oceanic assault. "
        "The thunderous crash of powerful swells creates geysers of "
        "spray that reach impossible heights, while the backwash "
        "reveals tide pools filled with creatures adapted to this "
        "harsh environment. The horizon stretches endlessly, where "
        "ocean meets sky in an infinite blue expanse, making this "
        "coastline a place of both beauty and awesome natural power.");
}
