//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("butte");
    addAdjectives(({ "isolated", "flat-topped", "steep-sided", "towering",
        "erosion-carved", "mesa-like", "weathered", "commanding" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " isolated in morning mist",
        " flat-topped in dawn clarity",
        " steep-sided in early light",
        " towering above dawn fog",
        " erosion-carved in first light",
        " mesa-like in morning glow",
        " weathered in dawn illumination",
        " commanding in sunrise",
        " dramatic against dawn sky",
        " imposing in early light"
        }));

    addTimeOfDayDescription("morning", ({
        " isolated in clear visibility",
        " flat-topped in bright clarity",
        " steep-sided in morning sun",
        " towering in full illumination",
        " erosion-carved in detailed light",
        " mesa-like in morning beauty",
        " weathered in clear exposure",
        " commanding in morning views",
        " impressive in daylight",
        " striking in morning clarity"
        }));

    addTimeOfDayDescription("noon", ({
        " isolated in harsh exposure",
        " flat-topped in blazing clarity",
        " steep-sided in intense light",
        " towering in overwhelming scale",
        " erosion-carved in stark detail",
        " mesa-like in noon grandeur",
        " weathered in harsh illumination",
        " commanding in peak visibility",
        " imposing in noon intensity",
        " dramatic in blazing sun"
        }));

    addTimeOfDayDescription("afternoon", ({
        " isolated in golden light",
        " flat-topped in warm illumination",
        " steep-sided with shadow patterns",
        " towering in afternoon glow",
        " erosion-carved in textured light",
        " mesa-like in afternoon beauty",
        " weathered in golden hour",
        " commanding in declining day",
        " beautiful in angled light",
        " striking in afternoon sun"
        }));

    addTimeOfDayDescription("evening", ({
        " isolated in sunset glory",
        " flat-topped in alpenglow",
        " steep-sided in evening drama",
        " towering in sunset beauty",
        " erosion-carved in golden light",
        " mesa-like in evening grandeur",
        " weathered in sunset colors",
        " commanding in evening views",
        " spectacular in sunset",
        " magnificent in evening light"
        }));

    addTimeOfDayDescription("dusk", ({
        " isolated in gathering twilight",
        " flat-topped in dusk outline",
        " steep-sided in fading light",
        " towering in twilight mystery",
        " erosion-carved in dusk shadow",
        " mesa-like in twilight beauty",
        " weathered in gathering gloom",
        " commanding in dusk presence",
        " mysterious in twilight",
        " impressive in fading light"
        }));

    addTimeOfDayDescription("night", ({
        " isolated under starry sky",
        " flat-topped in lunar outline",
        " steep-sided in night shadow",
        " towering in night grandeur",
        " erosion-carved in moonlight",
        " mesa-like in stellar glow",
        " weathered in night mystery",
        " commanding in night presence",
        " imposing under stars",
        " dramatic in night beauty"
        }));

    addTimeOfDayDescription("late night", ({
        " isolated in deep night",
        " flat-topped in night outline",
        " steep-sided in night mystery",
        " towering in felt presence",
        " erosion-carved in time",
        " mesa-like in night majesty",
        " weathered in night endurance",
        " commanding in deep darkness",
        " impressive in night presence",
        " mysterious in deep night"
        }));

    addTimeOfDayDescription("midnight", ({
        " isolated under starfield",
        " flat-topped in cosmic outline",
        " steep-sided in stellar shadow",
        " towering in cosmic presence",
        " erosion-carved in geological time",
        " mesa-like in stellar majesty",
        " weathered in cosmic endurance",
        " commanding in midnight presence",
        " eternal under cosmos",
        " timeless in stellar glow"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " isolated in winter landscape",
        " flat-topped with snow cover",
        " steep-sided with ice formation",
        " towering in winter storms",
        " erosion-carved in harsh weather",
        " mesa-like in winter beauty",
        " weathered in winter conditions",
        " commanding in winter clarity",
        " stark in winter exposure",
        " impressive in winter grandeur"
        }));

    addSeasonDescription("spring", ({
        " isolated in spring clarity",
        " flat-topped in mild weather",
        " steep-sided with spring runoff",
        " towering in spring beauty",
        " erosion-carved in spring rains",
        " mesa-like in spring renewal",
        " weathered in spring conditions",
        " commanding in spring views",
        " dramatic in spring weather",
        " impressive in spring clarity"
        }));

    addSeasonDescription("summer", ({
        " isolated in blazing heat",
        " flat-topped in summer haze",
        " steep-sided in scorching sun",
        " towering in heat shimmer",
        " erosion-carved in harsh conditions",
        " mesa-like in summer intensity",
        " weathered in summer storms",
        " commanding in summer visibility",
        " imposing in summer heat",
        " dramatic in blazing exposure"
        }));

    addSeasonDescription("autumn", ({
        " isolated in autumn clarity",
        " flat-topped in crisp air",
        " steep-sided in clear weather",
        " towering in autumn beauty",
        " erosion-carved in seasonal light",
        " mesa-like in autumn grandeur",
        " weathered in autumn conditions",
        " commanding in autumn views",
        " striking in autumn clarity",
        " impressive in seasonal beauty"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## butte rising as an isolated, "
        "flat-topped hill with steep sides");

    addItemTemplate("The butte stands as an isolated, flat-topped hill that "
        "rises dramatically from the surrounding plains or lowlands. Its "
        "distinctive shape results from erosion that has carved away softer "
        "surrounding rock while leaving the more resistant caprock intact. "
        "The steep sides make access to the flat summit challenging, while "
        "the elevated position provides commanding views of the surrounding "
        "landscape. The butte serves as a prominent landmark visible from "
        "great distances, its distinctive silhouette marking its location "
        "across vast stretches of terrain. Hardy vegetation may cling to "
        "cracks in the rock face, while the summit often supports different "
        "plant communities than the surrounding lowlands.");
}
