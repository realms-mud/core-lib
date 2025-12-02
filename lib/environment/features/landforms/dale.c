//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dale");
    addAdjectives(({ "broad", "fertile", "pastoral", "peaceful", "rolling",
        "gentle", "verdant", "open" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " misty with morning fog",
        " peaceful in dawn quiet",
        " fertile in morning dew",
        " broad in gentle illumination",
        " pastoral in dawn beauty",
        " rolling with morning mist",
        " gentle in early light",
        " verdant in morning freshness",
        " open to dawn sky",
        " serene in morning calm"
        }));

    addTimeOfDayDescription("morning", ({
        " bright with morning sun",
        " peaceful in morning calm",
        " fertile in warming light",
        " broad in clear visibility",
        " pastoral in morning beauty",
        " rolling in morning breezes",
        " gentle in strengthening light",
        " verdant in morning growth",
        " open to morning sky",
        " fresh in morning air"
        }));

    addTimeOfDayDescription("noon", ({
        " warm in midday sun",
        " peaceful in noon stillness",
        " fertile in bright light",
        " broad in full visibility",
        " pastoral in midday beauty",
        " rolling in warm air",
        " gentle in bright illumination",
        " verdant in noon abundance",
        " open to blazing sky",
        " abundant in midday warmth"
        }));

    addTimeOfDayDescription("afternoon", ({
        " golden in afternoon light",
        " peaceful in afternoon calm",
        " fertile in warm illumination",
        " broad in textured light",
        " pastoral in afternoon beauty",
        " rolling in warm breezes",
        " gentle in declining sun",
        " verdant in afternoon richness",
        " open to afternoon sky",
        " comfortable in warm air"
        }));

    addTimeOfDayDescription("evening", ({
        " beautiful in evening glow",
        " peaceful in twilight calm",
        " fertile in cooling air",
        " broad in soft illumination",
        " pastoral in evening beauty",
        " rolling in evening breezes",
        " gentle in sunset light",
        " verdant in evening moisture",
        " open to colored sky",
        " serene in evening peace"
        }));

    addTimeOfDayDescription("dusk", ({
        " serene in gathering twilight",
        " peaceful in dusk stillness",
        " fertile in evening damp",
        " broad in fading light",
        " pastoral in twilight beauty",
        " rolling in evening air",
        " gentle in gathering shadow",
        " verdant in evening moisture",
        " open to darkening sky",
        " tranquil in dusk peace"
        }));

    addTimeOfDayDescription("night", ({
        " peaceful in moonlight",
        " broad under starry sky",
        " fertile in night dew",
        " pastoral in night beauty",
        " rolling in night air",
        " gentle in lunar glow",
        " verdant in night moisture",
        " open to night sky",
        " serene in night stillness",
        " quiet in night peace"
        }));

    addTimeOfDayDescription("late night", ({
        " tranquil in deep night",
        " peaceful in night silence",
        " fertile in night damp",
        " broad in night expanse",
        " pastoral in night beauty",
        " rolling in night calm",
        " gentle in night quiet",
        " verdant in night humidity",
        " open to starfield",
        " serene in deep stillness"
        }));

    addTimeOfDayDescription("midnight", ({
        " serene under starfield",
        " peaceful in cosmic quiet",
        " fertile in midnight dew",
        " broad in stellar expanse",
        " pastoral in midnight beauty",
        " rolling in cosmic air",
        " gentle in stellar glow",
        " verdant in midnight moisture",
        " open to cosmos",
        " tranquil in cosmic peace"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " peaceful under snow",
        " broad in winter expanse",
        " fertile beneath frost",
        " pastoral in winter beauty",
        " rolling in winter landscape",
        " gentle in winter quiet",
        " verdant with winter life",
        " open to winter sky",
        " serene in winter stillness",
        " tranquil in winter peace"
        }));

    addSeasonDescription("spring", ({
        " fresh with new growth",
        " peaceful in spring awakening",
        " fertile in spring abundance",
        " broad in spring clarity",
        " pastoral in spring beauty",
        " rolling in spring breezes",
        " gentle in spring warmth",
        " verdant with spring life",
        " open to spring sky",
        " renewed in spring growth"
        }));

    addSeasonDescription("summer", ({
        " lush in summer abundance",
        " peaceful in summer warmth",
        " fertile in peak season",
        " broad in summer expanse",
        " pastoral in summer beauty",
        " rolling in summer breezes",
        " gentle in summer comfort",
        " verdant in full growth",
        " open to summer sky",
        " abundant in summer richness"
        }));

    addSeasonDescription("autumn", ({
        " colorful in autumn beauty",
        " peaceful in autumn calm",
        " fertile in autumn harvest",
        " broad in autumn clarity",
        " pastoral in autumn colors",
        " rolling in autumn breezes",
        " gentle in autumn peace",
        " verdant despite season change",
        " open to autumn sky",
        " serene in autumn tranquility"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## dale forming a broad, "
        "fertile valley");

    addItemTemplate("The dale spreads as a broad, gently rolling valley "
        "that opens between surrounding hills or uplands. This fertile "
        "depression typically supports rich agriculture or lush natural "
        "vegetation, with streams meandering through its lowest areas. "
        "The dale's open character and gentle slopes create an inviting, "
        "pastoral landscape that has often attracted settlement and farming. "
        "Unlike narrower valleys, the dale provides space for extensive "
        "activities while still offering some shelter from the surrounding "
        "higher ground. Its peaceful character makes it ideal for both "
        "human habitation and wildlife.");
}
