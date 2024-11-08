//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-creek.c", "west");
    addFeature("/lib/environment/features/landforms/glen.c", "northwest");

    addExit("east", "/areas/tol-dhurath/entry/1x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/entry/0x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
