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

    setInterior("/lib/environment/interiors/ruin-great-hall.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "south");
    addItem("/lib/environment/items/columns/ruined-pillar.c", "west");
    addDecorator("ruined interior southeast corner east entry");

    addExit("west",
        "/areas/tol-dhurath/temple-interior/9x0.c");
    addExitWithDoor("east",
        "/areas/tol-dhurath/temple-interior/12x0.c");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/11x1.c");
}
