//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "northeast");
    addFeature("/lib/environment/features/trees/rosewood-stand.c", "northwest");
    addFeature("/lib/environment/features/landforms/glen.c", "east");

    addExit("north", "/areas/tol-dhurath/forest-3/20x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-3/20x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
