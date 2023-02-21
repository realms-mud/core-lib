//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "northeast");
    addFeature("/lib/environment/features/trees/McIntosh-apple-stand.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "east");

    addExit("west", "/areas/tol-dhurath/entry/5x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/entry/7x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
