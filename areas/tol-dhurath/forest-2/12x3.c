//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "north");
    addFeature("/lib/environment/features/trees/buckthorn-stand.c", "north");

    addExit("north", "/areas/tol-dhurath/forest-2/12x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-2/11x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"zombie","keeper of the night"}));
}
