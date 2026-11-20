//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-east");
    addFeature("/lib/environment/features/water/brook.c", "south");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "north");

    addExit("north", "/areas/tol-dhurath/entry/17x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/argalen-keep/patrol-woods/0x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

