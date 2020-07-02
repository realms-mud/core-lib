//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/ruin-exterior.c");
    addDecorator("ruined interior courtyard with pillar");

    addExit("west", "/areas/tol-dhurath/temple-interior/5x8.c");
    addExit("east", "/areas/tol-dhurath/temple-interior/7x8.c");
    addExit("north", "/areas/tol-dhurath/temple-interior/6x9.c");
    addExit("south", "/areas/tol-dhurath/temple-interior/6x7.c");
}
