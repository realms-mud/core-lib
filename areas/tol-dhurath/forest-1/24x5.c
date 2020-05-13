//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "north");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "east");
    addFeature("/lib/environment/features/trees/maple-stand.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-1/23x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-1/24x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
