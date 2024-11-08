//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "southwest");
    addFeature("/lib/environment/features/water/ravine-creek.c", "southwest");

    addExit("north", "/areas/eledhel/west-rural-two/11x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/eledhel/west-rural-two/12x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
