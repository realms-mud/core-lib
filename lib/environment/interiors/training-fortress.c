//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("training fortress");

    addAdjectives(({
        "fortified hall echoing with the sound of combat drills",
        "sturdy chamber where battle techniques are honed",
        "grim training hall lined with weapon racks and sparring mats",
        "barren room with heavy stone walls, perfect for training",
        "intense chamber where warriors and mages perfect their skills",
        "military stronghold, echoing with the clang of metal and commands"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadow-filled chamber, the air heavy with silence and anticipation.");
    addLowLightDescriptionTemplate("a dimly lit training hall. Shadows dance across the stone walls, the faint outlines of training equipment visible.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the light casting long shadows of sparring partners and weapons");
    addSomeLightDescriptionTemplate("a well-lit ##Adjective##, every detail of the training space clear in the light");
}
