//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin entry");
    addAdjectives(({ "derelict entry with crumbling walls",
        "formerly grandiose atrium. The stone walls are now in disrepair",
        "grand atrium. Small piles of debris have fallen from what were once "
            "artfully-crafted walls",
        "crumbling entry. The battered wall has seen better days",
        "ruined entry with pockmarked walls",
        "long-neglected atrium"
     }));

    useExteriorLighting();

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a very dark atrium. Little detail can be made out in the extremely low light");
    addLowLightDescriptionTemplate("a dark entrance. Little detail can be made out in the extremely low light");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##");
    addSomeLightDescriptionTemplate("a ##Adjective##");
}
