//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");
    addFeature("/lib/environment/features/trees/yew-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/maple-stand.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-1/16x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"badger","red fox"}));
}
