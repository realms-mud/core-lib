//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "south");
    addFeature("/lib/environment/features/landforms/mound.c", "east");

    addExit("south", "/areas/tol-dhurath/entry/0x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/entry/0x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"muskrat","outlaw","kit fox"}));
}
