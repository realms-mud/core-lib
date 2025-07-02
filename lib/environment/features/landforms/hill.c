//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hill");
    addAdjectives(({ "grassy", "rolling", "windswept", "gently sloping",
        "sunlit", "open", "broad", "lonely" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " soft with first light",
        " dewy in morning quiet",
        " golden on the crest",
        " peaceful before sunrise",
        " gentle in pastel hues",
        " quiet with morning stillness",
        " bright with creeping light",
        " fresh with morning dew",
        " calm in early light",
        " serene at daybreak"
        }));

    addTimeOfDayDescription("morning", ({
        " golden in morning sun",
        " bright with stirring breezes",
        " alive with birdsong",
        " clear in open air",
        " fresh with morning warmth",
        " peaceful in morning light",
        " vibrant with awakening life",
        " gentle in morning breezes",
        " open to morning sky",
        " bright with wildflower color"
        }));

    addTimeOfDayDescription("noon", ({
        " bright under full sun",
        " warm with swaying grasses",
        " humming with insect life",
        " clear under wide sky",
        " open to brilliant light",
        " shimmering in heat",
        " vibrant in full illumination",
        " alive with midday activity",
        " bright in complete exposure",
        " warm in peak sunlight"
        }));

    addTimeOfDayDescription("afternoon", ({
        " golden in softening light",
        " peaceful in warm breezes",
        " content under blue sky",
        " gentle in declining sun",
        " warm with afternoon glow",
        " calm in moderate warmth",
        " beautiful in golden hues",
        " peaceful in warm air",
        " serene in afternoon light",
        " comfortable in gentle warmth"
        }));

    addTimeOfDayDescription("evening", ({
        " silhouetted against flaming sky",
        " glowing in amber light",
        " peaceful in cooling air",
        " beautiful against sunset",
        " calm in evening breezes",
        " romantic in golden hour",
        " serene in declining light",
        " peaceful in evening glow",
        " gentle in cooling warmth",
        " beautiful in sunset colors"
        }));

    addTimeOfDayDescription("dusk", ({
        " darkening under rising stars",
        " peaceful in gathering night",
        " soft in fading colors",
        " quiet in evening stillness",
        " gentle in twilight peace",
        " calm in deepening dusk",
        " serene in gathering darkness",
        " peaceful in evening quiet",
        " soft in dimming light",
        " tranquil in twilight calm"
        }));

    addTimeOfDayDescription("night", ({
        " quiet under starlight",
        " peaceful in moonlight",
        " silvered under night sky",
        " serene in nighttime stillness",
        " calm under stars",
        " peaceful in night breezes",
        " gentle in lunar light",
        " quiet in nocturnal peace",
        " tranquil under night sky",
        " still in midnight calm"
        }));

    addTimeOfDayDescription("late night", ({
        " still under starlight",
        " peaceful in night quiet",
        " calm in gentle breezes",
        " serene under dark sky",
        " quiet in deep night",
        " tranquil in nighttime peace",
        " gentle in late hour stillness",
        " peaceful in nocturnal calm",
        " still in deep nighttime",
        " silent in late night peace"
        }));

    addTimeOfDayDescription("midnight", ({
        " silent under blazing stars",
        " ethereal in moonlight",
        " peaceful in midnight stillness",
        " quiet in deep night",
        " serene under star-filled sky",
        " tranquil in midnight calm",
        " still in deepest night",
        " peaceful in absolute quiet",
        " gentle in lunar glow",
        " mystical in midnight peace"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " frosted with morning ice",
        " dusted with snow",
        " sharp with clear air",
        " white under pale sky",
        " crisp with winter wind",
        " bare in winter stillness",
        " cold with icy clarity",
        " stark in winter beauty",
        " peaceful in winter quiet",
        " clean with winter purity"
        }));

    addSeasonDescription("spring", ({
        " green with fresh growth",
        " dotted with wildflowers",
        " alive with new life",
        " fresh with spring scents",
        " vibrant with returning life",
        " colorful with spring blooms",
        " renewed with seasonal growth",
        " bright with spring energy",
        " peaceful with spring warmth",
        " beautiful with spring renewal"
        }));

    addSeasonDescription("summer", ({
        " vibrant with golden grass",
        " alive with summer activity",
        " warm with butterflies",
        " hot with full sun",
        " rich with summer growth",
        " abundant with wildflowers",
        " lush in peak season",
        " bright with summer color",
        " peaceful in summer warmth",
        " beautiful in full bloom"
        }));

    addSeasonDescription("autumn", ({
        " painted in russet and gold",
        " beautiful with autumn colors",
        " cool with changing season",
        " peaceful in autumn light",
        " rich with seasonal hues",
        " gentle with autumn breezes",
        " colorful in seasonal change",
        " serene in autumn peace",
        " beautiful with fall foliage",
        " calm in seasonal transition"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## hill rising gently above the "
        "surrounding land");

    addItemTemplate("The hill rises in a gentle slope above the surrounding "
        "terrain, its rounded form covered with grasses and wildflowers that "
        "sway in the frequent breezes. The elevation provides expansive views "
        "of the surrounding landscape, while the exposed position means weather "
        "and seasonal changes are particularly noticeable. Paths often wind "
        "around or over hills, taking advantage of the natural high ground "
        "for navigation and visibility.");
}
