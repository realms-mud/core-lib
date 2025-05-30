//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("library");
    setFloorPlanType("library");

    addAdjectives(({ "cozy", "modest", "rustic", "charming",
        "quaint" }));

    // Basic description template
    addDescriptionTemplate("a ##Adjective## wooden library with a pitched roof "
        "and small reading garden");

    // Add time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of dawn reveals wisps of mist curling around the "
        "wooden structure, giving it an almost fairy-tale quality",
        ". At dawn, dew glistens on the building's windowpanes, catching the "
        "golden light of the rising sun",
        ". The librarian can be seen through the front window in the early "
        "light, lighting oil lamps for the day's first visitors"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight plays across the weathered wooden exterior, "
        "highlighting the grain patterns that tell of years of service",
        ". The morning brings villagers who stop by to exchange books and "
        "share news before continuing their daily routines",
        ". Birds perch on the carved wooden sign above the door, their songs "
        "a pleasant counterpoint to the morning's stillness"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the shadow of the pitched roof provides a pleasant "
        "reading spot in the small garden beside the building",
        ". The wooden walls seem to creak and settle in the noon heat, the "
        "building alive with the subtle sounds of aged timber",
        ". Under the bright midday sun, the library's simple design showcases "
        "the craftsmanship that went into its construction"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon light, the warm honey tones of the wooden walls glow "
        "invitingly, beckoning passersby to step inside",
        ". The slanting afternoon sun illuminates the interior through small "
        "windows, dust motes dancing in the golden beams",
        ". As afternoon progresses, children gather on the porch after their "
        "lessons, eager to select stories for the evening"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, small oil lamps are lit within, their warm "
        "glow spilling from the windows in a welcoming manner",
        ". The evening transforms the modest building, the soft lamplight "
        "within making the windows glow like amber jewels",
        ". With the coming of evening, a few dedicated readers linger inside, "
        "reluctant to leave their literary journeys"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the library keeper can be seen moving from window to "
        "window, lighting lamps as darkness gathers outside",
        ". The fading light of dusk emphasizes the silhouettes of well-used "
        "bookshelves visible through the small windows",
        ". As dusk descends, the wooden structure seems to preserve a bubble of "
        "light and knowledge against the coming night"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the small library becomes a haven of lamplight, the soft "
        "glow from its windows a beacon of learning in the darkness",
        ". Moonlight washes over the wooden exterior at night, while the warm "
        "glow from within speaks of stories waiting to be discovered",
        ". The night watchman occasionally pauses by the library, his lantern "
        "briefly joining the soft light from the building's windows"
        }));

    // Add seasonal variations
    addSeasonDescription("spring", ({
        " with cheerful wildflowers planted along the walkway, their colors a "
        "bright welcome to visitors seeking knowledge",
        " surrounded by newly leafed trees that cast dappled shadows across the "
        "reading benches in the adjacent garden",
        " where the scent of spring blossoms mingles with the distinctive smell "
        "of old books wafting through the open windows"
        }));

    addSeasonDescription("summer", ({
        " with the front door propped open to catch the summer breeze, the "
        "peaceful sounds of pages turning carried outward",
        " where readers often choose the shade of the small garden rather than "
        "the warmer interior during the height of summer",
        " with window boxes overflowing with herbs and flowers, tended carefully "
        "by the librarian between assisting patrons"
        }));

    addSeasonDescription("autumn", ({
        " with colorful leaves collecting on the shingled roof and around the "
        "stone path leading to the arched wooden door",
        " where a small iron stove begins to warm the interior, the scent of "
        "burning wood mingling with that of aged paper and leather",
        " surrounded by trees in brilliant autumn colors, their falling leaves "
        "occasionally blown through the open windows to rest among the books"
        }));

    addSeasonDescription("winter", ({
        " with smoke curling from the chimney, promising warmth inside for those "
        "seeking refuge from the winter chill with a good book",
        " its wooden frame dusted with snow that emphasizes the simple beauty "
        "of the handcrafted architecture",
        " where frost patterns form on the windowpanes, creating natural artwork "
        "that complements the illustrations in the books within"
        }));

    // Add lighting condition descriptions
    addNearDarkDescriptionTemplate("the shadowy outline of a small building, "
        "perhaps with a single light visible through a window");

    addLowLightDescriptionTemplate("a modest wooden structure with what appears "
        "to be a pitched roof and small windows");

    addDimLightDescriptionTemplate("a small wooden library with shuttered "
        "windows and a covered porch for outdoor reading");

    addSomeLightDescriptionTemplate("a well-maintained wooden building with a "
        "pitched roof, clearly marked as the village library");

    // Single item template
    addItemTemplate("The simple wooden structure features hand-carved details "
        "around the doorway and windows, with a small covered porch where "
        "benches invite visitors to read in the fresh air");
}
