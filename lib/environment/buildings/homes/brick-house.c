//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("brick house");
    setFloorPlanType("house");

    addAdjectives(({
        "neat", "sturdy", "well-built", "red-brick", "comfortable", "tidy"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## brick house with a tiled roof and small garden"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the brick walls, giving them a warm "
        "glow as smoke begins to rise from the chimney",
        ". At dawn, the house stands quietly welcoming as its inhabitants begin "
        "their daily routines"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light streams through the curtained windows as the house "
        "bustles with activity",
        ". The smell of baking bread wafts from a small window, a homely "
        "counterpoint to the sturdy brick exterior"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the brick walls absorb the sun's warmth, making the "
        "house a cozy haven despite its solid appearance",
        ". Children sometimes play in the small garden during the noon hour, "
        "their laughter a bright contrast to the serious brick facade"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun highlights the varied colors within the brickwork, "
        "from deep rust to warm sienna",
        ". Shadows begin to lengthen across the garden as the day advances, but "
        "the brick walls still radiate the day's accumulated heat"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, windows glow with lamplight, turning the house "
        "into a beacon of homely comfort",
        ". The smell of the evening meal occasionally drifts from the chimney, "
        "a savory promise carried on the cooling air"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the house's outline softens as details fade, but its solid "
        "presence remains reassuring in the gathering darkness",
        ". The brick absorbs the last light of day, seeming to hold warmth even "
        "as night approaches"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the house stands as a dark sanctuary, with perhaps one or "
        "two windows still showing lamplight behind drawn curtains",
        ". Moonlight casts subtle shadows across the brickwork, highlighting "
        "the craftsmanship that went into the building's construction"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with climbing roses beginning to bud along a trellis beside the door",
        " where spring cleaning has left windows sparkling and brass fittings "
        "polished to a bright gleam"
        }));

    addSeasonDescription("summer", ({
        " with windows thrown open to catch cooling breezes and flower boxes "
        "overflowing with colorful blooms",
        " surrounded by a well-tended garden where vegetables and herbs grow "
        "in neat rows alongside ornamental flowers"
        }));

    addSeasonDescription("autumn", ({
        " with vines turning crimson against the red brick and apples laid to "
        "dry on windowsills",
        " as the brick radiates the last warmth of the year and the smell of "
        "preserves being prepared drifts from within"
        }));

    addSeasonDescription("winter", ({
        " with smoke steadily rising from the chimney and frost outlining the "
        "mortar between each brick",
        " where snow dusts the roof and windowsills, contrasting beautifully "
        "with the warm red of the brick walls"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a solid rectangular structure with a peaked roof"
    );
    addLowLightDescriptionTemplate(
        "a brick house with several windows and a small garden"
    );
    addDimLightDescriptionTemplate(
        "a well-built brick house with a tiled roof and neat garden"
    );
    addSomeLightDescriptionTemplate(
        "a sturdy red-brick house with multiple windows, a tiled roof, and a "
        "carefully tended garden"
    );

    // Single item template
    addItemTemplate(
        "The house is constructed of well-fired red bricks with contrasting "
        "lighter mortar. Its steep roof is covered in terracotta tiles, and "
        "the windows feature wooden shutters that can be closed against "
        "inclement weather. A small but well-tended garden surrounds the house, "
        "with practical herbs and vegetables growing alongside ornamental "
        "flowers. The solid construction speaks of permanence and security, "
        "a comfortable home built to last generations."
    );

    addSourceOfLight(3);
}
