//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("combe");
    addAdjectives(({ "gently sloping", "lush", "verdant", "small", "rolling",
        "peaceful", "grassy", "sheltered" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " bright over rolling crests",
        " warm with morning dew",
        " peaceful in dawn quiet",
        " gentle in first light",
        " lush with morning moisture",
        " verdant in early glow",
        " small in intimate beauty",
        " rolling in soft illumination",
        " grassy with sparkling dew",
        " sheltered in dawn calm"
        }));

    addTimeOfDayDescription("morning", ({
        " warm with spilling sunlight",
        " bright with morning glow",
        " peaceful in morning calm",
        " gentle in strengthening light",
        " lush in morning warmth",
        " verdant with morning growth",
        " small in perfect beauty",
        " rolling in morning breezes",
        " grassy in fresh abundance",
        " sheltered from morning wind"
        }));

    addTimeOfDayDescription("noon", ({
        " bright in even midday light",
        " rich with green abundance",
        " peaceful in noon stillness",
        " gentle in bright illumination",
        " lush in peak growth",
        " verdant in full sunlight",
        " small in perfect clarity",
        " rolling in warm air",
        " grassy in noon abundance",
        " sheltered in natural basin"
        }));

    addTimeOfDayDescription("afternoon", ({
        " peaceful with softening light",
        " gentle with lengthening shadows",
        " lush in afternoon warmth",
        " verdant in golden light",
        " small in afternoon beauty",
        " rolling in warm breezes",
        " grassy in afternoon glow",
        " sheltered in natural calm",
        " bright with golden hues",
        " serene in declining day"
        }));

    addTimeOfDayDescription("evening", ({
        " golden in last light",
        " peaceful with cooling air",
        " gentle in twilight beauty",
        " lush in evening moisture",
        " verdant in evening glow",
        " small in intimate twilight",
        " rolling in evening shadows",
        " grassy in golden hour",
        " sheltered in evening calm",
        " beautiful in sunset light"
        }));

    addTimeOfDayDescription("dusk", ({
        " soft in twilight darkness",
        " peaceful in evening quiet",
        " gentle in fading light",
        " lush in evening damp",
        " verdant in twilight shadow",
        " small in gathering gloom",
        " rolling in dusk mystery",
        " grassy in evening stillness",
        " sheltered in twilight peace",
        " serene in gathering darkness"
        }));

    addTimeOfDayDescription("night", ({
        " quiet under starry sky",
        " peaceful in night stillness",
        " gentle in lunar glow",
        " lush in night moisture",
        " verdant in night dew",
        " small in night beauty",
        " rolling in night air",
        " grassy in night dampness",
        " sheltered in night peace",
        " serene under stars"
        }));

    addTimeOfDayDescription("late night", ({
        " quiet in deep night peace",
        " peaceful in night stillness",
        " gentle in night calm",
        " lush in night humidity",
        " verdant in deep moisture",
        " small in night serenity",
        " rolling in night silence",
        " grassy with rustling wind",
        " sheltered in deep peace",
        " tranquil in night quiet"
        }));

    addTimeOfDayDescription("midnight", ({
        " dark against star-filled sky",
        " peaceful in cosmic quiet",
        " gentle in stellar glow",
        " lush in midnight dew",
        " verdant in night moisture",
        " small in cosmic beauty",
        " rolling in stellar outline",
        " grassy in midnight dampness",
        " sheltered in cosmic peace",
        " serene in midnight stillness"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " dusted with snow",
        " peaceful in winter quiet",
        " gentle with frost coating",
        " lush beneath snow cover",
        " verdant despite winter",
        " small in winter beauty",
        " rolling in winter landscape",
        " grassy under thin frost",
        " sheltered from winter wind",
        " crisp in winter air"
        }));

    addSeasonDescription("spring", ({
        " fresh with new growth",
        " peaceful in spring awakening",
        " gentle with spring breezes",
        " lush with spring abundance",
        " verdant in spring renewal",
        " small in spring beauty",
        " rolling with spring life",
        " grassy with vibrant growth",
        " sheltered in spring warmth",
        " fragrant with spring blooms"
        }));

    addSeasonDescription("summer", ({
        " lush with summer abundance",
        " peaceful in summer warmth",
        " gentle with warm breezes",
        " verdant in peak growth",
        " small in summer perfection",
        " rolling with summer life",
        " grassy with tall growth",
        " sheltered in summer calm",
        " thick with summer scents",
        " humming with summer insects"
        }));

    addSeasonDescription("autumn", ({
        " golden with autumn grasses",
        " peaceful in autumn beauty",
        " gentle with autumn breezes",
        " lush despite seasonal change",
        " verdant in autumn colors",
        " small in autumn perfection",
        " rolling with autumn hues",
        " grassy in seasonal change",
        " sheltered in autumn calm",
        " crisp with autumn air"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## combe forming a small, "
        "gently sloping valley");

    addItemTemplate("The combe forms a small, sheltered valley with gentle "
        "slopes that create a natural amphitheater of rolling hills. Soft "
        "grasses cover the slopes and floor, while wildflowers often dot "
        "the landscape in scattered patches of color. The combe's intimate "
        "scale and protected nature create ideal conditions for lush growth, "
        "making it a peaceful retreat from more exposed terrain. Streams "
        "may flow through the lowest areas, while the surrounding hills "
        "provide shelter from wind and harsh weather, creating a microclimate "
        "that supports rich vegetation.");
}
