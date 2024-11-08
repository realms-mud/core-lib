//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-creek.c", "north");

    addExit("south", "/areas/eledhel/west-rural-two/20x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/west-rural-two/19x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
