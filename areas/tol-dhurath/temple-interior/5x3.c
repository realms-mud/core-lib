//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setStateMachine("/areas/tol-dhurath/state-machine/tol-dhurath-quest.c");

    setTerrain("/lib/environment/terrain/ruin-exterior.c");
    addExitWithDoor("south",
        "/areas/tol-dhurath/temple-interior/5x2.c");
    addExit("east",
        "/areas/tol-dhurath/temple-interior/6x3.c");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/5x4.c");

    addDecorator("ruined interior large staired entrance left");
}
