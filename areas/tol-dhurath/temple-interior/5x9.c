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

    addExit("west", "/areas/tol-dhurath/temple-interior/4x9.c");
    addExit("east", "/areas/tol-dhurath/temple-interior/6x9.c");
}
