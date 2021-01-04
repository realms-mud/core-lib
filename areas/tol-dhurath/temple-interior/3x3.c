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

    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "east");
    addDecorator("ruined interior west T-intersection");

    addExit("west",
        "/areas/tol-dhurath/temple-interior/2x3.c");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/3x4.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/3x2.c");
}
