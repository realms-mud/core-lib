//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("geomancer hall");

    addAdjectives(({
        "ancient temple carved deep into the bedrock",
        "mysterious stone hall where earth magic flows through the walls",
        "hallowed temple with stone columns etched with runes of earth and stone",
        "majestic stone sanctuary where the very earth hums with power",
        "sacred hall where the air is thick with the energy of the earth",
        "stone chamber adorned with moss and vines, pulsing with raw arcane power"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowed temple, the stone walls glowing faintly with arcane symbols that pulse like the heartbeat of the earth.");
    addLowLightDescriptionTemplate("a dimly lit stone hall, ancient runes carved into the stone flickering with arcane energy.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the stone walls humming quietly with earth's power");
    addSomeLightDescriptionTemplate("a vibrant ##Adjective##, where light dances on the stone carvings, revealing their deep magic");
}
