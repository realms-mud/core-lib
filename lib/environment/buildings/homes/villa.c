//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("villa");
    setFloorPlanType("villa");

    addAdjectives(({
        "elegant", "sprawling", "sun-washed", "stately", "Mediterranean", "airy"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## villa with plastered walls, a red-tiled roof, and a "
        "central courtyard garden"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day washes over the plastered walls, giving them "
        "a soft golden glow against the red-tiled roof",
        ". At dawn, birds sing in the courtyard garden while dew glistens on "
        "the flowering vines that climb the villa's columns"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sun streams through the open courtyard, casting intricate "
        "shadows from ornamental trees onto the mosaic floor below",
        ". The villa comes alive in the morning light, its elegant proportions "
        "and careful detailing revealing the architect's skill"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the white walls reflect the harsh sun while deep porticos "
        "offer cooling shade throughout the sprawling residence",
        ". The central fountain catches the noon light, water droplets "
        "sparkling like diamonds as they play against the blue sky above"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light softens the villa's appearance, warming the "
        "plastered walls to a honey tone and illuminating the arched doorways",
        ". Cooling breezes flow through the loggia, demonstrating the clever "
        "design that makes this residence comfortable even in summer heat"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, oil lamps are lit throughout the villa, their warm "
        "glow spilling from windows and illuminating garden paths",
        ". The villa seems designed for evening entertaining, with its "
        "interconnected spaces flowing from interior rooms to outdoor terraces"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the villa's white walls take on the pink and purple hues of "
        "the setting sun, transforming the residence into a watercolor painting",
        ". The fountain in the central courtyard continues its gentle music as "
        "darkness falls, a soothing counterpoint to the evening's stillness"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the villa becomes a collection of warm, golden windows "
        "surrounding the courtyard, where lanterns illuminate garden paths",
        ". Moonlight washes over the plastered walls, creating dramatic "
        "contrasts with the shadows of columns and pergolas"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with citrus trees blooming in massive terracotta planters and "
        "climbing roses beginning their journey up trellised walls",
        " where spring breezes carry the scent of jasmine and orange blossoms "
        "from the carefully curated garden within"
        }));

    addSeasonDescription("summer", ({
        " with canvas awnings extended over terraces to provide additional "
        "shade and grape vines heavy with fruit along the pergola",
        " designed perfectly for summer living, with shallow pools reflecting "
        "sky and architecture while providing cooling evaporation"
        }));

    addSeasonDescription("autumn", ({
        " with the last roses still blooming in the sheltered courtyard and "
        "harvest celebrations evident in the grape-laden pergola",
        " where the slanting autumn light emphasizes the careful proportions of "
        "the architecture, from columned portico to garden vista"
        }));

    addSeasonDescription("winter", ({
        " with protective shutters closed against the occasional storm and "
        "evergreen plants providing structure to the winter garden",
        " where even in winter the sheltered courtyard captures enough sun to "
        "allow comfortable outdoor living on milder days"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large structure with what appears to be an open space in its center"
    );
    addLowLightDescriptionTemplate(
        "a sprawling building with white walls, a red-tiled roof, and what "
        "seems to be a central courtyard"
    );
    addDimLightDescriptionTemplate(
        "an elegant villa with plastered walls, a red-tiled roof, and a "
        "garden-filled courtyard at its center"
    );
    addSomeLightDescriptionTemplate(
        "a stately Mediterranean villa with gleaming white walls, a red-tiled "
        "roof, columned porticos, and a lush central courtyard garden"
    );

    // Single item template
    addItemTemplate(
        "The villa represents elegant country living, its design centered around "
        "a verdant courtyard with a splashing fountain. The structure is built "
        "of plastered stone painted a luminous white, crowned by red terra "
        "cotta roof tiles that extend over deep porticos and loggias. Graceful "
        "columns support these covered spaces, creating a rhythm of light and "
        "shadow around the perimeter. The rooms flow from one to another and "
        "from inside to out, with tall windows and doors positioned to capture "
        "both light and cooling breezes. Gardens are integral to the design, "
        "with flowering vines, ornamental trees, and fragrant herbs throughout."
    );

    addSourceOfLight(5);
}
