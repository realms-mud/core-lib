//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("marble spire");

    addAdjectives(({
        "tall, gleaming spire of white marble",
        "narrow tower lined with smooth marble",
        "serene chamber high within a marble spire",
        "airy room with vaulted ceilings and polished stone",
        "gleaming white chamber, the marble cool to the touch",
        "elegant room where sunlight dances off marble walls"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadow-filled chamber. The pale marble is barely visible in the gloom.");
    addLowLightDescriptionTemplate("a faintly glowing room, where bits of light glint off marble surfaces in the dark.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##");
    addSomeLightDescriptionTemplate("a radiant ##Adjective##, light glinting softly on the marble");
}
