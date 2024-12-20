//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cortland-apple-stand.c", "east");
    addFeature("/lib/environment/features/water/waterfall.c", "east");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "east");

    addExit("south", "/areas/eledhel/west-rural-two/22x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/eledhel/west-rural-two/22x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
