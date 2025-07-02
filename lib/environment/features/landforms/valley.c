//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("valley");
    addAdjectives(({ "wide", "fertile", "sweeping", "vast", "deep", "sheltered",
        "verdant", "majestic", "river-carved", "glacial" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " pooled with morning mist",
        " emerging from cool twilight",
        " touched first on eastern ridges",
        " flowing with rivers of cloud",
        " shadowed while heights catch light",
        " still and peaceful at sunrise",
        " gradual in receiving daylight",
        " misty along lowest points",
        " protected from early winds",
        " awakening slowly to dawn"
        }));

    addTimeOfDayDescription("morning", ({
        " flooded with descending sunlight",
        " warming as mist burns away",
        " alive with sheltered birdsong",
        " clear in still morning air",
        " revealing its true fertile scale",
        " protected from highland winds",
        " rich in accumulated morning warmth",
        " bright with reflected eastern light",
        " peaceful in its natural shelter",
        " lush in the strengthening day"
        }));

    addTimeOfDayDescription("noon", ({
        " revealed in full magnificent scale",
        " warm in its protected microclimate",
        " still while winds pass overhead",
        " bright from ridge to fertile floor",
        " peaceful in midday shelter",
        " clear between defining ridgelines",
        " warm and still at full sun",
        " visible in complete detail",
        " sheltered from peak exposure",
        " rich in accumulated solar heat"
        }));

    addTimeOfDayDescription("afternoon", ({
        " contrasted between light and shadow",
        " developing its own weather patterns",
        " warm on western slopes",
        " shadowed on eastern faces",
        " gathering afternoon clouds",
        " peaceful in protected warmth",
        " textured by declining light",
        " distinct in light and shadow",
        " building its own wind patterns",
        " golden on sun-facing slopes"
        }));

    addTimeOfDayDescription("evening", ({
        " painted brilliant on upper reaches",
        " purple-shadowed on the floor",
        " cooled by downslope breezes",
        " beautiful in alpenglow",
        " scented with accumulated warmth",
        " peaceful in gentle evening flow",
        " contrasted between heights and depths",
        " soft in gathering purple shadow",
        " aromatic with day's accumulated growth",
        " serene as temperatures moderate"
        }));

    addTimeOfDayDescription("dusk", ({
        " pooled with rising darkness",
        " silhouetted against fading sky",
        " mysterious as details disappear",
        " bounded by ridge silhouettes",
        " cooling in gathering shadow",
        " peaceful in protected twilight",
        " defined by darkening boundaries",
        " calm in evening's deepening quiet",
        " shadowy between defining heights",
        " protected from exposed night winds"
        }));

    addTimeOfDayDescription("night", ({
        " deeply dark between ridge boundaries",
        " sheltered from night exposure",
        " cool with accumulating dew",
        " peaceful in protected darkness",
        " bounded by star-outlined ridges",
        " flowing with nocturnal life",
        " quiet in natural shelter",
        " mysterious in deepest shadow",
        " protected from highland winds",
        " rich with night scents"
        }));

    addTimeOfDayDescription("late night", ({
        " protected from exposed heights",
        " guided by natural corridor",
        " peaceful in sheltered hollow",
        " flowing with nocturnal movement",
        " quiet between guardian ridges",
        " mysterious in deep protection",
        " cool with accumulated moisture",
        " alive with sheltered night life",
        " serene in its natural boundaries",
        " peaceful in protected depths"
        }));

    addTimeOfDayDescription("midnight", ({
        " filled with pooled darkness",
        " bounded by guardian heights",
        " peaceful in deepest shadow",
        " mysterious between star-outlined ridges",
        " protected from midnight exposure",
        " cool in accumulated night air",
        " serene in natural shelter",
        " quiet in its protected hollow",
        " dark between defining boundaries",
        " peaceful in sheltered depths"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " deeper with protected snow",
        " sheltered from winter winds",
        " slower to melt in reduced sun",
        " traced with gleaming frozen streams",
        " protected from exposed winter weather",
        " peaceful in winter shelter",
        " deeper with accumulated snow",
        " quieter in winter protection",
        " beautiful with preserved winter",
        " gentle in seasonal protection"
        }));

    addSeasonDescription("spring", ({
        " first green in sheltered lowlands",
        " early with protected spring growth",
        " blooming ahead of exposed heights",
        " renewed in climbing green tide",
        " alive with early awakening",
        " fresh with protected new growth",
        " vibrant in sheltered renewal",
        " early in protected spring warmth",
        " lush with encouraged growth",
        " peaceful in spring protection"
        }));

    addSeasonDescription("summer", ({
        " verdant between exposed heights",
        " rich with sheltered agriculture",
        " lush in protected growing conditions",
        " green in summer abundance",
        " fertile in seasonal protection",
        " abundant in sheltered growth",
        " rich with summer vegetation",
        " peaceful in protected abundance",
        " vibrant in peak growing season",
        " thriving in summer shelter"
        }));

    addSeasonDescription("autumn", ({
        " tapestried in protected seasonal colors",
        " late with extended growing season",
        " beautiful in descending autumn",
        " colorful from ridges downward",
        " protected from early frosts",
        " peaceful in extended warmth",
        " rich in autumn abundance",
        " beautiful in seasonal transformation",
        " gentle in protected autumn",
        " serene in seasonal protection"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## valley cutting through the "
        "terrain, creating a sheltered corridor between higher ground");

    addItemTemplate("The valley stretches between defining ridgelines, "
        "its floor typically lower and more sheltered than surrounding terrain. "
        "The natural corridor created by the valley's formation provides protection "
        "from wind and weather, often supporting richer vegetation and creating "
        "distinct microclimates. Stream courses frequently follow the valley bottom, "
        "while slopes rise gradually or steeply toward the surrounding heights "
        "that give the valley its characteristic enclosed feeling.");
}
