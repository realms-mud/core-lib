//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("alp");
    addAdjectives(({ "high", "alpine", "grassy", "pastoral", "elevated",
        "mountain", "seasonal", "windswept" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " bright in early alpine light",
        " high above dawn valleys",
        " alpine in morning clarity",
        " grassy with mountain dew",
        " pastoral in dawn beauty",
        " elevated in first light",
        " mountain-fresh in dawn air",
        " seasonal in morning peace",
        " windswept in dawn breezes",
        " peaceful in alpine dawn"
        }));

    addTimeOfDayDescription("morning", ({
        " clear in mountain air",
        " high in bright visibility",
        " alpine in morning glory",
        " grassy with morning freshness",
        " pastoral in mountain beauty",
        " elevated in clear light",
        " mountain-crisp in morning",
        " seasonal in perfect weather",
        " windswept in mountain breezes",
        " fresh in alpine morning"
        }));

    addTimeOfDayDescription("noon", ({
        " bright in alpine clarity",
        " high in peak illumination",
        " alpine in blazing sun",
        " grassy in mountain abundance",
        " pastoral in noon beauty",
        " elevated in clear exposure",
        " mountain-harsh in peak sun",
        " seasonal in intense light",
        " windswept in noon air",
        " brilliant in alpine sun"
        }));

    addTimeOfDayDescription("afternoon", ({
        " golden in mountain light",
        " high in afternoon clarity",
        " alpine in warm illumination",
        " grassy in afternoon warmth",
        " pastoral in golden beauty",
        " elevated in angled sun",
        " mountain-warm in afternoon",
        " seasonal in perfect conditions",
        " windswept in warm breezes",
        " beautiful in alpine afternoon"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing with alpenglow",
        " high in evening beauty",
        " alpine in sunset colors",
        " grassy in cooling air",
        " pastoral in evening peace",
        " elevated in evening glory",
        " mountain-beautiful in sunset",
        " seasonal in evening perfection",
        " windswept in evening air",
        " magical in alpine evening"
        }));

    addTimeOfDayDescription("dusk", ({
        " peaceful in mountain twilight",
        " high in gathering shadows",
        " alpine in dusk beauty",
        " grassy in evening coolness",
        " pastoral in twilight peace",
        " elevated in fading light",
        " mountain-quiet in dusk",
        " seasonal in twilight beauty",
        " windswept in evening air",
        " serene in alpine dusk"
        }));

    addTimeOfDayDescription("night", ({
        " starlit in mountain air",
        " high under brilliant stars",
        " alpine in night clarity",
        " grassy in night dew",
        " pastoral in night peace",
        " elevated in stellar glow",
        " mountain-clear in night",
        " seasonal in night beauty",
        " windswept in night air",
        " brilliant in alpine night"
        }));

    addTimeOfDayDescription("late night", ({
        " peaceful in mountain night",
        " high in stellar clarity",
        " alpine in deep night",
        " grassy with night moisture",
        " pastoral in night stillness",
        " elevated in night serenity",
        " mountain-quiet in deep night",
        " seasonal in night peace",
        " windswept in night breezes",
        " tranquil in alpine night"
        }));

    addTimeOfDayDescription("midnight", ({
        " cosmic in mountain setting",
        " high under starfield",
        " alpine in stellar beauty",
        " grassy in midnight dew",
        " pastoral in cosmic peace",
        " elevated in stellar presence",
        " mountain-eternal in midnight",
        " seasonal in cosmic time",
        " windswept in cosmic air",
        " pristine in alpine midnight"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " snow-covered in winter beauty",
        " high in winter exposure",
        " alpine in harsh conditions",
        " grassy beneath snow",
        " pastoral despite winter",
        " elevated in winter storms",
        " mountain-harsh in winter",
        " seasonal in winter sleep",
        " windswept in winter gales",
        " stark in winter landscape"
        }));

    addSeasonDescription("spring", ({
        " fresh with alpine spring",
        " high in spring renewal",
        " alpine in mild weather",
        " grassy with new growth",
        " pastoral in spring awakening",
        " elevated in spring beauty",
        " mountain-fresh in spring",
        " seasonal in spring glory",
        " windswept in spring breezes",
        " renewed in alpine spring"
        }));

    addSeasonDescription("summer", ({
        " lush in alpine summer",
        " high in summer perfection",
        " alpine in peak season",
        " grassy in full abundance",
        " pastoral in summer beauty",
        " elevated in summer glory",
        " mountain-perfect in summer",
        " seasonal in peak conditions",
        " windswept in summer air",
        " ideal in alpine summer"
        }));

    addSeasonDescription("autumn", ({
        " colorful in alpine autumn",
        " high in autumn beauty",
        " alpine in seasonal change",
        " grassy in autumn colors",
        " pastoral in autumn peace",
        " elevated in autumn clarity",
        " mountain-crisp in autumn",
        " seasonal in autumn glory",
        " windswept in autumn air",
        " beautiful in alpine autumn"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## alp forming a high mountain "
        "pasture or meadow");

    addItemTemplate("The alp spreads as a high mountain pasture or meadow, "
        "typically found at elevations where trees cannot grow but grasses "
        "and alpine plants thrive during the brief summer season. This "
        "elevated grassland provides seasonal grazing for livestock and "
        "supports specialized alpine flora adapted to harsh mountain "
        "conditions. The alp's beauty lies in its contrast to the rocky "
        "peaks above and forested slopes below, creating a pastoral oasis "
        "in the high mountains. Snow covers the alp for much of the year, "
        "but during the short growing season it bursts into life with "
        "wildflowers and lush grass that has sustained mountain communities "
        "for generations.");
}
