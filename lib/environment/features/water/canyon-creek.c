//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("canyon creek");
    addAdjectives(({ "rushing", "echoing", "carved", "sheltered", "winding" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching filtered dawn light",
        "outlined in the brightening canyon",
        "emerging from morning canyon mist",
        "touched by rays penetrating down the canyon",
        "shimmering in the pale morning light",
        "awakening with echoing murmurs"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle filtered morning light",
        "with sunlight dancing on canyon ripples",
        "bright in the morning canyon shadows",
        "alive with echoing morning activity",
        "sparkling with reflected morning sun",
        "peaceful in the morning canyon stillness"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible when sunlight penetrates",
        "crystal clear in the canyon's noon depths",
        "brilliant when touched by high sun",
        "prominent in the canyon's embrace",
        "dazzling in the filtered canyon daylight",
        "magnificent in the midday canyon flow"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with waters flowing through the canyon afternoon",
        "peaceful in the late afternoon canyon calm",
        "warmed by filtered afternoon sun",
        "serene in the canyon's protection",
        "comfortable in the afternoon canyon shadows",
        "beautiful in the canyon afternoon glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in filtered evening light",
        "as sunset light reaches into the canyon",
        "painted in muted canyon evening colors",
        "beautiful in the canyon evening glow",
        "romantic in the protected canyon twilight",
        "transformed by the filtered golden hour"
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
        "discernable by its gentle canyon echoes",
        "outlined by moonlight filtering down",
        "mysterious in the canyon darkness",
        "peaceful in the protected canyon night",
        "enchanted by amplified canyon night sounds",
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
    addSeasonDescription("winter", ({ " partially frozen in its canyon channel",
        " flowing beneath thin ice in canyon shelter", " bordered by frost in the canyon depths",
        " running cold through winter's canyon embrace", " carved through winter's protected canyon landscape",
        " standing as winter's sheltered canyon waterway" }));
    addSeasonDescription("spring", ({ " running high with canyon snowmelt",
        " surrounded by budding canyon vegetation", " flowing swiftly with spring canyon runoff",
        " alive with returning canyon wildlife", " bordered by protected spring canyon growth",
        " renewed by seasonal canyon rains" }));
    addSeasonDescription("summer", ({ " running clear through the canyon's summer embrace",
        " surrounded by lush canyon vegetation", " perfect for summer canyon contemplation",
        " alive with protected canyon aquatic life", " inviting in the canyon's cooling presence",
        " peaceful in summer's canyon protection" }));
    addSeasonDescription("autumn", ({ " reflecting autumn colors from canyon heights",
        " flowing past canyon walls touched by fall", " beautiful in autumn's filtered canyon light",
        " peaceful in the cooling canyon air", " contemplative as seasons change in the canyon",
        " carrying scattered canyon leaves downstream" }));

    addAlias("creek");
    addAlias("water");
    addAlias("flowing water");
    addAlias("canyon");
    addAlias("stream");

    addDescriptionTemplate("a ##Adjective## canyon creek");
    addItemTemplate("The canyon creek winds its way through the dramatic "
        "gorge with determined purpose, its clear waters navigating "
        "between moss-covered boulders and ancient stone formations. "
        "The creek has helped carve its canyon channel over countless "
        "years, creating small pools and cascades as it descends "
        "through the protected corridor. Ferns and moisture-loving "
        "plants thrive along its banks in the constantly humid "
        "environment, while small fish dart between the stones in "
        "the deeper canyon sections. The sound of flowing water "
        "echoes and amplifies off the canyon walls, creating a "
        "natural symphony that speaks of patience, persistence, "
        "and the gentle power of water to shape stone through "
        "time and determination.");
}
