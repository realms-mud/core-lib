//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addFeature("/lib/environment/features/water/canyon-brook.c", "southwest");
    addFeature("/lib/environment/features/trees/basswood-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-3/20x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-3/19x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"black bear","hunter","outlaw","white-tail deer"}));
}
