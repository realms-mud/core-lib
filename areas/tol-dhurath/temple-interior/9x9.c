//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior east-west hallway");

    addExit("east", "/areas/tol-dhurath/temple-interior/10x9.c");
    addExit("west", "/areas/tol-dhurath/temple-interior/8x9.c");
    addExit("south", "/areas/tol-dhurath/temple-interior/9x8.c");
}
