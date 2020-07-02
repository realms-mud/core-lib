//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/ruin-exterior.c");
    addDecorator("ruined interior courtyard");

    addExit("east", "/areas/tol-dhurath/temple-interior/11x5.c");
    addExit("west", "/areas/tol-dhurath/temple-interior/9x5.c");
    addExit("north", "/areas/tol-dhurath/temple-interior/10x6.c");
    addExit("south", "/areas/tol-dhurath/temple-interior/10x4.c");
}
