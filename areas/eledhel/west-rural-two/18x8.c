//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "west");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "west");

    addExit("south", "/areas/eledhel/west-rural-two/18x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/west-rural-two/17x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/18x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
