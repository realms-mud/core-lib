//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior east-west hallway north entry");

    addExit("west",
        "/areas/tol-dhurath/temple-interior/1x3.c");
    addExit("east",
        "/areas/tol-dhurath/temple-interior/3x3.c");
    addExitWithDoor("north",
        "/areas/tol-dhurath/temple-interior/2x4.c");
}
