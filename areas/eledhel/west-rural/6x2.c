//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "north");
    addFeature("/lib/environment/features/water/canyon-brook.c", "north");
    addFeature("/lib/environment/features/water/pond.c", "north");

    addExit("south", "/areas/eledhel/west-rural/6x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/eledhel/west-rural/7x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural/5x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
