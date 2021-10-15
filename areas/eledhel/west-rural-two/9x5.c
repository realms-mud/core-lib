//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "southwest");
    addFeature("/lib/environment/features/landforms/combe.c", "southwest");

    addExit("west", "/areas/eledhel/west-rural-two/8x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/9x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/eledhel/west-rural-two/10x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
