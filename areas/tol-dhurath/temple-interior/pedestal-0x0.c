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

    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "west");    
    addDecorator("ruined interior south-east corner hallway");

    addExit("east",
        "/areas/tol-dhurath/temple-interior/pedestal-0x1.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/pedestal-5x0.c");
}
