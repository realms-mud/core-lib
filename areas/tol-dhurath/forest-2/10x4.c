//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "west");
    addFeature("/lib/environment/features/landforms/glen.c", "north");
    addFeature("/lib/environment/features/landforms/crag.c", "southeast");

    addExit("west", "/areas/tol-dhurath/forest-2/9x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-2/10x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
