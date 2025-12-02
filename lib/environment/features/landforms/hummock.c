//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hummock");
    addAdjectives(({ "small", "grass-covered", "rounded", "marshy", "boggy",
        "isolated", "moss-covered", "wet", "spongy", "mounded" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " wet with morning dew",
        " small in misty dawn light",
        " spongy with overnight moisture",
        " rounded in gentle illumination",
        " grass-covered in dewy freshness",
        " marshy in morning dampness",
        " boggy with accumulated moisture",
        " isolated in morning mist",
        " moss-covered in dawn beauty",
        " mounded in morning peace"
        }));

    addTimeOfDayDescription("morning", ({
        " bright with morning moisture",
        " small in clear daylight",
        " spongy underfoot in warmth",
        " rounded in morning clarity",
        " grass-covered in fresh growth",
        " marshy with morning life",
        " boggy with rich moisture",
        " isolated in morning peace",
        " moss-covered in morning green",
        " mounded in modest beauty"
        }));

    addTimeOfDayDescription("noon", ({
        " warm despite moisture content",
        " small in bright visibility",
        " spongy in midday heat",
        " rounded in clear definition",
        " grass-covered in noon abundance",
        " marshy with midday life",
        " boggy with rich ecosystem",
        " isolated in noon solitude",
        " moss-covered in bright green",
        " mounded in perfect clarity"
        }));

    addTimeOfDayDescription("afternoon", ({
        " golden in angled sunlight",
        " small in afternoon warmth",
        " spongy in warming conditions",
        " rounded in textured light",
        " grass-covered in afternoon glow",
        " marshy with active life",
        " boggy with afternoon richness",
        " isolated in afternoon peace",
        " moss-covered in golden green",
        " mounded in afternoon beauty"
        }));

    addTimeOfDayDescription("evening", ({
        " peaceful in evening moisture",
        " small in gentle evening light",
        " spongy in cooling air",
        " rounded in soft illumination",
        " grass-covered in evening beauty",
        " marshy with evening activity",
        " boggy with evening richness",
        " isolated in evening quiet",
        " moss-covered in evening green",
        " mounded in twilight peace"
        }));

    addTimeOfDayDescription("dusk", ({
        " mysterious in gathering moisture",
        " small in fading light",
        " spongy in evening dampness",
        " rounded in vague outline",
        " grass-covered in twilight shadow",
        " marshy with dusk activity",
        " boggy with evening life",
        " isolated in gathering gloom",
        " moss-covered in twilight mystery",
        " mounded in evening quiet"
        }));

    addTimeOfDayDescription("night", ({
        " wet with night moisture",
        " small in moonlit beauty",
        " spongy with accumulated dew",
        " rounded in lunar outline",
        " grass-covered in night damp",
        " marshy with nocturnal life",
        " boggy with night richness",
        " isolated in night solitude",
        " moss-covered in night mystery",
        " mounded in night peace"
        }));

    addTimeOfDayDescription("late night", ({
        " soaked with late night dew",
        " small in deep night mystery",
        " spongy with maximum moisture",
        " rounded in felt presence",
        " grass-covered in night wetness",
        " marshy with deep night life",
        " boggy with accumulated moisture",
        " isolated in deep solitude",
        " moss-covered in night richness",
        " mounded in deep night peace"
        }));

    addTimeOfDayDescription("midnight", ({
        " saturated with midnight moisture",
        " small in cosmic solitude",
        " spongy with peak wetness",
        " rounded in stellar outline",
        " grass-covered in midnight damp",
        " marshy with midnight life",
        " boggy with cosmic moisture",
        " isolated in absolute solitude",
        " moss-covered in midnight mystery",
        " mounded in cosmic peace"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " frozen but still spongy",
        " small in winter solitude",
        " grass-covered despite cold",
        " rounded in snow outline",
        " marshy even in winter",
        " boggy with winter moisture",
        " isolated in winter peace",
        " moss-covered beneath snow",
        " mounded in winter beauty",
        " wet despite freezing conditions"
        }));

    addSeasonDescription("spring", ({
        " saturated with spring runoff",
        " small in spring abundance",
        " spongy with seasonal moisture",
        " rounded in spring clarity",
        " grass-covered with new growth",
        " marshy with spring life",
        " boggy with seasonal richness",
        " isolated in spring peace",
        " moss-covered in spring green",
        " mounded in spring beauty"
        }));

    addSeasonDescription("summer", ({
        " lush despite summer heat",
        " small in summer abundance",
        " spongy with retained moisture",
        " rounded in summer clarity",
        " grass-covered in peak growth",
        " marshy with summer life",
        " boggy with rich ecosystem",
        " isolated in summer peace",
        " moss-covered in vibrant green",
        " mounded in summer perfection"
        }));

    addSeasonDescription("autumn", ({
        " colorful with autumn grasses",
        " small in autumn beauty",
        " spongy with autumn moisture",
        " rounded in autumn clarity",
        " grass-covered in seasonal change",
        " marshy with autumn activity",
        " boggy with autumn richness",
        " isolated in autumn peace",
        " moss-covered in autumn color",
        " mounded in autumn tranquility"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## hummock forming a small "
        "mounded elevation in wet ground");

    addItemTemplate("The hummock appears as a small, rounded mound rising "
        "from marshy or boggy terrain, typically formed by the accumulation "
        "of organic matter and sediment over time. Its spongy surface yields "
        "underfoot, saturated with moisture that creates ideal conditions for "
        "specialized wetland vegetation. Grasses, sedges, and mosses cover "
        "its surface, while the surrounding wet ground often supports a rich "
        "ecosystem of amphibians, insects, and water-loving plants. The "
        "hummock provides a slightly drier foothold in otherwise waterlogged "
        "terrain, though it remains perpetually moist and soft.");
}
