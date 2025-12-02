//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pear-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "southwest");
    addFeature("/lib/environment/features/landforms/ridge.c", "southwest");

    addExit("north", "/areas/tol-dhurath/forest-5/24x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-5/23x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"white-tail deer","mink","keeper of the night"}));
}
