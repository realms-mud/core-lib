//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("shadowy crypts");

    addAdjectives(({
        "dark and oppressive crypt, the air thick with the scent of decay",
        "gloomy burial chambers where the shadows cling to the walls",
        "silent crypt, the stone tombs lined with ancient bones and forgotten relics",
        "mournful crypt where the dead whisper in the darkness",
        "shadow-filled burial hall, the stone cold and untouched by time",
        "ancient crypt, its halls echoing with the footsteps of the past"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a pitch-black crypt, the outlines of tombs barely visible in the gloom. The air feels heavy, as if the dead are watching.");
    addLowLightDescriptionTemplate("a dim crypt, where the faint light reveals rows of stone graves and carvings, the air heavy with silence.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the stone walls adorned with ancient carvings and the scent of incense lingering in the air");
    addSomeLightDescriptionTemplate("a faintly illuminated ##Adjective##, where shadows stretch long and seem to move with a life of their own");
}
