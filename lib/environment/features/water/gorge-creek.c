//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gorge creek");
    addAdjectives(({ "thundering", "powerful", "ancient", "carved", "magnificent" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching the faint dawn light",
        "outlined in the brightening gorge",
        "emerging from morning gorge mist",
        "touched by indirect rays filtering deep down",
        "shimmering in the pale morning light",
        "awakening with ancient power"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle filtered morning light",
        "with sunlight creating dramatic patterns",
        "bright in the deep morning gorge shadows",
        "alive with morning's thunderous energy",
        "sparkling with reflected morning sun",
        "powerful in the morning flow"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible when sunlight penetrates deeply",
        "magnificent and powerful at midday",
        "brilliant when touched by high noon sun",
        "imposing in the gorge's dramatic depths",
        "dazzling in the filtered intense daylight",
        "awe-inspiring in the midday flow"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with waters thundering through the afternoon",
        "powerful in the late afternoon current",
        "carving relentlessly in the afternoon warmth",
        "magnificent in the filtered afternoon light",
        "energetic in the afternoon's ancient flow",
        "persistent in the afternoon's endless carving"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in filtered evening light",
        "as sunset light reaches into the deep gorge",
        "painted in dramatic evening colors",
        "beautiful in the magnificent evening glow",
        "romantic despite its thunderous power",
        "transformed by the filtered golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the deep gorge shadows",
        "becoming mysterious as dusk deepens",
        "outlined in the darkening gorge depths",
        "peaceful despite its thunderous voice",
        "cool in the evening gorge shadows",
        "contemplative in the gathering gorge darkness"
        }));
    addTimeOfDayDescription("night", ({
        "discernable by its thunderous echoing roar",
        "outlined by moonlight filtering far down",
        "mysterious in the profound gorge darkness",
        "peaceful despite its constant thunder",
        "enchanted by greatly amplified night sounds",
        "active in the protected gorge darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible in the deep gorge shadows",
        "lost in the profound gorge darkness",
        "hidden in the gorge's midnight depths",
        "present as thunderous sounds in the night",
        "mysterious in the midnight's ancient flow",
        "embraced by the gorge's eternal darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " partially frozen with spectacular ice formations",
        " carving through winter's dramatic grip", " thundering despite winter's icy touch",
        " flowing beneath magnificent ice sculptures", " active even in winter's frozen embrace",
        " standing as winter's persistent ancient carver" }));
    addSeasonDescription("spring", ({ " swollen with dramatic spring flooding",
        " carving with tremendous spring energy", " thundering with spring's renewed ancient power",
        " alive with spectacular spring erosion", " energized by spring's overwhelming force",
        " renewed by seasonal gorge flooding" }));
    addSeasonDescription("summer", ({ " running powerful despite summer heat",
        " carving magnificently through summer months", " thundering with consistent summer power",
        " active with relentless summer flow", " determined in summer's ancient embrace",
        " steady in summer's persistent magnificent carving" }));
    addSeasonDescription("autumn", ({ " carrying autumn debris in its powerful flow",
        " carving with autumn's steady ancient power", " thundering as seasons change dramatically",
        " beautiful in autumn's filtered gorge light", " contemplative yet eternally powerful",
        " preparing for winter's frozen challenge" }));

    addAlias("creek");
    addAlias("water");
    addAlias("flowing water");
    addAlias("gorge");
    addAlias("canyon");

    addDescriptionTemplate("a ##Adjective## gorge creek");
    addItemTemplate("The gorge creek thunders through its ancient channel "
        "with the power and persistence of geological time itself. "
        "This magnificent waterway has carved its spectacular gorge "
        "through solid rock over countless millennia, creating "
        "towering walls that rise dramatically on either side. The "
        "creek's relentless flow echoes and amplifies within the "
        "stone confines, creating a natural cathedral where water's "
        "voice reverberates with primal power. Ancient sedimentary "
        "layers exposed in the gorge walls tell the story of Earth's "
        "history while the creek continues its eternal work of "
        "cutting ever deeper into the bedrock, demonstrating the "
        "ultimate triumph of persistence over resistance.");
}
