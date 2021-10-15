//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "southwest");
    addFeature("/lib/environment/features/trees/maple-stand.c", "southwest");

    addExit("south", "/areas/eledhel/west-rural/20x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/west-rural/19x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural/20x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
