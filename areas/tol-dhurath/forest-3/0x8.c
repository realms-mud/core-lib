//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "west");
    addFeature("/lib/environment/features/trees/maple-stand.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("east", "/areas/tol-dhurath/forest-3/1x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/temple-exterior/24x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
