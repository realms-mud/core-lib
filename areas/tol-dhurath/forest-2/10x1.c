//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "south");
    addFeature("/lib/environment/features/landforms/crag.c", "northwest");
    addFeature("/lib/environment/features/landforms/hollow.c", "north");

    addExit("east", "/areas/tol-dhurath/forest-2/11x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-2/9x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
