//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "southwest");

    addExit("south", "/areas/eledhel/west-rural-two/19x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/west-rural-two/18x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/eledhel/west-rural-two/20x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"beaver","outlaw","keeper of the night","moose"}));
}
