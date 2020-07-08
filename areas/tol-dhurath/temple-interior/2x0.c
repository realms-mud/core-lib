//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-room.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/unlit-sconce.c", "south");
    addDecorator("ruined interior north T-intersection");

    addExit("east",
        "/areas/tol-dhurath/temple-interior/3x0.c");
    addExit("west",
        "/areas/tol-dhurath/temple-interior/1x0.c");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/2x1.c");
}
