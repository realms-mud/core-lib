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

    setInterior("/lib/environment/interiors/ruin-room.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "south");
    addDecorator("ruined interior 4-way hallway");

    addExit("east",
        "/areas/tol-dhurath/temple-interior/4x1.c");
    addExit("west",
        "/areas/tol-dhurath/temple-interior/2x1.c");
    addExitWithDoor("north",
        "/areas/tol-dhurath/temple-interior/3x2.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/3x0.c");
}
