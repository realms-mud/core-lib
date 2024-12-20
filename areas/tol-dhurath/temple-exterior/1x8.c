//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "west");
    addFeature("/lib/environment/features/landforms/hillock.c", "northwest");
    addFeature("/lib/environment/features/water/gorge-creek.c", "east");

    addExit("west", "/areas/tol-dhurath/temple-exterior/0x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/temple-exterior/1x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
