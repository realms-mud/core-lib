//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setStateMachine("/areas/tol-dhurath/state-machine/tol-dhurath-quest.c");

    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "north");
    addDecorator("ruined interior east-west hallway south entry");

    addExit("west",
        "/areas/tol-dhurath/temple-interior/0x3.c");
    addExit("east",
        "/areas/tol-dhurath/temple-interior/2x3.c");
    addExitWithDoor("south",
        "/areas/tol-dhurath/temple-interior/1x2.c");
}
