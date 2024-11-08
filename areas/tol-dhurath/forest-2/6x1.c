//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "west");
    addFeature("/lib/environment/features/landforms/glen.c", "north");
    addFeature("/lib/environment/features/landforms/hollow.c", "east");

    addExit("north", "/areas/tol-dhurath/forest-2/6x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-2/7x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-2/5x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
