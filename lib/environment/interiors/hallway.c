//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("castle hallway");

    addAdjectives(({
        "long stone hallway lined with flickering torches and heavy tapestries",
        "arched corridor where footsteps echo off the flagstone floor",
        "grand passageway with vaulted ceilings and carved stone columns",
        "dim hallway where narrow windows let in slivers of light",
        "fortified corridor with arrow slits and banners of the ruling house",
        "ancient hallway where the air is cool and smells faintly of old stone"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy castle hallway where only the faint glow of distant torches "
        "reveals the outlines of stone walls and hanging banners"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit castle hallway, where the flicker of torchlight casts long "
        "shadows across the flagstones and tapestries"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the light from torches and narrow windows "
        "revealing the textures of stone, wood, and fabric"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through arched windows to "
        "illuminate the banners, columns, and polished flagstone floor"
    );
}
