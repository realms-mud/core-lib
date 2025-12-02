//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("canyon brook");
    addAdjectives(({ "babbling", "gentle", "peaceful", "tiny", "protected" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching filtered dawn light",
        "outlined in the brightening canyon",
        "emerging from morning canyon mist",
        "touched by gentle rays filtering down",
        "shimmering in the pale morning light",
        "awakening with soft canyon whispers"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle filtered morning light",
        "with sunlight dancing on tiny canyon ripples",
        "bright in the morning canyon shadows",
        "alive with delicate echoing morning sounds",
        "sparkling with reflected morning sun",
        "peaceful in the morning canyon calm"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible when sunlight penetrates",
        "crystal clear in the canyon's noon shelter",
        "brilliant when touched by high sun",
        "delicate in the canyon's protective depths",
        "dazzling in the filtered canyon daylight",
        "charming in the midday canyon light"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with waters trickling through the canyon afternoon",
        "peaceful in the late afternoon canyon calm",
        "warmed by gentle filtered afternoon sun",
        "serene in the canyon's protective embrace",
        "comfortable in the afternoon canyon shadows",
        "soothing in the canyon afternoon glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in filtered evening light",
        "as sunset light reaches into the canyon",
        "painted in gentle canyon evening colors",
        "beautiful in the canyon evening glow",
        "romantic in the protected canyon twilight",
        "enchanted by the filtered golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the canyon shadows",
        "becoming mysterious as canyon dusk deepens",
        "outlined in the darkening canyon",
        "peaceful as night approaches the canyon",
        "cool in the evening canyon shadows",
        "contemplative in the gathering canyon darkness"
        }));
    addTimeOfDayDescription("night", ({
        "discernable by its gentle canyon babble",
        "outlined by moonlight filtering down",
        "mysterious in the canyon darkness",
        "peaceful in the protected canyon night",
        "enchanted by softly amplified canyon night sounds",
        "hidden in the canyon's gentle embrace"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible in the deep canyon shadows",
        "lost in the profound canyon darkness",
        "hidden in the canyon's midnight depths",
        "present as gentle echoing sounds",
        "mysterious in the midnight canyon flow",
        "embraced by the canyon's darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " partially frozen with delicate canyon ice formations",
        " trickling beneath thin ice in canyon shelter", " bordered by frost-covered canyon pebbles",
        " running gently through winter's canyon embrace", " peaceful in winter's quiet canyon protection",
        " standing as winter's gentle canyon lifeline" }));
    addSeasonDescription("spring", ({ " swollen with gentle spring canyon rains",
        " surrounded by tender canyon vegetation", " flowing briskly with spring canyon energy",
        " alive with returning small canyon wildlife", " bordered by delicate canyon spring flowers",
        " renewed by seasonal canyon moisture" }));
    addSeasonDescription("summer", ({ " trickling peacefully through the canyon's summer embrace",
        " surrounded by lush small canyon plants", " perfect for quiet canyon contemplation",
        " alive with tiny protected aquatic creatures", " soothing with its gentle canyon presence",
        " peaceful in summer's canyon protection" }));
    addSeasonDescription("autumn", ({ " reflecting autumn colors from canyon heights above",
        " flowing past small canyon autumn plants", " beautiful in autumn's soft canyon light",
        " peaceful in the cooling canyon air", " contemplative as seasons change in the canyon",
        " carrying tiny leaves through the canyon" }));

    addAlias("brook");
    addAlias("water");
    addAlias("flowing water");
    addAlias("canyon");
    addAlias("stream");

    addDescriptionTemplate("a ##Adjective## canyon brook");
    addItemTemplate("The canyon brook trickles gently through the "
        "spectacular gorge with quiet determination, its shallow "
        "waters creating a delicate melody that echoes softly off "
        "the towering canyon walls. This intimate waterway has "
        "carved the smallest of channels through the canyon floor, "
        "creating miniature pools where water striders dance and "
        "small fish hide in the protected environment. Delicate "
        "mosses and tiny ferns cluster along its banks, thriving "
        "in the gentle moisture and constant humidity created by "
        "the canyon's embrace. The brook's soft babbling provides "
        "a peaceful soundtrack that reverberates gently through "
        "the natural stone amphitheater, creating an intimate "
        "sanctuary where time seems to slow in this hidden corner "
        "of the canyon's depths.");
}
