//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/red-apple-stand.c", "southwest");
    addFeature("/lib/environment/features/water/ravine-brook.c", "southwest");

    addExit("north", "/areas/eledhel/west-rural/4x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/eledhel/west-rural/4x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
