//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "south");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "south");
    addFeature("/lib/environment/features/trees/ash-stand.c", "south");

    addExit("west", "/areas/eledhel/west-rural/18x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural/19x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
