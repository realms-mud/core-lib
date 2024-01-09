//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/mound.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-1/6x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-1/7x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"gray fox","ruffian","outlaw","mule deer"}));
}
