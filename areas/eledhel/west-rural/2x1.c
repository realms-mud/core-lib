//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "northeast");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northeast");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "northeast");

    addExit("west", "/areas/eledhel/west-rural/1x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural/2x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
