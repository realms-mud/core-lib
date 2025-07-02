//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mountain");
    addAdjectives(({ "majestic", "towering", "snow-capped", "rugged", "imposing",
        "ancient", "craggy", "steep", "jagged", "massive" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " golden on distant peak",
        " bright above shadowed valleys",
        " painted in rose and gold",
        " misty on lower slopes",
        " clear against brightening sky",
        " illuminated before the lands below",
        " sharp in morning clarity",
        " beautiful in first light",
        " majestic in dawn's glow",
        " towering in early illumination"
        }));

    addTimeOfDayDescription("morning", ({
        " revealed in gradual sunlight",
        " echoing with eagle calls",
        " bright on eastern faces",
        " textured in morning light",
        " clear in full detail",
        " imposing in morning clarity",
        " massive in revealed scale",
        " beautiful in climbing sun",
        " sharp against morning sky",
        " majestic in full illumination"
        }));

    addTimeOfDayDescription("noon", ({
        " massive in full light",
        " harsh in midday clarity",
        " exposed in complete detail",
        " imposing in true scale",
        " clear to distant summit",
        " bright in shadowless light",
        " overwhelming in revealed majesty",
        " stark in brilliant illumination",
        " towering in overhead sun",
        " magnificent in full exposure"
        }));

    addTimeOfDayDescription("afternoon", ({
        " contrasted in light and shadow",
        " gathering afternoon clouds",
        " textured by declining sun",
        " beautiful in western glow",
        " dramatic in angled light",
        " impressive in afternoon clarity",
        " majestic in golden light",
        " striking in shadow contrast",
        " magnificent in afternoon sun",
        " imposing in declining day"
        }));

    addTimeOfDayDescription("evening", ({
        " silhouetted against flaming sky",
        " glowing with alpenglow",
        " beautiful in sunset colors",
        " dramatic against evening sky",
        " magnificent in golden rays",
        " inspiring in sunset light",
        " majestic in evening glow",
        " imposing against colored sky",
        " stunning in final light",
        " beautiful in dying day"
        }));

    addTimeOfDayDescription("dusk", ({
        " dark against star-filled sky",
        " mysterious in gathering night",
        " imposing in twilight shadow",
        " stark against evening sky",
        " magnificent in silhouette",
        " dramatic in fading light",
        " majestic in growing darkness",
        " impressive against night sky",
        " beautiful in twilight mystery",
        " towering into starlight"
        }));

    addTimeOfDayDescription("night", ({
        " silvered in moonlight",
        " imposing against night sky",
        " mysterious in lunar light",
        " stark in silver illumination",
        " majestic under stars",
        " dramatic in night shadow",
        " impressive in moonlit grandeur",
        " beautiful in nocturnal majesty",
        " towering into starlight",
        " magnificent in night silence"
        }));

    addTimeOfDayDescription("late night", ({
        " felt more than seen",
        " mysterious in star-outlined void",
        " imposing in unseen presence",
        " timeless against star field",
        " massive in felt presence",
        " eternal in night mystery",
        " overwhelming in unseen majesty",
        " permanent in night darkness",
        " constant in starlit silence",
        " magnificent in hidden grandeur"
        }));

    addTimeOfDayDescription("midnight", ({
        " timeless under midnight sky",
        " eternal against stars",
        " permanent in deepest night",
        " majestic in unseen presence",
        " constant in midnight silence",
        " overwhelming in hidden majesty",
        " imposing in felt grandeur",
        " magnificent in night mystery",
        " enduring in starlit darkness",
        " patient in midnight stillness"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " blanketed with snow",
        " gleaming with ice",
        " shrouded in winter storms",
        " white with accumulated snow",
        " stark in winter beauty",
        " dangerous with avalanche potential",
        " pristine in winter purity",
        " harsh in winter conditions",
        " beautiful in snow cover",
        " treacherous in winter weather"
        }));

    addSeasonDescription("spring", ({
        " cascading with snowmelt",
        " green in lower meadows",
        " renewed with climbing life",
        " fresh with seasonal awakening",
        " alive with returning growth",
        " beautiful with early blooms",
        " vibrant in gradual renewal",
        " peaceful with spring warmth",
        " renewed with melting snow",
        " fresh with spring energy"
        }));

    addSeasonDescription("summer", ({
        " blooming in alpine meadows",
        " clear in peak season",
        " accessible in brief warmth",
        " beautiful in wildflower season",
        " alive with summer activity",
        " peaceful in clear weather",
        " magnificent in full detail",
        " welcoming in moderate weather",
        " vibrant in peak growing season",
        " spectacular in summer clarity"
        }));

    addSeasonDescription("autumn", ({
        " tapestried with seasonal colors",
        " beautiful with climbing autumn",
        " frosted in high meadows",
        " colorful in changing season",
        " peaceful in autumn light",
        " magnificent in fall beauty",
        " transitioning to winter conditions",
        " beautiful with golden foliage",
        " serene in autumn clarity",
        " impressive in seasonal change"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## mountain rising dramatically "
        "from the surrounding terrain");

    addItemTemplate("The mountain dominates the landscape with its immense "
        "scale and dramatic elevation changes. Rocky slopes climb through "
        "distinct vegetation zones, from forested lower elevations through "
        "alpine meadows to barren upper reaches and summit. The massive form "
        "creates its own weather patterns and microclimates, while its "
        "presence serves as a landmark visible from great distances. Ridges, "
        "valleys, and peaks create a complex topography that challenges "
        "travelers and provides habitat for specialized mountain wildlife.");
}
