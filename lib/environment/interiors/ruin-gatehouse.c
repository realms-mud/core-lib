//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin gatehouse");
    addAdjectives(({ "derelict gatehouse with crumbling walls",
        "crumbling gatehouse. The battered wall has seen better days",
        "ruined gatehouse with pockmarked walls",
        "long-neglected gatehouse"
     }));

    useExteriorLighting();

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a very dark gatehouse. Little detail can be made out in the extremely low light");
    addLowLightDescriptionTemplate("a dark entrance. Little detail can be made out in the extremely low light");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##");
    addSomeLightDescriptionTemplate("a ##Adjective##");
}
