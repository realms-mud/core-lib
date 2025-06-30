//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("canyon stream");
    addAdjectives(({ "flowing", "echoing", "winding", "carved", "sheltered" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching filtered dawn light",
        "outlined in the brightening canyon",
        "emerging from morning canyon mist",
        "touched by indirect rays penetrating down",
        "shimmering in the pale morning light",
        "awakening in its protected corridor"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle filtered morning light",
        "with sunlight creating patterns on flowing water",
        "bright in the morning canyon shadows",
        "alive with echoing morning sounds",
        "sparkling with reflected morning sun",
        "peaceful in the morning canyon calm"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible when sunlight penetrates",
        "flowing steadily at midday",
        "brilliant when touched by noon sun",
        "prominent in the canyon's depths",
        "dazzling in the filtered daylight",
        "magnificent in the midday canyon light"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with waters flowing through the afternoon",
        "peaceful in the late afternoon canyon calm",
        "warmed by filtered afternoon sun",
        "serene in the canyon's protection",
        "comfortable in the afternoon shadows",
        "beautiful in the canyon's afternoon glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in filtered evening light",
        "as sunset light reaches into the canyon",
        "painted in muted evening colors",
        "beautiful in the gentle evening glow",
        "romantic in the protected twilight",
        "transformed by the filtered golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the canyon shadows",
        "becoming mysterious as dusk deepens",
        "outlined in the darkening canyon",
        "peaceful as night approaches",
        "cool in the evening canyon shadows",
        "contemplative in the gathering darkness"
        }));
    addTimeOfDayDescription("night", ({
        "discernable by its echoing flow",
        "outlined by moonlight filtering down",
        "mysterious in the canyon darkness",
        "peaceful in the protected night",
        "enchanted by amplified night sounds",
        "hidden in the canyon's embrace"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible in the deep canyon shadows",
        "lost in the profound darkness",
        "hidden in the canyon's midnight",
        "present as echoing sounds in the night",
        "mysterious in the midnight flow",
        "embraced by the canyon's darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " partially frozen in its protected channel",
        " flowing beneath thin ice in the canyon shelter", " bordered by frost in the canyon depths",
        " running cold through winter's canyon embrace", " carved through winter's protected landscape",
        " standing as winter's sheltered waterway" }));
    addSeasonDescription("spring", ({ " swollen with spring rains in the canyon",
        " surrounded by budding canyon vegetation", " flowing swiftly with spring canyon runoff",
        " alive with returning canyon wildlife", " bordered by protected spring growth",
        " renewed by seasonal canyon flooding" }));
    addSeasonDescription("summer", ({ " running clear through the canyon's summer shelter",
        " surrounded by lush canyon vegetation", " perfect for summer canyon exploration",
        " alive with protected aquatic life", " inviting in the canyon's cooling embrace",
        " peaceful in summer's canyon protection" }));
    addSeasonDescription("autumn", ({ " reflecting autumn colors visible above",
        " flowing past canyon walls touched by fall", " beautiful in autumn's filtered canyon light",
        " peaceful in the cooling canyon air", " contemplative as seasons change overhead",
        " carrying leaves fallen from canyon heights" }));

    addAlias("stream");
    addAlias("water");
    addAlias("flowing water");
    addAlias("canyon");
    addAlias("current");

    addDescriptionTemplate("a ##Adjective## canyon stream");
    addItemTemplate("The canyon stream flows purposefully through its "
        "carved channel, its waters echoing softly off the towering "
        "walls that rise on either side. Protected from harsh winds "
        "and weather by the canyon's embrace, this waterway has "
        "helped carve its spectacular corridor over countless years. "
        "The stream navigates between fallen boulders and smooth "
        "stone formations, creating pools and cascades that support "
        "a unique ecosystem adapted to the canyon environment. "
        "Ferns and moisture-loving plants thrive in the perpetual "
        "humidity while the stream's gentle song reverberates "
        "through the natural stone amphitheater, creating a peaceful "
        "sanctuary hidden from the world above.");
}
