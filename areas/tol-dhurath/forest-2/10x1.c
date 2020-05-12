//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "west");
    addFeature("/lib/environment/features/landforms/crag.c", "west");
    addFeature("/lib/environment/features/landforms/hollow.c", "west");

    addExit("east", "/areas/tol-dhurath/forest-2/11x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-2/9x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
