//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "south");
    addFeature("/lib/environment/features/water/gorge-creek.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-3/17x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-3/17x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"hunter","outlaw","gray fox","kit fox"}));
}
