//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rogue hall");

    addAdjectives(({
        "dim hall filled with hushed voices and watchful eyes",
        "shadowy den where thieves and smugglers trade secrets and silver",
        "hidden chamber reeking of oil, steel, and secrecy",
        "rogue's refuge, lined with weapon racks, maps, and concealed exits",
        "candlelit hall where deals are made with whispers and handshakes",
        "underground hall veiled in smoke and tension, every corner watched"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a nearly pitch-black hall. Only the faintest glow from dying embers offers any light, and unseen figures stir in the silence.");
    addLowLightDescriptionTemplate("a dark, quiet hall. Shadows gather in the corners, and the air feels heavy with unspoken threats.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, where every sound seems amplified and no step goes unnoticed");
    addSomeLightDescriptionTemplate("a dimly illuminated ##Adjective##, where even in the light, secrecy clings like smoke");
}
