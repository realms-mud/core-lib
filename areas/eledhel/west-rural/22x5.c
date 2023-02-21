//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "south");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("east", "/areas/eledhel/west-rural/23x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/west-rural/22x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
