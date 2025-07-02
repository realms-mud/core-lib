//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tor");
    addAdjectives(({ "weathered", "ancient", "granite", "isolated", "wind-carved",
        "brooding", "massive", "sentinel", "stark", "timeless" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " stark against brightening sky",
        " silhouetted in first light",
        " ancient in morning clarity",
        " weathered in dawn's glow",
        " isolated in early light",
        " brooding in sunrise",
        " massive against dawn sky",
        " timeless in morning peace",
        " granite-hard in first rays",
        " sentinel in awakening day"
        }));

    addTimeOfDayDescription("morning", ({
        " clear in strengthening light",
        " detailed in morning sun",
        " ancient in full visibility",
        " weathered in bright clarity",
        " isolated in morning exposure",
        " massive in revealed scale",
        " stark in morning light",
        " brooding in daylight",
        " timeless in morning stability",
        " granite-solid in sun"
        }));

    addTimeOfDayDescription("noon", ({
        " harsh in direct sunlight",
        " stark in shadowless exposure",
        " ancient in blazing clarity",
        " weathered in peak illumination",
        " isolated in full exposure",
        " massive in overwhelming scale",
        " brooding in intense light",
        " timeless in noon stillness",
        " granite-hot in sun",
        " sentinel in blazing day"
        }));

    addTimeOfDayDescription("afternoon", ({
        " textured in angled light",
        " dramatic in lengthening shadows",
        " ancient in golden illumination",
        " weathered in afternoon glow",
        " isolated in striking light",
        " massive in shadow contrast",
        " brooding in declining day",
        " timeless in afternoon peace",
        " granite-warm in sun",
        " sentinel in golden hour"
        }));

    addTimeOfDayDescription("evening", ({
        " dramatic against sunset sky",
        " silhouetted in evening glow",
        " ancient in alpenglow",
        " weathered in golden light",
        " isolated against colored sky",
        " massive in evening grandeur",
        " brooding in sunset beauty",
        " timeless in evening peace",
        " granite-dark in silhouette",
        " sentinel in dying light"
        }));

    addTimeOfDayDescription("dusk", ({
        " mysterious in gathering darkness",
        " stark against twilight sky",
        " ancient in fading light",
        " weathered in dusk shadows",
        " isolated in growing night",
        " massive in twilight mystery",
        " brooding in evening darkness",
        " timeless in dusk peace",
        " granite-cold in shadow",
        " sentinel in gathering gloom"
        }));

    addTimeOfDayDescription("night", ({
        " stark against starry sky",
        " mysterious in moonlight",
        " ancient under stars",
        " weathered in lunar glow",
        " isolated in night darkness",
        " massive in nocturnal grandeur",
        " brooding in night mystery",
        " timeless in stellar peace",
        " granite-cold in night",
        " sentinel under night sky"
        }));

    addTimeOfDayDescription("late night", ({
        " mysterious in deep darkness",
        " felt more than seen",
        " ancient in night presence",
        " weathered in unseen majesty",
        " isolated in night mystery",
        " massive in felt presence",
        " brooding in deep night",
        " timeless in night eternity",
        " granite-solid in darkness",
        " sentinel in midnight watch"
        }));

    addTimeOfDayDescription("midnight", ({
        " timeless under midnight stars",
        " eternal in deepest night",
        " ancient in star-filled darkness",
        " weathered in midnight mystery",
        " isolated in cosmic solitude",
        " massive in midnight presence",
        " brooding in deepest darkness",
        " permanent in stellar silence",
        " granite-enduring in night",
        " sentinel in midnight vigil"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " stark in winter exposure",
        " ice-carved in freezing wind",
        " ancient in winter endurance",
        " weathered in harsh conditions",
        " isolated in winter desolation",
        " massive in winter grandeur",
        " brooding in winter storms",
        " timeless in seasonal cycles",
        " granite-hard in frost",
        " sentinel in winter watch"
        }));

    addSeasonDescription("spring", ({
        " unchanged by seasonal renewal",
        " stark amid spring growth",
        " ancient while life returns",
        " weathered in spring rains",
        " isolated from spring joy",
        " massive in spring contrast",
        " brooding in season's change",
        " timeless through spring passage",
        " granite-constant in renewal",
        " sentinel over spring awakening"
        }));

    addSeasonDescription("summer", ({
        " stark in summer heat",
        " baked in intense sunlight",
        " ancient in summer endurance",
        " weathered in blazing sun",
        " isolated in summer exposure",
        " massive in heat shimmer",
        " brooding in summer storms",
        " timeless in summer cycles",
        " granite-hot in blazing day",
        " sentinel in summer watch"
        }));

    addSeasonDescription("autumn", ({
        " unchanged by seasonal color",
        " stark amid autumn beauty",
        " ancient through fall passage",
        " weathered in autumn storms",
        " isolated from seasonal joy",
        " massive in autumn grandeur",
        " brooding in season's end",
        " timeless through autumn change",
        " granite-enduring in cold",
        " sentinel over autumn's close"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## tor rising as a weathered "
        "granite outcrop from the surrounding landscape");

    addItemTemplate("The tor stands as an isolated rocky outcrop, typically "
        "formed from resistant granite or similar hard stone that has weathered "
        "more slowly than surrounding rock. Wind and weather have carved its "
        "distinctive profile over countless millennia, creating a landmark "
        "visible from great distances. The exposed rock face shows the scars "
        "of geological time, with joints and fractures creating distinctive "
        "patterns. Despite its stark appearance, small hardy plants often "
        "find footholds in cracks and crevices, while the tor itself serves "
        "as a navigation point and sometimes a place of ancient significance.");
}
