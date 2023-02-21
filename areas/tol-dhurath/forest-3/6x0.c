//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "northwest");
    addFeature("/lib/environment/features/landforms/tor.c", "east");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "west");

    addExit("north", "/areas/tol-dhurath/forest-3/6x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-3/7x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
