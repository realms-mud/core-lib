//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("promontory");
    addAdjectives(({ "jutting", "prominent", "elevated", "strategic", "commanding",
        "windswept", "exposed", "rocky", "isolated", "dramatic" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " prominent in first light",
        " commanding in dawn glow",
        " jutting into morning sky",
        " elevated in early brightness",
        " strategic in dawn clarity",
        " windswept in morning air",
        " exposed to first rays",
        " rocky in morning illumination",
        " isolated in dawn grandeur",
        " dramatic in sunrise beauty"
        }));

    addTimeOfDayDescription("morning", ({
        " commanding in morning views",
        " prominent in clear light",
        " jutting in bright visibility",
        " elevated in morning clarity",
        " strategic in daylight advantage",
        " windswept in morning breezes",
        " exposed in full illumination",
        " rocky in morning detail",
        " isolated in bright exposure",
        " dramatic in morning grandeur"
        }));

    addTimeOfDayDescription("noon", ({
        " commanding in peak visibility",
        " prominent in harsh clarity",
        " jutting in shadowless light",
        " elevated in noon brightness",
        " strategic in full advantage",
        " windswept in peak exposure",
        " exposed in blazing sun",
        " rocky in stark detail",
        " isolated in noon solitude",
        " dramatic in intense light"
        }));

    addTimeOfDayDescription("afternoon", ({
        " commanding in golden views",
        " prominent in angled light",
        " jutting in afternoon glow",
        " elevated in warm illumination",
        " strategic in afternoon advantage",
        " windswept in warm air",
        " exposed in declining sun",
        " rocky in textured light",
        " isolated in afternoon peace",
        " dramatic in golden beauty"
        }));

    addTimeOfDayDescription("evening", ({
        " commanding in sunset views",
        " prominent against colored sky",
        " jutting in evening grandeur",
        " elevated in alpenglow",
        " strategic in evening position",
        " windswept in cooling air",
        " exposed in golden light",
        " rocky in evening glow",
        " isolated in sunset beauty",
        " dramatic in evening majesty"
        }));

    addTimeOfDayDescription("dusk", ({
        " commanding in twilight views",
        " prominent in silhouette",
        " jutting into darkening sky",
        " elevated in dusk mystery",
        " strategic in twilight position",
        " windswept in evening air",
        " exposed in fading light",
        " rocky in twilight shadow",
        " isolated in gathering gloom",
        " dramatic in dusk silhouette"
        }));

    addTimeOfDayDescription("night", ({
        " commanding in night views",
        " prominent under stars",
        " jutting into starry sky",
        " elevated in nocturnal grandeur",
        " strategic in night position",
        " windswept in night air",
        " exposed under moonlight",
        " rocky in lunar glow",
        " isolated in night solitude",
        " dramatic in stellar beauty"
        }));

    addTimeOfDayDescription("late night", ({
        " commanding in felt presence",
        " prominent in night mystery",
        " jutting into deep darkness",
        " elevated in night majesty",
        " strategic in unseen advantage",
        " windswept in night breezes",
        " exposed to night elements",
        " rocky in night solidity",
        " isolated in deep solitude",
        " dramatic in night mystery"
        }));

    addTimeOfDayDescription("midnight", ({
        " commanding in cosmic views",
        " prominent under starfield",
        " jutting into cosmic space",
        " elevated in stellar majesty",
        " strategic in midnight position",
        " windswept in cosmic air",
        " exposed to stellar influence",
        " rocky in midnight solidity",
        " isolated in cosmic solitude",
        " dramatic in stellar grandeur"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " commanding in winter grandeur",
        " prominent in snow clarity",
        " jutting through winter storms",
        " elevated in cold majesty",
        " strategic in winter advantage",
        " windswept in harsh conditions",
        " exposed to winter elements",
        " rocky in frozen conditions",
        " isolated in winter solitude",
        " dramatic in winter beauty"
        }));

    addSeasonDescription("spring", ({
        " commanding in spring clarity",
        " prominent in mild weather",
        " jutting into spring sky",
        " elevated in spring freshness",
        " strategic in spring advantage",
        " windswept in gentle breezes",
        " exposed to spring elements",
        " rocky with spring runoff",
        " isolated in spring peace",
        " dramatic in spring renewal"
        }));

    addSeasonDescription("summer", ({
        " commanding in summer heat",
        " prominent in blazing clarity",
        " jutting into summer sky",
        " elevated in heat shimmer",
        " strategic in summer advantage",
        " windswept in hot air",
        " exposed to blazing sun",
        " rocky in intense heat",
        " isolated in summer solitude",
        " dramatic in summer grandeur"
        }));

    addSeasonDescription("autumn", ({
        " commanding in autumn clarity",
        " prominent in crisp air",
        " jutting into autumn sky",
        " elevated in clear weather",
        " strategic in autumn advantage",
        " windswept in cool breezes",
        " exposed to autumn elements",
        " rocky in autumn light",
        " isolated in autumn peace",
        " dramatic in autumn beauty"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## promontory jutting out from "
        "the surrounding landscape");

    addItemTemplate("The promontory extends outward from the main body of "
        "land, creating a prominent elevated feature that commands excellent "
        "views of the surrounding area. This natural observation point rises "
        "significantly above adjacent terrain, often formed by resistant rock "
        "that has weathered more slowly than surrounding materials. The exposed "
        "position subjects it to constant wind and weather, while its strategic "
        "location has likely made it significant for navigation, defense, or "
        "observation throughout history. The steep sides and elevated position "
        "create a natural fortress-like quality that dominates the landscape.");
}
