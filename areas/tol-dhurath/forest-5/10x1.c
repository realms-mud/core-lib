//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/mound.c", "northwest");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "northwest");
    addFeature("/lib/environment/features/water/gulley-creek.c", "northwest");

    addExit("east", "/areas/tol-dhurath/forest-5/11x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-5/10x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
