//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/unlit-sconce.c", "west");    addDecorator("ruined interior north-east corner hallway south entry");

    addExit("east",
        "/areas/tol-dhurath/temple-interior/4x2.c");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/3x3.c");
    addExitWithDoor("south",
        "/areas/tol-dhurath/temple-interior/3x1.c");
}
