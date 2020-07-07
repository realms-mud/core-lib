//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior south-west corner hallway");

    addExit("west",
        "/areas/tol-dhurath/temple-interior/3x1.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/4x0.c");
}
