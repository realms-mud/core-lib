//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crag");
    addAdjectives(({ "jagged", "weathered", "steep", "rocky", "harsh",
        "wind-carved", "precipitous", "rugged" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " stark in first light",
        " jagged against dawn sky",
        " weathered in early illumination",
        " steep in morning clarity",
        " rocky in dawn glow",
        " harsh in revealing light",
        " wind-carved in morning air",
        " precipitous in early exposure",
        " rugged in dawn beauty",
        " dramatic in sunrise"
        }));

    addTimeOfDayDescription("morning", ({
        " clearly defined in daylight",
        " jagged in bright visibility",
        " weathered in morning detail",
        " steep in full illumination",
        " rocky in morning sun",
        " harsh in clear exposure",
        " wind-carved in morning clarity",
        " precipitous in bright light",
        " rugged in morning grandeur",
        " imposing in daylight"
        }));

    addTimeOfDayDescription("noon", ({
        " harsh in direct sunlight",
        " jagged in shadowless clarity",
        " weathered in stark exposure",
        " steep in blazing light",
        " rocky in intense heat",
        " precipitous in noon glare",
        " wind-carved in harsh clarity",
        " rugged in peak exposure",
        " forbidding in bright light",
        " stark in noon intensity"
        }));

    addTimeOfDayDescription("afternoon", ({
        " textured in angled light",
        " jagged in shadow patterns",
        " weathered in afternoon glow",
        " steep in declining sun",
        " rocky in warm illumination",
        " harsh in afternoon clarity",
        " wind-carved in golden light",
        " precipitous in angled sun",
        " rugged in afternoon beauty",
        " dramatic in afternoon light"
        }));

    addTimeOfDayDescription("evening", ({
        " dramatic against sunset",
        " jagged in evening silhouette",
        " weathered in alpenglow",
        " steep in golden light",
        " rocky in sunset colors",
        " harsh in evening beauty",
        " wind-carved in sunset glow",
        " precipitous in evening drama",
        " rugged in evening grandeur",
        " imposing against colored sky"
        }));

    addTimeOfDayDescription("dusk", ({
        " mysterious in gathering shadow",
        " jagged in twilight outline",
        " weathered in fading light",
        " steep in dusk mystery",
        " rocky in twilight shadow",
        " harsh in gathering darkness",
        " wind-carved in dusk silhouette",
        " precipitous in twilight",
        " rugged in evening gloom",
        " forbidding in dusk shadow"
        }));

    addTimeOfDayDescription("night", ({
        " stark against starry sky",
        " jagged in moonlit outline",
        " weathered in lunar light",
        " steep in night shadow",
        " rocky in night clarity",
        " harsh in moonlight",
        " wind-carved in stellar glow",
        " precipitous in night danger",
        " rugged in night beauty",
        " imposing under stars"
        }));

    addTimeOfDayDescription("late night", ({
        " mysterious in deep darkness",
        " jagged in felt presence",
        " weathered in night endurance",
        " steep in night peril",
        " rocky in night solidity",
        " harsh in night reality",
        " wind-carved in night mystery",
        " precipitous in night danger",
        " rugged in night majesty",
        " forbidding in deep night"
        }));

    addTimeOfDayDescription("midnight", ({
        " eternal under starfield",
        " jagged in cosmic outline",
        " weathered in stellar time",
        " steep in midnight peril",
        " rocky in cosmic endurance",
        " harsh in stellar reality",
        " wind-carved in cosmic forces",
        " precipitous in midnight danger",
        " rugged in cosmic majesty",
        " timeless in stellar presence"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " ice-covered in harsh conditions",
        " jagged with icicle formations",
        " weathered in winter storms",
        " steep with dangerous ice",
        " rocky in frozen exposure",
        " harsh in winter brutality",
        " wind-carved in winter gales",
        " precipitous with winter hazards",
        " rugged in winter endurance",
        " forbidding in winter conditions"
        }));

    addSeasonDescription("spring", ({
        " stark amid spring growth",
        " jagged despite mild weather",
        " weathered in spring rains",
        " steep with spring runoff",
        " rocky with melting ice",
        " harsh despite spring warmth",
        " wind-carved in spring storms",
        " precipitous with unstable conditions",
        " rugged in spring exposure",
        " imposing in spring clarity"
        }));

    addSeasonDescription("summer", ({
        " baked in summer heat",
        " jagged in blazing clarity",
        " weathered in summer storms",
        " steep in scorching sun",
        " rocky in intense heat",
        " harsh in summer exposure",
        " wind-carved in summer gales",
        " precipitous in heat shimmer",
        " rugged in summer intensity",
        " forbidding in blazing heat"
        }));

    addSeasonDescription("autumn", ({
        " stark in autumn clarity",
        " jagged in crisp air",
        " weathered in autumn storms",
        " steep in clear weather",
        " rocky in autumn light",
        " harsh in seasonal change",
        " wind-carved in autumn gales",
        " precipitous in clear visibility",
        " rugged in autumn beauty",
        " imposing in autumn clarity"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## crag rising as a steep, "
        "rocky outcrop");

    addItemTemplate("The crag rises as a steep, jagged outcrop of exposed "
        "rock that has been carved and shaped by countless years of weathering. "
        "Its harsh, angular profile speaks to the resistant nature of the "
        "stone and the relentless forces that have sculpted its dramatic form. "
        "Wind, rain, frost, and time have created a landscape feature that "
        "is both beautiful and forbidding, with precipitous faces and sharp "
        "edges that challenge any attempt at easy passage. The crag serves "
        "as a stark reminder of the geological forces that shape the land, "
        "standing as a monument to the enduring power of stone against time.");
}
}