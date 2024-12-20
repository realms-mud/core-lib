//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "east");
    addFeature("/lib/environment/features/landforms/cliff.c", "east");
    addFeature("/lib/environment/features/water/creek.c", "east");

    addExit("south", "/areas/tol-dhurath/forest-5/18x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-5/18x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"weasel","black bear","keeper of the night","knight of the storm","white-tail deer","badger"}));
}
