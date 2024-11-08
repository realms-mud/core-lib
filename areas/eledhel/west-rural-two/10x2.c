//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "east");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "east");

    addExit("north", "/areas/eledhel/west-rural-two/10x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/west-rural-two/9x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
