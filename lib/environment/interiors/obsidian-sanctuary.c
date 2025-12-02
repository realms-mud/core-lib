//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("obsidian sanctuary");

    addAdjectives(({
        "solemn chamber of polished black obsidian",
        "shadowy sanctuary where every surface gleams with dark glass",
        "hushed room carved from volcanic stone, cold and silent",
        "dimly glowing chamber etched with faint runes in black stone",
        "sanctuary of gleaming obsidian, reflecting light like liquid night",
        "ancient, echoing hall of smooth, mirror-dark walls"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a lightless chamber. You can just make out the glossy surfaces of black stone all around you.");
    addLowLightDescriptionTemplate("a shadowed obsidian room. Faint glints of light flicker across glassy surfaces.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, where reflections dance quietly in the stone");
    addSomeLightDescriptionTemplate("a gleaming ##Adjective##, every detail of the obsidian revealed in stark contrast");
}
