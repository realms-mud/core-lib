//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("basin");
    addAdjectives(({ "circular", "enclosed", "low-lying", "drainage", "natural",
        "wide", "shallow", "protected" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " misty in morning collection",
        " circular in dawn outline",
        " enclosed in morning fog",
        " low-lying with pooled mist",
        " drainage-focused in morning",
        " natural in dawn beauty",
        " wide in gentle illumination",
        " shallow in morning light",
        " protected from dawn wind",
        " peaceful in morning calm"
        }));

    addTimeOfDayDescription("morning", ({
        " clear as mist burns away",
        " circular in bright definition",
        " enclosed in morning warmth",
        " low-lying in full visibility",
        " drainage-evident in morning",
        " natural in morning beauty",
        " wide in morning expanse",
        " shallow in clear light",
        " protected in morning calm",
        " peaceful in morning stillness"
        }));

    addTimeOfDayDescription("noon", ({
        " warm in enclosed depression",
        " circular in peak definition",
        " enclosed in midday heat",
        " low-lying in full exposure",
        " drainage-clear in noon light",
        " natural in bright clarity",
        " wide in noon expanse",
        " shallow in harsh light",
        " protected from noon wind",
        " still in midday calm"
        }));

    addTimeOfDayDescription("afternoon", ({
        " golden in afternoon warmth",
        " circular in textured light",
        " enclosed in afternoon heat",
        " low-lying in declining sun",
        " drainage-apparent in shadows",
        " natural in afternoon beauty",
        " wide in golden light",
        " shallow in warm illumination",
        " protected in afternoon calm",
        " peaceful in declining day"
        }));

    addTimeOfDayDescription("evening", ({
        " beautiful in evening glow",
        " circular in sunset outline",
        " enclosed in cooling air",
        " low-lying in gathering shadow",
        " drainage-collecting evening dew",
        " natural in evening beauty",
        " wide in evening expanse",
        " shallow in soft light",
        " protected from evening wind",
        " serene in evening peace"
        }));

    addTimeOfDayDescription("dusk", ({
        " mysterious in gathering darkness",
        " circular in vague outline",
        " enclosed in twilight shadow",
        " low-lying in pooled darkness",
        " drainage-collecting night moisture",
        " natural in twilight beauty",
        " wide in fading visibility",
        " shallow in gathering gloom",
        " protected in evening stillness",
        " peaceful in dusk quiet"
        }));

    addTimeOfDayDescription("night", ({
        " dark in pooled shadow",
        " circular in felt presence",
        " enclosed in night protection",
        " low-lying in deep darkness",
        " drainage-collecting night dew",
        " natural in night mystery",
        " wide in night expanse",
        " shallow in lunar light",
        " protected from night wind",
        " quiet in night stillness"
        }));

    addTimeOfDayDescription("late night", ({
        " peaceful in deep depression",
        " circular in night outline",
        " enclosed in night security",
        " low-lying in accumulated darkness",
        " drainage-pooling night moisture",
        " natural in night serenity",
        " wide in felt expanse",
        " shallow in night peace",
        " protected in deep stillness",
        " tranquil in night quiet"
        }));

    addTimeOfDayDescription("midnight", ({
        " serene in cosmic depression",
        " circular in stellar outline",
        " enclosed in cosmic protection",
        " low-lying in stellar shadow",
        " drainage-collecting cosmic dew",
        " natural in cosmic beauty",
        " wide in cosmic expanse",
        " shallow in starlight",
        " protected in cosmic stillness",
        " peaceful in midnight quiet"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " snow-filled in winter collection",
        " circular in white outline",
        " enclosed in winter protection",
        " low-lying with snow accumulation",
        " drainage-blocked by winter ice",
        " natural in winter beauty",
        " wide in winter expanse",
        " shallow beneath snow cover",
        " protected from winter wind",
        " peaceful in winter stillness"
        }));

    addSeasonDescription("spring", ({
        " pooled with spring runoff",
        " circular in spring clarity",
        " enclosed in spring renewal",
        " low-lying with water collection",
        " drainage-active in spring",
        " natural in spring beauty",
        " wide in spring expanse",
        " shallow with seasonal water",
        " protected in spring warmth",
        " renewed in spring awakening"
        }));

    addSeasonDescription("summer", ({
        " dry in summer heat",
        " circular in summer clarity",
        " enclosed in summer warmth",
        " low-lying in summer exposure",
        " drainage-evident in dry season",
        " natural in summer beauty",
        " wide in summer expanse",
        " shallow in summer dryness",
        " protected from summer wind",
        " peaceful in summer calm"
        }));

    addSeasonDescription("autumn", ({
        " collecting autumn moisture",
        " circular in autumn clarity",
        " enclosed in autumn protection",
        " low-lying with seasonal gathering",
        " drainage-active in autumn rains",
        " natural in autumn beauty",
        " wide in autumn expanse",
        " shallow with autumn water",
        " protected from autumn wind",
        " peaceful in autumn tranquility"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## basin forming a natural "
        "depression that collects water and sediment");

    addItemTemplate("The basin forms a natural depression in the landscape "
        "where water and sediment collect from the surrounding higher ground. "
        "This enclosed, typically circular or oval feature serves as a "
        "natural drainage point, with streams and surface runoff flowing "
        "toward its lowest areas. During wet seasons, the basin may hold "
        "temporary or permanent water, while in dry periods it reveals the "
        "accumulated sediments that make its soils particularly fertile. "
        "The protected environment often supports vegetation different from "
        "the surrounding terrain, creating a distinct ecosystem within the "
        "larger landscape. The basin's function as a collection point makes "
        "it valuable for both wildlife and human activities.");
}
