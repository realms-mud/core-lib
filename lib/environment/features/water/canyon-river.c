//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("canyon river");
    addAdjectives(({ "mighty", "thundering", "ancient", "carved", "powerful" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching filtered dawn light",
        "outlined in the brightening canyon depths",
        "emerging from morning canyon mist",
        "touched by rays penetrating the deep canyon",
        "shimmering in the pale morning light",
        "awakening with ancient power"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle filtered morning light",
        "with sunlight creating dramatic water patterns",
        "bright in the deep morning canyon shadows",
        "alive with thunderous morning energy",
        "sparkling with reflected morning sun",
        "powerful in the morning canyon flow"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible when sunlight penetrates deeply",
        "magnificent and powerful at midday",
        "brilliant when touched by high noon sun",
        "imposing in the canyon's dramatic depths",
        "dazzling in the filtered intense daylight",
        "awe-inspiring in the midday canyon flow"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with waters thundering through the afternoon",
        "powerful in the late afternoon canyon current",
        "carving relentlessly in the afternoon warmth",
        "magnificent in the filtered afternoon light",
        "energetic in the afternoon's ancient flow",
        "persistent in the afternoon's endless carving"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in filtered evening light",
        "as sunset light reaches into the deep canyon",
        "painted in dramatic evening colors",
        "beautiful in the magnificent evening glow",
        "romantic despite its thunderous power",
        "transformed by the filtered golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the deep canyon shadows",
        "becoming mysterious as canyon dusk deepens",
        "outlined in the darkening canyon depths",
        "peaceful despite its thunderous voice",
        "cool in the evening canyon shadows",
        "contemplative in the gathering canyon darkness"
        }));
    addTimeOfDayDescription("night", ({
        "discernable by its thunderous echoing roar",
        "outlined by moonlight filtering far down",
        "mysterious in the profound canyon darkness",
        "peaceful despite its constant thunder",
        "enchanted by greatly amplified night sounds",
        "active in the protected canyon darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible in the deep canyon shadows",
        "lost in the profound canyon darkness",
        "hidden in the canyon's midnight depths",
        "present as thunderous sounds in the night",
        "mysterious in the midnight's ancient flow",
        "embraced by the canyon's eternal darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({
        " partially frozen with spectacular canyon ice formations",
        " thundering through winter's dramatic canyon grip",
        " flowing with winter power in the canyon depths",
        " carving through winter's canyon embrace",
        " active even in winter's frozen canyon touch",
        " standing as winter's persistent canyon carver" }));
    addSeasonDescription("spring", ({
        " swollen with dramatic spring canyon flooding",
        " carving with tremendous spring canyon energy",
        " thundering with spring's renewed canyon power",
        " alive with spectacular canyon erosion",
        " energized by spring's overwhelming canyon force",
        " renewed by seasonal canyon flooding" }));
    addSeasonDescription("summer", ({
        " running powerful through the canyon's summer depths",
        " carving magnificently through summer canyon months",
        " thundering with consistent summer canyon power",
        " active with relentless summer canyon flow",
        " determined in summer's ancient canyon embrace",
        " steady in summer's persistent canyon carving" }));
    addSeasonDescription("autumn", ({
        " carrying autumn debris in its powerful canyon flow",
        " carving with autumn's steady canyon power",
        " thundering as seasons change in the canyon",
        " beautiful in autumn's filtered canyon light",
        " contemplative yet eternally canyon powerful",
        " preparing for winter's frozen canyon challenge" }));

    addAlias("river");
    addAlias("water");
    addAlias("flowing water");
    addAlias("canyon");
    addAlias("current");

    addDescriptionTemplate("a ##Adjective## canyon river");
    addItemTemplate("The canyon river thunders through its magnificent "
        "gorge with the accumulated power of countless tributaries, "
        "its mighty current having carved this spectacular canyon "
        "over geological ages. The river's relentless flow echoes "
        "and amplifies within the towering stone walls, creating "
        "a thunderous symphony that speaks of nature's ultimate "
        "power to reshape the earth. Ancient sedimentary layers "
        "exposed in the canyon walls tell the story of millions "
        "of years while the river continues its eternal work of "
        "cutting ever deeper into the bedrock. This magnificent "
        "waterway serves as both creator and centerpiece of one "
        "of nature's most spectacular architectural achievements.");
}
