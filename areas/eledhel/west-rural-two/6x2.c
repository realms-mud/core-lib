//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hummock.c", "east");
    addFeature("/lib/environment/features/trees/ash-stand.c", "east");

    addExit("west", "/areas/eledhel/west-rural-two/5x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/6x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
