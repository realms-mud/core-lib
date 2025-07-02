//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cliff");
    addAdjectives(({ "sheer", "towering", "vertical", "imposing", "weathered",
        "dangerous", "stark", "massive" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " stark in first light",
        " towering against dawn sky",
        " sheer in morning clarity",
        " imposing in early glow",
        " vertical in dawn illumination",
        " weathered in revealing light",
        " dangerous in clear exposure",
        " massive in dawn grandeur",
        " dramatic in sunrise",
        " formidable in early light"
        }));

    addTimeOfDayDescription("morning", ({
        " clear in morning illumination",
        " towering in bright visibility",
        " sheer in full exposure",
        " imposing in daylight",
        " vertical in morning clarity",
        " weathered in detailed light",
        " dangerous in clear view",
        " massive in morning scale",
        " forbidding in bright light",
        " overwhelming in daylight"
        }));

    addTimeOfDayDescription("noon", ({
        " harsh in direct sunlight",
        " towering in blazing clarity",
        " sheer in shadowless exposure",
        " imposing in peak illumination",
        " vertical in stark light",
        " weathered in harsh detail",
        " dangerous in full revelation",
        " massive in overwhelming scale",
        " forbidding in intense light",
        " brutal in noon exposure"
        }));

    addTimeOfDayDescription("afternoon", ({
        " textured in angled light",
        " towering in afternoon glow",
        " sheer with shadow patterns",
        " imposing in declining sun",
        " vertical in warm light",
        " weathered in golden illumination",
        " dangerous in clear definition",
        " massive in afternoon scale",
        " dramatic in angled sun",
        " striking in afternoon light"
        }));

    addTimeOfDayDescription("evening", ({
        " dramatic against sunset",
        " towering in evening glory",
        " sheer in golden light",
        " imposing in alpenglow",
        " vertical in sunset colors",
        " weathered in evening beauty",
        " dangerous in twilight drama",
        " massive in evening grandeur",
        " spectacular in sunset",
        " magnificent in evening light"
        }));

    addTimeOfDayDescription("dusk", ({
        " mysterious in gathering shadow",
        " towering in twilight outline",
        " sheer in fading light",
        " imposing in dusk mystery",
        " vertical in gathering gloom",
        " weathered in twilight shadow",
        " dangerous in dim visibility",
        " massive in dusk presence",
        " forbidding in gathering dark",
        " ominous in twilight"
        }));

    addTimeOfDayDescription("night", ({
        " stark against starry sky",
        " towering in night grandeur",
        " sheer in moonlit outline",
        " imposing in lunar light",
        " vertical in night shadow",
        " weathered in night mystery",
        " dangerous in darkness",
        " massive in night presence",
        " formidable under stars",
        " intimidating in night"
        }));

    addTimeOfDayDescription("late night", ({
        " mysterious in deep darkness",
        " towering in felt presence",
        " sheer in night mystery",
        " imposing in unseen majesty",
        " vertical in night threat",
        " weathered in time endurance",
        " dangerous in concealed peril",
        " massive in night dominance",
        " overwhelming in darkness",
        " forbidding in deep night"
        }));

    addTimeOfDayDescription("midnight", ({
        " eternal under starfield",
        " towering in cosmic presence",
        " sheer in stellar outline",
        " imposing in midnight majesty",
        " vertical in cosmic scale",
        " weathered in stellar time",
        " dangerous in absolute threat",
        " massive in cosmic grandeur",
        " timeless in stellar presence",
        " monumental in midnight"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " ice-covered in harsh conditions",
        " towering in winter storms",
        " sheer with icicle formations",
        " imposing in winter brutality",
        " vertical with dangerous ice",
        " weathered in winter gales",
        " dangerous with winter hazards",
        " massive in winter exposure",
        " forbidding in frozen conditions",
        " treacherous in winter weather"
        }));

    addSeasonDescription("spring", ({
        " stark with spring waterfalls",
        " towering in mild weather",
        " sheer with melting ice",
        " imposing despite spring warmth",
        " vertical with spring runoff",
        " weathered in spring rains",
        " dangerous with unstable conditions",
        " massive in spring clarity",
        " dramatic with cascading water",
        " impressive in spring exposure"
        }));

    addSeasonDescription("summer", ({
        " baked in summer heat",
        " towering in blazing sun",
        " sheer in summer exposure",
        " imposing in heat shimmer",
        " vertical in scorching light",
        " weathered in summer storms",
        " dangerous in heat conditions",
        " massive in summer intensity",
        " harsh in blazing exposure",
        " forbidding in summer heat"
        }));

    addSeasonDescription("autumn", ({
        " stark in autumn clarity",
        " towering in crisp air",
        " sheer in clear weather",
        " imposing in autumn light",
        " vertical in seasonal clarity",
        " weathered in autumn storms",
        " dangerous in clear visibility",
        " massive in autumn grandeur",
        " dramatic in autumn beauty",
        " impressive in seasonal light"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## cliff rising as a sheer "
        "vertical wall of rock");

    addItemTemplate("The cliff rises as a sheer, nearly vertical wall of "
        "exposed rock that presents an imposing barrier to any passage. "
        "Carved by geological forces over millions of years, the cliff face "
        "shows layers of different rock types and the scars of weathering. "
        "Its massive scale dwarfs human perspective, while the vertical "
        "nature makes it dangerous and often impassable without specialized "
        "equipment. Birds of prey may nest on narrow ledges, while hardy "
        "plants find footholds in cracks and crevices. The cliff serves as "
        "both a landmark and a formidable natural barrier.");
}
