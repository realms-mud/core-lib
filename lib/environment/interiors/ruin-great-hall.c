//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin great hall");
    addAdjectives(({ "derelict room with crumbling walls",
        "large chamber. The stone walls are in disrepair",
        "room. Small piles of debris have fallen from what were once "
            "artfully-crafted walls",
        "room. The battered wall has seen better days",
        "ruined chamber with pockmarked walls",
        "long-neglected room"
     }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a very dark room. Little detail can be made out in the extremely low light");
    addLowLightDescriptionTemplate("a dark room. Little detail can be made out in the extremely low light");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##");
    addSomeLightDescriptionTemplate("a ##Adjective##");
}
