//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/tor.c", "southwest");
    addFeature("/lib/environment/features/landforms/crag.c", "southwest");
    addFeature("/lib/environment/features/landforms/hill.c", "southwest");

    addExit("south", "/areas/eledhel/west-rural-two/4x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/eledhel/west-rural-two/4x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
