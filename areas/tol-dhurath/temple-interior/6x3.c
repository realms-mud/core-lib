//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        "/areas/tol-dhurath/temple-interior/6x2.c");
    addExit("west",
        "/areas/tol-dhurath/temple-interior/5x3.c");
    addExit("north", "/areas/tol-dhurath/temple-interior/6x4.c");

    addDecorator("ruined interior large staired entrance right");
}
