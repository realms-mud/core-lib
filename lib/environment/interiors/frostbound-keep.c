//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("frostbound keep");

    addAdjectives(({
        "frigid hall lined with ice-covered stone",
        "cold, wind-swept chamber echoing with silence",
        "frozen keep room where frost clings to every surface",
        "gloomy hall of ancient stone, glazed with rime",
        "bitterly cold chamber where your breath fogs the air",
        "austere room wrapped in layers of frost and silence"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a freezing darkness. The cold bites through the blackness, and the outlines of icy stone can barely be seen.");
    addLowLightDescriptionTemplate("a dark, frost-laced hall. Faint light glimmers off sheets of ice along the walls.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the light casting pale reflections in the frost");
    addSomeLightDescriptionTemplate("a cold, clear ##Adjective##, every frozen detail illuminated by the light");
}
