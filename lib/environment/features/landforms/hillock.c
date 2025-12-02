//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hillock");
    addAdjectives(({ "small", "rounded", "grassy", "gentle", "modest",
        "peaceful", "rolling", "low" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " bright with first light",
        " gentle in dawn glow",
        " rounded in early illumination",
        " grassy with morning dew",
        " small in modest beauty",
        " peaceful in dawn quiet",
        " rolling in soft light",
        " low in morning mist",
        " modest in gentle brightness",
        " quiet in dawn stillness"
        }));

    addTimeOfDayDescription("morning", ({
        " clear in morning sunshine",
        " gentle in warming light",
        " rounded in bright visibility",
        " grassy in morning freshness",
        " small in perfect proportion",
        " peaceful in morning calm",
        " rolling in morning breezes",
        " low in pleasant exposure",
        " modest in morning charm",
        " quiet in morning peace"
        }));

    addTimeOfDayDescription("noon", ({
        " warm in midday sun",
        " gentle in bright light",
        " rounded in full visibility",
        " grassy in noon abundance",
        " small in clear definition",
        " peaceful in midday stillness",
        " rolling in warm air",
        " low in comfortable heat",
        " modest in bright beauty",
        " quiet in noon calm"
        }));

    addTimeOfDayDescription("afternoon", ({
        " golden in afternoon light",
        " gentle in warm illumination",
        " rounded in textured shadow",
        " grassy in afternoon warmth",
        " small in perfect beauty",
        " peaceful in afternoon calm",
        " rolling in warm breezes",
        " low in pleasant warmth",
        " modest in golden charm",
        " quiet in afternoon peace"
        }));

    addTimeOfDayDescription("evening", ({
        " beautiful in evening glow",
        " gentle in sunset light",
        " rounded in soft illumination",
        " grassy in cooling air",
        " small in evening beauty",
        " peaceful in evening calm",
        " rolling in evening breezes",
        " low in gentle light",
        " modest in evening charm",
        " quiet in twilight peace"
        }));

    addTimeOfDayDescription("dusk", ({
        " serene in gathering twilight",
        " gentle in fading light",
        " rounded in soft outline",
        " grassy in evening shadow",
        " small in twilight beauty",
        " peaceful in dusk stillness",
        " rolling in evening air",
        " low in gentle shadow",
        " modest in fading charm",
        " quiet in gathering gloom"
        }));

    addTimeOfDayDescription("night", ({
        " peaceful in moonlight",
        " gentle under stars",
        " rounded in lunar glow",
        " grassy in night dew",
        " small in night beauty",
        " quiet in night stillness",
        " rolling in night air",
        " low in gentle darkness",
        " modest in lunar charm",
        " serene in night peace"
        }));

    addTimeOfDayDescription("late night", ({
        " tranquil in deep night",
        " gentle in night silence",
        " rounded in felt presence",
        " grassy in night moisture",
        " small in night serenity",
        " peaceful in deep stillness",
        " rolling in night calm",
        " low in night quiet",
        " modest in night beauty",
        " quiet in deep tranquility"
        }));

    addTimeOfDayDescription("midnight", ({
        " serene under starfield",
        " gentle in cosmic peace",
        " rounded in stellar outline",
        " grassy in midnight dew",
        " small in cosmic beauty",
        " peaceful in absolute stillness",
        " rolling in cosmic air",
        " low in stellar glow",
        " modest in midnight charm",
        " quiet in cosmic tranquility"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " peaceful under snow",
        " gentle in winter beauty",
        " rounded in white outline",
        " grassy beneath snow cover",
        " small in winter charm",
        " quiet in winter stillness",
        " rolling in winter landscape",
        " low in snow-covered peace",
        " modest in winter beauty",
        " serene in winter quiet"
        }));

    addSeasonDescription("spring", ({
        " fresh with new growth",
        " gentle in spring awakening",
        " rounded in spring clarity",
        " grassy with spring green",
        " small in spring beauty",
        " peaceful in spring renewal",
        " rolling in spring breezes",
        " low in spring freshness",
        " modest in spring charm",
        " quiet in spring peace"
        }));

    addSeasonDescription("summer", ({
        " lush in summer growth",
        " gentle in summer warmth",
        " rounded in summer clarity",
        " grassy in full abundance",
        " small in summer perfection",
        " peaceful in summer calm",
        " rolling in summer breezes",
        " low in summer comfort",
        " modest in summer beauty",
        " quiet in summer stillness"
        }));

    addSeasonDescription("autumn", ({
        " colorful in autumn grass",
        " gentle in autumn peace",
        " rounded in autumn clarity",
        " grassy in seasonal change",
        " small in autumn beauty",
        " peaceful in autumn calm",
        " rolling in autumn breezes",
        " low in autumn comfort",
        " modest in autumn charm",
        " quiet in autumn tranquility"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## hillock rising as a small "
        "rounded elevation");

    addItemTemplate("The hillock forms a small, gently rounded elevation "
        "that rises modestly from the surrounding landscape. Its low profile "
        "and gentle slopes make it easily accessible, while its grassy surface "
        "provides a comfortable place to rest or gain a slightly elevated "
        "view. The hillock's modest size means it integrates naturally with "
        "the terrain rather than dominating it, often serving as a pleasant "
        "focal point in rolling countryside. Its rounded form speaks to long "
        "weathering that has softened any sharp edges into gentle curves.");
}
