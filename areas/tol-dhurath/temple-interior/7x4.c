//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setStateMachine("/areas/tol-dhurath/state-machine/tol-dhurath-quest.c");

    setTerrain("/lib/environment/terrain/ruin-exterior.c");
    addDecorator("ruined interior courtyard with path");

    addExit("west", "/areas/tol-dhurath/temple-interior/6x4.c");
    addExit("east", "/areas/tol-dhurath/temple-interior/8x4.c");
    addExit("north", "/areas/tol-dhurath/temple-interior/7x5.c");

    addExitWithDoor("south",
        "/areas/tol-dhurath/temple-interior/7x3.c");

    addObject("/areas/tol-dhurath/characters/seilyndria/seilyndria.c");
    addObject("/areas/tol-dhurath/characters/galadhel/galadhel.c");
    addObject("/areas/tol-dhurath/characters/halgaladh/halgaladh.c");
}
