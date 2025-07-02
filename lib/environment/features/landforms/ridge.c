//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ridge");
    addAdjectives(({ "exposed", "windswept", "narrow", "elevated", "rocky",
        "spine-like", "continuous", "sharp-crested", "barren", "commanding" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " bright with first light",
        " windswept in morning air",
        " exposed to dawn's glow",
        " elevated above shadowed valleys",
        " commanding in morning clarity",
        " narrow against brightening sky",
        " rocky in early illumination",
        " spine-like in dawn outline",
        " sharp-crested in first rays",
        " continuous in morning light"
        }));

    addTimeOfDayDescription("morning", ({
        " clear in strengthening light",
        " windswept in morning breezes",
        " exposed in full morning sun",
        " elevated in bright visibility",
        " commanding in morning views",
        " narrow in detailed clarity",
        " rocky in morning illumination",
        " spine-like in clear outline",
        " sharp-crested in bright light",
        " continuous in morning exposure"
        }));

    addTimeOfDayDescription("noon", ({
        " harsh in direct sunlight",
        " windswept in peak exposure",
        " exposed in blazing clarity",
        " elevated in noon brightness",
        " commanding in full illumination",
        " narrow in stark definition",
        " rocky in shadowless light",
        " spine-like in harsh clarity",
        " sharp-crested in blazing sun",
        " continuous in peak visibility"
        }));

    addTimeOfDayDescription("afternoon", ({
        " textured in angled light",
        " windswept in afternoon air",
        " exposed in declining sun",
        " elevated in golden illumination",
        " commanding in afternoon views",
        " narrow in shadow patterns",
        " rocky in afternoon glow",
        " spine-like in golden light",
        " sharp-crested in warm sun",
        " continuous in afternoon clarity"
        }));

    addTimeOfDayDescription("evening", ({
        " dramatic against sunset sky",
        " windswept in evening air",
        " exposed in golden light",
        " elevated in evening grandeur",
        " commanding in sunset views",
        " narrow in silhouette",
        " rocky in evening glow",
        " spine-like against colored sky",
        " sharp-crested in alpenglow",
        " continuous in evening beauty"
        }));

    addTimeOfDayDescription("dusk", ({
        " silhouetted against twilight",
        " windswept in cooling air",
        " exposed in fading light",
        " elevated in twilight grandeur",
        " commanding in dusk mystery",
        " narrow in darkening outline",
        " rocky in twilight shadow",
        " spine-like in gathering gloom",
        " sharp-crested in dusk silhouette",
        " continuous in evening shadow"
        }));

    addTimeOfDayDescription("night", ({
        " stark against starry sky",
        " windswept in night air",
        " exposed under stars",
        " elevated in nocturnal grandeur",
        " commanding in night views",
        " narrow in moonlit outline",
        " rocky in lunar light",
        " spine-like in night silhouette",
        " sharp-crested under stars",
        " continuous in night clarity"
        }));

    addTimeOfDayDescription("late night", ({
        " mysterious in deep darkness",
        " windswept in night breezes",
        " exposed to night elements",
        " elevated in night mystery",
        " commanding in felt presence",
        " narrow in unseen outline",
        " rocky in night solidity",
        " spine-like in night form",
        " sharp-crested in darkness",
        " continuous in night presence"
        }));

    addTimeOfDayDescription("midnight", ({
        " eternal under midnight stars",
        " windswept in cosmic air",
        " exposed to stellar influence",
        " elevated in midnight majesty",
        " commanding in night dominion",
        " narrow in stellar outline",
        " rocky in midnight solidity",
        " spine-like in cosmic form",
        " sharp-crested under cosmos",
        " continuous in stellar permanence"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " stark in winter exposure",
        " windswept in harsh conditions",
        " exposed to winter storms",
        " elevated in winter grandeur",
        " commanding in snow clarity",
        " narrow in winter definition",
        " rocky in frozen conditions",
        " spine-like in winter outline",
        " sharp-crested in cold air",
        " continuous in winter endurance"
        }));

    addSeasonDescription("spring", ({
        " fresh in spring breezes",
        " windswept in mild air",
        " exposed to spring weather",
        " elevated in spring clarity",
        " commanding in spring views",
        " narrow in spring definition",
        " rocky with spring runoff",
        " spine-like in spring outline",
        " sharp-crested in clear air",
        " continuous in spring renewal"
        }));

    addSeasonDescription("summer", ({
        " blazing in summer heat",
        " windswept in hot air",
        " exposed to summer sun",
        " elevated in summer haze",
        " commanding in clear weather",
        " narrow in heat shimmer",
        " rocky in blazing light",
        " spine-like in summer outline",
        " sharp-crested in hot sun",
        " continuous in summer exposure"
        }));

    addSeasonDescription("autumn", ({
        " clear in autumn air",
        " windswept in cool breezes",
        " exposed to autumn weather",
        " elevated in crisp clarity",
        " commanding in autumn views",
        " narrow in clear definition",
        " rocky in autumn light",
        " spine-like in autumn outline",
        " sharp-crested in cool air",
        " continuous in autumn beauty"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## ridge forming an elevated "
        "linear feature across the landscape");

    addItemTemplate("The ridge extends as a narrow, elevated landform that "
        "rises above the surrounding terrain like the spine of some geological "
        "beast. Formed by resistant rock layers or tectonic forces, it creates "
        "a continuous barrier that often defines watersheds and travel routes. "
        "The exposed position makes it subject to constant wind and weather, "
        "resulting in sparse vegetation and dramatic views. The ridge crest "
        "may be sharp and knife-like or more rounded depending on the rock "
        "type and weathering, while its slopes often drop steeply into valleys "
        "on either side.");
}
