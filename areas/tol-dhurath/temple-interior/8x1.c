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

    setInterior("/lib/environment/interiors/ruin-great-hall.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "west");
    addDecorator("ruined interior west wall");

    addExit("east",
        "/areas/tol-dhurath/temple-interior/9x1.c");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/8x2.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/8x0.c");
}
