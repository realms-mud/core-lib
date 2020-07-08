//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-great-hall.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/unlit-sconce.c", "east");

    addDecorator("ruined interior east wall");

    addExit("west",
        "/areas/tol-dhurath/temple-interior/9x1.c");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/11x2.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/11x0.c");
}
