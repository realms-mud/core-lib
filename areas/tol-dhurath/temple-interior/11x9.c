//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setStateMachine("/areas/tol-dhurath/state-machine/tol-dhurath-quest.c");

    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior-to-exterior north-corner hallway west exit");

    addExit("west", "/areas/tol-dhurath/temple-interior/10x9.c");
    addExit("south", "/areas/tol-dhurath/temple-interior/11x8.c");
}
