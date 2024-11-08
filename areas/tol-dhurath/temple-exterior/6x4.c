//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "north");
    addFeature("/lib/environment/features/landforms/hillock.c", "west");

    addExit("west", "/areas/tol-dhurath/temple-exterior/5x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/temple-exterior/7x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/temple-exterior/6x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
