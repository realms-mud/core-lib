//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "southeast");
    addFeature("/lib/environment/features/water/ravine-creek.c", "southeast");

    addExit("north", "/areas/eledhel/west-rural-two/16x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/eledhel/west-rural-two/16x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
