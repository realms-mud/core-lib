//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/tor.c", "northeast");
    addFeature("/lib/environment/features/water/brook.c", "south");
    addFeature("/lib/environment/features/trees/maple-stand.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-2/15x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-2/15x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"white-tail deer","ruffian","outlaw"}));
}
