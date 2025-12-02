//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stone temple and meditation halls");

    addAdjectives(({
        "grand temple carved from ancient stone",
        "sacred hall of smooth stone, silent and still",
        "hallowed stone chamber where echoes of prayer linger",
        "peaceful meditation hall, the air heavy with silence",
        "stone sanctuary where time seems to slow",
        "sacred, cool stone chamber where soft chants fill the air"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowed stone temple, the faint outlines of intricate carvings visible in the gloom.");
    addLowLightDescriptionTemplate("a dimly lit meditation hall, the stone walls softly illuminated by flickering candles.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the air cool and calm, with light playing across the stone floors");
    addSomeLightDescriptionTemplate("a serene ##Adjective##, the stone glowing faintly with the light of incense and candles");
}
