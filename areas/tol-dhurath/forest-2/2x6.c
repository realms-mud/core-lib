//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/chokecherry-stand.c", "northeast");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "north");

    addExit("west", "/areas/tol-dhurath/forest-2/1x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-2/2x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
