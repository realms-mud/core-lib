//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin hallway");
    addAdjectives(({ "derelict hallway",
        "hallway. The stone walls are in disrepair",
        "corridor. Small piles of debris have fallen from what were once "
            "artfully-crafted walls",
        "hallway. The battered wall has seen better days",
        "ruined corridor with pockmarked walls",
        "long-neglected hallway"
    }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a very dark hallway. Little detail can be made out in the extremely low light");
    addLowLightDescriptionTemplate("a very dark hallway. Little detail can be made out in the extremely low light");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##");
    addSomeLightDescriptionTemplate("a ##Adjective##");
}
