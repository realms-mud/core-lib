//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior-to-exterior east-west hallway south exit");

    addExit("west", "/areas/tol-dhurath/temple-interior/3x9.c");
    addExit("east", "/areas/tol-dhurath/temple-interior/5x9.c");
    addExit("south", "/areas/tol-dhurath/temple-interior/4x8.c");
}
