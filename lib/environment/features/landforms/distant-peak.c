//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("distant peak");
    addAdjectives(({ "snow-capped", "hazy", "remote", "towering", "majestic",
        "blue-tinged", "ethereal", "far-off" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " glowing with first alpenglow",
        " bright while valleys sleep",
        " ethereal in morning mist",
        " remote in dawn clarity",
        " towering above morning fog",
        " majestic in sunrise colors",
        " hazy in morning atmosphere",
        " snow-capped in golden light",
        " blue-tinged in distance",
        " far-off in dawn beauty"
        }));

    addTimeOfDayDescription("morning", ({
        " clear in morning air",
        " towering in bright visibility",
        " remote in morning clarity",
        " majestic in full sunlight",
        " ethereal in mountain air",
        " hazy with atmospheric layers",
        " snow-capped in bright white",
        " blue-tinged with distance",
        " far-off but clearly visible",
        " inspiring in morning light"
        }));

    addTimeOfDayDescription("noon", ({
        " stark in harsh clarity",
        " towering in overwhelming scale",
        " remote in blazing distance",
        " majestic in noon grandeur",
        " ethereal in heat shimmer",
        " hazy in midday atmosphere",
        " snow-capped in brilliant white",
        " blue-tinged in noon haze",
        " far-off in crystal clarity",
        " imposing in peak visibility"
        }));

    addTimeOfDayDescription("afternoon", ({
        " dramatic in angled light",
        " towering in afternoon haze",
        " remote in golden distance",
        " majestic in afternoon glow",
        " ethereal in mountain air",
        " hazy in warming atmosphere",
        " snow-capped in afternoon sun",
        " blue-tinged in distance",
        " far-off in golden light",
        " beautiful in declining day"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing with alpenglow",
        " towering in sunset beauty",
        " remote in evening distance",
        " majestic in sunset colors",
        " ethereal in evening light",
        " hazy in evening atmosphere",
        " snow-capped in pink alpenglow",
        " blue-tinged in twilight",
        " far-off in evening glory",
        " inspiring in sunset grandeur"
        }));

    addTimeOfDayDescription("dusk", ({
        " silhouetted against twilight",
        " towering in dusk mystery",
        " remote in gathering darkness",
        " majestic in twilight grandeur",
        " ethereal in fading light",
        " hazy in evening mist",
        " snow-capped in twilight glow",
        " blue-tinged in dusk shadow",
        " far-off in gathering gloom",
        " mysterious in twilight beauty"
        }));

    addTimeOfDayDescription("night", ({
        " dark against starry sky",
        " towering in night mystery",
        " remote in stellar distance",
        " majestic under stars",
        " ethereal in moonlight",
        " hazy in night atmosphere",
        " snow-capped in lunar glow",
        " blue-tinged in night shadow",
        " far-off in night darkness",
        " impressive in night presence"
        }));

    addTimeOfDayDescription("late night", ({
        " felt more than seen",
        " towering in night presence",
        " remote in cosmic distance",
        " majestic in felt grandeur",
        " ethereal in night mystery",
        " hazy in deep night",
        " snow-capped in starlight",
        " blue-tinged in darkness",
        " far-off in night void",
        " mysterious in night presence"
        }));

    addTimeOfDayDescription("midnight", ({
        " eternal under starfield",
        " towering in cosmic presence",
        " remote in stellar space",
        " majestic in midnight grandeur",
        " ethereal in cosmic light",
        " hazy in midnight atmosphere",
        " snow-capped under cosmos",
        " blue-tinged in starlight",
        " far-off in cosmic distance",
        " timeless in midnight sky"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " bright with snow cover",
        " towering in winter clarity",
        " remote in crisp air",
        " majestic in winter grandeur",
        " ethereal in winter light",
        " hazy despite clear air",
        " snow-capped in winter white",
        " blue-tinged in cold distance",
        " far-off in winter beauty",
        " stark in winter exposure"
        }));

    addSeasonDescription("spring", ({
        " clear in spring air",
        " towering in mild weather",
        " remote in spring distance",
        " majestic in spring clarity",
        " ethereal in spring light",
        " hazy in spring atmosphere",
        " snow-capped despite season",
        " blue-tinged in spring sky",
        " far-off in spring beauty",
        " inspiring in spring clarity"
        }));

    addSeasonDescription("summer", ({
        " hazy in summer heat",
        " towering through heat shimmer",
        " remote in summer distance",
        " majestic despite heat haze",
        " ethereal in summer air",
        " blue-tinged in summer haze",
        " snow-capped even in summer",
        " far-off in summer atmosphere",
        " impressive in summer visibility",
        " beautiful in summer light"
        }));

    addSeasonDescription("autumn", ({
        " clear in autumn air",
        " towering in crisp weather",
        " remote in autumn distance",
        " majestic in autumn clarity",
        " ethereal in autumn light",
        " hazy in autumn atmosphere",
        " snow-capped in autumn white",
        " blue-tinged in clear air",
        " far-off in autumn beauty",
        " inspiring in autumn clarity"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## distant peak visible on the "
        "far horizon");

    addItemTemplate("The distant peak rises far beyond the immediate landscape, "
        "visible as a remote landmark that dominates the horizon. Its great "
        "distance renders details indistinct, creating an ethereal quality "
        "enhanced by atmospheric haze and the blue tinge of intervening air. "
        "The peak serves as a constant reference point, its snow-capped summit "
        "catching light differently than the surrounding terrain. Weather "
        "patterns around the distant mountain create changing moods, from "
        "crystal clarity to mysterious obscurity, while its immense scale "
        "provides perspective on the vastness of the landscape.");
}
