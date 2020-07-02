//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior-to-exterior north-south hallway east exit");

    addExit("west", "/areas/tol-dhurath/temple-interior/10x6.c");
    addExit("north", "/areas/tol-dhurath/temple-interior/11x7.c");
    addExit("south", "/areas/tol-dhurath/temple-interior/11x5.c");
}
