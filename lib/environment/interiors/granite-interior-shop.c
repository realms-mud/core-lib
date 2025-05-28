//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("granite interior shop");

    addAdjectives(({
        "sturdy shop with polished granite walls and high arched ceilings",
        "elegant store where sunlight glints off the speckled granite surfaces",
        "imposing shop with thick granite pillars and cool stone floors",
        "refined shop with display cases set against gleaming granite walls",
        "well-built store where the air is cool and echoes softly",
        "spacious shop where goods are arranged beneath vaulted granite arches"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy shop where the outline of shelves and the cold sheen of "
        "granite walls are barely visible in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit shop, where the granite walls absorb most of the light and "
        "shadows gather in the corners"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the glow from a few lanterns revealing the "
        "subtle sparkle of the granite and the gleam of polished wood"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through the front windows "
        "to illuminate the goods on display and highlight the cool, speckled "
        "granite walls"
    );
}
