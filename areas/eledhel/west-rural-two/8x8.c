//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/basswood-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/butte.c", "southwest");

    addExit("south", "/areas/eledhel/west-rural-two/8x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/eledhel/west-rural-two/9x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
