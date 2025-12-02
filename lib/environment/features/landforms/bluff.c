//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bluff");
    addAdjectives(({ "steep", "high", "rocky", "commanding", "exposed",
        "windswept", "elevated", "dramatic" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " bright in first light",
        " steep in morning clarity",
        " high above dawn valleys",
        " rocky in early illumination",
        " commanding in sunrise views",
        " exposed to dawn wind",
        " windswept in morning air",
        " elevated in dawn beauty",
        " dramatic against dawn sky",
        " impressive in early light"
        }));

    addTimeOfDayDescription("morning", ({
        " clear in morning visibility",
        " steep in bright daylight",
        " high in full illumination",
        " rocky in morning detail",
        " commanding in morning views",
        " exposed in morning clarity",
        " windswept in morning breezes",
        " elevated in bright light",
        " dramatic in morning grandeur",
        " imposing in daylight"
        }));

    addTimeOfDayDescription("noon", ({
        " harsh in direct sunlight",
        " steep in blazing clarity",
        " high in overwhelming exposure",
        " rocky in stark detail",
        " commanding in peak views",
        " exposed in intense light",
        " windswept in noon air",
        " elevated in blazing sun",
        " dramatic in noon intensity",
        " imposing in harsh light"
        }));

    addTimeOfDayDescription("afternoon", ({
        " textured in angled light",
        " steep with shadow patterns",
        " high in afternoon glow",
        " rocky in warm illumination",
        " commanding in afternoon views",
        " exposed in declining sun",
        " windswept in warm air",
        " elevated in golden light",
        " dramatic in afternoon beauty",
        " striking in angled sun"
        }));

    addTimeOfDayDescription("evening", ({
        " beautiful in sunset glow",
        " steep in evening drama",
        " high in alpenglow",
        " rocky in golden light",
        " commanding in sunset views",
        " exposed in evening beauty",
        " windswept in cooling air",
        " elevated in evening glory",
        " dramatic in sunset colors",
        " magnificent in evening light"
        }));

    addTimeOfDayDescription("dusk", ({
        " mysterious in gathering shadow",
        " steep in twilight outline",
        " high in fading light",
        " rocky in dusk mystery",
        " commanding in twilight views",
        " exposed in gathering gloom",
        " windswept in evening air",
        " elevated in dusk beauty",
        " dramatic in twilight",
        " impressive in fading light"
        }));

    addTimeOfDayDescription("night", ({
        " stark under starry sky",
        " steep in night outline",
        " high in lunar light",
        " rocky in moonlit shadow",
        " commanding in night views",
        " exposed under stars",
        " windswept in night air",
        " elevated in night beauty",
        " dramatic in stellar glow",
        " imposing under night sky"
        }));

    addTimeOfDayDescription("late night", ({
        " mysterious in deep darkness",
        " steep in night presence",
        " high in felt elevation",
        " rocky in night solidity",
        " commanding in night dominance",
        " exposed to night elements",
        " windswept in night breezes",
        " elevated in night mystery",
        " dramatic in deep night",
        " impressive in night presence"
        }));

    addTimeOfDayDescription("midnight", ({
        " eternal under starfield",
        " steep in cosmic outline",
        " high in stellar elevation",
        " rocky in midnight solidity",
        " commanding in cosmic views",
        " exposed to stellar influence",
        " windswept in cosmic air",
        " elevated in stellar presence",
        " dramatic in cosmic beauty",
        " timeless in midnight grandeur"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " stark in winter exposure",
        " steep with ice formation",
        " high in winter storms",
        " rocky in frozen conditions",
        " commanding in winter clarity",
        " exposed to winter winds",
        " windswept in harsh weather",
        " elevated in winter beauty",
        " dramatic in winter conditions",
        " imposing in winter landscape"
        }));

    addSeasonDescription("spring", ({
        " fresh in spring weather",
        " steep with spring runoff",
        " high in spring clarity",
        " rocky with melting conditions",
        " commanding in spring views",
        " exposed to spring storms",
        " windswept in mild breezes",
        " elevated in spring beauty",
        " dramatic in spring renewal",
        " impressive in spring weather"
        }));

    addSeasonDescription("summer", ({
        " blazing in summer heat",
        " steep in scorching sun",
        " high in summer haze",
        " rocky in intense heat",
        " commanding in summer views",
        " exposed to blazing sun",
        " windswept in hot air",
        " elevated in summer intensity",
        " dramatic in heat shimmer",
        " imposing in summer exposure"
        }));

    addSeasonDescription("autumn", ({
        " clear in autumn air",
        " steep in crisp weather",
        " high in autumn clarity",
        " rocky in seasonal light",
        " commanding in autumn views",
        " exposed to autumn winds",
        " windswept in cool breezes",
        " elevated in autumn beauty",
        " dramatic in autumn clarity",
        " impressive in seasonal weather"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## bluff rising as a steep, "
        "high bank or cliff");

    addItemTemplate("The bluff rises as a steep, elevated bank that creates "
        "a commanding position above the surrounding terrain. Its high vantage "
        "point provides excellent views of the landscape below, while the "
        "steep face presents a natural barrier that protects the elevated "
        "ground behind it. The bluff's exposed position subjects it to "
        "constant wind and weather, creating harsh conditions that support "
        "only hardy vegetation. Erosion continuously shapes its face, while "
        "the elevated position makes it valuable for observation, defense, "
        "or simply enjoying panoramic views of the surrounding countryside.");
}
