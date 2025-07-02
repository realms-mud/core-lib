//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mound");
    addAdjectives(({ "grassy", "artificial", "ancient", "burial", "earthen",
        "rounded", "mysterious", "low", "ceremonial", "overgrown" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " peaceful in morning light",
        " ancient in dawn's glow",
        " mysterious in early mist",
        " grassy with morning dew",
        " rounded in gentle illumination",
        " ceremonial in dawn quiet",
        " artificial in revealing light",
        " burial-quiet in morning peace",
        " earthen in morning warmth",
        " overgrown in dawn beauty"
        }));

    addTimeOfDayDescription("morning", ({
        " clearly artificial in daylight",
        " ancient in morning clarity",
        " mysterious despite bright light",
        " grassy in morning sunshine",
        " rounded in full visibility",
        " ceremonial in morning peace",
        " burial-significant in light",
        " earthen in morning warmth",
        " overgrown with morning life",
        " peaceful in morning calm"
        }));

    addTimeOfDayDescription("noon", ({
        " obviously artificial in harsh light",
        " ancient in blazing clarity",
        " mysterious in full exposure",
        " grassy in bright sunshine",
        " rounded in complete visibility",
        " ceremonial in noon stillness",
        " burial-sacred in bright light",
        " earthen in peak warmth",
        " overgrown in summer abundance",
        " peaceful in midday quiet"
        }));

    addTimeOfDayDescription("afternoon", ({
        " clearly defined in angled light",
        " ancient in afternoon glow",
        " mysterious in golden light",
        " grassy in warm sunshine",
        " rounded in textured light",
        " ceremonial in afternoon peace",
        " burial-reverent in golden hour",
        " earthen in afternoon warmth",
        " overgrown in abundant life",
        " peaceful in declining day"
        }));

    addTimeOfDayDescription("evening", ({
        " mysterious in evening shadows",
        " ancient in alpenglow",
        " ceremonial in evening peace",
        " grassy in cooling air",
        " rounded in gentle light",
        " burial-solemn in sunset",
        " artificial in evening clarity",
        " earthen in evening coolness",
        " overgrown in evening beauty",
        " peaceful in twilight calm"
        }));

    addTimeOfDayDescription("dusk", ({
        " mysterious in gathering darkness",
        " ancient in twilight mystery",
        " ceremonial in dusk solemnity",
        " grassy in evening shadow",
        " rounded in vague outline",
        " burial-sacred in twilight",
        " artificial in fading light",
        " earthen in cooling air",
        " overgrown in gathering gloom",
        " peaceful in evening quiet"
        }));

    addTimeOfDayDescription("night", ({
        " mysterious in moonlight",
        " ancient under stars",
        " ceremonial in night solemnity",
        " grassy in lunar glow",
        " rounded in night outline",
        " burial-sacred under night sky",
        " artificial in night clarity",
        " earthen in night coolness",
        " overgrown in night mystery",
        " peaceful in night stillness"
        }));

    addTimeOfDayDescription("late night", ({
        " mysterious in deep night",
        " ancient in night eternity",
        " ceremonial in late night solemnity",
        " grassy in night dew",
        " rounded in felt presence",
        " burial-sacred in deep night",
        " artificial in night reality",
        " earthen in night coolness",
        " overgrown in night growth",
        " peaceful in deep stillness"
        }));

    addTimeOfDayDescription("midnight", ({
        " mysterious in cosmic presence",
        " ancient under starfield",
        " ceremonial in midnight solemnity",
        " grassy in night moisture",
        " rounded in stellar outline",
        " burial-sacred under cosmos",
        " artificial in midnight reality",
        " earthen in cosmic coolness",
        " overgrown in midnight mystery",
        " peaceful in absolute stillness"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " stark under snow cover",
        " ancient in winter endurance",
        " mysterious in winter quiet",
        " grassy beneath snow",
        " rounded in winter outline",
        " ceremonial in winter solemnity",
        " burial-preserved in winter",
        " artificial in winter clarity",
        " earthen in frozen ground",
        " overgrown despite winter"
        }));

    addSeasonDescription("spring", ({
        " renewed with spring growth",
        " ancient in spring awakening",
        " mysterious in spring renewal",
        " grassy with new green",
        " rounded in spring clarity",
        " ceremonial in spring peace",
        " burial-honored in spring",
        " artificial in spring revelation",
        " earthen in spring warmth",
        " overgrown with spring life"
        }));

    addSeasonDescription("summer", ({
        " lush with summer growth",
        " ancient in summer abundance",
        " mysterious despite bright season",
        " grassy in full growth",
        " rounded in summer clarity",
        " ceremonial in summer peace",
        " burial-hidden in growth",
        " artificial in summer exposure",
        " earthen in summer warmth",
        " overgrown in peak season"
        }));

    addSeasonDescription("autumn", ({
        " colorful with autumn grass",
        " ancient in autumn beauty",
        " mysterious in autumn peace",
        " grassy in seasonal change",
        " rounded in autumn clarity",
        " ceremonial in autumn solemnity",
        " burial-reverent in autumn",
        " artificial in autumn exposure",
        " earthen in autumn coolness",
        " overgrown with autumn color"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## mound rising "
         "from the surrounding terrain");

    addItemTemplate("The mound appears as a deliberately constructed hill, "
        "clearly artificial in its regular shape and placement. Built from "
        "earth and stone piled and shaped by human hands, it likely serves "
        "or served a ceremonial, burial, or defensive purpose. The rounded "
        "profile has been softened by time and weather, while grasses and "
        "other vegetation have colonized its surface. Its strategic placement "
        "and construction suggest significant cultural importance to those "
        "who built it, whether as a burial site, ceremonial center, or "
        "marker of territorial significance.");
}
