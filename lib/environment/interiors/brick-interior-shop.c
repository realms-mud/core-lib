//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("brick interior shop");

    addAdjectives(({
        "cozy shop with exposed brick walls and wooden shelves",
        "inviting store where sunlight plays across the red brickwork",
        "charming shop with a high ceiling and arched brick alcoves",
        "well-kept store with polished counters and sturdy brick pillars",
        "warm shop filled with the scent of wood and stone",
        "bustling shop where goods are displayed against rustic brick walls"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy shop where the outline of shelves and the rough texture of "
        "brick walls are barely visible in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit shop, where the brick walls absorb most of the light and "
        "shadows gather in the corners"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the glow from a few lanterns revealing "
        "the uneven surface of the brickwork and the gleam of polished wood"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through the front "
        "windows to illuminate the goods on display and highlight the warm "
        "tones of the brick walls"
    );
}
