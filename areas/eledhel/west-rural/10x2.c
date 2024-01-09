//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "southwest");
    addFeature("/lib/environment/features/trees/oak-stand.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "southwest");

    addExit("west", "/areas/eledhel/west-rural/9x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/eledhel/west-rural/11x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
