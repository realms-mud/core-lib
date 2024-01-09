//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "south");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");
    addFeature("/lib/environment/features/water/gulley-creek.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-3/23x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-3/22x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-3/23x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"outlaw","ruffian","boar"}));
}
