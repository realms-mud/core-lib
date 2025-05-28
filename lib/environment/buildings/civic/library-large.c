//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("large library");
    setFloorPlanType("library");

    addAdjectives(({ "stately", "elegant", "venerable", "scholarly",
        "imposing" }));

    // Basic description template
    addDescriptionTemplate("##Adjective## stone library with tall windows and "
        "ornate entrance");

    // Add time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The rising sun illuminates the stone facade with a soft golden glow, "
        "making the building appear almost ethereal in the early light",
        ". Dawn's first light catches on the leaded glass windows, creating a "
        "kaleidoscope of colors on the weathered stone walls",
        ". In the quiet of dawn, a single lamp can be seen moving behind the "
        "windows as an early-rising scholar begins their studies"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light streams through the tall windows, dust motes dancing "
        "visibly in the shafts of sunlight penetrating the interior",
        ". The morning brings scholars and students who ascend the wide steps "
        "to the entrance, eager to pursue knowledge within",
        ". Sunlight illuminates the intricate carvings above the entrance, "
        "featuring symbols of wisdom and enlightenment"
        }));

    addTimeOfDayDescription("noon", ({
        ". Under the midday sun, the building stands as a testament to learning, "
        "its shadow providing refuge for readers on nearby benches",
        ". At noon, the contrast between sunlit and shadowed areas emphasizes "
        "the detailed stonework and architectural flourishes",
        ". The library stands dignified in the full light of day, the gleam of "
        "brass fixtures on the heavy oak doors catching the sunlight"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". Afternoon light slants through the western windows, creating long "
        "shadows that stretch across the reading rooms within",
        ". The warm afternoon glow softens the austere stone facade, lending "
        "the building an inviting amber hue",
        ". As the day wanes, scholars can be glimpsed through the windows, "
        "hunched over texts and scrolls in concentrated study"
        }));

    addTimeOfDayDescription("evening", ({
        ". Lamps are lit throughout the building as evening falls, creating a "
        "warm glow that spills from the windows onto the grounds outside",
        ". The evening light casts the carved stone figures flanking the "
        "entrance into dramatic relief, their shadows lengthening",
        ". With the setting sun, the library transforms from a place of study "
        "to a beacon of knowledge, light emanating from every window"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the library seems to hold onto the day's last light, the "
        "pale stone glowing against the darkening sky",
        ". The windows transition from reflecting the outside world to revealing "
        "the illuminated interior as dusk settles",
        ". The fading light gives way to the warm glow of lamps within, the "
        "silhouettes of late readers visible against the windows"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the library stands as a sanctuary of light and learning, "
        "its illuminated windows like beacons in the darkness",
        ". Moonlight bathes the stone facade in silvery light, while lamplight "
        "from within creates a contrasting warm glow at the windows",
        ". The night emphasizes the library's role as keeper of knowledge, a "
        "light in the darkness where wisdom is preserved"
        }));

    // Add seasonal variations
    addSeasonDescription("spring", ({
        " surrounded by flowering trees whose petals occasionally drift through "
        "open windows, much to the librarians' dismay",
        " with climbing ivy just beginning to show fresh green leaves along "
        "the ancient stone walls and columns",
        " where scholars often take their reading outdoors to benches placed "
        "beneath the awakening trees in the adjacent courtyard"
        }));

    addSeasonDescription("summer", ({
        " with tall windows propped open to catch the summer breeze, the "
        "sounds of rustling pages occasionally carried outward",
        " surrounded by lush greenery that contrasts beautifully with the "
        "weathered stone, some ivy reaching as high as the second floor",
        " where the cooling shade of the building provides a welcome respite "
        "for scholars seeking escape from the summer heat"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathering on the wide steps and window ledges, "
        "creating splashes of red and gold against the gray stone",
        " where the ivy covering portions of the walls has turned deep crimson, "
        "as if the building itself were changing with the season",
        " surrounded by trees whose golden leaves occasionally find their way "
        "between pages, preserved as impromptu bookmarks by distracted readers"
        }));

    addSeasonDescription("winter", ({
        " with smoke rising from multiple chimneys, the interior kept warm for "
        "the comfort of dedicated scholars even on the coldest days",
        " its stone facade dusted with snow that catches in the detailed "
        "carvings and creates delicate white outlines of the architecture",
        " where the contrast between the cold exterior and the warm, lamp-lit "
        "interior creates a particularly inviting atmosphere"
        }));

    // Add lighting condition descriptions
    addNearDarkDescriptionTemplate("the looming shape of a large building, its "
        "windows appearing as faint rectangles of lighter darkness");

    addLowLightDescriptionTemplate("a substantial stone building with multiple "
        "windows, some emitting a faint glow of lamplight");

    addDimLightDescriptionTemplate("a stone library with tall windows and an "
        "impressive entrance flanked by carved columns");

    addSomeLightDescriptionTemplate("a well-constructed stone library with "
        "ornate architectural details and large, leaded glass windows");

    // Single item template
    addItemTemplate("The building features rows of tall, arched windows that "
        "allow natural light to reach the bookshelves within, while carved "
        "stone figures representing knowledge and wisdom adorn the facade");
}
