//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stone fortress hall");

    addAdjectives(({
        "massive stone hall with high, vaulted ceilings",
        "fortified room with thick stone walls",
        "cold chamber lined with rough-hewn stone",
        "broad hall echoing with the weight of silence",
        "grim hall, its stonework etched with age and battle",
        "somber fortress hall with iron sconces set into the walls"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a nearly lightless chamber. Shadows fill every corner, and the stone walls are barely visible.");
    addLowLightDescriptionTemplate("a dark stone hall. Outlines of the stone walls and high arches are faintly visible in the gloom.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##");
    addSomeLightDescriptionTemplate("a ##Adjective##, the stone walls visible in the steady light");
}

