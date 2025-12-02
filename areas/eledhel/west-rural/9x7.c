//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/alder-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/valley.c", "southwest");

    addExit("north", "/areas/eledhel/west-rural/9x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/eledhel/west-rural/9x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
