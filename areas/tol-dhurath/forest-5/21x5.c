//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "northwest");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "northwest");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northwest");

    addExit("east", "/areas/tol-dhurath/forest-5/22x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-5/21x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
