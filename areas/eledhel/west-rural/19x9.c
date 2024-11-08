//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "south");
    addFeature("/lib/environment/features/water/canyon-creek.c", "south");
    addFeature("/lib/environment/features/trees/cedar-stand.c", "south");

    addExit("west", "/areas/eledhel/west-rural/18x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/eledhel/west-rural/19x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"fisher","ruffian","skeleton","raccoon"}));
}
