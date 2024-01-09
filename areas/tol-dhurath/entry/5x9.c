//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "west");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "east");
    addFeature("/lib/environment/features/trees/dogwood-stand.c", "northwest");

    addExit("west", "/areas/tol-dhurath/entry/4x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/entry/5x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
