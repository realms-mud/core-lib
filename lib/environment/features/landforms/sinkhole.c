//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sinkhole");
    addAdjectives(({ "circular", "steep-sided", "mysterious", "deep", "shadowed",
        "collapsed", "water-filled", "limestone", "treacherous", "hidden" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " mysterious in gathering mist",
        " shadowed while surroundings brighten",
        " deep in morning vapor",
        " dark in first light",
        " hidden in lingering shadows",
        " circular in dawn outline",
        " steep-sided in early clarity",
        " treacherous in dim light",
        " collapsed in morning revelation",
        " water-gleaming in depths"
        }));

    addTimeOfDayDescription("morning", ({
        " clearly revealed in daylight",
        " steep-sided in full visibility",
        " deep in morning illumination",
        " circular in bright outline",
        " treacherous in clear view",
        " mysterious despite visibility",
        " shadowed in inner depths",
        " collapsed in obvious danger",
        " hidden features now revealed",
        " water-bright in morning sun"
        }));

    addTimeOfDayDescription("noon", ({
        " harsh in direct overhead light",
        " steep-sided in stark clarity",
        " deep in shadowless exposure",
        " circular in perfect definition",
        " treacherous in full revelation",
        " mysterious in bright daylight",
        " collapsed in obvious peril",
        " hidden depths now visible",
        " water-brilliant in sun",
        " dangerous in clear visibility"
        }));

    addTimeOfDayDescription("afternoon", ({
        " textured by angled sunlight",
        " steep-sided in shadow patterns",
        " deep in afternoon clarity",
        " circular in declining light",
        " treacherous in revealed detail",
        " mysterious in lengthening shadows",
        " collapsed in afternoon exposure",
        " hidden features emphasized",
        " water-dark in angled light",
        " dangerous in clear definition"
        }));

    addTimeOfDayDescription("evening", ({
        " mysterious in gathering shadows",
        " steep-sided in evening darkness",
        " deep in shadowed mystery",
        " circular in twilight outline",
        " treacherous in fading light",
        " hidden in evening gloom",
        " collapsed in growing darkness",
        " water-black in depths",
        " dangerous in dimming visibility",
        " ominous in sunset shadows"
        }));

    addTimeOfDayDescription("dusk", ({
        " hidden in gathering darkness",
        " treacherous in failing light",
        " deep in twilight mystery",
        " circular in vague outline",
        " steep-sided in shadow",
        " mysterious in growing gloom",
        " collapsed in dangerous darkness",
        " water-invisible in depths",
        " perilous in dim visibility",
        " threatening in dusk shadows"
        }));

    addTimeOfDayDescription("night", ({
        " invisible in complete darkness",
        " treacherous without illumination",
        " deep in night mystery",
        " circular in felt presence",
        " steep-sided in hidden danger",
        " mysterious in night concealment",
        " collapsed in unseen peril",
        " water-hidden in black depths",
        " deadly in night darkness",
        " dangerous in unseen presence"
        }));

    addTimeOfDayDescription("late night", ({
        " perilous in deep darkness",
        " treacherous in night concealment",
        " deep in midnight mystery",
        " circular in unseen threat",
        " steep-sided in hidden danger",
        " mysterious in night secrecy",
        " collapsed in invisible peril",
        " water-black in unseen depths",
        " deadly in complete darkness",
        " threatening in night concealment"
        }));

    addTimeOfDayDescription("midnight", ({
        " deadly in absolute darkness",
        " treacherous in midnight concealment",
        " deep in cosmic mystery",
        " circular in felt menace",
        " steep-sided in midnight danger",
        " mysterious in deepest night",
        " collapsed in unseen threat",
        " water-void in black depths",
        " perilous in complete concealment",
        " ominous in midnight presence"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " ice-rimmed in freezing weather",
        " treacherous with winter hazards",
        " deep with accumulated snow",
        " circular in white outline",
        " steep-sided with icy walls",
        " mysterious in winter concealment",
        " collapsed in frozen peril",
        " water-frozen in depths",
        " dangerous with ice formation",
        " hidden by snow accumulation"
        }));

    addSeasonDescription("spring", ({
        " filling with spring runoff",
        " treacherous with muddy edges",
        " deep with seasonal water",
        " circular in clear spring outline",
        " steep-sided with erosion",
        " mysterious in spring revelation",
        " collapsed with spring damage",
        " water-rising in depths",
        " dangerous with unstable edges",
        " hidden by spring vegetation"
        }));

    addSeasonDescription("summer", ({
        " stark in summer exposure",
        " treacherous in heat shimmer",
        " deep in blazing clarity",
        " circular in harsh definition",
        " steep-sided in bright light",
        " mysterious despite full exposure",
        " collapsed in summer revelation",
        " water-low in summer depths",
        " dangerous in clear visibility",
        " obvious in summer heat"
        }));

    addSeasonDescription("autumn", ({
        " filled with fallen leaves",
        " treacherous with slippery debris",
        " deep in autumn mystery",
        " circular in leaf-outlined form",
        " steep-sided with autumn erosion",
        " mysterious in seasonal change",
        " collapsed with autumn damage",
        " water-dark with leaf matter",
        " dangerous with hidden edges",
        " concealed by autumn foliage"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## sinkhole forming a dangerous "
        "depression in the ground");

    addItemTemplate("The sinkhole forms a circular or oval depression where "
        "the ground has collapsed, typically due to underground water erosion "
        "of limestone or similar soluble rock. The steep-sided pit presents "
        "a significant hazard, with walls that may be unstable and prone to "
        "further collapse. Water often collects in the bottom, creating a "
        "deep pool that may connect to underground water systems. Vegetation "
        "around the edges may be disturbed or absent, and the sinkhole serves "
        "as a stark reminder of the hidden geological processes constantly "
        "reshaping the landscape.");
}
