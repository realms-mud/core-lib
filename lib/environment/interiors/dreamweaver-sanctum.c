//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dreamweaver's sanctum and ethereal chambers");

    addAdjectives(({
        "ethereal sanctum where the air shimmers with dreamlike energy",
        "otherworldly chambers, the walls shifting with unspoken visions",
        "mystic sanctum where reality twists and bends like a waking dream",
        "dream-soaked chamber, the air heavy with the fragrance of illusion",
        "fantastical sanctum, its walls made of swirling mist and starlight",
        "shifting ethereal halls where the boundaries between dreams and reality dissolve"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy sanctum, the edges of the walls fading into a haze of color and light, the air thick with a sense of dreamlike wonder.");
    addLowLightDescriptionTemplate("a dimly lit chamber, where the walls pulse softly with strange, otherworldly colors, flickering like a half-remembered dream.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the air thick with shifting forms and vague shapes, as though the room itself is half asleep");
    addSomeLightDescriptionTemplate("a softly illuminated ##Adjective##, where light dances through the walls, revealing fleeting glimpses of fantastical landscapes");
}
