//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/glen.c", "north");
    addFeature("/lib/environment/features/landforms/ridge.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-1/21x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-1/23x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"hunter","groundhog"}));
}
