//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "north");
    addFeature("/lib/environment/features/trees/winesap-apple-stand.c", "south");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "northwest");

    addExit("west", "/areas/tol-dhurath/forest-2/7x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-2/8x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
