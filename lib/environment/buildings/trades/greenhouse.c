//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("greenhouse");
    setFloorPlanType("trade");

    addAdjectives(({
        "glass", "sunlit", "humid", "lush", "warm", "verdant"
        }));

    addDescriptionTemplate(
        "a ##Adjective## greenhouse with glass walls and a peaked roof"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the greenhouse glows with the first light, dew sparkling "
        "on the glass",
        ". The air inside is warm and filled with the scent of growing plants"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, gardeners tend to rows of herbs and flowers",
        ". Sunlight streams through the glass, waking the plants to life"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the greenhouse is hot and humid, filled with the buzz "
        "of insects",
        ". The scent of earth and blossoms is strongest at this hour"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the greenhouse is a haven for rare and delicate "
        "plants",
        ". The glass walls shimmer in the sun, and shadows play among the leaves"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the greenhouse cools and the plants settle for "
        "the night",
        ". The last rays of sunlight linger on the glass panes"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the greenhouse glows softly, the day's warmth fading",
        ". The air is still, and the scent of flowers drifts outside"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the greenhouse is dark, its glass walls reflecting the "
        "moonlight",
        ". The plants rest in the quiet, waiting for the sun's return"
        }));

    addSeasonDescription("spring", ({
        " bursting with new shoots and the promise of fresh growth",
        " as gardeners prepare seedlings for the coming season"
        }));

    addSeasonDescription("summer", ({
        " filled with lush greenery and the scent of blooming flowers",
        " as the greenhouse is at its most vibrant and productive"
        }));

    addSeasonDescription("autumn", ({
        " with late-blooming flowers and the last of the summer's bounty",
        " as gardeners prepare the greenhouse for the colder months"
        }));

    addSeasonDescription("winter", ({
        " warm and humid inside, a refuge for tender plants from the cold",
        " as the greenhouse shelters rare and delicate species"
        }));

    addNearDarkDescriptionTemplate(
        "a glass-walled greenhouse glowing faintly in the dim light"
    );
    addLowLightDescriptionTemplate(
        "a sunlit greenhouse with rows of plants and glass walls"
    );
    addDimLightDescriptionTemplate(
        "a humid greenhouse filled with lush greenery and earthy scents"
    );
    addSomeLightDescriptionTemplate(
        "a verdant greenhouse with glass walls, a peaked roof, and "
        "thriving plants"
    );

    addItemTemplate(
        "The greenhouse is a sunlit structure of glass and wood, filled with "
        "rows of herbs, flowers, and rare plants. The air is warm and humid, "
        "and the scent of earth and blossoms fills the space. Sunlight streams "
        "through the glass, nurturing the plants within."
    );
}
