//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("limestone interior shop");

    addAdjectives(({
        "bright shop with pale limestone walls and sunlight streaming through "
            "arched windows",
        "airy chamber where vaulted ceilings and creamy stone create a sense of "
            "openness",
        "elegant store with polished limestone floors and carved stone pillars",
        "refined shop where goods are displayed on shelves set against smooth "
            "limestone",
        "cool room where the air is fresh and echoes softly off the stone walls",
        "spacious shop with high ceilings and goods arranged beneath limestone arches",
        "inviting store where the scent of herbs and parchment mingles in the air",
        "well-kept shop with limestone counters and baskets of colorful wares",
        "sunlit chamber where the stone glows gold in the afternoon light",
        "quiet shop where footsteps echo on the flagstone floor",
        "orderly store with alcoves carved into the limestone for special items",
        "charming shop where trailing ivy frames the windows and doorways",
        "bustling market room where merchants and customers haggle over goods",
        "tasteful shop with tapestries and lanterns brightening the pale stone",
        "storied chamber where the walls bear faint carvings from ages past"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy shop where the outline of shelves and pale limestone walls "
        "are barely visible in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit shop, where the limestone walls absorb most of the light "
        "and shadows gather in the corners"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the glow from a few lanterns revealing the "
        "subtle texture of the limestone and the gleam of polished wood"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through the front windows "
        "to illuminate the goods on display and highlight the creamy limestone walls"
    );
}
