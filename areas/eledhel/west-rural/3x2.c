//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "southwest");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/mound.c", "southwest");

    addExit("east", "/areas/eledhel/west-rural/4x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/eledhel/west-rural/3x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
