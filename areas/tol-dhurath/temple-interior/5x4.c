//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setStateMachine("/areas/tol-dhurath/state-machine/tol-dhurath-quest.c");

    setTerrain("/lib/environment/terrain/ruin-exterior.c");
    addDecorator("ruined interior courtyard");

    addExit("west", "/areas/tol-dhurath/temple-interior/4x4.c");
    addExit("east", "/areas/tol-dhurath/temple-interior/6x4.c");
    addExit("north", "/areas/tol-dhurath/temple-interior/5x5.c");
    addExit("south", "/areas/tol-dhurath/temple-interior/5x3.c");
}
